
// SalesSystem.h : SalesSystem Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSalesSystemApp:
// �йش����ʵ�֣������ SalesSystem.cpp
//

class CSalesSystemApp : public CWinApp
{
public:
	CSalesSystemApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSalesSystemApp theApp;
