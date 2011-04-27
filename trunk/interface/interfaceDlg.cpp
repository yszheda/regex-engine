// interfaceDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "interface.h"
#include "interfaceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CinterfaceDlg �Ի���




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
END_MESSAGE_MAP()


// CinterfaceDlg ��Ϣ�������

BOOL CinterfaceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//m_tab.SetCurSel(1);
	m_tab.SetCurFocus(1);
	UpdateData(false);

	//�г���ǩѡ��
	m_tab.InsertItem(0,L"����");
	m_tab.InsertItem(1,L"�滻");

	//�г�������
	m_list.InsertString(0,L"IP��ַ");
	m_list.InsertString(1,L"HTML��ǩ");
	m_list.InsertString(2,L"Internet URL");
	m_list.InsertString(3,L"���֤");

	m_dlg1.Create(IDD_DIALOG1,&m_tab);
	m_dlg2.Create(IDD_DIALOG2,&m_tab);

	CRect rs;
	m_tab.GetClientRect(&rs);

	rs.top+=25;  
	rs.bottom-=10;  
	rs.left+=1;  
	rs.right-=2;  
	//�����ӶԻ���ߴ粢�ƶ���ָ��λ�� 
	m_dlg1.MoveWindow(&rs);
	m_dlg2.MoveWindow(&rs);
	m_dlg1.ShowWindow(true);
	m_dlg2.ShowWindow(false);

	
	m_dlg1.state_posix=false;
	m_dlg1.state_ecmas=false;
	m_dlg1.state_js=false;
	m_dlg1.state_grep=false;
	m_dlg1.state_egrep=false;
	m_dlg1.state_awk=false;
	m_dlg1.state_sed=false;
	m_dlg1.state_perl=true;

	m_dlg2.state_posix=false;
	m_dlg2.state_ecmas=false;
	m_dlg2.state_js=false;
	m_dlg2.state_grep=false;
	m_dlg2.state_egrep=false;
	m_dlg2.state_awk=false;
	m_dlg2.state_sed=false;
	m_dlg2.state_perl=true;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CinterfaceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CinterfaceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CinterfaceDlg::OnLbnDblclkList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ������������û����洦��������
	//m_dlg1.state_posix=!m_dlg1.state_posix;
	pCmdUI->SetCheck(m_dlg1.state_posix);
}

void CinterfaceDlg::OnUpdateEcmas(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_dlg1.state_ecmas);
}

void CinterfaceDlg::OnUpdateJS(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_dlg1.state_js);
}

void CinterfaceDlg::OnUpdateGrep(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_dlg1.state_grep);
}

void CinterfaceDlg::OnUpdateEgrep(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_dlg1.state_egrep);
}


void CinterfaceDlg::OnUpdateAwk(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_dlg1.state_awk);
}

void CinterfaceDlg::OnUpdateSed(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_dlg1.state_sed);
}

void CinterfaceDlg::OnUpdatePerl(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_dlg1.state_perl);
}
void CinterfaceDlg::OnPosix()
{
	// TODO: �ڴ���������������
	if(m_dlg1.state_posix==false){
	m_dlg1.state_posix=!m_dlg1.state_posix;
	m_dlg1.state_ecmas=m_dlg1.state_js=m_dlg1.state_grep=m_dlg1.state_egrep=m_dlg1.state_awk=m_dlg1.state_sed=m_dlg1.state_perl=false;
	m_dlg1.OnPosix();
	m_dlg2.state_posix=!m_dlg2.state_posix;
	m_dlg2.state_ecmas=m_dlg2.state_js=m_dlg2.state_grep=m_dlg2.state_egrep=m_dlg2.state_awk=m_dlg2.state_sed=m_dlg2.state_perl=false;
	m_dlg2.OnPosix();}
}

void CinterfaceDlg::OnEcmas()
{
	// TODO: �ڴ���������������
	if(m_dlg1.state_ecmas==false){
	m_dlg1.state_ecmas=!m_dlg1.state_ecmas;
	m_dlg1.state_posix=m_dlg1.state_js=m_dlg1.state_grep=m_dlg1.state_egrep=m_dlg1.state_awk=m_dlg1.state_sed=m_dlg1.state_perl=false;
	m_dlg1.OnEcmas();
	m_dlg2.state_ecmas=!m_dlg2.state_ecmas;
	m_dlg2.state_posix=m_dlg2.state_js=m_dlg2.state_grep=m_dlg2.state_egrep=m_dlg2.state_awk=m_dlg2.state_sed=m_dlg2.state_perl=false;
	m_dlg2.OnEcmas();}
}

