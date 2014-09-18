#pragma once

#ifndef _ACCOUNT_H_INCLUDED_
#define _ACCOUNT_H_INCLUDED_
#include "AccountSrv.h"

#ifdef ACCOUNTS_LIBRARY_EXPORT // inside DLL
#   define ACCOUNTS  __declspec(dllexport)
#else //outside DLL
#   define ACCOUNTS   __declspec(dllimport)
#endif  //ACCOUNTS_LIBRARY_EXPORT

class ACCOUNTS CAccount
{
public:
	CAccount(void);
	~CAccount(void);

public:
	CString GetAccountDesc();
	void SetAccountDesc(CString AccountDesc) ;

	CString GetAccountId();
	void SetAccountId(CString AccountId) ;

	EMarginLevel GetMarginLevel() ;
	void SetMarginLevel(EMarginLevel MarginLevel) ;
	void SetMarginLevel(CString str);

	double GetNetAccountValue() ;
	void SetNetAccountValue(double NetAccountValue);

	CString GetRegistrationType() ;
	void SetRegistrationType(CString RegistrationType) ;
	void Serialize(CString &strString);

private:
	CString MarginLevelFromEnum();
	CString m_AccountDesc;
	CString m_AccountId;
	EMarginLevel m_MarginLevel;
	double m_NetAccountValue;
	CString m_RegistrationType;
};
#endif//_ACCOUNT_H_INCLUDED_