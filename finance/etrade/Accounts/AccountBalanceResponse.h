#pragma once

#ifndef _ACCOUNTBALANCERESPONSE_H_INCLUDED_
#define _ACCOUNTBALANCERESPONSE_H_INCLUDED_

#include "CashAccountBalance.h"
#include "MarginAccountBalance.h"

#ifdef ACCOUNTBALANCERESPONSE_LIBRARY_EXPORT // inside DLL
#   define ACCOUNTBALANCERESPONSE   __declspec(dllexport)
#else //outside DLL
#   define ACCOUNTBALANCERESPONSE   __declspec(dllimport)
#endif  //ACCOUNTBALANCERESPONSE_LIBRARY_EXPORT 

class ACCOUNTBALANCERESPONSE CAccountBalanceResponse
{
public:
	CAccountBalanceResponse(void);
	~CAccountBalanceResponse(void);

	CString GetAccountId();
	void SetAccountId(CString AccountId);

	EMarginLevel GetMarginLevel();
	void SetMarginLevel(EMarginLevel AccountType);
	void SetMarginLevel(CString str); 

	EOptionLevel GetOptionLevel(); 
	void SetOptionLevel(EOptionLevel OptionLevel);
	void SetOptionLevel(CString str); 

	CBalance GetAccountBalance();
	void SetAccountBalance(CBalance AccountBalance) ;

	CCashAccountBalance GetCashAccountBalance() ;
	void SetCashccountBalance(CCashAccountBalance CashAccountBalance) ;

	CMarginAccountBalance GetMarginAccountBalance() ;
	void SetMarginAccountBalance(CMarginAccountBalance MarginAccountBalance);
	void Serialize(CString &strAccount);
private:
	CString m_AccountId;
	EMarginLevel m_accountType;
	EOptionLevel m_OptionLevel;
    CBalance m_AccountBalance;
	CCashAccountBalance m_CashAccountBalance;
	CMarginAccountBalance m_MarginAccountBalance;
};
#endif //_ACCOUNTBALANCERESPONSE_H_INCLUDED_