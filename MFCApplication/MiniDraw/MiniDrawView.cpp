
// MiniDrawView.cpp : CMiniDrawView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MiniDraw.h"
#endif

#include "MiniDrawDoc.h"
#include "MiniDrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMiniDrawView

IMPLEMENT_DYNCREATE(CMiniDrawView, CView)

BEGIN_MESSAGE_MAP(CMiniDrawView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_BUTTON_LINE, &CMiniDrawView::OnButtonLine)
	ON_COMMAND(ID_BUTTON_ELLIPSE, &CMiniDrawView::OnButtonEllipse)
	ON_COMMAND(ID_BUTTON_RECT, &CMiniDrawView::OnButtonRect)
	ON_COMMAND(ID_BUTTON_POLYGON, &CMiniDrawView::OnButtonPolygon)
	ON_COMMAND(ID_BUTTON_FREEHAND, &CMiniDrawView::OnButtonFreehand)
	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
ON_WM_MOUSEMOVE()
ON_WM_LBUTTONUP()
ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMiniDrawView 构造/析构

CMiniDrawView::CMiniDrawView()
	: m_bDragging(false), m_uCurrentTool(ID_BUTTON_LINE)
{
	// TODO: 在此处添加构造代码
}

CMiniDrawView::~CMiniDrawView()
{
	for (unsigned i = 0; i < m_FigArray.size(); ++i)
	{
		if (NULL != m_FigArray[i])
		{
			delete m_FigArray[i];
			m_FigArray[i] = NULL;
		}
	}
	//std::vector<MyFigure *>().swap(m_FigArray);
	m_FigArray.clear();
	m_FigArray.shrink_to_fit();
}

BOOL CMiniDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMiniDrawView 绘制

void CMiniDrawView::OnDraw(CDC* pDC)
{
	CMiniDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	// 填充为空，新绘制的图形不会挡住旧的
	pDC->SelectStockObject(NULL_BRUSH);
	for (unsigned i = 0; i < m_FigArray.size(); ++i)
	{
		m_FigArray[i]->Draw(pDC);
	}
}


// CMiniDrawView 打印

BOOL CMiniDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMiniDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMiniDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMiniDrawView 诊断

#ifdef _DEBUG
void CMiniDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMiniDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMiniDrawDoc* CMiniDrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMiniDrawDoc)));
	return (CMiniDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CMiniDrawView 消息处理程序


void CMiniDrawView::OnButtonLine()
{
	// TODO: 在此添加命令处理程序代码
	m_uCurrentTool = ID_BUTTON_LINE;
}


void CMiniDrawView::OnButtonEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_uCurrentTool = ID_BUTTON_ELLIPSE;
}


void CMiniDrawView::OnButtonRect()
{
	// TODO: 在此添加命令处理程序代码
	m_uCurrentTool = ID_BUTTON_RECT;
}


void CMiniDrawView::OnButtonPolygon()
{
	// TODO: 在此添加命令处理程序代码
	m_uCurrentTool = ID_BUTTON_POLYGON;
	MyFigure *pFig = new MyPolygon;
	m_FigArray.push_back(pFig);
}


void CMiniDrawView::OnButtonFreehand()
{
	// TODO: 在此添加命令处理程序代码
	m_uCurrentTool = ID_BUTTON_FREEHAND;
}


void CMiniDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_PointOrigin = point;
	m_PointPrev = point;
	m_bDragging = true;

	MyFigure *pFig = NULL;
	switch (m_uCurrentTool)
	{
	case ID_BUTTON_POLYGON:
		pFig = m_FigArray.back();
		pFig->AddPoint(point);
		break;
	case ID_BUTTON_FREEHAND:
		pFig = new MyFreehand(point);
		m_FigArray.push_back(pFig);
		break;
	default:
		break;
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMiniDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!m_bDragging)
	{
		return;
	}

	CClientDC clientDC(this);
	clientDC.SelectStockObject(NULL_BRUSH);

	switch (m_uCurrentTool)
	{
	case ID_BUTTON_LINE:
		clientDC.SetROP2(R2_NOT);
		clientDC.MoveTo(m_PointOrigin);
		clientDC.LineTo(m_PointPrev);
		clientDC.MoveTo(m_PointOrigin);
		clientDC.LineTo(point);
		m_PointPrev = point;
		break;
	case ID_BUTTON_ELLIPSE:
		clientDC.SetROP2(R2_NOT);
		clientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, m_PointPrev.x, m_PointPrev.y);
		clientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		m_PointPrev = point;
		break;
	case ID_BUTTON_RECT:
		clientDC.SetROP2(R2_NOT);
		clientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, m_PointPrev.x, m_PointPrev.y);
		clientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y);
		m_PointPrev = point;
		break;
	case ID_BUTTON_POLYGON:
		clientDC.SetROP2(R2_NOT);
		clientDC.MoveTo(m_PointOrigin);
		clientDC.LineTo(m_PointPrev);
		clientDC.MoveTo(m_PointOrigin);
		clientDC.LineTo(point);
		m_PointPrev = point;
		break;
	case ID_BUTTON_FREEHAND:
		//clientDC.SetPixel(point, RGB(0, 0, 0));
		clientDC.MoveTo(m_PointPrev);
		clientDC.LineTo(point);
		m_PointPrev = point;
		m_FigArray.back()->AddPoint(point);
		break;
	default:
		break;
	}

	CView::OnMouseMove(nFlags, point);
}


void CMiniDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!m_bDragging)
	{
		return;
	}
	m_bDragging = false;

	CClientDC clientDC(this);
	clientDC.SelectStockObject(NULL_BRUSH);

	MyFigure *pFig = NULL;
	switch (m_uCurrentTool)
	{
	case ID_BUTTON_LINE:
		clientDC.SetROP2(R2_COPYPEN);
		clientDC.MoveTo(m_PointOrigin);
		clientDC.LineTo(m_PointPrev);
		pFig = new MyLine(m_PointOrigin.x, m_PointOrigin.y, m_PointPrev.x, m_PointPrev.y);
		m_FigArray.push_back(pFig);
		break;
	case ID_BUTTON_ELLIPSE:
		clientDC.SetROP2(R2_COPYPEN);
		clientDC.Ellipse(m_PointOrigin.x, m_PointOrigin.y, m_PointPrev.x, m_PointPrev.y);
		pFig = new MyEllipse(m_PointOrigin.x, m_PointOrigin.y, m_PointPrev.x, m_PointPrev.y);
		m_FigArray.push_back(pFig);
		break;
	case ID_BUTTON_RECT:
		clientDC.SetROP2(R2_COPYPEN);
		clientDC.Rectangle(m_PointOrigin.x, m_PointOrigin.y, m_PointPrev.x, m_PointPrev.y);
		pFig = new MyRect(m_PointOrigin.x, m_PointOrigin.y, m_PointPrev.x, m_PointPrev.y);
		m_FigArray.push_back(pFig);
		break;
	case ID_BUTTON_POLYGON:
		m_bDragging = true;
		break;
	case ID_BUTTON_FREEHAND:
		//clientDC.SetPixel(point, RGB(0, 0, 0));
		clientDC.SetROP2(R2_COPYPEN);
		pFig = m_FigArray.back();
		pFig->Draw(&clientDC);
		break;
	default:
		break;
	}

	CView::OnLButtonUp(nFlags, point);
}


void CMiniDrawView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	// 用于画多边形时终止选点
	CClientDC clientDC(this);
	clientDC.SelectStockObject(NULL_BRUSH);
	MyFigure *pFig = NULL;
	switch (m_uCurrentTool)
	{
	case ID_BUTTON_POLYGON:
		// 鼠标指针拖动状态设为false
		m_bDragging = false;
		// 清除最后一条多余的线
		/*clientDC.SetROP2(R2_NOT);
		clientDC.MoveTo(m_PointOrigin);
		clientDC.LineTo(m_PointPrev);*/
		// 绘制多边形
		m_FigArray.back()->Draw(&clientDC);
		// new下一个多边形对象的指针并存入m_FigArray
		pFig = new MyPolygon;
		m_FigArray.push_back(pFig);
		break;
	default:
		break;
	}

	CView::OnLButtonDblClk(nFlags, point);
}
