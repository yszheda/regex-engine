//#ifdef _SHOWERRMESSAGE_H_
//#define _SHOWERRMESSAGE_H_

#pragma once
#include "stdafx.h"


//#include <iostream> 
#include <string>
#include <boost/regex.hpp>
using namespace std; 
using namespace boost::regex_constants;
//extern void ShowErrMessage(const boost::regex_error &err);
inline void ShowErrMessage(const boost::regex_error &err)
{
	wstring message;
	switch(err.code())
	{
		case error_collate:
			message=L"[[.name.]] ����ָ���˷Ƿ��Ķ���Ԫ�ء�";
			break;
		case error_ctype:
			message=L"[[:name:]] ����ָ������Ч���ַ������ơ�";
			break;
		case error_escape:
			message=L"��������Ч��ĩβ��ת�����";
			break;
		case error_backref:
			message=L"ָ�򲻴��ڵı���ӱ��ʽ�ĺ������á�";
			break;
		case error_brack:
			message=L"��Ч���ַ��� [...]��";
			break;
		case error_paren:
			message=L"'(' �� ')' ��ƥ�䡣";
			break;
		case error_brace:
			message=L"'{' �� '}' ��ƥ�䡣";
			break;
		case error_badbrace:
			message=L"{...} ��������Ч��";
			break;
		case error_range:
			message=L"�ַ���Χ��Ч������ [d-a]��";
			break;
		case error_space:
			message=L"�ڴ������";
			break;
		case error_badrepeat:
			message=L"��ͼ��ĳЩ�����ظ��Ķ����ظ������� a+";
			break;
		case error_complexity:
			message=L"���ʽ���ڸ��ӣ��޷�����";
			break;
		case error_stack:
			message=L"����ջ�ռ������";
			break;
		case error_bad_pattern:
			message=L"����δָ������";
			break;
	}
	CString m_strErrMsg(message.c_str());
	//MessageBox("121");
	MessageBoxW(NULL, message.c_str(), NULL, MB_OK); 
}
//#endif
