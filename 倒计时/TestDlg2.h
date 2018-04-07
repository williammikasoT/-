#pragma once

#include  "filefunc.h"		// 文件操作
// CTestDlg2 对话框

class CTestDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg2)

public:
	CTestDlg2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTestDlg2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	FileClass m_file;
	DECLARE_MESSAGE_MAP()
public:
};
