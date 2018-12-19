
// Figure.h : MyFigure类及其子类的实现
//

#include "stdafx.h"
#include "Figure.h"


// MyFigure类的实现

MyFigure::MyFigure() {}

MyFigure::~MyFigure() {}

void MyFigure::Draw(CDC *pDC) {}

void MyFigure::AddPoint(const CPoint& pointToAdd)	{}


// MyLine类的实现

MyLine::MyLine(int x1, int y1, int x2, int y2, int type)
	: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_type(type) {}

void MyLine::Draw(CDC *pDC)
{
    this->ScanConversion(pDC);
}

void MyLine::ScanConversion(CDC *pDC)
{
    int x1 = m_x1, y1 = m_y1,
        x2 = m_x2, y2 = m_y2;

    if (x1 == x2 && y1 == y2)
    {
        pDC->SetPixel(x1, y1, RGB(255,0,0));
        return;
    }

    if (0 == m_type)
    {
        pDC->MoveTo(x1, y1);
        pDC->LineTo(x2, y2);
    }
    else if (1 == m_type)   // DDA（写得不好，未考虑斜率正负）
    {
        if (abs(x1 - x2) >= abs(y1 - y2))   // 斜率绝对值小于等于1
        {
            if (x1 > x2)
            {
                x1 = x2;
                y1 = y2;
                x2 = m_x1;
                y2 = m_y1;
            }

            double k = (y2 - y1) * 1.0 / (x2 - x1);
            double y = (double)y1;
            for (int x = x1; x <= x2; ++x)
            {
                pDC->SetPixel(x, int(y + 0.5), RGB(255, 0, 0));
                y += k;
            }
        }
        else    // 斜率绝对值大于1
        {
            if (y1 > y2)
            {
                x1 = x2;
                y1 = y2;
                x2 = m_x1;
                y2 = m_y1;
            }

            double k = (x2 - x1) * 1.0 / (y2 - y1);
            double x = (double)x1;
            for (int y = y1; y <= y2; ++y)
            {
                pDC->SetPixel(int(x + 0.5), y, RGB(0, 255, 0));
                x += k;
            }
        }
    }
    else if (2 == m_type)   // 中点画线法（写得不好）
    {
        // F(x, y) = ax + by + c
        // a = y1 - y2; b = x2 - x1; c = x1y2 - x2y1;
        // 以下的左右方向是对常见的平面直角坐标系来说

        if (abs(x1 - x2) >= abs(y1 - y2))   // 斜率绝对值小于等于1
        {
            if (x1 > x2)
            {
                x1 = x2;
                y1 = y2;
                x2 = m_x1;
                y2 = m_y1;
            }

            if (y2 >= y1)    // 斜率非负
            {
                int a, b, d, d1, d2, x, y;
                a = y1 - y2, b = x2 - x1;
                d = 2 * a + b;
                d1 = 2 * a, d2 = 2 * (a + b);
                x = x1, y = y1;
                pDC->SetPixel(x, y, RGB(255, 0, 0));
                while (x < x2)
                {
                    if (d >= 0)   // 取右方像素
                    {
                        ++x;
                        d += d1;
                    }
                    else    // 取右上方像素
                    {
                        ++x, ++y;
                        d += d2;
                    }
                    pDC->SetPixel(x, y, RGB(255, 0, 0));
                }
            }
            else    // 斜率为负
            {
                int a, b, d, d1, d2, x, y;
                a = y1 - y2, b = x2 - x1;
                d = 2 * a - b;
                d1 = 2 * a, d2 = 2 * (a - b);
                x = x1, y = y1;
                pDC->SetPixel(x, y, RGB(255, 0, 0));
                while (x < x2)
                {
                    if (d <= 0)   // 取右方像素
                    {
                        ++x;
                        d += d1;
                    }
                    else    // 取右下方像素
                    {
                        ++x, --y;
                        d += d2;
                    }
                    pDC->SetPixel(x, y, RGB(255, 0, 0));
                }
            }
        }   // if (abs(x1 - x2) >= abs(y1 - y2))
        else    // 斜率绝对值大于1
        {
            if (y1 > y2)
            {
                x1 = x2;
                y1 = y2;
                x2 = m_x1;
                y2 = m_y1;
            }

            if (x2 >= x1)    // 斜率非负
            {
                int a, b, d, d1, d2, x, y;
                a = x1 - x2, b = y2 - y1;
                d = 2 * a + b;
                d1 = 2 * a, d2 = 2 * (a + b);
                x = x1, y = y1;
                pDC->SetPixel(x, y, RGB(0, 255, 0));
                while (y < y2)
                {
                    if (d >= 0)   // 取上方像素
                    {
                        ++y;
                        d += d1;
                    }
                    else    // 取右上方像素
                    {
                        ++y, ++x;
                        d += d2;
                    }
                    pDC->SetPixel(x, y, RGB(0, 255, 0));
                }
            }
            else    // 斜率为负
            {
                int a, b, d, d1, d2, x, y;
                a = x1 - x2, b = y2 - y1;
                d = 2 * a - b;
                d1 = 2 * a, d2 = 2 * (a - b);
                x = x1, y = y1;
                pDC->SetPixel(x, y, RGB(0, 255, 0));
                while (y < y2)
                {
                    if (d <= 0)   // 取上方像素
                    {
                        ++y;
                        d += d1;
                    }
                    else    // 取左上方像素
                    {
                        ++y, --x;
                        d += d2;
                    }
                    pDC->SetPixel(x, y, RGB(0, 255, 0));
                }
            }
        }
    }
    else if (3 == m_type)   // Bresenham
    {
        if (abs(x1 - x2) >= abs(y1 - y2))    // 斜率绝对值小于等于1
        {
            if (x1 > x2)
            {
                x1 = x2;
                y1 = y2;
                x2 = m_x1;
                y2 = m_y1;
            }

            int dx = x2 - x1, dy = y2 - y1;
            int two_dx = 2 * dx, two_dy = 2 * dy;
            int x, y = y1;

            if (dy >= 0)
            {
                int e = -dx;
                for (x = x1; x <= x2; ++x)
                {
                    pDC->SetPixel(x, y, RGB(255, 0, 0));
                    e += two_dy;
                    if (e >= 0)
                    {
                        ++y;
                        e -= two_dx;
                    }
                }
            }
            else
            {
                int e = dx;
                for (x = x1; x <= x2; ++x)
                {
                    pDC->SetPixel(x, y, RGB(255, 0, 0));
                    e += two_dy;
                    if (e <= 0)
                    {
                        --y;
                        e += two_dx;
                    }
                }
            }
        }
        else    // 斜率绝对值大于1
        {
            if (y1 > y2)
            {
                x1 = x2;
                y1 = y2;
                x2 = m_x1;
                y2 = m_y1;
            }

            int dx = x2 - x1, dy = y2 - y1;
            int two_dx = 2 * dx, two_dy = 2 * dy;
            int x = x1, y;

            if (dx >= 0)   // 斜率非负
            {
                int e = -dy;
                for (y = y1; y <= y2; ++y)
                {
                    pDC->SetPixel(x, y, RGB(0, 255, 0));
                    e += two_dx;
                    if (e >= 0)
                    {
                        ++x;
                        e -= two_dy;
                    }
                }
            }
            else    // 斜率为负
            {
                int e = dy;
                for (y = y1; y <= y2; ++y)
                {
                    pDC->SetPixel(x, y, RGB(0, 255, 0));
                    e += two_dx;
                    if (e <= 0)
                    {
                        --x;
                        e += two_dy;
                    }
                }
            }
        }
    }
    else
    {
        pDC->MoveTo(x1, y1);
        pDC->LineTo(x2, y2);
    }
}


