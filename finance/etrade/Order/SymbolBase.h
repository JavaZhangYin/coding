#pragma once

#ifndef SYMBOL_BASE__H_INCLUDED_
#define SYMBOL_BASE__H_INCLUDED_

#ifdef SYMBOL_BASE__SDK_LIBRARY_EXPORT // inside DLL
#   define SYMBOL_BASE   __declspec(dllexport)
#else //outside DLL
#   define SYMBOL_BASE   __declspec(dllimport)
#endif  //SYMBOL_BASE__SDK_LIBRARY_EXPORT;

class SYMBOL_BASE CSymbolBase
{
public:
	CSymbolBase(void);
	virtual ~CSymbolBase(void);
	void Serialize(CString &strString);


	CString GetSymbol();
	void SetSymbol(CString Symbol);

	EOrderType GetType();
	void SetType(EOrderType Type);

private:
	CString				m_Symbol;
	EOrderType	m_Type;
};
#endif //SYMBOL_BASE__H_INCLUDED_
