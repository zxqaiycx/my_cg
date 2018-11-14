
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

MyLine::MyLine(int x1, int y1, int x2, int y2)
	: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}

void MyLine::Draw(CDC *pDC)
{
	pDC->MoveTo(m_x1, m_y1);
	pDC->LineTo(m_x2, m_y2);
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