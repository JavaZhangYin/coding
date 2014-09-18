// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxdisp.h>        // MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#include <list>

#define ORDER_SDK_LIBRARY_EXPORT
#define ERROR_SDK_LIBRARY_EXPORT

#define ORDER_LIST_REQUEST__SDK_LIBRARY_EXPORT
#define ORDER_LIST_RESPONSE__SDK_LIBRARY_EXPORT
#define ORDER_DETAILS__SDK_LIBRARY_EXPORT
#define ORDER__SDK_LIBRARY_EXPORT
#define GROUP_ORDER__SDK_LIBRARY_EXPORT
#define LEG_DETAILS__SDK_LIBRARY_EXPORT
#define SYMBOL_INFO__SDK_LIBRARY_EXPORT
#define BASIC_ORDER_REQUEST_SDK_LIBRARY_EXPORT
#define BASIC_ORDER_RESPONSE_SDK_LIBRARY_EXPORT
#define CANCEL_ORDER_REQUEST_SDK_LIBRARY_EXPORT

#define CANCEL_ORDER_RESPONSE_SDK_LIBRARY_EXPORT
#define CANCEL_ORDER_SDK_LIBRARY_EXPORT
#define CANCEL_RESPONSE_SDK_LIBRARY_EXPORT
#define CHANGE_EQUITY_ORDER_REQUEST_SDK_LIBRARY_EXPORT
#define CHANGE_EQUITY_ORDER_RESPONSE_SDK_LIBRARY_EXPORT
#define CHANGE_OPTION_ORDER_REQUEST__SDK_LIBRARY_EXPORT
#define CHANGE_OPTION_ORDER_RESPONSE__SDK_LIBRARY_EXPORT
#define CHANGE_ORDER_BASE__SDK_LIBRARY_EXPORT
#define EQUITY_ORDER_REQUEST__SDK_LIBRARY_EXPORT
#define EQUITY_ORDER_RESPONSE__SDK_LIBRARY_EXPORT
#define ETAPP_MESSAGES__SDK_LIBRARY_EXPORT
#define ET_MESSAGES__SDK_LIBRARY_EXPORT
#define OPTION_ORDER_REQUEST__SDK_LIBRARY_EXPORT
#define OPTION_ORDER_RESPONSE__SDK_LIBRARY_EXPORT
#define OPTION_SYMBOL__SDK_LIBRARY_EXPORT
#define REQUEST_BASE__SDK_LIBRARY_EXPORT
#define RESULT_BASE__SDK_LIBRARY_EXPORT
#define SYMBOL_BASE__SDK_LIBRARY_EXPORT

#include "OrderEnumDef.h"
