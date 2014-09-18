#pragma once

#ifndef INTRADAY_QUOTE__H_INCLUDED_
#define INTRADAY_QUOTE__H_INCLUDED_

#ifdef INTRADAY_QUOTE__SDK_LIBRARY_EXPORT // inside DLL
#   define INTRADAY_QUOTE   __declspec(dllexport)
#else //outside DLL
#   define INTRADAY_QUOTE   __declspec(dllimport)
#endif  //INTRADAY_QUOTE__SDK_LIBRARY_EXPORT 

class INTRADAY_QUOTE CIntradayQuote
{
public:
	CIntradayQuote(void);
	virtual ~CIntradayQuote(void);

	CString GetCompanyName();
	void SetCompanyName(CString companyName);

	double GetLastTrade();
	void SetLastTrade(double lastTrade);

	double GetAsk() ;
	void SetAsk(double ask);

	double GetBid();
	void SetBid(double bid);

	double GetChgClose();
	void SetChgClose(double chgClose);

	double GetChgClosePrcn();
	void SetChgClosePrcn(double chgClosePrcn);

	double GetHigh();
	void SetHigh(double high);

	double GetLow();
	void SetLow(double low);

	long long GetTotalVolume();
	void SetTotalVolume(long long totalVolume) ;

	void Serialize(CString &strString);
private:
    CString		m_CompanyName;
	double		m_LastTrade;
	double		m_ChgClose;
	double		m_ChgClosePrcn;
	double		m_Bid;
	double		m_Ask;
	double		m_High;
	double		m_Low;
	long long 	m_TotalVolume;
};

#endif //INTRADAY_QUOTE__H_INCLUDED_