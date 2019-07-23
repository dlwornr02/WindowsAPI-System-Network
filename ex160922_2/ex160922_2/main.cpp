//
//////////////////세마포어 동기화//////////////////////
//#include <windows.h>
//#include <process.h>
//
//struct ThreadParam
//{
//	HWND hwnd;
//	HANDLE hSema;
//	POINT pt;
//	ThreadParam(HWND hw,HANDLE hs,int x,int y):hwnd(hw),hSema(hs)
//	{
//		pt.x=x;
//		pt.y=y;
//	}
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
//unsigned int _stdcall TF(void*pParam)
//{
//	ThreadParam tp = *(ThreadParam*)pParam;
//	delete (ThreadParam*)pParam;
//	while(1)
//	{
//		POINT pt = tp.pt;
//		WaitForSingleObject(tp.hSema,INFINITE);
//		HDC hdc = GetDC(tp.hwnd);
//		for(int i=0;i<=100;i+=5)
//		{
//			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//			Sleep(100);
//		}
//		ReleaseDC(tp.hwnd,hdc);
//		LONG pc;
//		ReleaseSemaphore(tp.hSema,1,&pc);
//	}
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static HANDLE hSema;
//	unsigned  int id;
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		hSema = CreateSemaphore(NULL,3,3,NULL); //처음시작할때 3개 최대3개까지동시작업
//		break; 
//	case WM_LBUTTONDOWN:
//		{
//			ThreadParam* ptp = new ThreadParam(hwnd,hSema,LOWORD(lParam),HIWORD(lParam));
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id)); //API함수가 아니라서 (void*)로 써준거임
//		}
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		CloseHandle(hSema);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}


//
//#include <windows.h>
//#include <process.h>
//
//struct ThreadParam
//{
//	HWND hwnd;
//	HANDLE hSema;
//	POINT pt;
//	ThreadParam(HWND hw,HANDLE hs,int x,int y):hwnd(hw),hSema(hs)
//	{
//		pt.x=x;
//		pt.y=y;
//	}
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
//unsigned int _stdcall TF(void*pParam)
//{
//	ThreadParam tp = *(ThreadParam*)pParam;
//	delete (ThreadParam*)pParam;
//	while(1)
//	{
//		POINT pt = tp.pt;
//		WaitForSingleObject(tp.hSema,INFINITE);
//		HDC hdc = GetDC(tp.hwnd);
//		for(int i=0;i<=100;i+=5)
//		{
//			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//			Sleep(100);
//		}
//		ReleaseDC(tp.hwnd,hdc);
//		LONG pc;
//		ReleaseSemaphore(tp.hSema,1,&pc);
//	}
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static HANDLE hSema;
//	unsigned  int id;
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		hSema = CreateSemaphore(NULL,1,3,NULL); //처음시작할때 3개 최대3개까지동시작업
//		break; 
//	case WM_LBUTTONDOWN:
//		{
//			ThreadParam* ptp = new ThreadParam(hwnd,hSema,LOWORD(lParam),HIWORD(lParam));
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id)); //API함수가 아니라서 (void*)로 써준거임
//		}
//		break;
//	case WM_RBUTTONDOWN:
//		ReleaseSemaphore(hSema,1,NULL);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		CloseHandle(hSema);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//
//#include <windows.h>
//#include <process.h>
//
//struct ThreadParam
//{
//	HWND hwnd;
//	HANDLE hSema;
//	POINT pt;
//	ThreadParam(HWND hw,HANDLE hs,int x,int y):hwnd(hw),hSema(hs)
//	{
//		pt.x=x;
//		pt.y=y;
//	}
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
//unsigned int _stdcall TF(void*pParam)
//{
//	ThreadParam tp = *(ThreadParam*)pParam;
//	delete (ThreadParam*)pParam;
//	while(1)
//	{
//		POINT pt = tp.pt;
//		WaitForSingleObject(tp.hSema,INFINITE);
//		HDC hdc = GetDC(tp.hwnd);
//		for(int i=0;i<=100;i+=5)
//		{
//			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//			Sleep(100);
//		}
//		ReleaseDC(tp.hwnd,hdc);
//		LONG pc;
//		ReleaseSemaphore(tp.hSema,1,&pc);
//	}
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static HANDLE hSema;
//	unsigned  int id;
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		hSema = CreateSemaphore(NULL,3,3,"mySemaphore77"); //처음시작할때 3개 최대3개까지동시작업
//		break; 
//	case WM_LBUTTONDOWN:
//		{
//			ThreadParam* ptp = new ThreadParam(hwnd,hSema,LOWORD(lParam),HIWORD(lParam));
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id)); //API함수가 아니라서 (void*)로 써준거임
//		}
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		CloseHandle(hSema);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}



//
///////////////////Event//////////////////
//
//#include <windows.h>
//#include <process.h>
//
//struct ThreadParam
//{
//	HWND hwnd;
//	HANDLE hEvent;
//	POINT pt;
//	ThreadParam(HWND hw,HANDLE hs,int x,int y):hwnd(hw),hEvent(hs)
//	{
//		pt.x=x;
//		pt.y=y;
//	}
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
//unsigned int _stdcall TF(void*pParam)
//{
//	ThreadParam tp = *(ThreadParam*)pParam;
//	delete (ThreadParam*)pParam;
//	while(1)
//	{
//		POINT pt = tp.pt;
//		WaitForSingleObject(tp.hEvent,INFINITE);
//		HDC hdc = GetDC(tp.hwnd);
//		for(int i=0;i<=100;i+=5)
//		{
//			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//			Sleep(100);
//		}
//		ReleaseDC(tp.hwnd,hdc);
//		SetEvent(tp.hEvent);
//	}
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static HANDLE hEvent;
//	unsigned  int id;
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		hEvent = CreateEvent(NULL,FALSE,TRUE,"mySemaphore77"); //처음시작할때 3개 최대3개까지동시작업
//		break; 
//	case WM_LBUTTONDOWN:
//		{
//			ThreadParam* ptp = new ThreadParam(hwnd,hEvent,LOWORD(lParam),HIWORD(lParam));
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id)); //API함수가 아니라서 (void*)로 써준거임
//		}
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		CloseHandle(hEvent);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}


//
/////////////////////Event//////////////////
//
//#include <windows.h>
//#include <process.h>
//
//struct ThreadParam
//{
//	HWND hwnd;
//	HANDLE hEvent;
//	POINT pt;
//	ThreadParam(HWND hw,HANDLE hs,int x,int y):hwnd(hw),hEvent(hs)
//	{
//		pt.x=x;
//		pt.y=y;
//	}
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
//unsigned int _stdcall TF(void*pParam)
//{
//	ThreadParam tp = *(ThreadParam*)pParam;
//	delete (ThreadParam*)pParam;
//	while(1)
//	{
//		POINT pt = tp.pt;
//		WaitForSingleObject(tp.hEvent,INFINITE);
//		HDC hdc = GetDC(tp.hwnd);
//		for(int i=0;i<=100;i+=5)
//		{
//			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//			Sleep(100);
//		}
//		ReleaseDC(tp.hwnd,hdc);
//		SetEvent(tp.hEvent);
//	}
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static HANDLE hEvent;
//	unsigned  int id;
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		hEvent = CreateEvent(NULL,3,3,"mySemaphore77"); //처음시작할때 3개 최대3개까지동시작업
//		break; 
//	case WM_LBUTTONDOWN:
//		{
//			ThreadParam* ptp = new ThreadParam(hwnd,hEvent,LOWORD(lParam),HIWORD(lParam));
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id)); //API함수가 아니라서 (void*)로 써준거임
//		}
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		CloseHandle(hEvent);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}



