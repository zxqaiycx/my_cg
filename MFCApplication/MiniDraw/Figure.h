
// Figure.h : MyFigure类及其子类的接口
//

#pragma once

#include <vector>


// MyFigure类：各种图形类的父类
class MyFigure
{
public:
	MyFigure();
	~MyFigure();
public:
	virtual void Draw(CDC *pDC);
	virtual void AddPoint(const CPoint& pointToAdd);
};


// 线段
class MyLine : public MyFigure
{
public:
	MyLine(int x1, int y1, 
		int x2, int y2);	
public:
	void Draw(CDC *pDC);
private:
	int m_x1, m_y1,	// 起点
		m_x2, m_y2;	// 终点
};


// 椭圆
class MyEllipse : public MyFigure
{
public:
	MyEllipse(int x1, int y1, 
		int x2, int y2);	
public:
	void Draw(CDC *pDC);
private:
	int m_x1, m_y1,	// 椭圆最左、最上
		m_x2, m_y2;	// 椭圆最右、最下
};


// 矩形
class MyRect : public MyFigure
{
public:
	MyRect(int x1, int y1, 
		int x2, int y2);
public:
	void Draw(CDC *pDC);
private:
	int m_x1, m_y1,	// 矩形最左、最上
		m_x2, m_y2;	// 矩形最右、最下
};


// 多边形
class MyPolygon : public MyFigure
{
public:
	MyPolygon();
	MyPolygon(const CPoint& pointToAdd);
	~MyPolygon();
public:
	void Draw(CDC *pDC);
	void AddPoint(const CPoint& pointToAdd);
private:
	std::vector<CPoint> m_points;
};


// 自由手绘线
class MyFreehand : public MyFigure
{
public:
	MyFreehand();
	MyFreehand(const CPoint& pointToAdd);
	~MyFreehand();
public:
	void Draw(CDC *pDC);
	void AddPoint(const CPoint& pointToAdd);
private:
	std::vector<CPoint> m_points;
};