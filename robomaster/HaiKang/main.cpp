#include "camera.h"

int main()
{
    Camera cam;

    cam.camStart();
    cam.pictureGet("jpeg", "file", "/home/yan-han/Code/HaiKang");
    cam.camStop();

    return 0;
}