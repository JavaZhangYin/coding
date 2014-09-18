#pragma once

#ifndef WEEK52_QUOTE__H_INCLUDED_
#define WEEK52_QUOTE__H_INCLUDED_

#ifdef WEEK52_QUOTE__SDK_LIBRARY_EXPORT // inside DLL
#   define WEEK52_QUOTE   __declspec(dllexport)
#else //outside DLL
#   define WEEK52_QUOTE   __declspec(dllimport)
#endif  //WEEK52_QUOTE__SDK_LIBRARY_EXPORT 

class WEEK52_QUOTE CWeek52Quote
{
public:
	CWeek52Quote(void);
	virtual ~CWeek52Quote(void);

	double GetAnnualDividend();
	void SetAnnualDividend(double annualDividend) ;

	CString GetCompanyName();
	void SetCompanyName(CString companyName);


	double GetHigh52() ;
	void SetHigh52(double high52) ;

	double GetLastTrade() ;
	void SetLastTrade(double lastTrade);

	double GetLow52();
	void SetLow52(double low52);

	double GetPerf12Months() ;
	void SetPerf12Months(double perf12Months) ;

	double GetPrevClose() ;
	void SetPrevClose(double prevClose);

	CString GetSymbolDesc();
	void SetSymbolDesc(CString symbolDesc);

	long long GetTotalVolume();
	void SetTotalVolume(long long totalVolume) ;

	void Serialize(CString &strString);
private:
    double		m_AnnualDividend;
	CString		m_CompanyName;
	double		m_High52;
	double		m_LastTrade;
    double		m_Low52;
    double		m_Perf12Months;
	double		m_PrevClose;
	CString		m_SymbolDesc;
    long long 	m_TotalVolume;
 };
#endif//WEEK52_QUOTE__H_INCLUDED_

