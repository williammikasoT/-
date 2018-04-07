
// 倒计时Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "TestDlg1.h"
#include "TestDlg2.h"



// C倒计时Dlg 对话框
class C倒计时Dlg : public CDialogEx
{
// 构造
public:
	C倒计时Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	int m_CurSelTab;
	CTestDlg1 m_page1;
	CTestDlg2 m_page2;
	CDialog* pDialog[2];

	afx_msg LRESULT OnMyMsgHandler(WPARAM,LPARAM);
	

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void OnClose();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_Tab;
	FileClass m_FileWrite;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);

	
};
