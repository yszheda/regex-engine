#pragma once


// CEdit3 �Ի���

class CEdit3 : public CDialog
{
	DECLARE_DYNAMIC(CEdit3)

public:
	CEdit3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEdit3();

// �Ի�������
	enum { IDD = IDD_INTERFACE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
