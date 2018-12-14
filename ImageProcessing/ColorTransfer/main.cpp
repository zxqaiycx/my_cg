// 
// Copyright
// License
// Author: XiaoqianZhang
// 
// 本程序实现了颜色迁移：根据目标图像调整原图像的颜色特征。
// source + target -> result
//  

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "ColorTransfer.h"
using namespace cv;

int main()
{
    //Mat source = imread("source0.jpg");
    //namedWindow("source", WINDOW_AUTOSIZE);
    //imshow("source", source);
    //Mat target = imread("target0.jpg");
    //namedWindow("target", WINDOW_AUTOSIZE);
    //imshow("target", target);
    //ColorTransfer example0(source, target);
    //namedWindow("result", WINDOW_AUTOSIZE);
    //imshow("result", example0.result_);

    Mat source = imread("source0.jpg");
    Mat target = imread("target0.jpg");
    ColorTransfer eg(source, target);
    Mat matWrite;
    eg.result_.convertTo(matWrite, CV_8U, 255.0);
    imwrite("result0.jpg", matWrite);

    // 在同一窗口显示三个图像
    Mat matAll(Size(eg.source_.cols + eg.target_.cols + 30, eg.source_.rows + eg.result_.rows + 30),
        eg.source_.type(), Scalar::all(0));
    Mat matRoi = matAll(Rect(10, 10, eg.source_.cols, eg.source_.rows));
    eg.source_.copyTo(matRoi);
    matRoi = matAll(Rect(eg.source_.cols + 20, 10, eg.target_.cols, eg.target_.rows));
    eg.target_.copyTo(matRoi);
    matRoi = matAll(Rect(10, eg.source_.rows + 20, eg.result_.cols, eg.result_.rows));
    eg.result_.copyTo(matRoi);
    
    namedWindow("result", WINDOW_NORMAL);
    imshow("result", matAll);
    waitKey(0);
    return 0;
}