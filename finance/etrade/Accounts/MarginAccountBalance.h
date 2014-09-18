#pragma once

#ifndef _MARGINACCOUNTBALANCE_H_INCLUDED_
#define _MARGINACCOUNTBALANCE_H_INCLUDED_


#ifdef MARGINACCOUNTBALANCE_LIBRARY_EXPORT // inside DLL
#   define CMARGINACCOUNTBALANCE  __declspec(dllexport)
#else //outside DLL
#   define CMARGINACCOUNTBALANCE   __declspec(dllimport)
#endif  //MARGINACCOUNTBALANCE_LIBRARY_EXPORT 


#include "Balance.h"
#include "AccountDTBalance.h"

class CMARGINACCOUNTBALANCE CMarginAccountBalance 
{
public:
	CMarginAccountBalance(void);
	~CMarginAccountBalance(void);
	    
	CAccountDTBalance GetDtBalance();
	void SetDtBalance(CAccountDTBalance DtBalance) ;

	bool IsFedCall() ;
	void SetFedCall(bool FedCall) ;

	double GetMarginBalance() ;
	void SetMarginBalance(double MarginBalance) ;
	
	double GetMarginBalanceWithdrawal() ;
	void SetMarginBalanceWithdrawal(double MarginBalanceWithdrawal) ;
	
	double GetMarginEquity() ;
	void SetMarginEquity(double MarginEquity);

	double GetMarginEquityPct();
	void SetMarginEquityPct(double MarginEquityPct);

	double GetMarginableSecurities() ;
	void SetMarginableSecurities(double MarginableSecurities);

	double GetMaxAvailableForWithdrawal();
	void SetMaxAvailableForWithdrawal(double MaxAvailableForWithdrawal);

	bool IsMinEquityCall() ;
	void SetMinEquityCall(bool MinEquityCall) ;
	
	double GetNonMarginableSecuritiesAndOptions();
	void SetNonMarginableSecuritiesAndOptions(double NonMarginableSecuritiesAndOptions) ;
	
	double GetTotalShortValue();
	void SetTotalShortValue(double TotalShortValue) ;
	
	double GetShortReserve() ;
	void SetShortReserve(double ShortReserve) ;
	void Serialize(CString &strString);
private:
    CAccountDTBalance m_DtBalance;
    bool m_FedCall;
    double m_MarginBalance;
    double m_MarginBalanceWithdrawal;
    double m_MarginEquity;
    double m_MarginEquityPct;
    double m_MarginableSecurities;
    double m_MaxAvailableForWithdrawal;
    bool m_MinEquityCall;
    double m_NonMarginableSecuritiesAndOptions;
    double m_TotalShortValue;
    double m_ShortReserve;
};
#endif//_MARGINACCOUNTBALANCE_H_INCLUDED_