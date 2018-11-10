
// MFCApp22View.h : CMFCApp22View 类的接口
//

#pragma once

#include <vector>
#include "CLine.h"


class CMFCApp22View : public CView
{
protected: // 仅从序列化创建
	CMFCApp22View();
	DECLARE_DYNCREATE(CMFCApp22View)

// 特性
public:
	CMFCApp22Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCApp22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // MFCApp22View.cpp 中的调试版本
inline CMFCApp22Doc* CMFCApp22View::GetDocument() const
   { return reinterpret_cast<CMFCApp22Doc*>(m_pDocument); }
#endif

