#pragma once

#ifndef DETAIL_PRODUCT__H_INCLUDED_
#define DETAIL_PRODUCT__H_INCLUDED_

#ifdef DETAIL_PRODUCT__SDK_LIBRARY_EXPORT // inside DLL
#   define DETAIL_PRODUCT   __declspec(dllexport)
#else //outside DLL
#   define DETAIL_PRODUCT   __declspec(dllimport)
#endif  //DETAIL_PRODUCT__SDK_LIBRARY_EXPORT 


class CDetailProduct
{
public:
	CDetailProduct(void);
	virtual ~CDetailProduct(void);

	CString GetSymbol() ;
	void SetSymbol(CString Symbol) ;

	CString GetType();
	void SetType(CString Type);

	CString GetExchange();
	void SetExchange(CString Exchange);

	CString GetOptionType();
	void SetOptionType(CString OptionType);

	double GetStrikePrice();
	void SetStrikePrice(double StrikePrice);

	int GetExpirationYear();
	void SetExpirationYear(int ExpirationYear);

	int GetExpirationMonth();
	void SetExpirationMonth(int ExpirationMonth);

	int GetExpirationDay();
	void SetExpirationDay(int ExpirationDay);

	void Serialize(CString &strString);
private:
	CString		m_Symbol;
    CString		m_Type;
    CString		m_Exchange;
    CString		m_OptionType;
    double		m_StrikePrice;
    int			m_ExpirationYear;
    int			m_ExpirationMonth;
    int			m_ExpirationDay;
};					
#endif //DETAIL_PRODUCT__H_INCLUDED_
