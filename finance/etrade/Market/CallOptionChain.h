#pragma once
#include "ExpirationDate.h"
#include "MarketProductId.h"

#ifndef CALL_OPTION_CHAIN_H_INCLUDED_
#define CALL_OPTION_CHAIN_H_INCLUDED_

#ifdef CALL_OPTION_CHAIN__SDK_LIBRARY_EXPORT // inside DLL
#   define CALL_OPTION_CHAIN_   __declspec(dllexport)
#else //outside DLL
#   define CALL_OPTION_CHAIN_   __declspec(dllimport)
#endif  //CALL_OPTION_CHAIN__SDK_LIBRARY_EXPORT 



class CALL_OPTION_CHAIN_ CCallOptionChain
{
public:
	CCallOptionChain(void);
	virtual ~CCallOptionChain(void);

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
#endif//CALL_OPTION_CHAIN_H_INCLUDED_
