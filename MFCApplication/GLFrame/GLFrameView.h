
// GLFrameView.h : CGLFrameView 类的接口
//

#pragma once

#include "gl/glut.h"

//#ifdef _MSC_VER                         // Check if MS Visual C compiler
//#  pragma comment(lib, "opengl32.lib")  // Compiler-specific directive to avoid manually configuration
//#  pragma comment(lib, "glu32.lib")     // Link libraries
//#  pragma comment(lib, "glut32.lib")
//#endif

class CGLFrameView : public CView
{
protected: // 仅从序列化创建
	CGLFrameView();
	DECLARE_DYNCREATE(CGLFrameView)

// 特性
public:
	CGLFrameDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CGLFrameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

public:
    HGLRC hglrc;
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnDestroy();
    afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // GLFrameView.cpp 中的调试版本
inline CGLFrameDoc* CGLFrameView::GetDocument() const
   { return reinterpret_cast<CGLFrameDoc*>(m_pDocument); }
#endif

