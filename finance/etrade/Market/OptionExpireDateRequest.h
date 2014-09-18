#pragma once

#ifndef _OPTION_EXPIREDATE_REQUEST__H_INCLUDED_
#define _OPTION_EXPIREDATE_REQUEST__H_INCLUDED_

#ifdef OPTION_EXPIREDATE_REQUEST__SDK_LIBRARY_EXPORT // inside DLL
#   define OPTION_EXPIREDATE_REQUEST   __declspec(dllexport)
#else //outside DLL
#   define OPTION_EXPIREDATE_REQUEST   __declspec(dllimport)
#endif  //OPTION_EXPIREDATE_REQUEST__SDK_LIBRARY_EXPORT

class OPTION_EXPIREDATE_REQUEST COptionExpireDateRequest
{
public:
	COptionExpireDateRequest(void);
	virtual ~COptionExpireDateRequest(void);

	CString GetSymbol(); 
	void SetSymbol(CString symbol);
private:
	CString m_symbol;
};
#endif//_OPTION_EXPIREDATE_REQUEST__H_INCLUDED_
