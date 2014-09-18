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


#define ERROR_SDK_LIBRARY_EXPORT
#define EXPIRATION_DATE__SDK_LIBRARY_EXPORT
#define MARKET_PRODUCTID__SDK_LIBRARY_EXPORT
#define MARKET_SDK_LIBRARY_EXPORT
#define OPTION_CHAIN_PAIR__SDK_LIBRARY_EXPORT
#define OPTION_CHAIN_REQUEST__SDK_LIBRARY_EXPORT
#define OPTION_CHAIN_RESPONSE__SDK_LIBRARY_EXPORT
#define OPTION_CHAIN__SDK_LIBRARY_EXPORT
#define OPTION_EXPIREDATE_REQUEST__SDK_LIBRARY_EXPORT
#define OPTION_EXPIREDATE_RESPONSE__SDK_LIBRARY_EXPORT
#define PRODUCT_LOOKUP_REQUEST__SDK_LIBRARY_EXPORT		
#define PRODUCT_LOOKUP_RESPONSE__SDK_LIBRARY_EXPORT
#define PRODUCT__SDK_LIBRARY_EXPORT

#define QUOTE_REQEUST__SDK_LIBRARY_EXPORT
#define QUOTE_RESPONSE__SDK_LIBRARY_EXPORT
#define QUOTE_DATA__SDK_LIBRARY_EXPORT
#define FUNDAMENTAL_QUOTE__SDK_LIBRARY_EXPORT
#define INTRADAY_QUOTE__SDK_LIBRARY_EXPORT
#define OPTION_QUOTE__SDK_LIBRARY_EXPORT
#define WEEK52_QUOTE__SDK_LIBRARY_EXPORT
#define CALL_OPTION_CHAIN__SDK_LIBRARY_EXPORT
#define PUT_OPTION_CHAIN__SDK_LIBRARY_EXPORT
#define DETAIL_PRODUCT__SDK_LIBRARY_EXPORT
#include "EnumDef.h"
