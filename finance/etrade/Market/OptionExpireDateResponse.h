#pragma once

#include "ExpirationDate.h"

#ifndef _OPTION_EXPIREDATE_RESPONSE__H_INCLUDED_
#define _OPTION_EXPIREDATE_RESPONSE__H_INCLUDED_

#ifdef OPTION_EXPIREDATE_RESPONSE__SDK_LIBRARY_EXPORT // inside DLL
#   define OPTION_EXPIREDATE_RESPONSE   __declspec(dllexport)
#else //outside DLL
#   define OPTION_EXPIREDATE_RESPONSE   __declspec(dllimport)
#endif  //OPTION_EXPIREDATE_RESPONSE__SDK_LIBRARY_EXPORT

typedef std::list<CExpirationDate> ExpirationDateList;

class OPTION_EXPIREDATE_RESPONSE COptionExpireDateResponse
{
public:
	COptionExpireDateResponse(void);
	virtual ~COptionExpireDateResponse(void);

	CString GetSymbol() ;
	void SetSymbol(CString symbol);

	ExpirationDateList GetExpireDates();
	void SetExpireDates(ExpirationDateList expireDates) ;
	void Serialize(CString &strString);
private:
	CString m_Symbol;
	ExpirationDateList m_ExpireDatesList;
};

#endif//_OPTION_EXPIREDATE_RESPONSE__H_INCLUDED_