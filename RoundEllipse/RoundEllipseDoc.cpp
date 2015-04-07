// RoundEllipseDoc.cpp : implementation of the CRoundEllipseDoc class
//

#include "stdafx.h"
#include "RoundEllipse.h"

#include "RoundEllipseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRoundEllipseDoc

IMPLEMENT_DYNCREATE(CRoundEllipseDoc, CDocument)

BEGIN_MESSAGE_MAP(CRoundEllipseDoc, CDocument)
	//{{AFX_MSG_MAP(CRoundEllipseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoundEllipseDoc construction/destruction

CRoundEllipseDoc::CRoundEllipseDoc()
{
	// TODO: add one-time construction code here

}

CRoundEllipseDoc::~CRoundEllipseDoc()
{
}

BOOL CRoundEllipseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRoundEllipseDoc serialization

void CRoundEllipseDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRoundEllipseDoc diagnostics

#ifdef _DEBUG
void CRoundEllipseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRoundEllipseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRoundEllipseDoc commands
