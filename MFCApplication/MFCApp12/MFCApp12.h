
// MFCApp12.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCApp12App: 
// �йش����ʵ�֣������ MFCApp12.cpp
//

class CMFCApp12App : public CWinApp
{
public:
	CMFCApp12App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCApp12App theApp;