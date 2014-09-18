#pragma once

#ifndef ORDER_LIST_REQUEST__H_INCLUDED_
#define ORDER_LIST_REQUEST__H_INCLUDED_

#ifdef ORDER_LIST_REQUEST__SDK_LIBRARY_EXPORT // inside DLL
#   define ORDER_LIST_REQUEST   __declspec(dllexport)
#else //outside DLL
#   define ORDER_LIST_REQUEST   __declspec(dllimport)
#endif  //ORDER_LIST_REQUEST__SDK_LIBRARY_EXPORT

class ORDER_LIST_REQUEST COrderListRequest
{
public:
	COrderListRequest(void);
	virtual ~COrderListRequest(void);

 	CString GetAccountId();
    void SetAccountId(CString AccountId);

    CString GetMarker();
	void SetMarker(CString Marker);

    CString GetCount();
    void SetCount(CString Count);

	void Serialize(CString &strString);
private:
	CString m_AccountId;
    CString m_Marker;
    CString m_Count;
};
#endif//ORDER_LIST_REQUEST__H_INCLUDED_
