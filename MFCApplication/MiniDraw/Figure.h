
// Figure.h : CFigure�༰������Ľӿ�
//

#pragma once


// CFigure�ࣺ����ͼ���������
class CFigure
{
public:
	CFigure();
public:
	virtual void Draw(CDC *pDC);
};


// �߶�
class CLine : public CFigure
{
public:
	CLine();
	CLine(int x1, int y1,	
		  int x2, int y2);	
public:
	void Draw(CDC *pDC);
private:
	int m_x1, m_y1,	// ���
		m_x2, m_y2;	// �յ�
};


// ��Բ
class CEllipse : public CFigure
{
public:
	CEllipse();
	CEllipse(int x1, int y1,	
			 int x2, int y2);	
public:
	void Draw(CDC *pDC);
private:
	int m_x1, m_y1,	// ��Բ��������
		m_x2, m_y2;	// ��Բ���ҡ�����
};