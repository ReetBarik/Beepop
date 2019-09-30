#if !defined(AFX_STRINGCOLLECTION_H__12DF2523_6AF6_11D4_AC53_444553546170__INCLUDED_)
#define AFX_STRINGCOLLECTION_H__12DF2523_6AF6_11D4_AC53_444553546170__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CStringCollection wrapper class

class CStringCollection : public COleDispatchDriver
{
public:
	CStringCollection() {}		// Calls COleDispatchDriver default constructor
	CStringCollection(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CStringCollection(const CStringCollection& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:
	long GetCount();
	LPDISPATCH GetParent();

// Operations
public:
	void Remove(long Index);
	void Add(LPCTSTR String, const VARIANT& BeforeIndex);
	CString GetItem(long Index);
	void SetItem(long Index, LPCTSTR lpszNewValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STRINGCOLLECTION_H__12DF2523_6AF6_11D4_AC53_444553546170__INCLUDED_)
