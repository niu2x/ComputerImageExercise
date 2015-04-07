// anotherDoc.h : interface of the CAnotherDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANOTHERDOC_H__CD69300E_B1CC_49B4_BD0E_EBA7971D35EA__INCLUDED_)
#define AFX_ANOTHERDOC_H__CD69300E_B1CC_49B4_BD0E_EBA7971D35EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAnotherDoc : public CDocument
{
protected: // create from serialization only
	CAnotherDoc();
	DECLARE_DYNCREATE(CAnotherDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnotherDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAnotherDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAnotherDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANOTHERDOC_H__CD69300E_B1CC_49B4_BD0E_EBA7971D35EA__INCLUDED_)
