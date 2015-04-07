// DialogSetCameraPos.cpp : implementation file
//

#include "stdafx.h"
#include "Cube.h"
#include "DialogSetCameraPos.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogSetCameraPos dialog


DialogSetCameraPos::DialogSetCameraPos(CWnd* pParent /*=NULL*/)
	: CDialog(DialogSetCameraPos::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogSetCameraPos)
	m_cameraX = 0.0f;
	m_cameraY = 0.0f;
	m_cameraZ = 0.0f;
	//}}AFX_DATA_INIT
}


void DialogSetCameraPos::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogSetCameraPos)
	DDX_Text(pDX, IDC_EDIT1, m_cameraX);
	DDX_Text(pDX, IDC_EDIT2, m_cameraY);
	DDX_Text(pDX, IDC_EDIT3, m_cameraZ);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogSetCameraPos, CDialog)
	//{{AFX_MSG_MAP(DialogSetCameraPos)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogSetCameraPos message handlers
