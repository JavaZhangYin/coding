#pragma once

#ifndef OPTION_QUOTE__H_INCLUDED_
#define OPTION_QUOTE__H_INCLUDED_

#ifdef OPTION_QUOTE__SDK_LIBRARY_EXPORT // inside DLL
#   define OPTION_QUOTE   __declspec(dllexport)
#else //outside DLL
#   define OPTION_QUOTE   __declspec(dllimport)
#endif  //OPTION_QUOTE__SDK_LIBRARY_EXPORT 

class OPTION_QUOTE COptionQuote
{
public:
	COptionQuote(void);
	virtual ~COptionQuote(void);

	CString GetCompanyName();
	void SetCompanyName(CString companyName);
	
	double GetAsk() ;
	void SetAsk(double ask) ;

	long long GetAskSize() ;
	void SetAskSize(long long askSize) ;

	double GetBid();
	void SetBid(double bid) ;

	long long GetBidSize();
	void SetBidSize(long long bidSize) ;

	long long GetDaysToExpiration() ;
	void SetDaysToExpiration(long long daysToExpiration) ;

	double GetLastTrade();
	void SetLastTrade(double lastTrade);

	long long GetOpenInterest();
	void SetOpenInterest(long long  openInterest) ;
	void Serialize(CString &strString);
private:
	CString			m_CompanyName;
    double			m_Ask;
	long long		m_AskSize;
	double			m_Bid;
    long long 		m_BidSize;
	long long 		m_DaysToExpiration;
	double			m_LastTrade;
	long long			m_OpenInterest;

};			

#endif//OPTION_QUOTE__H_INCLUDED_
