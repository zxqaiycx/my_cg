
// Figure.h : Figure类及其子类的实现
//

#include "stdafx.h"
#include "Figure.h"


// 以下为CFigure类的实现

CFigure::CFigure() {}

void CFigure::Draw(CDC *pDC) {}


// 以下为CLine类的实现

CLine::CLine() {}

CLine::CLine(int x1, int y1, int x2, int y2)
	: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}

void CLine::Draw(CDC *pDC)
{
	pDC->MoveTo(m_x1, m_y1);
	pDC->LineTo(m_x2, m_y2);
}


// 以下为CEllipse类的实现

CEllipse::CEllipse() {}

CEllipse::CEllipse(int x1, int y1, int x2, int y2)
	: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2) {}

void CEllipse::Draw(CDC *pDC)
{
	pDC->Ellipse(m_x1, m_y1, m_x2, m_y2);
}
