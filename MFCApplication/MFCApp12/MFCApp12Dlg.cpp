
// MFCApp12Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApp12.h"
#include "MFCApp12Dlg.h"
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


// CMFCApp12Dlg �Ի���



CMFCApp12Dlg::CMFCApp12Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPP12_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApp12Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApp12Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHUTDOWN, &CMFCApp12Dlg::OnBnClickedShutdown)
	ON_BN_CLICKED(IDC_CANCELSHUTDOWN, &CMFCApp12Dlg::OnBnClickedCancelshutdown)
END_MESSAGE_MAP()


// CMFCApp12Dlg ��Ϣ�������

BOOL CMFCApp12Dlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApp12Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApp12Dlg::OnPaint()
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
HCURSOR CMFCApp12Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApp12Dlg::OnBnClickedShutdown()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int iResult = ::MessageBox(NULL, _T("ȷ��Ҫ�ػ���"), _T("�ػ�"), MB_OKCANCEL | MB_ICONQUESTION);
	
	if (1 == iResult)
	{
		CString command;

		//GetDlgItem(IDC_COUNTDOWNTIME)->GetWindowTextW(command);
		//command = _T("shutdown -s -t ") + command;
		//const size_t commandSize = (command.GetLength() + 1) * 2;	// ���ַ��ĳ���
		//char *lpszCommand = new char[commandSize];	// ����ռ�
		//lpszCommand = (LPSTR)command.GetBuffer(commandSize);
		//command.ReleaseBuffer();

		((CEdit *)GetDlgItem(IDC_COUNTDOWNTIME))->GetWindowText(command);	// �ӿؼ���ȡstring������ת��
		CString shut = _T("shutdown -s -t ");
		command = shut + command;
		const size_t commandSize = (command.GetLength() + 1) * 2;	// ���ַ��ĳ���
		char *lpszCommand = new char[commandSize];	// ����ռ�
		size_t sz = 0;
		wcstombs_s(&sz, lpszCommand, commandSize, command, _TRUNCATE);
		int n = atoi((const char*)lpszCommand);

		system(lpszCommand);
		getchar();
	}
}


void CMFCApp12Dlg::OnBnClickedCancelshutdown()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	system("shutdown -a");
}
