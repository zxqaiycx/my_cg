
// MFCApp22View.cpp : CMFCApp22View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCApp22View ����/����

CMFCApp22View::CMFCApp22View()
	: m_nDragging(0)
{
	// TODO: �ڴ˴���ӹ������

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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApp22View ����

void CMFCApp22View::OnDraw(CDC* pDC)
{
	CMFCApp22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (unsigned i = 0; i < m_LineArray.size(); ++i)
	{
		m_LineArray[i]->DrawLine(pDC);
	}
}


// CMFCApp22View ��ӡ

BOOL CMFCApp22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCApp22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCApp22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCApp22View ���

#ifdef _DEBUG
void CMFCApp22View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApp22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApp22Doc* CMFCApp22View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApp22Doc)));
	return (CMFCApp22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApp22View ��Ϣ�������


void CMFCApp22View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_PointOrigin = point;
	m_PointOld = point;
	m_nDragging = 1;

	CView::OnLButtonDown(nFlags, point);
}


void CMFCApp22View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (0 == m_nDragging)
	{
		return;
	}

	CClientDC clientDC(this);

	clientDC.SetROP2(R2_NOT);
	clientDC.MoveTo(m_PointOrigin);
	clientDC.LineTo(m_PointOld);

	clientDC.SetROP2(R2_COPYPEN); //ʹ�õ�ǰ�Ļ��ʵ���ɫ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (0 == m_nDragging)
	{
		return;
	}
	
	CClientDC clientDC(this);
	clientDC.SetROP2(R2_NOT); //���õ�ǰǰ��ɫ�Ļ��ģʽ��R2_NOTΪȡ����
	clientDC.MoveTo(m_PointOrigin);
	clientDC.LineTo(m_PointOld);
	
	clientDC.MoveTo(m_PointOrigin);
	clientDC.LineTo(point);

	m_PointOld = point;

	CView::OnMouseMove(nFlags, point);
}
