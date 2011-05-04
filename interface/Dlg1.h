#pragma once
#include <boost/regex.hpp>

// CDlg1 �Ի���

class CDlg1 : public CDialog
{
	DECLARE_DYNAMIC(CDlg1)

public:
	CDlg1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlg1();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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


	//afx_msg void OnBnClickedLoad();
	afx_msg void OnBnClickedLoad();

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
