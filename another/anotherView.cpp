// anotherView.cpp : implementation of the CAnotherView class
//

#include "stdafx.h"
#include "another.h"

#include "anotherDoc.h"
#include "anotherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnotherView

IMPLEMENT_DYNCREATE(CAnotherView, CView)

BEGIN_MESSAGE_MAP(CAnotherView, CView)
	//{{AFX_MSG_MAP(CAnotherView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnotherView construction/destruction

CAnotherView::CAnotherView()
{
	// TODO: add construction code here

}

CAnotherView::~CAnotherView()
{
}

BOOL CAnotherView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAnotherView drawing

void CAnotherView::OnDraw(CDC* pDC)
{
	CAnotherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CAnotherView printing

BOOL CAnotherView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAnotherView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAnotherView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAnotherView diagnostics

#ifdef _DEBUG
void CAnotherView::AssertValid() const
{
	CView::AssertValid();
}

void CAnotherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAnotherDoc* CAnotherView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAnotherDoc)));
	return (CAnotherDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAnotherView message handlers
