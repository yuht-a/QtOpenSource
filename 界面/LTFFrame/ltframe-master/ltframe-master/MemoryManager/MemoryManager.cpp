// MemoryManager.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "MemoryManager.h"
#include "UIClass.h"
int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	HANDLE hMutex = ::CreateMutex(NULL,FALSE,L"{A406B74E-8E21-4B6D-98E8-003BCB009140}");
	if (::GetLastError()==ERROR_ALREADY_EXISTS)
	{
		MessageBox(0,L"������ͬʵ����һ��������������,��رպ�����",0,0);
		::ReleaseMutex(hMutex);
		::CloseHandle( hMutex );
		return 0;  
	}


	OSVERSIONINFO osvi;

	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	GetVersionEx(&osvi);
	if (osvi.dwMajorVersion<5)
	{
		MessageBox(NULL,_T("����ϵͳ�汾����,���д˳�����Ҫwindows2000���ϵĲ���ϵͳ"),_T("����"),MB_ICONERROR);
		return FALSE;	
	}

	UIClass * uiclass=new UIClass();
	return 1;
}



