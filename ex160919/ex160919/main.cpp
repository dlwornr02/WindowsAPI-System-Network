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
//void DrawRect(HDC hdc, const RECT&rt)
//{
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int width, height;
//	static RECT upRect;
//	static RECT downRect;
//
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRect(hdc,upRect);
//		DrawRect(hdc,downRect);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_SIZE:
//		width = LOWORD(lParam);
//		height = HIWORD(lParam);
//		SetRect(&upRect,0,0,width/3,height/2);
//		SetRect(&downRect,0,height/2,width/5,height);
//		break;
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
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
//void DrawRect(HDC hdc, const RECT&rt)
//{
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int width, height;
//	static RECT upRect;
//	static RECT downRect;
//
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRect(hdc,upRect);
//		DrawRect(hdc,downRect);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_SIZE:
//		width = LOWORD(lParam);
//		height = HIWORD(lParam);
//		SetRect(&upRect,0,0,width/3,height/2);
//		SetRect(&downRect,0,height/2,width/5,height);
//		break;
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//#include <windows.h>
//#define UPRTCOUNT 3
//#define DOWNRTCOUNT 5
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
//void DrawRect(HDC hdc, const RECT&rt)
//{
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int width, height;
//	static int upRtWidth,upRtHeight,downRtWidth,downRtHeight;
//	static RECT upRect;
//	static RECT downRect;
//
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		for(int i = 0 ; i<UPRTCOUNT;i++)
//		{
//			SetRect(&upRect,upRtWidth*i,0,upRtWidth*(i+1),upRtHeight);
//			DrawRect(hdc,upRect);
//		}
//		for(int i = 0 ; i<DOWNRTCOUNT;i++)
//		{
//			SetRect(&downRect,downRtWidth*i,downRtHeight,downRtWidth*(i+1),downRtHeight*2);
//			DrawRect(hdc,downRect);
//		}
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_SIZE:
//		width = LOWORD(lParam);
//		height = HIWORD(lParam);
//		upRtWidth = width/UPRTCOUNT;
//		downRtWidth = width/DOWNRTCOUNT;
//		upRtHeight = height/2;
//		downRtHeight = height/2;
//		break;
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//#include <windows.h>
//#define UPRTCOUNT 3
//#define DOWNRTCOUNT 5
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
//void DrawRect(HDC hdc, const RECT&rt)
//{
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//}
//void DrawBackground(HDC hdc,int upRtWidth,int downRtWidth,int upRtHeight,int downRtHeight)
//{
//	RECT upRect,downRect;
//	for(int i = 0 ; i<UPRTCOUNT;i++)
//		{
//			SetRect(&upRect,upRtWidth*i,0,upRtWidth*(i+1),upRtHeight);
//			DrawRect(hdc,upRect);
//		}
//		for(int i = 0 ; i<DOWNRTCOUNT;i++)
//		{
//			SetRect(&downRect,downRtWidth*i,downRtHeight,downRtWidth*(i+1),downRtHeight*2);
//			DrawRect(hdc,downRect);
//		}
//}
//void DrawUpRect(HDC hdc,const RECT& rt)
//{
//	HBRUSH hNewBrush = CreateSolidBrush(RGB(255,0,0));
//	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);
//
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//
//	SelectObject(hdc,hOldBrush);
//	DeleteObject(hNewBrush);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int width, height;
//	static int upRtWidth,upRtHeight,downRtWidth,downRtHeight;
//	static RECT upRect;
//
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawBackground(hdc,upRtWidth,downRtWidth,upRtHeight,downRtHeight);
//		DrawUpRect(hdc,upRect);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_SIZE:
//		width = LOWORD(lParam);
//		height = HIWORD(lParam);
//		upRtWidth = width/UPRTCOUNT;
//		downRtWidth = width/DOWNRTCOUNT;
//		upRtHeight = height/2;
//		downRtHeight = height/2;
//		//////////////////////////////////////////
//		SetRect(&upRect,0,0,upRtWidth,upRtHeight);
//		break;
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//
//
//#include <windows.h>
//#define UPRTCOUNT 3
//#define DOWNRTCOUNT 5
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
//void DrawRect(HDC hdc, const RECT&rt)
//{
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//}
//void DrawBackground(HDC hdc,int upRtWidth,int downRtWidth,int upRtHeight,int downRtHeight)
//{
//	RECT upRect,downRect;
//	for(int i = 0 ; i<UPRTCOUNT;i++)
//		{
//			SetRect(&upRect,upRtWidth*i,0,upRtWidth*(i+1),upRtHeight);
//			DrawRect(hdc,upRect);
//		}
//		for(int i = 0 ; i<DOWNRTCOUNT;i++)
//		{
//			SetRect(&downRect,downRtWidth*i,downRtHeight,downRtWidth*(i+1),downRtHeight*2);
//			DrawRect(hdc,downRect);
//		}
//}
//void DrawUpRect(HDC hdc,int upRectCount, int upRtWidth, int upRtHeight)
//{
//	RECT rt = {upRtWidth*upRectCount,0,upRtWidth*(upRectCount+1),upRtHeight};
//	HBRUSH hNewBrush = CreateSolidBrush(RGB(255,0,0));
//	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);
//
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//
//	SelectObject(hdc,hOldBrush);
//	DeleteObject(hNewBrush);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int width, height;
//	static int upRtWidth,upRtHeight,downRtWidth,downRtHeight;
//	static int upRectCount;
//	static RECT upRect;
//
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		SetTimer(hwnd,1,500,NULL);
//		break;
//	case WM_TIMER:
//		upRectCount++;
//		InvalidateRect(hwnd,NULL,TRUE);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawBackground(hdc,upRtWidth,downRtWidth,upRtHeight,downRtHeight);
//		DrawUpRect(hdc,upRectCount%UPRTCOUNT, upRtWidth , upRtHeight);
//
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_SIZE:
//		width = LOWORD(lParam);
//		height = HIWORD(lParam);
//		upRtWidth = width/UPRTCOUNT;
//		downRtWidth = width/DOWNRTCOUNT;
//		upRtHeight = height/2;
//		downRtHeight = height/2;
//		//////////////////////////////////////////
//		SetRect(&upRect,0,0,upRtWidth,upRtHeight);
//		break;
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		KillTimer(hwnd,1);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//#include <windows.h>
//#define UPRTCOUNT 3
//#define DOWNRTCOUNT 5
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
//void DrawRect(HDC hdc, const RECT&rt)
//{
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//}
//void DrawBackground(HDC hdc,int upRtWidth,int downRtWidth,int upRtHeight,int downRtHeight)
//{
//	RECT upRect,downRect;
//	for(int i = 0 ; i<UPRTCOUNT;i++)
//		{
//			SetRect(&upRect,upRtWidth*i,0,upRtWidth*(i+1),upRtHeight);
//			DrawRect(hdc,upRect);
//		}
//		for(int i = 0 ; i<DOWNRTCOUNT;i++)
//		{
//			SetRect(&downRect,downRtWidth*i,downRtHeight,downRtWidth*(i+1),downRtHeight*2);
//			DrawRect(hdc,downRect);
//		}
//}
//COLORREF SelectColor(int i)
//{
//	switch(i)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//		break;
//	case 1:
//		return RGB(0,0xff,0);
//		break;
//	case 2:
//		return RGB(0,0,0xff);
//		break;
//	}
//	return RGB(0,0,0);
//}
//void DrawUpRect(HDC hdc,int upRectCount, int upRtWidth, int upRtHeight)
//{
//	RECT rt = {upRtWidth*upRectCount,0,upRtWidth*(upRectCount+1),upRtHeight};
//	
//	HBRUSH hNewBrush = CreateSolidBrush(SelectColor(upRectCount));
//	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);
//
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//
//	SelectObject(hdc,hOldBrush);
//	DeleteObject(hNewBrush);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int width, height;
//	static int upRtWidth,upRtHeight,downRtWidth,downRtHeight;
//	static int upRectCount;
//	static RECT upRect;
//
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		SetTimer(hwnd,1,500,NULL);
//		break;
//	case WM_TIMER:
//		upRectCount++;
//		InvalidateRect(hwnd,NULL,TRUE);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawBackground(hdc,upRtWidth,downRtWidth,upRtHeight,downRtHeight);
//		DrawUpRect(hdc,upRectCount%UPRTCOUNT, upRtWidth , upRtHeight);
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_SIZE:
//		width = LOWORD(lParam);
//		height = HIWORD(lParam);
//		upRtWidth = width/UPRTCOUNT;
//		downRtWidth = width/DOWNRTCOUNT;
//		upRtHeight = height/2;
//		downRtHeight = height/2;
//		//////////////////////////////////////////
//		SetRect(&upRect,0,0,upRtWidth,upRtHeight);
//		break;
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		KillTimer(hwnd,1);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//#include <windows.h>
//#define UPRTCOUNT 3
//#define DOWNRTCOUNT 5
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
//void DrawRect(HDC hdc, const RECT&rt)
//{
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//}
//void DrawBackground(HDC hdc,int upRtWidth,int downRtWidth,int upRtHeight,int downRtHeight)
//{
//	RECT upRect,downRect;
//	for(int i = 0 ; i<UPRTCOUNT;i++)
//		{
//			SetRect(&upRect,upRtWidth*i,0,upRtWidth*(i+1),upRtHeight);
//			DrawRect(hdc,upRect);
//		}
//		for(int i = 0 ; i<DOWNRTCOUNT;i++)
//		{
//			SetRect(&downRect,downRtWidth*i,downRtHeight,downRtWidth*(i+1),downRtHeight*2);
//			DrawRect(hdc,downRect);
//		}
//}
//COLORREF SelectColor(int i)
//{
//	switch(i)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//		break;
//	case 1:
//		return RGB(0,0xff,0);
//		break;
//	case 2:
//		return RGB(0,0,0xff);
//		break;
//	}
//	return RGB(0,0,0);
//}
//void DrawUpRect(HDC hdc,int upRectCount, int upRtWidth, int upRtHeight)
//{
//	RECT rt = {upRtWidth*upRectCount,0,upRtWidth*(upRectCount+1),upRtHeight};
//	
//	HBRUSH hNewBrush = CreateSolidBrush(SelectColor(upRectCount));
//	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);
//
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//
//	SelectObject(hdc,hOldBrush);
//	DeleteObject(hNewBrush);
//}
//void DrawDownLine(HDC hdc,int downRtCount,
//	int downRtWidth,int downRtHeight)
//{
//	int dDivision = downRtHeight/5;
//	POINT startPt={0,downRtHeight+dDivision*downRtCount};
//	POINT endPt={downRtWidth,downRtHeight+dDivision*downRtCount};
//
//	MoveToEx(hdc,startPt.x,startPt.y,NULL);
//	LineTo(hdc,endPt.x,endPt.y);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int width, height;
//	static int upRtWidth,upRtHeight,downRtWidth,downRtHeight;
//	static int upRectCount;
//	static int downRectCount;
//	static RECT upRect;
//
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		SetTimer(hwnd,1,500,NULL);
//		SetTimer(hwnd,2,300,NULL);
//		break;
//	case WM_TIMER:
//		if(wParam==1)
//		{
//			upRectCount++;
//		}
//		else
//		{
//			downRectCount++;
//		}
//
//		InvalidateRect(hwnd,NULL,TRUE);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawBackground(hdc,upRtWidth,downRtWidth,upRtHeight,downRtHeight);
//		DrawUpRect(hdc,upRectCount%UPRTCOUNT, upRtWidth , upRtHeight);
//		DrawDownLine(hdc, downRectCount%DOWNRTCOUNT,downRtWidth,downRtHeight);
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_SIZE:
//		width = LOWORD(lParam);
//		height = HIWORD(lParam);
//		upRtWidth = width/UPRTCOUNT;
//		downRtWidth = width/DOWNRTCOUNT;
//		upRtHeight = height/2;
//		downRtHeight = height/2;
//		//////////////////////////////////////////
//		SetRect(&upRect,0,0,upRtWidth,upRtHeight);
//		break;
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		KillTimer(hwnd,1);
//		KillTimer(hwnd,2);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//#include <windows.h>
//#define UPRTCOUNT 3
//#define DOWNRTCOUNT 5
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
//void DrawRect(HDC hdc, const RECT&rt)
//{
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//}
//void DrawBackground(HDC hdc,int upRtWidth,int downRtWidth,int upRtHeight,int downRtHeight)
//{
//	RECT upRect,downRect;
//	for(int i = 0 ; i<UPRTCOUNT;i++)
//		{
//			SetRect(&upRect,upRtWidth*i,0,upRtWidth*(i+1),upRtHeight);
//			DrawRect(hdc,upRect);
//		}
//		for(int i = 0 ; i<DOWNRTCOUNT;i++)
//		{
//			SetRect(&downRect,downRtWidth*i,downRtHeight,downRtWidth*(i+1),downRtHeight*2);
//			DrawRect(hdc,downRect);
//		}
//}
//COLORREF SelectColor(int i)
//{
//	switch(i)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//		break;
//	case 1:
//		return RGB(0,0xff,0);
//		break;
//	case 2:
//		return RGB(0,0,0xff);
//		break;
//	}
//	return RGB(0,0,0);
//}
//void DrawUpRect(HDC hdc,int upRectCount, int upRtWidth, int upRtHeight)
//{
//	RECT rt = {upRtWidth*upRectCount,0,upRtWidth*(upRectCount+1),upRtHeight};
//	
//	HBRUSH hNewBrush = CreateSolidBrush(SelectColor(upRectCount));
//	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);
//
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//
//	SelectObject(hdc,hOldBrush);
//	DeleteObject(hNewBrush);
//}
//void DrawDownLine(HDC hdc,int downRtCount,int downLineCount,
//	int downRtWidth,int downRtHeight)
//{
//	int dDivision = downRtHeight/5;
//	POINT startPt={downRtWidth*downLineCount,downRtHeight+dDivision*downRtCount};
//	POINT endPt={downRtWidth*(downLineCount+1),downRtHeight+dDivision*downRtCount};
//
//	MoveToEx(hdc,startPt.x,startPt.y,NULL);
//	LineTo(hdc,endPt.x,endPt.y);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int width, height;
//	static int upRtWidth,upRtHeight,downRtWidth,downRtHeight;
//	static int upRectCount;
//	static int downRectCount,downLineCount;
//	static RECT upRect;
//
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		SetTimer(hwnd,1,500,NULL);
//		SetTimer(hwnd,2,300,NULL);
//		break;
//	case WM_TIMER:
//		if(wParam==1)
//		{
//			upRectCount++;
//		}
//		else
//		{
//			downRectCount++;
//			if(downRectCount%5==0)
//			{
//				downLineCount++;
//			}
//		}
//
//		InvalidateRect(hwnd,NULL,TRUE);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawBackground(hdc,upRtWidth,downRtWidth,upRtHeight,downRtHeight);
//		DrawUpRect(hdc,upRectCount%UPRTCOUNT, upRtWidth , upRtHeight);
//		DrawDownLine(hdc, downRectCount%DOWNRTCOUNT,downLineCount%5,downRtWidth,downRtHeight);
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_SIZE:
//		width = LOWORD(lParam);
//		height = HIWORD(lParam);
//		upRtWidth = width/UPRTCOUNT;
//		downRtWidth = width/DOWNRTCOUNT;
//		upRtHeight = height/2;
//		downRtHeight = height/2;
//		//////////////////////////////////////////
//		SetRect(&upRect,0,0,upRtWidth,upRtHeight);
//		break;
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		KillTimer(hwnd,1);
//		KillTimer(hwnd,2);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
/////////////////////////////////////////////////////////////////////////////

