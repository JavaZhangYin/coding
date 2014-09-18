#pragma once

#include "Transaction.h"
#include <list>

#ifndef _TRANSACTIONS_H_INCLUDED_
#define _TRANSACTIONS_H_INCLUDED_

#ifdef TRANSACTIONS_LIBRARY_EXPORT // inside DLL
#   define TRANSACTIONS   __declspec(dllexport)
#else //outside DLL
#   define TRANSACTIONS   __declspec(dllimport)
#endif  //TRANSACTIONS_LIBRARY_EXPORT 

typedef std::list<CTransaction> TransactionList;

class TRANSACTIONS CTransactions
{
public:
	CTransactions(void);
	virtual ~CTransactions(void);
	void Serialize(CString &strString);

	CString GetAccountId();
	void SetAccountId(CString AccountId) ;

	int GetCount();
	void SetCount(int Count) ;

	CString GetNext();
	void SetNext(CString Next) ;

	TransactionList GetTransactionList();
	void SetTransactionList(TransactionList TransactionListObj) ;

private:
	CString					m_AccountId;
	int						m_Count;
	CString					m_Next;
	TransactionList			m_TransactionList;
};

#endif //_TRANSACTIONS_H_INCLUDED_