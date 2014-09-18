#pragma once
#include "OptionSymbol.h"
#include "BasicOrderRequest.h"

#ifndef OPTION_ORDER_REQUEST__H_INCLUDED_
#define OPTION_ORDER_REQUEST__H_INCLUDED_

#ifdef OPTION_ORDER_REQUEST__SDK_LIBRARY_EXPORT // inside DLL
#   define OPTION_ORDER_REQUEST   __declspec(dllexport)
#else //outside DLL
#   define OPTION_ORDER_REQUEST   __declspec(dllimport)
#endif  //OPTION_ORDER_REQUEST__SDK_LIBRARY_EXPORT


class OPTION_ORDER_REQUEST COptionOrderRequest : public CBasicOrderRequest
{
public:
	COptionOrderRequest(void);
	virtual ~COptionOrderRequest(void);

	void Serialize(CString &strString);

	double GetStopLimitPrice();
	void SetStopLimitPrice(double StopLimitPrice);

	COptionSymbol GetSymbolInfo();
	void SetSymbolInfo(COptionSymbol SymbolInfo) ;

//	OptionOrderAction GetOrderAction();
	CString GetOrderAction();
//	void SetOrderAction(OptionOrderAction OrderAction) ;
	void SetOrderAction(CString str) ;

//	OptionPriceType GetPriceType();
	CString GetPriceType();
//	void SetPriceType(OptionPriceType PriceType);
	void SetPriceType(CString str);

	CString GetRoutingDestination() ;
	void SetRoutingDestination(CString RoutingDestination);

//	OptionOrderTerm GetOrderTerm();
	CString GetOrderTerm();
//	void SetOrderTerm(OptionOrderTerm OrderTerm);
	void SetOrderTerm(CString str);

private:
	double							m_StopLimitPrice;
	COptionSymbol			m_SymbolInfo;
//	OptionOrderAction		m_OrderAction;
	CString							m_OrderAction;
//	OptionPriceType			m_PriceType;
	CString							m_PriceType;
	CString							m_RoutingDestination;
//	OptionOrderTerm			m_OrderTerm;
	CString							m_OrderTerm;
};

#endif//OPTION_ORDER_REQUEST__H_INCLUDED_