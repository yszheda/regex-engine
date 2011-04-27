
#pragma once
#include "stdafx.h"
#include "interface.h"
#include "Dlg1.h"
#include "ShowErrMessage.h"
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;
using namespace boost::regex_constants;
//extern void ShowErrMessage(const boost::regex_error &err);
// CDlg1 对话框

IMPLEMENT_DYNAMIC(CDlg1, CDialog)

CDlg1::CDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg1::IDD, pParent)
	//, m_edit1(_T(""))
	, m_strExpression(_T(""))
	, m_strTestString(_T(""))
	, m_matchFlag(boost::regex_constants::match_default)
	, m_syntaxType(boost::regex_constants::normal)
{

}

CDlg1::~CDlg1()
{
}

void CDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EXPRESSION, m_strExpression);
	DDX_Text(pDX, IDC_TESTSTRING, m_strTestString);
}


BEGIN_MESSAGE_MAP(CDlg1, CDialog)
	ON_BN_CLICKED(IDC_MATCH, &CDlg1::OnBnClickedMatch)
	ON_BN_CLICKED(IDC_SEARCH, &CDlg1::OnBnClickedSearch)
	//ON_BN_CLICKED(IDC_LOAD, &CDlg1::OnBnClickedLoad)
	ON_BN_CLICKED(IDC_LOAD, &CDlg1::OnBnClickedLoad)
END_MESSAGE_MAP()


// CDlg1 消息处理程序

void CDlg1::OnBnClickedMatch()
{
	UpdateData(TRUE);
	wcmatch what;
	wstring testString(m_strTestString.GetBuffer());
	wstring expString(m_strExpression.GetBuffer());
	try{
		wregex expression(expString, m_syntaxType);
		wstring result;
		if(regex_match(testString.c_str(), what, expression, m_matchFlag))
		{
			//AfxMessageBox("Match!");
			result = L"Match!\n";
			result += L"The strings matched are:";
			for(int i=0;i<what.size();i++)
				result += what[i].str();
		}
		else
		{
			//AfxMessageBox("No match!");
			result = L"No match!\n";
		}
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

void CDlg1::OnBnClickedSearch()
{
	UpdateData(TRUE);
	wsmatch what;
	wstring testString(m_strTestString.GetBuffer());
	wstring expString(m_strExpression.GetBuffer());
	try{
		wregex expression(expString, m_syntaxType);
		wstring result;
		wstring::const_iterator start = testString.begin();
		wstring::const_iterator end = testString.end();
		bool flag=0;
		while(regex_search(start, end, what, expression, m_matchFlag))
		{
			if(!flag)
			{
				result += L"The strings matched are:\n";
				flag = 1;
			}
			//AfxMessageBox(L"Match!");
			/*wstring msg(what[1].first, what[1].second);
			CString test(msg.c_str());
			MessageBox(test);
			result += what[1].str();*/
			for(int i=0;i<what.size();i++)
				result += what[i].str();
			/*for(int i=what[1].first;i<what[1].second;i++)
				result += what[i].str();*/
			result += L"\n";
			start = what[0].second;

			//result += L"The strings matched are:";
			//for(int i=0;i<what.size();i++)
				//result += what[i].str();
		}
		if(result.size() == 0)
		{
			result = L"No match!\n";
		}
		//else
		//{
		//	//AfxMessageBox("No match!");
		//	result = L"No match!\n";
		//}
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

void CDlg1::OnBnClickedLoad()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog  *lpszOpenFile;

	CStdioFile file;
	CString FilePathName;
	int row;
	CString result;

	lpszOpenFile = new CFileDialog(TRUE,L"",L"",OFN_FILEMUSTEXIST |OFN_HIDEREADONLY ,L"文件类型(*.txt)|*.txt|所有文件(*.*)|*.*|");
	
	if(lpszOpenFile->DoModal()==IDOK)
	{
		FilePathName=lpszOpenFile->GetPathName();
		SetWindowText(FilePathName);
	}

	if(FilePathName=="") return;

	if(!file.Open(FilePathName,CFile::modeRead))
	{
		MessageBox(L"Wrong!");
		return;
	}

	CString strLine,strTemp;
	row=0;
	while(file.ReadString(strLine))
	{
		TCHAR *str=strLine.GetBufferSetLength(strLine.GetLength());
		TCHAR *p;

		if(strLine!="")
		{
			for(p=_tcstok(str,_T(":"));p!=NULL;p=_tcstok(NULL,_T(":")))
			{
				strTemp=p;
				result=result+strTemp+_T("\r\n");
			}
			row++;
		}
	}

	delete lpszOpenFile;

	m_strTestString=result;
	UpdateData(false);
}

void CDlg1::OnPosix()
{
	if(state_posix==true)
	{
		//m_syntaxType=
	}
}

void CDlg1::OnEcmas()
{
	if(state_ecmas==true)
	{
		//m_syntaxType=;
	}MessageBox(L"T2");
}

void CDlg1::OnJS()
{
	if(state_js==true)
	{
		m_syntaxType=JavaScript;
	}
}

void CDlg1::OnGrep()
{
	if(state_grep==true)
	{
		m_syntaxType=grep;
	}
}

void CDlg1::OnEgrep()
{
	if(state_egrep==true)
	{
		m_syntaxType=egrep;
	}
}

void CDlg1::OnAwk()
{
	if(state_awk==true)
	{
		m_syntaxType=awk;
	}
}

void CDlg1::OnSed()
{
	if(state_sed==true)
	{
		m_syntaxType=sed;
	}
}

void CDlg1::OnPerl()
{
	if(state_perl==true)
	{
		m_syntaxType=perl;
	}
}
