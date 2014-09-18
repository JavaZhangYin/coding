#pragma once
#include "QuoteData.h"

#ifndef QUOTE_RESPONSE__H_INCLUDED_
#define QUOTE_RESPONSE__H_INCLUDED_

#ifdef QUOTE_RESPONSE__SDK_LIBRARY_EXPORT // inside DLL
#   define QUOTE_RESPONSE   __declspec(dllexport)
#else //outside DLL
#   define QUOTE_RESPONSE   __declspec(dllimport)
#endif  //QUOTE_RESPONSE__SDK_LIBRARY_EXPORT 


typedef std::list<CQuoteData> QuoteDataList;

class QUOTE_RESPONSE CQuoteResponse
{
public:
	CQuoteResponse(void);
	virtual ~CQuoteResponse(void);

	QuoteDataList GetQuoteData();
	void SetQuoteData(QuoteDataList quoteData);

	void Serialize(CString &strString);
private:
	QuoteDataList m_QuoteData;

};
#endif//QUOTE_RESPONSE__H_INCLUDED_