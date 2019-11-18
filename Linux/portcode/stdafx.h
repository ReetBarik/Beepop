#pragma once
#ifndef STDAFX_CUSTOM_H
#define STDAFX_CUSTOM_H

#define DECLARE_DYNCREATE(Class) // void
#define IMPLEMENT_DYNCREATE(Class, BaseClass) // void

#define DECLARE_SERIAL(Class) // void
#define IMPLEMENT_SERIAL(Class, BaseClass, Offset) // void

#define DECLARE_MESSAGE_MAP() // void
#define BEGIN_MESSAGE_MAP(Class, BaseClass) // void
#define END_MESSAGE_MAP() // void

#define DDX_Text(_1, _2, _3) // void
#define DDV_MinMaxInt(_1, _2, _3, _4) // void
#define DDX_Radio(_1, _2, _3) // void

#define afx_msg 

#include <cassert>
#define ASSERT assert

#include <memory>
#define DEBUG_NEW new

#include "fmt/printf.h"
// #define TRACE(...) fmt::printf(__VA_ARGS__)
#define TRACE(...) // void

#include <cstdint>
typedef int32_t BOOL;
typedef unsigned char BYTE;
typedef BYTE BOOLEAN;
typedef unsigned long DWORD;
typedef uint32_t UINT;
typedef const char* LPCTSTR;
typedef char TCHAR;
//typedef size_t INT_PTR;
typedef long LONG;

#include <ctime>
typedef time_t SYSTEMTIME;

#define TRUE true
#define FALSE false

// Abstract iteration position check if we can change to a size_t
typedef size_t POSITION;

#include "carchive.h"
#include "carray.h"
#include "cobject.h"
#include "cdialog.h"
#include "ccmdtarget.h"
#include "cfile.h"
#include "cmapstringtoob.h"
#include "coblist.h"
#include "coledatetime.h"
#include "cptrlist.h"
#include "cstring.h"
#include "cstringarray.h"
#include "cstdiofile.h"
#include "ctime.h"
#include "cuintarray.h"

#include "fmt/format.h"
FMT_BEGIN_NAMESPACE
template <> struct formatter<CString>
{
	auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
		return ctx.begin();
	}
	auto format(const CString& str, format_context& ctx) -> decltype(ctx.out()) {
		return format_to(ctx.out(), "%s", str.ToString());
	}
};
FMT_END_NAMESPACE

#include "fmt/ostream.h"
std::ostream &operator<<(std::ostream &stream, const CString& string)
{
    return stream << string.ToString();
}

#if !defined(_WIN32) && !defined(_WIN64) && !defined(__STDC_LIB_EXT1__)
#define strcpy_s strcpy
#define strtok_s(_In, _Delim, _SafeToken) strtok(_In, _Delim)
#endif

#endif // STDAFX_CUSTOM_H
