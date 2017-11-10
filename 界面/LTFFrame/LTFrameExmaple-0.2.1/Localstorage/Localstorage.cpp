// Localstorage.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Localstorage.h"
#include "UIClass.h"
int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{

	HANDLE hMutex = ::CreateMutex(NULL,FALSE,L"{26A00FAE-FA3E-4A10-8CD8-374CB1A95C41}");
	if (::GetLastError()==ERROR_ALREADY_EXISTS)
	{
		MessageBox(0,L"具有相同实例的一个窗口已在运行,请关闭后重试",0,0);
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
		MessageBox(NULL,_T("操纵系统版本过低,运行此程序需要windows2000以上的操作系统"),_T("警告"),MB_ICONERROR);
		return FALSE;	
	}

	UIClass * uiclass=new UIClass();
	return 1;
}