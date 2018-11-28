
// GLFrameView.cpp : CGLFrameView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "GLFrame.h"
#endif

#include "GLFrameDoc.h"
#include "GLFrameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGLFrameView

IMPLEMENT_DYNCREATE(CGLFrameView, CView)

BEGIN_MESSAGE_MAP(CGLFrameView, CView)
    ON_WM_CREATE()
    ON_WM_DESTROY()
    ON_WM_SIZE()
END_MESSAGE_MAP()

// CGLFrameView 构造/析构

CGLFrameView::CGLFrameView()
{
	// TODO: 在此处添加构造代码

}

CGLFrameView::~CGLFrameView()
{
}

BOOL CGLFrameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改CREATESTRUCT cs 来修改窗口类或样式
    cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	return CView::PreCreateWindow(cs);
}

// CGLFrameView 绘制

void CGLFrameView::OnDraw(CDC* pDC)
{
	CGLFrameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
    // 清除颜色、深度缓存
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //可以添加渲染函数

    // Flush掉渲染流水线
    glFinish();
    // 交换前后缓存区
    SwapBuffers(pDC->GetSafeHdc());
}


// CGLFrameView 诊断

#ifdef _DEBUG
void CGLFrameView::AssertValid() const
{
	CView::AssertValid();
}

void CGLFrameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGLFrameDoc* CGLFrameView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGLFrameDoc)));
	return (CGLFrameDoc*)m_pDocument;
}
#endif //_DEBUG


// CGLFrameView 消息处理程序


int CGLFrameView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CView::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  在此添加您专用的创建代码
    PIXELFORMATDESCRIPTOR pfd =  
    {  
        sizeof(PIXELFORMATDESCRIPTOR),   // pfd结构的大小                               
        1,                                                             // 版本号                                     
        PFD_DRAW_TO_WINDOW |              // 支持在窗口中绘图                                     
        PFD_SUPPORT_OPENGL |                 // 支持 OpenGL                                     
        PFD_DOUBLEBUFFER,                        // 双缓存模式                                     
        PFD_TYPE_RGBA,                               // RGBA 颜色模式                                     
        24,                                                         // 24 位颜色深度                                     
        0, 0, 0, 0, 0, 0,                                     // 忽略颜色位                                     
        0,                                                          // 没有非透明度缓存                                     
        0,                                                          // 忽略移位位                                     
        0,                                                         // 无累计缓存                                     
        0, 0, 0, 0,                                            // 忽略累计位                                     
        32,                                                      // 32 位深度缓存                                         
        0,                                                       // 无模板缓存                                     
        0,                                                        // 无辅助缓存                                     
        PFD_MAIN_PLANE,                       // 主层                                     
        0,                                                      // 保留                                     
        0, 0, 0                                              // 忽略层,可见性和损毁掩模       
    }; 
    CClientDC clientdc(this);  
    int pf = ChoosePixelFormat(clientdc.m_hDC, &pfd);  
    BOOL rt = SetPixelFormat(clientdc.m_hDC,pf, &pfd);  
    hglrc = wglCreateContext(clientdc.m_hDC);
    //背景颜色
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    //深度缓存 1最大，让任何都能显示出来
    glClearDepth(1.0f);
    //如果通过比较后深度值发生变化了，会进行更新深度缓冲区的操作
    glEnable(GL_DEPTH_TEST);

    return 0;
}


void CGLFrameView::OnDestroy()
{
    CView::OnDestroy();

    // TODO: 在此处添加消息处理程序代码
    if (wglGetCurrentContext() != NULL)
    {
        wglMakeCurrent(NULL, NULL);
    }
    if (hglrc != NULL)
    {
        wglDeleteContext(hglrc);
        hglrc = NULL;
    }
}


void CGLFrameView::OnSize(UINT nType, int cx, int cy)
{
    CView::OnSize(nType, cx, cy);

    // TODO: 在此处添加消息处理程序代码
    GLsizei w = cx;
    GLsizei h = cy;
    if (!h) { return; }

    CClientDC clientDC(this);
    wglMakeCurrent(clientDC.m_hDC, hglrc);
    glViewport(0, 0, w, h);
    wglMakeCurrent(NULL, NULL);
}
