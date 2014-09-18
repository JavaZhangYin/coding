#pragma once
//#include "StdAfx.h"
#include "EnumDefs.h"

#ifndef _ACCOUNTSDK_H_INCLUDED_
#define _ACCOUNTSDK_H_INCLUDED_

#include "..\..\common\Common\CommonDefs.h"
#include "..\..\common\Common\ClientDetails.h"
#include "..\..\common\Common\OAuthHelper.h"


#include "Account.h"
#include "Balance.h"
#include "AccountBalanceResponse.h"
#include "AccountPosition.h"
#include "AccountPositionsResponse.h"
#include "Alert.h"
#include "AlertDetailsResponse.h"
#include "DeleteAlertResponse.h"
#include "Error.h"
#include "AccountPositionsRequest.h"

#include "TransactionsRequest.h"
#include "Transactions.h"
#include "transactionDetails.h"

#ifdef ACCOUNTS_SDK_LIBRARY_EXPORT // inside DLL
#   define ACCOUNTS_SDK   __declspec(dllexport)
#else //outside DLL
#   define ACCOUNTS_SDK   __declspec(dllimport)
#endif  //ACCOUNTS_SDK_LIBRARY_EXPORT

typedef std::list<CAccount> AccountList;
typedef std::list<CAlert> AlertList;


class ACCOUNTS_SDK CAccountSDK
{
public:
	CAccountSDK(CClientDetails objClientDetails);
	~CAccountSDK(void);
public:
	AccountList GetAccountList() throw (...);
	CAccountBalanceResponse GetAccountBalance(CString strAccountId) throw (...);
	CAccountPositionsResponse GetAccountPositions(CAccountPositionsRequest accountPositionsRequest)throw (...);
	AlertList GetAlerts() throw (...);
	CAlertDetailsResponse GetAlertDetails(int nAlertID) throw (...);
	CDeleteAlertResponse DeleteAlert(int nAlertID)throw (...);

//	CTransactions GetTransactions(CTransactionsRequest transactionsRequest,CString transactionsUrl = "")throw (...);
//	CTransactionDetails GetTransactionsDetails(CString transactionDetailUrl)throw (...);
	
	void CheckClientRequestObject()throw (...);
	void SetClientDetails(CClientDetails objClientDetails){m_objClientDetails = objClientDetails;}
private:
	HTTPParameters constructParameters(CAccountPositionsRequest accountPositionsRequest) ;
	CString ConstructFullURL(CString Resource,CString AbstractId="") ;
	CClientDetails m_objClientDetails;
	COAuthHelper m_ObjOAuthHelper;
	static CString m_PrdHost ;
	static CString m_SandboxHost;
	static CString m_SandboxURL;
	static CString m_LiveURL;

//	static CString m_TransactionsSandBoxURL;
//	static CString m_TransactionsLiveURL;
};
#endif //#define _ACCOUNTSDK_H_INCLUDED_