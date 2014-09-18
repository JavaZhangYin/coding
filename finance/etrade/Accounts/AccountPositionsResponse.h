#pragma once

#ifndef _ACCOUNTPOSITIONSRESPONSE_H_INCLUDED_
#define _ACCOUNTPOSITIONSRESPONSE_H_INCLUDED_

#ifdef ACCOUNTPOSITIONSRESPONSE_LIBRARY_EXPORT // inside DLL
#   define CACCOUNTPOSITIONSRESPONSE  __declspec(dllexport)
#else //outside DLL
#   define CACCOUNTPOSITIONSRESPONSE   __declspec(dllimport)
#endif  //ACCOUNTPOSITIONSRESPONSE_LIBRARY_EXPORT 


#include "AccountPosition.h"
#include <list>

typedef std::list<CAccountPosition> AccountPositionList;

class CACCOUNTPOSITIONSRESPONSE CAccountPositionsResponse
{
public:
	CAccountPositionsResponse(void);
	virtual ~CAccountPositionsResponse(void);

	CString GetAccountId();
	void SetAccountId(CString AccountId) ;

	int GetCount() ;
	void SetCount(int Count) ;

	CString GetMarker() ;
	void SetMarker(CString Marker) ;

	AccountPositionList GetResponse();
	void SetResponse(AccountPositionList AccountPositionResponse);
	void Serialize(CString &strString);
private:
	CString m_AccountId;
	int m_Count;
	CString m_Marker;
	AccountPositionList m_AccountPositionResponse;
};
#endif //_ACCOUNTPOSITIONSRESPONSE_H_INCLUDED_