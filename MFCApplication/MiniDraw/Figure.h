
// Figure.h : MyFigure�༰������Ľӿ�
//

#pragma once

#include <vector>


// MyFigure�ࣺ����ͼ����ĸ���
class MyFigure
{
public:
	MyFigure();
	~MyFigure();
public:
	virtual void Draw(CDC *pDC);
	virtual void AddPoint(const CPoint& pointToAdd);
};


// �߶�
class MyLine : public MyFigure
{
public:
	MyLine(int x1, int y1, 
		int x2, int y2);	
public:
	void Draw(CDC *pDC);
private:
	int m_x1, m_y1,	// ���
		m_x2, m_y2;	// �յ�
};


// ��Բ
class MyEllipse : public MyFigure
{
public:
	MyEllipse(int x1, int y1, 
		int x2, int y2);	
public:
	void Draw(CDC *pDC);
private:
	int m_x1, m_y1,	// ��Բ��������
		m_x2, m_y2;	// ��Բ���ҡ�����
};


// ����
class MyRect : public MyFigure
{
public:
	MyRect(int x1, int y1, 
		int x2, int y2);
public:
	void Draw(CDC *pDC);
private:
	int m_x1, m_y1,	// ������������
		m_x2, m_y2;	// �������ҡ�����
};


// �����
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


// �����ֻ���
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