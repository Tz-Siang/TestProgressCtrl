// C_ProgressCtrlExtend.cpp : implementation file
//

#include "stdafx.h"
#include "TestProgressCtrl.h"
#include "C_ProgressCtrlExtend.h"

#include <Uxtheme.h>

#pragma comment(lib, "UxTheme.lib")

// C_ProgressCtrlExtend

IMPLEMENT_DYNAMIC(C_ProgressCtrlExtend, CProgressCtrl)

C_ProgressCtrlExtend::C_ProgressCtrlExtend()
	: m_nState(PBST_NORMAL)
{
}

C_ProgressCtrlExtend::~C_ProgressCtrlExtend()
{
}

BEGIN_MESSAGE_MAP(C_ProgressCtrlExtend, CProgressCtrl)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// C_ProgressCtrlExtend message handlers
void C_ProgressCtrlExtend::OnPaint()
{
	RECT rc;
	GetClientRect(&rc);

	CPaintDC dc(this);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);

	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc, rc.right, rc.bottom);
	CBitmap* oldBmp = dcMem.SelectObject(&bmp);

	DrawThemedBar(dcMem, m_nState);

	dc.BitBlt(0, 0, rc.right, rc.bottom, &dcMem, 0, 0, SRCCOPY);

	dcMem.SelectObject(oldBmp);
	dcMem.DeleteDC();
}

int C_ProgressCtrlExtend::SetState(_In_ int iState)
{
	m_nState = iState;// Keep the progress state
	switch(m_nState)
	{
		case PBFS_PARTIAL:
			// CProgressCtrl::SetState is no accept PBFS_PARTIAL
			// The state will be set to PBST_NORMAL
			// So we should keep the state
			break;
		case PBST_NORMAL:
		case PBST_PAUSED:
		case PBST_ERROR:
		default:
			return CProgressCtrl::SetState(m_nState);
	}

	return 1;
}

void C_ProgressCtrlExtend::DrawThemedBar(CDC& dc, int nState)
{
	CRect rect;
	GetClientRect(&rect);

	// Draw empty progress bar
	HTHEME hTheme = OpenThemeData(this->GetSafeHwnd(), L"PROGRESS");
	DrawThemeBackground(hTheme, dc, PP_BAR, 0, &rect, NULL);

	// Calculate the width of chunk part
	int nLower = 0;
	int nUpper = 0;
	GetRange(nLower, nUpper);	
	double lfChunkPart = (double)(rect.right - rect.left) / (nUpper - nLower);

	// Calculate right position of current chunk
	int nPos = GetPos() - nLower;
	rect.right = rect.left + lfChunkPart * nPos;

	// Draw the chunk(The chunk color will change by nState)
	DrawThemeBackground(hTheme, dc, PP_FILL, nState, &rect, NULL);

	if(hTheme)
		CloseThemeData(hTheme);
}