/////////////////////Event//////////////////
//
//#include <windows.h>
//#include <process.h>
//
//struct ThreadParam
//{
//	HWND hwnd;
//	HANDLE hEvent;
//	POINT pt;
//	ThreadParam(HWND hw,HANDLE hs,int x,int y):hwnd(hw),hEvent(hs)
//	{
//		pt.x=x;
//		pt.y=y;
//	}
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
//unsigned int _stdcall TF(void*pParam)
//{
//	ThreadParam tp = *(ThreadParam*)pParam;
//	delete (ThreadParam*)pParam;
//	while(1)
//	{
//		POINT pt = tp.pt;
//		WaitForSingleObject(tp.hEvent,INFINITE);
//		HDC hdc = GetDC(tp.hwnd);
//		for(int i=0;i<=100;i+=5)
//		{
//			Rectangle(hdc,pt.x,pt.y,pt.x+i,pt.y+i);
//			Sleep(100);
//		}
//		ReleaseDC(tp.hwnd,hdc);
//		SetEvent(tp.hEvent);
//	}
//	return 0;
//}
//void DrawRectangle(HDC hdc,const RECT rt)
//{
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static HANDLE hEvent;
//	static int cx,cy;
//	static RECT topLeft,topRight,bottom;
//	unsigned  int id;
//
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		hEvent = CreateEvent(NULL,3,3,"mySemaphore77"); //처음시작할때 3개 최대3개까지동시작업
//		break; 
//	case WM_SIZE:
//		cx = LOWORD(lParam);
//		cy = HIWORD(lParam);
//		SetRect(&topLeft,0,0,cx/2,cy/2);
//		SetRect(&topRight,cx/2,0,cx,cy/2);
//		SetRect(&bottom,0,cy/2,cx,cy);
//		break;
//	case WM_LBUTTONDOWN:
//		{
//			ThreadParam* ptp = new ThreadParam(hwnd,hEvent,LOWORD(lParam),HIWORD(lParam));
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id)); //API함수가 아니라서 (void*)로 써준거임
//		}
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRectangle(hdc,topLeft);
//		DrawRectangle(hdc,topRight);
//		DrawRectangle(hdc,bottom);
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		CloseHandle(hEvent);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//

//
/////////////////////Event//////////////////
//
//#include <windows.h>
//#include <process.h>
//
//struct ThreadParam
//{
//	HWND hwnd;
//	HANDLE hEvent;
//	RECT* prt;
//	int start,end;
//	ThreadParam(HWND hw,HANDLE hd,RECT rt,int st,int ed):hwnd(hw),hEvent(hd),prt(&rt),start(st),end(ed){}
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
//void DrawInteger(HDC hdc,RECT rt, int num)
//{
//	TCHAR buf[100];
//	wsprintf(buf,"%d",num);
//	DrawText(hdc,buf,-1,&rt,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
//}
//unsigned int _stdcall TF(void*pParam)
//{
//	ThreadParam tp = *(ThreadParam*)pParam;
//	delete (ThreadParam*)pParam;
//	HDC hdc = GetDC(tp.hwnd);
//	for(int i = tp.start;i<=tp.end;i++)
//	{
//		DrawInteger(hdc,*tp.prt,i);
//		Sleep(10);
//	}
//	ReleaseDC(tp.hwnd,hdc);
//	return 0;
//}
//void DrawRectangle(HDC hdc,const RECT rt)
//{
//	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static HANDLE hEvent;
//	static int cx,cy;
//	static RECT topLeft,topRight,bottom;
//	unsigned  int id;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		{
//			hEvent = CreateEvent(NULL,3,3,"mySemaphore77"); //처음시작할때 3개 최대3개까지동시작업
//
//
//			ThreadParam* ptp = NULL;
//
//			RECT rt = {0,0,200,200};
//
//			ptp = new ThreadParam(hwnd,hEvent,rt,1,1000);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id)); //API함수가 아니라서 (void*)로 써준거임
//
//			ptp = new ThreadParam(hwnd,hEvent,rt,1001,2000);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id)); //API함수가 아니라서 (void*)로 써준거임
//
//			ptp = new ThreadParam(hwnd,hEvent,rt,2001,3000);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id)); //API함수가 아니라서 (void*)로 써준거임
//		}
//		break;
//	case WM_SIZE:
//		cx = LOWORD(lParam);
//		cy = HIWORD(lParam);
//		SetRect(&topLeft,0,0,cx/2,cy/2);
//		SetRect(&topRight,cx/2,0,cx,cy/2);
//		SetRect(&bottom,0,cy/2,cx,cy);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRectangle(hdc,topLeft);
//		DrawRectangle(hdc,topRight);
//		DrawRectangle(hdc,bottom);
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		CloseHandle(hEvent);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//

