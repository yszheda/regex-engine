// interface.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "interface.h"
#include "interfaceDlg.h"
#include "SkinPPWTL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CinterfaceApp

BEGIN_MESSAGE_MAP(CinterfaceApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CinterfaceApp ����

CinterfaceApp::CinterfaceApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CinterfaceApp ����

CinterfaceApp theApp;


// CinterfaceApp ��ʼ��

BOOL CinterfaceApp::InitInstance()
{
	//InitializeSkin("Gloss.ssk"); //����Ƥ��
	//skinppLoadSkin("Steel.ssk");			//����Ƥ�� && ��̬����
	//skinppLoadSkin("dogmax.ssk");			//����Ƥ�� && ��̬����
	//skinppLoadSkin("MAC.ssk");			//����Ƥ�� && ��̬����
	skinppLoadSkin("xp_corona.ssk");			//����Ƥ�� && ��̬����

	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	


	CinterfaceDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

int CinterfaceApp::ExitInstance()
{
	skinppExitSkin(); //�˳�����⣬����������

	return CWinApp::ExitInstance();
}
