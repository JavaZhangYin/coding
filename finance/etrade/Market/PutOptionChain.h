#pragma once

#include "ExpirationDate.h"
#include "MarketProductId.h"

#ifndef PUT_OPTION_CHAIN__H_INCLUDED_
#define PUT_OPTION_CHAIN__H_INCLUDED_

#ifdef PUT_OPTION_CHAIN__SDK_LIBRARY_EXPORT // inside DLL
#   define PUT_OPTION_CHAIN   __declspec(dllexport)
#else //outside DLL
#   define PUT_OPTION_CHAIN   __declspec(dllimport)
#endif  //PUT_OPTION_CHAIN__SDK_LIBRARY_EXPORT 

class PUT_OPTION_CHAIN CPutOptionChain
{
public:
	CPutOptionChain(void);
	virtual ~CPutOptionChain(void);

	CString GetRootSymbol();
	void SetRootSymbol(CString RootSymbol);

    CExpirationDate GetExpireDate();
    void SetExpireDate(CExpirationDate ExpireDate);

    CMarketProductId GetProduct();
    void SetProduct(CMarketProductId Product);

    double GetStrikePrice();
    void SetStrikePrice(double StrikePrice);

	void Serialize(CString &strString);
private:
	CString					m_RootSymbol;
    CExpirationDate	m_ExpireDate;
    CMarketProductId	m_Product;
    double					m_StrikePrice;
};

#endif//PUT_OPTION_CHAIN__H_INCLUDED_