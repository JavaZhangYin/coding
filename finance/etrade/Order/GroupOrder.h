#pragma once
#include "Order.h"
//#include "OrderEnumDef.h"

#ifndef GROUP_ORDER__H_INCLUDED_
#define GROUP_ORDER__H_INCLUDED_

#ifdef GROUP_ORDER__SDK_LIBRARY_EXPORT // inside DLL
#   define GROUP_ORDER   __declspec(dllexport)
#else //outside DLL
#   define GROUP_ORDER   __declspec(dllimport)
#endif  //GROUP_ORDER__SDK_LIBRARY_EXPORT

typedef std::list<COrder> COrderList;


class GROUP_ORDER CGroupOrder
{
public:
	CGroupOrder(void);
	virtual ~CGroupOrder(void);

	void Serialize(CString &strString);

    long long GetGroupOrderId();
    void SetGroupOrderId(long long GroupOrderId);

	EViewOrderType GetGroupOrderType() ;
	void GetGroupOrderType(CString &str) ;
	void SetGroupOrderType(EViewOrderType GroupOrderType) ;
	void SetGroupOrderType(CString  str) ;

    long long GetTotalOrderValue();
    void SetTotalOrderValue(long long TotalOrderValue);

    double GetCumulativeEstimatedCommission();
    void SetCumulativeEstimatedCommission(double CumulativeEstimatedCommission );

    double GetCumulativeEstimatedFees();
    void SetCumulativeEstimatedFees(double CumulativeEstimatedFees);


	COrderList GetOrder() ;
    void SetOrder(COrderList Order ) ;
private:
	long long				m_GroupOrderId;
    EViewOrderType	m_GroupOrderType;
    long long				m_TotalOrderValue;
    double					m_CumulativeEstimatedCommission;
    double					m_CumulativeEstimatedFees;
    COrderList		m_Order;
};
#endif//GROUP_ORDER__H_INCLUDED_
