
// MFCApp11Dlg.h : ͷ�ļ�
//

#pragma once


// CMFCApp11Dlg �Ի���
class CMFCApp11Dlg : public CDialogEx
{
// ����
public:
	CMFCApp11Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPP11_DIALOG };
#endif

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
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCalc();
	afx_msg void OnBnClickedNotepad();
	afx_msg void OnBnClickedNslookup();
};
