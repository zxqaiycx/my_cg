
// MFCApp21View.h : CMFCApp21View ��Ľӿ�
//

#pragma once


class CMFCApp21View : public CView
{
protected: // �������л�����
	CMFCApp21View();
	DECLARE_DYNCREATE(CMFCApp21View)

// ����
public:
	CMFCApp21Doc* GetDocument() const;

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
	virtual ~CMFCApp21View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApp21View.cpp �еĵ��԰汾
inline CMFCApp21Doc* CMFCApp21View::GetDocument() const
   { return reinterpret_cast<CMFCApp21Doc*>(m_pDocument); }
#endif

