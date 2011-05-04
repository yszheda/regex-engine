// interfaceDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "interface.h"
#include "interfaceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnUpdateAwk(CCmdUI *pCmdUI);
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	
	//ON_UPDATE_COMMAND_UI(ID_AWK, &CAboutDlg::OnUpdateAwk)
END_MESSAGE_MAP()


// CinterfaceDlg 对话框




CinterfaceDlg::CinterfaceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CinterfaceDlg::IDD, pParent)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CinterfaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_LIST1, m_list);
	
}

BEGIN_MESSAGE_MAP(CinterfaceDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_LBN_DBLCLK(IDC_LIST1, &CinterfaceDlg::OnLbnDblclkList1)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CinterfaceDlg::OnTcnSelchangeTab1)
	ON_COMMAND(ID_32773, &CinterfaceDlg::OnAbout)
	ON_WM_INITMENUPOPUP()
	ON_UPDATE_COMMAND_UI(ID_POSIX, &CinterfaceDlg::OnUpdatePosix)
	ON_UPDATE_COMMAND_UI(ID_ECMAS, &CinterfaceDlg::OnUpdateEcmas)
	ON_UPDATE_COMMAND_UI(ID_JAVAS, &CinterfaceDlg::OnUpdateJS)
	ON_UPDATE_COMMAND_UI(ID_GREP, &CinterfaceDlg::OnUpdateGrep)
	ON_UPDATE_COMMAND_UI(ID_EGREP, &CinterfaceDlg::OnUpdateEgrep)
	ON_UPDATE_COMMAND_UI(ID_SED, &CinterfaceDlg::OnUpdateSed)
	ON_UPDATE_COMMAND_UI(ID_PERL, &CinterfaceDlg::OnUpdatePerl)
	ON_UPDATE_COMMAND_UI(ID_AWK, &CinterfaceDlg::OnUpdateAwk)
	ON_COMMAND(ID_POSIX, &CinterfaceDlg::OnPosix)
	ON_COMMAND(ID_ECMAS, &CinterfaceDlg::OnEcmas)
	ON_COMMAND(ID_JAVAS, &CinterfaceDlg::OnJS)
	ON_COMMAND(ID_GREP, &CinterfaceDlg::OnGrep)
	ON_COMMAND(ID_EGREP, &CinterfaceDlg::OnEgrep)
	ON_COMMAND(ID_AWK, &CinterfaceDlg::OnAwk)
	ON_COMMAND(ID_SED, &CinterfaceDlg::OnSed)
	ON_COMMAND(ID_PERL, &CinterfaceDlg::OnPerl)
	ON_COMMAND(ID_ICASE, &CinterfaceDlg::OnIcase)
	ON_UPDATE_COMMAND_UI(ID_ICASE, &CinterfaceDlg::OnUpdateIcase)
	ON_COMMAND(ID_SINGLELINE, &CinterfaceDlg::OnSingleline)
	ON_UPDATE_COMMAND_UI(ID_SINGLELINE, &CinterfaceDlg::OnUpdateSingleline)
	ON_COMMAND(ID_MULTILINE, &CinterfaceDlg::OnMultiline)
	ON_UPDATE_COMMAND_UI(ID_MULTILINE, &CinterfaceDlg::OnUpdateMultiline)
	ON_COMMAND(ID_BASIC, &CinterfaceDlg::OnBasic)
	ON_UPDATE_COMMAND_UI(ID_BASIC, &CinterfaceDlg::OnUpdateBasic)
	ON_COMMAND(ID_EXTENDED, &CinterfaceDlg::OnExtended)
	ON_UPDATE_COMMAND_UI(ID_EXTENDED, &CinterfaceDlg::OnUpdateExtended)
	ON_COMMAND(ID_NOT_NULL, &CinterfaceDlg::OnNotNull)
	ON_UPDATE_COMMAND_UI(ID_NOT_NULL, &CinterfaceDlg::OnUpdateNotNull)
END_MESSAGE_MAP()



