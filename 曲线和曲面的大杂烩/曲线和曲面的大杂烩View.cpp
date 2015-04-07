// 曲线和曲面的大杂烩View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "曲线和曲面的大杂烩.h"

#include "曲线和曲面的大杂烩Doc.h"
#include "曲线和曲面的大杂烩View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "HermiteShape1.h"
#include "BezierShape.h"
#include "BezierPlaneShape.h"
#include "BShape.h"
/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	ON_COMMAND(ID_B, OnB)
	ON_COMMAND(ID_BEZIER, OnBezier)
	ON_COMMAND(ID_BEZIER_PLANE, OnBezierPlane)
	ON_COMMAND(ID_HERMITE, OnHermite)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
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
	currentDrawing = 0;
}

void CMyView::clear ()
{
	while(!shapePtrGrp.empty())
	{
		ShapePtrGrp::iterator it = shapePtrGrp.begin();
		delete *it;
		shapePtrGrp.erase(it);
	}
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

	if(currentDrawing != 0)
	{
		if(currentDrawing -> IsDone())
		{
			shapePtrGrp.push_back(currentDrawing);

			currentDrawing = 0;
		}
		else
		{
			currentDrawing -> Draw(&DCMem);
		}
	}

	for(ShapePtrGrp::iterator it = shapePtrGrp.begin(); it != shapePtrGrp.end(); it ++)
	{
		(*it) -> Draw(&DCMem);
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

void CMyView::OnB() 
{
	// TODO: Add your command handler code here
	if(currentDrawing == 0)
	{
		currentDrawing = new BShape();
		currentDrawing -> Init();
		OnDraw(0);
	}
}

void CMyView::OnBezier() 
{
	// TODO: Add your command handler code here
	if(currentDrawing == 0)
	{
		currentDrawing = new BezierShape();
		currentDrawing -> Init();
		OnDraw(0);
	}
}

void CMyView::OnBezierPlane() 
{
	// TODO: Add your command handler code here
	if(currentDrawing == 0)
	{
		currentDrawing = new BezierPlaneShape();
		currentDrawing -> Init();
		OnDraw(0);
	}
}

void CMyView::OnHermite() 
{
	// TODO: Add your command handler code here
	if(currentDrawing == 0)
	{
		currentDrawing = new HermiteShape();
		currentDrawing -> Init();
		OnDraw(0);
	}
}

void CMyView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
	if(currentDrawing != 0)
	{
		currentDrawing -> LButtonDown(point);
		OnDraw(0);
	}
}

void CMyView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnMouseMove(nFlags, point);
}

void CMyView::OnClear() 
{
	// TODO: Add your command handler code here
	clear();
	OnDraw(0);
}
