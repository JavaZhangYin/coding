#pragma once

#ifndef _OAUTHSDK_H_INCLUDED_
#define _OAUTHSDK_H_INCLUDED_

#include "..\..\common\Common\CommonDefs.h"
#include "..\..\common\Common\OAuthHelper.h"
using namespace std;

#ifdef OAUTH_LIBRARY_EXPORT // inside DLL
#   define OAUTH_API   __declspec(dllexport)
#else //outside DLL
#   define OAUTH_API   __declspec(dllimport)
#endif  //OAUTH_LIBRARY_EXPORT

class OAUTH_API COAuthSDK
{
public:
	COAuthSDK(void);
	virtual ~COAuthSDK(void);

	bool GetRequestToken(CClientDetails &objClientDetails) throw (...);
	bool GetAccessToken(CClientDetails &objClientDetails,string strVerifier) throw (...);
	void RenewToken(CClientDetails &objClientDetails) throw (...);
	void RevokeToken(CClientDetails &objClientDetails) throw (...);
	string AuthorizeUrl(CClientDetails &objClientDetails) throw (...);

	string GetProtectedResourse(CClientDetails &objClientDetails,string strUrl, HttpMethodConstants httpMethod = GETMethod, string postParameters = NULL) throw (...);
};

#endif//_OAUTHSDK_H_INCLUDED_