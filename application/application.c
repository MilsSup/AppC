#include <windows.h>
#include "mainwindow.h"
HINSTANCE h;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hpi, LPSTR cmdline, int ss) {
    (void)hpi;
    (void)cmdline; 
	WNDCLASS wc;
	wc.style=0;
	wc.lpfnWndProc=MainWinProc;
	wc.cbClsExtra=wc.cbWndExtra=0;
	wc.hInstance=hInst;
	wc.hIcon=LoadIcon(hInst, "Ex4_Icon");
	wc.hCursor=NULL;
	wc.hbrBackground=CreateSolidBrush(RGB(108, 0, 198));
	wc.lpszMenuName="Ex4_Menu";
	wc.lpszClassName="Example MainWnd Class";
	if (!RegisterClass(&wc))
		return FALSE;

	HWND hMainWnd = CreateWindow(
	"Example MainWnd Class",
	"EXAMPLE",
	WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	NULL,
	NULL,
	hInst,
	NULL);
	if (!hMainWnd)
		return FALSE;
	
	ShowWindow(hMainWnd,ss);
	UpdateWindow(hMainWnd);
	MSG msg;
	while (GetMessage(&msg,NULL,0,0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	} 
	
	return msg.wParam;
}

