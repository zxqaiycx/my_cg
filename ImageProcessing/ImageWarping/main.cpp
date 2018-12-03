// 
// Copyright
// License
// Author: XiaoqianZhang
// 
// 本程序实现了图像变形，使用的方法为反距离加权插值（IDW）
// Reference:
// 1.Image Warping with Scattered Data Interpolation
// 2.Image Warping by Radial Basis Functions: Application to Facial Expressions
//

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "Operation.h"
using namespace cv;

Operation *gPtr;

void onMouse(int event, int x, int y, int flags, void* param)
{
    gPtr->OnMouse(event, x, y, flags, param);
}

int main()
{
    Mat img = imread("monalisa.jpg", 1);
    std::string windowName("ImageWarping");
    namedWindow(windowName);

    Operation op(img, windowName);
    gPtr = &op;

    setMouseCallback(windowName, onMouse, 0);

    waitKey();

    return 0;
}