
// GLFrameView.cpp : CGLFrameView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CGLFrameView ����/����

CGLFrameView::CGLFrameView()
{
	// TODO: �ڴ˴���ӹ������

}

CGLFrameView::~CGLFrameView()
{
}

BOOL CGLFrameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�CREATESTRUCT cs ���޸Ĵ��������ʽ
    cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	return CView::PreCreateWindow(cs);
}

// CGLFrameView ����

void CGLFrameView::OnDraw(CDC* pDC)
{
	CGLFrameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
    // �����ɫ����Ȼ���
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //���������Ⱦ����

    // Flush����Ⱦ��ˮ��
    glFinish();
    // ����ǰ�󻺴���
    SwapBuffers(pDC->GetSafeHdc());
}


// CGLFrameView ���

#ifdef _DEBUG
void CGLFrameView::AssertValid() const
{
	CView::AssertValid();
}

void CGLFrameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGLFrameDoc* CGLFrameView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGLFrameDoc)));
	return (CGLFrameDoc*)m_pDocument;
}
#endif //_DEBUG


// CGLFrameView ��Ϣ�������


int CGLFrameView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CView::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  �ڴ������ר�õĴ�������
    PIXELFORMATDESCRIPTOR pfd =  
    {  
        sizeof(PIXELFORMATDESCRIPTOR),   // pfd�ṹ�Ĵ�С                               
        1,                                                             // �汾��                                     
        PFD_DRAW_TO_WINDOW |              // ֧���ڴ����л�ͼ                                     
        PFD_SUPPORT_OPENGL |                 // ֧�� OpenGL                                     
        PFD_DOUBLEBUFFER,                        // ˫����ģʽ                                     
        PFD_TYPE_RGBA,                               // RGBA ��ɫģʽ                                     
        24,                                                         // 24 λ��ɫ���                                     
        0, 0, 0, 0, 0, 0,                                     // ������ɫλ                                     
        0,                                                          // û�з�͸���Ȼ���                                     
        0,                                                          // ������λλ                                     
        0,                                                         // ���ۼƻ���                                     
        0, 0, 0, 0,                                            // �����ۼ�λ                                     
        32,                                                      // 32 λ��Ȼ���                                         
        0,                                                       // ��ģ�建��                                     
        0,                                                        // �޸�������                                     
        PFD_MAIN_PLANE,                       // ����                                     
        0,                                                      // ����                                     
        0, 0, 0                                              // ���Բ�,�ɼ��Ժ������ģ       
    }; 
    CClientDC clientdc(this);  
    int pf = ChoosePixelFormat(clientdc.m_hDC, &pfd);  
    BOOL rt = SetPixelFormat(clientdc.m_hDC,pf, &pfd);  
    hglrc = wglCreateContext(clientdc.m_hDC);
    //������ɫ
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    //��Ȼ��� 1������κζ�����ʾ����
    glClearDepth(1.0f);
    //���ͨ���ȽϺ����ֵ�����仯�ˣ�����и�����Ȼ������Ĳ���
    glEnable(GL_DEPTH_TEST);

    return 0;
}


void CGLFrameView::OnDestroy()
{
    CView::OnDestroy();

    // TODO: �ڴ˴������Ϣ����������
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

    // TODO: �ڴ˴������Ϣ����������
    GLsizei w = cx;
    GLsizei h = cy;
    if (!h) { return; }

    CClientDC clientDC(this);
    wglMakeCurrent(clientDC.m_hDC, hglrc);
    glViewport(0, 0, w, h);
    wglMakeCurrent(NULL, NULL);
}
