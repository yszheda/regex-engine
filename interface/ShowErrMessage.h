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
			message=L"[[.name.]] 块中指定了非法的对照元素。";
			break;
		case error_ctype:
			message=L"[[:name:]] 块中指定了无效的字符类名称。";
			break;
		case error_escape:
			message=L"出现了无效或末尾的转义符。";
			break;
		case error_backref:
			message=L"指向不存在的标记子表达式的后向引用。";
			break;
		case error_brack:
			message=L"无效的字符集 [...]。";
			break;
		case error_paren:
			message=L"'(' 和 ')' 不匹配。";
			break;
		case error_brace:
			message=L"'{' 和 '}' 不匹配。";
			break;
		case error_badbrace:
			message=L"{...} 块内容无效。";
			break;
		case error_range:
			message=L"字符范围无效，例如 [d-a]。";
			break;
		case error_space:
			message=L"内存溢出。";
			break;
		case error_badrepeat:
			message=L"试图将某些不能重复的东西重复，例如 a+";
			break;
		case error_complexity:
			message=L"表达式过于复杂，无法处理。";
			break;
		case error_stack:
			message=L"程序栈空间溢出。";
			break;
		case error_bad_pattern:
			message=L"其他未指定错误。";
			break;
	}
	CString m_strErrMsg(message.c_str());
	//MessageBox("121");
	MessageBoxW(NULL, message.c_str(), NULL, MB_OK); 
}
//#endif
