#pragma once


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
