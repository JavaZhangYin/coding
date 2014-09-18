#pragma once
//#include "EnumDef.h"
#ifndef _PRODUCT__H_INCLUDED_
#define _PRODUCT__H_INCLUDED_

#ifdef PRODUCT__SDK_LIBRARY_EXPORT // inside DLL
#   define PRODUCT_   __declspec(dllexport)
#else //outside DLL
#   define PRODUCT_   __declspec(dllimport)
#endif  //PRODUCT__SDK_LIBRARY_EXPORT

class PRODUCT_ CProduct
{
public:
	CProduct(void);
	virtual ~CProduct(void);
	
	CString GetSymbol() ;
	void SetSymbol(CString symbol);

	ESecurityType GetSecurityType() ;
	void SetSecurityType(ESecurityType securityType);
	void SetSecurityType(CString str);

	CString GetExchange();
	void SetExchange(CString exchange); 

	CString GetCompanyName();
	void SetCompanyName(CString companyName);

	void Serialize(CString &strString);
private:
	CString m_Symbol;
	ESecurityType m_SecurityType;
	CString m_Exchange;
	CString m_CompanyName;
};

#endif //_PRODUCT__H_INCLUDED_