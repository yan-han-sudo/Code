#include "hikeSDK.h"

#include <cstring>
#include <cstddef>
#include <cstdio>

#define Check(x) \
    do { \
        if ((x) != MV_OK) { \
            printf("SDK error: 0x%X at line %d\n", (x), __LINE__); \
            return (x); \
        } \
    } while (0)

int main()
{
    int nRet = MV_OK;

    // 1. 初始化 SDK
    nRet = MV_CC_Initialize();
    Check(nRet);

    // 2. 枚举 GigE / USB 相机
    MV_CC_DEVICE_INFO_LIST stDeviceList;
    memset(&stDeviceList, 0, sizeof(stDeviceList));
    nRet = MV_CC_EnumDevicesEx2(MV_GIGE_DEVICE | MV_USB_DEVICE,
                                &stDeviceList, nullptr,
                                SortMethod_SerialNumber);
    Check(nRet);

    if (stDeviceList.nDeviceNum == 0) {
        printf("No camera found.\n");
        MV_CC_Finalize();
        return -1;
    }
    printf("Found %u camera(s).\n", stDeviceList.nDeviceNum);

    // 3. 创建句柄（选第 0 个设备）
    void* handle = nullptr;
    nRet = MV_CC_CreateHandle(&handle, stDeviceList.pDeviceInfo[0]);
    Check(nRet);

    // 4. 打开设备
    nRet = MV_CC_OpenDevice(handle);
    Check(nRet);

    // 5. 开始取流
    nRet = MV_CC_StartGrabbing(handle);
    Check(nRet);

    // 6. 主动获取一帧图像（超时 1000ms）
    MV_FRAME_OUT stFrameOut;
    memset(&stFrameOut, 0, sizeof(stFrameOut));
    nRet = MV_CC_GetImageBuffer(handle, &stFrameOut, 1000);
    Check(nRet);

    printf("Get frame: Width[%d], Height[%d], FrameLen[%lld], FrameNum[%d]\n",
           stFrameOut.stFrameInfo.nExtendWidth,
           stFrameOut.stFrameInfo.nExtendHeight,
           (long long)stFrameOut.stFrameInfo.nFrameLenEx,
           stFrameOut.stFrameInfo.nFrameNum);

    // 7. 保存为 JPEG
    MV_CC_IMAGE stImage;
    memset(&stImage, 0, sizeof(stImage));
    stImage.nWidth        = stFrameOut.stFrameInfo.nExtendWidth;
    stImage.nHeight       = stFrameOut.stFrameInfo.nExtendHeight;
    stImage.enPixelType   = stFrameOut.stFrameInfo.enPixelType;
    stImage.pImageBuf     = stFrameOut.pBufAddr;
    stImage.nImageLen     = stFrameOut.stFrameInfo.nFrameLenEx;
    stImage.nImageBufSize = stFrameOut.stFrameInfo.nFrameLenEx;

    MV_CC_SAVE_IMAGE_PARAM stSaveParam;
    memset(&stSaveParam, 0, sizeof(stSaveParam));
    stSaveParam.enImageType  = MV_Image_Jpeg;   // 保存为 JPEG
    stSaveParam.nQuality     = 99;              // JPEG 质量 (50-99]
    stSaveParam.iMethodValue = 1;               // 插值方法：1-均衡

    char chImageName[256] = { 0 };
    snprintf(chImageName, sizeof(chImageName),
             "InPut_w%d_h%d_fn%03d.jpg",
             stImage.nWidth, stImage.nHeight,
             stFrameOut.stFrameInfo.nFrameNum);

    nRet = MV_CC_SaveImageToFileEx2(handle, &stImage, &stSaveParam, chImageName);
    Check(nRet);
    printf("Saved: %s\n", chImageName);

    // 8. 释放图像缓存（与 GetImageBuffer 配套）
    nRet = MV_CC_FreeImageBuffer(handle, &stFrameOut);
    Check(nRet);

    // 9. 停止取流
    nRet = MV_CC_StopGrabbing(handle);
    Check(nRet);

    // 10. 关闭设备
    nRet = MV_CC_CloseDevice(handle);
    Check(nRet);

    // 11. 销毁句柄
    nRet = MV_CC_DestroyHandle(handle);
    Check(nRet);

    // 12. 反初始化
    MV_CC_Finalize();
    return 0;
}