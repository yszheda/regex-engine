#pragma once


// CEdit2 �Ի���

class CEdit2 : public CDialog
{
	DECLARE_DYNAMIC(CEdit2)

public:
	CEdit2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEdit2();

// �Ի�������
	enum { IDD = IDD_INTERFACE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
