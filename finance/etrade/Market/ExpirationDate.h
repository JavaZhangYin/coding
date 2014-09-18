#pragma once

#ifndef EXPIRATION_DATE__H_INCLUDED_
#define EXPIRATION_DATE__H_INCLUDED_

#ifdef EXPIRATION_DATE__SDK_LIBRARY_EXPORT // inside DLL
#   define EXPIRATION_DATE   __declspec(dllexport)
#else //outside DLL
#   define EXPIRATION_DATE   __declspec(dllimport)
#endif  //EXPIRATION_DATE__SDK_LIBRARY_EXPORT



class EXPIRATION_DATE CExpirationDate
{
public:
	CExpirationDate(void);
	virtual ~CExpirationDate(void);

	int GetYear();
	void SetYear(int year) ;
	
	int GetMonth() ;
	void SetMonth(int month) ;
//	void SetMonth(CString str) ;

	int GetDay() ;
	void SetDay(int day); 

	CString GetExpiryType() ;
	void SetExpiryType(CString ExpiryType); 
	void Serialize(CString &strString);
private:
	int m_Month;
	int m_Year;
	int m_Day;
	CString m_ExpiryType;
};

#endif//EXPIRATION_DATE__H_INCLUDED_