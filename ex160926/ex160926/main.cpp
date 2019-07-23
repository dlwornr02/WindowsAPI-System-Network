//
//#include <windows.h>
//#include<process.h>
//struct ThreadParam
//{
//	HWND hwnd;
//	RECT* prt;
//};
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
//unsigned int __stdcall T1(void* pParam)
//{
//	ThreadParam*ptp = (ThreadParam*)pParam;
//	HWND hwnd = ptp->hwnd;
//	RECT*prt = ptp->prt;
//	delete ptp;
//	HDC hdc = GetDC(hwnd);
//
//	while(1)
//	{
//		int cx = prt->right - prt->left;
//		int cy = prt->bottom - prt->top;
//		for(int i=0;i<prt->right;i+=10)
//		{
//			Rectangle(hdc,prt->left,prt->top,prt->right+i,prt->bottom+i);
//			Sleep(500);
//
//		}
//	}
//
//	ReleaseDC(hwnd,hdc);
//	return 0;
//}
//unsigned int __stdcall T2(void* pParam)
//{
//	return 0;
//}
//unsigned int __stdcall T3(void* pParam)
//{
//	return 0;
//}
//unsigned int __stdcall T4(void* pParam)
//{
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	unsigned int id;
//	static int cx,cy;
//	static RECT rtArray[4];
//	ThreadParam* ptp;
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		ptp = new ThreadParam;
//		ptp->hwnd = hwnd;
//		ptp ->prt = &rtArray[0];
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,T1,(void*)ptp,0,&id));
//
//		ptp = new ThreadParam;
//		ptp->hwnd = hwnd;
//		ptp ->prt = &rtArray[1];
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,T2,(void*)ptp,0,&id));
//
//		ptp = new ThreadParam;
//		ptp->hwnd = hwnd;
//		ptp ->prt = &rtArray[2];
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,T3,(void*)ptp,0,&id));
//
//		ptp = new ThreadParam;
//		ptp->hwnd = hwnd;
//		ptp ->prt = &rtArray[3];
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,T4,(void*)ptp,0,&id));
//		break; 
//	case WM_SIZE:
//		cx = LOWORD(lParam);
//		cy = HIWORD(lParam);
//		SetRect(&rtArray[0],0,0,cx/2,cy/2);
//		SetRect(&rtArray[1],cx/2,0,cx,cy/2);
//		SetRect(&rtArray[2],0,cy/2,cx/2,cy);
//		SetRect(&rtArray[3],cx/2,cy/2,cx,cy);
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
//#include<process.h>
//struct ThreadParam
//{
//	HWND hwnd;
//	RECT* prt;
//};
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
//unsigned int __stdcall T1(void* pParam)
//{
//	ThreadParam*ptp = (ThreadParam*)pParam;
//	HWND hwnd = ptp->hwnd;
//	RECT*prt = ptp->prt;
//	delete ptp;
//	HDC hdc = GetDC(hwnd);
//
//	while(1)
//	{
//			Rectangle(hdc,prt->left,prt->top,prt->right,prt->bottom);
//			Sleep(100);
//
//	}
//
//	ReleaseDC(hwnd,hdc);
//	return 0;
//}
//unsigned int __stdcall T2(void* pParam)
//{
//	ThreadParam*ptp = (ThreadParam*)pParam;
//	HWND hwnd = ptp->hwnd;
//	RECT*prt = ptp->prt;
//	delete ptp;
//	HDC hdc = GetDC(hwnd);
//
//	while(1)
//	{
//			Rectangle(hdc,prt->left,prt->top,prt->right,prt->bottom);
//			Sleep(100);
//
//	}
//
//	ReleaseDC(hwnd,hdc);
//	return 0;
//}
//unsigned int __stdcall T3(void* pParam)
//{
//	ThreadParam*ptp = (ThreadParam*)pParam;
//	HWND hwnd = ptp->hwnd;
//	RECT*prt = ptp->prt;
//	delete ptp;
//	HDC hdc = GetDC(hwnd);
//
//	while(1)
//	{
//			Rectangle(hdc,prt->left,prt->top,prt->right,prt->bottom);
//			Sleep(100);
//
//	}
//
//	ReleaseDC(hwnd,hdc);
//	return 0;
//}
//unsigned int __stdcall T4(void* pParam)
//{
//	ThreadParam*ptp = (ThreadParam*)pParam;
//	HWND hwnd = ptp->hwnd;
//	RECT*prt = ptp->prt;
//	delete ptp;
//	HDC hdc = GetDC(hwnd);
//
//	while(1)
//	{
//			Rectangle(hdc,prt->left,prt->top,prt->right,prt->bottom);
//			Sleep(100);
//
//	}
//
//	ReleaseDC(hwnd,hdc);
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	unsigned int id;
//	static int cx,cy;
//	static RECT rtArray[4];
//	ThreadParam* ptp;
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		ptp = new ThreadParam;
//		ptp->hwnd = hwnd;
//		ptp ->prt = &rtArray[0];
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,T1,(void*)ptp,0,&id));
//
//		ptp = new ThreadParam;
//		ptp->hwnd = hwnd;
//		ptp ->prt = &rtArray[1];
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,T2,(void*)ptp,0,&id));
//
//		ptp = new ThreadParam;
//		ptp->hwnd = hwnd;
//		ptp ->prt = &rtArray[2];
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,T3,(void*)ptp,0,&id));
//
//		ptp = new ThreadParam;
//		ptp->hwnd = hwnd;
//		ptp ->prt = &rtArray[3];
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,T4,(void*)ptp,0,&id));
//		break; 
//	case WM_SIZE:
//		cx = LOWORD(lParam);
//		cy = HIWORD(lParam);
//		SetRect(&rtArray[0],0,0,cx/2,cy/2);
//		SetRect(&rtArray[1],cx/2,0,cx,cy/2);
//		SetRect(&rtArray[2],0,cy/2,cx/2,cy);
//		SetRect(&rtArray[3],cx/2,cy/2,cx,cy);
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
//#include<process.h>
//struct ThreadParam
//{
//	HWND hwnd;
//	RECT* prt;
//};
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
//unsigned int __stdcall T1(void* pParam)
//{
//	ThreadParam*ptp = (ThreadParam*)pParam;
//	HWND hwnd = ptp->hwnd;
//	RECT*prt = ptp->prt;
//	delete ptp;
//	HBRUSH hR = CreateSolidBrush(RGB(0xff,0,0));
//	HBRUSH hG = CreateSolidBrush(RGB(0,0xff,0));
//	HBRUSH hB = CreateSolidBrush(RGB(0,0,0xff));
//	HBRUSH hOldBrush;
//
//	int count = 0;
//
//	HDC hdc = GetDC(hwnd);
//
//	while(1)
//	{
//		switch(count++%3)
//		{
//		case 0:
//			hOldBrush = (HBRUSH)SelectObject(hdc,hR);
//			break;
//		case 1:
//			hOldBrush = (HBRUSH)SelectObject(hdc,hG);
//			break;
//		case 2:
//			hOldBrush = (HBRUSH)SelectObject(hdc,hB);
//			break;
//		}
//		Rectangle(hdc,prt->left,prt->top,prt->right,prt->bottom);
//		SelectObject(hdc,hOldBrush);
//		Sleep(1000);
//
//	}
//	DeleteObject(hR);
//	DeleteObject(hG);
//	DeleteObject(hB);
//	ReleaseDC(hwnd,hdc);
//	return 0;
//}
//unsigned int __stdcall T2(void* pParam)
//{
//	ThreadParam*ptp = (ThreadParam*)pParam;
//	HWND hwnd = ptp->hwnd;
//	RECT*prt = ptp->prt;
//	delete ptp;
//	HDC hdc = GetDC(hwnd);
//
//	while(1)
//	{
//		for(int i = 1;i<=100;i++)
//		{
//			TCHAR buf[100];
//			wsprintf(buf,"(%d)",i);
//			DrawText(hdc,buf,-1,prt,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
//			GdiFlush();
//			Sleep(200);
//		}
//		for(int i = 1;i<=100;i++)
//		{
//			TCHAR buf[100];
//			wsprintf(buf,"(%d)",100-i+1);
//			DrawText(hdc,buf,-1,prt,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
//			GdiFlush();
//			Sleep(200);
//		}
//
//	}
//
//	ReleaseDC(hwnd,hdc);
//	return 0;
//}
//unsigned int __stdcall T3(void* pParam)
//{
//	ThreadParam*ptp = (ThreadParam*)pParam;
//	HWND hwnd = ptp->hwnd;
//	RECT*prt = ptp->prt;
//	delete ptp;
//	HDC hdc = GetDC(hwnd);
//
//	while(1)
//	{
//			Rectangle(hdc,prt->left,prt->top,prt->right,prt->bottom);
//			Sleep(100);
//
//	}
//
//	ReleaseDC(hwnd,hdc);
//	return 0;
//}
//unsigned int __stdcall T4(void* pParam)
//{
//	ThreadParam*ptp = (ThreadParam*)pParam;
//	HWND hwnd = ptp->hwnd;
//	RECT*prt = ptp->prt;
//	delete ptp;
//	HDC hdc = GetDC(hwnd);
//
//	while(1)
//	{
//			Rectangle(hdc,prt->left,prt->top,prt->right,prt->bottom);
//			Sleep(100);
//
//	}
//
//	ReleaseDC(hwnd,hdc);
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	unsigned int id;
//	static int cx,cy;
//	static RECT rtArray[4];
//	ThreadParam* ptp;
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		ptp = new ThreadParam;
//		ptp->hwnd = hwnd;
//		ptp ->prt = &rtArray[0];
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,T1,(void*)ptp,0,&id));
//
//		ptp = new ThreadParam;
//		ptp->hwnd = hwnd;
//		ptp ->prt = &rtArray[1];
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,T2,(void*)ptp,0,&id));
//
//		ptp = new ThreadParam;
//		ptp->hwnd = hwnd;
//		ptp ->prt = &rtArray[2];
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,T3,(void*)ptp,0,&id));
//
//		ptp = new ThreadParam;
//		ptp->hwnd = hwnd;
//		ptp ->prt = &rtArray[3];
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,T4,(void*)ptp,0,&id));
//		break; 
//	case WM_SIZE:
//		cx = LOWORD(lParam);
//		cy = HIWORD(lParam);
//		SetRect(&rtArray[0],0,0,cx/2,cy/2);
//		SetRect(&rtArray[1],cx/2,0,cx,cy/2);
//		SetRect(&rtArray[2],0,cy/2,cx/2,cy);
//		SetRect(&rtArray[3],cx/2,cy/2,cx,cy);
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



