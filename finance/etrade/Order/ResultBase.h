#pragma once

#ifndef RESULT_BASE__H_INCLUDED_
#define RESULT_BASE__H_INCLUDED_

#ifdef RESULT_BASE__SDK_LIBRARY_EXPORT // inside DLL
#   define RESULT_BASE   __declspec(dllexport)
#else //outside DLL
#   define RESULT_BASE   __declspec(dllimport)
#endif  //RESULT_BASE__SDK_LIBRARY_EXPORT;

class RESULT_BASE CResultBase
{
public:
	CResultBase(void);
	virtual ~CResultBase(void);
	void Serialize(CString &strString);


	CString GetAccountId();
	void SetAccountId(CString AccountId);
private:
	CString m_AccountId;
};
#endif//RESULT_BASE__H_INCLUDED_