//#include <windows.h>
//#include <process.h>                     //Event
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//                   WPARAM wParam, LPARAM lParam);
//
//struct ThreadParam
//{
//   HWND   hwnd;
//   HANDLE hEvent;
//   RECT* prt;
//   int start, end;
//   ThreadParam(HWND hw, HANDLE hd, RECT* prt, int st, int ed):hwnd(hw), hEvent(hd), prt(prt), start(st), end(ed){}
//};
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//               LPSTR lpszCmdLine, int nCmdShow)
//{
//   HWND     hwnd;
//   MSG     msg;
//   WNDCLASS WndClass;   
//   WndClass.style = CS_HREDRAW | CS_VREDRAW;
//   WndClass.lpfnWndProc = WndProc;      
//   WndClass.cbClsExtra   = 0;      
//   WndClass.cbWndExtra   = 0;      
//   WndClass.hInstance = hInstance;      
//   WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//   WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);   
//   WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   
//   WndClass.lpszMenuName = NULL;      
//   WndClass.lpszClassName = "Window Class Name";   
//   RegisterClass(&WndClass);   
//   hwnd = CreateWindow("Window Class Name",
//      "Window Title Name",
//      WS_OVERLAPPEDWINDOW,
//      CW_USEDEFAULT,   
//      CW_USEDEFAULT,   
//      CW_USEDEFAULT,   
//      CW_USEDEFAULT,   
//      NULL,   
//      NULL,   
//      hInstance,   
//      NULL    
//   );
//   ShowWindow(hwnd, nCmdShow);
//   UpdateWindow(hwnd);
//   while (GetMessage(&msg, NULL, 0, 0))
//   {
//      TranslateMessage(&msg);   
//      DispatchMessage(&msg);   
//   }   
//   return (int)msg.wParam;
//}
//void DrawInteger(HDC hdc, RECT rt, int num)
//{
//   TCHAR buf[100];
//   wsprintf(buf,"%d", num);
//   DrawText(hdc, buf, -1/*NULL문자일때까지*/, &rt, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
//}
//unsigned int _stdcall TF(void* pParam)
//{
//   ThreadParam tp = *(ThreadParam*)pParam;
//   delete (ThreadParam*)pParam;
//
//   HDC hdc = GetDC(tp.hwnd);
//   for(int i=tp.start; i<=tp.end; ++i)
//   {
//      DrawInteger(hdc, *tp.prt, i);
//	  GdiFlush();  //너무빠르면 안보이는데 이메서드를 써주면 보인다.
//      Sleep(1);
//   }
//   ReleaseDC(tp.hwnd, hdc);
//   return 0;
//}
//void DrawRectangle(HDC hdc, RECT rt)
//{
//   Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//   HDC         hdc;
//   PAINTSTRUCT ps;
//   unsigned int id;
//   static HANDLE hEvent;
//   static int cx,cy;
//   static RECT topLeft, topRight, bottom;
//
//   switch (iMsg)
//   {
//    case WM_CREATE:
//      hEvent = CreateEvent(NULL, TRUE/*자동*/,TRUE/*현재 신호상태*/, "MyEvent_789");  //mutex처럼 이름을 가지면 2개의 윈도우에서 실행 안된다. kernalObject이기에
//      {
//         ThreadParam* ptp = NULL;
//
//         ptp = new ThreadParam(hwnd, hEvent, &topLeft, 1, 1000);
//         CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//         ptp = new ThreadParam(hwnd, hEvent, &topRight, 1001, 2000);
//         CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//         ptp = new ThreadParam(hwnd, hEvent, &bottom, 2001, 3000);
//         CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//      }
//      break;
//   case WM_SIZE:
//      cx = LOWORD(lParam);
//      cy = HIWORD(lParam);
//      SetRect(&topLeft,0,0,cx/2,cy/2); // rect설정
//      SetRect(&topRight, cx/2,0,cx,cy/2);
//      SetRect(&bottom, 0,cy/2, cx,cy);//size가 바뀔대 사이즈도 바뀐다 그러니 참조를 보내야한다
//      break;
//    case WM_PAINT:
//      hdc = BeginPaint(hwnd, &ps);
//      DrawRectangle(hdc,topLeft);
//      DrawRectangle(hdc,topRight);
//      DrawRectangle(hdc,bottom);
//      EndPaint(hwnd, &ps);
//      break; 
//    case WM_DESTROY:
//      CloseHandle(hEvent);
//      PostQuitMessage(0);
//      break; 
//   }
//   return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//
//#include <windows.h>
//#include <process.h>                     //Event
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//                   WPARAM wParam, LPARAM lParam);
//HANDLE hLTMutex,hRTMutex,hBTMutex;
//struct ThreadParam
//{
//   HWND   hwnd;
//   HANDLE hEvent;
//   HANDLE hMutex;
//   RECT* prt;
//   int start, end;
//   ThreadParam(HWND hw, HANDLE hd,HANDLE hm, RECT* prt, int st, int ed):hwnd(hw), hEvent(hd),hMutex(hm), prt(prt), start(st), end(ed){}
//};
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//               LPSTR lpszCmdLine, int nCmdShow)
//{
//   HWND     hwnd;
//   MSG     msg;
//   WNDCLASS WndClass;   
//   WndClass.style = CS_HREDRAW | CS_VREDRAW;
//   WndClass.lpfnWndProc = WndProc;      
//   WndClass.cbClsExtra   = 0;      
//   WndClass.cbWndExtra   = 0;      
//   WndClass.hInstance = hInstance;      
//   WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//   WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);   
//   WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   
//   WndClass.lpszMenuName = NULL;      
//   WndClass.lpszClassName = "Window Class Name";   
//   RegisterClass(&WndClass);   
//   hwnd = CreateWindow("Window Class Name",
//      "Window Title Name",
//      WS_OVERLAPPEDWINDOW,
//      CW_USEDEFAULT,   
//      CW_USEDEFAULT,   
//      CW_USEDEFAULT,   
//      CW_USEDEFAULT,   
//      NULL,   
//      NULL,   
//      hInstance,   
//      NULL    
//   );
//   ShowWindow(hwnd, nCmdShow);
//   UpdateWindow(hwnd);
//   while (GetMessage(&msg, NULL, 0, 0))
//   {
//      TranslateMessage(&msg);   
//      DispatchMessage(&msg);   
//   }   
//   return (int)msg.wParam;
//}
//void DrawInteger(HDC hdc, RECT rt, int num)
//{
//   TCHAR buf[100];
//   wsprintf(buf,"%d", num);
//   DrawText(hdc, buf, -1/*NULL문자일때까지*/, &rt, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
//}
//unsigned int _stdcall TF(void* pParam)
//{
//   ThreadParam tp = *(ThreadParam*)pParam;
//   delete (ThreadParam*)pParam;
//
//   HDC hdc = GetDC(tp.hwnd);
//   for(int i=tp.start; i<=tp.end; ++i)
//   {
//	   WaitForSingleObject(tp.hMutex,INFINITE);
//	  RECT rt = *tp.prt;
//	  ReleaseMutex(tp.hMutex);
//
//      DrawInteger(hdc, rt, i);
//	  GdiFlush();  //너무빠르면 안보이는데 이메서드를 써주면 보인다.
//      Sleep(1);
//   }
//   ReleaseDC(tp.hwnd, hdc);
//   return 0;
//}
//void DrawRectangle(HDC hdc, RECT rt)
//{
//   Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//   HDC         hdc;
//   PAINTSTRUCT ps;
//   unsigned int id;
//   static HANDLE hEvent;
//   static int cx,cy;
//   static RECT topLeft, topRight, bottom;
//
//   switch (iMsg)
//   {
//    case WM_CREATE:
//      hEvent = CreateEvent(NULL, TRUE/*자동*/,TRUE/*현재 신호상태*/, "MyEvent_789");  //mutex처럼 이름을 가지면 2개의 윈도우에서 실행 안된다. kernalObject이기에
//	  hLTMutex = CreateMutex(NULL,FALSE,NULL);
//	  hRTMutex = CreateMutex(NULL,FALSE,NULL);
//	  hBTMutex = CreateMutex(NULL,FALSE,NULL);
//      {
//         ThreadParam* ptp = NULL;
//
//         ptp = new ThreadParam(hwnd, hEvent,hLTMutex, &topLeft, 1, 1000);
//         CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//         ptp = new ThreadParam(hwnd, hEvent,hRTMutex, &topRight, 1001, 2000);
//         CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//         ptp = new ThreadParam(hwnd, hEvent,hBTMutex, &bottom, 2001, 3000);
//         CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//      }
//      break;
//   case WM_SIZE:
//      cx = LOWORD(lParam);
//      cy = HIWORD(lParam);
//	  WaitForSingleObject(hLTMutex,INFINITE);
//      SetRect(&topLeft,0,0,cx/2,cy/2); // rect설정
//	  ReleaseMutex(hLTMutex);
//      
//	  WaitForSingleObject(hRTMutex,INFINITE);
//	  SetRect(&topRight, cx/2,0,cx,cy/2);
//	  ReleaseMutex(hRTMutex);
//      
//	  WaitForSingleObject(hBTMutex,INFINITE);
//	  SetRect(&bottom, 0,cy/2, cx,cy);//size가 바뀔대 사이즈도 바뀐다 그러니 참조를 보내야한다
//	  ReleaseMutex(hBTMutex);
//
//      break;
//    case WM_PAINT:
//      hdc = BeginPaint(hwnd, &ps);
//      DrawRectangle(hdc,topLeft);
//      DrawRectangle(hdc,topRight);
//      DrawRectangle(hdc,bottom);
//      EndPaint(hwnd, &ps);
//      break; 
//    case WM_DESTROY:
//      CloseHandle(hEvent);
//      CloseHandle(hLTMutex);
//      CloseHandle(hRTMutex);
//      CloseHandle(hBTMutex);
//      PostQuitMessage(0);
//      break; 
//   }
//   return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}


