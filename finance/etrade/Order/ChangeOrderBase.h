#pragma once

#ifndef _CHANGE_ORDER_BASE__H_INCLUDED_
#define _CHANGE_ORDER_BASE__H_INCLUDED_

#ifdef CHANGE_ORDER_BASE__SDK_LIBRARY_EXPORT // inside DLL
#   define CHANGE_ORDER_BASE   __declspec(dllexport)
#else //outside DLL
#   define CHANGE_ORDER_BASE   __declspec(dllimport)
#endif  //CHANGE_ORDER_BASE__SDK_LIBRARY_EXPORT

class CHANGE_ORDER_BASE CChangeOrderBase
{
public:
	CChangeOrderBase(void);
	virtual ~CChangeOrderBase(void);

	void Serialize(CString &strString);

	CString GetAccountId();
	void SetAccountId(CString AccountId) ;

	long long GetOrderNum();
	void SetOrderNum(long long OrderNum) ;

	CString GetClientOrderId();
	void SetClientOrderId(CString ClientOrderId) ;

	double GetLimitPrice();
	void SetLimitPrice(double LimitPrice) ;

	long long GetPreviewId();
	void SetPreviewId(long long PreviewId) ;

	double GetStopPrice();
	void SetStopPrice(double StopPrice) ;

	CString GetAllOrNone();
	void SetAllOrNone(CString Quantity) ;

	CString GetQuantity();
	void SetQuantity(CString Quantity) ;

	CString GetReserveOrder();
	void SetReserveOrder(CString ReserveOrder) ;

	long long GetReserveQuantity();
	void SetReserveQuantity(long long ReserveQuantity) ;

private:
	CString			m_AccountId;
	long long		m_OrderNum;
	CString			m_ClientOrderId;
	double			m_LimitPrice;
	long long		m_PreviewId;
	double			m_StopPrice;
	CString			m_AllOrNone;
	CString			m_Quantity;
	CString			m_ReserveOrder;
	long long		m_ReserveQuantity;
};

#endif//_CHANGE_ORDER_BASE__H_INCLUDED_