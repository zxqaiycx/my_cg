#pragma once

#include <math.h>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "IDW.h"

using std::vector;
using namespace cv;

#pragma comment(lib, "opencv_world331d.lib")

class Operation
{
public:
    Operation();
    Operation(const Mat& image, const std::string& windowName);
    ~Operation();

public:
    // 用于OpenCV鼠标事件的回调函数
    void OnMouse(int event, int x, int y, int flags, void* param);
    // 创建窗口，显示图像
    void Show();

private:
    // 图像扭曲：srcImage_ -> dstImage_
    void WarpingIDW();
    void WarpingRBF();
    // 图像扭曲后，渲染dstImage_中未改变的像素（根据周围的像素）
    void CompleteImage();
    
private:
    Mat srcImage_;       // 原图像
    Mat dstImage_;       // 扭曲后的图像
    Mat showImage_;      // 用于显示扭曲操作的临时图像
    bool **isChanged_;   // 扭曲操作后，dstImage中每个像素是否改变

    std::string windowName_;

    bool isInput_;      // 是否在输入数据点
    //bool isMove_;       // 是否鼠标单击后移动

    vector<Point> p_;   // 原图中选点
    vector<Point> q_;   // 扭曲后对应点
};