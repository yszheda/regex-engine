#pragma once


// CEdit2 对话框

class CEdit2 : public CDialog
{
	DECLARE_DYNAMIC(CEdit2)

public:
	CEdit2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEdit2();

// 对话框数据
	enum { IDD = IDD_INTERFACE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
