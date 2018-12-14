
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

MyLine::MyLine(int x1, int y1, int x2, int y2, int type = 0)
	: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_type(type) {}

void MyLine::Draw(CDC *pDC)
{
    this->ScanConversion(pDC);
}

void MyLine::ScanConversion(CDC *pDC)
{
    int x1 = m_x1, y1 = m_y1,
        x2 = m_y2, y2 = m_y2;

    if (x1 == x2 && y1 == y2)
    {
        pDC->SetPixel(x1, y1, RGB(0,0,0));
        return;
    }

    if (0 == m_type)
    {
        pDC->MoveTo(x1, y1);
        pDC->LineTo(x2, y2);
    }
    else if (1 == m_type)   // DDA
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
            double k = (y2 - y1) / (x2 - x1);
        }
        else
        {

        }
    }
    else if (2 == m_type)
    {

    }
    else if (2 == m_type)
    {

    }
    else
    {

    }
}


// MyEllipse类的实现

MyEllipse::MyEllipse(int x1, int y1, int x2, int y2)
	: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}

void MyEllipse::Draw(CDC *pDC)
{
	pDC->Ellipse(m_x1, m_y1, m_x2, m_y2);
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