void CinterfaceDlg::OnJS()
{
	// TODO: �ڴ���������������
	if(m_dlg1.state_js==false)
	{
	m_dlg1.state_js=!m_dlg1.state_js;
	m_dlg1.state_ecmas=m_dlg1.state_posix=m_dlg1.state_grep=m_dlg1.state_egrep=m_dlg1.state_awk=m_dlg1.state_sed=m_dlg1.state_perl=false;
	m_dlg1.OnJS();
	m_dlg2.state_js=!m_dlg2.state_js;
	m_dlg2.state_ecmas=m_dlg2.state_posix=m_dlg2.state_grep=m_dlg2.state_egrep=m_dlg2.state_awk=m_dlg2.state_sed=m_dlg2.state_perl=false;
	m_dlg2.OnJS();
	}
}

void CinterfaceDlg::OnGrep()
{
	// TODO: �ڴ���������������
	if(m_dlg1.state_grep==false){
	m_dlg1.state_grep=!m_dlg1.state_grep;
	m_dlg1.state_ecmas=m_dlg1.state_js=m_dlg1.state_posix=m_dlg1.state_egrep=m_dlg1.state_awk=m_dlg1.state_sed=m_dlg1.state_perl=false;
	m_dlg1.OnGrep();
	m_dlg2.state_grep=!m_dlg2.state_grep;
	m_dlg2.state_ecmas=m_dlg2.state_js=m_dlg2.state_posix=m_dlg2.state_egrep=m_dlg2.state_awk=m_dlg2.state_sed=m_dlg2.state_perl=false;
	m_dlg2.OnGrep();}
}

void CinterfaceDlg::OnEgrep()
{
	// TODO: �ڴ���������������
	if(m_dlg1.state_egrep==false){
	m_dlg1.state_egrep=!m_dlg1.state_egrep;
	m_dlg1.state_ecmas=m_dlg1.state_js=m_dlg1.state_grep=m_dlg1.state_posix=m_dlg1.state_awk=m_dlg1.state_sed=m_dlg1.state_perl=false;
	m_dlg1.OnEgrep();
	m_dlg2.state_egrep=!m_dlg2.state_egrep;
	m_dlg2.state_ecmas=m_dlg2.state_js=m_dlg2.state_grep=m_dlg2.state_posix=m_dlg2.state_awk=m_dlg2.state_sed=m_dlg2.state_perl=false;
	m_dlg2.OnEgrep();}
}

void CinterfaceDlg::OnAwk()
{
	// TODO: �ڴ���������������
	if(m_dlg1.state_awk==false){
	m_dlg1.state_awk=!m_dlg1.state_awk;
	m_dlg1.state_ecmas=m_dlg1.state_js=m_dlg1.state_grep=m_dlg1.state_egrep=m_dlg1.state_posix=m_dlg1.state_sed=m_dlg1.state_perl=false;
	m_dlg1.OnAwk();
	m_dlg2.state_awk=!m_dlg2.state_awk;
	m_dlg2.state_ecmas=m_dlg2.state_js=m_dlg2.state_grep=m_dlg2.state_egrep=m_dlg2.state_posix=m_dlg2.state_sed=m_dlg2.state_perl=false;
	m_dlg2.OnAwk();}
}

void CinterfaceDlg::OnSed()
{
	// TODO: �ڴ���������������
	if(m_dlg1.state_sed==false){
	m_dlg1.state_sed=!m_dlg1.state_sed;
	m_dlg1.state_ecmas=m_dlg1.state_js=m_dlg1.state_grep=m_dlg1.state_egrep=m_dlg1.state_awk=m_dlg1.state_posix=m_dlg1.state_perl=false;
	m_dlg1.OnSed();
	m_dlg2.state_sed=!m_dlg2.state_sed;
	m_dlg2.state_ecmas=m_dlg2.state_js=m_dlg2.state_grep=m_dlg2.state_egrep=m_dlg2.state_awk=m_dlg2.state_posix=m_dlg2.state_perl=false;
	m_dlg2.OnSed();}
}

void CinterfaceDlg::OnPerl()
{
	// TODO: �ڴ���������������
	if(m_dlg1.state_perl==false){
	m_dlg1.state_perl=!m_dlg1.state_perl;
	m_dlg1.state_ecmas=m_dlg1.state_js=m_dlg1.state_grep=m_dlg1.state_egrep=m_dlg1.state_awk=m_dlg1.state_sed=m_dlg1.state_posix=false;
	m_dlg1.OnPerl();
	m_dlg2.state_perl=!m_dlg2.state_perl;
	m_dlg2.state_ecmas=m_dlg2.state_js=m_dlg2.state_grep=m_dlg2.state_egrep=m_dlg2.state_awk=m_dlg2.state_sed=m_dlg2.state_posix=false;
	m_dlg2.OnPerl();}
}