//#include <windows.h>
//#define UPRTCOUNT 3
//#define DOWNRTCOUNT 7
//#define DOWNLINECOUNT 5
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
//void DrawRect(HDC hdc, const RECT&rt)
//{
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//}
//void DrawBackground(HDC hdc,int upRtWidth,int downRtWidth,int upRtHeight,int downRtHeight)
//{
//	RECT upRect,downRect;
//	for(int i = 0 ; i<UPRTCOUNT;i++)
//		{
//			SetRect(&upRect,upRtWidth*i,0,upRtWidth*(i+1),upRtHeight);
//			DrawRect(hdc,upRect);
//		}
//		for(int i = 0 ; i<DOWNLINECOUNT;i++)
//		{
//			SetRect(&downRect,downRtWidth*i,downRtHeight,downRtWidth*(i+1),downRtHeight*2);
//			DrawRect(hdc,downRect);
//		}
//}
//COLORREF SelectColor(int i)
//{
//	switch(i)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//		break;
//	case 1:
//		return RGB(0,0xff,0);
//		break;
//	case 2:
//		return RGB(0,0,0xff);
//		break;
//	}
//	return RGB(0,0,0);
//}
//void DrawUpRect(HDC hdc,int upRectCount, int upRtWidth, int upRtHeight)
//{
//	RECT rt = {upRtWidth*upRectCount,0,upRtWidth*(upRectCount+1),upRtHeight};
//	
//	HBRUSH hNewBrush = CreateSolidBrush(SelectColor(upRectCount));
//	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);
//
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//
//	SelectObject(hdc,hOldBrush);
//	DeleteObject(hNewBrush);
//}
//void DrawDownLine(HDC hdc,int downRtCount,int downLineCount,
//	int downRtWidth,int downRtHeight)
//{
//	int dDivision = downRtHeight/5;
//	POINT startPt={downRtWidth*downLineCount,downRtHeight+dDivision*downRtCount};
//	POINT endPt={downRtWidth*(downLineCount+1),downRtHeight+dDivision*downRtCount};
//
//	MoveToEx(hdc,startPt.x,startPt.y,NULL);
//	LineTo(hdc,endPt.x,endPt.y);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int width, height;
//	static int upRtWidth,upRtHeight,downRtWidth,downRtHeight;
//	static int upRectCount;
//	static int downRectCount,downLineCount;
//	static RECT upRect;
//
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		SetTimer(hwnd,1,500,NULL);
//		SetTimer(hwnd,2,300,NULL);
//		break;
//	case WM_TIMER:
//		if(wParam==1)
//		{
//			upRectCount++;
//		}
//		else
//		{
//			downRectCount++;
//			if(downRectCount%DOWNRTCOUNT==0)
//			{
//				downLineCount++;
//			}
//		}
//
//		InvalidateRect(hwnd,NULL,TRUE);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawBackground(hdc,upRtWidth,downRtWidth,upRtHeight,downRtHeight);
//		DrawUpRect(hdc,upRectCount%UPRTCOUNT, upRtWidth , upRtHeight);
//		DrawDownLine(hdc, downRectCount%DOWNLINECOUNT,downLineCount%DOWNRTCOUNT,downRtWidth,downRtHeight);
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_SIZE:
//		width = LOWORD(lParam);
//		height = HIWORD(lParam);
//		upRtWidth = width/UPRTCOUNT;
//		downRtWidth = width/DOWNRTCOUNT;
//		upRtHeight = height/2;
//		downRtHeight = height/2;
//		//////////////////////////////////////////
//		SetRect(&upRect,0,0,upRtWidth,upRtHeight);
//		break;
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		KillTimer(hwnd,1);
//		KillTimer(hwnd,2);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//#include <windows.h>
//#define UPRTCOUNT 3
//#define DOWNRTCOUNT 3
//#define DOWNLINECOUNT 5
//
//#define UPTIMERID 1
//#define DOWNTIMERID 2
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
//void DrawRect(HDC hdc, const RECT&rt)
//{
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//}
//void DrawBackground(HDC hdc,int upRtWidth,int downRtWidth,int upRtHeight,int downRtHeight)
//{
//	RECT upRect,downRect;
//	for(int i = 0 ; i<UPRTCOUNT;i++)
//		{
//			SetRect(&upRect,upRtWidth*i,0,upRtWidth*(i+1),upRtHeight);
//			DrawRect(hdc,upRect);
//		}
//		for(int i = 0 ; i<DOWNLINECOUNT;i++)
//		{
//			SetRect(&downRect,downRtWidth*i,downRtHeight,downRtWidth*(i+1),downRtHeight*2);
//			DrawRect(hdc,downRect);
//		}
//}
//COLORREF SelectColor(int i)
//{
//	switch(i)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//		break;
//	case 1:
//		return RGB(0,0xff,0);
//		break;
//	case 2:
//		return RGB(0,0,0xff);
//		break;
//	}
//	return RGB(0,0,0);
//}
//void DrawUpRect(HDC hdc,int upRectCount, int upRtWidth, int upRtHeight)
//{
//	RECT rt = {upRtWidth*upRectCount,0,upRtWidth*(upRectCount+1),upRtHeight};
//	
//	HBRUSH hNewBrush = CreateSolidBrush(SelectColor(upRectCount));
//	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);
//
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//
//	SelectObject(hdc,hOldBrush);
//	DeleteObject(hNewBrush);
//}
//void DrawDownLine(HDC hdc,int downRtCount,int downLineCount,
//	int downRtWidth,int downRtHeight)
//{
//	int dDivision = downRtHeight/downRtCount;
//	POINT startPt={downRtWidth*downLineCount,downRtHeight+dDivision*downRtCount};
//	POINT endPt={downRtWidth*(downLineCount+1),downRtHeight+dDivision*downRtCount};
//
//	MoveToEx(hdc,startPt.x,startPt.y,NULL);
//	LineTo(hdc,endPt.x,endPt.y);
//}
//void UpdateTitle(HWND hwnd,int upCount,int downCount)
//{
//	TCHAR buf[200];
//	wsprintf(buf,"up:%d,down:%d",upCount,downCount);
//	SetWindowText(hwnd,buf);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int width, height;
//	static int upRtWidth,upRtHeight,downRtWidth,downRtHeight;
//	static int upRectCount;
//	static int downRectCount,downLineCount;
//	static int upCount,downCount;
//
//	static RECT upRect;
//
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		SetTimer(hwnd,UPTIMERID,500,NULL);
//		SetTimer(hwnd,DOWNTIMERID,300,NULL);
//		break;
//	case WM_TIMER:
//		if(wParam==UPTIMERID)
//		{
//			upRectCount++;
//			if(upRectCount%UPRTCOUNT == 0)
//				upRectCount++;
//		}
//		else
//		{
//			downRectCount++;
//			if(downRectCount%DOWNRTCOUNT==0)
//			{
//				downLineCount++;
//				if(downLineCount%DOWNLINECOUNT == 0)
//					upRectCount++;
//			}
//		}
//		UpdateTitle(hwnd,upCount, downCount);
//		InvalidateRect(hwnd,NULL,TRUE);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawBackground(hdc,upRtWidth,downRtWidth,upRtHeight,downRtHeight);
//		DrawUpRect(hdc,upRectCount%UPRTCOUNT, upRtWidth , upRtHeight);
//		DrawDownLine(hdc, downRectCount%DOWNLINECOUNT,downLineCount%DOWNRTCOUNT,downRtWidth,downRtHeight);
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_SIZE:
//		width = LOWORD(lParam);
//		height = HIWORD(lParam);
//		upRtWidth = width/UPRTCOUNT;
//		downRtWidth = width/DOWNRTCOUNT;
//		upRtHeight = height/2;
//		downRtHeight = height/2;
//		//////////////////////////////////////////
//		SetRect(&upRect,0,0,upRtWidth,upRtHeight);
//		break;
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		KillTimer(hwnd,UPTIMERID);
//		KillTimer(hwnd,DOWNTIMERID);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//
//
//#include <windows.h>
//#define UPRTCOUNT 3
//#define DOWNRTCOUNT 3
//#define DOWNLINECOUNT 5
//
//#define UPTIMERID 1
//#define DOWNTIMERID 2
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
//void DrawRect(HDC hdc, const RECT&rt)
//{
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//}
//void DrawBackground(HDC hdc,int upRtWidth,int downRtWidth,int upRtHeight,int downRtHeight)
//{
//	RECT upRect,downRect;
//	for(int i = 0 ; i<UPRTCOUNT;i++)
//		{
//			SetRect(&upRect,upRtWidth*i,0,upRtWidth*(i+1),upRtHeight);
//			DrawRect(hdc,upRect);
//		}
//		for(int i = 0 ; i<DOWNLINECOUNT;i++)
//		{
//			SetRect(&downRect,downRtWidth*i,downRtHeight,downRtWidth*(i+1),downRtHeight*2);
//			DrawRect(hdc,downRect);
//		}
//}
//COLORREF SelectColor(int i)
//{
//	switch(i)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//		break;
//	case 1:
//		return RGB(0,0xff,0);
//		break;
//	case 2:
//		return RGB(0,0,0xff);
//		break;
//	}
//	return RGB(0,0,0);
//}
//void DrawUpRect(HDC hdc,int upRectCount, int upRtWidth, int upRtHeight)
//{
//	RECT rt = {upRtWidth*upRectCount,0,upRtWidth*(upRectCount+1),upRtHeight};
//	
//	HBRUSH hNewBrush = CreateSolidBrush(SelectColor(upRectCount));
//	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);
//
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//
//	SelectObject(hdc,hOldBrush);
//	DeleteObject(hNewBrush);
//}
//void DrawDownLine(HDC hdc,int downRtCount,int downLineCount,
//	int downRtWidth,int downRtHeight)
//{
//	int dDivision = downRtHeight/downRtCount;
//	POINT startPt={downRtWidth*downLineCount,downRtHeight+dDivision*downRtCount};
//	POINT endPt={downRtWidth*(downLineCount+1),downRtHeight+dDivision*downRtCount};
//
//	MoveToEx(hdc,startPt.x,startPt.y,NULL);
//	LineTo(hdc,endPt.x,endPt.y);
//}
//void UpdateTitle(HWND hwnd,int upCount,int downCount)
//{
//	TCHAR buf[200];
//	wsprintf(buf,"up:%d,down:%d",upCount,downCount);
//	SetWindowText(hwnd,buf);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static int width, height;
//	static int upRtWidth,upRtHeight,downRtWidth,downRtHeight;
//	static int upRectCount;
//	static int downRectCount,downLineCount;
//	static int upCount,downCount;
//
//	static RECT upRect;
//
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		SetTimer(hwnd,UPTIMERID,500,NULL);
//		SetTimer(hwnd,DOWNTIMERID,300,NULL);
//		break;
//	case WM_TIMER:
//		if(wParam==UPTIMERID)
//		{
//			upRectCount++;
//			if(upRectCount%UPRTCOUNT == 0)
//				upRectCount++;
//		}
//		else
//		{
//			downRectCount++;
//			if(downRectCount%DOWNRTCOUNT==0)
//			{
//				downLineCount++;
//				if(downLineCount%DOWNLINECOUNT == 0)
//					upRectCount++;
//			}
//		}
//		UpdateTitle(hwnd,upCount, downCount);
//		InvalidateRect(hwnd,NULL,TRUE);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawBackground(hdc,upRtWidth,downRtWidth,upRtHeight,downRtHeight);
//		DrawUpRect(hdc,upRectCount%UPRTCOUNT, upRtWidth , upRtHeight);
//		DrawDownLine(hdc, downRectCount%DOWNLINECOUNT,downLineCount%DOWNRTCOUNT,downRtWidth,downRtHeight);
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_SIZE:
//		width = LOWORD(lParam);
//		height = HIWORD(lParam);
//		upRtWidth = width/UPRTCOUNT;
//		downRtWidth = width/DOWNRTCOUNT;
//		upRtHeight = height/2;
//		downRtHeight = height/2;
//		//////////////////////////////////////////
//		SetRect(&upRect,0,0,upRtWidth,upRtHeight);
//		break;
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		KillTimer(hwnd,UPTIMERID);
//		KillTimer(hwnd,DOWNTIMERID);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

