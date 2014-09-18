#pragma once

#ifndef _ALERTDETAILSRESPONSE_H_INCLUDED_
#define _ALERTDETAILSRESPONSE_H_INCLUDED_

#ifdef ALERTDETAILSRESPONSE_LIBRARY_EXPORT // inside DLL
#   define CALERTDETAILSRESPONSE  __declspec(dllexport)
#else //outside DLL
#   define CALERTDETAILSRESPONSE   __declspec(dllimport)
#endif  //ALERTDETAILSRESPONSE_LIBRARY_EXPORT 


class CALERTDETAILSRESPONSE CAlertDetailsResponse
{
public:
	CAlertDetailsResponse(void);
	virtual ~CAlertDetailsResponse(void);

    long GetCreateDate();
    void SetCreateDate(long CreateDate);

    long GetAlertId() ;
    void SetAlertId(long AlertId) ;

	CString GetMsgText() ;
	void SetMsgText(CString MsgText) ;

	long GetReadDate() ;
	void SetReadDate(long ReadDate) ;

	CString GetSubject() ;
    void SetSubject(CString Subject) ;
	void Serialize(CString &strString);
private:
	long m_CreateDate;
    long m_AlertId;
    CString m_MsgText;
    long m_ReadDate;
    CString m_Subject;
};

#endif//_ALERTDETAILSRESPONSE_H_INCLUDED_