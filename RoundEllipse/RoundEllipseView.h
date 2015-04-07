// RoundEllipseView.h : interface of the CRoundEllipseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROUNDELLIPSEVIEW_H__0708757F_5CA7_4DF4_9CD1_D107EC77BF1E__INCLUDED_)
#define AFX_ROUNDELLIPSEVIEW_H__0708757F_5CA7_4DF4_9CD1_D107EC77BF1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRoundEllipseView : public CView
{
private:
	enum {T_ROUND = 0, T_ELLIPSE};
	int type;
	int drawing;
	CPoint point1;
	CPoint point2;

	CPoint roundGrp[1024];
	int roundNum;

	CPoint ellipseGrp[1024];
	int ellipseNum;

	CDC dc;

	void drawSaved();
	void drawDrawing();
	void saveRound();
	void saveEllipse();

	void drawRound(CPoint, int radius);
	void drawEllipse(int a, int b, int ox, int oy);

protected: // create from serialization only
	CRoundEllipseView();
	DECLARE_DYNCREATE(CRoundEllipseView)

// Attributes
public:
	CRoundEllipseDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoundEllipseView)
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
	virtual ~CRoundEllipseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRoundEllipseView)
	afx_msg void OnELLIPSE();
	afx_msg void OnROUND();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDhk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RoundEllipseView.cpp
inline CRoundEllipseDoc* CRoundEllipseView::GetDocument()
   { return (CRoundEllipseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROUNDELLIPSEVIEW_H__0708757F_5CA7_4DF4_9CD1_D107EC77BF1E__INCLUDED_)
