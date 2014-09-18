#pragma once

#ifndef OPTION_SYMBOL__H_INCLUDED_
#define OPTION_SYMBOL__H_INCLUDED_

#ifdef OPTION_SYMBOL__SDK_LIBRARY_EXPORT // inside DLL
#   define OPTION_SYMBOL   __declspec(dllexport)
#else //outside DLL
#   define OPTION_SYMBOL   __declspec(dllimport)
#endif  //OPTION_SYMBOL__SDK_LIBRARY_EXPORT

class OPTION_SYMBOL COptionSymbol
{
public:
	COptionSymbol(void);
	virtual ~COptionSymbol(void);

	void Serialize(CString &strString);

	CString GetSymbol();
	void SetSymbol(CString Symbol) ;

//	CallOrPut GetCallOrPut();
	CString GetCallOrPut();
//	void SetCallOrPut(CallOrPut CallOrPut);
	void SetCallOrPut(CString str);

	double GetStrikePrice();
	void SetStrikePrice(double StrikePrice);

	long long GetExpirationYear();
	void SetExpirationYear(long long ExpirationYear) ;

	long long GetExpirationMonth();
	void SetExpirationMonth(long long ExpirationMonth) ;

	long long GetExpirationDay();
	void SetExpirationDay(long long ExpirationDay) ;

private:
	CString				m_Symbol;
//	CallOrPut	m_CallOrPut;
	CString				m_CallOrPut;
	double				m_StrikePrice;
	long long			m_ExpirationYear;
	long long			m_ExpirationMonth;
	long long			m_ExpirationDay;
};

#endif//OPTION_SYMBOL__H_INCLUDED_