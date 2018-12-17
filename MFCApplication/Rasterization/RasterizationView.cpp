
// RasterizationView.cpp : CRasterizationView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CRasterizationView ����/����

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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CRasterizationView ����

void CRasterizationView::OnDraw(CDC* pDC)
{
	CRasterizationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

    // ���Ϊ�գ��»��Ƶ�ͼ�β��ᵲס�ɵ�
    pDC->SelectStockObject(NULL_BRUSH);
    for (unsigned i = 0; i < m_FigArray.size(); ++i)
    {
        m_FigArray[i]->Draw(pDC);
    }
}


// CRasterizationView ��ӡ

BOOL CRasterizationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CRasterizationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CRasterizationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CRasterizationView ���

#ifdef _DEBUG
void CRasterizationView::AssertValid() const
{
	CView::AssertValid();
}

void CRasterizationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRasterizationDoc* CRasterizationView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRasterizationDoc)));
	return (CRasterizationDoc*)m_pDocument;
}
#endif //_DEBUG


// CRasterizationView ��Ϣ�������

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
    // ���ڻ������ʱ��ֹѡ��
    CClientDC clientDC(this);
    clientDC.SelectStockObject(NULL_BRUSH);
    MyFigure *pFig = NULL;
    switch (m_uCurrentTool)
    {
    case ID_BUTTON_POLYGON:
        // ���ָ���϶�״̬��Ϊfalse
        m_bDragging = false;
        // ������һ���������
        clientDC.SetROP2(R2_NOT);
        clientDC.MoveTo(m_PointOrigin);
        clientDC.LineTo(m_PointPrev);
        // �洢�����ƶ����
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
        // �ػ�ͻ���
        CRect rect;
        GetClientRect(&rect);
        InvalidateRect(rect);
    }
}

void CRasterizationView::OnButtonClear()
{
    m_FigArray.clear();
    m_FigArray.shrink_to_fit();
    // �ػ�ͻ���
    CRect rect;
    GetClientRect(&rect);
    InvalidateRect(rect);
}
