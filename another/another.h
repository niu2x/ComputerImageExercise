// another.h : main header file for the ANOTHER application
//

#if !defined(AFX_ANOTHER_H__84C095BA_1C17_436F_BDA6_78E28D0F5C9A__INCLUDED_)
#define AFX_ANOTHER_H__84C095BA_1C17_436F_BDA6_78E28D0F5C9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAnotherApp:
// See another.cpp for the implementation of this class
//

class CAnotherApp : public CWinApp
{
public:
	CAnotherApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnotherApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAnotherApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANOTHER_H__84C095BA_1C17_436F_BDA6_78E28D0F5C9A__INCLUDED_)
