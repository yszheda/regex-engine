
#pragma once
#include "stdafx.h"
#include "interface.h"
#include "Dlg2.h"
#include "ShowErrMessage.h"
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;
//extern void ShowErrMessage(const boost::regex_error &err);
// CDlg2 对话框

IMPLEMENT_DYNAMIC(CDlg2, CDialog)

CDlg2::CDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg2::IDD, pParent)
	//, m_edit2(_T(""))
	, m_strExpression(_T(""))
	, m_strTestString(_T(""))
	, m_strReplaceString(_T(""))
	, m_matchFlag(boost::regex_constants::match_default)
	, m_syntaxType(boost::regex_constants::normal)
{

}

CDlg2::~CDlg2()
{
}

void CDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT1, m_edit2);
	DDX_Text(pDX, IDC_EXPRESSION, m_strExpression);
	DDX_Text(pDX, IDC_TESTSTRING, m_strTestString);
	DDX_Text(pDX, IDC_REPLACESTRING, m_strReplaceString);
}


BEGIN_MESSAGE_MAP(CDlg2, CDialog)
	ON_BN_CLICKED(IDC_REPLACE, &CDlg2::OnBnClickedReplace)
END_MESSAGE_MAP()


// CDlg2 消息处理程序

void CDlg2::OnBnClickedReplace()
{
	UpdateData(TRUE);
	wstring testString(m_strTestString.GetBuffer());
	wstring expString(m_strExpression.GetBuffer());
	wstring repString(m_strReplaceString.GetBuffer());
	try{
		wregex expression(expString, m_syntaxType);
		wstring result = regex_replace(testString, expression, repString, m_matchFlag);
		//m_strResult.Format("%s",result.c_str());
		CString m_strResult(result.c_str());
		MessageBox(m_strResult);
		UpdateData(FALSE);
	}catch(const boost::regex_error &err)
	{
		ShowErrMessage(err);
	}
	catch(...)
	{
		MessageBox(L"未知错误！");
	}
}

void CDlg2::OnPosix()
{
	if(state_posix==true)
	{
		//m_syntaxType=
	}
}

void CDlg2::OnEcmas()
{
	if(state_ecmas==true)
	{
		//m_syntaxType=;
	}MessageBox(L"T2");
}

void CDlg2::OnJS()
{
	if(state_js==true)
	{
		m_syntaxType=JavaScript;
	}
}

void CDlg2::OnGrep()
{
	if(state_grep==true)
	{
		m_syntaxType=grep;
	}
}

void CDlg2::OnEgrep()
{
	if(state_egrep==true)
	{
		m_syntaxType=egrep;
	}
}

void CDlg2::OnAwk()
{
	if(state_awk==true)
	{
		m_syntaxType=awk;
	}
}

void CDlg2::OnSed()
{
	if(state_sed==true)
	{
		m_syntaxType=sed;
	}
}

void CDlg2::OnPerl()
{
	if(state_perl==true)
	{
		m_syntaxType=perl;
	}
}