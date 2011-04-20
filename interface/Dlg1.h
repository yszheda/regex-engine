#pragma once


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
public:
	CString m_edit1;
private:
	CString m_strExpression;
	CString m_strTestString;
public:
	afx_msg void OnBnClickedMatch();
	afx_msg void OnBnClickedSearch();

	friend class CinterfaceDlg;

	//afx_msg void OnBnClickedLoad();
	afx_msg void OnBnClickedLoad();
};
