#pragma once
#include "BasicOrderRequest.h"

#ifndef _EQUITY_ORDER_REQUEST__H_INCLUDED_
#define _EQUITY_ORDER_REQUEST__H_INCLUDED_

#ifdef EQUITY_ORDER_REQUEST__SDK_LIBRARY_EXPORT // inside DLL
#   define EQUITY_ORDER_REQUEST   __declspec(dllexport)
#else //outside DLL
#   define EQUITY_ORDER_REQUEST   __declspec(dllimport)
#endif  //EQUITY_ORDER_REQUEST__SDK_LIBRARY_EXPORT


class EQUITY_ORDER_REQUEST CEquityOrderRequest : public CBasicOrderRequest
{
public:
	CEquityOrderRequest(void);
	virtual ~CEquityOrderRequest(void);

	void Serialize(CString &strString);

	CString GetSymbol(); 
	void SetSymbol(CString symbol);

	CString GetOrderAction();
	void SetOrderAction(CString orderAction);

	CString GetPriceType() ;
	void SetPriceType(CString priceType);

	CString GetRoutingDestination();
	void SetRoutingDestination(CString routingDestination) ;

	CString GetMarketSession();
	void SetMarketSession(CString marketSession) ;

	CString GetOrderTerm();
	void SetOrderTerm(CString orderTerm);

private:
	CString						m_symbol;
//	EquityOrderAction	m_orderAction;
//	EquityPriceType		m_priceType;
//	MarketSession		m_marketSession;
//	EquityOrderTerm		m_orderTerm;
	CString						m_orderAction;
	CString						m_priceType;
	CString						m_routingDestination;
	CString						m_marketSession;
	CString						m_orderTerm;
};

#endif//_EQUITY_ORDER_REQUEST__H_INCLUDED_