#pragma once

#include "OptionChainPair.h"

#ifndef OPTION_CHAIN_RESPONSE__H_INCLUDED_
#define OPTION_CHAIN_RESPONSE__H_INCLUDED_

#ifdef OPTION_CHAIN_RESPONSE__SDK_LIBRARY_EXPORT // inside DLL
#   define OPTION_CHAIN_RESPONSE   __declspec(dllexport)
#else //outside DLL
#   define OPTION_CHAIN_RESPONSE   __declspec(dllimport)
#endif  //OPTION_CHAIN_RESPONSE__SDK_LIBRARY_EXPORT 

typedef std::list<COptionChainPair> OptionChainPairList;
class OPTION_CHAIN_RESPONSE COptionChainResponse
{
public:
	COptionChainResponse(void);
	virtual ~COptionChainResponse(void);

	CString GetSymbol();
	void SetSymbol(CString symbol);

	OptionChainPairList GetOptionPairs();
	void SetOptionPairs(OptionChainPairList optionPairs);

	int GetOptionPairCount();
	void SetOptionPairCount(int optionPairCount) ;
	void Serialize(CString &strString);
private :
	OptionChainPairList m_OptionChainPairListObj;
	int m_OptionPairCount;
	CString m_Symbol;
};

#endif //OPTION_CHAIN_RESPONSE__H_INCLUDED_