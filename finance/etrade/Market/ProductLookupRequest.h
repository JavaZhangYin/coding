#pragma once

#ifndef PRODUCT_LOOKUP_REQUEST__H_INCLUDED_
#define PRODUCT_LOOKUP_REQUEST__H_INCLUDED_

#ifdef PRODUCT_LOOKUP_REQUEST__SDK_LIBRARY_EXPORT // inside DLL
#   define PRODUCT_LOOKUP_REQUEST   __declspec(dllexport)
#else //outside DLL
#   define PRODUCT_LOOKUP_REQUEST   __declspec(dllimport)
#endif  //PRODUCT_LOOKUP_REQUEST__SDK_LIBRARY_EXPORT

class PRODUCT_LOOKUP_REQUEST CProductLookupRequest
{
public:
	CProductLookupRequest(void);
	virtual ~CProductLookupRequest(void);

	CString GetCompany() ;
	void SetCompany(CString company); 

	CString GetType();
	void SetType(CString type);
private:
	CString m_Company;
    CString m_Type;	
};

#endif//PRODUCT_LOOKUP_REQUEST__H_INCLUDED_