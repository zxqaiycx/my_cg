
// MiniDraw.h : MiniDraw Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMiniDrawApp:
// �йش����ʵ�֣������ MiniDraw.cpp
//

class CMiniDrawApp : public CWinAppEx
{
public:
	CMiniDrawApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMiniDrawApp theApp;
