// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "marker.h"

// Dispatch interfaces referenced by this interface
#include "LineStyle.h"
#include "DataIndex.h"
#include "DataCoord.h"


/////////////////////////////////////////////////////////////////////////////
// CMarker properties

CString CMarker::GetName()
{
	CString result;
	GetProperty(0x1, VT_BSTR, (void*)&result);
	return result;
}

BOOL CMarker::GetIsShowing()
{
	BOOL result;
	GetProperty(0x2, VT_BOOL, (void*)&result);
	return result;
}

void CMarker::SetIsShowing(BOOL propVal)
{
	SetProperty(0x2, VT_BOOL, propVal);
}

long CMarker::GetMethod()
{
	long result;
	GetProperty(0x3, VT_I4, (void*)&result);
	return result;
}

void CMarker::SetMethod(long propVal)
{
	SetProperty(0x3, VT_I4, propVal);
}

BOOL CMarker::GetIsStyleDefault()
{
	BOOL result;
	GetProperty(0x4, VT_BOOL, (void*)&result);
	return result;
}

void CMarker::SetIsStyleDefault(BOOL propVal)
{
	SetProperty(0x4, VT_BOOL, propVal);
}

CLineStyle CMarker::GetStyle()
{
	LPDISPATCH pDispatch;
	GetProperty(0x5, VT_DISPATCH, (void*)&pDispatch);
	return CLineStyle(pDispatch);
}

CDataIndex CMarker::GetIndex()
{
	LPDISPATCH pDispatch;
	GetProperty(0x6, VT_DISPATCH, (void*)&pDispatch);
	return CDataIndex(pDispatch);
}

CDataCoord CMarker::GetValue()
{
	LPDISPATCH pDispatch;
	GetProperty(0x7, VT_DISPATCH, (void*)&pDispatch);
	return CDataCoord(pDispatch);
}

LPDISPATCH CMarker::GetParent()
{
	LPDISPATCH result;
	GetProperty(0x8, VT_DISPATCH, (void*)&result);
	return result;
}

/////////////////////////////////////////////////////////////////////////////
// CMarker operations
