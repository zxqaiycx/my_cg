
// MFCApp21View.cpp : CMFCApp21View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCApp21View ����/����

CMFCApp21View::CMFCApp21View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCApp21View::~CMFCApp21View()
{
}

BOOL CMFCApp21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApp21View ����

void CMFCApp21View::OnDraw(CDC* pDC)
{
	CMFCApp21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	RECT ClientRect;
	GetClientRect(&ClientRect);
	pDC->DrawTextW(pDoc->GetGreeting(), -1, &ClientRect, DT_LEFT);
}


// CMFCApp21View ��ӡ

BOOL CMFCApp21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCApp21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCApp21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCApp21View ���

#ifdef _DEBUG
void CMFCApp21View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApp21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApp21Doc* CMFCApp21View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApp21Doc)));
	return (CMFCApp21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApp21View ��Ϣ�������
