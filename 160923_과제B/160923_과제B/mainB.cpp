//
//
//#include <windows.h>
//#define DIVISIONS 5
//
//enum CDType
//{
//	CLICK, LOGIN, LOGREP
//};
//
//
//LRESULT CALLBACK WndProc   (HWND, UINT, WPARAM, LPARAM) ;
//LRESULT CALLBACK ChildWndProc (HWND, UINT, WPARAM, LPARAM) ;
//
//TCHAR szChildClass[] = TEXT ("Checker3_Child") ;
//
//int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
//	PSTR szCmdLine, int iCmdShow)
//{
//	static TCHAR szAppName[] = TEXT ("Checker3") ;
//	HWND         hwnd ;
//	MSG          msg ;
//	WNDCLASS     wndclass ;
//
//	wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
//	wndclass.lpfnWndProc   = WndProc ;
//	wndclass.cbClsExtra    = 0 ;
//	wndclass.cbWndExtra    = 0 ;
//	wndclass.hInstance     = hInstance ;
//	wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
//	wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
//	wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
//	wndclass.lpszMenuName  = NULL ;
//	wndclass.lpszClassName = szAppName ;
//
//	if (!RegisterClass (&wndclass))
//	{
//		MessageBox (NULL, TEXT ("Program requires Windows NT!"), 
//			szAppName, MB_ICONERROR) ;
//		return 0 ;
//	}
//
//	wndclass.lpfnWndProc   = ChildWndProc ;
//	wndclass.cbWndExtra    = sizeof (long) ;
//	wndclass.hIcon         = NULL ;
//	wndclass.lpszClassName = szChildClass ;
//
//	RegisterClass (&wndclass) ;
//
//	hwnd = CreateWindow (szAppName, TEXT("CopyDataB"),
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, CW_USEDEFAULT,
//		CW_USEDEFAULT, CW_USEDEFAULT,
//		NULL, NULL, hInstance, NULL) ;
//
//	ShowWindow (hwnd, iCmdShow) ;
//	UpdateWindow (hwnd) ;
//
//	while (GetMessage (&msg, NULL, 0, 0))
//	{
//		TranslateMessage (&msg) ;
//		DispatchMessage (&msg) ;
//	}
//	return msg.wParam ;
//}
//void SendMessageCopyData(HWND hwnd, PCOPYDATASTRUCT pcds)
//{
//	HWND hWndA = FindWindow(NULL, TEXT("CopyDataA"));
//	if( hWndA )
//		SendMessage(hWndA, WM_COPYDATA, (WPARAM)hwnd, (LPARAM)pcds);
//}
//LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	static HWND hwndChild[DIVISIONS][DIVISIONS] ;
//	int         cxBlock, cyBlock, x, y ;
//
//	switch (message)
//	{
//	case WM_CREATE :
//		for (x = 0 ; x < DIVISIONS ; x++)
//			for (y = 0 ; y < DIVISIONS ; y++)
//				hwndChild[x][y] = CreateWindow (szChildClass, NULL,
//				WS_CHILDWINDOW | WS_VISIBLE,
//				0, 0, 0, 0,
//				hwnd, (HMENU) (y << 8 | x),
//				(HINSTANCE) GetWindowLong (hwnd, GWL_HINSTANCE),
//				NULL) ;
//		{
//			COPYDATASTRUCT cds={0};
//			cds.dwData = LOGIN;
//			SendMessageCopyData(hwnd, &cds);
//		}
//		return 0 ;
//
//	case WM_SIZE :
//		cxBlock = LOWORD (lParam) / DIVISIONS ;
//		cyBlock = HIWORD (lParam) / DIVISIONS ;
//
//		for (x = 0 ; x < DIVISIONS ; x++)
//			for (y = 0 ; y < DIVISIONS ; y++)
//				MoveWindow (hwndChild[x][y],
//				x * cxBlock, y * cyBlock,
//				cxBlock, cyBlock, TRUE) ;
//		return 0 ;
//
//	case WM_LBUTTONDOWN :
//		MessageBeep (0) ;
//		return 0 ;
//	case WM_COPYDATA:
//		{
//			COPYDATASTRUCT* pcds = (COPYDATASTRUCT*)lParam;
//			switch(pcds->dwData)
//			{
//			case CLICK:
//				{
//					int x = LOWORD(*(long*)pcds->lpData);
//					int y = HIWORD(*(long*)pcds->lpData);
//					SetWindowLong(hwndChild[x][y],0, 
//						1^GetWindowLong(hwndChild[x][y],0));
//					InvalidateRect(hwndChild[x][y], NULL, TRUE);
//				}
//				break;
//			case LOGIN:
//				{
//					COPYDATASTRUCT cds = {0};
//					char stateArray[DIVISIONS][DIVISIONS];
//					for(int x = 0;x<DIVISIONS;x++)
//						for(int y = 0;y<DIVISIONS;y++)
//							stateArray[x][y] = (char)GetWindowLong(hwndChild[x][y],0);
//					cds.dwData = LOGREP;
//					cds.lpData = stateArray;
//					cds.cbData = sizeof(stateArray);
//					SendMessage((HWND)wParam, WM_COPYDATA,
//						(WPARAM)hwnd, (LPARAM)&cds);
//				}
//				break;
//			case LOGREP:
//				{
//					char (*stateArray)[DIVISIONS];
//					stateArray = (char(*)[DIVISIONS])pcds->lpData;
//					for(int x = 0;x<DIVISIONS;x++)
//						for(int y = 0;y<DIVISIONS;y++)
//							SetWindowLong(hwndChild[x][y],0,stateArray[x][y]);
//				}
//				break;
//			}			
//		}
//		break;
//
//	case WM_DESTROY :
//		PostQuitMessage (0) ;
//		return 0 ;
//	}
//	return DefWindowProc (hwnd, message, wParam, lParam) ;
//}
//
//LRESULT CALLBACK ChildWndProc (HWND hwnd, UINT message, 
//	WPARAM wParam, LPARAM lParam)
//{
//	HDC         hdc ;
//	PAINTSTRUCT ps ;
//	RECT        rect ;
//
//	switch (message)
//	{
//	case WM_CREATE :
//		SetWindowLong (hwnd, 0, 0) ;       // on/off flag
//		return 0 ;
//
//	case WM_LBUTTONDOWN :
//		{
//			COPYDATASTRUCT cds={0};
//			DWORD id = GetWindowLong(hwnd, GWL_ID);
//			cds.dwData = CLICK;
//			long pos = MAKELONG(LOWORD(LOBYTE(id)), LOWORD(HIBYTE(id)));
//			cds.lpData = &pos;
//			cds.cbData = sizeof(pos);
//
//			SendMessageCopyData(GetParent(hwnd), &cds);
//		}
//		SetWindowLong (hwnd, 0, 1 ^ GetWindowLong (hwnd, 0));
//		InvalidateRect (hwnd, NULL, FALSE) ;
//		return 0 ;
//
//	case WM_PAINT :
//		hdc = BeginPaint (hwnd, &ps) ;
//
//		GetClientRect (hwnd, &rect) ;
//		Rectangle (hdc, 0, 0, rect.right, rect.bottom) ;
//
//		if (GetWindowLong (hwnd, 0))
//		{
//			MoveToEx (hdc, 0,          0, NULL) ;
//			LineTo   (hdc, rect.right, rect.bottom) ;
//			MoveToEx (hdc, 0,          rect.bottom, NULL) ;
//			LineTo   (hdc, rect.right, 0) ;
//		}
//
//		EndPaint (hwnd, &ps) ;
//		return 0 ;
//	}
//	return DefWindowProc (hwnd, message, wParam, lParam) ;
//}