//
//
//#include <windows.h>
//#include <process.h>                     //Event
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//                   WPARAM wParam, LPARAM lParam);
//struct ThreadParam
//{
//   HWND   hwnd;
//   HANDLE hEvent;
//   HANDLE hMutex;
//   int*pResult;
//   RECT* prt;
//   int start, end;
//   ThreadParam(HWND hw, HANDLE hd,HANDLE hm, RECT* prt, int st, int ed,int* pr):hwnd(hw), hEvent(hd),hMutex(hm), prt(prt), start(st), end(ed),pResult(pr){}
//};
//struct Thread2Param
//{
//   HWND   hwnd;
//   HANDLE hEvent[2];
//   HANDLE hMutex;
//   int*pResult[2];
//   RECT* prt;
//   int start, end;
//   Thread2Param(HWND hw, HANDLE he1,HANDLE he2, RECT* prt, int st, int ed,int*pr1,int*pr2):hwnd(hw), prt(prt), start(st), end(ed)
//   {
//	   hEvent[0] = he1;
//	   hEvent[1] = he2;
//	   pResult[0] = pr1;
//	   pResult[1] = pr2;
//   }
//};
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//               LPSTR lpszCmdLine, int nCmdShow)
//{
//   HWND     hwnd;
//   MSG     msg;
//   WNDCLASS WndClass;   
//   WndClass.style = CS_HREDRAW | CS_VREDRAW;
//   WndClass.lpfnWndProc = WndProc;      
//   WndClass.cbClsExtra   = 0;      
//   WndClass.cbWndExtra   = 0;      
//   WndClass.hInstance = hInstance;      
//   WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//   WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);   
//   WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   
//   WndClass.lpszMenuName = NULL;      
//   WndClass.lpszClassName = "Window Class Name";   
//   RegisterClass(&WndClass);   
//   hwnd = CreateWindow("Window Class Name",
//      "Window Title Name",
//      WS_OVERLAPPEDWINDOW,
//      CW_USEDEFAULT,   
//      CW_USEDEFAULT,   
//      CW_USEDEFAULT,   
//      CW_USEDEFAULT,   
//      NULL,   
//      NULL,   
//      hInstance,   
//      NULL    
//   );
//   ShowWindow(hwnd, nCmdShow);
//   UpdateWindow(hwnd);
//   while (GetMessage(&msg, NULL, 0, 0))
//   {
//      TranslateMessage(&msg);   
//      DispatchMessage(&msg);   
//   }   
//   return (int)msg.wParam;
//}
//void DrawInteger(HDC hdc, RECT rt, int num)
//{
//   TCHAR buf[100];
//   wsprintf(buf,"%d", num);
//   DrawText(hdc, buf, -1/*NULL문자일때까지*/, &rt, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
//}
//unsigned int _stdcall TF(void* pParam)
//{
//   ThreadParam tp = *(ThreadParam*)pParam;
//   delete (ThreadParam*)pParam;
//
//   HDC hdc = GetDC(tp.hwnd);
//   for(int i=tp.start; i<=tp.end; ++i)
//   {
//	   *tp.pResult += i;
//
//	   WaitForSingleObject(tp.hMutex,INFINITE);
//	  RECT rt = *tp.prt;
//	  ReleaseMutex(tp.hMutex);
//
//      DrawInteger(hdc, rt, i);
//	  GdiFlush();  //너무빠르면 안보이는데 이메서드를 써주면 보인다.
//      Sleep(1);
//   }
//   ReleaseDC(tp.hwnd, hdc);
//
//   SetEvent(tp.hEvent);
//   return 0;
//}
//unsigned int _stdcall TF_Result(void* pParam)
//{
//   Thread2Param tp = *(Thread2Param*)pParam;
//   delete (Thread2Param*)pParam;
//
//   int nResult = 0;
//   HDC hdc = GetDC(tp.hwnd);
//   for(int i=tp.start; i<=tp.end; ++i)
//   {
//	   nResult +=i;
//	   WaitForSingleObject(tp.hMutex,INFINITE);
//	  RECT rt = *tp.prt;
//	  ReleaseMutex(tp.hMutex);
//
//      DrawInteger(hdc, rt, i);
//	  GdiFlush();  //너무빠르면 안보이는데 이메서드를 써주면 보인다.
//      Sleep(1);
//   }
//   WaitForMultipleObjects(2,tp.hEvent,TRUE,INFINITE);
//   int sum = nResult + *tp.pResult[0] + *tp.pResult[1];
//   {
//	   TCHAR buf[100];
//	   wsprintf(buf,"T1+T2+T3 = %d",sum);
//	   TextOut(hdc,tp.prt->right/2,tp.prt->bottom/2+100,buf,lstrlen(buf));
//   }
//   ReleaseDC(tp.hwnd, hdc);
//   return 0;
//}
//
//void DrawRectangle(HDC hdc, RECT rt)
//{
//   Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//   HDC         hdc;
//   PAINTSTRUCT ps;
//   static HANDLE hLTMutex,hRTMutex,hBTMutex;
//   unsigned int id;
//   static HANDLE hT1Event,hT2Event;
//   static int cx,cy;
//   static int nResultT1,nResultT2;
//   static RECT topLeft, topRight, bottom;
//
//   switch (iMsg)
//   {
//    case WM_CREATE:
//      hT1Event = CreateEvent(NULL, TRUE/*자동*/,TRUE/*현재 신호상태*/, NULL);  //mutex처럼 이름을 가지면 2개의 윈도우에서 실행 안된다. kernalObject이기에
//      hT2Event = CreateEvent(NULL, TRUE/*자동*/,TRUE/*현재 신호상태*/, NULL);  //mutex처럼 이름을 가지면 2개의 윈도우에서 실행 안된다. kernalObject이기에
//	  hLTMutex = CreateMutex(NULL,FALSE,NULL);
//	  hRTMutex = CreateMutex(NULL,FALSE,NULL);
//	  hBTMutex = CreateMutex(NULL,FALSE,NULL);
//      {
//         ThreadParam* ptp = NULL;
//
//         ptp = new ThreadParam(hwnd, hT1Event,hLTMutex, &topLeft, 1, 1000,&nResultT1);
//         CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//         ptp = new ThreadParam(hwnd, hT2Event,hRTMutex, &topRight, 1001, 2000,&nResultT2);
//         CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//         Thread2Param* ptp2 = new Thread2Param(hwnd, hT1Event, hT2Event, &bottom, 2001, 3000,&nResultT1,&nResultT2);
//         CloseHandle((HANDLE)_beginthreadex(NULL,0,TF_Result,(void*)ptp2,0,&id));
//      }
//      break;
//   case WM_SIZE:
//      cx = LOWORD(lParam);
//      cy = HIWORD(lParam);
//	  WaitForSingleObject(hLTMutex,INFINITE);
//      SetRect(&topLeft,0,0,cx/2,cy/2); // rect설정
//	  ReleaseMutex(hLTMutex);
//      
//	  WaitForSingleObject(hRTMutex,INFINITE);
//	  SetRect(&topRight, cx/2,0,cx,cy/2);
//	  ReleaseMutex(hRTMutex);
//      
//	  WaitForSingleObject(hBTMutex,INFINITE);
//	  SetRect(&bottom, 0,cy/2, cx,cy);//size가 바뀔대 사이즈도 바뀐다 그러니 참조를 보내야한다
//	  ReleaseMutex(hBTMutex);
//
//      break;
//    case WM_PAINT:
//      hdc = BeginPaint(hwnd, &ps);
//      DrawRectangle(hdc,topLeft);
//      DrawRectangle(hdc,topRight);
//      DrawRectangle(hdc,bottom);
//      EndPaint(hwnd, &ps);
//      break; 
//    case WM_DESTROY:
//      CloseHandle(hT1Event);
//      CloseHandle(hT2Event);
//      CloseHandle(hLTMutex);
//      CloseHandle(hRTMutex);
//      CloseHandle(hBTMutex);
//      PostQuitMessage(0);
//      break; 
//   }
//   return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//#include <windows.h>
//#include <process.h>                     //Event
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//struct ThreadParam
//{
//	HWND   hwnd;
//	HANDLE hEvent;
//	HANDLE hMutex;
//	int*pResult;
//	RECT* prt;
//	int start, end;
//	ThreadParam(HWND hw, HANDLE hd,HANDLE hm, RECT* prt, int st, int ed,int* pr):hwnd(hw), hEvent(hd),hMutex(hm), prt(prt), start(st), end(ed),pResult(pr){}
//};
//struct Thread2Param
//{
//	HWND   hwnd;
//	HANDLE hEvent[2];
//	HANDLE hMutex;
//	int*pResult[2];
//	RECT* prt;
//	int start, end;
//	Thread2Param(HWND hw, HANDLE he1,HANDLE he2, RECT* prt, int st, int ed,int*pr1,int*pr2):hwnd(hw), prt(prt), start(st), end(ed)
//	{
//		hEvent[0] = he1;
//		hEvent[1] = he2;
//		pResult[0] = pr1;
//		pResult[1] = pr2;
//	}
//};
//class Lock
//{
//	HANDLE hMutex;
//public:
//	Lock(HANDLE hm):hMutex(hm)
//	{
//		WaitForSingleObject(hMutex,INFINITE);
//	}
//	~Lock()
//	{
//		ReleaseMutex(hMutex);
//	}
//};
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND     hwnd;
//	MSG     msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;      
//	WndClass.cbClsExtra   = 0;      
//	WndClass.cbWndExtra   = 0;      
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
//		);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);   
//		DispatchMessage(&msg);   
//	}   
//	return (int)msg.wParam;
//}
//void DrawInteger(HDC hdc, RECT rt, int num)
//{
//	TCHAR buf[100];
//	wsprintf(buf,"%d", num);
//	DrawText(hdc, buf, -1/*NULL문자일때까지*/, &rt, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
//}
//unsigned int _stdcall TF(void* pParam)
//{
//	ThreadParam tp = *(ThreadParam*)pParam;
//	delete (ThreadParam*)pParam;
//
//	HDC hdc = GetDC(tp.hwnd);
//	for(int i=tp.start; i<=tp.end; ++i)
//	{
//		*tp.pResult += i;
//		RECT rt;
//		{
//			Lock lock(tp.hMutex);
//			rt = *tp.prt;
//			
//		}
//
//		DrawInteger(hdc, rt, i);
//		GdiFlush();  //너무빠르면 안보이는데 이메서드를 써주면 보인다.
//		Sleep(1);
//	}
//	ReleaseDC(tp.hwnd, hdc);
//
//	SetEvent(tp.hEvent);
//	return 0;
//}
//unsigned int _stdcall TF_Result(void* pParam)
//{
//	Thread2Param tp = *(Thread2Param*)pParam;
//	delete (Thread2Param*)pParam;
//
//	int nResult = 0;
//	HDC hdc = GetDC(tp.hwnd);
//	for(int i=tp.start; i<=tp.end; ++i)
//	{
//		nResult +=i;
//		WaitForSingleObject(tp.hMutex,INFINITE);
//		RECT rt = *tp.prt;
//		ReleaseMutex(tp.hMutex);
//
//		DrawInteger(hdc, rt, i);
//		GdiFlush();  //너무빠르면 안보이는데 이메서드를 써주면 보인다.
//		Sleep(1);
//	}
//	WaitForMultipleObjects(2,tp.hEvent,TRUE,INFINITE);
//	int sum = nResult + *tp.pResult[0] + *tp.pResult[1];
//	{
//		TCHAR buf[100];
//		wsprintf(buf,"T1+T2+T3 = %d",sum);
//		TextOut(hdc,tp.prt->right/2,tp.prt->bottom/2+100,buf,lstrlen(buf));
//	}
//	ReleaseDC(tp.hwnd, hdc);
//	return 0;
//}
//
//void DrawRectangle(HDC hdc, RECT rt)
//{
//	Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//	static HANDLE hLTMutex,hRTMutex,hBTMutex;
//	unsigned int id;
//	static HANDLE hT1Event,hT2Event;
//	static int cx,cy;
//	static int nResultT1,nResultT2;
//	static RECT topLeft, topRight, bottom;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		hT1Event = CreateEvent(NULL, TRUE/*자동*/,TRUE/*현재 신호상태*/, NULL);  //mutex처럼 이름을 가지면 2개의 윈도우에서 실행 안된다. kernalObject이기에
//		hT2Event = CreateEvent(NULL, TRUE/*자동*/,TRUE/*현재 신호상태*/, NULL);  //mutex처럼 이름을 가지면 2개의 윈도우에서 실행 안된다. kernalObject이기에
//		hLTMutex = CreateMutex(NULL,FALSE,NULL);
//		hRTMutex = CreateMutex(NULL,FALSE,NULL);
//		hBTMutex = CreateMutex(NULL,FALSE,NULL);
//		{
//			ThreadParam* ptp = NULL;
//
//			ptp = new ThreadParam(hwnd, hT1Event,hLTMutex, &topLeft, 1, 1000,&nResultT1);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//			ptp = new ThreadParam(hwnd, hT2Event,hRTMutex, &topRight, 1001, 2000,&nResultT2);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//			Thread2Param* ptp2 = new Thread2Param(hwnd, hT1Event, hT2Event, &bottom, 2001, 3000,&nResultT1,&nResultT2);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF_Result,(void*)ptp2,0,&id));
//		}
//		break;
//	case WM_SIZE:
//		cx = LOWORD(lParam);
//		cy = HIWORD(lParam);
//
//		{
//			Lock lock(hLTMutex);
//			SetRect(&topLeft,0,0,cx/2,cy/2); // rect설정
//		}
//
//		{
//			Lock lock(hRTMutex);
//			SetRect(&topRight, cx/2,0,cx,cy/2);
//		}
//
//		{
//			Lock lock(hBTMutex);
//			SetRect(&bottom, 0,cy/2, cx,cy);//size가 바뀔대 사이즈도 바뀐다 그러니 참조를 보내야한다
//		}
//
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRectangle(hdc,topLeft);
//		DrawRectangle(hdc,topRight);
//		DrawRectangle(hdc,bottom);
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		CloseHandle(hT1Event);
//		CloseHandle(hT2Event);
//		CloseHandle(hLTMutex);
//		CloseHandle(hRTMutex);
//		CloseHandle(hBTMutex);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//#include <windows.h>
//#include <process.h>                     //Event
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//struct ThreadParam
//{
//	HWND   hwnd;
//	HANDLE hEvent;
//	HANDLE hMutex;
//	int*pResult;
//	RECT* prt;
//	int start, end;
//	ThreadParam(HWND hw, HANDLE hd,HANDLE hm, RECT* prt, int st, int ed,int* pr):hwnd(hw), hEvent(hd),hMutex(hm), prt(prt), start(st), end(ed),pResult(pr){}
//};
//struct Thread2Param
//{
//	HWND   hwnd;
//	HANDLE hEvent[2];
//	HANDLE hMutex;
//	int*pResult[2];
//	RECT* prt;
//	int start, end;
//	Thread2Param(HWND hw, HANDLE he1,HANDLE he2, RECT* prt, int st, int ed,int*pr1,int*pr2):hwnd(hw), prt(prt), start(st), end(ed)
//	{
//		hEvent[0] = he1;
//		hEvent[1] = he2;
//		pResult[0] = pr1;
//		pResult[1] = pr2;
//	}
//};
//class Lock
//{
//	HANDLE hMutex;
//public:
//	Lock(HANDLE hm):hMutex(hm)
//	{
//		WaitForSingleObject(hMutex,INFINITE);
//	}
//	~Lock()
//	{
//		ReleaseMutex(hMutex);
//	}
//};
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND     hwnd;
//	MSG     msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;      
//	WndClass.cbClsExtra   = 0;      
//	WndClass.cbWndExtra   = 0;      
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
//		);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);   
//		DispatchMessage(&msg);   
//	}   
//	return (int)msg.wParam;
//}
//void DrawInteger(HDC hdc, RECT rt, int num)
//{
//	TCHAR buf[100];
//	wsprintf(buf,"%d", num);
//	DrawText(hdc, buf, -1/*NULL문자일때까지*/, &rt, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
//}
//unsigned int _stdcall TF(void* pParam)
//{
//	ThreadParam tp = *(ThreadParam*)pParam;
//	delete (ThreadParam*)pParam;
//
//	HDC hdc = GetDC(tp.hwnd);
//	for(int i=tp.start; i<=tp.end; ++i)
//	{
//		*tp.pResult += i;
//		RECT rt;
//		{
//			Lock lock(tp.hMutex);
//			rt = *tp.prt;
//			
//		}
//
//		DrawInteger(hdc, rt, i);
//		GdiFlush();  //너무빠르면 안보이는데 이메서드를 써주면 보인다.
//		Sleep(1);
//	}
//	ReleaseDC(tp.hwnd, hdc);
//
//	SetEvent(tp.hEvent);
//	return 0;
//}
//void DrawResult(HDC hdc,POINT pt,int sum)
//{
//	TCHAR buf[100];
//	wsprintf(buf,"T1+T2+T3 = %d",sum);
//	TextOut(hdc,pt.x,pt.y,buf,lstrlen(buf));
//}
//unsigned int _stdcall TF_Result(void* pParam)
//{
//	Thread2Param tp = *(Thread2Param*)pParam;
//	delete (Thread2Param*)pParam;
//
//	int nResult = 0;
//	HDC hdc = GetDC(tp.hwnd);
//	for(int i=tp.start; i<=tp.end; ++i)
//	{
//		nResult +=i;
//		WaitForSingleObject(tp.hMutex,INFINITE);
//		RECT rt = *tp.prt;
//		ReleaseMutex(tp.hMutex);
//
//		DrawInteger(hdc, rt, i);
//		GdiFlush();  //너무빠르면 안보이는데 이메서드를 써주면 보인다.
//		Sleep(1);
//	}
//	WaitForMultipleObjects(2,tp.hEvent,TRUE,INFINITE);
//	int sum = nResult + *tp.pResult[0] + *tp.pResult[1];
//	POINT pt = {tp.prt->right/2,tp.prt->bottom/2+50};
//	DrawResult(hdc,pt,sum);
//	ReleaseDC(tp.hwnd, hdc);
//	return 0;
//}
//
//void DrawRectangle(HDC hdc, RECT rt)
//{
//	Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//	static HANDLE hLTMutex,hRTMutex,hBTMutex;
//	unsigned int id;
//	static HANDLE hT1Event,hT2Event;
//	static int cx,cy;
//	static int nResultT1,nResultT2;
//	static RECT topLeft, topRight, bottom;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		hT1Event = CreateEvent(NULL, TRUE/*자동*/,TRUE/*현재 신호상태*/, NULL);  //mutex처럼 이름을 가지면 2개의 윈도우에서 실행 안된다. kernalObject이기에
//		hT2Event = CreateEvent(NULL, TRUE/*자동*/,TRUE/*현재 신호상태*/, NULL);  //mutex처럼 이름을 가지면 2개의 윈도우에서 실행 안된다. kernalObject이기에
//		hLTMutex = CreateMutex(NULL,FALSE,NULL);
//		hRTMutex = CreateMutex(NULL,FALSE,NULL);
//		hBTMutex = CreateMutex(NULL,FALSE,NULL);
//		{
//			ThreadParam* ptp = NULL;
//
//			ptp = new ThreadParam(hwnd, hT1Event,hLTMutex, &topLeft, 1, 1000,&nResultT1);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//			ptp = new ThreadParam(hwnd, hT2Event,hRTMutex, &topRight, 1001, 2000,&nResultT2);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//			Thread2Param* ptp2 = new Thread2Param(hwnd, hT1Event, hT2Event, &bottom, 2001, 3000,&nResultT1,&nResultT2);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF_Result,(void*)ptp2,0,&id));
//		}
//		break;
//	case WM_SIZE:
//		cx = LOWORD(lParam);
//		cy = HIWORD(lParam);
//
//		{
//			Lock lock(hLTMutex);
//			SetRect(&topLeft,0,0,cx/2,cy/2); // rect설정
//		}
//
//		{
//			Lock lock(hRTMutex);
//			SetRect(&topRight, cx/2,0,cx,cy/2);
//		}
//
//		{
//			Lock lock(hBTMutex);
//			SetRect(&bottom, 0,cy/2, cx,cy);//size가 바뀔대 사이즈도 바뀐다 그러니 참조를 보내야한다
//		}
//
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRectangle(hdc,topLeft);
//		DrawRectangle(hdc,topRight);
//		DrawRectangle(hdc,bottom);
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		CloseHandle(hT1Event);
//		CloseHandle(hT2Event);
//		CloseHandle(hLTMutex);
//		CloseHandle(hRTMutex);
//		CloseHandle(hBTMutex);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//#include <windows.h>
//#include <process.h>                     //Event
//#include<vector>
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//struct ThreadParam
//{
//	HWND   hwnd;
//	HANDLE hEvent;
//	HANDLE hMutex;
//	int*pResult;
//	RECT* prt;
//	int start, end;
//	ThreadParam(HWND hw, HANDLE hd,HANDLE hm, RECT* prt, int st, int ed,int* pr):
//		hwnd(hw), hEvent(hd),hMutex(hm), prt(prt), start(st), end(ed),pResult(pr){}
//};
//struct Thread2Param
//{
//	HWND   hwnd;
//	vector<HANDLE> hEvent;
//	HANDLE hMutex;
//	vector<int*>pResult;
//	RECT* prt;
//	int start, end;
//	Thread2Param(HWND hw, const vector<HANDLE> he, RECT* prt, int st, int ed,vector<int*>pr):
//		hwnd(hw), hEvent(he),prt(prt), start(st), end(ed),pResult(pr){}
//};
//class Lock
//{
//	HANDLE hMutex;
//public:
//	Lock(HANDLE hm):hMutex(hm)
//	{
//		WaitForSingleObject(hMutex,INFINITE);
//	}
//	~Lock()
//	{
//		ReleaseMutex(hMutex);
//	}
//};
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND     hwnd;
//	MSG     msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;      
//	WndClass.cbClsExtra   = 0;      
//	WndClass.cbWndExtra   = 0;      
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
//		);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);   
//		DispatchMessage(&msg);   
//	}   
//	return (int)msg.wParam;
//}
//void DrawInteger(HDC hdc, RECT rt, int num)
//{
//	TCHAR buf[100];
//	wsprintf(buf,"%d", num);
//	DrawText(hdc, buf, -1/*NULL문자일때까지*/, &rt, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
//}
//unsigned int _stdcall TF(void* pParam)
//{
//	ThreadParam tp = *(ThreadParam*)pParam;
//	delete (ThreadParam*)pParam;
//
//	HDC hdc = GetDC(tp.hwnd);
//	for(int i=tp.start; i<=tp.end; ++i)
//	{
//		*tp.pResult += i;
//		RECT rt;
//		{
//			Lock lock(tp.hMutex);
//			rt = *tp.prt;
//			
//		}
//
//		DrawInteger(hdc, rt, i);
//		GdiFlush();  //너무빠르면 안보이는데 이메서드를 써주면 보인다.
//		Sleep(1);
//	}
//	ReleaseDC(tp.hwnd, hdc);
//
//	SetEvent(tp.hEvent);
//	return 0;
//}
//void DrawResult(HDC hdc,POINT pt,int sum)
//{
//	TCHAR buf[100];
//	wsprintf(buf,"T1+T2+T3 = %d",sum);
//	TextOut(hdc,pt.x,pt.y,buf,lstrlen(buf));
//}
//unsigned int _stdcall TF_Result(void* pParam)
//{
//	Thread2Param tp = *(Thread2Param*)pParam;
//	delete (Thread2Param*)pParam;
//
//	int nResult = 0;
//	HDC hdc = GetDC(tp.hwnd);
//	for(int i=tp.start; i<=tp.end; ++i)
//	{
//		nResult +=i;
//		WaitForSingleObject(tp.hMutex,INFINITE);
//		RECT rt = *tp.prt;
//		ReleaseMutex(tp.hMutex);
//
//		DrawInteger(hdc, rt, i);
//		GdiFlush();  //너무빠르면 안보이는데 이메서드를 써주면 보인다.
//		Sleep(1);
//	}
//	WaitForMultipleObjects(2,&tp.hEvent[0],TRUE,INFINITE);
//	int sum = nResult + *tp.pResult[0] + *tp.pResult[1];
//	POINT pt = {tp.prt->right/2,tp.prt->bottom/2+50};
//	DrawResult(hdc,pt,sum);
//	ReleaseDC(tp.hwnd, hdc);
//	return 0;
//}
//
//void DrawRectangle(HDC hdc, RECT rt)
//{
//	Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//	static HANDLE hLTMutex,hRTMutex,hBTMutex;
//	unsigned int id;
//	static HANDLE hT1Event,hT2Event;
//	static int cx,cy;
//	static int nResultT1,nResultT2;
//	static RECT topLeft, topRight, bottom;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		hT1Event = CreateEvent(NULL, TRUE/*자동*/,TRUE/*현재 신호상태*/, NULL);  //mutex처럼 이름을 가지면 2개의 윈도우에서 실행 안된다. kernalObject이기에
//		hT2Event = CreateEvent(NULL, TRUE/*자동*/,TRUE/*현재 신호상태*/, NULL);  //mutex처럼 이름을 가지면 2개의 윈도우에서 실행 안된다. kernalObject이기에
//		hLTMutex = CreateMutex(NULL,FALSE,NULL);
//		hRTMutex = CreateMutex(NULL,FALSE,NULL);
//		hBTMutex = CreateMutex(NULL,FALSE,NULL);
//		{
//			ThreadParam* ptp = NULL;
//
//			ptp = new ThreadParam(hwnd, hT1Event,hLTMutex, &topLeft, 1, 1000,&nResultT1);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//			ptp = new ThreadParam(hwnd, hT2Event,hRTMutex, &topRight, 1001, 2000,&nResultT2);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//
//			vector<HANDLE> eArray;
//			eArray.push_back(hT1Event);
//			eArray.push_back(hT2Event);
//			vector<int*>rArray;
//			rArray.push_back(&nResultT1);
//			rArray.push_back(&nResultT2);
//			Thread2Param* ptp2 = new Thread2Param(hwnd, eArray, &bottom, 2001, 3000,rArray);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF_Result,(void*)ptp2,0,&id));
//		}
//		break;
//	case WM_SIZE:
//		cx = LOWORD(lParam);
//		cy = HIWORD(lParam);
//
//		{
//			Lock lock(hLTMutex);
//			SetRect(&topLeft,0,0,cx/2,cy/2); // rect설정
//		}
//
//		{
//			Lock lock(hRTMutex);
//			SetRect(&topRight, cx/2,0,cx,cy/2);
//		}
//
//		{
//			Lock lock(hBTMutex);
//			SetRect(&bottom, 0,cy/2, cx,cy);//size가 바뀔대 사이즈도 바뀐다 그러니 참조를 보내야한다
//		}
//
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRectangle(hdc,topLeft);
//		DrawRectangle(hdc,topRight);
//		DrawRectangle(hdc,bottom);
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		CloseHandle(hT1Event);
//		CloseHandle(hT2Event);
//		CloseHandle(hLTMutex);
//		CloseHandle(hRTMutex);
//		CloseHandle(hBTMutex);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//#include <windows.h>
//#include <process.h>                     //Event
//#include<vector>
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//struct ThreadParam
//{
//	HWND   hwnd;
//	HANDLE hEvent;
//	HANDLE hMutex;
//	int*pResult;
//	RECT* prt;
//	int start, end;
//	ThreadParam(HWND hw, HANDLE hd,HANDLE hm, RECT* prt, int st, int ed,int* pr):
//		hwnd(hw), hEvent(hd),hMutex(hm), prt(prt), start(st), end(ed),pResult(pr){}
//};
//struct Thread2Param
//{
//	HWND   hwnd;
//	vector<HANDLE> hEvent;
//	HANDLE hMutex;
//	vector<int*>pResult;
//	RECT* prt;
//	int start, end;
//	Thread2Param(HWND hw, const vector<HANDLE> he,HANDLE hm, RECT* prt, int st, int ed,vector<int*>pr):
//		hwnd(hw), hEvent(he),hMutex(hm),prt(prt), start(st), end(ed),pResult(pr){}
//};
//class Lock
//{
//	HANDLE hMutex;
//public:
//	Lock(HANDLE hm):hMutex(hm)
//	{
//		WaitForSingleObject(hMutex,INFINITE);
//	}
//	~Lock()
//	{
//		ReleaseMutex(hMutex);
//	}
//};
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND     hwnd;
//	MSG     msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;      
//	WndClass.cbClsExtra   = 0;      
//	WndClass.cbWndExtra   = 0;      
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
//		);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);   
//		DispatchMessage(&msg);   
//	}   
//	return (int)msg.wParam;
//}
//void DrawInteger(HDC hdc, RECT rt, int num)
//{
//	TCHAR buf[100];
//	wsprintf(buf,"%d", num);
//	DrawText(hdc, buf, -1/*NULL문자일때까지*/, &rt, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
//}
//unsigned int _stdcall TF(void* pParam)
//{
//	ThreadParam tp = *(ThreadParam*)pParam;
//	delete (ThreadParam*)pParam;
//
//	HDC hdc = GetDC(tp.hwnd);
//	for(int i=tp.start; i<=tp.end; ++i)
//	{
//		*tp.pResult += i;
//		RECT rt;
//		{
//			Lock lock(tp.hMutex);
//			rt = *tp.prt;
//			
//		}
//
//		DrawInteger(hdc, rt, i);
//		GdiFlush();  //너무빠르면 안보이는데 이메서드를 써주면 보인다.
//		Sleep(1);
//	}
//	ReleaseDC(tp.hwnd, hdc);
//
//	SetEvent(tp.hEvent);
//	return 0;
//}
//void DrawResult(HDC hdc,POINT pt,int sum)
//{
//	TCHAR buf[100];
//	wsprintf(buf,"T1+T2+T3 = %d",sum);
//	TextOut(hdc,pt.x,pt.y,buf,lstrlen(buf));
//}
//unsigned int _stdcall TF_Result(void* pParam)
//{
//	Thread2Param tp = *(Thread2Param*)pParam;
//	delete (Thread2Param*)pParam;
//
//	int nResult = 0;
//	HDC hdc = GetDC(tp.hwnd);
//	for(int i=tp.start; i<=tp.end; ++i)
//	{
//		nResult +=i;
//		WaitForSingleObject(tp.hMutex,INFINITE);
//		RECT rt = *tp.prt;
//		ReleaseMutex(tp.hMutex);
//
//		DrawInteger(hdc, rt, i);
//		GdiFlush();  //너무빠르면 안보이는데 이메서드를 써주면 보인다.
//		Sleep(1);
//	}
//	WaitForMultipleObjects(2,&tp.hEvent[0],TRUE,INFINITE);
//	int sum = nResult + *tp.pResult[0] + *tp.pResult[1];
//	POINT pt = {tp.prt->right/2,tp.prt->bottom/2+50};
//	DrawResult(hdc,pt,sum);
//	ReleaseDC(tp.hwnd, hdc);
//	return 0;
//}
//
//void DrawRectangle(HDC hdc, RECT rt)
//{
//	Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//	static HANDLE hLTMutex,hRTMutex,hBTMutex;
//	unsigned int id;
//	static HANDLE hEvent[2];
//	static int cx,cy;
//	static int nResult1,nResult2;
//	static int* nResult[2]={&nResult1,&nResult2};
//	static RECT topLeft, topRight, bottom;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		hEvent[0] = CreateEvent(NULL, TRUE/*자동*/,TRUE/*현재 신호상태*/, NULL);  //mutex처럼 이름을 가지면 2개의 윈도우에서 실행 안된다. kernalObject이기에
//		hEvent[1] = CreateEvent(NULL, TRUE/*자동*/,TRUE/*현재 신호상태*/, NULL);  //mutex처럼 이름을 가지면 2개의 윈도우에서 실행 안된다. kernalObject이기에
//
//		hLTMutex = CreateMutex(NULL,FALSE,NULL);
//		hRTMutex = CreateMutex(NULL,FALSE,NULL);
//		hBTMutex = CreateMutex(NULL,FALSE,NULL);
//		{
//			 
//
//			ThreadParam* ptp = new ThreadParam(hwnd, hEvent[0],hLTMutex, &topLeft, 1, 1000,nResult[0]);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//			ptp = new ThreadParam(hwnd, hEvent[1],hRTMutex, &topRight, 1001, 2000,nResult[1]);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//
//			vector<HANDLE> eArray(hEvent,hEvent+2);
//			vector<int*>rArray(nResult,nResult+2);
//			Thread2Param* ptp2 = new Thread2Param(hwnd, eArray,hBTMutex, &bottom, 2001, 3000,rArray);
//			CloseHandle((HANDLE)_beginthreadex(NULL,0,TF_Result,(void*)ptp2,0,&id));
//		}
//		break;
//	case WM_SIZE:
//		cx = LOWORD(lParam);
//		cy = HIWORD(lParam);
//
//		{
//			Lock lock(hLTMutex);
//			SetRect(&topLeft,0,0,cx/2,cy/2); // rect설정
//		}
//
//		{
//			Lock lock(hRTMutex);
//			SetRect(&topRight, cx/2,0,cx,cy/2);
//		}
//
//		{
//			Lock lock(hBTMutex);
//			SetRect(&bottom, 0,cy/2, cx,cy);//size가 바뀔대 사이즈도 바뀐다 그러니 참조를 보내야한다
//		}
//
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRectangle(hdc,topLeft);
//		DrawRectangle(hdc,topRight);
//		DrawRectangle(hdc,bottom);
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		CloseHandle(hEvent[0]);
//		CloseHandle(hEvent[1]);
//
//		CloseHandle(hLTMutex);
//		CloseHandle(hRTMutex);
//		CloseHandle(hBTMutex);
//
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}


