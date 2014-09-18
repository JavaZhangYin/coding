#pragma once

#ifndef _MARKETSDK_H_INCLUDED_
#define _MARKETSDK_H_INCLUDED_

#include "..\..\common\Common\CommonDefs.h"
#include "..\..\common\Common\ClientDetails.h"
#include "..\..\common\Common\OAuthHelper.h"


#include "Product.h"
#include "OptionExpireDateRequest.h"
#include "OptionExpireDateResponse.h"
#include "ProductLookupRequest.h"
#include "ProductLookupResponse.h"
#include "OptionChainRequest.h"
#include "OptionChainResponse.h"
#include "QuoteReqeust.h"
#include "QuoteResponse.h"

#include "Error.h"

#ifdef MARKET_SDK_LIBRARY_EXPORT // inside DLL
#   define MARKET_SDK   __declspec(dllexport)
#else //outside DLL
#   define MARKET_SDK   __declspec(dllimport)
#endif  //MARKET_SDK_LIBRARY_EXPORT

class MARKET_SDK CMarketSDK
{
public:
	CMarketSDK(CClientDetails objClientDetails);
	virtual ~CMarketSDK(void);

public:
	CQuoteResponse GetQuote(CQuoteReqeust QuoteReqeustObj) throw (...);
	COptionChainResponse GetOptionChains(COptionChainRequest OptionChainRequestObj)throw (...);
	CProductLookupResponse GetProductLookup(CProductLookupRequest ProductLookupRequestObj) throw (...);
	COptionExpireDateResponse GetOptionExpireDate(COptionExpireDateRequest OptionExpireDateRequestObj) throw (...);

	void CheckClientRequestObject()throw (...);
	void SetClientDetails(CClientDetails objClientDetails){m_objClientDetails = objClientDetails;}
private:
	CString ConstructFullURL(CString Resource,CString AbstractId="") ;
	CClientDetails m_objClientDetails;
	COAuthHelper m_ObjOAuthHelper;
	static CString m_PrdHost ;
	static CString m_SandboxHost;
	static CString m_SandboxURL;
	static CString m_LiveURL;
};

#endif//_MARKETSDK_H_INCLUDED_