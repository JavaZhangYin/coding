#pragma once
#include "BasicOrderResponse.h"

#ifndef _CHANGE_EQUITY_ORDER_RESPONSE__H_INCLUDED_
#define _CHANGE_EQUITY_ORDER_RESPONSE__H_INCLUDED_

#ifdef CHANGE_EQUITY_ORDER_RESPONSE_SDK_LIBRARY_EXPORT // inside DLL
#   define CHANGE_EQUITY_ORDER_RESPONSE   __declspec(dllexport)
#else //outside DLL
#   define CHANGE_EQUITY_ORDER_RESPONSE   __declspec(dllimport)
#endif  //CHANGE_EQUITY_ORDER_RESPONSE_SDK_LIBRARY_EXPORT

class CHANGE_EQUITY_ORDER_RESPONSE CChangeEquityOrderResponse : public CBasicOrderResponse
{
public:
	CChangeEquityOrderResponse(void);
	virtual ~CChangeEquityOrderResponse(void);

	void Serialize(CString &strStrin);

    CString GetSymbolDesc();
    void SetSymbolDesc(CString SymbolDesc);

	CString GetSymbol();
	void SetSymbol(CString Symbol);

	EEquityOrderAction GetOrderAction();
	void SetOrderAction(EEquityOrderAction OrderAction);
	void SetOrderAction(CString str);

	EEquityPriceType GetPriceType();
	void SetPriceType(EEquityPriceType PriceType);
	void SetPriceType(CString str);

private:
	CString						m_SymbolDesc;
    CString						m_Symbol;
    EEquityOrderAction	m_OrderAction;
    EEquityPriceType		m_PriceType;
};

#endif//_CHANGE_EQUITY_ORDER_RESPONSE__H_INCLUDED_