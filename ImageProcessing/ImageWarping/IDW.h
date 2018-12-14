#pragma once

#include <math.h>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
using std::vector;
using cv::Point;
using cv::Point2d;

#pragma comment(lib, "opencv_world331d.lib")

class IDW
{
public:
    IDW();
    IDW(const vector<Point>& p_points, const vector<Point>& q_points, const double u = 2.0);
    ~IDW();

public:
    // IDW�㷨�н���pӳ�䵽ͼ����κ��q�ĺ���F��F = ��Wi*Fi��
    // ����������ԣ���F(p_i) = q_i
    // simpleΪtrueʱ������Fi�еı任����T������λ��
    Point F(const Point& p, const bool simple = true);

private:
    double Distance(const Point& p1, const Point& p2);
    double Wi(const int i, const Point& p);
    Point2d Fi(const int i, const Point& p, const bool simple = true);

private:
    vector<Point> p_points_;
    vector<Point> q_points_;
    double u_;
};