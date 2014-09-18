#pragma once

#include "OptionSymbol.h"
#include "BasicOrderResponse.h"

#ifndef OPTION_ORDER_RESPONSE__H_INCLUDED_
#define OPTION_ORDER_RESPONSE__H_INCLUDED_

#ifdef OPTION_ORDER_RESPONSE__SDK_LIBRARY_EXPORT // inside DLL
#   define OPTION_ORDER_RESPONSE   __declspec(dllexport)
#else //outside DLL
#   define OPTION_ORDER_RESPONSE   __declspec(dllimport)
#endif  //OPTION_ORDER_RESPONSE__SDK_LIBRARY_EXPORT


class OPTION_ORDER_RESPONSE COptionOrderResponse : public CBasicOrderResponse
{
public:
	COptionOrderResponse(void);
	virtual ~COptionOrderResponse(void);

	void Serialize(CString &strString);

	double GetStopLimitPrice() ;
	void SetStopLimitPrice(double StopLimitPrice) ;

	COptionSymbol GetOptionSymbol();
	void SetOptionSymbol(COptionSymbol OptionSymbol);

	EOptionOrderAction GetOrderAction();
	void SetOrderAction(EOptionOrderAction OrderAction);
	void SetOrderAction(CString str);

	EOptionPriceType GetPriceType() ;
	void SetPriceType(EOptionPriceType PriceType) ;
	void SetPriceType(CString str) ;

private:
	double						m_StopLimitPrice;
	COptionSymbol		m_OptionSymbol;
	EOptionOrderAction	m_OrderAction;
	EOptionPriceType		m_PriceType;
};

#endif//OPTION_ORDER_RESPONSE__H_INCLUDED_