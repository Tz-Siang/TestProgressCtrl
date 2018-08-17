
// TestProgressCtrlDlg.h : header file
//

#pragma once
#include "afxcmn.h"

#include "C_ProgressCtrlExtend.h"

// CTestProgressCtrlDlg dialog
class CTestProgressCtrlDlg : public CDialog
{
// Construction
public:
	CTestProgressCtrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TESTPROGRESSCTRL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedCancel();
	DECLARE_MESSAGE_MAP()

public:
	CProgressCtrl m_ProgressNormal;
	CProgressCtrl m_ProgressPaused;
	CProgressCtrl m_ProgressError;
	C_ProgressCtrlExtend m_ProgressPartial;
};
