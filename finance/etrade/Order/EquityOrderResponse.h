#pragma once
#include "BasicOrderResponse.h"

#ifndef _EQUITY_ORDER_RESPONSE__H_INCLUDED_
#define _EQUITY_ORDER_RESPONSE__H_INCLUDED_

#ifdef EQUITY_ORDER_RESPONSE__SDK_LIBRARY_EXPORT // inside DLL
#   define EQUITY_ORDER_RESPONSE   __declspec(dllexport)
#else //outside DLL
#   define EQUITY_ORDER_RESPONSE   __declspec(dllimport)
#endif  //EQUITY_ORDER_RESPONSE__SDK_LIBRARY_EXPORT


class EQUITY_ORDER_RESPONSE CEquityOrderResponse : public CBasicOrderResponse
{
public:
	CEquityOrderResponse(void);
	virtual ~CEquityOrderResponse(void);

	void Serialize(CString &strString);

	CString GetSymbolDesc();
	void SetSymbolDesc(CString symbolDesc);

	CString GetSymbol();
	void SetSymbol(CString symbol);

	EEquityOrderAction GetOrderAction() ;
	void SetOrderAction(EEquityOrderAction orderAction) ;
	void SetOrderAction(CString str ) ;

	EEquityPriceType GetPriceType();
	void SetPriceType(EEquityPriceType priceType);
	void SetPriceType(CString str);

private:
	CString						m_SymbolDesc;
	CString						m_Symbol;
	EEquityOrderAction	m_OrderAction;
	EEquityPriceType		m_PriceType;
};

#endif//_EQUITY_ORDER_RESPONSE__H_INCLUDED_