#pragma once

#include "CallOptionChain.h"
#include "PutOptionChain.h"

#ifndef OPTION_CHAIN_PAIR__H_INCLUDED_
#define OPTION_CHAIN_PAIR__H_INCLUDED_

#ifdef OPTION_CHAIN_PAIR__SDK_LIBRARY_EXPORT // inside DLL
#   define OPTION_CHAIN_PAIR   __declspec(dllexport)
#else //outside DLL
#   define OPTION_CHAIN_PAIR   __declspec(dllimport)
#endif  //OPTION_CHAIN_PAIR__SDK_LIBRARY_EXPORT 

typedef std::list<CCallOptionChain> CallOptionChainList;
typedef std::list<CPutOptionChain> PutOptionChainList;

class OPTION_CHAIN_PAIR COptionChainPair
{
public:
	COptionChainPair(void);
	virtual ~COptionChainPair(void);

	EPairType GetPairType();
	void SetPairType(EPairType pairType) ;
	void SetPairType(CString pairType) ;

	int GetCallCount();
	void SetCallCount(int callCount);

	int GetPutCount() ;
	void SetPutCount(int putCount);
	
	CallOptionChainList GetCall();
	void SetCall(CallOptionChainList call);

	PutOptionChainList GetPut();
	void SetPut(PutOptionChainList put);

	void Serialize(CString &strString);
private:
	EPairType m_PairType;
	int m_CallCount;
	int m_PutCount;
	CallOptionChainList m_Call;
	PutOptionChainList m_Put;
};
#endif //OPTION_CHAIN_PAIR__H_INCLUDED_

