// 
// Copyright
// License
// Author: XiaoqianZhang
// 
// ������ʵ������ɫǨ�ƣ�����Ŀ��ͼ�����ԭͼ�����ɫ������
// source + target -> result
//  

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "ColorTransfer.h"
using cv::Mat;
using cv::imread;
using cv::namedWindow;
using cv::imshow;
using cv::WINDOW_AUTOSIZE;

int main()
{
    Mat source = imread("source0.jpg");
    namedWindow("source", WINDOW_AUTOSIZE);
    imshow("source", source);
    Mat target = imread("target0.jpg");
    namedWindow("target", WINDOW_AUTOSIZE);
    imshow("target", target);

    ColorTransfer eg0(source, target);
    namedWindow("result", WINDOW_AUTOSIZE);
    imshow("result", eg0.result_);

    cv::waitKey(0);
    return 0;
}