#include "hikeSDK.h"

#include <cstring>
#include <cstddef>
#include <cstdio>
#include <string>

class Camera
{
public:
    Camera() = default;
    ~Camera() { camStop(); }   // 析构自动关闭

    // 禁止拷贝（句柄唯一）
    Camera(const Camera&) = delete;
    Camera& operator=(const Camera&) = delete;

    // 启动相机：初始化 SDK -> 枚举 -> 创建句柄 -> 打开 -> 开始取流
    int camStart()
    {
        if (m_isOpen) {
            printf("Camera already started.\n");
            return MV_OK;
        }

        int nRet = MV_OK;

        // 1. 初始化 SDK
        nRet = MV_CC_Initialize();
        if (nRet != MV_OK) {
            printf("MV_CC_Initialize failed: 0x%X\n", nRet);
            return nRet;
        }

        // 2. 枚举设备
        MV_CC_DEVICE_INFO_LIST stDeviceList;
        memset(&stDeviceList, 0, sizeof(stDeviceList));
        nRet = MV_CC_EnumDevicesEx2(MV_GIGE_DEVICE | MV_USB_DEVICE,
                                    &stDeviceList, nullptr,
                                    SortMethod_SerialNumber);
        if (nRet != MV_OK) {
            printf("MV_CC_EnumDevicesEx2 failed: 0x%X\n", nRet);
            MV_CC_Finalize();
            return nRet;
        }

        if (stDeviceList.nDeviceNum == 0) {
            printf("No camera found.\n");
            MV_CC_Finalize();
            return -1;
        }
        printf("Found %u camera(s).\n", stDeviceList.nDeviceNum);

        // 3. 创建句柄（选第 0 个）
        nRet = MV_CC_CreateHandle(&m_handle, stDeviceList.pDeviceInfo[0]);
        if (nRet != MV_OK) {
            printf("MV_CC_CreateHandle failed: 0x%X\n", nRet);
            MV_CC_Finalize();
            return nRet;
        }

        // 4. 打开设备
        nRet = MV_CC_OpenDevice(m_handle);
        if (nRet != MV_OK) {
            printf("MV_CC_OpenDevice failed: 0x%X\n", nRet);
            MV_CC_DestroyHandle(m_handle);
            m_handle = nullptr;
            MV_CC_Finalize();
            return nRet;
        }

        // 5. 开始取流
        nRet = MV_CC_StartGrabbing(m_handle);
        if (nRet != MV_OK) {
            printf("MV_CC_StartGrabbing failed: 0x%X\n", nRet);
            MV_CC_CloseDevice(m_handle);
            MV_CC_DestroyHandle(m_handle);
            m_handle = nullptr;
            MV_CC_Finalize();
            return nRet;
        }

        m_isOpen = true;
        printf("Camera started.\n");
        return MV_OK;
    }

    // 抓一帧并保存
    // type:    "jpeg" / "jpg" / "bmp" / "png" / "tif" / "tiff"
    // name:    文件名（不含扩展名）
    // address: 目录，如 "/home/yan-han/Code/HaiKang"
    int pictureGet(const std::string& type,
                   const std::string& name,
                   const std::string& address)
    {
        if (!m_isOpen || m_handle == nullptr) {
            printf("Camera is not open. Call camStart() first.\n");
            return -1;
        }

        int nRet = MV_OK;

        // 6. 主动获取一帧
        MV_FRAME_OUT stFrameOut;
        memset(&stFrameOut, 0, sizeof(stFrameOut));
        nRet = MV_CC_GetImageBuffer(m_handle, &stFrameOut, 1000);
        if (nRet != MV_OK) {
            printf("MV_CC_GetImageBuffer failed: 0x%X\n", nRet);
            return nRet;
        }

        unsigned int w = stFrameOut.stFrameInfo.nExtendWidth
                             ? stFrameOut.stFrameInfo.nExtendWidth
                             : stFrameOut.stFrameInfo.nWidth;
        unsigned int h = stFrameOut.stFrameInfo.nExtendHeight
                             ? stFrameOut.stFrameInfo.nExtendHeight
                             : stFrameOut.stFrameInfo.nHeight;

        printf("Get frame: Width[%u], Height[%u], FrameLen[%lld], FrameNum[%u]\n",
               w, h,
               (long long)stFrameOut.stFrameInfo.nFrameLenEx,
               stFrameOut.stFrameInfo.nFrameNum);

        // 7. 填充 MV_CC_IMAGE
        MV_CC_IMAGE stImage;
        memset(&stImage, 0, sizeof(stImage));
        stImage.nWidth        = w;
        stImage.nHeight       = h;
        stImage.enPixelType   = stFrameOut.stFrameInfo.enPixelType;
        stImage.pImageBuf     = stFrameOut.pBufAddr;
        stImage.nImageLen     = stFrameOut.stFrameInfo.nFrameLenEx;
        stImage.nImageBufSize = stFrameOut.stFrameInfo.nFrameLenEx;

        // 8. 选择保存格式（用 else if，不要用多个独立 if）
        MV_CC_SAVE_IMAGE_PARAM stSaveParam;
        memset(&stSaveParam, 0, sizeof(stSaveParam));

        if (type == "jpeg" || type == "jpg") {
            stSaveParam.enImageType = MV_Image_Jpeg;
        } else if (type == "bmp") {
            stSaveParam.enImageType = MV_Image_Bmp;
        } else if (type == "png") {
            stSaveParam.enImageType = MV_Image_Png;
        } else if (type == "tif" || type == "tiff") {
            stSaveParam.enImageType = MV_Image_Tif;
        } else {
            printf("Unsupported image type: %s\n", type.c_str());
            MV_CC_FreeImageBuffer(m_handle, &stFrameOut);
            return -1;
        }

        stSaveParam.nQuality     = 99;   // JPEG 质量 [50, 99]
        stSaveParam.iMethodValue = 1;    // 插值方法：1-均衡

        // 9. 拼接完整路径：目录 + "/" + 文件名 + "." + 扩展名
        std::string fullPath = address + "/" + name + "." + type;
        if (fullPath.size() >= 256) {
            printf("Path too long (>=256): %s\n", fullPath.c_str());
            MV_CC_FreeImageBuffer(m_handle, &stFrameOut);
            return -1;
        }

        // 10. 保存
        nRet = MV_CC_SaveImageToFileEx2(m_handle, &stImage,
                                        &stSaveParam, fullPath.c_str());

        // 11. 无论成功失败，都要释放缓存
        MV_CC_FreeImageBuffer(m_handle, &stFrameOut);

        if (nRet != MV_OK) {
            printf("MV_CC_SaveImageToFileEx2 failed: 0x%X\n", nRet);
            return nRet;
        }

        printf("Saved: %s\n", fullPath.c_str());
        return MV_OK;
    }

    // 关闭相机：停止取流 -> 关闭设备 -> 销毁句柄 -> 反初始化
    void camStop()
    {
        if (!m_isOpen || m_handle == nullptr) {
            return;
        }

        MV_CC_StopGrabbing(m_handle);
        MV_CC_CloseDevice(m_handle);
        MV_CC_DestroyHandle(m_handle);
        m_handle = nullptr;

        MV_CC_Finalize();
        m_isOpen = false;
        printf("Camera stopped.\n");
    }

    bool isOpen() const { return m_isOpen; }

private:
    void* m_handle = nullptr;
    bool  m_isOpen = false;
};

int main()
{
    Camera cam;

    cam.camStart();
    cam.pictureGet("jpeg", "file", "/home/yan-han/Code/HaiKang");
    cam.camStop();

    return 0;
}