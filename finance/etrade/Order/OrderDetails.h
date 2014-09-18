#include "GroupOrder.h"
#include "Order.h"

#pragma once

#ifndef ORDER_DETAILS__H_INCLUDED_
#define ORDER_DETAILS__H_INCLUDED_

#ifdef ORDER_DETAILS__SDK_LIBRARY_EXPORT // inside DLL
#   define ORDER_DETAILS   __declspec(dllexport)
#else //outside DLL
#   define ORDER_DETAILS   __declspec(dllimport)
#endif  //ORDER_DETAILS_

class ORDER_DETAILS COrderDetails
{
public:
	COrderDetails(void);
	virtual ~COrderDetails(void);
	
	void Serialize(CString &strString);

    CGroupOrder GetGroupOrder();
	void SetGroupOrder(CGroupOrder GroupOrder);

    COrder GetOrder();
    void SetOrder(COrder Order);
private :
	CGroupOrder	m_GroupOrder;
    COrder		m_Order;
};
#endif//ORDER_DETAILS__H_INCLUDED_

