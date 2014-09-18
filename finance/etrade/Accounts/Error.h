#pragma once

#ifndef _ERROR_H_INCLUDED_
#define _ERROR_H_INCLUDED_

#ifdef ERROR_SDK_LIBRARY_EXPORT // inside DLL
#   define MY_ERROR   __declspec(dllexport)
#else //outside DLL
#   define MY_ERROR   __declspec(dllimport)
#endif  //ERROR_SDK_LIBRARY_EXPORT

class MY_ERROR CError
{
public:
	CError(void);
	virtual ~CError(void);

	int GetHTTPErrorCode() ;
	void SetHTTPErrorCode(int nHTTPErrorCode) ;
	
	int GetErrorCode() ;
	void SetErrorCode(int nErrorCode) ;

	CString GetErrorMsg() ;
	void SetErrorMsg(CString strErrorMsg) ;

	void Serialize(CString &strString);
private:
	int m_nHTTPErrorCode;
	int m_nErrorCode;
	CString m_strErrorMsg;
};
#endif //#ifndef _ERROR_H_INCLUDED_

