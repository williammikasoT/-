
// ����ʱ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C����ʱApp: 
// �йش����ʵ�֣������ ����ʱ.cpp
//

class C����ʱApp : public CWinApp
{
public:
	C����ʱApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C����ʱApp theApp;