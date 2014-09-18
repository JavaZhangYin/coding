#pragma once
//#include "EnumDef.h"
#include "LegDetails.h"

#ifndef ORDER__H_INCLUDED_
#define ORDER__H_INCLUDED_

#ifdef ORDER__SDK_LIBRARY_EXPORT // inside DLL
#   define ORDER   __declspec(dllexport)
#else //outside DLL
#   define ORDER   __declspec(dllimport)
#endif  //ORDER__SDK_LIBRARY_EXPORT;

typedef std::list<CLegDetails> CLegDetailsList;

class ORDER COrder
{
public:
	COrder(void);
	virtual ~COrder(void);

	void Serialize(CString &strString);

	long long GetOrderId();
	void SetOrderId(long long OrderId);

	long GetOrderPlacedTime();
	void SetOrderPlacedTime(long OrderPlacedTime);

	long GetOrderExecutedTime();
	void SetOrderExecutedTime(long OrderExecutedTime);

	double GetOrderValue();
	void SetOrderValue(double OrderValue);

	EOrderStatus GetOrderStatus() ;
	void GetOrderStatus(CString &str); 
	void SetOrderStatus(EOrderStatus  OrderStatus) ;
	void SetOrderStatus(CString str) ;

	EViewOrderType GetOrderType() ;
	void GetOrderType(CString  &str) ;
	void SetOrderType(EViewOrderType OrderType) ;
	void SetOrderType(CString  str);

	EOrderTerm GetOrderTerm();
	void GetOrderTerm(CString &str);
	void SetOrderTerm(EOrderTerm OrderTerm);
	void SetOrderTerm(CString str);

	EOrderPriceType GetPriceType();
	void GetPriceType(CString &str);
	void SetPriceType(EOrderPriceType PriceType);
	void SetPriceType(CString str);

	double GetLimitPrice() ;
	void SetLimitPrice(double LimitPrice);

	double GetStopPrice() ;
	void SetStopPrice(double StopPrice);

	EOrderRoutingDestination GetRoutingDestination() ;
	void GetRoutingDestination(CString &str) ;
	void SetRoutingDestination(EOrderRoutingDestination OrderRoutingDestination) ;
	void SetRoutingDestination(CString str);

	CLegDetailsList GetLegDetails();
	void SetLegDetails(CLegDetailsList LegDetailsList );

	double GetBracketLimitPrice() ;
	void SetBracketLimitPrice(double BracketLimitPrice) ;

	double GetInitialStopPrice();
	void SetInitialStopPrice(double InitialStopPrice);

	double GetTrailPrice();
	void SetTrailPrice(double TrailPrice);

	double GetTriggerPrice();
	void SetTriggerPrice(double TriggerPrice);

	double GetConditionPrice() ;
//	void GetConditionPrice(CString str); 
	void SetConditionPrice(double ConditionPrice) ;
//	void SetConditionPrice(CString str) ;

	CString GetConditionSymbol();
	void SetConditionSymbol(CString ConditionSymbol);

	EConditionType GetConditionType() ;
	void GetConditionType(CString &str);
	void SetConditionType(EConditionType ConditionType) ;
	void SetConditionType(CString str); 

	EConditionFollowPrice GetConditionFollowPrice() ;
	void GetConditionFollowPrice(CString &str); 
	void SetConditionFollowPrice(EConditionFollowPrice ConditionFollowPrice) ;
	void SetConditionFollowPrice(CString str) ;

	long long GetReplacedByOrderId() ;
	void SetReplacedByOrderId(long long ReplacedByOrderId) ;

	long long GetReplacesOrderId() ;
	void SetReplacesOrderId(long long ReplacesOrderId) ;

	bool isAllOrNone();
	void SetAllOrNone(bool AllOrNone);
private:
    long long							m_OrderId;
    long								m_OrderPlacedTime;
    long								m_OrderExecutedTime;
    double								m_OrderValue;
    EOrderStatus					m_OrderStatus;
    EViewOrderType				m_OrderType;
    EOrderTerm					m_OrderTerm;
    EOrderPriceType				m_PriceType;
    double								m_LimitPrice;
    double								m_StopPrice;
    EOrderRoutingDestination		m_RoutingDestination;
    CLegDetailsList				m_LegDetails;
    double								m_BracketLimitPrice;
    double								m_InitialStopPrice;
    double								m_TrailPrice;
    double								m_TriggerPrice;
    double								m_ConditionPrice;
    CString								m_ConditionSymbol;
    EConditionType				m_ConditionType;
    EConditionFollowPrice		    m_ConditionFollowPrice;
    long long							m_ReplacedByOrderId;
    long long							m_ReplacesOrderId;
    bool								m_AllOrNone;
};										
#endif//ORDER__H_INCLUDED_