void CinterfaceDlg::InitializeState()
{
	state_posix=false;
	state_ecmas=false;
	state_js=false;
	state_grep=false;
	state_egrep=false;
	state_awk=false;
	state_sed=false;
	state_perl=true;
	state_basic=true;
	state_extended=false;

	state_icase=false;

	state_singleline=false;
	state_multiline=true;
	state_not_null=false;
}
// CinterfaceDlg 消息处理程序
BOOL CinterfaceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//m_tab.SetCurSel(1);
	m_tab.SetCurFocus(1);
	UpdateData(false);

	//列出标签选项
	m_tab.InsertItem(0,L"查找");
	m_tab.InsertItem(1,L"替换");

	//列出样例库
	m_list.InsertString(0,L"IP地址");
	m_list.InsertString(1,L"HTML标签");
	m_list.InsertString(2,L"Internet URL");
	m_list.InsertString(3,L"身份证");

	m_dlg1.Create(IDD_DIALOG1,&m_tab);
	m_dlg2.Create(IDD_DIALOG2,&m_tab);

	CRect rs;
	m_tab.GetClientRect(&rs);

	rs.top+=25;  
	rs.bottom-=10;  
	rs.left+=1;  
	rs.right-=2;  
	//设置子对话框尺寸并移动到指定位置 
	m_dlg1.MoveWindow(&rs);
	m_dlg2.MoveWindow(&rs);
	m_dlg1.ShowWindow(true);
	m_dlg2.ShowWindow(false);

	InitializeState();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CinterfaceDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CinterfaceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CinterfaceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CinterfaceDlg::OnLbnDblclkList1()
{
	// TODO: 在此添加控件通知处理程序代码
	int listnum=m_list.GetCurSel();
	switch(listnum)
	{
	case 0:
		m_dlg1.m_strExpression="(1?\d{1,2}|2[1234]\d|25[12345])\.(1?\d{1,2}|2[1234]\d|25[12345])\.(1?\d{1,2}|2[1234]\d|25[12345])\.(1?\d{1,2}|2[1234]\d|25[12345])";
		m_dlg2.m_strExpression="(1?\d{1,2}|2[1234]\d|25[12345])\.(1?\d{1,2}|2[1234]\d|25[12345])\.(1?\d{1,2}|2[1234]\d|25[12345])\.(1?\d{1,2}|2[1234]\d|25[12345])";
		break;
	case 1:
		m_dlg1.m_strExpression="<(\S*?)[^>]*>.*?</>|<.*? /> ";
		m_dlg2.m_strExpression="<(\S*?)[^>]*>.*?</>|<.*? /> ";
		break;
	case 2:
		m_dlg1.m_strExpression="(http://)?([\w-]+\.)+[\w-]+(/[\w- ./?%&=]*)?";
		m_dlg2.m_strExpression="(http://)?([\w-]+\.)+[\w-]+(/[\w- ./?%&=]*)?";
		break;
	case 3:
		m_dlg1.m_strExpression="\d{18}|\d{15}";
		m_dlg2.m_strExpression="\d{18}|\d{15}";
		break;
	default:
		;
	}
	
	m_dlg1.UpdateData(false);
	m_dlg2.UpdateData(false);
}

void CinterfaceDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int CurSel=m_tab.GetCurSel();
		switch(CurSel)
		{
		case 0:
			//MessageBox(L"0");
			m_dlg1.ShowWindow(true);
			m_dlg2.ShowWindow(false);
			break;
		case 1:
			//MessageBox(L"1");
			m_dlg1.ShowWindow(false);
			m_dlg2.ShowWindow(true);
			break;
		default:
			;
		}
	*pResult = 0;
}



