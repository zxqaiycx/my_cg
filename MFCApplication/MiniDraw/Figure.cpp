
// Figure.h : Figure�༰�������ʵ��
//

#include "stdafx.h"
#include "Figure.h"


// ����ΪCFigure���ʵ��

CFigure::CFigure() {}

void CFigure::Draw(CDC *pDC) {}


// ����ΪCLine���ʵ��

CLine::CLine() {}

CLine::CLine(int x1, int y1, int x2, int y2)
	: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}

void CLine::Draw(CDC *pDC)
{
	pDC->MoveTo(m_x1, m_y1);
	pDC->LineTo(m_x2, m_y2);
}


// ����ΪCEllipse���ʵ��

CEllipse::CEllipse() {}

CEllipse::CEllipse(int x1, int y1, int x2, int y2)
	: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}

void CEllipse::Draw(CDC *pDC)
{
	pDC->Ellipse(m_x1, m_y1, m_x2, m_y2);
}