// MyEllipse类的实现

MyEllipse::MyEllipse(int x1, int y1, int x2, int y2)
	: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}

void MyEllipse::Draw(CDC *pDC)
{
	pDC->Ellipse(m_x1, m_y1, m_x2, m_y2);
}


// MyCircle类的实现

MyCircle::MyCircle(int x1, int y1, int x2, int y2, int type)
{
    if (abs(x2 - x1) <= abs(y2 - y1))
    {
        m_radius = abs(x2 - x1) / 2;
        m_x0 = (x1 + x2) / 2;
        m_y0 = y1 + (y2 > y1 ? 1 : -1) * m_radius;
    }
    else
    {
        m_radius = abs(y2 - y1) / 2;
        m_x0 = x1 + (x2 > x1 ? 1 : -1) * m_radius;
        m_y0 = (y1 + y2) / 2;
    }
    
    m_type = type;
}

void MyCircle::Draw(CDC *pDC)
{
    this->ScanConversion(pDC);
}

void MyCircle::ScanConversion(CDC *pDC)
{
    int x0 = m_x0, y0 = m_y0;
    int R = m_radius;

    if (0 == m_type)
    {
        pDC->Ellipse(x0 - R, y0 - R, x0 + R, y0 + R);
    }
    else if (1 == m_type)   // 中点画圆法
    {
        int x = 0, y = R;
        float d = 1.25f - R;

        while (x <= y)
        {
            // 八分画圆
            pDC->SetPixel(x0 + x, y0 + y, RGB(255, 0, 0));
            pDC->SetPixel(x0 - x, y0 + y, RGB(255, 0, 0));
            pDC->SetPixel(x0 - y, y0 + x, RGB(255, 0, 0));
            pDC->SetPixel(x0 - y, y0 - x, RGB(255, 0, 0));
            pDC->SetPixel(x0 - x, y0 - y, RGB(255, 0, 0));
            pDC->SetPixel(x0 + x, y0 - y, RGB(255, 0, 0));
            pDC->SetPixel(x0 + y, y0 - x, RGB(255, 0, 0));
            pDC->SetPixel(x0 + y, y0 + x, RGB(255, 0, 0));

            if (d < 0)
            {
                d = d + 2 * x + 3;
                ++x;
            }
            else
            {
                d = d + 2 * (x - y) + 5;
                ++x, --y;
            }
        }
    }
    else if (2 == m_type)   // Bresenham画圆法
    {
        int x = 0, y = R;
        int d = 3 - 2 * y;

        while (x <= y)
        {
            // 八分画圆
            pDC->SetPixel(x0 + x, y0 + y, RGB(255, 0, 0));
            pDC->SetPixel(x0 - x, y0 + y, RGB(255, 0, 0));
            pDC->SetPixel(x0 - y, y0 + x, RGB(255, 0, 0));
            pDC->SetPixel(x0 - y, y0 - x, RGB(255, 0, 0));
            pDC->SetPixel(x0 - x, y0 - y, RGB(255, 0, 0));
            pDC->SetPixel(x0 + x, y0 - y, RGB(255, 0, 0));
            pDC->SetPixel(x0 + y, y0 - x, RGB(255, 0, 0));
            pDC->SetPixel(x0 + y, y0 + x, RGB(255, 0, 0));

            if (d < 0)
            {
                d = d + 4 * x + 6;
                ++x;
            }
            else
            {
                d = d + 4 * (x - y) + 10;
                ++x, --y;
            }
        }
    }
    else if (3 == m_type)   // 正负法
    {

    }
    else
    {
        pDC->Ellipse(x0 - R, y0 - R, x0 + R, y0 + R);
    }
}


