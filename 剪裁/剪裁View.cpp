// ¼ô²ÃView.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "¼ô²Ã.h"

#include "¼ô²ÃDoc.h"
#include "¼ô²ÃView.h"

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
	ON_COMMAND(ID_REGION, OnRegion)
	ON_COMMAND(ID_CAI, OnCai)
	ON_COMMAND(ID_CLEAR, OnClear)
	ON_COMMAND(ID_POLYGON, OnPolygon)
	ON_WM_MOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
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
	polygonDrawed = false;
	regionDrawed = false;
	select = T_INVALID;
	regionDrawing = false;
	polygonDrawing = false;
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

void DrawPolygon(CDC &DCMem, std::vector<CPoint> &polygon, int width, unsigned int col)
{
	CPen pen;
	pen.CreatePen(1, width, col);

	CPen *oldPen = DCMem.SelectObject(&pen);
	
	DCMem.MoveTo(*polygon.begin());
	for(std::vector<CPoint>::iterator it = polygon.begin(); it != polygon.end(); it ++)
	{
		DCMem.LineTo(*it);
	}
	DCMem.LineTo(*polygon.begin());

	DCMem.SelectObject(oldPen);
}

void FillPolygon(CDC &DCMem, std::vector<CPoint> &polygon, unsigned int col)
{
	POINT *points= new POINT [polygon.size()];

	for(int i = 0; i < polygon.size(); i ++)
	{
		points[i].x = polygon[i].x;
		points[i].y = polygon[i].y;
	}

	CRgn rgn;
	CBrush hbr;
	hbr.CreateSolidBrush(col);
	rgn.CreatePolygonRgn(points, polygon.size(), 2);

	DCMem.FillRgn(&rgn, &hbr);

	delete []points;
}

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
	

	if(regionDrawed || regionDrawing)
	{
		DCMem.Rectangle(&region);
	}

	if(polygonDrawing)
	{
		DCMem.MoveTo(*polygon.begin());
		for(std::vector<CPoint>::iterator it = polygon.begin(); it != polygon.end(); it ++)
		{
			DCMem.LineTo(*it);
		}
		DCMem.LineTo(lastMousePos);
	}
	else if(polygonDrawed)
	{
		DrawPolygon(DCMem, polygon, 1, 0x0);
	}

	if(regionDrawed && polygonDrawed)
	{
		JianCaiAndFill(DCMem);
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

void CMyView::OnRegion() 
{
	// TODO: Add your command handler code here
	if(regionDrawed == false)
	{
		select = T_REGION;
	}
	else
	{
		this->MessageBox("Region»­¹ýÁË", "Alert", MB_OK);
	}
}

void CMyView::OnCai() 
{
	// TODO: Add your command handler code here
	
}

void CMyView::OnClear() 
{
	// TODO: Add your command handler code here
	regionDrawed = false;
	polygonDrawed = false;
	polygon.clear();
	OnDraw(0);
}

void CMyView::OnPolygon() 
{
	// TODO: Add your command handler code here
	if(polygonDrawed == false)
	{
		select = T_POLYGON;
	}
	else
	{
		this->MessageBox("Polygon»­¹ýÁË", "Alert", MB_OK);
	}
	
}

void CMyView::OnMove(int x, int y) 
{
	CView::OnMove(x, y);
	
	// TODO: Add your message handler code here
	
}

void CMyView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);

	switch(select)
	{
	case T_REGION:
		region.left = point.x;
		region.top = point.y;
		region.right = point.x;
		region.bottom = point.y;
		regionDrawing = true;
		OnDraw(0);
		break;
	case T_POLYGON:
		polygon.push_back(point);
		polygonDrawing = true;
		lastMousePos = point;
		OnDraw(0);
		break;
	}
}

void CMyView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonUp(nFlags, point);
	switch(select)
	{
	case T_REGION:
		if(regionDrawing)
		{
			region.right = point.x;
			region.bottom = point.y;
			regionDrawing = false;
			regionDrawed = true;
			OnDraw(0);
			select = T_INVALID;
		}
		break;
	case T_POLYGON:
		break;
	}
}

void CMyView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnMouseMove(nFlags, point);
	switch(select)
	{
	case T_REGION:
		if(regionDrawing)
		{
			region.right = point.x;
			region.bottom = point.y;
			OnDraw(0);
		}
		break;
	case T_POLYGON:
		if(polygonDrawing)
		{
			lastMousePos = point;
			OnDraw(0);
		}
		break;
	}
}

void CMyView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDblClk(nFlags, point);
	switch(select)
	{
	case T_REGION:
		break;
	case T_POLYGON:
		if(polygonDrawing)
		{
			lastMousePos = point;
			polygon.push_back(point);
			polygonDrawing = false;
			polygonDrawed = true;
			OnDraw(0);
			select = T_INVALID;
		}
		break;
	}
}

int isInside(CPoint a, CPoint b, CPoint point)
{
	float i1 = a.x - b.x;
	float j1 = a.y - b.y;

	float i2 = point.x - b.x;
	float j2 = point.y - b.y;

	return i1 * j2 - i2 * j1;
}