////////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include "resource.h"
#define UPRTCOUNT 3 //도형 그리기 위한것.
#define DOWNRTCOUNT 3 //도형을 그리기 위한 것이다. //상수 5로 지정해준것을 갈아준다.
#define DOWNLINECOUNT 5 // 선형을 그리기 위한것.

#define UPTIMERID 1
#define DOWNTIMERID 2
int upCount,downCount;//이것은 위에 도형의 돌아가는 횟수를 위한 변수
HWND hDlg;
HINSTANCE g_hInst;
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
	WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, 
	WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpszCmdLine, int nCmdShow)
{
	g_hInst = hInstance;

	HWND     hwnd;
	MSG     msg;
	WNDCLASS WndClass;   
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;      
	WndClass.cbClsExtra   = 0;      
	WndClass.cbWndExtra   = 0;      
	WndClass.hInstance = hInstance;      
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);   
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);      
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



void DrawRect(HDC hdc , const RECT& rt)
{
	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);// 그려준다.
}



void DrawBackground(HDC hdc, int upRtWidth, int downRtWidth, int upRtHeight,int downRtHeight)
{
	RECT upRect,downRect;

	for(int i = 0 ; i < UPRTCOUNT; ++i)
	{
		SetRect(&upRect,upRtWidth*i,0,upRtWidth*(i+1),upRtHeight);
		DrawRect(hdc , upRect);
	}
	for(int i = 0 ; i < DOWNLINECOUNT; ++i)
	{
		SetRect(&downRect, downRtWidth*i , upRtHeight , downRtWidth*(i+1), downRtHeight*2);
		DrawRect(hdc , downRect);
	}
}
COLORREF SelectColor(int i) // 카운트에다가 색상을 넣어 바꿔준다.
{
	switch(i)
	{
	case 0:
		return RGB(0xff,0,0);
		break;
	case 1:
		return RGB(0,0xff,0);
		break;
	default:
		return RGB(0,0,0xff);
		break;

	}
}
void DrawUpRect(HDC hdc, int upRectCount, int upRtWidth, int upRtHeight)
{
	RECT rt = {upRtWidth*upRectCount,0,upRtWidth*(upRectCount+1),upRtHeight};

	HBRUSH hNewBrush = CreateSolidBrush(SelectColor(upRectCount));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);
	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);

	SelectObject(hdc, hOldBrush);
	DeleteObject(hNewBrush);
}