#include <windows.h>
#include<process.h>
struct ThreadParam
{
	HWND hwnd;
	RECT* prt;
};

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
unsigned int __stdcall T1(void* pParam)
{
	ThreadParam*ptp = (ThreadParam*)pParam;
	HWND hwnd = ptp->hwnd;
	RECT*prt = ptp->prt;
	delete ptp;
	HBRUSH hR = CreateSolidBrush(RGB(0xff,0,0));
	HBRUSH hG = CreateSolidBrush(RGB(0,0xff,0));
	HBRUSH hB = CreateSolidBrush(RGB(0,0,0xff));
	HBRUSH hOldBrush;

	int count = 0;

	HDC hdc = GetDC(hwnd);

	while(1)
	{
		switch(count++%3)
		{
		case 0:
			hOldBrush = (HBRUSH)SelectObject(hdc,hR);
			break;
		case 1:
			hOldBrush = (HBRUSH)SelectObject(hdc,hG);
			break;
		case 2:
			hOldBrush = (HBRUSH)SelectObject(hdc,hB);
			break;
		}
		Rectangle(hdc,prt->left,prt->top,prt->right,prt->bottom);
		SelectObject(hdc,hOldBrush);
		Sleep(1000);

	}
	DeleteObject(hR);
	DeleteObject(hG);
	DeleteObject(hB);
	ReleaseDC(hwnd,hdc);
	return 0;
}
unsigned int __stdcall T2(void* pParam)
{
	ThreadParam*ptp = (ThreadParam*)pParam;
	HWND hwnd = ptp->hwnd;
	RECT*prt = ptp->prt;
	delete ptp;
	HDC hdc = GetDC(hwnd);

	while(1)
	{
		for(int i = 1;i<=100;i++)
		{
			TCHAR buf[100];
			wsprintf(buf,"(%d)",i);
			DrawText(hdc,buf,-1,prt,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			GdiFlush();
			Sleep(200);
		}
		for(int i = 1;i<=100;i++)
		{
			TCHAR buf[100];
			wsprintf(buf,"(%d)",100-i+1);
			DrawText(hdc,buf,-1,prt,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			GdiFlush();
			Sleep(200);
		}

	}

	ReleaseDC(hwnd,hdc);
	return 0;
}
unsigned int __stdcall T3(void* pParam)
{
	ThreadParam*ptp = (ThreadParam*)pParam;
	HWND hwnd = ptp->hwnd;
	RECT*prt = ptp->prt;
	delete ptp;
	HDC hdc = GetDC(hwnd);
	while(1)
	{
		int cx = prt->right - prt->left;
		int cy = prt->bottom - prt->top;

		int block = cy/5;

		for(int i = 0;i<5;i++)
		{
			Rectangle(hdc,prt->left,prt->top,prt->right,prt->bottom);
			MoveToEx(hdc,prt->left,prt->top+block*i,NULL);
			LineTo(hdc,prt->right,prt->top+block*i);
			Sleep(300);
		}

	}

	ReleaseDC(hwnd,hdc);
	return 0;
}
unsigned int __stdcall T4(void* pParam)
{
	ThreadParam*ptp = (ThreadParam*)pParam;
	HWND hwnd = ptp->hwnd;
	RECT*prt = ptp->prt;
	delete ptp;
	HDC hdc = GetDC(hwnd);

	while(1)
	{
		int cx = prt->right - prt->left;
		int cy = prt->bottom - prt->top;

		int block = cy/5;

		for(int i = 0;i<5;i++)
		{
			Rectangle(hdc,prt->left,prt->top,prt->right,prt->bottom);
			TCHAR buf[100];
			wsprintf(buf,"Hello:%d",i);
			TextOut(hdc,prt->left+cx/2,prt->top+block*(i)+50,buf,lstrlen(buf));
			GdiFlush();
			Sleep(300);
		}

	}

	ReleaseDC(hwnd,hdc);
	return 0;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
                         WPARAM wParam, LPARAM lParam) 
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	unsigned int id;
	static int cx,cy;
	static RECT rtArray[4];
	ThreadParam* ptp;
	switch (iMsg)
	{
    case WM_CREATE:
		ptp = new ThreadParam;
		ptp->hwnd = hwnd;
		ptp ->prt = &rtArray[0];
		CloseHandle((HANDLE)_beginthreadex(NULL,0,T1,(void*)ptp,0,&id));

		ptp = new ThreadParam;
		ptp->hwnd = hwnd;
		ptp ->prt = &rtArray[1];
		CloseHandle((HANDLE)_beginthreadex(NULL,0,T2,(void*)ptp,0,&id));

		ptp = new ThreadParam;
		ptp->hwnd = hwnd;
		ptp ->prt = &rtArray[2];
		CloseHandle((HANDLE)_beginthreadex(NULL,0,T3,(void*)ptp,0,&id));

		ptp = new ThreadParam;
		ptp->hwnd = hwnd;
		ptp ->prt = &rtArray[3];
		CloseHandle((HANDLE)_beginthreadex(NULL,0,T4,(void*)ptp,0,&id));
		break; 
	case WM_SIZE:
		cx = LOWORD(lParam);
		cy = HIWORD(lParam);
		SetRect(&rtArray[0],0,0,cx/2,cy/2);
		SetRect(&rtArray[1],cx/2,0,cx,cy/2);
		SetRect(&rtArray[2],0,cy/2,cx/2,cy);
		SetRect(&rtArray[3],cx/2,cy/2,cx,cy);
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
