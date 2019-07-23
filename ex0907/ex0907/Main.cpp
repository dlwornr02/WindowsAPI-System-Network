#include <windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
						 WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
				   LPSTR lpszCmdLine, int nCmdShow)
{
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
	hwnd = CreateWindow("Window Class Name",
		"Window Title Name",
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
	return (int)msg.wParam;
}

void DrawX(HDC hdc, int cx, int cy)
{
	HPEN hNewPen = CreatePen(PS_SOLID, 2, RGB(255,0,0));
	HPEN hOldPen = (HPEN)SelectObject(hdc, hNewPen);

	MoveToEx(hdc, 0,0, NULL);
	LineTo(hdc, cx, cy);
	MoveToEx(hdc, cx, 0, NULL);
	LineTo(hdc, 0, cy);

	SelectObject(hdc, hOldPen);
	DeleteObject(hNewPen);
}
void DrawRect(HDC hdc, RECT rt)
{
	HPEN hNewPen = CreatePen(PS_SOLID, 2, RGB(0,0,255));
	HPEN hOldPen = (HPEN)SelectObject(hdc, hNewPen);
	HBRUSH hNewBrush = CreateSolidBrush(RGB(255,255,0));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hNewBrush);

	Rectangle(hdc, rt.left,rt.top,rt.right,rt.bottom);

	SelectObject(hdc, hOldPen);
	SelectObject(hdc, hOldBrush);
	DeleteObject(hNewPen);
	DeleteObject(hOldBrush);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
                         WPARAM wParam, LPARAM lParam) 
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	static int cx, cy;
	static RECT rt;

	switch (iMsg)
	{
    case WM_CREATE:
		break; 
	case WM_SIZE:
		cx = LOWORD(lParam);
		cy = HIWORD(lParam);
		rt.left = cx/4;
		rt.top = cy/4;
		rt.right = cx/4 * 3;
		rt.bottom = cy/4 * 3;
		break;
    case WM_PAINT:
		{
			hdc = BeginPaint(hwnd, &ps);			

			DrawX(hdc, cx, cy);
			DrawRect(hdc, rt);

			SetTextColor(hdc, RGB(0,255,0));
			SetBkColor(hdc, RGB(0,255,255));
			DrawText(hdc, "Hello!", -1, &rt, DT_CENTER|DT_VCENTER|DT_SINGLELINE); 

			EndPaint(hwnd, &ps);
		}
		break; 
    case WM_DESTROY:
		PostQuitMessage(0);
		break; 
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//void DrawX(HDC hdc, int cx, int cy)
//{
//	HPEN hNewPen = CreatePen(PS_SOLID, 2, RGB(255,0,0));
//	HPEN hOldPen = (HPEN)SelectObject(hdc, hNewPen);
//
//	MoveToEx(hdc, 0,0, NULL);
//	LineTo(hdc, cx, cy);
//	MoveToEx(hdc, cx, 0, NULL);
//	LineTo(hdc, 0, cy);
//
//	SelectObject(hdc, hOldPen);
//	DeleteObject(hNewPen);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int cx, cy;
//	static RECT rt;
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_SIZE:
//		cx = LOWORD(lParam);
//		cy = HIWORD(lParam);
//		rt.left = cx/4;
//		rt.top = cy/4;
//		rt.right = cx/4 * 3;
//		rt.bottom = cy/4 * 3;
//		break;
//    case WM_PAINT:
//		{
//			hdc = BeginPaint(hwnd, &ps);			
//
//			DrawX(hdc, cx, cy);
//			Rectangle(hdc, rt.left,rt.top,rt.right,rt.bottom);
//			DrawText(hdc, "Hello!", -1, &rt, DT_CENTER|DT_VCENTER|DT_SINGLELINE); 
//
//			EndPaint(hwnd, &ps);
//		}
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//void DrawX(HDC hdc, int cx, int cy)
//{
//	MoveToEx(hdc, 0,0, NULL);
//	LineTo(hdc, cx, cy);
//	MoveToEx(hdc, cx, 0, NULL);
//	LineTo(hdc, 0, cy);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int cx, cy;
//	static RECT rt;
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_SIZE:
//		cx = LOWORD(lParam);
//		cy = HIWORD(lParam);
//		rt.left = cx/4;
//		rt.top = cy/4;
//		rt.right = cx/4 * 3;
//		rt.bottom = cy/4 * 3;
//		break;
//    case WM_PAINT:
//		{
//			hdc = BeginPaint(hwnd, &ps);
//			HPEN hNewPen = CreatePen(PS_SOLID, 2, RGB(255,0,0));
//			HPEN hOldPen = (HPEN)SelectObject(hdc, hNewPen);
//
//			DrawX(hdc, cx, cy);
//			Rectangle(hdc, rt.left,rt.top,rt.right,rt.bottom);
//			DrawText(hdc, "Hello!", -1, &rt, DT_CENTER|DT_VCENTER|DT_SINGLELINE); 
//
//			SelectObject(hdc, hOldPen);
//			DeleteObject(hNewPen);
//			EndPaint(hwnd, &ps);
//		}
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//void DrawX(HDC hdc, int cx, int cy)
//{
//	MoveToEx(hdc, 0,0, NULL);
//	LineTo(hdc, cx, cy);
//	MoveToEx(hdc, cx, 0, NULL);
//	LineTo(hdc, 0, cy);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int cx, cy;
//	static RECT rt;
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_SIZE:
//		cx = LOWORD(lParam);
//		cy = HIWORD(lParam);
//		rt.left = cx/4;
//		rt.top = cy/4;
//		rt.right = cx/4 * 3;
//		rt.bottom = cy/4 * 3;
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawX(hdc, cx, cy);
//		Rectangle(hdc, rt.left,rt.top,rt.right,rt.bottom);
//		DrawText(hdc, "Hello!", -1, &rt, DT_CENTER|DT_VCENTER|DT_SINGLELINE); 
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int cx, cy;
//	static RECT rt;
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_SIZE:
//		cx = LOWORD(lParam);
//		cy = HIWORD(lParam);
//		rt.left = cx/4;
//		rt.top = cy/4;
//		rt.right = cx/4 * 3;
//		rt.bottom = cy/4 * 3;
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		Rectangle(hdc, rt.left,rt.top,rt.right,rt.bottom);
//		DrawText(hdc, "Hello!", -1, &rt, DT_CENTER|DT_VCENTER|DT_SINGLELINE); 
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//void CALLBACK TimerProc(HWND hwnd, UINT msg, UINT id, DWORD time);
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static bool bTimer = false;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		srand( GetTickCount() );		
//		break; 
//	case WM_LBUTTONDOWN:
//		if( bTimer == false )
//		{
//			SetTimer(hwnd, 1, 100, TimerProc);
//			SetTimer(hwnd, 2, 300, TimerProc);
//		}
//		else
//		{
//			KillTimer(hwnd, 1);
//			KillTimer(hwnd, 2);
//		}
//		bTimer ^= true;
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//void CALLBACK TimerProc(HWND hwnd, UINT msg, UINT id, DWORD time)
//{
//	RECT clientRt;
//	GetClientRect(hwnd, &clientRt);
//	int w = clientRt.right;
//	int h = clientRt.bottom;
//	RECT rt = { rand()%w, rand()%h, rand()%w, rand()%h };
//	HDC hdc = GetDC(hwnd);
//
//	if( id == 1 )
//		Rectangle(hdc, rt.left,rt.top, rt.right, rt.bottom);
//	else 
//		Ellipse(hdc, rt.left,rt.top, rt.right, rt.bottom);
//	ReleaseDC(hwnd, hdc);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static bool bTimer = false;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		srand( GetTickCount() );		
//		break; 
//	case WM_LBUTTONDOWN:
//		if( bTimer == false )
//		{
//			SetTimer(hwnd, 1, 100, NULL);
//			SetTimer(hwnd, 2, 300, NULL);
//		}
//		else
//		{
//			KillTimer(hwnd, 1);
//			KillTimer(hwnd, 2);
//		}
//		bTimer ^= true;
//		break;
//
//	case WM_TIMER:
//		{
//			RECT clientRt;
//			GetClientRect(hwnd, &clientRt);
//			int w = clientRt.right;
//			int h = clientRt.bottom;
//			RECT rt = { rand()%w, rand()%h, rand()%w, rand()%h };
//			hdc = GetDC(hwnd);
//
//			if( wParam == 1 )
//				Rectangle(hdc, rt.left,rt.top, rt.right, rt.bottom);
//			else 
//				Ellipse(hdc, rt.left,rt.top, rt.right, rt.bottom);
//			ReleaseDC(hwnd, hdc);
//		}
//		break;
//
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static bool bTimer = false;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		srand( GetTickCount() );		
//		break; 
//	case WM_LBUTTONDOWN:
//		if( bTimer == false )
//		{
//			SetTimer(hwnd, 1, 100, NULL);
//			SetTimer(hwnd, 2, 300, NULL);
//			bTimer = true;
//		}
//		else
//		{
//			KillTimer(hwnd, 1);
//			KillTimer(hwnd, 2);
//			bTimer = false;
//		}
//		break;
//
//	case WM_TIMER:
//		{
//			RECT clientRt;
//			GetClientRect(hwnd, &clientRt);
//			int w = clientRt.right;
//			int h = clientRt.bottom;
//			RECT rt = { rand()%w, rand()%h, rand()%w, rand()%h };
//			hdc = GetDC(hwnd);
//
//			if( wParam == 1 )
//				Rectangle(hdc, rt.left,rt.top, rt.right, rt.bottom);
//			else 
//				Ellipse(hdc, rt.left,rt.top, rt.right, rt.bottom);
//			ReleaseDC(hwnd, hdc);
//		}
//		break;
//
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		srand( GetTickCount() );
//		SetTimer(hwnd, 1, 100, NULL);
//		SetTimer(hwnd, 2, 300, NULL);
//		break; 
//
//	case WM_TIMER:
//		{
//			RECT clientRt;
//			GetClientRect(hwnd, &clientRt);
//			int w = clientRt.right;
//			int h = clientRt.bottom;
//			RECT rt = { rand()%w, rand()%h, rand()%w, rand()%h };
//			hdc = GetDC(hwnd);
//
//			if( wParam == 1 )
//				Rectangle(hdc, rt.left,rt.top, rt.right, rt.bottom);
//			else 
//				Ellipse(hdc, rt.left,rt.top, rt.right, rt.bottom);
//			ReleaseDC(hwnd, hdc);
//		}
//		break;
//
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		KillTimer(hwnd, 1);
//		KillTimer(hwnd, 2);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		srand( GetTickCount() );
//		SetTimer(hwnd, 1, 100, NULL);
//		SetTimer(hwnd, 2, 300, NULL);
//		break; 
//
//	case WM_TIMER:
//		{
//			RECT clientRt;
//			GetClientRect(hwnd, &clientRt);
//			int w = clientRt.right;
//			int h = clientRt.bottom;
//			RECT rt = { rand()%w, rand()%h, rand()%w, rand()%h };
//			hdc = GetDC(hwnd);
//
//			if( wParam == 1 )
//				Rectangle(hdc, rt.left,rt.top, rt.right, rt.bottom);
//			else 
//				Ellipse(hdc, rt.left,rt.top, rt.right, rt.bottom);
//			ReleaseDC(hwnd, hdc);
//		}
//		break;
//
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		KillTimer(hwnd, 1);
//		KillTimer(hwnd, 2);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		SetTimer(hwnd, 1, 100, NULL);
//		SetTimer(hwnd, 2, 300, NULL);
//		break; 
//
//	case WM_TIMER:
//		{
//			RECT clientRt;
//			GetClientRect(hwnd, &clientRt);
//			int w = clientRt.right;
//			int h = clientRt.bottom;
//			RECT rt = { rand()%w, rand()%h, rand()%w, rand()%h };
//			hdc = GetDC(hwnd);
//
//			if( wParam == 1 )
//				Rectangle(hdc, rt.left,rt.top, rt.right, rt.bottom);
//			else 
//				Ellipse(hdc, rt.left,rt.top, rt.right, rt.bottom);
//			ReleaseDC(hwnd, hdc);
//		}
//		break;
//
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		KillTimer(hwnd, 1);
//		KillTimer(hwnd, 2);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		SetTimer(hwnd, 1, 100, NULL);
//		break; 
//
//	case WM_TIMER:
//		{
//			RECT clientRt;
//			GetClientRect(hwnd, &clientRt);
//			int w = clientRt.right;
//			int h = clientRt.bottom;
//			RECT rt = { rand()%w, rand()%h, rand()%w, rand()%h };
//			hdc = GetDC(hwnd);
//			Rectangle(hdc, rt.left,rt.top, rt.right, rt.bottom);
//			ReleaseDC(hwnd, hdc);
//		}
//		break;
//
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		KillTimer(hwnd, 1);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//#include <list>
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//void MoveRectangle(list<RECT>& rtList, int dx, int dy)
//{
//	for(list<RECT>::iterator iter= rtList.begin(); iter != rtList.end();
//		++iter)
//	{
//		iter->left += dx;
//		iter->right += dx;
//		iter->top += dy;
//		iter->bottom += dy;
//	}
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rt;
//	static list<RECT> rtList;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_KEYDOWN:
//		switch(wParam)
//		{
//			case VK_LEFT:
//				MoveRectangle(rtList, -5, 0);
//				break;
//			case VK_RIGHT:
//				MoveRectangle(rtList, 5, 0);
//				break;
//			case VK_UP:
//				MoveRectangle(rtList, 0, -5);
//				break;
//			case VK_DOWN:
//				MoveRectangle(rtList, 0, 5);
//				break;
//			case VK_RETURN:
//				rtList.clear();
//				break;
//		}
//		InvalidateRect(hwnd, NULL, TRUE);
//		break;
//	case WM_LBUTTONDOWN:
//		SetCapture(hwnd);
//
//		rt.left = (short)LOWORD(lParam);
//		rt.top = (short)HIWORD(lParam);		
//		break;
//	case WM_LBUTTONUP:
//		ReleaseCapture();
//
//		rt.right = (short)LOWORD(lParam);
//		rt.bottom = (short)HIWORD(lParam);
//		rtList.push_back( rt );
//
//		hdc = GetDC(hwnd);
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		ReleaseDC(hwnd, hdc);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		for(list<RECT>::iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//		{
//			const RECT& rt = *iter;
//			Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		}
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//#include <list>
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//void MoveRectangle(list<RECT>& rtList, int dx, int dy)
//{
//	for(list<RECT>::iterator iter= rtList.begin(); iter != rtList.end();
//		++iter)
//	{
//		iter->left += dx;
//		iter->right += dx;
//		iter->top += dy;
//		iter->bottom += dy;
//	}
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rt;
//	static list<RECT> rtList;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_KEYDOWN:
//		switch(wParam)
//		{
//			case VK_LEFT:
//				MoveRectangle(rtList, -5, 0);
//				break;
//			case VK_RIGHT:
//				MoveRectangle(rtList, 5, 0);
//				break;
//			case VK_UP:
//				MoveRectangle(rtList, 0, -5);
//				break;
//			case VK_DOWN:
//				MoveRectangle(rtList, 0, 5);
//				break;
//			case VK_RETURN:
//				rtList.clear();
//				break;
//		}
//		InvalidateRect(hwnd, NULL, TRUE);
//		break;
//	case WM_LBUTTONDOWN:
//		SetCapture(hwnd);
//
//		rt.left = (short)LOWORD(lParam);
//		rt.top = (short)HIWORD(lParam);		
//		break;
//	case WM_LBUTTONUP:
//		ReleaseCapture();
//
//		rt.right = (short)LOWORD(lParam);
//		rt.bottom = (short)HIWORD(lParam);
//		rtList.push_back( rt );
//
//		hdc = GetDC(hwnd);
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		ReleaseDC(hwnd, hdc);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		for(list<RECT>::iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//		{
//			const RECT& rt = *iter;
//			Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		}
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}



//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	TCHAR buf[100];
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_KEYDOWN:
//		wsprintf(buf,"keydown:%c,%d\n", wParam, wParam);
//		OutputDebugString(buf);
//		break;
//	case WM_KEYUP:
//		wsprintf(buf,"keyup:%c,%d\n", wParam, wParam);
//		OutputDebugString(buf);
//		break;
//	case WM_CHAR:
//		wsprintf(buf,"char:%c,%d\n", wParam, wParam);
//		OutputDebugString(buf);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}


//#include <windows.h>
//#include <list>
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rt;
//	static list<RECT> rtList;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		SetCapture(hwnd);
//
//		rt.left = (short)LOWORD(lParam);
//		rt.top = (short)HIWORD(lParam);		
//		break;
//	case WM_LBUTTONUP:
//		ReleaseCapture();
//
//		rt.right = (short)LOWORD(lParam);
//		rt.bottom = (short)HIWORD(lParam);
//		rtList.push_back( rt );
//
//		hdc = GetDC(hwnd);
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		ReleaseDC(hwnd, hdc);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		for(list<RECT>::iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//		{
//			const RECT& rt = *iter;
//			Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		}
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//#include <list>
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rt;
//	static list<RECT> rtList;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		SetCapture(hwnd);
//
//		rt.left = (short)LOWORD(lParam);
//		rt.top = (short)HIWORD(lParam);		
//		break;
//	case WM_LBUTTONUP:
//		ReleaseCapture();
//
//		rt.right = (short)LOWORD(lParam);
//		rt.bottom = (short)HIWORD(lParam);
//		rtList.push_back( rt );
//
//		hdc = GetDC(hwnd);
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		ReleaseDC(hwnd, hdc);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		for(list<RECT>::iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//		{
//			const RECT& rt = *iter;
//			Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		}
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rt;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		rt.left = (short)LOWORD(lParam);
//		rt.top = (short)HIWORD(lParam);
//
//		SetCapture(hwnd);
//		break;
//	case WM_LBUTTONUP:
//		ReleaseCapture();
//
//		rt.right = (short)LOWORD(lParam);
//		rt.bottom = (short)HIWORD(lParam);
//		hdc = GetDC(hwnd);
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		ReleaseDC(hwnd, hdc);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rt;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		rt.left = LOWORD(lParam);
//		rt.top = HIWORD(lParam);
//
//		SetCapture(hwnd);
//		break;
//	case WM_LBUTTONUP:
//		ReleaseCapture();
//
//		rt.right = LOWORD(lParam);
//		rt.bottom = HIWORD(lParam);
//		hdc = GetDC(hwnd);
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		ReleaseDC(hwnd, hdc);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rt;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		rt.left = LOWORD(lParam);
//		rt.top = HIWORD(lParam);
//
//		SetCapture(hwnd);
//		break;
//	case WM_LBUTTONUP:
//		ReleaseCapture();
//
//		rt.right = LOWORD(lParam);
//		rt.bottom = HIWORD(lParam);
//		hdc = GetDC(hwnd);
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		ReleaseDC(hwnd, hdc);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rt;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		rt.left = LOWORD(lParam);
//		rt.top = HIWORD(lParam);
//		break;
//	case WM_LBUTTONUP:
//		rt.right = LOWORD(lParam);
//		rt.bottom = HIWORD(lParam);
//		hdc = GetDC(hwnd);
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		ReleaseDC(hwnd, hdc);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_MOUSEMOVE:
//		if( wParam&MK_SHIFT && wParam&MK_CONTROL )
//		{
//			POINT pt = { LOWORD(lParam), HIWORD(lParam) };
//			TCHAR buf[100];
//			wsprintf(buf,"(%d,%d)", pt.x, pt.y);
//			hdc = GetDC(hwnd);
//			TextOut(hdc, pt.x, pt.y, buf, lstrlen(buf));
//			ReleaseDC(hwnd, hdc);
//		}
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_MOUSEMOVE:
//		{
//			POINT pt = { LOWORD(lParam), HIWORD(lParam) };
//			TCHAR buf[100];
//			wsprintf(buf,"(%d,%d)", pt.x, pt.y);
//			hdc = GetDC(hwnd);
//			TextOut(hdc, pt.x, pt.y, buf, lstrlen(buf));
//			ReleaseDC(hwnd, hdc);
//		}
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONUP:
//		{
//			POINT pt = { LOWORD(lParam), HIWORD(lParam) };
//			TCHAR buf[100];
//			wsprintf(buf,"(%d,%d)", pt.x, pt.y);
//			hdc = GetDC(hwnd);
//			TextOut(hdc, pt.x, pt.y, buf, lstrlen(buf));
//			ReleaseDC(hwnd, hdc);
//		}
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"Window Title Name",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONUP:
//		{
//			POINT pt = { LOWORD(lParam), HIWORD(lParam) };
//			hdc = GetDC(hwnd);
//			TextOut(hdc, pt.x, pt.y, "A", 1 );
//			ReleaseDC(hwnd, hdc);
//		}
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}


//#include <windows.h>
//#include <vector>
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "W";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("W",
//		"Title",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//void DrawOrigin(HDC hdc, POINT pt)
//{
//	MoveToEx(hdc, pt.x, pt.y-20, NULL);
//	LineTo(hdc,  pt.x, pt.y+20);
//	MoveToEx(hdc, pt.x-20, pt.y, NULL);
//	LineTo(hdc,  pt.x+20, pt.y);
//}
//int DistanceOriginToPoint(POINT origin, POINT pt)
//{
//	int width = origin.x-pt.x;
//	int height = origin.y-pt.y;
//	return width*width + height*height;
//}
//POINT FindMinPoint(POINT origin, const vector<POINT>& ptList)
//{
//	POINT minPoint={10000,10000};
//	for(unsigned i = 0 ; i < ptList.size() ; ++i)
//	{
//		int distance = DistanceOriginToPoint(origin, ptList[i]);
//		if(distance < DistanceOriginToPoint(origin, minPoint) )
//			minPoint = ptList[i];
//	}
//
//	return minPoint;
//}
//void DrawMinPoint(HDC hdc, POINT pt)
//{
//	TextOut(hdc, pt.x, pt.y, "Hello!", strlen("Hello!"));
//}
//void DrawPointList(HDC hdc, const vector<POINT>& ptList)
//{
//	for(unsigned i = 0 ; i < ptList.size(); ++i)
//			TextOut(hdc,ptList[i].x, ptList[i].y, "Hello!", strlen("Hello!"));
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam)
//{
//	HDC			hdc;
//	PAINTSTRUCT ps;
//	static	vector<POINT> ptList;
//	static POINT origin;
//	static POINT minPoint = { -1000, -1000 };
//	RECT clientRect;
//
//	switch (iMsg) 
//	{
//	case WM_CREATE:
//		break; 
//	case WM_SIZE:
//		GetClientRect(hwnd, &clientRect);
//		origin.x = clientRect.right/2;
//		origin.y = clientRect.bottom/2;
//		break;
//	case WM_LBUTTONDOWN:
//		{
//			POINT pt = { LOWORD(lParam), HIWORD(lParam) };
//			ptList.push_back(pt);
//		
//			if( ptList.size() == 5)
//			{
//				minPoint = FindMinPoint(origin, ptList);
//				ptList.clear();
//			}
//			InvalidateRect(hwnd, NULL, TRUE);
//		}
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);	
//
//		DrawOrigin(hdc, origin);
//		DrawMinPoint(hdc, minPoint);
//		DrawPointList(hdc, ptList);
//
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
//}

//#include <windows.h>
//#include <vector>
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "W";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("W",
//		"Title",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//void DrawOrigin(HDC hdc, POINT pt)
//{
//	MoveToEx(hdc, pt.x, pt.y-20, NULL);
//	LineTo(hdc,  pt.x, pt.y+20);
//	MoveToEx(hdc, pt.x-20, pt.y, NULL);
//	LineTo(hdc,  pt.x+20, pt.y);
//}
//int DistanceOriginToPoint(POINT origin, POINT pt)
//{
//	int width = origin.x-pt.x;
//	int height = origin.y-pt.y;
//	return width*width + height*height;
//}
//POINT FindMinPoint(POINT origin, const vector<POINT>& ptList)
//{
//	POINT minPoint={10000,10000};
//	for(unsigned i = 0 ; i < ptList.size() ; ++i)
//	{
//		int distance = DistanceOriginToPoint(origin, ptList[i]);
//		if(distance < DistanceOriginToPoint(origin, minPoint) )
//			minPoint = ptList[i];
//	}
//
//	return minPoint;
//}
//void DrawMinPoint(HDC hdc, POINT pt)
//{
//	TextOut(hdc, pt.x, pt.y, "Hello!", strlen("Hello!"));
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam)
//{
//	HDC			hdc;
//	PAINTSTRUCT ps;
//	static	vector<POINT> ptList;
//	static POINT origin;
//	static POINT minPoint = { -1000, -1000 };
//	RECT clientRect;
//
//	switch (iMsg) 
//	{
//	case WM_CREATE:
//		break; 
//	case WM_SIZE:
//		GetClientRect(hwnd, &clientRect);
//		origin.x = clientRect.right/2;
//		origin.y = clientRect.bottom/2;
//		break;
//	case WM_LBUTTONDOWN:
//		{
//			POINT pt = { LOWORD(lParam), HIWORD(lParam) };
//			ptList.push_back(pt);
//		
//			if( ptList.size() == 3 )
//			{
//				minPoint = FindMinPoint(origin, ptList);
//				ptList.clear();
//			}
//			InvalidateRect(hwnd, NULL, TRUE);
//		}
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);	
//		DrawOrigin(hdc, origin);
//		DrawMinPoint(hdc, minPoint);
//		for(unsigned i = 0 ; i < ptList.size(); ++i)
//			TextOut(hdc,ptList[i].x, ptList[i].y, "Hello!", strlen("Hello!"));
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
//}

//#include <windows.h>
//#include <vector>
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "W";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("W",
//		"Title",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//void DrawOrigin(HDC hdc, POINT pt)
//{
//	MoveToEx(hdc, pt.x, pt.y-20, NULL);
//	LineTo(hdc,  pt.x, pt.y+20);
//	MoveToEx(hdc, pt.x-20, pt.y, NULL);
//	LineTo(hdc,  pt.x+20, pt.y);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam)
//{
//	HDC			hdc;
//	PAINTSTRUCT ps;
//	static	vector<POINT> ptList;
//	static POINT origin;
//	RECT clientRect;
//
//	switch (iMsg) 
//	{
//	case WM_CREATE:
//		break; 
//	case WM_SIZE:
//		GetClientRect(hwnd, &clientRect);
//		origin.x = clientRect.right/2;
//		origin.y = clientRect.bottom/2;
//		break;
//	case WM_LBUTTONDOWN:
//		{
//			POINT pt = { LOWORD(lParam), HIWORD(lParam) };
//			ptList.push_back(pt);
//		
//			if( ptList.size() == 3 )
//			{
//				ptList.clear();
//			}
//			InvalidateRect(hwnd, NULL, TRUE);
//		}
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);	
//		DrawOrigin(hdc, origin);
//		for(unsigned i = 0 ; i < ptList.size(); ++i)
//			TextOut(hdc,ptList[i].x, ptList[i].y, "Hello!", strlen("Hello!"));
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
//}

//#include <windows.h>
//#include <vector>
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "W";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("W",
//		"Title",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam)
//{
//	HDC			hdc;
//	PAINTSTRUCT ps;
//	static	vector<POINT> ptList;
//
//	switch (iMsg) 
//	{
//	case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		POINT pt = { LOWORD(lParam), HIWORD(lParam) };
//		ptList.push_back(pt);
//			
//		if( ptList.size() < 2 )
//		{			
//		}
//		else
//		{
//			ptList.clear();
//		}
//		InvalidateRect(hwnd, NULL, TRUE);
//
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);	
//		for(unsigned i = 0 ; i < ptList.size(); ++i)
//			TextOut(hdc,ptList[i].x, ptList[i].y, "Hello!", strlen("Hello!"));
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
//}

//#include <windows.h>
//#include <vector>
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "W";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("W",
//		"Title",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam)
//{
//	HDC			hdc;
//	PAINTSTRUCT ps;
//	static	vector<POINT> ptList;
//
//	switch (iMsg) 
//	{
//	case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		POINT pt = { LOWORD(lParam), HIWORD(lParam) };
//		ptList.push_back(pt);
//			
//		if( ptList.size() < 2 )
//		{			
//			hdc = GetDC(hwnd);
//			TextOut(hdc, pt.x, pt.y, "Hello!", strlen("Hello!"));
//			ReleaseDC(hwnd, hdc);
//		}
//		else
//		{
//			ptList.clear();
//			InvalidateRect(hwnd, NULL, TRUE);
//		}
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);	
//		for(unsigned i = 0 ; i < ptList.size(); ++i)
//			TextOut(hdc,ptList[i].x, ptList[i].y, "Hello!", strlen("Hello!"));
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
//}


//#include <windows.h>
//#include <vector>
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "W";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("W",
//		"Title",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam)
//{
//	HDC			hdc;
//	PAINTSTRUCT ps;
//	static	vector<POINT> ptList;
//
//	switch (iMsg) 
//	{
//	case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		{
//			POINT pt = { LOWORD(lParam), HIWORD(lParam) };
//			ptList.push_back(pt);
//			
//			hdc = GetDC(hwnd);
//			TextOut(hdc, pt.x, pt.y, "Hello!", strlen("Hello!"));
//			ReleaseDC(hwnd, hdc);
//		}
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);	
//		for(unsigned i = 0 ; i < ptList.size(); ++i)
//			TextOut(hdc,ptList[i].x, ptList[i].y, "Hello!", strlen("Hello!"));
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
//}

//#include <windows.h>
//#include <vector>
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "W";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("W",
//		"Title",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam)
//{
//	HDC			hdc;
//	PAINTSTRUCT ps;
//	static	vector<POINT> ptList;
//
//	switch (iMsg) 
//	{
//	case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		{
//			POINT pt = { LOWORD(lParam), HIWORD(lParam) };
//			ptList.push_back(pt);
//			InvalidateRect(hwnd, NULL, TRUE);
//		}
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);	
//		for(unsigned i = 0 ; i < ptList.size(); ++i)
//			TextOut(hdc,ptList[i].x, ptList[i].y, "Hello!", strlen("Hello!"));
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
//}

//#include <windows.h>
//#include <vector>
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		
//	WndClass.cbWndExtra	= 0;		
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "W";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("W",
//		"Title",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//	);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam)
//{
//	HDC			hdc;
//	PAINTSTRUCT ps;
//
//	switch (iMsg) 
//	{
//	case WM_CREATE:
//		break; 
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);	
//		TextOut(hdc, 100, 100, "Hello!", strlen("Hello!"));
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
//}
