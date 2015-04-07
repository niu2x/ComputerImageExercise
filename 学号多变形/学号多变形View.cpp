// 学号多变形View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "学号多变形.h"

#include "学号多变形Doc.h"
#include "学号多变形View.h"
#include "AskID.h"
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
	ON_COMMAND(ID_SET_ID, OnSetId)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(CLEAR, OnCLEAR)
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
	id = 0;
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
	DrawPolygon(&DCMem);
	RECT rect;
	GetClientRect(&rect); 
	MyPolygon::Fill (&DCMem, id, rect.right -rect.left, rect.bottom - rect.top );

	if(theDrawing.points .size() > 0)
	{
		int len = theDrawing.points .size();
		for(int i = 0; i < len - 1; i ++)
		{
			theDrawing.Line (&DCMem, theDrawing.points[i], theDrawing.points[i + 1]); 
		}
		theDrawing.Line (&DCMem, theDrawing.points[i], mousePos);
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

void CMyView::OnSetId() 
{
	// TODO: Add your command handler code here
	AskID askID;
	if( askID.DoModal() == 1)
	{
		id = askID.m_id ;
		OnDraw(0);
	}
}

void CMyView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonUp(nFlags, point);
}

void CMyView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
	theDrawing.AddPoint (point);
	OnDraw(0);
}

void CMyView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnMouseMove(nFlags, point);
	mousePos = point;
	if(theDrawing.points.size()>0)
	{
		OnDraw(0);
	}
}

void CMyView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDblClk(nFlags, point);
	polygonGrp.push_back(theDrawing);
	theDrawing.Clear();
	OnDraw(0);
}

void CMyView::DrawPolygon (CDC *pDC)
{
	std::vector<MyPolygon>::iterator it = polygonGrp.begin();
	while(it != polygonGrp.end())
	{
		(*it).Draw(pDC);
		it ++;
	}
}

void CMyView::OnCLEAR() 
{
	// TODO: Add your command handler code here
	polygonGrp.clear();
	theDrawing.ClearMask();
	OnDraw(0);
}