void DrawDownLine(HDC hdc,int downRectCount, int downLineCount , int downRtWidth, int downRtHeight)
{
	int dDivision = downRtHeight/DOWNRTCOUNT;
	POINT startPt = {downRtWidth*downLineCount,downRtHeight+dDivision*downRectCount}; //x축의 기본 설정을 해준다.
	//x축에 LineCount 를 넣어서 기본 x좌표의 값을 이동시켜주면서 끝좌표도 같이 이동시켜준다 마지막은 기본보다 커야하기
	POINT endPt={downRtWidth*(downLineCount+1),downRtHeight+dDivision*downRectCount}; // y축의 기본설정을한다.

	MoveToEx(hdc, startPt.x,startPt.y , NULL);
	LineTo(hdc, endPt.x, endPt.y);
}
void UpdateTitle(HWND hwnd, int upCount,int downCount)
{
	TCHAR buf[200];
	wsprintf(buf,"(up : %d , down : %d)",upCount,downCount);
	SetWindowText(hwnd,buf);
}
void UpdateEdit(HWND hDlg, int upCount,int downCount)
{
	SetDlgItemInt(hDlg,IDC_EDIT1,upCount,TRUE);
	SetDlgItemInt(hDlg,IDC_EDIT2,downCount,TRUE);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam) 
{
	HDC         hdc;

	PAINTSTRUCT ps; 
	static int  width,height; //두개의 변수를 만들어놓는다.
	static int upRtWidth, downRtWidth; // 위와 밑의 반복문을 돌리기 위해서 변수 4개를 만들어준다.
	static int downRtHeight , upRtHeight;

	static RECT upRect; //임시적으로 SIZE에서 변경해준다.

	static int upRectCount; //몇번 즈악되는지 만들어진다.
	static int downRectCount; 

	static int downLineCount;//전체적으로 변위를 만들어주는 변수를 만들어준다.

	switch (iMsg)
	{
	case WM_CREATE:

		SetTimer(hwnd,UPTIMERID,500,NULL);
		SetTimer(hwnd,DOWNTIMERID,300,NULL);//동작하는 타이머 시간이 다르기때문에 아이디를 만들어줌

		break; 
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case ID_MODELESS:
			if(!IsWindow(hDlg))
			{
				hDlg=CreateDialog(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
				ShowWindow(hDlg,SW_SHOW);
			}
			else
				SetFocus(hDlg);
			break;
		}
		break;
	case WM_TIMER:
		if(wParam == UPTIMERID)
		{
			++upRectCount;   

			if(upRectCount%UPRTCOUNT == 0)
			{
				upCount++;
			}
		}
		else
		{

			++downRectCount;
			if(downRectCount%DOWNRTCOUNT == 0)//조건문을 걸어줘서 옆도형으로 이동시키기 위해 걸어준다.
			{
				++downLineCount;
				if(downLineCount%DOWNLINECOUNT == 0)
				{
					downCount++;
				}
			}
		}
		if(IsWindow(hDlg))
			UpdateEdit(hDlg,upCount,downCount);
		UpdateTitle(hwnd,upCount,downCount);
		InvalidateRect(hwnd,NULL,TRUE);
		break;
	case WM_SIZE:
		width = LOWORD(lParam); //가로 길이 
		height = HIWORD(lParam); // 세로 길이를 받는다.


		upRtWidth = width/UPRTCOUNT; // 이뜻은 width/3 이라는것이다.
		downRtWidth = width/DOWNLINECOUNT;

		upRtHeight = height/2;
		downRtHeight= height/2;


		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);



		DrawBackground(hdc,upRtWidth,downRtWidth,upRtHeight,downRtHeight); //기본 배경색을 흰색으로 두어 색상을 출력해주는 함수를 따로히 만든다.
		DrawUpRect(hdc,upRectCount%UPRTCOUNT,upRtWidth,upRtHeight); //색상 그리는것.

		DrawDownLine(hdc,downRectCount%DOWNRTCOUNT, downLineCount%DOWNLINECOUNT, downRtWidth,downRtHeight);

		EndPaint(hwnd,&ps);
		break; 
	case WM_DESTROY:
		PostQuitMessage(0);
		KillTimer(hwnd,UPTIMERID);
		KillTimer(hwnd,DOWNTIMERID);
		break; 
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch(iMsg)
	{
	case WM_INITDIALOG:
		UpdateEdit(hDlg,upCount,downCount);
		break;
	case WM_CLOSE:
		DestroyWindow(hDlg);
		hDlg = NULL;
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDC_BUTTON1:
			{
				static bool bRun = true;
				if(bRun)
				{
					KillTimer(GetParent(hDlg),UPTIMERID);
					KillTimer(GetParent(hDlg),DOWNTIMERID);
					SetDlgItemText(hDlg,IDC_BUTTON1,"실행");
				}
				else
				{
					SetTimer(GetParent(hDlg),UPTIMERID,500,NULL);
					SetTimer(GetParent(hDlg),DOWNTIMERID,300,NULL);
					SetDlgItemText(hDlg,IDC_BUTTON1,"정지");
				}
				bRun ^= true;
			}
			break;
		}
		break;
	}
	return FALSE;
}