#pragma once

#ifndef _ACCOUNTDTBALANCE_H_INCLUDED_
#define _ACCOUNTDTBALANCE_H_INCLUDED_

#ifdef ACCOUNTDTBALANCE_LIBRARY_EXPORT // inside DLL
#   define CAccountDTBalance_INFO  __declspec(dllexport)
#else //outside DLL
#   define ACCOUNTS_INFO   __declspec(dllimport)
#endif  //ACCOUNTDTBALANCE_LIBRARY_EXPORT 



class CAccountDTBalance 
{
public:
	CAccountDTBalance(void);
	~CAccountDTBalance(void);

	double GetDtCashBalance() ;
	void SetDtCashBalance(double DtCashBalance);

	double GetDtMarginBalance();
	void SetDtMarginBalance(double DtMarginBalance);

	double GetDtMarginSecurities() ;
	void SetDtMarginSecurities(double DtMarginSecurities); 

	double GetDtNonMarginableSecuritiesAndOptions() ;
	void SetDtNonMarginableSecuritiesAndOptions(double DtNonMarginableSecuritiesAndOptions);

	EDayTraderStatus GetDtStatus() ;
	void SetDtStatus(EDayTraderStatus DtStatus);
	void SetDtStatus(CString DtStatus);

	void Serialize(CString &strString);
private:
	double m_DtCashBalance;
	double m_DtMarginBalance;
	double m_DtMarginSecurities;
	double m_DtNonMarginableSecuritiesAndOptions;
	EDayTraderStatus m_DtStatus;
};

#endif //_ACCOUNTDTBALANCE_H_INCLUDED_