#pragma once

#ifndef SYMBOL_INFO__H_INCLUDED_
#define SYMBOL_INFO__H_INCLUDED_

#ifdef SYMBOL_INFO__SDK_LIBRARY_EXPORT // inside DLL
#   define SYMBOL_INFO   __declspec(dllexport)
#else //outside DLL
#   define SYMBOL_INFO   __declspec(dllimport)
#endif  //SYMBOL_INFO__SDK_LIBRARY_EXPORT

class SYMBOL_INFO CSymbolInfo
{
public:
	CSymbolInfo(void);
	virtual ~CSymbolInfo(void);
	void Serialize(CString &strString);

	CString GetSymbol() ;
	void SetSymbol(CString Symbol);

	ECallOrPut GetCallPut();
	void SetCallPut(ECallOrPut CallPut) ;
	void SetCallPut(CString str) ;

	int GetExpYear();
	void SetExpYear(int ExpYear);

	int GetExpMonth();
	void SetExpMonth(int ExpMonth);

	int GetExpDay() ;
	void SetExpDay(int ExpDay) ;

	double GetStrikePrice();
	void SetStrikePrice(double StrikePrice);

private:
	CString				m_Symbol;
	ECallOrPut		m_CallPut;
    int 				m_ExpYear;
    int					m_ExpMonth;
    int					m_ExpDay;
    double				m_StrikePrice;
};
#endif//SYMBOL_INFO__H_INCLUDED_
