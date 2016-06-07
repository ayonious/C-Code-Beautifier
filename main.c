#include <windows.h>
#include <commctrl.h>
#include "resource.h"
//#include "parseeeeeebegins3.c"
//#include "parsingandalignment3.c"

//#define IDC_CHILD_EDIT	104
const char g_szClassName[] = "myWindowClass";

int ayontwo(char string1[],char string2[]);
int ayonone(char string1[],char string2[]);
int ar=0,nCmdShow;

#define IDC_MAIN_EDIT	101

BOOL LoadTextFileToEdit(HWND hEdit, LPCTSTR pszFileName)
{
	HANDLE hFile;
	BOOL bSuccess = FALSE;

	hFile = CreateFile(pszFileName, GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_EXISTING, 0, NULL);
	if(hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwFileSize;

		dwFileSize = GetFileSize(hFile, NULL);
		if(dwFileSize != 0xFFFFFFFF)
		{
			LPSTR pszFileText;

			pszFileText = (LPSTR)GlobalAlloc(GPTR, dwFileSize + 1);
			if(pszFileText != NULL)
			{
				DWORD dwRead;

				if(ReadFile(hFile, pszFileText, dwFileSize, &dwRead, NULL))
				{
					pszFileText[dwFileSize] = 0; 
					if(SetWindowText(hEdit, pszFileText))
						bSuccess = TRUE; 
				}
				GlobalFree(pszFileText);
			}
		}
		CloseHandle(hFile);
	}
	return bSuccess;
}

BOOL SaveTextFileFromEdit(HWND hEdit, LPCTSTR pszFileName)
{
	HANDLE hFile;
	BOOL bSuccess = FALSE;

	hFile = CreateFile(pszFileName, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if(hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwTextLength;

		dwTextLength = GetWindowTextLength(hEdit);
		// No need to bother if there's no text.
		if(dwTextLength > 0)
		{
			LPSTR pszText;
			DWORD dwBufferSize = dwTextLength + 1;

			pszText = (LPSTR)GlobalAlloc(GPTR, dwBufferSize);
			if(pszText != NULL)
			{
				if(GetWindowText(hEdit, pszText, dwBufferSize)) 
				{
					DWORD dwWritten;

					if(WriteFile(hFile, pszText, dwTextLength, &dwWritten, NULL))
						bSuccess = TRUE;
				}
				GlobalFree(pszText);

				//ayonone(pszFileName,"medium");
				//ayontwo("medium",pszFileName);
			}
		}
		CloseHandle(hFile);
	}
	return bSuccess;
}

void DoFileOpen(HWND hwnd)
{
	OPENFILENAME ofn;
	char szFileName[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = "txt";

	if(GetOpenFileName(&ofn))
	{
		HWND hEdit = GetDlgItem(hwnd, IDC_MAIN_EDIT);
		LoadTextFileToEdit(hEdit, szFileName);
	}
}

void DoFileSave(HWND hwnd)
{
	OPENFILENAME ofn;
	char szFileName[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrDefExt = "cpp";
	ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;

	if(GetSaveFileName(&ofn))
	{
		HWND hEdit = GetDlgItem(hwnd, IDC_MAIN_EDIT);
		SaveTextFileFromEdit(hEdit, szFileName);
		//ayontwo(szFileName,"medium.txt");
		//ayonone("medium.txt",szFileName);
		//DoFileOpen(hwnd);
	}
}
void DoFileBeautify(HWND hwnd)
{
	OPENFILENAME ofn;
	char szFileName[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrDefExt = "cpp";
	ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;

	if(GetSaveFileName(&ofn))
	{
		HWND hEdit = GetDlgItem(hwnd, IDC_MAIN_EDIT);
		SaveTextFileFromEdit(hEdit, szFileName);
		ayonone(szFileName,"medium.txt");
		ayontwo("medium.txt",szFileName);
		DoFileOpen(hwnd);
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_CREATE:
		{
			HFONT hfDefault;
			HWND hEdit;

			hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", 
				WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, 
				0, 0, 100, 100, hwnd, (HMENU)IDC_MAIN_EDIT, GetModuleHandle(NULL), NULL);
			if(hEdit == NULL)
				MessageBox(hwnd, "Could not create edit box.", "Error", MB_OK | MB_ICONERROR);

			hfDefault = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
			SendMessage(hEdit, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(FALSE, 0));
		}
		break;
		case WM_SIZE:
		{
			HWND hEdit;
			RECT rcClient;

			GetClientRect(hwnd, &rcClient);

			hEdit = GetDlgItem(hwnd, IDC_MAIN_EDIT);
			SetWindowPos(hEdit, NULL, 0, 0, rcClient.right, rcClient.bottom, SWP_NOZORDER);
		}
		break;
		case WM_CLOSE:
			DestroyWindow(hwnd);
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
		break;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case ID_FILE_EXIT:
					PostMessage(hwnd, WM_CLOSE, 0, 0);
				break;
				case ID_FILE_NEW:
					SetDlgItemText(hwnd, IDC_MAIN_EDIT, "");
				break;
				case ID_FILE_OPEN:
					DoFileOpen(hwnd);
				break;
				case ID_FILE_SAVEAS:
					DoFileSave(hwnd);
				break;
				case ID_HELP_ABOUT:
					MessageBox(hwnd, "This is a simple C Code Beautifier developed by 0805013,0805006,0805003", "Thank you!", 
						MB_OK | MB_ICONINFORMATION);
				break;
				case ID_BEAUTIFY_BEAUTIFY:
					DoFileBeautify(hwnd);
				break;
				case ID_EDIT_CUT:
					//MessageBox(hwnd, "This resource is still to be developed", "Sorry!", 
						//MB_OK | MB_ICONINFORMATION);
					SendDlgItemMessage(hwnd, IDC_CHILD_EDIT, WM_CUT, 0, 0);
				break;
				case ID_EDIT_COPY:
					//MessageBox(hwnd, "This resource is still to be developed", "Sorry!", 
						//MB_OK | MB_ICONINFORMATION);
					SendDlgItemMessage(hwnd, IDC_CHILD_EDIT, WM_COPY, 0, 0);
				break;
				case ID_EDIT_PASTE:
					//MessageBox(hwnd, "This resource is still to be developed", "Sorry!", 
					//	MB_OK | MB_ICONINFORMATION);
					SendDlgItemMessage(hwnd, IDC_CHILD_EDIT, WM_PASTE, 0, 0);
				break;
			}
		break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.style		 = 0;
	wc.lpfnWndProc	 = WndProc;
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra	 = 0;
	wc.hInstance	 = hInstance;
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MAINMENU);
	wc.lpszClassName = g_szClassName;
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(
		0,
		g_szClassName,
		"C Code Beautifier",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 1024, 1024,
		NULL, NULL, hInstance, NULL);

	if(hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while(GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}
