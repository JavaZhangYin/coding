#pragma once

#ifndef _ACCOUNTPOSITIONSREQUEST_H_INCLUDED_
#define _ACCOUNTPOSITIONSREQUEST_H_INCLUDED_

#ifdef ACCOUNTPOSITIONSREQUEST_LIBRARY_EXPORT // inside DLL
#   define CACCOUNTPOSITIONSREQUEST  __declspec(dllexport)
#else //outside DLL
#   define CACCOUNTPOSITIONSREQUEST   __declspec(dllimport)
#endif  //ACCOUNTPOSITIONSREQUEST_LIBRARY_EXPORT 


class CACCOUNTPOSITIONSREQUEST CAccountPositionsRequest
{
public:
	CAccountPositionsRequest(void);
	virtual ~CAccountPositionsRequest(void);

    CString GetAccountId(); 
	void SetAccountId(CString AccountId);

	CString GetCount() ;
    void SetCount(CString Count) ;

    CString GetMarker() ;
    void SetMarker(CString Marker);

    CString GetSymbol() ;
    void SetSymbol(CString Symbol);

    CString GetTypeCode() ;
    void SetTypeCode(CString TypeCode);

    CString GetCallPut();
    void SetCallPut(CString CallPut) ;

	double GetStrikePrice() ;
    void SetStrikePrice(double StrikePrice) ;

    CString GetExpYear() ;
    void SetExpYear(CString ExpYear) ;

    CString GetExpMonth() ;
    void SetExpMonth(CString ExpMonth) ;

    CString GetExpDay() ;
    void SetExpDay(CString ExpDay) ;
	void Serialize(CString &strString);

private:
	CString m_AccountId;
    CString m_Count;
    CString m_Marker;
    CString m_Symbol;
    CString m_TypeCode;
    CString m_CallPut;
    double m_StrikePrice;
    CString m_ExpYear;
    CString m_ExpMonth;
    CString m_ExpDay;
};
#endif//_ACCOUNTPOSITIONSREQUEST_H_INCLUDED_