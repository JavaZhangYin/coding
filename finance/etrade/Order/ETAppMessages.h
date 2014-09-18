#pragma once

#ifndef _ETAPP_MESSAGES__H_INCLUDED_
#define _ETAPP_MESSAGES__H_INCLUDED_

#ifdef ETAPP_MESSAGES__SDK_LIBRARY_EXPORT // inside DLL
#   define ETAPP_MESSAGES   __declspec(dllexport)
#else //outside DLL
#   define ETAPP_MESSAGES   __declspec(dllimport)
#endif  //ETAPP_MESSAGES__SDK_LIBRARY_EXPORT


class ETAPP_MESSAGES CETAppMessages
{
public:
	CETAppMessages(void);
	virtual ~CETAppMessages(void);

	void Serialize(CString &strString);


	CString GetMsgDesc();
	void SetMsgDesc(CString MsgDesc);

	int GetMsgCode();
	void SetMsgCode(int MsgCode) ;

private:
	CString		m_MsgDesc;
	int			m_MsgCode;
};
#endif//_ETAPP_MESSAGES__H_INCLUDED_
