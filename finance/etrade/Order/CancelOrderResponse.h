#pragma once
#include "ETAppMessages.h"

#ifndef _CANCEL_ORDER_RESPONSE__H_INCLUDED_ 
#define _CANCEL_ORDER_RESPONSE__H_INCLUDED_

#ifdef CANCEL_ORDER_RESPONSE_SDK_LIBRARY_EXPORT // inside DLL
#   define CANCEL_ORDER_RESPONSE   __declspec(dllexport)
#else //outside DLL
#   define CANCEL_ORDER_RESPONSE   __declspec(dllimport)
#endif  //CANCEL_ORDER_RESPONSE_SDK_LIBRARY_EXPORT

typedef std::list<CETAppMessages> ETAppMessagesList;

class CANCEL_ORDER_RESPONSE CCancelOrderResponse
{
public:
	CCancelOrderResponse(void);
	~CCancelOrderResponse(void);
	
	void Serialize(CString &strString);

	CString GetAccountId();
	void SetAccountId(CString accountId);

	long long GetOrderNum();
	void SetOrderNum(long long  orderNum);

	long long GetCancelTime();
	void SetCancelTime(long long cancelTime);

	ETAppMessagesList GetMessageList();
	void SetMessageList(ETAppMessagesList messageList);

	CString GetResultMessage();
	void SetResultMessage(CString resultMessage);

private:
	CString						m_accountId;
	long long					m_orderNum;
	long long					m_cancelTime;
	ETAppMessagesList	m_messageList;
	CString						m_resultMessage;
};

#endif//_CANCEL_ORDER_RESPONSE__H_INCLUDED_