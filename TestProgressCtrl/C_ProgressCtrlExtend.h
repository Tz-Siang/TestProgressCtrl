#pragma once

// C_ProgressCtrlExtend

class C_ProgressCtrlExtend : public CProgressCtrl
{
	DECLARE_DYNAMIC(C_ProgressCtrlExtend)

public:
	C_ProgressCtrlExtend();
	virtual ~C_ProgressCtrlExtend();

	int SetState(_In_ int iState);

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

	int m_nState;
private:
	void DrawThemedBar(CDC& dc, int nState);
};