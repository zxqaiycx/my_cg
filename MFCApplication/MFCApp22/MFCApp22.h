
// MFCApp22.h : MFCApp22 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApp22App:
// �йش����ʵ�֣������ MFCApp22.cpp
//

class CMFCApp22App : public CWinAppEx
{
public:
	CMFCApp22App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApp22App theApp;
