// RoundEllipseView.cpp : implementation of the CRoundEllipseView class
//
#include "stdafx.h"
#include "RoundEllipse.h"

#include "RoundEllipseDoc.h"
#include "RoundEllipseView.h"
#include "qwe.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRoundEllipseView

IMPLEMENT_DYNCREATE(CRoundEllipseView, CView)

BEGIN_MESSAGE_MAP(CRoundEllipseView, CView)
	//{{AFX_MSG_MAP(CRoundEllipseView)
	ON_COMMAND(ELLIPSE, OnELLIPSE)
	ON_COMMAND(ROUND, OnROUND)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_DHK, OnDhk)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoundEllipseView construction/destruction

CRoundEllipseView::CRoundEllipseView()
{
	// TODO: add construction code here

	type = 0;
	drawing = 0;

	roundNum = 0;
	ellipseNum = 0;
}

CRoundEllipseView::~CRoundEllipseView()
{
}

BOOL CRoundEllipseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRoundEllipseView drawing

void CRoundEllipseView::OnDraw(CDC* pDC)
{
	CRoundEllipseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	dc.CreateCompatibleDC (pDC);
	CBitmap bmp, *pbmp;
	bmp.CreateCompatibleBitmap (pDC, 1600, 1600);
	pbmp = (CBitmap*)dc.SelectObject (&bmp);
	dc.BitBlt (0, 0, 1600, 1600, 0, 0, 0, 0xffffff);
	drawSaved();
	if(drawing == 1)
	{
		drawDrawing();
	}
	pDC->BitBlt (0, 0, 1600, 1600, &dc, 0, 0, SRCCOPY);
	dc.SelectObject (pbmp);
	bmp.DeleteObject ();
	dc.DeleteDC ();
}

/////////////////////////////////////////////////////////////////////////////
// CRoundEllipseView printing

BOOL CRoundEllipseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRoundEllipseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRoundEllipseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRoundEllipseView diagnostics

#ifdef _DEBUG
void CRoundEllipseView::AssertValid() const
{
	CView::AssertValid();
}

void CRoundEllipseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRoundEllipseDoc* CRoundEllipseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRoundEllipseDoc)));
	return (CRoundEllipseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRoundEllipseView message handlers

void CRoundEllipseView::OnELLIPSE() 
{
	// TODO: Add your command handler code here
	type = T_ELLIPSE;
}

void CRoundEllipseView::OnROUND() 
{
	// TODO: Add your command handler code here
	type = T_ROUND;
}

void CRoundEllipseView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(drawing)
	{
		point2 = point;
		this->Invalidate ();
	}
}

void CRoundEllipseView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	drawing = 0;
	if(type == T_ROUND) saveRound();
	if(type == T_ELLIPSE) saveEllipse();
	this->Invalidate ();
}

void CRoundEllipseView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	point1 = point;
	point2 = point;
	drawing = 1;

	this->Invalidate ();
}

void CRoundEllipseView::drawSaved()
{
	for(int i = 0; i < roundNum; i ++)
	{
		int radius = sqrt((roundGrp[i*2].x - roundGrp[i*2 + 1].x)*(roundGrp[i*2].x - roundGrp[i*2 + 1].x)+(roundGrp[i*2].y - roundGrp[i*2 + 1].y)*(roundGrp[i*2].y - roundGrp[i*2 + 1].y));
		drawRound(roundGrp[i*2], radius);
	}
	for(i = 0; i < ellipseNum; i ++)
	{
		int a = abs(ellipseGrp[i*2].x - ellipseGrp[i*2+1].x)/2;
		int b = abs(ellipseGrp[i*2].y - ellipseGrp[i*2+1].y)/2;
		int ox = abs(ellipseGrp[i*2].x + ellipseGrp[i*2+1].x)/2;
		int oy = abs(ellipseGrp[i*2].y + ellipseGrp[i*2+1].y)/2;
		drawEllipse(a, b, ox, oy);
	}
}
void CRoundEllipseView::drawDrawing()
{
	if(type == T_ROUND)
	{
		int radius = sqrt((point2.x - point1.x)*(point2.x - point1.x)+(point2.y - point1.y)*(point2.y - point1.y));
		drawRound(point1, radius);
	}
	if(type == T_ELLIPSE)
	{
		int a = abs(point2.x - point1.x)/2;
		int b = abs(point2.y - point1.y)/2;
		int ox = abs(point2.x + point1.x)/2;
		int oy = abs(point2.y + point1.y)/2;
		drawEllipse(a, b, ox, oy);
	}
}
void CRoundEllipseView::saveRound()
{
	roundGrp[roundNum*2] = point1;
	roundGrp[roundNum*2 + 1] = point2;
	roundNum ++;
}
void CRoundEllipseView::saveEllipse()
{
	ellipseGrp[ellipseNum*2] = point1;
	ellipseGrp[ellipseNum*2 + 1] = point2;
	ellipseNum ++;
}

