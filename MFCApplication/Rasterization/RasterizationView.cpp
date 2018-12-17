
// RasterizationView.cpp : CRasterizationView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Rasterization.h"
#endif

#include "RasterizationDoc.h"
#include "RasterizationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRasterizationView

IMPLEMENT_DYNCREATE(CRasterizationView, CView)

BEGIN_MESSAGE_MAP(CRasterizationView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_COMMAND(ID_BUTTON_LINE, &CRasterizationView::OnButtonLine)
    ON_COMMAND(ID_BUTTON_ELLIPSE, &CRasterizationView::OnButtonEllipse)
    ON_COMMAND(ID_BUTTON_RECT, &CRasterizationView::OnButtonRect)
    ON_COMMAND(ID_BUTTON_POLYGON, &CRasterizationView::OnButtonPolygon)
    ON_COMMAND(ID_BUTTON_FREEHAND, &CRasterizationView::OnButtonFreehand)
    ON_COMMAND(ID_BUTTON_UNDO, &CRasterizationView::OnButtonUndo)
    ON_COMMAND(ID_BUTTON_CLEAR, &CRasterizationView::OnButtonClear)
    ON_WM_LBUTTONDOWN()
    ON_WM_MOUSEMOVE()
    ON_WM_LBUTTONUP()
    ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CRasterizationView 构造/析构

CRasterizationView::CRasterizationView()
{
    m_uCurrentTool = ID_BUTTON_LINE;
    m_bDragging = false;
}

CRasterizationView::~CRasterizationView()
{
    for (unsigned i = 0; i < m_FigArray.size(); ++i)
    {
        if (NULL != m_FigArray[i])
        {
            delete m_FigArray[i];
            m_FigArray[i] = NULL;
        }
    }
}

BOOL CRasterizationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CRasterizationView 绘制

void CRasterizationView::OnDraw(CDC* pDC)
{
	CRasterizationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

    // 填充为空，新绘制的图形不会挡住旧的
    pDC->SelectStockObject(NULL_BRUSH);
    for (unsigned i = 0; i < m_FigArray.size(); ++i)
    {
        m_FigArray[i]->Draw(pDC);
    }
}


// CRasterizationView 打印

BOOL CRasterizationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CRasterizationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CRasterizationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CRasterizationView 诊断

#ifdef _DEBUG
void CRasterizationView::AssertValid() const
{
	CView::AssertValid();
}

void CRasterizationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRasterizationDoc* CRasterizationView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRasterizationDoc)));
	return (CRasterizationDoc*)m_pDocument;
}
#endif //_DEBUG


// CRasterizationView 消息处理程序

void CRasterizationView::OnButtonLine()
{
    m_uCurrentTool = ID_BUTTON_LINE;
}

void CRasterizationView::OnButtonEllipse()
{
    m_uCurrentTool = ID_BUTTON_ELLIPSE;
}

void CRasterizationView::OnButtonRect()
{
    m_uCurrentTool = ID_BUTTON_RECT;
}

void CRasterizationView::OnButtonPolygon()
{
    m_uCurrentTool = ID_BUTTON_POLYGON;
}

void CRasterizationView::OnButtonFreehand()
{
    m_uCurrentTool = ID_BUTTON_FREEHAND;
}

void CRasterizationView::OnLButtonDown(UINT nFlags, CPoint point)
{
    m_PointOrigin = point;
    m_PointPrev = point;
    m_bDragging = true;

    MyFigure *pFig = NULL;
    switch (m_uCurrentTool)
    {
    case ID_BUTTON_POLYGON:
        m_PointsPoly.push_back(point);
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

void CRasterizationView::OnMouseMove(UINT nFlags, CPoint point)
{
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

void CRasterizationView::OnLButtonUp(UINT nFlags, CPoint point)
{
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
        clientDC.SetROP2(R2_NOT);
        clientDC.MoveTo(m_PointOrigin);
        clientDC.LineTo(m_PointPrev);
        clientDC.SetROP2(R2_COPYPEN);
        pFig = new MyLine(m_PointOrigin.x, m_PointOrigin.y, point.x, point.y, 2);
        pFig->Draw(&clientDC);
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

void CRasterizationView::OnRButtonDown(UINT nFlags, CPoint point)
{
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
        clientDC.SetROP2(R2_NOT);
        clientDC.MoveTo(m_PointOrigin);
        clientDC.LineTo(m_PointPrev);
        // 存储并绘制多边形
        pFig = new MyPolygon;
        for (unsigned i = 0; i < m_PointsPoly.size(); ++i)
        {
            pFig->AddPoint(m_PointsPoly[i]);
        }
        m_PointsPoly.clear();
        m_PointsPoly.shrink_to_fit();
        m_FigArray.push_back(pFig);
        clientDC.SetROP2(R2_COPYPEN);
        pFig->Draw(&clientDC);
        break;
    default:
        break;
    }

    CView::OnRButtonDown(nFlags, point);
}

void CRasterizationView::OnButtonUndo()
{
    if (m_FigArray.size() > 0)
    {
        m_FigArray.pop_back();
        // 重绘客户区
        CRect rect;
        GetClientRect(&rect);
        InvalidateRect(rect);
    }
}

void CRasterizationView::OnButtonClear()
{
    m_FigArray.clear();
    m_FigArray.shrink_to_fit();
    // 重绘客户区
    CRect rect;
    GetClientRect(&rect);
    InvalidateRect(rect);
}
