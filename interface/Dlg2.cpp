

#include "stdafx.h"
#include "interface.h"
#include "Dlg2.h"
#include <string>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

// CDlg2 对话框

IMPLEMENT_DYNAMIC(CDlg2, CDialog)

CDlg2::CDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg2::IDD, pParent)
	//, m_edit2(_T(""))
	, m_strExpression(_T(""))
	, m_strTestString(_T(""))
	, m_strReplaceString(_T(""))
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
	ON_COMMAND(ID_POSIX, &CDlg2::OnPosix)
	ON_COMMAND(ID_ECMAS, &CDlg2::OnEcmas)
	ON_COMMAND(ID_JAVAS, &CDlg2::OnJavas)
	ON_COMMAND(ID_GREP, &CDlg2::OnGrep)
	ON_COMMAND(ID_EGREP, &CDlg2::OnEgrep)
	ON_COMMAND(ID_AWK, &CDlg2::OnAwk)
	ON_COMMAND(ID_SED, &CDlg2::OnSed)
	ON_COMMAND(ID_PERL, &CDlg2::OnPerl)
END_MESSAGE_MAP()


// CDlg2 消息处理程序

void CDlg2::OnBnClickedReplace()
{
	UpdateData(TRUE);
	wstring testString(m_strTestString.GetBuffer());
	wstring expString(m_strExpression.GetBuffer());
	wstring repString(m_strReplaceString.GetBuffer());
	wregex expression(expString);
	wstring result = regex_replace(testString, expression, repString);
	//m_strResult.Format("%s",result.c_str());
	CString m_strResult(result.c_str());
	MessageBox(m_strResult);
	UpdateData(FALSE);
}

void CDlg2::OnPosix()
{
	// TODO: 在此添加命令处理程序代码
}

void CDlg2::OnEcmas()
{
	// TODO: 在此添加命令处理程序代码
}

void CDlg2::OnJavas()
{
	// TODO: 在此添加命令处理程序代码
}

void CDlg2::OnGrep()
{
	// TODO: 在此添加命令处理程序代码
}

void CDlg2::OnEgrep()
{
	// TODO: 在此添加命令处理程序代码
}

void CDlg2::OnAwk()
{
	// TODO: 在此添加命令处理程序代码
}

void CDlg2::OnSed()
{
	// TODO: 在此添加命令处理程序代码
}

void CDlg2::OnPerl()
{
	// TODO: 在此添加命令处理程序代码
}
