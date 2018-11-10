
// MFCApp21View.cpp : CMFCApp21View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApp21.h"
#endif

#include "MFCApp21Doc.h"
#include "MFCApp21View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApp21View

IMPLEMENT_DYNCREATE(CMFCApp21View, CView)

BEGIN_MESSAGE_MAP(CMFCApp21View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCApp21View 构造/析构

CMFCApp21View::CMFCApp21View()
{
	// TODO: 在此处添加构造代码

}

CMFCApp21View::~CMFCApp21View()
{
}

BOOL CMFCApp21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApp21View 绘制

void CMFCApp21View::OnDraw(CDC* pDC)
{
	CMFCApp21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	RECT ClientRect;
	GetClientRect(&ClientRect);
	pDC->DrawTextW(pDoc->GetGreeting(), -1, &ClientRect, DT_LEFT);
}


// CMFCApp21View 打印

BOOL CMFCApp21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApp21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApp21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApp21View 诊断

#ifdef _DEBUG
void CMFCApp21View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApp21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApp21Doc* CMFCApp21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApp21Doc)));
	return (CMFCApp21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApp21View 消息处理程序
