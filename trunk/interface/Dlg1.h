#pragma once
#include <boost/regex.hpp>

// CDlg1 对话框

class CDlg1 : public CDialog
{
	DECLARE_DYNAMIC(CDlg1)

public:
	CDlg1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlg1();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_strExpression;
	CString m_strTestString;
	boost::regex_constants::match_flag_type m_matchFlag;
	boost::regex_constants::syntax_option_type m_syntaxType;
public:
	afx_msg void OnBnClickedMatch();
	afx_msg void OnBnClickedSearch();

	friend class CinterfaceDlg;

	bool state_posix;
	bool state_ecmas;
	bool state_js;
	bool state_grep;
	bool state_egrep;
	bool state_awk;
	bool state_sed;
	bool state_perl;

	//afx_msg void OnBnClickedLoad();
	afx_msg void OnBnClickedLoad();

	void OnPosix();
	void OnEcmas();
	void OnJS();
	void OnGrep();
	void OnEgrep();
	void OnAwk();
	void OnSed();
	void OnPerl();
};
