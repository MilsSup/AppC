#include <windows.h>

char buf[256]=""; // строка для текстового поля в диалоге

BOOL CALLBACK DlgProc(HWND hw, UINT msg, WPARAM wp, LPARAM lp) {
	(void)lp;
	switch (msg) {
	case WM_INITDIALOG: // сообщение о создании диалога
		SetDlgItemText(hw, 1, buf);
		return TRUE;
	case WM_COMMAND: // сообщение от управляющих элементов
		if (LOWORD(wp)==2)
			EndDialog(hw,0);
	}
	return FALSE;
}