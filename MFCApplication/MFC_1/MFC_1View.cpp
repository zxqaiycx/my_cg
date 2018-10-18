
// MFC_1View.cpp : CMFC_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC_1.h"
#endif

#include "MFC_1Doc.h"
#include "MFC_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_1View

IMPLEMENT_DYNCREATE(CMFC_1View, CView)

BEGIN_MESSAGE_MAP(CMFC_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC_1View ����/����

CMFC_1View::CMFC_1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC_1View::~CMFC_1View()
{
}

BOOL CMFC_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_1View ����

void CMFC_1View::OnDraw(CDC* /*pDC*/)
{
	CMFC_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_1View ��ӡ

BOOL CMFC_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC_1View ���

#ifdef _DEBUG
void CMFC_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_1Doc* CMFC_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_1Doc)));
	return (CMFC_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_1View ��Ϣ�������
