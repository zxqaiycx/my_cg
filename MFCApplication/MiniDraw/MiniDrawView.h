
// MiniDrawView.h : CMiniDrawView 类的接口
//

#pragma once

#include "Figure.h"
#include <vector>


class CMiniDrawView : public CView
{
protected: // 仅从序列化创建
	CMiniDrawView();
	DECLARE_DYNCREATE(CMiniDrawView)

// 特性
public:
	CMiniDrawDoc* GetDocument() const;

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
	virtual ~CMiniDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

// 自定义部分
private:
	std::vector<MyFigure *> m_FigArray;
	UINT m_uCurrentTool;	// 图形类型
	BOOL m_bDragging;		// 是否在拖动鼠标
	CPoint m_PointOrigin;	// 起点
	CPoint m_PointPrev;		// 上一次的终点
public:
	afx_msg void OnButtonLine();
	afx_msg void OnButtonEllipse();
	afx_msg void OnButtonRect();
	afx_msg void OnButtonPolygon();
	afx_msg void OnButtonFreehand();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MiniDrawView.cpp 中的调试版本
inline CMiniDrawDoc* CMiniDrawView::GetDocument() const
   { return reinterpret_cast<CMiniDrawDoc*>(m_pDocument); }
#endif

