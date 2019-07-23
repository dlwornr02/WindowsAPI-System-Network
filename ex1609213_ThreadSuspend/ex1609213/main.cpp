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
//DWORD _stdcall TF(LPVOID pParam)
//{
//	HWND hwnd = (HWND)pParam;
//	HDC hdc = GetDC(hwnd);
//	for(int i = 0;i<100;i+=5)
//	{
//		Rectangle(hdc,100,100,100+i,100+i);
//		Sleep(100);
//	}
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	DWORD id;
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		CreateThread(NULL,0,TF,(LPVOID)hwnd,0,&id);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
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
//struct TParam
//{
//	HWND hwnd;
//	POINT pt;
//};
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
//DWORD _stdcall TF(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//	for(int i = 0;i<100;i+=5)
//	{
//		Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//		Sleep(100);
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	DWORD id;
//	TParam tp;  //스레드 사이에는 지역변수를 보내지않는다. main의 지역변수를 넘겨줄수 없다.
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		tp.hwnd = hwnd;
//		tp.pt.x = LOWORD(lParam);
//		tp.pt.y = HIWORD(lParam);
//		CreateThread(NULL,0,TF,(LPVOID)&tp,0,&id);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
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
//struct TParam
//{
//	HWND hwnd;
//	POINT pt;
//};
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
//DWORD _stdcall TF(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//	for(int i = 0;i<100;i+=5)
//	{
//		Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//		Sleep(100);
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	DWORD id;
//	static TParam tp;  //스레드 사이에는 지역변수를 보내지않는다. main의 지역변수를 넘겨줄수 없다.
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		tp.hwnd = hwnd;
//		tp.pt.x = LOWORD(lParam);
//		tp.pt.y = HIWORD(lParam);
//		CreateThread(NULL,0,TF,(LPVOID)&tp,0,&id);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
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
//struct TParam
//{
//	HWND hwnd;
//	POINT pt;
//};
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
//DWORD _stdcall TF(LPVOID pParam)
//{
//	Sleep(1000);
//	TParam tp = *(TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//	while(1)
//	{
//		for(int i = 0;i<100;i+=5)
//		{
//			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//			Sleep(100);
//		}
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	DWORD id;
//	static TParam tp;  //스레드 사이에는 지역변수를 보내지않는다. main의 지역변수를 넘겨줄수 없다.
//	switch (iMsg)	//static변수사용시 중첩현상발생 동적메모리로 한다.
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		tp.hwnd = hwnd;
//		tp.pt.x = LOWORD(lParam);
//		tp.pt.y = HIWORD(lParam);
//		CreateThread(NULL,0,TF,(LPVOID)&tp,0,&id);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
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
//struct TParam
//{
//	HWND hwnd;
//	POINT pt;
//};
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
//DWORD _stdcall TF(LPVOID pParam)
//{
//	Sleep(1000);
//	TParam tp = *(TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//	while(1)
//	{
//		for(int i = 0;i<100;i+=5)
//		{
//			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//			Sleep(100);
//		}
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	DWORD id;
//	TParam* ptp;  //스레드 사이에는 지역변수를 보내지않는다. main의 지역변수를 넘겨줄수 없다.
//	switch (iMsg)	//static변수사용시 중첩현상발생 동적메모리로 한다.
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		ptp = new TParam;
//		ptp->hwnd = hwnd;
//		ptp->pt.x = LOWORD(lParam);
//		ptp->pt.y = HIWORD(lParam);
//		CreateThread(NULL,0,TF,(LPVOID)ptp,0,&id);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
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
//struct TParam
//{
//	HWND hwnd;
//	POINT pt;
//};
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
//void DrawCount(HDC hdc,POINT pt,int count)
//{
//	TCHAR buf[200];
//	wsprintf(buf,"%d",count);
//	TextOut(hdc,pt.x,pt.y,buf,lstrlen(buf));
//}
//DWORD _stdcall TF(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	delete (TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//	int count = 0;
//
//
//	while(1)
//	{
//		POINT ptText = {pt.x+40, pt.y-25};
//		DrawCount(hdc,ptText,count);
//		for(int i = 0;i<100;i+=5)
//		{
//			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//			Sleep(100);
//		}
//		++count;
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	DWORD id;
//	TParam* ptp;  //스레드 사이에는 지역변수를 보내지않는다. main의 지역변수를 넘겨줄수 없다.
//	switch (iMsg)	//static변수사용시 중첩현상발생 동적메모리로 한다.
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		ptp = new TParam;
//		ptp->hwnd = hwnd;
//		ptp->pt.x = LOWORD(lParam);
//		ptp->pt.y = HIWORD(lParam);
//		CreateThread(NULL,0,TF,(LPVOID)ptp,0,&id);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
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
//struct TParam
//{
//	HWND hwnd;
//	POINT pt;
//};
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
//void DrawCount(HDC hdc,POINT pt,int count)
//{
//	TCHAR buf[200];
//	wsprintf(buf,"%d",count);
//	TextOut(hdc,pt.x,pt.y,buf,lstrlen(buf));
//}
//int AddCount()
//{
//	static int count=0;
//	return count++;
//}
//DWORD _stdcall TF(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	delete (TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//	int count = 0;
//
//
//	while(1)
//	{
//		POINT ptText = {pt.x+40, pt.y-25};
//		DrawCount(hdc , ptText , AddCount() );
//		for(int i = 0;i<100;i+=5)
//		{
//			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//			Sleep(100);
//		}
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	DWORD id;
//	TParam* ptp;  //스레드 사이에는 지역변수를 보내지않는다. main의 지역변수를 넘겨줄수 없다.
//	switch (iMsg)	//static변수사용시 중첩현상발생 동적메모리로 한다.
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		ptp = new TParam;
//		ptp->hwnd = hwnd;
//		ptp->pt.x = LOWORD(lParam);
//		ptp->pt.y = HIWORD(lParam);
//		CreateThread(NULL,0,TF,(LPVOID)ptp,0,&id);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
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
//struct TParam
//{
//	HWND hwnd;
//	POINT pt;
//};
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
//void DrawCount(HDC hdc,POINT pt,int count)
//{
//	TCHAR buf[200];
//	wsprintf(buf,"%d",count);
//	TextOut(hdc,pt.x,pt.y,buf,lstrlen(buf));
//}
//int AddCount()
//{
//	__declspec(thread) static int count=0; //정적TLS
//	return count++;
//}
//DWORD _stdcall TF(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	delete (TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//	int count = 0;
//
//
//	while(1)
//	{
//		POINT ptText = {pt.x+40, pt.y-25};
//		DrawCount(hdc , ptText , AddCount() );
//		for(int i = 0;i<100;i+=5)
//		{
//			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//			Sleep(100);
//		}
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	DWORD id;
//	TParam* ptp;  //스레드 사이에는 지역변수를 보내지않는다. main의 지역변수를 넘겨줄수 없다.
//	switch (iMsg)	//static변수사용시 중첩현상발생 동적메모리로 한다.
//	{
//    case WM_CREATE:
//		break; 
//	case WM_LBUTTONDOWN:
//		ptp = new TParam;
//		ptp->hwnd = hwnd;
//		ptp->pt.x = LOWORD(lParam);
//		ptp->pt.y = HIWORD(lParam);
//		CreateThread(NULL,0,TF,(LPVOID)ptp,0,&id);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
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
//struct TParam
//{
//	HWND hwnd;
//	POINT pt;
//};
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//						 WPARAM wParam, LPARAM lParam);
//int tlsIndex;
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
//void DrawCount(HDC hdc,POINT pt,int count)
//{
//	TCHAR buf[200];
//	wsprintf(buf,"%d",count);
//	TextOut(hdc,pt.x,pt.y,buf,lstrlen(buf));
//}
//int AddCount()
//{
//	int count = (int)TlsGetValue(tlsIndex);//동적 TLS사용법
//	TlsSetValue(tlsIndex,(LPVOID)(count+1)); //동적 TLS사용법
//	return count++;
//}
//DWORD _stdcall TF(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	delete (TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//	int count = 0;
//
//
//	while(1)
//	{
//		POINT ptText = {pt.x+40, pt.y-25};
//		DrawCount(hdc , ptText , AddCount() );
//		for(int i = 0;i<100;i+=5)
//		{
//			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//			Sleep(100);
//		}
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	DWORD id;
//	TParam* ptp;  //스레드 사이에는 지역변수를 보내지않는다. main의 지역변수를 넘겨줄수 없다.
//	switch (iMsg)	//static변수사용시 중첩현상발생 동적메모리로 한다.
//	{
//    case WM_CREATE:
//		tlsIndex = TlsAlloc();//동적 TLS사용법
//		break; 
//	case WM_LBUTTONDOWN:
//		ptp = new TParam;
//		ptp->hwnd = hwnd;
//		ptp->pt.x = LOWORD(lParam);
//		ptp->pt.y = HIWORD(lParam);
//		CloseHandle(CreateThread(NULL,0,TF,(LPVOID)ptp,0,&id)); 
//		//Close를 해줘야 커널오브젝트가 핸들테이블에 남아있지않고 스레드가 종료될때 제거된다.
//		//다사용하고나서 Close를 꼭해줘야함.
//		break;
//		//case RBUTTON
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		TlsFree(tlsIndex);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//#include <windows.h>
//struct TParam
//{
//	HWND hwnd;
//	POINT pt;
//};
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//						 WPARAM wParam, LPARAM lParam);
//int tlsIndex;
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
//void DrawCount(HDC hdc,POINT pt,int count)
//{
//	TCHAR buf[200];
//	wsprintf(buf,"%d",count);
//	TextOut(hdc,pt.x,pt.y,buf,lstrlen(buf));
//}
//int AddCount()
//{
//	int count = (int)TlsGetValue(tlsIndex);//동적 TLS사용법
//	TlsSetValue(tlsIndex,(LPVOID)(count+1)); //동적 TLS사용법
//	return count++;
//}
//DWORD _stdcall TF(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	delete (TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//	int count = 0;
//
//
//	while(1)
//	{
//		POINT ptText = {pt.x+40, pt.y-25};
//		DrawCount(hdc , ptText , AddCount() );
//		for(int i = 0;i<100;i+=5)
//		{
//			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//			Sleep(100);
//		}
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	DWORD id;
//	TParam* ptp;  //스레드 사이에는 지역변수를 보내지않는다. main의 지역변수를 넘겨줄수 없다.
//	switch (iMsg)	//static변수사용시 중첩현상발생 동적메모리로 한다.
//	{
//    case WM_CREATE:
//		tlsIndex = TlsAlloc();//동적 TLS사용법
//		break; 
//	case WM_LBUTTONDOWN:
//		ptp = new TParam;
//		ptp->hwnd = hwnd;
//		ptp->pt.x = LOWORD(lParam);
//		ptp->pt.y = HIWORD(lParam);
//		CloseHandle(CreateThread(NULL,0,TF,(LPVOID)ptp,0,&id)); 
//		//Close를 해줘야 커널오브젝트가 핸들테이블에 남아있지않고 스레드가 종료될때 제거된다.
//		//다사용하고나서 Close를 꼭해줘야함.
//		break;
//		//case RBUTTON
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		TlsFree(tlsIndex);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//#include <windows.h>
//#include<process.h>
//struct TParam
//{
//	HWND hwnd;
//	POINT pt;
//};
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//						 WPARAM wParam, LPARAM lParam);
//int tlsIndex;
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
//void DrawCount(HDC hdc,POINT pt,int count)
//{
//	TCHAR buf[200];
//	wsprintf(buf,"%d",count);
//	TextOut(hdc,pt.x,pt.y,buf,lstrlen(buf));
//}
//int AddCount()
//{
//	int count = (int)TlsGetValue(tlsIndex);//동적 TLS사용법
//	TlsSetValue(tlsIndex,(LPVOID)(count+1)); //동적 TLS사용법
//	return count++;
//}
//unsigned int _stdcall TF(void* pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	delete (TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//
//
//	while(1)
//	{
//		POINT ptText = {pt.x+40, pt.y-25};
//		DrawCount(hdc , ptText , AddCount() );
//		for(int i = 0;i<100;i+=5)
//		{
//			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//			Sleep(100);
//		}
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	unsigned int id;
//	TParam* ptp;  //스레드 사이에는 지역변수를 보내지않는다. main의 지역변수를 넘겨줄수 없다.
//	switch (iMsg)	//static변수사용시 중첩현상발생 동적메모리로 한다.
//	{
//    case WM_CREATE:
//		tlsIndex = TlsAlloc();//동적 TLS사용법
//		break; 
//	case WM_LBUTTONDOWN:
//		ptp = new TParam;
//		ptp->hwnd = hwnd;
//		ptp->pt.x = LOWORD(lParam);
//		ptp->pt.y = HIWORD(lParam);
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//		//Close를 해줘야 커널오브젝트가 핸들테이블에 남아있지않고 스레드가 종료될때 제거된다.
//		//다사용하고나서 Close를 꼭해줘야함.
//		break;
//		//case RBUTTON
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		TlsFree(tlsIndex);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}