// MyRect类的实现

MyRect::MyRect(int x1, int y1, int x2, int y2)
	: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}

void MyRect::Draw(CDC *pDC)
{
	pDC->Rectangle(m_x1, m_y1, m_x2, m_y2);
}


// MyPolygon的实现

MyPolygon::MyPolygon()
{
	m_points.clear();
}

MyPolygon::MyPolygon(const CPoint& pointToAdd)
{
	m_points.clear();
	m_points.push_back(pointToAdd);
}

MyPolygon::~MyPolygon()
{
	m_points.clear();
	m_points.shrink_to_fit();
}

void MyPolygon::Draw(CDC *pDC)
{
	CPoint *points = new CPoint[m_points.size()];
	for (unsigned i = 0; i < m_points.size(); ++i)
	{
		*(points + i) = m_points[i];
	}
	pDC->Polygon(points, m_points.size());
	delete[] points;
	points = NULL;
}
void MyPolygon::AddPoint(const CPoint& pointToAdd)
{
	m_points.push_back(pointToAdd);
}


// MyFreehand的实现

MyFreehand::MyFreehand()
{
	m_points.clear();
}

MyFreehand::MyFreehand(const CPoint& pointToAdd)
{
	m_points.clear();
	m_points.push_back(pointToAdd);
}

MyFreehand::~MyFreehand()
{
	m_points.clear();
	m_points.shrink_to_fit();
}

void MyFreehand::Draw(CDC *pDC)
{
	CPoint *points = new CPoint[m_points.size()];
	for (unsigned i = 0; i < m_points.size(); ++i)
	{
		*(points + i) = m_points[i];
	}
	pDC->Polyline(points, m_points.size());
	delete[] points;
	points = NULL;
};

void MyFreehand::AddPoint(const CPoint& pointToAdd)
{
	m_points.push_back(pointToAdd);
}