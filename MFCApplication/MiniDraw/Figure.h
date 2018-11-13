
// Figure.h : CFigure类及其子类的接口
//

#pragma once


// CFigure类：各种图形类的子类
class CFigure
{
public:
	CFigure();
public:
	virtual void Draw(CDC *pDC);
};


// 线段
class CLine : public CFigure
{
public:
	CLine();
	CLine(int x1, int y1,	
		  int x2, int y2);	
public:
	void Draw(CDC *pDC);
private:
	int m_x1, m_y1,	// 起点
		m_x2, m_y2;	// 终点
};


// 椭圆
class CEllipse : public CFigure
{
public:
	CEllipse();
	CEllipse(int x1, int y1,	
			 int x2, int y2);	
public:
	void Draw(CDC *pDC);
private:
	int m_x1, m_y1,	// 椭圆最左、最上
		m_x2, m_y2;	// 椭圆最右、最下
};