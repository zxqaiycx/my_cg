
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
END_MESSAGE_MAP()

// CMiniDrawView ����/����

CMiniDrawView::CMiniDrawView()
{
	// TODO: �ڴ˴���ӹ������
	m_CurrentTool = 0;
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

void CMiniDrawView::OnDraw(CDC* /*pDC*/)
{
	CMiniDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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
