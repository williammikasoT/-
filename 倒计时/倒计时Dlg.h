
// ����ʱDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "TestDlg1.h"
#include "TestDlg2.h"



// C����ʱDlg �Ի���
class C����ʱDlg : public CDialogEx
{
// ����
public:
	C����ʱDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	int m_CurSelTab;
	CTestDlg1 m_page1;
	CTestDlg2 m_page2;
	CDialog* pDialog[2];

	afx_msg LRESULT OnMyMsgHandler(WPARAM,LPARAM);
	

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
