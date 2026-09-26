#include "opencv2/videoio.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream> // IWYU pragma: keep
using namespace std;
using namespace cv;

//读取图片
// int main()
// {
//     string path = "Resources/test.png";
//     Mat img = imread(path);
//     imshow("Image",img);
//     waitKey(0);
// }

// //读取视频
// int main()
// {
//     string path = "/home/yan-han/Code/opencv/Resources/test_video.mp4";
//     VideoCapture cap(path);
//     Mat img;

//     while(true)
//     {
//         cap.read(img);
//         imshow("Image",img);
//         waitKey(20);
//     }
//     return 0;
// }

//读取相机画面
int main()
{
    VideoCapture cap("/dev/video0");
    Mat img;

    while(true)
    {
        cap.read(img);
        imshow("Image",img);
        waitKey(20);
    }
    return 0;
}