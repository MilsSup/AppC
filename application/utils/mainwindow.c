#include <windows.h>
#include "digproc.h"
#define ID_MYBUTTON 1

LRESULT CALLBACK MainWinProc(HWND hw, UINT msg, WPARAM wp, LPARAM lp) {
	extern HINSTANCE h;
	switch (msg) {
	case WM_CREATE:
		CreateWindow(
		"button",
		"My button",
		WS_CHILD |
		BS_PUSHBUTTON |
		WS_VISIBLE,
		5,
		5,
		100,
		20,
		hw,
		(HMENU)ID_MYBUTTON,
		NULL,
		NULL);
		return 0;
	case WM_COMMAND:
		if (HIWORD(wp)==0) {
			extern char buf[256];
			switch (LOWORD(wp)) {
			case 6:  // команда меню Exit (6 id в ресурсах)
				PostQuitMessage(0);
				break;
			default: // все остальные команды
				wsprintf(buf,"Command code: %d",LOWORD(wp));
				DialogBox(h,"Ex4_Dlg",hw,DlgProc);
			}
		}
   return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hw,msg,wp,lp);
}