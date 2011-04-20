#pragma once


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
public:
	CString m_edit2;
private:
	CString m_strExpression;
	CString m_strTestString;
	CString m_strReplaceString;
public:
	afx_msg void OnBnClickedReplace();

	friend class CinterfaceDlg;
};


