#pragma once

#include "ProductId.h"

#ifndef _TRANSACTIONDETAILS_H_INCLUDED_
#define _TRANSACTIONDETAILS_H_INCLUDED_

#ifdef TRANSACTIONDETAILS_LIBRARY_EXPORT // inside DLL
#   define TRANSACTIONDETAILS  __declspec(dllexport)
#else //outside DLL
#   define TRANSACTIONDETAILS   __declspec(dllimport)
#endif  //TRANSACTIONDETAILS_LIBRARY_EXPORT 


class TRANSACTIONDETAILS CTransactionDetails
{
public:
	CTransactionDetails(void);
	~CTransactionDetails(void);

	long GetTransactionDate();
	void SetTransactionDate(long TransactionDate);

	CString GetTransactionType();
	void SetTransactionType(CString TransactionType);

	CString GetUserDescription();
	void SetUserDescription(CString UserDescription);

	CString GetTransactionDescription();
	void SetTransactionDescription(CString TransactionDescription);

	double GetQuantity();
	void SetQuantity(double Quantity);

	double GetAmount();
	void SetAmount(double Amount);

	double GetPrice();
	void SetPrice(double Price);

	double GetCommission();
	void SetCommission(double Commission);

	CProductId GetProductId();
	void SetProductId(CProductId ProductId);

	CProductId GetUnderlyingProductId();
	void SetUnderlyingProductId(CProductId UnderlyingProductId);

	CString GetDisplaySymbol();
	void SetDisplaySymbol(CString DisplaySymbol);

	long GetAccountOrderNo();
	void SetAccountOrderNo(long AccountOrderNo);

	CString GetSettlementCurrency();
	void SetSettlementCurrency(CString SettlementCurrency);

	CString GetPaymentCurrency();
	void SetPaymentCurrency(CString PaymentCurrency);

	CString GetCategory();
	void SetCategory(CString Category);

	long GetSettlementDate();
	void SetSettlementDate(long SettlementDate);

	void Serialize(CString &strString);

private:
	long m_TransactionDate;
	CString m_TransactionType;
	CString m_UserDescription;
	CString m_TransactionDescription;
	double m_Quantity;
	double m_Amount;
	double m_Price;
	double m_Commission;
	CProductId m_ProductId;
	CProductId m_UnderlyingProductId;
	CString m_DisplaySymbol;
	long m_AccountOrderNo;
	CString m_SettlementCurrency;
	CString m_PaymentCurrency;
	CString m_Category;
	long m_SettlementDate;
};
#endif //_TRANSACTIONDETAILSWRAPPER_H_INCLUDED_
