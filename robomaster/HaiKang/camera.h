#ifndef CAMERA_H
#define CAMERA_H

#include <MvErrorDefine.h>
#include <CameraParams.h>
#include <MvISPErrorDefine.h>
#include <MvObsoleteInterfaces.h>
#include <ObsoleteCamParams.h>
#include <PixelType.h>
#include <MvCameraControl.h>

#include <string>

class Camera
{
public:
    Camera();
    ~Camera();
    int camStart();
    int pictureGet(const std::string& type,
                   const std::string& name,
                   const std::string& address);
    void camStop();

private:
    void* m_handle = nullptr;
    bool  m_isOpen = false;
};

#endif