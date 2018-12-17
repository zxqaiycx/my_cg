
// GLFrameView.h : CGLFrameView ��Ľӿ�
//

#pragma once


class CGLFrameView : public CView
{
protected: // �������л�����
	CGLFrameView();
	DECLARE_DYNCREATE(CGLFrameView)

// ����
public:
	CGLFrameDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CGLFrameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

public:
    HGLRC hglrc;
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnDestroy();
    afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // GLFrameView.cpp �еĵ��԰汾
inline CGLFrameDoc* CGLFrameView::GetDocument() const
   { return reinterpret_cast<CGLFrameDoc*>(m_pDocument); }
#endif
