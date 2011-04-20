#pragma once


// CEdit3 对话框

class CEdit3 : public CDialog
{
	DECLARE_DYNAMIC(CEdit3)

public:
	CEdit3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEdit3();

// 对话框数据
	enum { IDD = IDD_INTERFACE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
