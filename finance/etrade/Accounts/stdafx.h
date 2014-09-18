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

#define ACCOUNTS_SDK_LIBRARY_EXPORT
#define ACCOUNTS_LIBRARY_EXPORT
#define ACCOUNTBALANCE_LIBRARY_EXPORT
#define ACCOUNTPOSITION_LIBRARY_EXPORT
#define ACCOUNTBALANCERESPONSE_LIBRARY_EXPORT
#define	ACCOUNTPOSITIONSRESPONSE_LIBRARY_EXPORT
#define ALERT_SDK_LIBRARY_EXPORT
#define DELETEALERTRESPONSE_SDK_LIBRARY_EXPORT
#define ACCOUNTBALANCERESPONSE_LIBRARY_EXPORT
#define ACCOUNTPOSITIONSREQUEST_LIBRARY_EXPORT
#define BALANCE_LIBRARY_EXPORT
#define CASHACCOUNTBALANCE_LIBRARY_EXPORT
#define ALERTDETAILSRESPONSE_LIBRARY_EXPORT
#define MARGINACCOUNTBALANCE_LIBRARY_EXPORT
#define PRODUCTID_LIBRARY_EXPORT
#define ERROR_SDK_LIBRARY_EXPORT
#define TRANSACTIONS_LIBRARY_EXPORT
#define TRANSACTION_LIBRARY_EXPORT
#define TRANSACTIONSREQUEST_LIBRARY_EXPORT
#define TRANSACTIONDETAILS_LIBRARY_EXPORT
#include "EnumDefs.h"