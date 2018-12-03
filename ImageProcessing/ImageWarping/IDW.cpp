
#include "IDW.h"
#include <math.h>

IDW::IDW() {}

IDW::IDW(const vector<Point>& p_points, const vector<Point>& q_points, const double u = 2.0)
{
    p_points_ = p_points;
    q_points_ = q_points;
    u_ = u;
}

IDW::~IDW() {}

Point IDW::F(const Point& p, const bool simple = true)
{

}

double IDW::Wi(const int i, const Point& p)
{

}

double IDW::Fi(const int i, const Point& p, const bool simple = true)
{

}