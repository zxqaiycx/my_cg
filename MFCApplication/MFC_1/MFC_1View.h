
// MFC_1View.h : CMFC_1View 类的接口
//

#pragma once


class CMFC_1View : public CView
{
protected: // 仅从序列化创建
	CMFC_1View();
	DECLARE_DYNCREATE(CMFC_1View)

// 特性
public:
	CMFC_1Doc* GetDocument() const;

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
	virtual ~CMFC_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC_1View.cpp 中的调试版本
inline CMFC_1Doc* CMFC_1View::GetDocument() const
   { return reinterpret_cast<CMFC_1Doc*>(m_pDocument); }
#endif

