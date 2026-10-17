#ifndef HEAD_H
#define HEAD_H

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

    Camera();
    ~Camera();

    void check(int x);
    void getCam();
    void startCam(int num);
    void stopCam();
    void static __stdcall ImageCallBackEx(unsigned char * pData, MV_FRAME_OUT_INFO_EX * pFrameInfo, void * pUser);
    void startGrab();
    void stopGrab();
    void getPicture(const string& type , const string& name, const string& address);
};

#endif