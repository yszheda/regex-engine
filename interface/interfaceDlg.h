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

	//bool state1;
	//bool state2;
	//bool state3;

	CListBox m_list;
	afx_msg void OnLbnDblclkList1();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnAbout();

	afx_msg void OnUpdatePosix(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEcmas(CCmdUI *pCmdUI);
	afx_msg void OnUpdateJS(CCmdUI *pCmdUI);
	afx_msg void OnUpdateGrep(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEgrep(CCmdUI *pCmdUI);
	afx_msg void OnUpdateSed(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePerl(CCmdUI *pCmdUI);
	afx_msg void OnUpdateAwk(CCmdUI *pCmdUI);
	afx_msg void OnPosix();
	afx_msg void OnEcmas();
	afx_msg void OnJS();
	afx_msg void OnGrep();
	afx_msg void OnEgrep();
	afx_msg void OnAwk();
	afx_msg void OnSed();
	afx_msg void OnPerl();
private:
	void InitializeState();
	bool state_posix;
	bool state_ecmas;
	bool state_js;
	bool state_grep;
	bool state_egrep;
	bool state_awk;
	bool state_sed;
	bool state_perl;
	bool state_basic;
	bool state_extended;

	bool state_icase;

	bool state_singleline;
	bool state_multiline;
	bool state_not_null;


public:
	afx_msg void OnIcase();
	afx_msg void OnUpdateIcase(CCmdUI *pCmdUI);
	afx_msg void OnSingleline();
	afx_msg void OnUpdateSingleline(CCmdUI *pCmdUI);
	afx_msg void OnMultiline();
	afx_msg void OnUpdateMultiline(CCmdUI *pCmdUI);
	afx_msg void OnBasic();
	afx_msg void OnUpdateBasic(CCmdUI *pCmdUI);
	afx_msg void OnExtended();
	afx_msg void OnUpdateExtended(CCmdUI *pCmdUI);
	afx_msg void OnNotNull();
	afx_msg void OnUpdateNotNull(CCmdUI *pCmdUI);
};
