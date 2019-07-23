#include <windows.h>
#include "resource.h"

HINSTANCE g_hInst;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
						 WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
				   LPSTR lpszCmdLine, int nCmdShow)
{
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

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
                         WPARAM wParam, LPARAM lParam) 
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	static HBITMAP hBit;
	static RECT rt;
	HDC hMemDC;
	
	
	switch (iMsg)
	{
    case WM_CREATE:
		hBit = LoadBitmap(g_hInst,MAKEINTRESOURCE(IDB_BITMAP1));
		break; 
	case WM_LBUTTONDOWN:
		rt.left = LOWORD(lParam);
		rt.top = HIWORD(lParam);
		break;
	case WM_LBUTTONUP:
		rt.right = LOWORD(lParam);
		rt.bottom = HIWORD(lParam);

		hdc = GetDC(hwnd);
		hMemDC = CreateCompatibleDC(hdc);
		SelectObject(hMemDC, hBit);

		//BitBlt(hdc, LOWORD(lParam), HIWORD(lParam), 50,100, hMemDC, 0,0, SRCCOPY);
		StretchBlt(hdc,rt.left, rt.top,
			rt.right-rt.left, rt.bottom-rt.top, hMemDC, 0,0,100,100, SRCCOPY);
		
		DeleteDC(hMemDC);
		ReleaseDC(hwnd,hdc);
		break;
    case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);		
		EndPaint(hwnd, &ps);
		break; 
    case WM_DESTROY:
		DeleteObject(hBit);
		PostQuitMessage(0);
		break; 
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

//#include <windows.h>
//#include "resource.h"
//
//HINSTANCE g_hInst;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
//
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
//	static HBITMAP hBit;
//	HDC hMemDC;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		hBit = LoadBitmap(g_hInst,MAKEINTRESOURCE(IDB_BITMAP1));
//		break; 
//	case WM_LBUTTONDOWN:
//		hdc = GetDC(hwnd);
//		hMemDC = CreateCompatibleDC(hdc);
//		SelectObject(hMemDC, hBit);
//
//		//BitBlt(hdc, LOWORD(lParam), HIWORD(lParam), 50,100, hMemDC, 0,0, SRCCOPY);
//		StretchBlt(hdc,LOWORD(lParam),HIWORD(lParam),
//			-200,-200, hMemDC, 0,0,100,100, SRCCOPY);
//		
//		DeleteDC(hMemDC);
//		ReleaseDC(hwnd,hdc);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);		
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		DeleteObject(hBit);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//#include "resource.h"
//
//HINSTANCE g_hInst;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
//
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
//	static HBITMAP hBit;
//	HDC hMemDC;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		hBit = LoadBitmap(g_hInst,MAKEINTRESOURCE(IDB_BITMAP1));
//		break; 
//	case WM_LBUTTONDOWN:
//		hdc = GetDC(hwnd);
//		hMemDC = CreateCompatibleDC(hdc);
//		SelectObject(hMemDC, hBit);
//
//		//BitBlt(hdc, LOWORD(lParam), HIWORD(lParam), 50,100, hMemDC, 0,0, SRCCOPY);
//		StretchBlt(hdc,LOWORD(lParam),HIWORD(lParam),
//			200,200, hMemDC, 0,0,100,100, SRCCOPY);
//		
//		DeleteDC(hMemDC);
//		ReleaseDC(hwnd,hdc);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);		
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		DeleteObject(hBit);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//#include "resource.h"
//
//HINSTANCE g_hInst;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
//
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
//	static HBITMAP hBit;
//	HDC hMemDC;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		hBit = LoadBitmap(g_hInst,MAKEINTRESOURCE(IDB_BITMAP1));
//		break; 
//	case WM_LBUTTONDOWN:
//		hdc = GetDC(hwnd);
//		hMemDC = CreateCompatibleDC(hdc);
//		SelectObject(hMemDC, hBit);
//
//		BitBlt(hdc, LOWORD(lParam), HIWORD(lParam), 100,100, hMemDC, 0,0, SRCCOPY);
//		
//		DeleteDC(hMemDC);
//		ReleaseDC(hwnd,hdc);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);		
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		DeleteObject(hBit);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//#include "resource.h"
//
//HINSTANCE g_hInst;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
//
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
//	HBITMAP hBit;
//	HDC hMemDC;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//
//		hBit = LoadBitmap(g_hInst,MAKEINTRESOURCE(IDB_BITMAP1));
//		hMemDC = CreateCompatibleDC(hdc);
//		SelectObject(hMemDC, hBit);
//
//		BitBlt(hdc, 200,200, 100,100, hMemDC, 0,0, SRCCOPY);
//
//		DeleteObject(hBit);
//		DeleteDC(hMemDC);
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
//#include "resource.h"
//
//HINSTANCE g_hInst;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//				   LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
//
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
//	HBITMAP hBit;
//	HDC hMemDC;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//
//		hBit = LoadBitmap(g_hInst,MAKEINTRESOURCE(IDB_BITMAP1));
//		hMemDC = CreateCompatibleDC(hdc);
//		SelectObject(hMemDC, hBit);
//
//		BitBlt(hdc, 200,200, 100,100, hMemDC, 0,0, SRCCOPY);
//
//		DeleteObject(hBit);
//		DeleteDC(hMemDC);
//		
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