#include <windows.h>
#include<process.h>
#include<vector>
using namespace std;
struct TParam
{
	HWND hwnd;
	POINT pt;
};
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
						 WPARAM wParam, LPARAM lParam);
int tlsIndex;
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
void DrawCount(HDC hdc,POINT pt,int count)
{
	TCHAR buf[200];
	wsprintf(buf,"%d",count);
	TextOut(hdc,pt.x,pt.y,buf,lstrlen(buf));
}
int AddCount()
{
	int count = (int)TlsGetValue(tlsIndex);//동적 TLS사용법
	TlsSetValue(tlsIndex,(LPVOID)(count+1)); //동적 TLS사용법
	return count++;
}
unsigned int _stdcall TF(void* pParam)
{
	TParam tp = *(TParam*)pParam;
	delete (TParam*)pParam;
	HDC hdc = GetDC(tp.hwnd);
	POINT pt = tp.pt;


	while(1)
	{
		POINT ptText = {pt.x+40, pt.y-25};
		DrawCount(hdc , ptText , AddCount() );
		for(int i = 0;i<100;i+=5)
		{
			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
			Sleep(100);
		}
	}
	ReleaseDC(tp.hwnd,hdc);
	return 0;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
                         WPARAM wParam, LPARAM lParam) 
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	unsigned int id;
	static vector<HANDLE> threadArray;
	TParam* ptp;  //스레드 사이에는 지역변수를 보내지않는다. main의 지역변수를 넘겨줄수 없다.
	switch (iMsg)	//static변수사용시 중첩현상발생 동적메모리로 한다.
	{
    case WM_CREATE:
		tlsIndex = TlsAlloc();//동적 TLS사용법
		break; 
	case WM_LBUTTONDOWN:
		ptp = new TParam;
		ptp->hwnd = hwnd;
		ptp->pt.x = LOWORD(lParam);
		ptp->pt.y = HIWORD(lParam);
		threadArray.push_back((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
		//createthread()보다 _beginthreadex()를 쓰는것을 권장한다.
		//Close를 해줘야 커널오브젝트가 핸들테이블에 남아있지않고 스레드가 종료될때 제거된다.
		//다사용하고나서 Close를 꼭해줘야함.
		break;
	case WM_RBUTTONDOWN:
		{
			static bool bRun=true;
			if(bRun)
			{
				for(unsigned i=0;i<threadArray.size();i++)
				{
					SuspendThread(threadArray[i]); //스레드를 정지시키는 메서드
				}
			}
			else
			{
				for(unsigned i=0;i<threadArray.size();i++)
				{
					ResumeThread(threadArray[i]); //스레드를 정지시키는 메서드
				}
			}
			bRun = !bRun;
		}
		break;
    case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		// 이곳에서 출력이 이루어짐
		EndPaint(hwnd, &ps);
		break; 
    case WM_DESTROY:
		for(unsigned i=0;i<threadArray.size();i++)
		{
			CloseHandle(threadArray[i]);
		}
		PostQuitMessage(0);
		TlsFree(tlsIndex);
		break; 
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}