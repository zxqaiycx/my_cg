
// MFCApp21View.h : CMFCApp21View 类的接口
//

#pragma once


class CMFCApp21View : public CView
{
protected: // 仅从序列化创建
	CMFCApp21View();
	DECLARE_DYNCREATE(CMFCApp21View)

// 特性
public:
	CMFCApp21Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCApp21View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApp21View.cpp 中的调试版本
inline CMFCApp21Doc* CMFCApp21View::GetDocument() const
   { return reinterpret_cast<CMFCApp21Doc*>(m_pDocument); }
#endif

