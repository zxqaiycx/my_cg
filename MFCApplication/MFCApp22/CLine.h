#pragma once

#include <afxwin.h>

//线段数据结构
class CLine
{
private:
	int m_X1, m_Y1,
		m_X2, m_Y2;
public:
	CLine(int X1 = 0, int Y1 = 0, int X2 = 0, int Y2 = 0)
		: m_X1(X1), m_Y1(Y1), m_X2(X2), m_Y2(Y2)
	{}

	void DrawLine(CDC *pDC)
	{
		pDC->MoveTo(m_X1, m_Y1);
		pDC->LineTo(m_X2, m_Y2);
	}
};