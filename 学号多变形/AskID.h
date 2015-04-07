#if !defined(AFX_ASKID_H__40587715_EEFF_4AA2_87DC_F9166F55A14F__INCLUDED_)
#define AFX_ASKID_H__40587715_EEFF_4AA2_87DC_F9166F55A14F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AskID.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AskID dialog

class AskID : public CDialog
{
// Construction
public:
	AskID(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AskID)
	enum { IDD = IDD_DIALOG1 };
	int		m_id;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AskID)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AskID)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASKID_H__40587715_EEFF_4AA2_87DC_F9166F55A14F__INCLUDED_)