void CinterfaceDlg::OnAbout()
{
	// TODO: 在此添加命令处理程序代码
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

void CinterfaceDlg::OnInitMenuPopup(CMenu *pPopupMenu, UINT nIdex, BOOL bSysMenu)
{
	 ASSERT(pPopupMenu != NULL);
    // Check the enabled state of various menu items.
	 CCmdUI state;
    state.m_pMenu = pPopupMenu;
    ASSERT(state.m_pOther == NULL);
    ASSERT(state.m_pParentMenu == NULL);

	// Determine if menu is popup in top-level menu and set m_pOther to
    // it if so (m_pParentMenu == NULL indicates that it is secondary popup).
    HMENU hParentMenu;
    if (AfxGetThreadState()->m_hTrackingMenu == pPopupMenu->m_hMenu)
        state.m_pParentMenu = pPopupMenu;    // Parent == child for tracking popup.
    else if ((hParentMenu = ::GetMenu(m_hWnd)) != NULL)
    {
        CWnd* pParent = this;
           // Child Windows don't have menus--need to go to the top!
        if (pParent != NULL &&
           (hParentMenu = ::GetMenu(pParent->m_hWnd)) != NULL)
        {
           int nIndexMax = ::GetMenuItemCount(hParentMenu);
           for (int nIndex = 0; nIndex < nIndexMax; nIndex++)
           {
            if (::GetSubMenu(hParentMenu, nIndex) == pPopupMenu->m_hMenu)
            {
                // When popup is found, m_pParentMenu is containing menu.
                state.m_pParentMenu = CMenu::FromHandle(hParentMenu);
                break;
            }
           }
        }
    }

	state.m_nIndexMax = pPopupMenu->GetMenuItemCount();
    for (state.m_nIndex = 0; state.m_nIndex < state.m_nIndexMax;
      state.m_nIndex++)
    {
        state.m_nID = pPopupMenu->GetMenuItemID(state.m_nIndex);
        if (state.m_nID == 0)
           continue; // Menu separator or invalid cmd - ignore it.

		 ASSERT(state.m_pOther == NULL);
        ASSERT(state.m_pMenu != NULL);
        if (state.m_nID == (UINT)-1)
        {
           // Possibly a popup menu, route to first item of that popup.
           state.m_pSubMenu = pPopupMenu->GetSubMenu(state.m_nIndex);
           if (state.m_pSubMenu == NULL ||
            (state.m_nID = state.m_pSubMenu->GetMenuItemID(0)) == 0 ||
            state.m_nID == (UINT)-1)
           {
            continue;       // First item of popup can't be routed to.
           }
           state.DoUpdate(this, TRUE);   // Popups are never auto disabled.
        }
        else
        {
           // Normal menu item.
           // Auto enable/disable if frame window has m_bAutoMenuEnable
           // set and command is _not_ a system command.
           state.m_pSubMenu = NULL;
           state.DoUpdate(this, FALSE);
        }

		// Adjust for menu deletions and additions.
        UINT nCount = pPopupMenu->GetMenuItemCount();
        if (nCount < state.m_nIndexMax)
        {
           state.m_nIndex -= (state.m_nIndexMax - nCount);
           while (state.m_nIndex < nCount &&
            pPopupMenu->GetMenuItemID(state.m_nIndex) == state.m_nID)
           {
            state.m_nIndex++;
           }
        }
        state.m_nIndexMax = nCount;
    }
}
void CinterfaceDlg::OnUpdatePosix(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	//m_dlg1.state_posix=!m_dlg1.state_posix;
	pCmdUI->SetCheck(state_posix);
}

void CinterfaceDlg::OnUpdateEcmas(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(state_ecmas);
}

void CinterfaceDlg::OnUpdateJS(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(state_js);
}

void CinterfaceDlg::OnUpdateGrep(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(state_grep);
}

void CinterfaceDlg::OnUpdateEgrep(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(state_egrep);
}


void CinterfaceDlg::OnUpdateAwk(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(state_awk);
}

void CinterfaceDlg::OnUpdateSed(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(state_sed);
}

void CinterfaceDlg::OnUpdatePerl(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(state_perl);
}
void CinterfaceDlg::OnPosix()
{
	// TODO: 在此添加命令处理程序代码
	if(state_posix==false)
	{
		state_posix=!state_posix;
		state_ecmas=state_js=state_grep=state_egrep=state_awk=state_sed=state_perl=false;
		m_dlg1.SetPosix();
		m_dlg2.SetPosix();
	}
}

void CinterfaceDlg::OnEcmas()
{
	// TODO: 在此添加命令处理程序代码
	if(state_ecmas==false)
	{
		state_ecmas=!state_ecmas;
		state_posix=state_js=state_grep=state_egrep=state_awk=state_sed=state_perl=false;
		m_dlg1.SetEcmas();
		m_dlg2.SetEcmas();
	}
}

void CinterfaceDlg::OnJS()
{
	// TODO: 在此添加命令处理程序代码
	if(state_js==false)
	{
		state_js=!state_js;
		state_ecmas=state_posix=state_grep=state_egrep=state_awk=state_sed=state_perl=false;
		m_dlg1.SetJS();
		m_dlg2.SetJS();
	}
}

void CinterfaceDlg::OnGrep()
{
	// TODO: 在此添加命令处理程序代码
	if(state_grep==false)
	{
		state_grep=!state_grep;
		state_ecmas=state_js=state_posix=state_egrep=state_awk=state_sed=state_perl=false;
		m_dlg1.SetGrep();
		m_dlg2.SetGrep();
	}
}

void CinterfaceDlg::OnEgrep()
{
	// TODO: 在此添加命令处理程序代码
	if(state_egrep==false)
	{
		state_egrep=!state_egrep;
		state_ecmas=state_js=state_grep=state_posix=state_awk=state_sed=state_perl=false;
		m_dlg1.SetEgrep();
		m_dlg2.SetEgrep();
	}
}

void CinterfaceDlg::OnAwk()
{
	// TODO: 在此添加命令处理程序代码
	if(state_awk==false)
	{
		state_awk=!state_awk;
		state_ecmas=state_js=state_grep=state_egrep=state_posix=state_sed=state_perl=false;
		m_dlg1.SetAwk();
		m_dlg2.SetAwk();
	}
}

void CinterfaceDlg::OnSed()
{
	// TODO: 在此添加命令处理程序代码
	if(state_sed==false)
	{
		state_sed=!state_sed;
		state_ecmas=state_js=state_grep=state_egrep=state_awk=state_posix=state_perl=false;
		m_dlg1.SetSed();
		m_dlg2.SetSed();
	}
}

void CinterfaceDlg::OnPerl()
{
	// TODO: 在此添加命令处理程序代码
	if(state_perl==false)
	{
		state_perl=!state_perl;
		state_ecmas=state_js=state_grep=state_egrep=state_awk=state_sed=state_posix=false;
		m_dlg1.SetPerl();
		m_dlg2.SetPerl();
	}
}

void CinterfaceDlg::OnIcase()
{
	if(state_icase==false)
	{
		state_icase=!state_icase;
		m_dlg1.SetICase(state_icase);
		m_dlg2.SetICase(state_icase);
	}
}

void CinterfaceDlg::OnUpdateIcase(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(state_icase);
}

void CinterfaceDlg::OnSingleline()
{
	if(state_singleline==false)
	{
		state_singleline=!state_singleline;
		state_multiline=!state_multiline;
		m_dlg1.SetSingleLine();
		m_dlg2.SetSingleLine();
	}
}

void CinterfaceDlg::OnUpdateSingleline(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(state_singleline);
}

void CinterfaceDlg::OnMultiline()
{
	if(state_multiline==false)
	{
		state_singleline=!state_singleline;
		state_multiline=!state_multiline;
		m_dlg1.ResetSingleLine();
		m_dlg2.ResetSingleLine();
	}
}

void CinterfaceDlg::OnUpdateMultiline(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(state_multiline);
}

void CinterfaceDlg::OnBasic()
{
	if(state_basic==false)
	{
		state_basic=!state_basic;
		state_extended=!state_extended;
		m_dlg1.SetBasic();
		m_dlg2.SetBasic();
	}
}

void CinterfaceDlg::OnUpdateBasic(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(state_basic);
}

void CinterfaceDlg::OnExtended()
{
	if(state_extended==false)
	{
		state_extended=!state_extended;
		state_basic=!state_basic;
		m_dlg1.SetExtended();
		m_dlg2.SetExtended();
	}
}

void CinterfaceDlg::OnUpdateExtended(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(state_extended);
}

void CinterfaceDlg::OnNotNull()
{
	if(state_not_null==false)
	{
		state_not_null=!state_not_null;
		m_dlg1.SetNotNull(state_not_null);
		m_dlg2.SetNotNull(state_not_null);
	}
}

void CinterfaceDlg::OnUpdateNotNull(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(state_not_null);
}
