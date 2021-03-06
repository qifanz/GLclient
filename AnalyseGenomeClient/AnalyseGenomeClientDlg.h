
// AnalyseGenomeClientDlg.h : header file
//

#pragma once
#include "ClientSocket.h"
#include "InterfaceClient.h"

// CAnalyseGenomeClientDlg dialog
class CAnalyseGenomeClientDlg : public CDialogEx
{
// Construction
public:
	CAnalyseGenomeClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANALYSEGENOMECLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString MsgToSend;
	afx_msg void OnBnClickedsend();
private:
	InterfaceClient interfacehm;
	Genome * g;
public:
	CString msg2;
	afx_msg void OnBnClickedlistermaladie();
	

	CString nomMaladieSaisie;
	afx_msg void OnBnClickedButton3();
	CString etatGenome;
	virtual void OnOK();
};
