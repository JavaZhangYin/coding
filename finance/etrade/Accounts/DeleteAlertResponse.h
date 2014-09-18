#pragma once

#ifndef _DELETEALERTRESPONSE_H_INCLUDED_
#define _DELETEALERTRESPONSE_H_INCLUDED_

#ifdef DELETEALERTRESPONSE_SDK_LIBRARY_EXPORT // inside DLL
#   define DELETEALERTRESPONSE   __declspec(dllexport)
#else //outside DLL
#   define DELETEALERTRESPONSE   __declspec(dllimport)
#endif  //DELETEALERTRESPONSE_SDK_LIBRARY_EXPORT

class DELETEALERTRESPONSE CDeleteAlertResponse
{
public:
	CDeleteAlertResponse(void);
	virtual ~CDeleteAlertResponse(void);

	CString GetResult();
	void SetResult(CString Result);
	void Serialize(CString &strString);
private:
	CString m_Result;
};
#endif//_DELETEALERTRESPONSE_H_INCLUDED_