#include <windows.h>
#define DIVISIONS 5

enum CDType
{
	CLICK, LOGIN, LOGREP
};


LRESULT CALLBACK WndProc   (HWND, UINT, WPARAM, LPARAM) ;
LRESULT CALLBACK ChildWndProc (HWND, UINT, WPARAM, LPARAM) ;

TCHAR szChildClass[] = TEXT ("Checker3_Child") ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT ("Checker3") ;
	HWND         hwnd ;
	MSG          msg ;
	WNDCLASS     wndclass ;

	wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
	wndclass.lpfnWndProc   = WndProc ;
	wndclass.cbClsExtra    = 0 ;
	wndclass.cbWndExtra    = 0 ;
	wndclass.hInstance     = hInstance ;
	wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
	wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
	wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
	wndclass.lpszMenuName  = NULL ;
	wndclass.lpszClassName = szAppName ;

	if (!RegisterClass (&wndclass))
	{
		MessageBox (NULL, TEXT ("Program requires Windows NT!"), 
			szAppName, MB_ICONERROR) ;
		return 0 ;
	}

	wndclass.lpfnWndProc   = ChildWndProc ;
	wndclass.cbWndExtra    = sizeof (long) ;
	wndclass.hIcon         = NULL ;
	wndclass.lpszClassName = szChildClass ;

	RegisterClass (&wndclass) ;

	hwnd = CreateWindow (szAppName, TEXT("CopyDataB"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL) ;

	ShowWindow (hwnd, iCmdShow) ;
	UpdateWindow (hwnd) ;

	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg) ;
		DispatchMessage (&msg) ;
	}
	return msg.wParam ;
}
void SendMessageCopyData(HWND hwnd, PCOPYDATASTRUCT pcds)
{
	HWND hWndA = FindWindow(NULL, TEXT("CopyDataA"));
	if( hWndA )
	{
		SendMessage(hWndA, WM_COPYDATA, (WPARAM)hwnd, (LPARAM)pcds);
	}
}
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hwndChild[DIVISIONS][DIVISIONS] ;
	int         cxBlock, cyBlock, x, y ;

	switch (message)
	{
	case WM_CREATE :
		for (x = 0 ; x < DIVISIONS ; x++)
			for (y = 0 ; y < DIVISIONS ; y++)
				hwndChild[x][y] = CreateWindow (szChildClass, NULL,
				WS_CHILDWINDOW | WS_VISIBLE,
				0, 0, 0, 0,
				hwnd, (HMENU) (y << 8 | x),
				(HINSTANCE) GetWindowLong (hwnd, GWL_HINSTANCE),
				NULL) ;
		{
			COPYDATASTRUCT cds={0};
			cds.dwData = LOGIN;
			SendMessageCopyData(hwnd, &cds);
		}
		return 0 ;

	case WM_SIZE :
		cxBlock = LOWORD (lParam) / DIVISIONS ;
		cyBlock = HIWORD (lParam) / DIVISIONS ;

		for (x = 0 ; x < DIVISIONS ; x++)
			for (y = 0 ; y < DIVISIONS ; y++)
				MoveWindow (hwndChild[x][y],
				x * cxBlock, y * cyBlock,
				cxBlock, cyBlock, TRUE) ;
		return 0 ;

	case WM_LBUTTONDOWN :
		MessageBeep (0) ;
		return 0 ;
	case WM_COPYDATA:
		{
			COPYDATASTRUCT* pcds = (COPYDATASTRUCT*)lParam;
			switch(pcds->dwData)
			{
			case CLICK:
				{
					int x = LOWORD(*(long*)pcds->lpData);
					int y = HIWORD(*(long*)pcds->lpData);
					SetWindowLong(hwndChild[x][y],0, 
						GetWindowLong(hwndChild[x][y],0));
					SendMessage(hwndChild[x][y], WM_LBUTTONDOWN, (WPARAM)hwnd, (LPARAM)pcds);
					InvalidateRect(hwndChild[x][y], NULL, TRUE);
				}
				break;
			case LOGIN:
				{
					COPYDATASTRUCT cds = {0};
					char stateArray[DIVISIONS][DIVISIONS];
					for(int x = 0;x<DIVISIONS;x++)
						for(int y = 0;y<DIVISIONS;y++)
							stateArray[x][y] = (char)GetWindowLong(hwndChild[x][y],0);
					cds.dwData = LOGREP;
					cds.lpData = stateArray;
					cds.cbData = sizeof(stateArray);
					SendMessage((HWND)wParam, WM_COPYDATA,
						(WPARAM)hwnd, (LPARAM)&cds);
				}
				break;
			case LOGREP:
				{
					char (*stateArray)[DIVISIONS];
					stateArray = (char(*)[DIVISIONS])pcds->lpData;
					for(int x = 0;x<DIVISIONS;x++)
						for(int y = 0;y<DIVISIONS;y++)
							SetWindowLong(hwndChild[x][y],0,stateArray[x][y]);
				}
				break;
			}			
		}
		break;

	case WM_DESTROY :
		PostQuitMessage (0) ;
		return 0 ;
	}
	return DefWindowProc (hwnd, message, wParam, lParam) ;
}

