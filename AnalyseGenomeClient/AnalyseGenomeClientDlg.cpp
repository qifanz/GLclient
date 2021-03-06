
// AnalyseGenomeClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AnalyseGenomeClient.h"
#include "AnalyseGenomeClientDlg.h"
#include "afxdialogex.h"
#include "ClientSocket.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CAnalyseGenomeClientDlg dialog



CAnalyseGenomeClientDlg::CAnalyseGenomeClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ANALYSEGENOMECLIENT_DIALOG, pParent)


	, nomMaladieSaisie(_T(""))
	, etatGenome(_T("genome non charge"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnalyseGenomeClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT2, nomMaladieSaisie);
	DDX_Text(pDX, IDC_EDIT5, etatGenome);
}

BEGIN_MESSAGE_MAP(CAnalyseGenomeClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAnalyseGenomeClientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(Msg_send, &CAnalyseGenomeClientDlg::OnBnClickedsend)
	ON_BN_CLICKED(listerMaladie, &CAnalyseGenomeClientDlg::OnBnClickedlistermaladie)



	ON_BN_CLICKED(IDC_BUTTON3, &CAnalyseGenomeClientDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CAnalyseGenomeClientDlg message handlers

BOOL CAnalyseGenomeClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	interfacehm.initialise();
	interfacehm.demanderListerMaladies();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAnalyseGenomeClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAnalyseGenomeClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAnalyseGenomeClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAnalyseGenomeClientDlg::OnBnClickedButton1()
{
	//	interfacehm.startConnection();

	UpdateData(true);
	//CString nomFichier = nomFichierGenome;
	CString nomFichier;
	GetDlgItemText(IDC_MFCEDITBROWSE1, nomFichier);
	UpdateData(false);
	g = new Genome(nomFichier);
	if (g != nullptr)
	{
		UpdateData(true);
		etatGenome = (CString)"genome charge";
		UpdateData(false);
	}
}


void CAnalyseGenomeClientDlg::OnBnClickedsend()
{
	/**Analyse a(*g,"Genrale");
	if (a.getVersion() != "MA v1.0")
	{
		AfxMessageBox(_T("the genome version is not correct."));
	}
	else
	{
		interfacehm.demanderAnalyseGenerale(a);
	}**/
	if (g == nullptr)
	{
		AfxMessageBox(_T("Veuillez charger un fichier genome avant de lancer une analyse."));
	}
	else
	{
		Analyse a(*g, "Generale");
		if (a.getVersion() != "MA v1.0")
		{
			AfxMessageBox(_T("the genome version is not correct."));
		}
		else
		{
			interfacehm.demanderAnalyseGenerale(a);
		}
	}
}


void CAnalyseGenomeClientDlg::OnBnClickedlistermaladie()
{

	interfacehm.demanderListerMaladies();
	interfacehm.afficherResultatListeMaladies();
}








void CAnalyseGenomeClientDlg::OnBnClickedButton3()
{
	UpdateData(true);

	CT2CA pszName(nomMaladieSaisie);
	string nomMaladie(pszName);
	UpdateData(false);
	if (g == nullptr)
	{
		AfxMessageBox(_T("Veuillez charger un fichier genome avant de lancer une analyse."));
	}
	else if (nomMaladie == "")
	{
		AfxMessageBox(_T("Veuillez saisir un nom de la maladie."));
	}
	else
	{
		Analyse a(*g, nomMaladie);
		interfacehm.demanderAnalyseCiblee(a, nomMaladie);
	}
	// TODO: 在此添加控件通知处理程序代码
}



void CAnalyseGenomeClientDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	delete g;
	CDialogEx::OnOK();
}
