
// MFC_1View.h : CMFC_1View ��Ľӿ�
//

#pragma once


class CMFC_1View : public CView
{
protected: // �������л�����
	CMFC_1View();
	DECLARE_DYNCREATE(CMFC_1View)

// ����
public:
	CMFC_1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFC_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC_1View.cpp �еĵ��԰汾
inline CMFC_1Doc* CMFC_1View::GetDocument() const
   { return reinterpret_cast<CMFC_1Doc*>(m_pDocument); }
#endif
