
// MFCApp11.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCApp11App: 
// �йش����ʵ�֣������ MFCApp11.cpp
//

class CMFCApp11App : public CWinApp
{
public:
	CMFCApp11App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCApp11App theApp;