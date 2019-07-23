#include <windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
						 WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg, 
						 WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg, 
						 WPARAM wParam, LPARAM lParam);
HINSTANCE g_hInst;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
				   LPSTR lpszCmdLine, int nCmdShow)
{


	// 윈속 초기화
   WSADATA wsa;
   if(WSAStartup(MAKEWORD(2,2), &wsa) != 0) 
      return -1;

	g_hInst = hInstance;

	HWND 	 hwnd;
	MSG 	 msg;
	WNDCLASS WndClass;   
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;		
	WndClass.cbClsExtra	= 0;		
	WndClass.cbWndExtra	= 0;		
	WndClass.hInstance = hInstance;		
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
	WndClass.lpszMenuName = NULL;		
	WndClass.lpszClassName = "Window Class Name";	
	RegisterClass(&WndClass);

	WndClass.lpfnWndProc = TopProc;
	WndClass.lpszClassName = "TopWindow";
	RegisterClass(&WndClass);

	WndClass.lpfnWndProc = BottomProc;
	WndClass.lpszClassName = "BottomWindow";
	RegisterClass(&WndClass);
	hwnd = CreateWindow("Window Class Name",
		"GUI_TCP_Client",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,	
		CW_USEDEFAULT,	
		CW_USEDEFAULT,	
		CW_USEDEFAULT,	
		NULL,	
		NULL,	
		hInstance,	
		NULL	 
	);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);	
		DispatchMessage(&msg);	
	}   

	// 윈속 종료
	WSACleanup();

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
                         WPARAM wParam, LPARAM lParam) 
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	static HWND hTop,hBottom;
	switch (iMsg)
	{
    case WM_CREATE:
		hTop = CreateWindow("TopWindow",NULL,WS_VISIBLE | WS_CHILD,0,0,0,0,hwnd,(HMENU)1,((CREATESTRUCT*)lParam)->hInstance,NULL);
		hBottom = CreateWindow("BottomWindow",NULL,WS_VISIBLE | WS_CHILD,0,0,0,0,hwnd,(HMENU)2,((CREATESTRUCT*)lParam)->hInstance,NULL);
		break; 
	case WM_SIZE:
		{
			int cx = LOWORD(lParam);
			int cy = HIWORD(lParam);
			MoveWindow(hTop,0,0,cx,cy/2,TRUE);
			MoveWindow(hBottom,0,cy/2,cx,cy,TRUE);
		}
		break;
    case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		// 이곳에서 출력이 이루어짐
		EndPaint(hwnd, &ps);
		break; 
    case WM_DESTROY:
		PostQuitMessage(0);
		break; 
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg,
                         WPARAM wParam, LPARAM lParam)
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	RECT rt;
	switch (iMsg)
	{
    case WM_CREATE:
		CreateWindow("listbox",NULL,WS_VISIBLE | WS_CHILD | WS_BORDER,0,0,0,0,hwnd,(HMENU)1,g_hInst,NULL);
		CreateWindow("edit",NULL,WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,0,0,0,0,hwnd,(HMENU)2,g_hInst,NULL);
		CreateWindow("button","전송",WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON,0,0,0,0,hwnd,(HMENU)3,g_hInst,NULL);
		break;
	case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
			case 3:
				{
					TCHAR buf[300];
					GetWindowText(GetDlgItem(hwnd,2),buf,500);
					SetWindowText(GetDlgItem(hwnd,2),"");
					SetDlgItemText(GetDlgItem(hwnd,1),LB_ADDSTRING,buf);
				}
				break;
			}
		}
		break;
	case WM_SIZE:
		{
			int cx = LOWORD(lParam);
			int cy = HIWORD(lParam);
			MoveWindow(GetDlgItem(hwnd,1),0,0,cx,cy-50,TRUE);
			MoveWindow(GetDlgItem(hwnd,2),0,cy-40,cx-100,30,TRUE);
			MoveWindow(GetDlgItem(hwnd,3),cx-90,cy-40,75,30,TRUE);

		}
	case WM_PAINT:
		hdc = BeginPaint(hwnd,&ps);
		GetClientRect(hwnd,&rt);
		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
		EndPaint(hwnd,&ps);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);

}

LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg,
                         WPARAM wParam, LPARAM lParam)
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	RECT rt;
	switch (iMsg)
	{
    case WM_CREATE:
		break; 
	case WM_PAINT:
		hdc = BeginPaint(hwnd,&ps);
		GetClientRect(hwnd,&rt);
		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
		EndPaint(hwnd,&ps);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);

}