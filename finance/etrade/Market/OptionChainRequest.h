#pragma once


#ifndef _OPTION_CHAIN_REQUEST__H_INCLUDED_
#define _OPTION_CHAIN_REQUEST__H_INCLUDED_

#ifdef OPTION_CHAIN_REQUEST__SDK_LIBRARY_EXPORT // inside DLL
#   define OPTION_CHAIN_REQUEST   __declspec(dllexport)
#else //outside DLL
#   define OPTION_CHAIN_REQUEST   __declspec(dllimport)
#endif  //OPTION_CHAIN_REQUEST__SDK_LIBRARY_EXPORT

class OPTION_CHAIN_REQUEST COptionChainRequest
{
public:
	COptionChainRequest(void);
	virtual ~COptionChainRequest(void);

	CString GetUnderlier();
	void SetUnderlier(CString Underlier) ;

	CString GetChainType(); 
	void SetChainType(CString ChainType) ;

	CString GetExpirationDay() ;
	void SetExpirationDay(CString ExpirationDay);

	CString GetExpirationMonth() ;
	void SetExpirationMonth(CString ExpirationMonth);

	CString GetExpirationYear() ;
	void SetExpirationYear(CString expirationYear) ;

	CString GetSkipAdjusted();
	void SetSkipAdjusted(CString skipAdjusted) ;

	void Serialize(CString &strString);
private:
	CString m_ExpirationDay;
	CString m_ExpirationMonth;
    CString m_ExpirationYear;
    CString m_ChainType;
    CString m_SkipAdjusted;
    CString m_Underlier;
};

#endif //_OPTION_CHAIN_REQUEST__H_INCLUDED_