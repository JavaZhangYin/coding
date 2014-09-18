#pragma once
#include "SymbolInfo.h"

#ifndef LEG_DETAILS__H_INCLUDED_
#define LEG_DETAILS__H_INCLUDED_

#ifdef LEG_DETAILS__SDK_LIBRARY_EXPORT // inside DLL
#   define LEG_DETAILS   __declspec(dllexport)
#else //outside DLL
#   define LEG_DETAILS   __declspec(dllimport)
#endif  //LEG_DETAILS__SDK_LIBRARY_EXPORT


class LEG_DETAILS CLegDetails
{
public:
	CLegDetails(void);
	virtual ~CLegDetails(void);
	void Serialize(CString &strString);

	long GetLegNumber();
    void SetLegNumber(long LegNumber);

	CSymbolInfo GetSymbolInfo() ;
	void SetSymbolInfo(CSymbolInfo SymbolInfo) ;

	CString GetSymbolDescription();
	void SetSymbolDescription(CString SymbolDescription);

	EOrderAction GetOrderAction();
	void GetOrderAction(CString &str);
	void SetOrderAction(EOrderAction OrderAction);
	void SetOrderAction(CString str);
	
	long long GetOrderedQuantity();
	void SetOrderedQuantity(long long OrderedQuantity);

    long long GetFilledQuantity();
    void SetFilledQuantity(long long FilledQuantity);
	
	double GetExecutedPrice();
    void SetExecutedPrice(double ExecutedPrice);

	double GetEstimatedCommission();
	void SetEstimatedCommission(double EstimatedCommission);

	double GetEstimatedFees();
	void SetEstimatedFees(double EstimatedFees);

	long long GetReserveQuantity();
	void SetReserveQuantity(long long ReserveQuantity);
private:
	long					m_LegNumber;
    CSymbolInfo		m_SymbolInfo;
    CString					m_SymbolDescription;
    EOrderAction		m_OrderAction;
    long long				m_OrderedQuantity;
    long long				m_FilledQuantity;
    double					m_ExecutedPrice;
    double					m_EstimatedCommission;
    double					m_EstimatedFees;
    long long				m_ReserveQuantity;
};					
#endif//LEG_DETAILS__H_INCLUDED_