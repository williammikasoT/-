
// ����ʱDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʱ.h"
#include "����ʱDlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C����ʱDlg �Ի���



C����ʱDlg::C����ʱDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);  //�ĳ�����ʾ��ͼ��
}

void C����ʱDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
}

BEGIN_MESSAGE_MAP(C����ʱDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &C����ʱDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// C����ʱDlg ��Ϣ�������

BOOL C����ʱDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_Tab.InsertItem(0, L"��ʱ");
	m_Tab.InsertItem(1, L"����");

	m_page1.Create(IDD_DIALOG1, &m_Tab);
	m_page2.Create(IDD_DIALOG2, &m_Tab);

	CRect rc;
	m_Tab.GetClientRect(rc);
	rc.top += 20;
	m_page1.MoveWindow(&rc);
	m_page2.MoveWindow(&rc);

	pDialog[0] = &m_page1;
	pDialog[1] = &m_page2;

	pDialog[0]->ShowWindow(SW_SHOW);
	pDialog[1]->ShowWindow(SW_HIDE);

	m_CurSelTab = 0;
	m_Tab.SetCurSel(0);

	//���Ե��õ��Ӵ��ڵ�û�з���Ϣ���Ե���¼�û�з���
	pDialog[0]->GetDlgItem(IDC_BUTTON_STAR);
	
	//SendMessage(WM_COMMAND, MAKEWPARAM(IDC_BUTTON_STAR, BN_CLICKED));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C����ʱDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C����ʱDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C����ʱDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C����ʱDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);
	m_CurSelTab = m_Tab.GetCurSel();
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);
	*pResult = 0;
}
	

LRESULT C����ʱDlg::OnMyMsgHandler(WPARAM, LPARAM)
{
	MessageBox(L"���ڵ��Զ����Զ�����Ϣ");

	::SendMessage(pDialog[0]->m_hWnd, MAKEWPARAM(IDC_BUTTON_STAR, BN_CLICKED),0,0); //::AfxGetMainWnd()->m_hWnd

	return 0;
}

void C����ʱDlg::OnClose()
{
	//MessageBox(L"������������", L"��ʾ", MB_OK);
	CString strText;
	pDialog[1]->GetDlgItem(IDC_EDIT_DATA)->GetWindowTextW(strText);
	m_FileWrite.C_WriteData(L"text.txt",strText);
	CDialog::OnClose();
}