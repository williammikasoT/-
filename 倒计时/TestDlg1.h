#pragma once


// CTestDlg1 对话框
#include "ExcelClass.h"


class CTestDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg1)

public:
	CTestDlg1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTestDlg1();

	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_iNum;


// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	ExcelClass m_excle;

	afx_msg void OnBnClickedButtonStar();
	afx_msg void OnBnClickedCheck1();
	afx_msg void ProgressMove(CString strT);
	afx_msg void OnBnClickedCheck2();
	void SaveDataExcel(CString strText, CString strTime);
	afx_msg void OnBnClickedButtonLog();
};
