#pragma once


#ifndef QUOTE_REQEUST__H_INCLUDED_
#define QUOTE_REQEUST__H_INCLUDED_

#ifdef QUOTE_REQEUST__SDK_LIBRARY_EXPORT // inside DLL
#   define QUOTE_REQEUST   __declspec(dllexport)
#else //outside DLL
#   define QUOTE_REQEUST   __declspec(dllimport)
#endif  //QUOTE_REQEUST__SDK_LIBRARY_EXPORT 

typedef std::list<CString> StringList;

class QUOTE_REQEUST CQuoteReqeust
{
public:
	CQuoteReqeust(void);
	virtual ~CQuoteReqeust(void);

	StringList GetSymbolList();
	void SetSymbolList(StringList SymbolList);

	CString GetDetailFlag();
	void SetDetailFlag(CString DetailFlag);
private:
	StringList m_SymbolList;
	CString m_DetailFlag ;
};

#endif//QUOTE_REQEUST__H_INCLUDED_