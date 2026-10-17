#include "head.h"

class Cam1 : public Camera;
class Cam2 : public Camera;

int main()
{
    Cam1 cam1;
    Cam2 cam2;

    Cam1::Camera::getCam();

    cam1.startCam(0);
    cam1.startGrab();
    cam1.getPicture("jpeg", "file1", "/home/yan-han/Code/HaiKang_refine");
    cam1.stopGrab();
    cam1.stopCam();

    cam2.startCam(1);
    cam2.startGrab();
    cam2.getPicture("png", "file2", "/home/yan-han/Code/HaiKang_refine");
    cam2.stopGrab();
    cam2.stopCam();

    return 0;
}