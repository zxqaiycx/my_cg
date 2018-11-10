
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

private:
	std::vector<CFigure *> m_FigArray;
	UINT m_CurrentTool;	//ͼ������
};

#ifndef _DEBUG  // MiniDrawView.cpp �еĵ��԰汾
inline CMiniDrawDoc* CMiniDrawView::GetDocument() const
   { return reinterpret_cast<CMiniDrawDoc*>(m_pDocument); }
#endif

