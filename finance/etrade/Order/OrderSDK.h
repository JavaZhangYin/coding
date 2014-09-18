#pragma once

#ifndef _ORDERSDK_H_INCLUDED_
#define _ORDERSDK_H_INCLUDED_

#include "..\..\common\Common\CommonDefs.h"
#include "..\..\common\Common\ClientDetails.h"
#include "..\..\common\Common\OAuthHelper.h"
#include "OrderListRequest.h"
#include "OrderListResponse.h"
#include "BasicOrderRequest.h"
#include "BasicOrderResponse.h"
#include "EquityOrderRequest.h"
#include "EquityOrderResponse.h"
#include "ChangeEquityOrderRequest.h"
#include "ChangeEquityOrderResponse.h"
#include "ChangeOptionOrderRequest.h"
#include "ChangeOptionOrderResponse.h"
#include "ChangeOrderBase.h"
#include "OptionOrderRequest.h"
#include "OptionOrderResponse.h"
#include "ChangeOptionOrderRequest.h"
#include "ChangeOptionOrderResponse.h"
#include "CancelOrderRequest.h"
#include "CancelOrderResponse.h"


#include "Error.h" 

#ifdef ORDER_SDK_LIBRARY_EXPORT // inside DLL
#   define ORDER_SDK   __declspec(dllexport)
#else //outside DLL
#   define ORDER_SDK   __declspec(dllimport)
#endif  //ORDER_SDK_LIBRARY_EXPORT
class ORDER_SDK COrderSDK
{
public:
	COrderSDK(CClientDetails objClientDetails);
	virtual ~COrderSDK();
	  
	COrderListResponse GetOrderList(COrderListRequest MyOrderListRequestObj);
	
	CEquityOrderResponse GetPreviewEquityOrder(CEquityOrderRequest MyEquityOrderRequestObj) throw (...);
	CEquityOrderResponse GetPlaceEquityorder  (CEquityOrderRequest MYEquityOrderRequestObj)  throw (...);
	CChangeEquityOrderResponse GetPreviewChangeEquityOrder(CChangeEquityOrderRequest MyChangeEquityOrderRequestObj) throw (...);
	CChangeEquityOrderResponse GetPlaceChangeEquityOrder  (CChangeEquityOrderRequest MyChangeEquityOrderRequestObj) throw (...);

	COptionOrderResponse GetPreviewOptionOrder(COptionOrderRequest MyOptionOrderRequestObj) throw (...);
	COptionOrderResponse GetPlaceOptionOrder(COptionOrderRequest MyOptionOrderRequestObj) throw (...);
	CChangeOptionOrderResponse GetPreviewChangeOptionOrder(CChangeOptionOrderRequest MyChangeOptionOrderRequestObj) throw (...);
	CChangeOptionOrderResponse GetPlaceChangeOptionOrder(CChangeOptionOrderRequest MyChangeOptionOrderRequestObj) throw (...);

	CCancelOrderResponse GetCancelOrder(CCancelOrderRequest MyCancelOrderRequestObj) throw (...);

	void CheckClientRequestObject()throw (...);
	void SetClientDetails(CClientDetails objClientDetails);
private:
	CString ConstructFullURL(CString Resource,CString AbstractId="") ;
	CClientDetails m_objClientDetails;
	COAuthHelper m_ObjOAuthHelper;
	static CString m_PrdHost ;
	static CString m_SandboxHost;
	static CString m_SandboxURL;
	static CString m_LiveURL;
};
#endif//_ORDERSDK_H_INCLUDED_
