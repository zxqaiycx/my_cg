
// MiniDrawView.h : CMiniDrawView ��Ľӿ�
//

#pragma once

#include "Figure.h"
#include <vector>


class CMiniDrawView : public CView
{
protected: // �������л�����
	CMiniDrawView();
	DECLARE_DYNCREATE(CMiniDrawView)

// ����
public:
	CMiniDrawDoc* GetDocument() const;

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
	virtual ~CMiniDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

// �Զ��岿��
private:
	std::vector<MyFigure *> m_FigArray;	// �洢�����ѻ���ͼ�ζ����ָ��
	std::vector<CPoint> m_PointsPoly;	// ���ƶ����ʱ�ݴ涥��
	UINT m_uCurrentTool;				// ͼ������
	BOOL m_bDragging;					// �Ƿ����϶����
	CPoint m_PointOrigin;				// ���
	CPoint m_PointPrev;					// ��һ�ε��յ�
public:
	afx_msg void OnButtonLine();
	afx_msg void OnButtonEllipse();
	afx_msg void OnButtonRect();
	afx_msg void OnButtonPolygon();
	afx_msg void OnButtonFreehand();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButtonUndo();
	afx_msg void OnButtonClear();
};

#ifndef _DEBUG  // MiniDrawView.cpp �еĵ��԰汾
inline CMiniDrawDoc* CMiniDrawView::GetDocument() const
   { return reinterpret_cast<CMiniDrawDoc*>(m_pDocument); }
#endif

