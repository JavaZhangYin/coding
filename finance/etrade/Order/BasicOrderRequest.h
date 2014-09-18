#pragma once
#include "RequestBase.h"

#ifndef _BASIC_ORDER_REQUEST__H_INCLUDED_
#define _BASIC_ORDER_REQUEST__H_INCLUDED_

#ifdef BASIC_ORDER_REQUEST_SDK_LIBRARY_EXPORT // inside DLL
#   define BASIC_ORDER_REQUEST   __declspec(dllexport)
#else //outside DLL
#   define BASIC_ORDER_REQUEST   __declspec(dllimport)
#endif  //BASIC_ORDER_REQUEST_SDK_LIBRARY_EXPORT

class BASIC_ORDER_REQUEST CBasicOrderRequest : public CRequestBase
{
public:
	CBasicOrderRequest(void);
	virtual ~CBasicOrderRequest(void);
	void Serialize(CString &strString);

    CString GetAllOrNone();
    void SetAllOrNone(CString AllOrNone);

    long long GetQuantity();
    void SetQuantity(long long Quantity) ;

    CString GetReserveOrder();
    void SetReserveOrder(CString ReserveOrder);

    long long GetReserveQuantity();
    void SetReserveQuantity(long long ReserveQuantity) ;

private:
	CString			m_AllOrNone;
	long long		m_Quantity;
	CString			m_ReserveOrder;
	long long		m_ReserveQuantity;
};
#endif//_BASIC_ORDER_REQUEST__H_INCLUDED_
