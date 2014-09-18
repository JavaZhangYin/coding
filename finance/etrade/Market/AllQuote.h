#pragma once

class CAllQuote
{
public:
	CAllQuote(void);
	virtual ~CAllQuote(void);

	double GetChgClose();
	void SetChgClose(double chgClose);

	double GetChgClosePrcn();
	void SetChgClosePrcn(double chgClosePrcn);

	double GetLastTrade();
	void SetLastTrade(double lastTrade);
	
	long long GetVolume10Day() ;
	void SetVolume10Day(long long volume10Day);

	bool isAdjNonAdjFlag();
	void SetAdjNonAdjFlag(bool adjNonAdjFlag);

	double GetAnnualDividend();
	void SetAnnualDividend(double annualDividend) ;

	double GetAsk();
	void SetAsk(double ask) ;

	CString GetAskExchange();
	void SetAskExchange(CString askExchange) ;

	long long GetAskSize();
	void SetAskSize(long long askSize) ;

	CString GetAskTime();
	void SetAskTime(CString askTime) ;


	double GetBeta() ;
	void SetBeta(double beta) ;

	double GetBid();
	void SetBid(double bid) ;

	CString GetBidExchange();
	void SetBidExchange(CString bidExchange) ;

	long long GetBidSize() ;
	void SetBidSize(long long bidSize) ;

	CString GetBidTime() ;
	void SetBidTime(CString bidTime) ;

	CString GetCompanyName() ;
	void SetCompanyName(CString companyName) ;

	long long GetDaysToExpiration() ;
	void SetDaysToExpiration(long long daysToExpiration) ;

	CString GetDirLast();
	void SetDirLast(CString dirLast) ;

	double GetDividend();
	void SetDividend(double dividend) ;

	double GetEps();
	void SetEps(double eps) ;

	double GetEstEarnings();
	void SetEstEarnings(double estEarnings) ;

	CString GetExchgLastTrade() ;
	void SetExchgLastTrade(CString exchgLastTrade) ;

	CString GetExDivDate();
	void SetExDivDate(CString exDivDate) ;


	CString GetFsi();
	void SetFsi(CString fsi);

	double GetHigh();
	void SetHigh(double high) ;

	double GetHigh52() ;
	void SetHigh52(double high52) ;

	double GetHighAsk() ;
	void SetHighAsk(double highAsk) ;

	double GetHighBid();
	void SetHighBid(double highBid) ;


	double GetLow();
	void SetLow(double low) ;

	double GetLow52() ;
	void SetLow52(double low52) ;

	double GetLowAsk();
	void SetLowAsk(double lowAsk) ;

	double GetLowBid() ;
	void SetLowBid(double lowBid) ;

	long long GetNumTrades() ;
	void SetNumTrades(long long numTrades) ;

	double GetOpen();
	void SetOpen(double open) ;

	long long GetOpenInterest() ;
	void SetOpenInterest(long long openInterest) ;

	CString GetOptionStyle() ;
	void SetOptionStyle(CString optionStyle) ;

	CString GetOptionUnderlier() ;
	void SetOptionUnderlier(CString optionUnderlier) ;

	double GetPrevClose() ;
	void SetPrevClose(double prevClose) ;

	long long GetPrevDayVolume() ;
	void SetPrevDayVolume(long long prevDayVolume) ;

	CString GetPrimaryExchange() ;
	void SetPrimaryExchange(CString primaryExchange) ;

	CString GetSymbolDesc() ;
	void SetSymbolDesc(CString symbolDesc) ;


	double GetTodayClose() ;
	void SetTodayClose(double todayClose) ;

	long long GetTotalVolume() ;
	void SetTotalVolume(long long totalVolume) ;

	long long GetUpc() ;
	void SetUpc(long long upc) ;

	void Serialize(CString &strString);
private:
    double			m_chgClose;
    double			m_chgClosePrcn;

	double			m_LastTrade;
	long long		m_Volume10Day;
    bool			m_AdjNonAdjFlag;
    double			m_AnnualDividend;
    double			m_Ask;
    CString			m_AskExchange;
    long long		m_AskSize;
    CString			m_AskTime;
    double			m_Beta;
    				
    double			m_Bid;
    CString			m_BidExchange;
    long long		m_BidSize;
    CString			m_BidTime;
    CString			m_CompanyName;    
    long long			m_DaysToExpiration;
    CString			m_DirLast;
    double			m_Dividend;
    double			m_Eps;
    double			m_EstEarnings;
    				
    CString			m_ExchgLastTrade;
    CString			m_ExDivDate;
    CString			m_Fsi;
    double			m_High;
    double			m_High52;
    double			m_HighAsk;
    double			m_HighBid;
    				
    double			m_Low;
    double			m_Low52;
    double			m_LowAsk;
    double			m_LowBid;
    long long		m_NumTrades;
    double			m_Open;
    long long 		m_OpenInterest;
    CString			m_OptionStyle;
    CString			m_OptionUnderlier;
    double			m_PrevClose;
    				
    long long 		m_PrevDayVolume;
    CString			m_PrimaryExchange;
    CString			m_SymbolDesc;
    double			m_TodayClose;
    long long		m_TotalVolume;
	long long		m_Upc;
};

