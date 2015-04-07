// CubeView.h : interface of the CCubeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CUBEVIEW_H__4660C4E2_8865_4C0C_98AC_77529D10842C__INCLUDED_)
#define AFX_CUBEVIEW_H__4660C4E2_8865_4C0C_98AC_77529D10842C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "World.h"
#include "myCube.h"

class CCubeView : public CView
{
private:
	CPoint lastMousePos;
	World world;
protected: // create from serialization only
	CCubeView();
	DECLARE_DYNCREATE(CCubeView)

// Attributes
public:
	CCubeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCubeView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCubeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCubeView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSetCameraPos();
	afx_msg void OnSetCameraFront();
	afx_msg void OnPoint();
	afx_msg void OnPingxing();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CubeView.cpp
inline CCubeDoc* CCubeView::GetDocument()
   { return (CCubeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUBEVIEW_H__4660C4E2_8865_4C0C_98AC_77529D10842C__INCLUDED_)
