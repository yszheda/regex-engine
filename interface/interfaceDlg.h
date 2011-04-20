// interfaceDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "Dlg1.h"
#include "Dlg2.h"
#include "afxwin.h"


// CinterfaceDlg 对话框
class CinterfaceDlg : public CDialog
{
// 构造
public:
	CinterfaceDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_INTERFACE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInitMenuPopup(CMenu *pPopupMenu, UINT nIndex,BOOL bSysMenu);
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	afx_msg void OnLbnSelchangeList1();

	CDlg1 m_dlg1;
	CDlg2 m_dlg2;

	bool state1;
	bool state2;
	bool state3;

	CListBox m_list;
	afx_msg void OnLbnDblclkList1();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnAbout();
	afx_msg void OnUpdate32776(CCmdUI *pCmdUI);
	afx_msg void On32776();
	afx_msg void On32777();
	afx_msg void OnUpdate32777(CCmdUI *pCmdUI);
	afx_msg void On32778();
	afx_msg void OnUpdate32778(CCmdUI *pCmdUI);
};
