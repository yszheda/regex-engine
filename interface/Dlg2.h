#pragma once


// CDlg2 �Ի���

class CDlg2 : public CDialog
{
	DECLARE_DYNAMIC(CDlg2)

public:
	CDlg2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlg2();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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


