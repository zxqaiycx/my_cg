
// MiniDrawView.cpp : CMiniDrawView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CMiniDrawView ����/����

CMiniDrawView::CMiniDrawView()
	: m_bDragging(false), m_uCurrentTool(ID_BUTTON_LINE)
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMiniDrawView ����

void CMiniDrawView::OnDraw(CDC* pDC)
{
	CMiniDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	// ���Ϊ�գ��»��Ƶ�ͼ�β��ᵲס�ɵ�
	pDC->SelectStockObject(NULL_BRUSH);
	for (unsigned i = 0; i < m_FigArray.size(); ++i)
	{
		m_FigArray[i]->Draw(pDC);
	}
}


// CMiniDrawView ��ӡ

BOOL CMiniDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMiniDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMiniDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMiniDrawView ���

#ifdef _DEBUG
void CMiniDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMiniDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMiniDrawDoc* CMiniDrawView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMiniDrawDoc)));
	return (CMiniDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CMiniDrawView ��Ϣ�������


void CMiniDrawView::OnButtonLine()
{
	// TODO: �ڴ���������������
	m_uCurrentTool = ID_BUTTON_LINE;
}


void CMiniDrawView::OnButtonEllipse()
{
	// TODO: �ڴ���������������
	m_uCurrentTool = ID_BUTTON_ELLIPSE;
}


void CMiniDrawView::OnButtonRect()
{
	// TODO: �ڴ���������������
	m_uCurrentTool = ID_BUTTON_RECT;
}


void CMiniDrawView::OnButtonPolygon()
{
	// TODO: �ڴ���������������
	m_uCurrentTool = ID_BUTTON_POLYGON;
	MyFigure *pFig = new MyPolygon;
	m_FigArray.push_back(pFig);
}


void CMiniDrawView::OnButtonFreehand()
{
	// TODO: �ڴ���������������
	m_uCurrentTool = ID_BUTTON_FREEHAND;
}


void CMiniDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

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
		/*clientDC.SetROP2(R2_NOT);
		clientDC.MoveTo(m_PointOrigin);
		clientDC.LineTo(m_PointPrev);*/
		// ���ƶ����
		m_FigArray.back()->Draw(&clientDC);
		// new��һ������ζ����ָ�벢����m_FigArray
		pFig = new MyPolygon;
		m_FigArray.push_back(pFig);
		break;
	default:
		break;
	}

	CView::OnLButtonDblClk(nFlags, point);
}