CPoint QJD(CPoint a, CPoint b, CPoint c, CPoint d)
{
	float k = (-d.y*((float)a.x-b.x)+b.y*((float)a.x-b.x)-b.x*((float)a.y-b.y)+d.x*((float)a.y-b.y))/(((float)a.x-b.x)*((float)c.y-d.y)-((float)a.y-b.y)*((float)c.x-d.x));
	return CPoint(k*(c.x-d.x)+d.x, (c.y-d.y)*k+d.y);
}

void CMyView::JianCaiAndFill (CDC &DCMem)
{
	CPoint lt = CPoint(region.left, region.top);
	CPoint rt = CPoint(region.right, region.top);
	CPoint lb = CPoint(region.left, region.bottom);
	CPoint rb = CPoint(region.right, region.bottom);

	std::vector<CPoint> inside = polygon;
	std::vector<CPoint> outside;

	std::vector<CPoint> process = inside;
	inside.clear();

	FillPolygon(DCMem, process,  0xff);


	for(int i = 0; i < process.size(); i ++)
	{
		CPoint a = process[i];
		CPoint b = process[(i+1)%process.size()];

		bool a_is_inside = isInside(lt, rt, a) < 0;
		bool b_is_inside = isInside(lt, rt, b) < 0;

		if(a_is_inside && b_is_inside)
		{
			inside.push_back(b);
		}
		else if(!a_is_inside && !b_is_inside)
		{
			outside.push_back(b);
		}
		else if(a_is_inside && !b_is_inside)
		{
			inside.push_back(QJD(lt, rt, a, b));

			outside.push_back(QJD(lt, rt, a, b));
			outside.push_back(b);
		}
		else if(!a_is_inside && b_is_inside)
		{
			inside.push_back(QJD(lt, rt, a, b));
			inside.push_back(b);

			outside.push_back(QJD(lt, rt, a, b));
		}
	}

	process = inside;
	inside.clear();

//	FillPolygon(DCMem, outside,  0xff);
//	outside.clear();

	for( i = 0; i < process.size(); i ++)
	{
		CPoint a = process[i];
		CPoint b = process[(i+1)%process.size()];

		bool a_is_inside = isInside(lb, lt, a) < 0;
		bool b_is_inside = isInside(lb, lt, b) < 0;

		if(a_is_inside && b_is_inside)
		{
			inside.push_back(b);
		}
		else if(!a_is_inside && !b_is_inside)
		{
			outside.push_back(b);
		}
		else if(a_is_inside && !b_is_inside)
		{
			inside.push_back(QJD(lb, lt, a, b));

			outside.push_back(QJD(lt, rt, a, b));
			outside.push_back(b);
		}
		else if(!a_is_inside && b_is_inside)
		{
			inside.push_back(QJD(lb, lt, a, b));
			inside.push_back(b);

				outside.push_back(QJD(lt, rt, a, b));
		}
	}
	
	process = inside;
	inside.clear();

//	FillPolygon(DCMem, outside,  0xff);
//	outside.clear();
	for( i = 0; i < process.size(); i ++)
	{
		CPoint a = process[i];
		CPoint b = process[(i+1)%process.size()];

		bool a_is_inside = isInside(rb, lb, a) < 0;
		bool b_is_inside = isInside(rb, lb, b) < 0;

		if(a_is_inside && b_is_inside)
		{
			inside.push_back(b);
		}
		else if(!a_is_inside && !b_is_inside)
		{
			outside.push_back(b);
		}
		else if(a_is_inside && !b_is_inside)
		{
			inside.push_back(QJD(rb, lb, a, b));

			outside.push_back(QJD(lt, rt, a, b));
			outside.push_back(b);
		}
		else if(!a_is_inside && b_is_inside)
		{
			inside.push_back(QJD(rb, lb, a, b));
			inside.push_back(b);

				outside.push_back(QJD(lt, rt, a, b));
		}
	}

	process = inside;
	inside.clear();
//	FillPolygon(DCMem, outside,  0xff);
//	outside.clear();

	for( i = 0; i < process.size(); i ++)
	{
		CPoint a = process[i];
		CPoint b = process[(i+1)%process.size()];

		bool a_is_inside = isInside(rt, rb, a) < 0;
		bool b_is_inside = isInside(rt, rb, b) < 0;

		if(a_is_inside && b_is_inside)
		{
			inside.push_back(b);
		}
		else if(!a_is_inside && !b_is_inside)
		{
			outside.push_back(b);
		}
		else if(a_is_inside && !b_is_inside)
		{
			inside.push_back(QJD(rt, rb, a, b));

			outside.push_back(QJD(lt, rt, a, b));
			outside.push_back(b);
		}
		else if(!a_is_inside && b_is_inside)
		{
			inside.push_back(QJD(rt, rb, a, b));
			inside.push_back(b);

			outside.push_back(QJD(lt, rt, a, b));
		}
	}


//	FillPolygon(DCMem, outside,  0xff);
//	outside.clear();

	DrawPolygon(DCMem, inside, 2, 0xff);
	FillPolygon(DCMem, inside, 0xffff);
}
