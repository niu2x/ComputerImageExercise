// qwe.cpp : implementation file
//

#include "stdafx.h"
#include "RoundEllipse.h"
#include "qwe.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// qwe dialog


qwe::qwe(CWnd* pParent /*=NULL*/)
	: CDialog(qwe::IDD, pParent)
{
	//{{AFX_DATA_INIT(qwe)
	m_width = 0;
	//}}AFX_DATA_INIT
}


void qwe::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(qwe)
	DDX_Text(pDX, IDC_EDIT1, m_width);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(qwe, CDialog)
	//{{AFX_MSG_MAP(qwe)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// qwe message handlers
