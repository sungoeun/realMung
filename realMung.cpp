
// realMung.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "realMung.h"
#include "realMungDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CrealMungApp

BEGIN_MESSAGE_MAP(CrealMungApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CrealMungApp 생성
CrealMungApp::CrealMungApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CrealMungApp 개체입니다.

CrealMungApp theApp;



BOOL CrealMungApp::InitInstance()
{
	CWinApp::InitInstance();

	CrealMungDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}

