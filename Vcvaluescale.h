// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CVcValueScale wrapper class

class CVcValueScale : public COleDispatchDriver
{
public:
	CVcValueScale() {}		// Calls COleDispatchDriver default constructor
	CVcValueScale(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CVcValueScale(const CVcValueScale& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	BOOL GetAuto();
	void SetAuto(BOOL bNewValue);
	double GetMinimum();
	void SetMinimum(double newValue);
	double GetMaximum();
	void SetMaximum(double newValue);
	short GetMajorDivision();
	void SetMajorDivision(short nNewValue);
	short GetMinorDivision();
	void SetMinorDivision(short nNewValue);
};
