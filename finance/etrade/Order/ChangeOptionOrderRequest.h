#pragma once
#include "ChangeOrderBase.h"

#ifndef _CHANGE_OPTION_ORDER_REQUEST__H_INCLUDED_
#define _CHANGE_OPTION_ORDER_REQUEST__H_INCLUDED_

#ifdef CHANGE_OPTION_ORDER_REQUEST__SDK_LIBRARY_EXPORT // inside DLL
#   define CHANGE_OPTION_ORDER_REQUEST   __declspec(dllexport)
#else //outside DLL
#   define CHANGE_OPTION_ORDER_REQUEST   __declspec(dllimport)
#endif  //CHANGE_OPTION_ORDER_REQUEST__SDK_LIBRARY_EXPORT


class CHANGE_OPTION_ORDER_REQUEST CChangeOptionOrderRequest : public CChangeOrderBase
{
public:
	CChangeOptionOrderRequest(void);
	virtual ~CChangeOptionOrderRequest(void);

	void Serialize(CString &strCString);


	double GetStopLimitPrice() ;
	void SetStopLimitPrice(double StopLimitPrice);

	CString GetPriceType();
	void SetPriceType(CString PriceType) ;

	CString GetOrderTerm();
	void SetOrderTerm(CString OrderTerm) ;

private:
	double	m_StopLimitPrice;
	CString m_PriceType;
	CString m_OrderTerm;
};
#endif//_CHANGE_OPTION_ORDER_REQUEST__H_INCLUDED_
