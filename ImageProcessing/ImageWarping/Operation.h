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
    // ����OpenCV����¼��Ļص�����
    void OnMouse(int event, int x, int y, int flags, void* param);
    // �������ڣ���ʾͼ��
    void Show();

private:
    // ͼ��Ť����srcImage_ -> dstImage_
    void WarpingIDW();
    void WarpingRBF();
    // ͼ��Ť������ȾdstImage_��δ�ı�����أ�������Χ�����أ�
    void CompleteImage();
    
private:
    Mat srcImage_;       // ԭͼ��
    Mat dstImage_;       // Ť�����ͼ��
    Mat showImage_;      // ������ʾŤ����������ʱͼ��
    bool **isChanged_;   // Ť��������dstImage��ÿ�������Ƿ�ı�

    std::string windowName_;

    bool isInput_;      // �Ƿ����������ݵ�
    //bool isMove_;       // �Ƿ���굥�����ƶ�

    vector<Point> p_;   // ԭͼ��ѡ��
    vector<Point> q_;   // Ť�����Ӧ��
};