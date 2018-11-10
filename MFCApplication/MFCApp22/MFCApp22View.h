
// MFCApp22View.h : CMFCApp22View ��Ľӿ�
//

#pragma once

#include <vector>
#include "CLine.h"


class CMFCApp22View : public CView
{
protected: // �������л�����
	CMFCApp22View();
	DECLARE_DYNCREATE(CMFCApp22View)

// ����
public:
	CMFCApp22Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFCApp22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

private:
	int m_nDragging;
	CPoint m_PointOrigin;
	CPoint m_PointOld;
	std::vector<CLine *> m_LineArray;
	
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApp22View.cpp �еĵ��԰汾
inline CMFCApp22Doc* CMFCApp22View::GetDocument() const
   { return reinterpret_cast<CMFCApp22Doc*>(m_pDocument); }
#endif

