// TestDlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "倒计时.h"
#include "TestDlg1.h"
#include "afxdialogex.h"




// CTestDlg1 对话框

IMPLEMENT_DYNAMIC(CTestDlg1, CDialogEx)

CTestDlg1::CTestDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CTestDlg1::~CTestDlg1()
{
}

void CTestDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDlg1, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_STAR, &CTestDlg1::OnBnClickedButtonStar)
	ON_BN_CLICKED(IDC_CHECK1, &CTestDlg1::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CTestDlg1::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_BUTTON_LOG, &CTestDlg1::OnBnClickedButtonLog)
END_MESSAGE_MAP()


// CTestDlg1 消息处理程序



BOOL CTestDlg1::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	GetDlgItem(IDC_EDIT_WORK1)->SetWindowTextW(L"测试使用");
	GetDlgItem(IDC_EDIT_LONG1)->SetWindowTextW(L"1");

	m_excle.InitExcel();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestDlg1::ProgressMove(CString strT)
{
	int i = _ttoi(strT);
	m_iNum = i * 60; // 分钟转换为秒
	CProgressCtrl* pProgCtrl = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS1);
	pProgCtrl->SetPos(0);
	pProgCtrl->SetRange(0, m_iNum);
	pProgCtrl->SetStep(1);
	SetTimer(1, 1000, NULL);
}

void CTestDlg1::OnBnClickedCheck1()
{
	CString strT;
	CButton *pCheckBox = (CButton*)GetDlgItem(IDC_CHECK1);
	if (pCheckBox->GetCheck())
	{
		GetDlgItem(IDC_EDIT_WORK1)->GetWindowTextW(strT);
		if (strT.IsEmpty())
		{
			MessageBox(L"请填写任务!",L"系统提示");
			pCheckBox->SetCheck(0);
			return ;
		}

		GetDlgItem(IDC_EDIT_LONG1)->GetWindowTextW(strT);
		if (strT.IsEmpty())
		{
			MessageBox(L"请填写多少分钟!", L"提示");
			return;
		}
		ProgressMove(strT);
		GetDlgItem(IDC_BUTTON_STAR)->EnableWindow(TRUE);
	}
	else {
		KillTimer(1);
		GetDlgItem(IDC_BUTTON_STAR)->EnableWindow(FALSE);
	}
	
}

void CTestDlg1::OnBnClickedCheck2()
{
	CString strT;
	CButton *pCheckBox = (CButton*)GetDlgItem(IDC_CHECK2);
	if (pCheckBox->GetCheck())
	{
		GetDlgItem(IDC_EDIT_WORK2)->GetWindowTextW(strT);
		if (strT.IsEmpty())
		{
			MessageBox(L"请填写任务!", L"系统提示");
			pCheckBox->SetCheck(0);
			return;
		}

		GetDlgItem(IDC_EDIT_LONG2)->GetWindowTextW(strT);
		if (strT.IsEmpty())
		{
			MessageBox(L"请填写多少分钟!", L"提示");
			return;
		}
		ProgressMove(strT);
		GetDlgItem(IDC_BUTTON_STAR)->EnableWindow(TRUE);
	}
	else {
		KillTimer(1);
		GetDlgItem(IDC_BUTTON_STAR)->EnableWindow(FALSE);
	}

}

void CTestDlg1::OnBnClickedButtonStar()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strText, strName;
	GetDlgItem(IDC_BUTTON_STAR)->GetWindowTextW(strName);
	if (strName == L"暂停")
	{
		KillTimer(1);
		GetDlgItem(IDC_BUTTON_STAR)->SetWindowTextW(L"开始");
	}
	else {
		SetTimer(1, 1000, NULL);
		GetDlgItem(IDC_BUTTON_STAR)->SetWindowTextW(L"暂停");
	}
}

void CTestDlg1::SaveDataExcel(CString strText, CString strTime)
{
	std::vector<CString> vStr;
	vStr.push_back(strText);
	vStr.push_back(strTime);
	m_excle.WriteExcel(vStr, L"\\模版.xlsx", TRUE);
}

void CTestDlg1::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case 1:
		if (m_iNum--)
		{
			CProgressCtrl* pProgCtrl = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS1);
			int nPrePos = pProgCtrl->StepIt();
		}
		else {
			KillTimer(1);

			CString strText, strTime;
			CButton *pCheckBox = (CButton*)GetDlgItem(IDC_CHECK1);
			if (pCheckBox->GetCheck())
			{
				GetDlgItem(IDC_EDIT_WORK1)->GetWindowTextW(strText);
				GetDlgItem(IDC_EDIT_LONG1)->GetWindowTextW(strTime);
				SaveDataExcel(strText, strTime);
			}
			else
			{
				GetDlgItem(IDC_EDIT_WORK2)->GetWindowTextW(strText);
				GetDlgItem(IDC_EDIT_LONG2)->GetWindowTextW(strTime);
				SaveDataExcel(strText, strTime);
			}
			GetDlgItem(IDC_BUTTON_STAR)->EnableWindow(FALSE);
			MessageBox(L"时间到了请注意！", L"提示");
		}
		break;


	}

	CDialogEx::OnTimer(nIDEvent);
}


void CTestDlg1::OnBnClickedButtonLog()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(0, _T("open"),L"模版.xlsx", NULL, NULL, SW_NORMAL);
}