void CRoundEllipseView::drawRound (CPoint o, int radius)
{
	int d = radius + radius - 3;
	int x = 0;
	int y = radius;
	int x_div_sqrt_2 = radius / sqrt(2);

	while( x <= x_div_sqrt_2 + 1)
	{
		dc.SetPixel(CPoint(x + o.x, y + o.y), 0x0);
		dc.SetPixel(CPoint(y + o.x, x + o.y), 0x0);
		dc.SetPixel(CPoint(-x + o.x, y + o.y), 0x0);
		dc.SetPixel(CPoint(x + o.x, -y + o.y), 0x0);
		dc.SetPixel(CPoint(-y + o.x, x + o.y), 0x0);
		dc.SetPixel(CPoint(y + o.x, -x + o.y), 0x0);
		dc.SetPixel(CPoint(-x + o.x, -y + o.y), 0x0);
		dc.SetPixel(CPoint(-y + o.x, -x + o.y), 0x0);

		if( d >= 0)
		{
			d += -6 - x - x - x - x;
			x ++;
		}
		else
		{
			d += -10 - x - x - x - x + y + y + y + y;
			x ++;
			y --;
		}
	}
}

void CRoundEllipseView::drawEllipse (int a, int b, int ox, int oy)
{
	if(a == 0 || b == 0) return ;
	int d = - a*a + 2*b*a*a - 2*b*b;
	int x = 0;
	int y = b;

	while( x*b*b <= y*a*a)
	{
		dc.SetPixel(CPoint(x + ox, y + oy), 0x0);
		dc.SetPixel(CPoint(x + ox, -y + oy), 0x0);
		dc.SetPixel(CPoint(-x + ox, y + oy), 0x0);
		dc.SetPixel(CPoint(-x + ox, -y + oy), 0x0);

		if(d >= 0)
		{
			d += -2*b*b*(3 + 2*x);
			x ++;
		}
		else
		{
			d += -2*b*b*(3 + 2*x) + a*a*(4*y - 4);
			x ++;
			y --;
		}
	}

	d = - b*b + 2*a*b*b - 2*a*a;
	x = a;
	y = 0;

	while( y*a*a <= x*b*b)
	{
		dc.SetPixel(CPoint(x + ox, y + oy), 0x0);
		dc.SetPixel(CPoint(x + ox, -y + oy), 0x0);
		dc.SetPixel(CPoint(-x + ox, y + oy), 0x0);
		dc.SetPixel(CPoint(-x + ox, -y + oy), 0x0);

		if(d >= 0)
		{
			d += -2*a*a*(3 + 2*y);
			y ++;
		}
		else
		{
			d += -2*a*a*(3 + 2*y) + b*b*(4*x - 4);
			y ++;
			x --;
		}
	}
}

void CRoundEllipseView::OnDhk() 
{
	// TODO: Add your command handler code here
	qwe aboutDlg;
	aboutDlg.DoModal();	
	int n = aboutDlg.m_width ;
}
