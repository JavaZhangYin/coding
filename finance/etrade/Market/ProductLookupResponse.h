#pragma once

#include "Product.h"

#ifndef _PRODUCT_LOOKUP_RESPONSE__H_INCLUDED_
#define _PRODUCT_LOOKUP_RESPONSE__H_INCLUDED_

#ifdef PRODUCT_LOOKUP_RESPONSE__SDK_LIBRARY_EXPORT // inside DLL
#   define PRODUCT_LOOKUP_RESPONSE   __declspec(dllexport)
#else //outside DLL
#   define PRODUCT_LOOKUP_RESPONSE   __declspec(dllimport)
#endif  //PRODUCT_LOOKUP_RESPONSE__SDK_LIBRARY_EXPORT

typedef std::list<CProduct> ProductList;

class PRODUCT_LOOKUP_RESPONSE CProductLookupResponse
{
public:
	CProductLookupResponse(void);
	virtual ~CProductLookupResponse(void);

	ProductList GetProductList();
	void SetProductList(ProductList productList);
	void Serialize(CString &strString);
private:
	ProductList m_ProductList;
};
#endif//_PRODUCT_LOOKUP_RESPONSE__H_INCLUDED_