LRESULT CALLBACK ChildWndProc (HWND hwnd, UINT message, 
	WPARAM wParam, LPARAM lParam)
{
	HDC         hdc ;
	PAINTSTRUCT ps ;
	RECT        rect ;

	switch (message)
	{
	case WM_CREATE :
		SetWindowLong (hwnd, 0, -1) ;       // on/off flag
		return 0 ;
	case WM_LBUTTONDOWN :
		{
			int count = (GetWindowLong (hwnd, 0)+1);
			COPYDATASTRUCT cds={0};
			DWORD id = GetWindowLong(hwnd, GWL_ID);
			cds.dwData = CLICK;
			long pos = MAKELONG(LOWORD(LOBYTE(id)), LOWORD(HIBYTE(id)));
			cds.lpData = &pos;
			cds.cbData = sizeof(pos);

			SendMessageCopyData(GetParent(hwnd), &cds);

			SetWindowLong (hwnd, 0, count) ;
			InvalidateRect (hwnd, NULL, TRUE) ;
			return 0 ;
		}
	case WM_PAINT :
		{
			COLORREF color = NULL;
			hdc = BeginPaint (hwnd, &ps) ;
			GetClientRect (hwnd, &rect) ;


			if (GetWindowLong (hwnd, 0)%3==0)
			{
				color = RGB(255,0,0);
			}
			else if (GetWindowLong (hwnd, 0)%3==1)
			{
				color = RGB(0,255,0);
			}
			else if (GetWindowLong (hwnd, 0)%3==2)
			{
				color = RGB(0,0,255);
			}
			else
			{
				color = RGB(255,255,255);
			}
			HBRUSH newBrush = CreateSolidBrush(color);
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc,newBrush);
			Rectangle (hdc, 0, 0, rect.right, rect.bottom) ;
			TCHAR buf[100];
			wsprintf(buf,TEXT("%d"),(GetWindowLong(hwnd,0)+1));
			DrawText(hdc,buf,lstrlen(buf),&rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			oldBrush = (HBRUSH)SelectObject(hdc,newBrush);
			DeleteObject(newBrush);
			EndPaint (hwnd, &ps) ;
			return 0 ;
		}
	}
	return DefWindowProc (hwnd, message, wParam, lParam) ;
}