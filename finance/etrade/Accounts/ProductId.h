#pragma once

#ifndef _PRODUCTID_H_INCLUDED_
#define _PRODUCTID_H_INCLUDED_

#ifdef PRODUCTID_LIBRARY_EXPORT // inside DLL
#   define CPRODUCTID  __declspec(dllexport)
#else //outside DLL
#   define CPRODUCTID   __declspec(dllimport)
#endif  //PRODUCTID_LIBRARY_EXPORT 


class CPRODUCTID CProductId
{
public:
	CProductId(void);
	~CProductId(void);

	CString GetSymbol() ;
	void SetSymbol(CString Symbol) ;

	CString GetTypeCode() ;
	void SetTypeCode(CString TypeCode) ;

	ECallPut GetCallPut() ;
	void  SetCallPut(ECallPut CallPut);
	void  SetCallPut(CString str);

	double GetStrikePrice() ;
	void  SetStrikePrice(double StrikePrice) ;

	int GetExpYear() ;
	void SetExpYear(int ExpYear) ;

	int GetExpMonth() ;
	void SetExpMonth(int ExpMonth) ;

	int GetExpDay() ;
	void SetExpDay(int ExpDay) ;
	void Serialize(CString &strString);
private:
	CString m_Symbol;
	CString m_TypeCode;
	ECallPut m_CallPut;
	double m_StrikePrice;
	int m_ExpYear;
	int m_ExpMonth;
	int m_ExpDay;
};
#endif//#define _PRODUCTID_H_INCLUDED_