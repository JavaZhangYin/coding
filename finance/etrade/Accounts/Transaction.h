#pragma once

#ifndef _TRANSACTION_H_INCLUDED_
#define _TRANSACTION_H_INCLUDED_

#ifdef TRANSACTION_LIBRARY_EXPORT // inside DLL
#   define TRANSACTION   __declspec(dllexport)
#else //outside DLL
#   define TRANSACTION   __declspec(dllimport)
#endif  //TRANSACTION_LIBRARY_EXPORT 

class TRANSACTION CTransaction
{
public:
	CTransaction(void);
	virtual ~CTransaction(void);
	void Serialize(CString &strString);

	long GetTransactionDate();
	void SetTransactionDate(long TransactionDate) ;

	CString GetTransactionShortDes();
	void SetTransactionShortDes(CString TransactionShortDesc) ;

	CString GetDescription();
	void SetDescription(CString Description) ;

	float GetAmount();
	void SetAmount(float Amount) ;
	
	CString GetDetail();
	void SetDetail(CString Details) ;
private:
   long				m_TransactionDate;
   CString			m_TransactionShortDesc;
   CString			m_Description;
   float			m_Amount;
   CString			m_Details;
};


#endif //_TRANSACTION_H_INCLUDED_