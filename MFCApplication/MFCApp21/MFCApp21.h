
// MFCApp21.h : MFCApp21 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApp21App:
// �йش����ʵ�֣������ MFCApp21.cpp
//

class CMFCApp21App : public CWinApp
{
public:
	CMFCApp21App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApp21App theApp;
