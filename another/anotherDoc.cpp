// anotherDoc.cpp : implementation of the CAnotherDoc class
//

#include "stdafx.h"
#include "another.h"

#include "anotherDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnotherDoc

IMPLEMENT_DYNCREATE(CAnotherDoc, CDocument)

BEGIN_MESSAGE_MAP(CAnotherDoc, CDocument)
	//{{AFX_MSG_MAP(CAnotherDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnotherDoc construction/destruction

CAnotherDoc::CAnotherDoc()
{
	// TODO: add one-time construction code here

}

CAnotherDoc::~CAnotherDoc()
{
}

BOOL CAnotherDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAnotherDoc serialization

void CAnotherDoc::Serialize(CArchive& ar)
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
// CAnotherDoc diagnostics

#ifdef _DEBUG
void CAnotherDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAnotherDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAnotherDoc commands
