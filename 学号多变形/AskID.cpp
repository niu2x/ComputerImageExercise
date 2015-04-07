// AskID.cpp : implementation file
//

#include "stdafx.h"
#include "学号多变形.h"
#include "AskID.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AskID dialog


AskID::AskID(CWnd* pParent /*=NULL*/)
	: CDialog(AskID::IDD, pParent)
{
	//{{AFX_DATA_INIT(AskID)
	m_id = 0;
	//}}AFX_DATA_INIT
}


void AskID::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AskID)
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDV_MinMaxInt(pDX, m_id, 0, 9999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AskID, CDialog)
	//{{AFX_MSG_MAP(AskID)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AskID message handlers
