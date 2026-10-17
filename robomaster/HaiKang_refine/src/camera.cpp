//#include "head.h"
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#include <CameraParams.h>
#include <MvISPErrorDefine.h>
#include <MvObsoleteInterfaces.h>
#include <ObsoleteCamParams.h>
#include <PixelType.h>
#include <MvCameraControl.h>
#include <MvErrorDefine.h>

class Camera
{
protected:
    int result;
    void * handle = nullptr;

    Camera()
    {
        result = MV_CC_Initialize();
        check(result);
    }
    ~ Camera()
    {
        MV_CC_Finalize();
    }

    void check(int x)
    {
        if(x != MV_OK)
        {
            printf("SDK error: 0x%X at line %d\n", (x), __LINE__);
        }
    }

    MV_CC_DEVICE_INFO_LIST deviceList;

    void getCam()
    {
        memset(&deviceList, 0, sizeof(deviceList));
        result = MV_CC_EnumDevicesEx2(MV_GIGE_DEVICE | MV_USB_DEVICE , &deviceList, nullptr , SortMethod_SerialNumber);
        check(result);

        if (deviceList.nDeviceNum == 0) 
        {
            printf("No camera found.\n");
            MV_CC_Finalize();
        }
        printf("Found %u camera(s).\n", deviceList.nDeviceNum);
    }

    void startCam(int num)
    {
        result = MV_CC_CreateHandle(&handle, deviceList.pDeviceInfo[num]);
        check(result);

        result = MV_CC_OpenDevice(handle);
        check(result);
    }

    void stopCam()
    {
        result = MV_CC_CloseDevice(handle);
        check(result);

        result = MV_CC_DestroyHandle(handle);
        check(result);
    }

    void static __stdcall ImageCallBackEx(unsigned char * pData, MV_FRAME_OUT_INFO_EX * pFrameInfo, void * pUser)
    {
        if(pFrameInfo != nullptr)
        {
            printf("Get One Frame: Width[%d], Height[%d], FrameLen[%I64d] nFrameNum[%d]\n", 
            pFrameInfo->nExtendWidth, pFrameInfo->nExtendHeight, pFrameInfo->nFrameLenEx,pFrameInfo->nFrameNum);
        }
    }

    void startGrab()
    {
        result = MV_CC_RegisterImageCallBackEx(handle, ImageCallBackEx, handle);
        check(result);

        result = MV_CC_SetImageNodeNum(handle, 5);
        check(result);

        result = MV_CC_StartGrabbing(handle);
        check(result);
    }

    void stopGrab()
    {
        result = MV_CC_StopGrabbing(handle);
        check(result);
    }

    void getPicture(const string& type , const string& name, const string& address)
    {
        char chImageName[IMAGE_NAME_LEN] = { 0 };
        MV_CC_IMAGE stImage;
        memset(&stImage, 0, sizeof(MV_CC_IMAGE));
        MV_CC_SAVE_IMAGE_PARAM stSaveImageParam;
        memset(&stSaveImageParam, 0, sizeof(MV_CC_SAVE_IMAGE_PARAM));
        stImage.enPixelType = stImageInfo.stFrameInfo.enPixelType;
        stImage.nHeight = stImageInfo.stFrameInfo.nExtendWidth;
        stImage.nWidth = stImageInfo.stFrameInfo.nExtendHeight;
        stImage.nImageBufLen = stImageInfo.stFrameInfo.nFrameLenEx;
        stImage.pImageBuf = stImageInfo.pBufAddr;
        stSaveImageParam.iMethodValue = 1;
        if(type == "bmp")
        {
            stSaveImageParam.enImageType = MV_Image_Bmp;
            sprintf_s(chImageName, IMAGE_NAME_LEN, "InPut_w%d_h%d_fn%03d.bmp", stImage.nWidth, stImage.nHeight, stImageInfo.stFrameInfo.nFrameNum);
        }
        else if(type == "jpeg")
        {
            stSaveImageParam.enImageType = MV_Image_Jpeg;
            stSaveImageParam.nQuality = 99;
            sprintf_s(chImageName, IMAGE_NAME_LEN, "InPut_w%d_h%d_fn%03d.jpeg", stImage.nWidth, stImage.nHeight, stImageInfo.stFrameInfo.nFrameNum);
        }
        else if(type == "png")
        {
            stSaveImageParam.enImageType = MV_Image_Png;
            sprintf_s(chImageName, IMAGE_NAME_LEN, "InPut_w%d_h%d_fn%03d.png", stImage.nWidth, stImage.nHeight, stImageInfo.stFrameInfo.nFrameNum);
        }
        else if(type == "tif")
        {
            stSaveImageParam.enImageType = MV_Image_Tif;
            sprintf_s(chImageName, IMAGE_NAME_LEN, "InPut_w%d_h%d_fn%03d.png", stImage.nWidth, stImage.nHeight, stImageInfo.stFrameInfo.nFrameNum);
        }
        
        result = MV_CC_SaveImageToFileEx2(handle, &stImage, &stSaveImageParam, chImageName);
        check(result);
    }
};