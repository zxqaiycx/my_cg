#pragma once

#include <math.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
using cv::Mat;
using cv::Mat_;
using cv::Scalar;
using cv::Vec3d;

#pragma comment(lib, "opencv_world331d.lib")
//#pragma comment(lib, "opencv_world331.lib")

class ColorTransfer
{
public:
    ColorTransfer(const Mat &source, const Mat &target);
    void RGB2Lab(const Mat &img_rgb, Mat &img_lab);
    void Lab2RGB(const Mat &img_lab, Mat &img_rgb);
    void CalcMeanSd(const Mat &img, Mat &mean, Mat &sd);
    void Transfer();
public:
    Mat source_;
    Mat target_;
    Mat result_;
};