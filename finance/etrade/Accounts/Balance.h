#pragma once

#ifndef _BALANCECOMMON_H_INCLUDED_
#define _BALANCECOMMON_H_INCLUDED_

#ifdef BALANCE_LIBRARY_EXPORT // inside DLL
#   define CBALANCE  __declspec(dllexport)
#else //outside DLL
#   define CBALANCE   __declspec(dllimport)
#endif  //BALANCE_LIBRARY_EXPORT 

class CBALANCE CBalance
{
public:
	CBalance(void);
	~CBalance(void);
	
	double GetCashCall() ;
	void SetCashCall(double CashCall) ;

	double GetNetAccountValue() ;
	void SetNetAccountValue(double NetAccountValue) ;

	double GetTotalSecuritiesValue() ;
	void SetTotalSecuritiesValue(double TotalSecuritiesValue) ;

	double GetTotalLongValue() ;
	void SetTotalLongValue(double TotalLongValue) ;

	double GetCashAvailableForWithdrawal() ;
	void SetCashAvailableForWithdrawal(double CashAvailableForWithdrawal) ;

	double GetSweepDepositAmount() ;
	void SetSweepDepositAmount(double SweepDepositAmount) ;
	
	double GetNetCash() ;
	void SetNetCash(double NetCash) ;
	
	double GetFundsWithheldFromPurchasePower();
	void SetFundsWithheldFromPurchasePower(double FundsWithheldFromPurchasePower) ;

	double GetFundsWithheldFromWithdrawal() ;
	void SetFundsWithheldFromWithdrawal(double FundsWithheldFromWithdrawal) ;

	void Serialize(CString &strString);
private:
	double m_CashAvailableForWithdrawal;
	double m_CashCall;
	double m_FundsWithheldFromPurchasePower;
	double m_FundsWithheldFromWithdrawal;
	double m_NetAccountValue;
	double m_NetCash;
	double m_SweepDepositAmount;
	double m_TotalLongValue;
	double m_TotalSecuritiesValue;
};
#endif//_BALANCECOMMON_H_INCLUDED_