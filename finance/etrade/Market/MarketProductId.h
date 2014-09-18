#pragma once

#ifndef MARKET_PRODUCTID__H_INCLUDED_
#define MARKET_PRODUCTID__H_INCLUDED_

#ifdef MARKET_PRODUCTID__SDK_LIBRARY_EXPORT // inside DLL
#   define MARKET_PRODUCTID   __declspec(dllexport)
#else //outside DLL
#   define MARKET_PRODUCTID   __declspec(dllimport)
#endif  //MARKET_PRODUCTID__SDK_LIBRARY_EXPORT 

class MARKET_PRODUCTID CMarketProductId
{
public:
	CMarketProductId(void);
	virtual ~CMarketProductId(void);

	CString GetExchangeCode();
	void SetExchangeCode(CString exchangeCode) ;

	CString GetSymbol(); 
	void SetSymbol(CString symbol) ;

	CString GetTypeCode(); 
	void SetTypeCode(CString typeCode) ;

	void Serialize(CString &strString);
private:
	CString m_ExchangeCode;
	CString m_Symbol;
	CString m_TypeCode;
};
#endif //MARKET_PRODUCTID__H_INCLUDED_
