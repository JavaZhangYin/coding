#pragma once

#include "AllQuote.h"
#include "FundamentalQuote.h"
#include "IntradayQuote.h"
#include "OptionQuote.h"
#include "Week52Quote.h"
#include "DetailProduct.h"

#ifndef QUOTE_DATA__H_INCLUDED_
#define QUOTE_DATA__H_INCLUDED_

#ifdef QUOTE_DATA__SDK_LIBRARY_EXPORT // inside DLL
#   define QUOTE_DATA   __declspec(dllexport)
#else //outside DLL
#   define QUOTE_DATA   __declspec(dllimport)
#endif  //QUOTE_DATA__SDK_LIBRARY_EXPORT 


class QUOTE_DATA CQuoteData
{
public:
	CQuoteData(void);
	virtual ~CQuoteData(void);

	CString GetErrorMessage() ;
	void SetErrorMessage(CString errorMessage) ;

	CString GetDateTime();
	void SetDateTime(CString dateTime) ;

	CAllQuote GetAll();
	void SetAll(CAllQuote all) ;

	CFundamentalQuote GetFundamental() ;
	void SetFundamental(CFundamentalQuote fundamental) ;

	CIntradayQuote GetIntraday() ;
	void SetIntraday(CIntradayQuote intraday) ;

	COptionQuote GetOption() ;
	void SetOption(COptionQuote option) ;

	CDetailProduct GetDetailProduct() ;
	void SetDetailProduct(CDetailProduct DetailProduct) ;

	CWeek52Quote GetWeek52();
	void SetWeek52(CWeek52Quote week52) ;

	void Serialize(CString &strString);
private: 
	CString m_ErrorMessage;
	CString m_DateTime;
	
	CAllQuote			m_All;
    CFundamentalQuote	m_Fundamental;
    CIntradayQuote		m_Intraday;
    COptionQuote			m_Option;
	CDetailProduct		m_Product;
    CWeek52Quote			m_Week52;    
};

#endif//QUOTE_DATA__H_INCLUDED_