#pragma once
#include <boost/regex.hpp>

// CDlg2 对话框

class CDlg2 : public CDialog
{
	DECLARE_DYNAMIC(CDlg2)

public:
	CDlg2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlg2();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_strExpression;
	CString m_strTestString;
	CString m_strReplaceString;
	boost::regex_constants::match_flag_type m_matchFlag;
	boost::regex_constants::syntax_option_type m_syntaxType;
public:
	afx_msg void OnBnClickedReplace();

	friend class CinterfaceDlg;
	
		
	void SetPosix();
	void SetEcmas();
	void SetJS();
	void SetGrep();
	void SetEgrep();
	void SetAwk();
	void SetSed();
	void SetPerl();
	void SetBasic();
	void SetExtended();

	void SetICase(bool state_icase);
	
	void SetSingleLine();
	void ResetSingleLine();
	void SetNotNull(bool state_not_null);
};


