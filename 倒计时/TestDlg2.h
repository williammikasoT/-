#pragma once

#include  "filefunc.h"		// �ļ�����
// CTestDlg2 �Ի���

class CTestDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg2)

public:
	CTestDlg2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTestDlg2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	FileClass m_file;
	DECLARE_MESSAGE_MAP()
public:
};
