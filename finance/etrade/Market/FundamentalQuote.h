#pragma once

#ifndef FUNDAMENTAL_QUOTE__H_INCLUDED_
#define FUNDAMENTAL_QUOTE__H_INCLUDED_

#ifdef FUNDAMENTAL_QUOTE__SDK_LIBRARY_EXPORT // inside DLL
#   define FUNDAMENTAL_QUOTE   __declspec(dllexport)
#else //outside DLL
#   define FUNDAMENTAL_QUOTE   __declspec(dllimport)
#endif  //FUNDAMENTAL_QUOTE__SDK_LIBRARY_EXPORT 

class FUNDAMENTAL_QUOTE CFundamentalQuote
{
public:
	CFundamentalQuote(void);
	virtual ~CFundamentalQuote(void);

	double GetLastTrade();
	void SetLastTrade(double lastTrade) ;
	
	long long GetVolume10Day();
	void SetVolume10Day(long long volume10Day);

	double GetEps();
	void SetEps(double eps);

	double GetEstEarnings() ;
	void SetEstEarnings(double estEarnings) ;

	double GetHigh52();
	void SetHigh52(double high52);

	double GetLow52();
	void SetLow52(double low52);

	CString GetSymbolDesc();
	void SetSymbolDesc(CString symbolDesc);

	CString GetCompanyName();
	void SetCompanyName(CString CompanyName);

	void Serialize(CString &strString);
private :
	CString		m_CompanyName;
	double		m_Eps;
	double		m_EstEarnings;
	double		m_High52;
	double		m_LastTrade;
	double		m_Low52;
	CString		m_SymbolDesc;
	long long	m_volume10Day;
};
#endif //FUNDAMENTAL_QUOTE__H_INCLUDED_
