
// Rasterization.h : Rasterization Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CRasterizationApp:
// �йش����ʵ�֣������ Rasterization.cpp
//

class CRasterizationApp : public CWinAppEx
{
public:
	CRasterizationApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRasterizationApp theApp;
