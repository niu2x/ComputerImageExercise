// RoundEllipseDoc.h : interface of the CRoundEllipseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROUNDELLIPSEDOC_H__54E5586E_AF66_4DA8_9EE4_ED6DAB754D29__INCLUDED_)
#define AFX_ROUNDELLIPSEDOC_H__54E5586E_AF66_4DA8_9EE4_ED6DAB754D29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRoundEllipseDoc : public CDocument
{
protected: // create from serialization only
	CRoundEllipseDoc();
	DECLARE_DYNCREATE(CRoundEllipseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoundEllipseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRoundEllipseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRoundEllipseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROUNDELLIPSEDOC_H__54E5586E_AF66_4DA8_9EE4_ED6DAB754D29__INCLUDED_)
