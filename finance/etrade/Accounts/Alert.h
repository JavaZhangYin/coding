#pragma once

#ifndef _ALERTS_H_INCLUDED_
#define _ALERTS_H_INCLUDED_

#ifdef ALERT_SDK_LIBRARY_EXPORT // inside DLL
#   define ALERT   __declspec(dllexport)
#else //outside DLL
#   define ALERT   __declspec(dllimport)
#endif  //ALERT_SDK_LIBRARY_EXPORT


class ALERT CAlert
{
public:
	CAlert(void);
	~CAlert(void);

	long GetAlertDateTime();
	void SetAlertDateTime(long AlertDateTime) ;

	long GetAlertId() ;
	void SetAlertId(long AlertId) ;
	
	CString GetAlertSubject() ;
	void SetAlertSubject(CString AlertSubject) ;

	EAlertCategory GetCategory() ;
	void SetCategory(EAlertCategory Category) ;
	void SetCategory(CString str);
	
	EAlertReadFlag GetReadFlag() ;
	void SetReadFlag(EAlertReadFlag ReadFlag) ;
	void SetReadFlag(CString str);

	CString GetSymbol() ;
	void SetSymbol(CString Symbol) ;
	void Serialize(CString &strString);
private:
    long m_AlertDateTime;
	long m_AlertId;
    CString m_AlertSubject;
    EAlertCategory m_Category;
	EAlertReadFlag m_ReadFlag;
    CString m_Symbol;
};
#endif//_ALERTS_H_INCLUDED_