#pragma once


// CTestDlg1 �Ի���
#include "ExcelClass.h"


class CTestDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg1)

public:
	CTestDlg1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTestDlg1();

	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_iNum;


// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
