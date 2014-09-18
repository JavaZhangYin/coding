#pragma once
#include "ChangeOrderBase.h"

#ifndef _CHANGE_EQUITY_ORDER_REQUEST__H_INCLUDED_
#define _CHANGE_EQUITY_ORDER_REQUEST__H_INCLUDED_

#ifdef CHANGE_EQUITY_ORDER_REQUEST_SDK_LIBRARY_EXPORT // inside DLL
#   define CHANGE_EQUITY_ORDER_REQUEST   __declspec(dllexport)
#else //outside DLL
#   define CHANGE_EQUITY_ORDER_REQUEST   __declspec(dllimport)
#endif  //CHANGE_EQUITY_ORDER_REQUEST_SDK_LIBRARY_EXPORT

class CHANGE_EQUITY_ORDER_REQUEST CChangeEquityOrderRequest : public CChangeOrderBase
{
public:
	CChangeEquityOrderRequest(void);
	virtual ~CChangeEquityOrderRequest(void);

	void Serialize(CString &strString);

	CString GetPriceType();
    void SetPriceType(CString PriceType);

    CString GetOrderTerm();
    void SetOrderTerm(CString OrderTerm) ;
private:
	CString	m_PriceType;
    CString m_OrderTerm;
};
#endif//_CHANGE_EQUITY_ORDER_REQUEST__H_INCLUDED_

