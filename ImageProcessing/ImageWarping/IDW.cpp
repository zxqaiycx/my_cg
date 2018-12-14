
#include "IDW.h"

IDW::IDW() {}

IDW::IDW(const vector<Point>& p_points, const vector<Point>& q_points, const double u)
{
    p_points_ = p_points;
    q_points_ = q_points;
    u_ = u;
}

IDW::~IDW() {}

Point IDW::F(const Point& p, const bool simple)
{
    Point result;
    double x = 0., y = 0.;

    for (int j = 0; j < p_points_.size(); ++j)
    {
        x += Wi(j, p) * Fi(j, p).x;
        y += Wi(j, p) * Fi(j, p).y;
    }

    result.x = (int)x;
    result.y = (int)y;

    return result;
}

double IDW::Distance(const Point& p1, const Point& p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) );
}

double IDW::Wi(const int i, const Point& p)
{
    double sum_sigma = 0;
    for (int j = 0; j < p_points_.size(); ++j)
    {
        if (p == p_points_[j])  // 坐标都是整型，可以直接用==
        {
            if (j != i) { return 0; }
            else { return 1; }
        }

        sum_sigma += 1. / pow( Distance(p, p_points_[j]), u_ );
    }
    double sigma_i = 1. / pow(Distance(p, p_points_[i]), u_);

    return sigma_i / sum_sigma;
}

Point2d IDW::Fi(const int i, const Point& p, const bool simple)
{
    Point2d result;
    if (simple) 
    {
        result.x = q_points_[i].x + 1.0 * (p.x - p_points_[i].x);
        result.y = q_points_[i].y + 1.0 * (p.y - p_points_[i].y);
    }
    else {} // 不考虑T复杂的情况

    return result;
}