#pragma once

#include "ProductId.h"

#ifndef _ACCOUNTPOSITION_H_INCLUDED_
#define _ACCOUNTPOSITION_H_INCLUDED_

#ifdef ACCOUNTPOSITION_LIBRARY_EXPORT // inside DLL
#   define ACCOUNTPOSITION   __declspec(dllexport)
#else //outside DLL
#   define ACCOUNTPOSITION   __declspec(dllimport)
#endif  //ACCOUNTPOSITION_LIBRARY_EXPORT 

class ACCOUNTPOSITION CAccountPosition
{
public:
	CAccountPosition(void);
	~CAccountPosition(void);

	double GetCostBasis();
	void SetCostBasis(double CostBasis);

	CString GetDescription() ;
	void SetDescription(CString Description) ;

	ELongOrShort GetLongOrShort() ;
	void SetLongOrShort(ELongOrShort longOrShort) ;
	void SetLongOrShort(CString str);

	bool GetMarginable() ;
	void SetMarginable(bool bMarginable) ;

	CProductId GetProductId() ;
	void SetProductId(CProductId ProductId) ;

	double GetQty() ;
	void SetQty(double Qty) ;

	double GetMarketValue() ;
	void SetMarketValue(double MarketValue) ;
	void Serialize(CString &strString);
private:
    double m_CostBasis;
    CString m_Description;
    ELongOrShort m_LongOrShort;
    bool m_Marginable;
    CProductId m_ProductId;
    double m_Qty;
	double m_marketValue;
};
#endif //#define _ACCOUNTPOSITION_H_INCLUDED_