//
//
//#include <windows.h>
//#include <process.h>                     //Event
//#include<vector>
//using namespace std;
//int sum=0;
//HANDLE hSMutex;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//struct ThreadParam
//{
//	HWND   hwnd;
//	HANDLE hEvent;
//	HANDLE hMutex;
//	int*pResult;
//	RECT* prt;
//	int start, end;
//	ThreadParam(HWND hw, HANDLE hd,HANDLE hm, RECT* prt, int st, int ed,int* pr):
//		hwnd(hw), hEvent(hd),hMutex(hm), prt(prt), start(st), end(ed),pResult(pr){}
//};
//struct Thread2Param
//{
//	HWND   hwnd;
//	vector<HANDLE> hEvent;
//	HANDLE hMutex;
//	vector<int*>pResult;
//	RECT* prt;
//	int start, end;
//	Thread2Param(HWND hw, const vector<HANDLE> he,HANDLE hm, RECT* prt, int st, int ed,vector<int*>pr):
//		hwnd(hw), hEvent(he),hMutex(hm),prt(prt), start(st), end(ed),pResult(pr){}
//};
//class Lock
//{
//	HANDLE hMutex;
//public:
//	Lock(HANDLE hm):hMutex(hm)
//	{
//		WaitForSingleObject(hMutex,INFINITE);
//	}
//	~Lock()
//	{
//		ReleaseMutex(hMutex);
//	}
//};
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	HWND     hwnd;
//	MSG     msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;      
//	WndClass.cbClsExtra   = 0;      
//	WndClass.cbWndExtra   = 0;      
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
//		);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);   
//		DispatchMessage(&msg);   
//	}   
//	return (int)msg.wParam;
//}
//void DrawInteger(HDC hdc, RECT rt, int num)
//{
//	TCHAR buf[100];
//	wsprintf(buf,"%d", num);
//	DrawText(hdc, buf, -1/*NULL문자일때까지*/, &rt, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
//}
//void CalMiddleResult(int data)
//{
//	{
//		sum+=data;
//	}
//}
//unsigned int _stdcall TF(void* pParam)
//{
//	ThreadParam tp = *(ThreadParam*)pParam;
//	delete (ThreadParam*)pParam;
//
//	HDC hdc = GetDC(tp.hwnd);
//	for(int i=tp.start; i<=tp.end; ++i)
//	{
//		*tp.pResult += i;
//		RECT rt;
//		{
//			Lock lock(tp.hMutex);
//			rt = *tp.prt;
//		}
//		WaitForSingleObject(hSMutex,INFINITE);
//		CalMiddleResult(i);
//		ReleaseMutex(hSMutex);
//		DrawInteger(hdc, rt, i);
//		GdiFlush();  //너무빠르면 안보이는데 이메서드를 써주면 보인다.
//		Sleep(10);
//	}
//	ReleaseDC(tp.hwnd, hdc);
//
//	SetEvent(tp.hEvent);
//	return 0;
//}
//void DrawResult(HDC hdc,POINT pt)
//{
//	TCHAR buf[100];
//	wsprintf(buf,"T1+T2+T3 = %d",sum);
//	TextOut(hdc,pt.x,pt.y,buf,lstrlen(buf));
//}
//unsigned int _stdcall TF_Result(void* pParam)
//{
//	Thread2Param tp = *(Thread2Param*)pParam;
//	delete (Thread2Param*)pParam;
//
//	int nResult = 0;
//	HDC hdc = GetDC(tp.hwnd);
//	for(int i=tp.start; i<=tp.end; ++i)
//	{
//		nResult +=i;
//		WaitForSingleObject(tp.hMutex,INFINITE);
//		RECT rt = *tp.prt;
//		ReleaseMutex(tp.hMutex);
//
//		WaitForSingleObject(hSMutex,INFINITE);
//		CalMiddleResult(i);
//		ReleaseMutex(hSMutex);
//		DrawInteger(hdc, rt, i);
//		GdiFlush();  //너무빠르면 안보이는데 이메서드를 써주면 보인다.
//		Sleep(10);
//	}
//	WaitForMultipleObjects(2,&tp.hEvent[0],TRUE,INFINITE);
//	//sum = nResult + *tp.pResult[0] + *tp.pResult[1];
//	POINT pt = {tp.prt->right/2,tp.prt->bottom/2+50};
//	DrawResult(hdc,pt);
//	ReleaseDC(tp.hwnd, hdc);
//	return 0;
//}
//
//void DrawRectangle(HDC hdc, RECT rt)
//{
//	Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//	static HANDLE hLTMutex,hRTMutex,hBTMutex;
//	unsigned int id;
//	static HANDLE hEvent[2];
//	static int cx,cy;
//	static int nResult1,nResult2;
//	static int* nResult[2]={&nResult1,&nResult2};
//	static RECT topLeft, topRight, bottom;
//	static vector<HANDLE> threadhlist;
//	static bool lbt=TRUE;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		hEvent[0] = CreateEvent(NULL, TRUE/*자동*/,TRUE/*현재 신호상태*/, NULL);  //mutex처럼 이름을 가지면 2개의 윈도우에서 실행 안된다. kernalObject이기에
//		hEvent[1] = CreateEvent(NULL, TRUE/*자동*/,TRUE/*현재 신호상태*/, NULL);  //mutex처럼 이름을 가지면 2개의 윈도우에서 실행 안된다. kernalObject이기에
//
//		hLTMutex = CreateMutex(NULL,FALSE,NULL);
//		hRTMutex = CreateMutex(NULL,FALSE,NULL);
//		hBTMutex = CreateMutex(NULL,FALSE,NULL);
//		hSMutex = CreateMutex(NULL,FALSE,NULL);
//		{
//			ThreadParam* ptp = NULL;
//
//			ptp = new ThreadParam(hwnd, hEvent[0],hLTMutex, &topLeft, 1, 1000,nResult[0]);
//			threadhlist.push_back((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//			
//			ptp = new ThreadParam(hwnd, hEvent[1],hRTMutex, &topRight, 1001, 2000,nResult[1]);
//			threadhlist.push_back((HANDLE)_beginthreadex(NULL,0,TF,(void*)ptp,0,&id));
//
//			vector<HANDLE> eArray(hEvent,hEvent+2);
//			
//			vector<int*>rArray(nResult,nResult+2);
//			
//			Thread2Param* ptp2 = new Thread2Param(hwnd, eArray,hBTMutex, &bottom, 2001, 3000,rArray);
//			threadhlist.push_back((HANDLE)_beginthreadex(NULL,0,TF_Result,(void*)ptp2,0,&id));
//		}
//		break;
//	case WM_SIZE:
//		cx = LOWORD(lParam);
//		cy = HIWORD(lParam);
//
//		{
//			Lock lock(hLTMutex);
//			SetRect(&topLeft,0,0,cx/2,cy/2); // rect설정
//		}
//
//		{
//			Lock lock(hRTMutex);
//			SetRect(&topRight, cx/2,0,cx,cy/2);
//		}
//
//		{
//			Lock lock(hBTMutex);
//			SetRect(&bottom, 0,cy/2, cx,cy);//size가 바뀔대 사이즈도 바뀐다 그러니 참조를 보내야한다
//		}
//
//		break;
//	case WM_LBUTTONDOWN:
//		if(lbt)
//		{
//			for(unsigned i=0;i<threadhlist.size();i++)
//			{
//				SuspendThread(threadhlist[i]);
//			}
//			POINT pt = {LOWORD(lParam),HIWORD(lParam)};
//			hdc = GetDC(hwnd);
//			DrawResult(hdc,pt);
//			ReleaseDC(hwnd,hdc);
//
//		}
//		else
//		{
//			InvalidateRect(hwnd,NULL,TRUE);
//			for(unsigned i=0;i<threadhlist.size();i++)
//			{
//				ResumeThread(threadhlist[i]);
//			}
//		}
//		lbt=!lbt;
//
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRectangle(hdc,topLeft);
//		DrawRectangle(hdc,topRight);
//		DrawRectangle(hdc,bottom);
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		CloseHandle(hEvent[0]);
//		CloseHandle(hEvent[1]);
//		for(unsigned i=0;i<threadhlist.size();i++)
//		{
//			CloseHandle(threadhlist[i]);
//		}
//		CloseHandle(hLTMutex);
//		CloseHandle(hRTMutex);
//		CloseHandle(hBTMutex);
//		CloseHandle(hSMutex);
//
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}