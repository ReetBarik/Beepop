#if !defined(AFX_CHARTSTYLE_H__12DF2520_6AF6_11D4_AC53_444553546170__INCLUDED_)
#define AFX_CHARTSTYLE_H__12DF2520_6AF6_11D4_AC53_444553546170__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CLineStyle;
class CFillStyle;
class CSymbolStyle;
class CSliceStyle;

/////////////////////////////////////////////////////////////////////////////
// CChartStyle wrapper class

class CChartStyle : public COleDispatchDriver
{
public:
	CChartStyle() {}		// Calls COleDispatchDriver default constructor
	CChartStyle(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CChartStyle(const CChartStyle& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:
	CLineStyle GetLine();
	CFillStyle GetFill();
	CSymbolStyle GetSymbol();
	LPDISPATCH GetParent();
	CSliceStyle GetSlice();

// Operations
public:
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHARTSTYLE_H__12DF2520_6AF6_11D4_AC53_444553546170__INCLUDED_)
