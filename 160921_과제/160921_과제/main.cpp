//
////1.
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
//DWORD _stdcall TFR(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//
//	while(1)
//	{
//		for(int i = 255;i>=0;i-=5)
//		{
//			HBRUSH newHbrush = CreateSolidBrush(RGB(i,0,0));
//			HBRUSH oldHbrush = (HBRUSH)SelectObject(hdc,newHbrush);
//			Rectangle(hdc,0,0,pt.x/2,pt.y/2);
//			Sleep(1);
//			SelectObject(hdc, oldHbrush);
//			DeleteObject(newHbrush);
//		}
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//DWORD _stdcall TFG(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//	while(1)
//	{
//		for(int i = 255;i>=0;i-=5)
//		{
//			HBRUSH newHbrush = CreateSolidBrush(RGB(0,i,0));
//			HBRUSH oldHbrush = (HBRUSH)SelectObject(hdc,newHbrush);
//			Rectangle(hdc,pt.x/2,0,pt.x,pt.y/2);
//			Sleep(1);
//			SelectObject(hdc, oldHbrush);
//			DeleteObject(newHbrush);
//		}
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//DWORD _stdcall TFB(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//
//
//	while(1)
//	{
//		for(int i = 255;i>=0;i-=5)
//		{
//			HBRUSH newHbrush = CreateSolidBrush(RGB(0,0,i));
//			HBRUSH oldHbrush = (HBRUSH)SelectObject(hdc,newHbrush);
//			Rectangle(hdc,0,pt.y/2,pt.x/2,pt.y);
//			Sleep(1);
//			SelectObject(hdc, oldHbrush);
//			DeleteObject(newHbrush);
//		}
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//DWORD _stdcall TFBL(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	delete (TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//
//
//	while(1)
//	{
//		for(int i = 255;i>=0;i-=5)
//		{
//			HBRUSH newHbrush = CreateSolidBrush(RGB(i,i,i));
//			HBRUSH oldHbrush = (HBRUSH)SelectObject(hdc,newHbrush);
//			Rectangle(hdc,pt.x/2,pt.y/2,pt.x,pt.y);
//			Sleep(1);
//			SelectObject(hdc, oldHbrush);
//			DeleteObject(newHbrush);
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
//	RECT clientrt;
//	switch (iMsg)	//static변수사용시 중첩현상발생 동적메모리로 한다.
//	{
//    case WM_CREATE:
//		GetClientRect(hwnd,&clientrt);
//		ptp = new TParam;
//		ptp->hwnd = hwnd;
//		ptp->pt.x = clientrt.right;
//		ptp->pt.y = clientrt.bottom;
//		CloseHandle(CreateThread(NULL,0,TFR,(LPVOID)ptp,0,&id));
//		CloseHandle(CreateThread(NULL,0,TFG,(LPVOID)ptp,0,&id));
//		CloseHandle(CreateThread(NULL,0,TFB,(LPVOID)ptp,0,&id));
//		Sleep(10);
//		CloseHandle(CreateThread(NULL,0,TFBL,(LPVOID)ptp,0,&id));
//		break; 
//	case WM_SIZE:
//		GetClientRect(hwnd,&clientrt);
//
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




////2.
//#include <windows.h>
//HANDLE hMutex;
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
//DWORD _stdcall TFR(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//
//	while(1)
//	{
//		WaitForSingleObject(hMutex,INFINITE);
//		for(int i = 255;i>=0;i-=10)
//		{
//			HBRUSH newHbrush = CreateSolidBrush(RGB(i,0,0));
//			HBRUSH oldHbrush = (HBRUSH)SelectObject(hdc,newHbrush);
//			Rectangle(hdc,0,0,pt.x/2,pt.y/2);
//			Sleep(1);
//			SelectObject(hdc, oldHbrush);
//			DeleteObject(newHbrush);
//		}
//		ReleaseMutex(hMutex);
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//DWORD _stdcall TFG(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//	while(1)
//	{
//		WaitForSingleObject(hMutex,INFINITE);
//		for(int i = 255;i>=0;i-=10)
//		{
//			HBRUSH newHbrush = CreateSolidBrush(RGB(0,i,0));
//			HBRUSH oldHbrush = (HBRUSH)SelectObject(hdc,newHbrush);
//			Rectangle(hdc,pt.x/2,0,pt.x,pt.y/2);
//			Sleep(1);
//			SelectObject(hdc, oldHbrush);
//			DeleteObject(newHbrush);
//		}
//		ReleaseMutex(hMutex);
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//DWORD _stdcall TFB(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//
//
//	while(1)
//	{
//		WaitForSingleObject(hMutex,INFINITE);
//		for(int i = 255;i>=0;i-=10)
//		{
//			HBRUSH newHbrush = CreateSolidBrush(RGB(0,0,i));
//			HBRUSH oldHbrush = (HBRUSH)SelectObject(hdc,newHbrush);
//			Rectangle(hdc,0,pt.y/2,pt.x/2,pt.y);
//			Sleep(1);
//			SelectObject(hdc, oldHbrush);
//			DeleteObject(newHbrush);
//		}
//		ReleaseMutex(hMutex);
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//DWORD _stdcall TFBL(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	delete (TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//
//
//	while(1)
//	{
//		WaitForSingleObject(hMutex,INFINITE);
//		for(int i = 255;i>=0;i-=10)
//		{
//			HBRUSH newHbrush = CreateSolidBrush(RGB(i,i,i));
//			HBRUSH oldHbrush = (HBRUSH)SelectObject(hdc,newHbrush);
//			Rectangle(hdc,pt.x/2,pt.y/2,pt.x,pt.y);
//			Sleep(1);
//			SelectObject(hdc, oldHbrush);
//			DeleteObject(newHbrush);
//		}
//		ReleaseMutex(hMutex);
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
//	RECT clientrt;
//	switch (iMsg)	//static변수사용시 중첩현상발생 동적메모리로 한다.
//	{
//    case WM_CREATE:
//		GetClientRect(hwnd,&clientrt);
//		ptp = new TParam;
//		ptp->hwnd = hwnd;
//		ptp->pt.x = clientrt.right;
//		ptp->pt.y = clientrt.bottom;
//		hMutex = CreateMutex(NULL,FALSE,NULL);
//		CloseHandle(CreateThread(NULL,0,TFR,(LPVOID)ptp,0,&id));
//		CloseHandle(CreateThread(NULL,0,TFG,(LPVOID)ptp,0,&id));
//		CloseHandle(CreateThread(NULL,0,TFB,(LPVOID)ptp,0,&id));
//		CloseHandle(CreateThread(NULL,0,TFBL,(LPVOID)ptp,0,&id));
//		break; 
//	case WM_SIZE:
//		GetClientRect(hwnd,&clientrt);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		CloseHandle(hMutex);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//



