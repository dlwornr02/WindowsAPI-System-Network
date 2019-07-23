#include <windows.h>
#define DIVISIONS 5

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

	hwnd = CreateWindow (szAppName, TEXT ("CopyDataB"),
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

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hwndChild[DIVISIONS][DIVISIONS];
	int         cxBlock, cyBlock, x, y ;

	switch (message)
	{
	case WM_CREATE :
		for (x = 0 ; x < DIVISIONS ; x++)
			for (y = 0 ; y < DIVISIONS ; y++)
				hwndChild[x][y] = CreateWindow (szChildClass, NULL,
				WS_CHILDWINDOW | WS_VISIBLE,
				0, 0, 0, 0,
				hwnd, (HMENU) (y << 8 | x)/*ID로 사용하려고 하위1바이트에는x 상위 1바이트에는 y*/,
				(HINSTANCE) GetWindowLong (hwnd, GWL_HINSTANCE),
				NULL) ;
		return 0 ;

	case WM_SIZE :
		cxBlock = LOWORD (lParam) / DIVISIONS ; //작은사각형의 width,height정함
		cyBlock = HIWORD (lParam) / DIVISIONS ;

		for (x = 0 ; x < DIVISIONS ; x++)
			for (y = 0 ; y < DIVISIONS ; y++)
				MoveWindow (hwndChild[x][y],  //윈도우를 보여준다.
				x * cxBlock, y * cyBlock,
				cxBlock, cyBlock, TRUE) ;
		return 0 ;

	case WM_LBUTTONDOWN : //main Window도 메세지 발생가능
		MessageBeep (0) ; 
		return 0 ;
	case WM_COPYDATA:
		{
			COPYDATASTRUCT* pcds = (COPYDATASTRUCT*)lParam;
			int x = LOWORD(pcds->dwData);
			int y = HIWORD(pcds->dwData);
			SetWindowLong(hwndChild[x][y],0,1^GetWindowLong(hwndChild[x][y],0));
			InvalidateRect(hwndChild[x][y],NULL,TRUE);
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
		SetWindowLong (hwnd, 0, 0) ;       // on/off flag
		return 0 ;

	case WM_LBUTTONDOWN :
		{
			COPYDATASTRUCT cds={0};
			int id = GetWindowLong(hwnd,GWL_ID);
			cds.dwData = MAKELONG(LOWORD(LOBYTE(id)),LOWORD(HIBYTE(id)));
			//TCHAR buf[100];
			//wsprintf(buf,TEXT("%d,%d"),LOBYTE(LOWORD(id)),HIBYTE(LOWORD(id)));
			//SetWindowText(GetParent(hwnd),buf);
			HWND hWndA = FindWindow(NULL,TEXT("CopyDataA"));
			if(hWndA)
				SendMessage(hWndA,WM_COPYDATA,0,(LPARAM)&cds);
		}
		SetWindowLong (hwnd, 0, 1 ^ GetWindowLong (hwnd, 0)) ;
		InvalidateRect (hwnd, NULL, FALSE) ;
		return 0 ;

	case WM_PAINT :
		hdc = BeginPaint (hwnd, &ps) ;

		GetClientRect (hwnd, &rect) ;
		Rectangle (hdc, 0, 0, rect.right, rect.bottom) ;

		if (GetWindowLong (hwnd, 0))//GetWindowLong (hwnd, 0) , extra메모리 사용
		{
			MoveToEx (hdc, 0,          0, NULL) ;
			LineTo   (hdc, rect.right, rect.bottom) ;
			MoveToEx (hdc, 0,          rect.bottom, NULL) ;
			LineTo   (hdc, rect.right, 0) ;
		}

		EndPaint (hwnd, &ps) ;
		return 0 ;
	}
	return DefWindowProc (hwnd, message, wParam, lParam) ;
}
