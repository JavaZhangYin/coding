#pragma once
#include "OrderDetails.h"

#ifndef ORDER_LIST_RESPONSE__H_INCLUDED_
#define ORDER_LIST_RESPONSE__H_INCLUDED_

#ifdef ORDER_LIST_RESPONSE__SDK_LIBRARY_EXPORT // inside DLL
#   define ORDER_LIST_RESPONSE   __declspec(dllexport)
#else //outside DLL
#   define ORDER_LIST_RESPONSE   __declspec(dllimport)
#endif  //ORDER_LIST_RESPONSE__SDK_LIBRARY_EXPORT

typedef std::list<COrderDetails> OrderDetailsList;

class ORDER_LIST_RESPONSE COrderListResponse
{
public:
	COrderListResponse(void);
	virtual ~COrderListResponse(void);
	void Serialize(CString &strString);

    long GetCount() ;
    void SetCount(long Count) ;

	CString GetMarker();
	void SetMarker(CString Marker);

    OrderDetailsList GetOrderDetails();
    void SetOrderDetails(OrderDetailsList OrderDetails) ;

private:
	long					m_Count;
    CString					m_Marker;
    OrderDetailsList	m_OrderDetails;
};
#endif //ORDER_LIST_RESPONSE__H_INCLUDED_
