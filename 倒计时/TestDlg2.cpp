// TestDlg2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʱ.h"
#include "TestDlg2.h"
#include "afxdialogex.h"
//#include "����ʱDlg.h"

// CTestDlg2 �Ի���

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


// CTestDlg2 ��Ϣ�������

BOOL CTestDlg2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString strBuf,strTemp, strText;
	m_file.ReadData("text.txt", strText);
	GetDlgItem(IDC_EDIT_DATA)->SetWindowTextW(strText);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

