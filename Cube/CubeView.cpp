// CubeView.cpp : implementation of the CCubeView class
//

#include "stdafx.h"
#include "Cube.h"

#include "CubeDoc.h"
#include "CubeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "DialogSetCameraPos.h"
/////////////////////////////////////////////////////////////////////////////
// CCubeView

IMPLEMENT_DYNCREATE(CCubeView, CView)

BEGIN_MESSAGE_MAP(CCubeView, CView)
	//{{AFX_MSG_MAP(CCubeView)
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(CMD_SET_CAMERA_POS, OnSetCameraPos)
	ON_COMMAND(CMD_SET_CAMERA_FRONT, OnSetCameraFront)
	ON_COMMAND(CMD_POINT, OnPoint)
	ON_COMMAND(CMD_PINGXING, OnPingxing)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCubeView construction/destruction

CCubeView::CCubeView()
{
	// TODO: add construction code here
	lastMousePos = CPoint(0,0);

}

CCubeView::~CCubeView()
{
}

BOOL CCubeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCubeView drawing

void CCubeView::OnDraw(CDC*)
{
	CCubeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CDC *pDC, DCMem;
	CBitmap bmp, *oldBmp;
	pDC = GetDC();
	DCMem.CreateCompatibleDC(pDC);
	bmp.CreateCompatibleBitmap(pDC, 1600, 1600);
	oldBmp = DCMem.SelectObject(&bmp);
	DCMem.BitBlt(0,0,1600, 1600,0,0,0,0xffffff);
	world.Draw (&DCMem);
	pDC->BitBlt(0,0,1600,1600,&DCMem,0,0,SRCCOPY);
	DCMem.SelectObject(oldBmp);
	bmp.DeleteObject();
	DCMem.DeleteDC();
	ReleaseDC(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CCubeView printing

BOOL CCubeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCubeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCubeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCubeView diagnostics

#ifdef _DEBUG
void CCubeView::AssertValid() const
{
	CView::AssertValid();
}

void CCubeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCubeDoc* CCubeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCubeDoc)));
	return (CCubeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCubeView message handlers

void CCubeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default

	CView::OnKeyDown(nChar, nRepCnt, nFlags);

	switch(nChar)
	{
	case VK_UP:
		{
			Point3D pos = world.GetCamera ()->GetPos ();
			Vector3D front = world.GetCamera ()->GetFront ();
			world.GetCamera ()->SetPos (Point3D(pos.x + front.i*10, pos.y + front.j*10, pos.z + front.k*10));
		}
		break;
	case VK_DOWN:
		{
			Point3D pos = world.GetCamera ()->GetPos ();
			Vector3D front = world.GetCamera ()->GetFront ();
			world.GetCamera ()->SetPos (Point3D(pos.x - front.i*10, pos.y - front.j*10, pos.z - front.k*10));
		}
		break;

	case 'Q':
		{
			world.GetShape (0)->MoveBy (Vector3D(10, 0, 0));
		}
		break;
	case 'A':
		{
			world.GetShape (0)->MoveBy (Vector3D(-10, 0, 0));
		}
		break;
	case 'W':
		{
			world.GetShape (0)->MoveBy (Vector3D(0, 10, 0));
		}
		break;
	case 'S':
		{
			world.GetShape (0)->MoveBy (Vector3D(0, -10, 0));
		}
		break;
	case 'E':
		{
			world.GetShape (0)->MoveBy (Vector3D(0, 0, 10));
		}
		break;
	case 'D':
		{
			world.GetShape (0)->MoveBy (Vector3D(0, 0, -10));
		}
		break;
	case 'R':
		{
			world.GetShape (0)->RotationX (1);
		}
		break;
	case 'F':
		{
			world.GetShape (0)->RotationX (-1);
		}
		break;
	case 'T':
		{
			world.GetShape (0)->RotationY (1);
		}
		break;
	case 'G':
		{
			world.GetShape (0)->RotationY (-1);
		}
		break;
	case 'Y':
		{
			world.GetShape (0)->RotationZ (1);
		}
		break;
	case 'H':
		{
			world.GetShape (0)->RotationZ (-1);
		}
		break;
	case 'U':
		{
			world.GetShape (0)->Zoom (1.1f);
		}
		break;
	case 'J':
		{
			world.GetShape (0)->Zoom  (0.9f);
		}
		break;
	}
	OnDraw(0);
}

void CCubeView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnMouseMove(nFlags, point);

	if(nFlags & MK_LBUTTON)
	{
		Vector3D front = world.GetCamera ()->GetFront ();
		Vector3D up = world.GetCamera ()->GetUp();
		Vector3D side = world.GetCamera ()->GetSide ();

		if(point.y > lastMousePos.y)
		{
			world.GetCamera ()->SetFront (front - up/100.0f);
		}

		if(point.y < lastMousePos.y)
		{
			world.GetCamera ()->SetFront (front + up/100.0f);
		}

		if(point.x < lastMousePos.x)
		{
			world.GetCamera ()->SetFront (front - side/100.0f);
		}

		if(point.x > lastMousePos.x)
		{
			world.GetCamera ()->SetFront (front + side/100.0f);
		}
		OnDraw(0);
	}

	if(nFlags & MK_RBUTTON)
	{
		Vector3D light = world.GetCamera ()->GetLight ();
		Vector3D up = world.GetCamera ()->GetUp();
		Vector3D side = world.GetCamera ()->GetSide ();
		if(point.y > lastMousePos.y)
		{
			world.GetCamera ()->SetLight (light - up/100.0f);
		}
		if(point.y < lastMousePos.y)
		{
			world.GetCamera ()->SetLight (light + up/100.0f);
		}
		if(point.x < lastMousePos.x)
		{
			world.GetCamera ()->SetLight (light - side/100.0f);
		}
		if(point.x > lastMousePos.x)
		{
			world.GetCamera ()->SetLight (light + side/100.0f);
		}
		OnDraw(0);
	}
	lastMousePos = point;
}

void CCubeView::OnSetCameraPos() 
{
	// TODO: Add your command handler code here
	DialogSetCameraPos askCameraPos;
	if(askCameraPos.DoModal() == 1)
	{
		world.GetCamera ()->SetPos (Point3D(askCameraPos.m_cameraX ,askCameraPos.m_cameraY , askCameraPos.m_cameraZ ));
		OnDraw(0);
	}
}

void CCubeView::OnSetCameraFront() 
{
	// TODO: Add your command handler code here
	DialogSetCameraPos askCameraPos;
	if(askCameraPos.DoModal() == 1)
	{
		world.GetCamera ()->SetFront (Vector3D(askCameraPos.m_cameraX ,askCameraPos.m_cameraY , askCameraPos.m_cameraZ ));
		OnDraw(0);
	}
}

extern float ty_to_client_scale;

void CCubeView::OnPoint() 
{
	// TODO: Add your command handler code here
	world.GetCamera ()->SetType (Camera::T_POINT);
	ty_to_client_scale = 1300;
	OnDraw(0);
}
void CCubeView::OnPingxing() 
{
	// TODO: Add your command handler code here
	world.GetCamera ()->SetType (Camera::T_PINGXING);
	ty_to_client_scale = 1;
	OnDraw(0);
}
