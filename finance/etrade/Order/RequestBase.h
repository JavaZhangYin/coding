#pragma once

#ifndef REQUEST_BASE__H_INCLUDED_
#define REQUEST_BASE__H_INCLUDED_

#ifdef REQUEST_BASE__SDK_LIBRARY_EXPORT // inside DLL
#   define REQUEST_BASE   __declspec(dllexport)
#else //outside DLL
#   define REQUEST_BASE   __declspec(dllimport)
#endif  //REQUEST_BASE__SDK_LIBRARY_EXPORT;



class REQUEST_BASE CRequestBase
{
public:
	CRequestBase(void);
	virtual ~CRequestBase(void);

	void Serialize(CString &strString);

	CString GetAccountId();
	void SetAccountId(CString AccountId) ;

	CString GetClientOrderId();
	void SetClientOrderId(CString ClientOrderId) ;

	double GetLimitPrice();
	void SetLimitPrice(double LimitPrice) ;

	long long GetPreviewId();
	void SetPreviewId(long long PreviewId) ;

	double GetStopPrice();
	void SetStopPrice(double StopPrice) ;

private:
	CString			m_AccountId;
	CString			m_ClientOrderId;
	double			m_LimitPrice;
	long long		m_PreviewId;
	double			m_StopPrice;
};					

#endif//REQUEST_BASE__H_INCLUDED_