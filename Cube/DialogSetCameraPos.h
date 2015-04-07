#if !defined(AFX_DIALOGSETCAMERAPOS_H__C8007B7A_0AB1_40A3_AFBF_B19D70D12CEF__INCLUDED_)
#define AFX_DIALOGSETCAMERAPOS_H__C8007B7A_0AB1_40A3_AFBF_B19D70D12CEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogSetCameraPos.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DialogSetCameraPos dialog

class DialogSetCameraPos : public CDialog
{
// Construction
public:
	DialogSetCameraPos(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DialogSetCameraPos)
	enum { IDD = IDD_DIALOG1 };
	float	m_cameraX;
	float	m_cameraY;
	float	m_cameraZ;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DialogSetCameraPos)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DialogSetCameraPos)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGSETCAMERAPOS_H__C8007B7A_0AB1_40A3_AFBF_B19D70D12CEF__INCLUDED_)
