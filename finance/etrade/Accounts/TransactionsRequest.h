#pragma once

#include <list>

#ifndef _TRANSACTIONSREQUEST_H_INCLUDED_
#define _TRANSACTIONSREQUEST_H_INCLUDED_


#ifdef TRANSACTIONSREQUEST_LIBRARY_EXPORT // inside DLL
#   define TRANSACTIONSREQUEST   __declspec(dllexport)
#else //outside DLL
#   define TRANSACTIONSREQUEST   __declspec(dllimport)
#endif  //TRANSACTIONSREQUEST_LIBRARY_EXPORT 

typedef std::list<ETransType>	ETranTypeList;
typedef std::list<std::string>		TranTypeList;

class TRANSACTIONSREQUEST CTransactionsRequest
{
public:
	CTransactionsRequest(void);
	virtual ~CTransactionsRequest(void);

	CString GetAccountId();
	void SetAccountId(CString AccountId) ;

	int GetCount();
	void SetCount(int Count) ;

	CString GetFromDate();
	void SetFromDate(CString FromDate) ;

	CString GetFromDateInMiliSec();
	void SetFromDateInMiliSec(CString FromDateInMiliSec) ;

	CString GetMarker();
	void SetMarker(CString Marker) ;

	CString GetSymbol();
	void SetSymbol(CString Symbol) ;

	CString GetToDate();
	void SetToDate(CString ToDate) ;

	CString GetToDateInMiliSec();
	void SetToDateInMiliSec(CString ToDateInMiliSec) ;

/*	CString GetTranGroup();
	void SetTranGroup(EGroupType TranGroup) ;

	CString GetTranType();
	void SetTranType(ETranTypeList TranType) ;

	CString GetAssetType();
	void SetAssetType(EAssetType AssetType) ;
*/
	CString GetTranGroup();
	void SetTranGroup(CString TranGroup) ;

	CString GetTranType();
	void SetTranType(CString TranType) ;

	CString GetAssetType();
	void SetAssetType(CString AssetType) ;

private:
	CString					m_AccountId;
	int						m_Count;
	CString					m_FromDate;
    CString					m_FromDateInMiliSec;
	CString					m_Marker;
    CString					m_Symbol;
    CString					m_ToDate;
	CString					m_ToDateInMiliSec;
//    EGroupType				m_TranGroup;
//    ETranTypeList			m_TranType;
//	EAssetType				m_AssetType;
    CString				m_TranGroup;
    CString				m_TranType;
	CString				m_AssetType;
};

#endif //_TRANSACTIONSREQUEST_H_INCLUDED_