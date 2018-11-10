
// MFCApp22View.cpp : CMFCApp22View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApp22.h"
#endif

#include "MFCApp22Doc.h"
#include "MFCApp22View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifndef SAFEDELETE(p)
#define SAFEDELETE(p) {if(p!=NULL){delete p; p=NULL;}}
#endif // !SAFEDELETE(p)


// CMFCApp22View

IMPLEMENT_DYNCREATE(CMFCApp22View, CView)

BEGIN_MESSAGE_MAP(CMFCApp22View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApp22View 构造/析构

CMFCApp22View::CMFCApp22View()
	: m_nDragging(0)
{
	// TODO: 在此处添加构造代码

}

CMFCApp22View::~CMFCApp22View()
{
	for (unsigned i = 0; i < m_LineArray.size(); ++i)
	{
		SAFEDELETE(m_LineArray[i]);
	}
}

BOOL CMFCApp22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApp22View 绘制

void CMFCApp22View::OnDraw(CDC* pDC)
{
	CMFCApp22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (unsigned i = 0; i < m_LineArray.size(); ++i)
	{
		m_LineArray[i]->DrawLine(pDC);
	}
}


// CMFCApp22View 打印

BOOL CMFCApp22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApp22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApp22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApp22View 诊断

#ifdef _DEBUG
void CMFCApp22View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApp22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApp22Doc* CMFCApp22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApp22Doc)));
	return (CMFCApp22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApp22View 消息处理程序


void CMFCApp22View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_PointOrigin = point;
	m_PointOld = point;
	m_nDragging = 1;

	CView::OnLButtonDown(nFlags, point);
}


void CMFCApp22View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (0 == m_nDragging)
	{
		return;
	}

	CClientDC clientDC(this);

	clientDC.SetROP2(R2_NOT);
	clientDC.MoveTo(m_PointOrigin);
	clientDC.LineTo(m_PointOld);

	clientDC.SetROP2(R2_COPYPEN); //使用当前的画笔的颜色
	clientDC.MoveTo(m_PointOrigin);
	clientDC.LineTo(point);

	m_nDragging = 0;

	CLine *pLine = NULL;
	pLine = new CLine(m_PointOrigin.x, m_PointOrigin.y,
		point.x, point.y);
	m_LineArray.push_back(pLine);

	CView::OnLButtonUp(nFlags, point);
}


void CMFCApp22View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (0 == m_nDragging)
	{
		return;
	}
	
	CClientDC clientDC(this);
	clientDC.SetROP2(R2_NOT); //设置当前前景色的混合模式，R2_NOT为取反。
	clientDC.MoveTo(m_PointOrigin);
	clientDC.LineTo(m_PointOld);
	
	clientDC.MoveTo(m_PointOrigin);
	clientDC.LineTo(point);

	m_PointOld = point;

	CView::OnMouseMove(nFlags, point);
}
