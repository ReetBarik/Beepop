// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "location.h"

// Dispatch interfaces referenced by this interface
#include "derivedlong.h"


/////////////////////////////////////////////////////////////////////////////
// CLocation properties

CDerivedLong CLocation::GetLeft()
{
	LPDISPATCH pDispatch;
	GetProperty(0x1, VT_DISPATCH, (void*)&pDispatch);
	return CDerivedLong(pDispatch);
}

CDerivedLong CLocation::GetTop()
{
	LPDISPATCH pDispatch;
	GetProperty(0x2, VT_DISPATCH, (void*)&pDispatch);
	return CDerivedLong(pDispatch);
}

CDerivedLong CLocation::GetWidth()
{
	LPDISPATCH pDispatch;
	GetProperty(0x3, VT_DISPATCH, (void*)&pDispatch);
	return CDerivedLong(pDispatch);
}

CDerivedLong CLocation::GetHeight()
{
	LPDISPATCH pDispatch;
	GetProperty(0x4, VT_DISPATCH, (void*)&pDispatch);
	return CDerivedLong(pDispatch);
}

LPDISPATCH CLocation::GetParent()
{
	LPDISPATCH result;
	GetProperty(0x5, VT_DISPATCH, (void*)&result);
	return result;
}

/////////////////////////////////////////////////////////////////////////////
// CLocation operations
