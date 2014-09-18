#pragma once

#ifndef _CANCEL_ORDER_REQUEST__H_INCLUDED_
#define _CANCEL_ORDER_REQUEST__H_INCLUDED_

#ifdef CANCEL_ORDER_REQUEST_SDK_LIBRARY_EXPORT // inside DLL
#   define CANCEL_ORDER_REQUEST   __declspec(dllexport)
#else //outside DLL
#   define CANCEL_ORDER_REQUEST   __declspec(dllimport)
#endif  //CANCEL_ORDER_REQUEST_SDK_LIBRARY_EXPORT


class CANCEL_ORDER_REQUEST CCancelOrderRequest
{
public:
	CCancelOrderRequest(void);
	virtual ~CCancelOrderRequest(void);

	void Serialize(CString &strString);

    CString GetAccountId();
    void SetAccountId(CString AccountId);

    long long GetOrderNum();
    void SetOrderNum(long long OrderNum);
private:
	CString		m_AccountId;
    long long	m_OrderNum;
};

#endif//_CANCEL_ORDER_REQUEST__H_INCLUDED_