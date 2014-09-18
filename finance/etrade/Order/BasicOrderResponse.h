#pragma once
#include "ResultBase.h"
#include "ETAppMessages.h"


#ifndef _BASIC_ORDER_RESPONSE__H_INCLUDED_
#define _BASIC_ORDER_RESPONSE__H_INCLUDED_

#ifdef BASIC_ORDER_RESPONSE_SDK_LIBRARY_EXPORT // inside DLL
#   define BASIC_ORDER_RESPONSE  __declspec(dllexport)
#else //outside DLL
#   define BASIC_ORDER_RESPONSE   __declspec(dllimport)
#endif  //BASIC_ORDER_RESPONSE_SDK_LIBRARY_EXPORT

typedef std::list<CETAppMessages> ETAppMessagesList;

class BASIC_ORDER_RESPONSE CBasicOrderResponse : public CResultBase
{
public:
	CBasicOrderResponse(void);
	virtual ~CBasicOrderResponse(void);
	
	void Serialize(CString &strString);

    
	bool isAllOrNone();
	void SetAllOrNone(bool AllOrNone);

	double GetEstimatedCommission();
	void SetEstimatedCommission(double EstimatedCommission);

	double GetEstimatedTotalAmount();
	void SetEstimatedTotalAmount(double EstimatedTotalAmount);

	ETAppMessagesList GetMessageList();
	void SetMessageList(ETAppMessagesList);

	long long GetOrderNum();
	void SetOrderNum(long long );

	long GetOrderTime();
	void SetOrderTime(long);

	long GetPreviewTime();
	void SetPreviewTime(long );

	long long GetPreviewId();
	void SetPreviewId(long long );

	long long GetQuantity();
	void SetQuantity(long long );

	bool isReserveOrder();
	void SetReserveOrder(bool );

	long long GetReserveQuantity();
	void SetReserveQuantity(long long );

	EOrderTerm GetOrderTerm();
	void SetOrderTerm(EOrderTerm );
	void SetOrderTerm(CString str);

	double GetLimitPrice() ;
	void SetLimitPrice(double) ;

	double GetStopPrice();
	void SetStopPrice(double );

	EOrderRoutingDestination GetRoutingDestination();
	void SetRoutingDestination(EOrderRoutingDestination );
	void SetRoutingDestination(CString str);

private:
	bool							m_AllOrNone;
	double							m_EstimatedCommission;
	double							m_EstimatedTotalAmount;
	ETAppMessagesList				m_MessageList;
	long long						m_OrderNum;
	long							m_OrderTime;
	long							m_PreviewTime;
	long long						m_PreviewId;
	long long						m_Quantity;
	bool							m_ReserveOrder;
	long long						m_ReserveQuantity;
	EOrderTerm						m_OrderTerm;
	double							m_LimitPrice;
	double							m_StopPrice;
	EOrderRoutingDestination		m_RoutingDestination;
};
#endif//_BASIC_ORDER_RESPONSE__H_INCLUDED_
