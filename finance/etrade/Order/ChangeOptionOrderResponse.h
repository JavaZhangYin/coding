#pragma once
//#include "OrderEnumDef.h"
#include "BasicOrderResponse.h"
#include "OptionSymbol.h"
#include "BasicOrderResponse.h"
#ifndef _CHANGE_OPTION_ORDER_RESPONSE__H_INCLUDED_
#define _CHANGE_OPTION_ORDER_RESPONSE__H_INCLUDED_

#ifdef CHANGE_OPTION_ORDER_RESPONSE__SDK_LIBRARY_EXPORT // inside DLL
#   define CHANGE_OPTION_ORDER_RESPONSE   __declspec(dllexport)
#else //outside DLL
#   define CHANGE_OPTION_ORDER_RESPONSE   __declspec(dllimport)
#endif  //CHANGE_OPTION_ORDER_RESPONSE__SDK_LIBRARY_EXPORT


class CHANGE_OPTION_ORDER_RESPONSE CChangeOptionOrderResponse :public CBasicOrderResponse
{
public:
	CChangeOptionOrderResponse(void);
	virtual ~CChangeOptionOrderResponse(void);

	void Serialize(CString &strString);

    double GetStopLimitPrice();
    void SetStopLimitPrice(double StopLimitPrice);

	COptionSymbol GetOptionSymbol();
	void SetOptionSymbol(COptionSymbol OptionSymbol);

//	OptionOrderAction GetOrderAction();
//	void SetOrderAction(OptionOrderAction OrderAction);
	CString GetOrderAction();
	void SetOrderAction(CString str);

//	OptionPriceType GetPriceType();
//   void SetPriceType(OptionPriceType PriceType);
    CString GetPriceType();
    void SetPriceType(CString str);
private:
	double						m_StopLimitPrice;
    COptionSymbol		m_OptionSymbol;
//    OptionOrderAction	m_OrderAction;
//    OptionPriceType		m_PriceType;
    CString						m_OrderAction;
    CString						m_PriceType;
};

#endif//_CHANGE_OPTION_ORDER_RESPONSE__H_INCLUDED_