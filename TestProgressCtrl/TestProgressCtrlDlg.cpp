
// TestProgressCtrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestProgressCtrl.h"
#include "TestProgressCtrlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestProgressCtrlDlg dialog
CTestProgressCtrlDlg::CTestProgressCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestProgressCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestProgressCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS_NORMAL, m_ProgressNormal);
	DDX_Control(pDX, IDC_PROGRESS_PAUSED, m_ProgressPaused);
	DDX_Control(pDX, IDC_PROGRESS_ERROR, m_ProgressError);
	DDX_Control(pDX, IDC_PROGRESS_PARTIAL, m_ProgressPartial);
}

BEGIN_MESSAGE_MAP(CTestProgressCtrlDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_START, &CTestProgressCtrlDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CTestProgressCtrlDlg::OnBnClickedButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CTestProgressCtrlDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDCANCEL, &CTestProgressCtrlDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CTestProgressCtrlDlg message handlers

BOOL CTestProgressCtrlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_ProgressNormal.SetState(PBST_NORMAL);
	m_ProgressPaused.SetState(PBST_PAUSED);
	m_ProgressError.SetState(PBST_ERROR);
	m_ProgressPartial.SetState(PBFS_PARTIAL);

	m_ProgressNormal.SetRange(70, 100);
	m_ProgressPaused.SetRange(70, 100);
	m_ProgressError.SetRange(70, 100);
	m_ProgressPartial.SetRange(70, 100);

	m_ProgressNormal.SetStep(1);
	m_ProgressPaused.SetStep(1);
	m_ProgressError.SetStep(1);
	m_ProgressPartial.SetStep(1);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestProgressCtrlDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestProgressCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTestProgressCtrlDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
		case 1:
			m_ProgressNormal.StepIt();
			break;
		case 2:
			m_ProgressPaused.StepIt();
			break;
		case 3:
			m_ProgressError.StepIt();
			break;
		case 4:
			m_ProgressPartial.StepIt();
			break;
		default:
			break;
	}

	CDialog::OnTimer(nIDEvent);
}

void CTestProgressCtrlDlg::OnBnClickedButtonStart()
{
	// TODO: Add your control notification handler code here
	SetTimer(1, 100, NULL);
	SetTimer(2, 100, NULL);
	SetTimer(3, 100, NULL);
	SetTimer(4, 100, NULL);
}

void CTestProgressCtrlDlg::OnBnClickedButtonStop()
{
	// TODO: Add your control notification handler code here
	KillTimer(1);
	KillTimer(2);
	KillTimer(3);
	KillTimer(4);
}

void CTestProgressCtrlDlg::OnBnClickedButtonClear()
{
	// TODO: Add your control notification handler code here
	m_ProgressNormal.SetPos(0);

	// If the progress state is NOT "PBST_NORMAL", SetPos function will NOT work in the first time
	m_ProgressPaused.SetPos(0);
	m_ProgressPaused.SetPos(0);

	// If the progress state is NOT "PBST_NORMAL", SetPos function will NOT work in the first time
	m_ProgressError.SetPos(0);
	m_ProgressError.SetPos(0);

	m_ProgressPartial.SetPos(0);
}

void CTestProgressCtrlDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	KillTimer(1);
	KillTimer(2);
	KillTimer(3);
	KillTimer(4);

	OnCancel();
}
