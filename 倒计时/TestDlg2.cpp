// TestDlg2.cpp : 实现文件
//

#include "stdafx.h"
#include "倒计时.h"
#include "TestDlg2.h"
#include "afxdialogex.h"
//#include "倒计时Dlg.h"

// CTestDlg2 对话框

IMPLEMENT_DYNAMIC(CTestDlg2, CDialogEx)

CTestDlg2::CTestDlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CTestDlg2::~CTestDlg2()
{
}

void CTestDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDlg2, CDialogEx)
END_MESSAGE_MAP()


// CTestDlg2 消息处理程序

BOOL CTestDlg2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString strBuf,strTemp, strText;
	m_file.ReadData("text.txt", strText);
	GetDlgItem(IDC_EDIT_DATA)->SetWindowTextW(strText);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

