#pragma once

#ifndef _CASHACCOUNTBALANCE_H_INCLUDED_
#define _CASHACCOUNTBALANCE_H_INCLUDED_

#ifdef CASHACCOUNTBALANCE_LIBRARY_EXPORT // inside DLL
#   define CCASHACCOUNTBALANCE  __declspec(dllexport)
#else //outside DLL
#   define CCASHACCOUNTBALANCE   __declspec(dllimport)
#endif  //CASHACCOUNTBALANCE_LIBRARY_EXPORT 


class CCASHACCOUNTBALANCE CCashAccountBalance
{
public:
	CCashAccountBalance(void);
	~CCashAccountBalance(void);

	double GetCashAvailableForInvestment();
	void SetCashAvailableForInvestment(double CashAvailableForInvestment) ;

	double GetSettledCashForInvestment();
	void SetSettledCashForInvestment(double SettledCashForInvestment) ;

	double GetUnSettledCashForInvestment() ;
	void SetUnSettledCashForInvestment(double UnSettledCashForInvestment) ;

	double GetCashBalance();
	void SetCashBalance(double CashBalance) ;
	
	void Serialize(CString &strString);
private:
	double m_CashAvailableForInvestment;
    double m_CashBalance;
	double m_SettledCashForInvestment;
    double m_UnSettledCashForInvestment;
};
#endif //_CASHACCOUNTBALANCE_H_INCLUDED_