
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
END_MESSAGE_MAP()

// CMiniDrawView ����/����

CMiniDrawView::CMiniDrawView()
	: m_Dragging(0), m_CurrentTool(ID_BUTTON_LINE), m_PointOld(CPoint(0,0)), m_PointOrigin(CPoint(0,0))
{
	// TODO: �ڴ˴���ӹ������
}

CMiniDrawView::~CMiniDrawView()
{
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
	m_CurrentTool = ID_BUTTON_LINE;
}


void CMiniDrawView::OnButtonEllipse()
{
	// TODO: �ڴ���������������
	m_CurrentTool = ID_BUTTON_ELLIPSE;
}


void CMiniDrawView::OnButtonRect()
{
	// TODO: �ڴ���������������
	m_CurrentTool = ID_BUTTON_RECT;
}


void CMiniDrawView::OnButtonPolygon()
{
	// TODO: �ڴ���������������
	m_CurrentTool = ID_BUTTON_POLYGON;
}


void CMiniDrawView::OnButtonFreehand()
{
	// TODO: �ڴ���������������
	m_CurrentTool = ID_BUTTON_FREEHAND;
}


void CMiniDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_PointOrigin = point;
	m_PointOld = point;
	m_Dragging = 1;

	CView::OnLButtonDown(nFlags, point);
}


void CMiniDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (0 != m_Dragging)
	{
		return;
	}

	CClientDC clientDC(this);
	clientDC.SelectStockObject(NULL_BRUSH);

	switch (m_CurrentTool)
	{
	case ID_BUTTON_LINE:
		clientDC.SetROP2(R2_NOT);
		break;
	case ID_BUTTON_ELLIPSE:
		break;
	case ID_BUTTON_RECT:
		break;
	case ID_BUTTON_POLYGON:
		break;
	case ID_BUTTON_FREEHAND:
		break;
	default:
		break;
	}

	CView::OnMouseMove(nFlags, point);
}


void CMiniDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonUp(nFlags, point);
}
