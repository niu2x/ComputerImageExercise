// 底气会View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "底气会.h"

#include "底气会Doc.h"
#include "底气会View.h"

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
	ON_COMMAND(ID_BUTTON32771, OnButton32771)
	ON_COMMAND(ID_BUTTON32772, OnButton32772)
	ON_COMMAND(ID_BUTTON32773, OnButton32773)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_BUTTON32774, OnButton32774)
	ON_WM_KEYDOWN()
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
	shape = new BShape();
	shape ->Init();
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

void CMyView::OnButton32771() 
{
	// TODO: Add your command handler code here
	shape->SetMode(0);
	OnDraw(0);
}

void CMyView::OnButton32772() 
{
	// TODO: Add your command handler code here
	shape->SetMode(1);
	OnDraw(0);
}

void CMyView::OnButton32773() 
{
	// TODO: Add your command handler code here
	shape->SetMode(2);
	OnDraw(0);
}

void CMyView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDblClk(nFlags, point);
	if(!(shape->IsDone()))
	{
		shape->LButtonDoubleDown(point);
		OnDraw(0);
	}
}

void CMyView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
	if(!(shape->IsDone()))
	{
		shape->LButtonDown(point);
		OnDraw(0);
	}
}

void CMyView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnMouseMove(nFlags, point);
	if(!(shape->IsDone()))
	{
		shape->MouseMove(point);
		OnDraw(0);
	}
}

void CMyView::OnButton32774() 
{
	// TODO: Add your command handler code here
	shape->Init();
	OnDraw(0);
}

void CMyView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
