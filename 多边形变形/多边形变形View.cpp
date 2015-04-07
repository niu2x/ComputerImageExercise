// 多边形变形View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "多边形变形.h"

#include "多边形变形Doc.h"
#include "多边形变形View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_START, OnStart)
	ON_COMMAND(ID_STOP, OnStop)
	ON_COMMAND(ID_CLEAR, OnClear)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyView construction/destruction

CMyView::CMyView()
{
	// TODO: add construction code here
	shape = new InnerRound();
	shape->Init();
}

CMyView::~CMyView()
{
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyView drawing

void CMyView::OnDraw(CDC*)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CDC *pDC, DCMem;
	CBitmap bmp, *oldBmp;
	pDC = GetDC();
	DCMem.CreateCompatibleDC(pDC);
	bmp.CreateCompatibleBitmap(pDC, 1600, 1600);
	oldBmp = DCMem.SelectObject(&bmp);
	DCMem.BitBlt(0,0,1600, 1600,0,0,0,0xffffff);

	if(shape)
	{
		shape -> Draw(&DCMem);
	}

	pDC->BitBlt(0,0,1600,1600,&DCMem,0,0,SRCCOPY);
	DCMem.SelectObject(oldBmp);
	bmp.DeleteObject();
	DCMem.DeleteDC();
	ReleaseDC(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CMyView printing

BOOL CMyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyView diagnostics

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyView message handlers

void CMyView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDblClk(nFlags, point);

	if(shape && !(shape->IsDone()))
	{
		shape -> LButtonDoubleDown(point);
	}

	OnDraw(0);
}

void CMyView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);

	if(shape && !(shape->IsDone()))
	{
		shape -> LButtonDown(point);
	}

	OnDraw(0);
}

void CMyView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnTimer(nIDEvent);

	CRect rect;

	GetClientRect(rect);
	((InnerRound*)(shape))->Move(rect); 

	OnDraw(0);
}



void CMyView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnMouseMove(nFlags, point);
	if(shape && !(shape->IsDone()))
	{
		shape -> MouseMove(point);
	}

	OnDraw(0);
}

void CMyView::OnStart() 
{
	// TODO: Add your command handler code here

	if(shape && (shape->IsDone()))
	{
		SetTimer(0, 50, 0);
	}
}

void CMyView::OnStop() 
{
	// TODO: Add your command handler code here
	KillTimer(0);
}

void CMyView::OnClear() 
{
	// TODO: Add your command handler code here
	delete shape;
	shape = new InnerRound();
	shape->Init();

	OnStop();

	OnDraw(0);
}