//
////3.
//#include <windows.h>
//struct TParam
//{
//	HWND hwnd;
//	POINT pt;
//};
//int count=0;
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
//void Add_Set_count(HWND hwnd)
//{
//	TCHAR buf[100];
//	InterlockedIncrement((long*)&count);
//	wsprintf(buf,"fullcount: %d",count);
//	SetWindowText(hwnd,buf);
//}
//DWORD _stdcall TFR(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//
//	while(1)
//	{
//		for(int i = 255;i>=0;i-=4)
//		{
//			HBRUSH newHbrush = CreateSolidBrush(RGB(i,0,0));
//			HBRUSH oldHbrush = (HBRUSH)SelectObject(hdc,newHbrush);
//			Rectangle(hdc,0,0,pt.x/2,pt.y/2);
//			Sleep(1);
//			SelectObject(hdc, oldHbrush);
//			DeleteObject(newHbrush);
//		}
//		Add_Set_count(tp.hwnd);
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//DWORD _stdcall TFG(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//	while(1)
//	{
//		for(int i = 255;i>=0;i-=3)
//		{
//			HBRUSH newHbrush = CreateSolidBrush(RGB(0,i,0));
//			HBRUSH oldHbrush = (HBRUSH)SelectObject(hdc,newHbrush);
//			Rectangle(hdc,pt.x/2,0,pt.x,pt.y/2);
//			Sleep(1);
//			SelectObject(hdc, oldHbrush);
//			DeleteObject(newHbrush);
//		}
//		Add_Set_count(tp.hwnd);
//		
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//DWORD _stdcall TFB(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//
//
//	while(1)
//	{
//		for(int i = 255;i>=0;i-=2)
//		{
//			HBRUSH newHbrush = CreateSolidBrush(RGB(0,0,i));
//			HBRUSH oldHbrush = (HBRUSH)SelectObject(hdc,newHbrush);
//			Rectangle(hdc,0,pt.y/2,pt.x/2,pt.y);
//			Sleep(1);
//			SelectObject(hdc, oldHbrush);
//			DeleteObject(newHbrush);
//		}
//		Add_Set_count(tp.hwnd);
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//DWORD _stdcall TFBL(LPVOID pParam)
//{
//	TParam tp = *(TParam*)pParam;
//	delete (TParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	POINT pt = tp.pt;
//
//
//	while(1)
//	{
//		for(int i = 255;i>=0;i-=1)
//		{
//			HBRUSH newHbrush = CreateSolidBrush(RGB(i,i,i));
//			HBRUSH oldHbrush = (HBRUSH)SelectObject(hdc,newHbrush);
//			Rectangle(hdc,pt.x/2,pt.y/2,pt.x,pt.y);
//			Sleep(1);
//			SelectObject(hdc, oldHbrush);
//			DeleteObject(newHbrush);
//		}
//		Add_Set_count(tp.hwnd);
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
//	RECT clientrt;
//	switch (iMsg)	//static변수사용시 중첩현상발생 동적메모리로 한다.
//	{
//    case WM_CREATE:
//		GetClientRect(hwnd,&clientrt);
//		ptp = new TParam;
//		ptp->hwnd = hwnd;
//		ptp->pt.x = clientrt.right;
//		ptp->pt.y = clientrt.bottom;
//		CloseHandle(CreateThread(NULL,0,TFR,(LPVOID)ptp,0,&id));
//		CloseHandle(CreateThread(NULL,0,TFG,(LPVOID)ptp,0,&id));
//		CloseHandle(CreateThread(NULL,0,TFB,(LPVOID)ptp,0,&id));
//		Sleep(10);
//		CloseHandle(CreateThread(NULL,0,TFBL,(LPVOID)ptp,0,&id));
//		break; 
//	case WM_SIZE:
//		GetClientRect(hwnd,&clientrt);
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
