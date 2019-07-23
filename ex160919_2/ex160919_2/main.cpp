//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//HINSTANCE g_hInst;
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
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		CreateWindow("button","Push",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,50,50,120,25,hwnd,(HMENU)10,g_hInst,NULL);
//					//클래스이름,WS_VISIBLE와 WS_CHILD의 옵션이 있어야 한다.시작 위치와 10은 버튼의 ID
//		CreateWindow("Edit","Hello!",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,50,100,120,25,hwnd,(HMENU)11,g_hInst,NULL);
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
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//HINSTANCE g_hInst;
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
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		CreateWindow("button","Push",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,50,50,120,25,hwnd,(HMENU)10,g_hInst,NULL);
//					//클래스이름,WS_VISIBLE와 WS_CHILD의 옵션이 있어야 한다.시작 위치와 10은 버튼의 ID
//		CreateWindow("Edit","Hello!",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,50,100,120,25,hwnd,(HMENU)11,g_hInst,NULL);
//		CreateWindow("listbox","",WS_VISIBLE|WS_CHILD|WS_BORDER|WS_VSCROLL,50,150,200,100,hwnd,(HMENU)12,g_hInst,NULL);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case 10:
//			{
//				TCHAR buf[200];
//				GetDlgItemText(hwnd,11,buf,200);
//				SendDlgItemMessage(hwnd,12,LB_ADDSTRING,0,(LPARAM)buf);
//			}
//			break;
//		}
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
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//HINSTANCE g_hInst;
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
//	static HWND hButton, hEdit,hList;
//	static POINT pt={50,50};
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		hButton = CreateWindow("button","Push",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,pt.x,pt.y,120,25,hwnd,(HMENU)10,g_hInst,NULL);
//					//클래스이름,WS_VISIBLE와 WS_CHILD의 옵션이 있어야 한다.시작 위치와 10은 버튼의 ID
//		hEdit = CreateWindow("Edit","Hello!",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,pt.x,pt.y+50,120,25,hwnd,(HMENU)11,g_hInst,NULL);
//		hList = CreateWindow("listbox","",WS_VISIBLE|WS_CHILD|WS_BORDER|WS_VSCROLL,pt.x,pt.y+100,200,100,hwnd,(HMENU)12,g_hInst,NULL);
//		break;
//	case WM_LBUTTONDOWN:
//		pt.x = LOWORD(lParam);
//		pt.y = HIWORD(lParam);
//
//		MoveWindow(hButton,pt.x,pt.y,125,25,TRUE);
//		MoveWindow(hEdit,pt.x,pt.y+50,125,25,TRUE);
//		MoveWindow(hList,pt.x,pt.y+100,200,100,TRUE);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case 10:
//			{
//				TCHAR buf[200];
//				GetDlgItemText(hwnd,11,buf,200);
//				SendDlgItemMessage(hwnd,12,LB_ADDSTRING,0,(LPARAM)buf);
//			}
//			break;
//		}
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
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//HINSTANCE g_hInst;
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
//	static HWND hButton, hEdit,hList;
//	static POINT pt={50,50};
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		hButton = CreateWindow("button","Push",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,pt.x,pt.y,120,25,hwnd,(HMENU)10,g_hInst,NULL);
//					//클래스이름,WS_VISIBLE와 WS_CHILD의 옵션이 있어야 한다.시작 위치와 10은 버튼의 ID
//		hEdit = CreateWindow("Edit","Hello!",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,pt.x,pt.y+50,120,25,hwnd,(HMENU)11,g_hInst,NULL);
//		hList = CreateWindow("listbox","",WS_VISIBLE|WS_CHILD|WS_BORDER|WS_VSCROLL,pt.x,pt.y+100,200,100,hwnd,(HMENU)12,g_hInst,NULL);
//		break;
//	case WM_LBUTTONDOWN:
//		pt.x = LOWORD(lParam);
//		pt.y = HIWORD(lParam);
//
////		MoveWindow(hButton,pt.x,pt.y,125,25,TRUE);
////		MoveWindow(hEdit,pt.x,pt.y+50,125,25,TRUE);
////		MoveWindow(hList,pt.x,pt.y+100,200,100,TRUE);
//		MoveWindow(GetDlgItem(hwnd,10),pt.x,pt.y,125,25,TRUE);
//		MoveWindow(GetDlgItem(hwnd,11),pt.x,pt.y+50,125,25,TRUE);
//		MoveWindow(GetDlgItem(hwnd,12),pt.x,pt.y+100,200,100,TRUE);//위의 코드와 동일하다.
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case 10:
//			{
//				TCHAR buf[200];
//				GetDlgItemText(hwnd,11,buf,200);
//				SendDlgItemMessage(hwnd,12,LB_ADDSTRING,0,(LPARAM)buf);
//			}
//			break;
//		}
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
////클래스와 윈도우를 모두 사용자가 정의한것
////프로시저를 정밀하게 처리하기 위해 사용한다.
////윈도우만 사용자가 정의하게되면 정밀한 처리가 불가능
//
//
//#include <windows.h>
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//HINSTANCE g_hInst;
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
//
//	WndClass.hbrBackground = CreateSolidBrush(RGB(0xff,0,0)); //사용자가정함
//
//	WndClass.lpfnWndProc = TopProc;
//	WndClass.lpszClassName = "TopWindow";
//	RegisterClass(&WndClass);
//
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH); //시스템이 만들어놓은것
//	WndClass.lpfnWndProc = BottomProc;
//	WndClass.lpszClassName = "BottonWindow";
//	RegisterClass(&WndClass);
//
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
//LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//	static HWND hButton, hEdit,hList;
//	static POINT pt={50,50};
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		hButton = CreateWindow("button","Push",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,pt.x,pt.y,120,25,hwnd,(HMENU)10,g_hInst,NULL);
//					//클래스이름,WS_VISIBLE와 WS_CHILD의 옵션이 있어야 한다.시작 위치와 10은 버튼의 ID
//		hEdit = CreateWindow("Edit","Hello!",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,pt.x,pt.y+50,120,25,hwnd,(HMENU)11,g_hInst,NULL);
//		hList = CreateWindow("listbox","",WS_VISIBLE|WS_CHILD|WS_BORDER|WS_VSCROLL,pt.x,pt.y+100,200,100,hwnd,(HMENU)12,g_hInst,NULL);
//		break;
//	case WM_LBUTTONDOWN:
//		pt.x = LOWORD(lParam);
//		pt.y = HIWORD(lParam);
//
////		MoveWindow(hButton,pt.x,pt.y,125,25,TRUE);
////		MoveWindow(hEdit,pt.x,pt.y+50,125,25,TRUE);
////		MoveWindow(hList,pt.x,pt.y+100,200,100,TRUE);
//		MoveWindow(GetDlgItem(hwnd,10),pt.x,pt.y,125,25,TRUE);
//		MoveWindow(GetDlgItem(hwnd,11),pt.x,pt.y+50,125,25,TRUE);
//		MoveWindow(GetDlgItem(hwnd,12),pt.x,pt.y+100,200,100,TRUE);//위의 코드와 동일하다.
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case 10:
//			{
//				TCHAR buf[200];
//				GetDlgItemText(hwnd,11,buf,200);
//				SendDlgItemMessage(hwnd,12,LB_ADDSTRING,0,(LPARAM)buf);
//			}
//			break;
//		}
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
////클래스와 윈도우를 모두 사용자가 정의한것
////프로시저를 정밀하게 처리하기 위해 사용한다.
////윈도우만 사용자가 정의하게되면 정밀한 처리가 불가능
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	static HWND hTop,hLeft,hRight;
//	switch(iMsg)
//	{
//	case WM_CREATE:
//		hTop = CreateWindow("TopWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)1,g_hInst,NULL);
//		hLeft = CreateWindow("TopWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)2,g_hInst,NULL);
//		hRight = CreateWindow("TopWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)3,g_hInst,NULL);
//		break;
//	case WM_SIZE:
//		{
//			int cx = LOWORD(lParam);
//			int cy = HIWORD(lParam);
//			MoveWindow(hTop,0,0,cx,cy/2,TRUE);
//			MoveWindow(hLeft,0,cy/2,cx/2,cy,TRUE);
//			MoveWindow(hRight,cx/2,cy/2,cx,cy,TRUE);
//		}
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	return DefWindowProc(hwnd,iMsg,wParam,lParam);
//}
////숙제 메인윈도우
//
//
//#include <windows.h>
//#include<vector>
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//HINSTANCE g_hInst;
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
//
//	WndClass.hbrBackground = CreateSolidBrush(RGB(0xff,0,0)); //사용자가정함
//
//	WndClass.lpfnWndProc = TopProc;
//	WndClass.lpszClassName = "TopWindow";
//	RegisterClass(&WndClass);
//
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH); //시스템이 만들어놓은것
//	WndClass.lpfnWndProc = BottomProc;
//	WndClass.lpszClassName = "BottomWindow";
//	RegisterClass(&WndClass);
//
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
//LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//	static HWND hButton, hEdit,hList;
//	static POINT pt={50,50};
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		hButton = CreateWindow("button","Push",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,pt.x,pt.y,120,25,hwnd,(HMENU)10,g_hInst,NULL);
//					//클래스이름,WS_VISIBLE와 WS_CHILD의 옵션이 있어야 한다.시작 위치와 10은 버튼의 ID
//		hEdit = CreateWindow("Edit","Hello!",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,pt.x,pt.y+50,120,25,hwnd,(HMENU)11,g_hInst,NULL);
//		hList = CreateWindow("listbox","",WS_VISIBLE|WS_CHILD|WS_BORDER|WS_VSCROLL,pt.x,pt.y+100,200,100,hwnd,(HMENU)12,g_hInst,NULL);
//		break;
//	case WM_LBUTTONDOWN:
//		pt.x = LOWORD(lParam);
//		pt.y = HIWORD(lParam);
//
////		MoveWindow(hButton,pt.x,pt.y,125,25,TRUE);
////		MoveWindow(hEdit,pt.x,pt.y+50,125,25,TRUE);
////		MoveWindow(hList,pt.x,pt.y+100,200,100,TRUE);
//		MoveWindow(GetDlgItem(hwnd,10),pt.x,pt.y,125,25,TRUE);
//		MoveWindow(GetDlgItem(hwnd,11),pt.x,pt.y+50,125,25,TRUE);
//		MoveWindow(GetDlgItem(hwnd,12),pt.x,pt.y+100,200,100,TRUE);//위의 코드와 동일하다.
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case 10:
//			{
//				TCHAR buf[200];
//				GetDlgItemText(hwnd,11,buf,200);
//				SendDlgItemMessage(hwnd,12,LB_ADDSTRING,0,(LPARAM)buf);
//			}
//			break;
//		}
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
////클래스와 윈도우를 모두 사용자가 정의한것
////프로시저를 정밀하게 처리하기 위해 사용한다.
////윈도우만 사용자가 정의하게되면 정밀한 처리가 불가능
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	static HWND hTop,hLeft,hRight;
//	switch(iMsg)
//	{
//	case WM_CREATE:
//		hTop = CreateWindow("TopWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)1,g_hInst,NULL);
//		hLeft = CreateWindow("BottomWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)2,g_hInst,NULL);
//		hRight = CreateWindow("BottomWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)3,g_hInst,NULL);
//		break;
//	case WM_SIZE:
//		{
//			int cx = LOWORD(lParam);
//			int cy = HIWORD(lParam);
//			MoveWindow(hTop,0,0,cx,cy/2,TRUE);
//			MoveWindow(hLeft,0,cy/2,cx/2,cy,TRUE);
//			MoveWindow(hRight,cx/2,cy/2,cx,cy,TRUE);
//		}
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	static vector<POINT> ptList;
//	HDC hdc;
//	POINT pt;
//	PAINTSTRUCT ps;
//	switch(iMsg)
//	{
//	case WM_LBUTTONDOWN:
//		pt.x = LOWORD(lParam);
//		pt.y = HIWORD(lParam);
//		
//		ptList.push_back(pt);
//		InvalidateRect(hwnd,NULL,TRUE);
//
//		break;
//	case WM_RBUTTONDOWN:
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd,&ps);
//		for(unsigned i=0;i<ptList.size();i++)
//		{
//			const POINT&pt = ptList[i];
//			Ellipse(hdc,pt.x-20,pt.y-20,pt.x+20,pt.y+20);
//		}
//		EndPaint(hwnd,&ps);
//		break;
//	}
//	return DefWindowProc(hwnd,iMsg,wParam,lParam);
//}
//vector를 공유하기때문에 각각윈도우에서 독립적으로 저장이 불가능하다
//
//
//#include <windows.h>
//#include<vector>
//#include<map>
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//HINSTANCE g_hInst;
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
//
//	WndClass.hbrBackground = CreateSolidBrush(RGB(0xff,0,0)); //사용자가정함
//
//	WndClass.lpfnWndProc = TopProc;
//	WndClass.lpszClassName = "TopWindow";
//	RegisterClass(&WndClass);
//
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH); //시스템이 만들어놓은것
//	WndClass.lpfnWndProc = BottomProc;
//	WndClass.lpszClassName = "BottomWindow";
//	RegisterClass(&WndClass);
//
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
//LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//	static HWND hButton, hEdit,hList;
//	static POINT pt={50,50};
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		hButton = CreateWindow("button","Push",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,pt.x,pt.y,120,25,hwnd,(HMENU)10,g_hInst,NULL);
//					//클래스이름,WS_VISIBLE와 WS_CHILD의 옵션이 있어야 한다.시작 위치와 10은 버튼의 ID
//		hEdit = CreateWindow("Edit","Hello!",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,pt.x,pt.y+50,120,25,hwnd,(HMENU)11,g_hInst,NULL);
//		hList = CreateWindow("listbox","",WS_VISIBLE|WS_CHILD|WS_BORDER|WS_VSCROLL,pt.x,pt.y+100,200,100,hwnd,(HMENU)12,g_hInst,NULL);
//		break;
//	case WM_LBUTTONDOWN:
//		pt.x = LOWORD(lParam);
//		pt.y = HIWORD(lParam);
//
////		MoveWindow(hButton,pt.x,pt.y,125,25,TRUE);
////		MoveWindow(hEdit,pt.x,pt.y+50,125,25,TRUE);
////		MoveWindow(hList,pt.x,pt.y+100,200,100,TRUE);
//		MoveWindow(GetDlgItem(hwnd,10),pt.x,pt.y,125,25,TRUE);
//		MoveWindow(GetDlgItem(hwnd,11),pt.x,pt.y+50,125,25,TRUE);
//		MoveWindow(GetDlgItem(hwnd,12),pt.x,pt.y+100,200,100,TRUE);//위의 코드와 동일하다.
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case 10:
//			{
//				TCHAR buf[200];
//				GetDlgItemText(hwnd,11,buf,200);
//				SendDlgItemMessage(hwnd,12,LB_ADDSTRING,0,(LPARAM)buf);
//			}
//			break;
//		}
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
////클래스와 윈도우를 모두 사용자가 정의한것
////프로시저를 정밀하게 처리하기 위해 사용한다.
////윈도우만 사용자가 정의하게되면 정밀한 처리가 불가능
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	static HWND hTop,hLeft,hRight;
//	switch(iMsg)
//	{
//	case WM_CREATE:
//		hTop = CreateWindow("TopWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)1,g_hInst,NULL);
//		hLeft = CreateWindow("BottomWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)2,g_hInst,NULL);
//		hRight = CreateWindow("BottomWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)3,g_hInst,NULL);
//		break;
//	case WM_SIZE:
//		{
//			int cx = LOWORD(lParam);
//			int cy = HIWORD(lParam);
//			MoveWindow(hTop,0,0,cx,cy/2,TRUE);
//			MoveWindow(hLeft,0,cy/2,cx/2,cy,TRUE);
//			MoveWindow(hRight,cx/2,cy/2,cx,cy,TRUE);
//		}
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	static map<HWND,vector<POINT>*> ptMap;  //이렇게하면 벡터가 계속 복사되서 안된다
//						//map이 반환을 참조형식으로 한다.
//	HDC hdc;
//	POINT pt;
//	PAINTSTRUCT ps;
//	switch(iMsg)
//	{
//	case WM_CREATE:
//		ptMap[hwnd] = new vector<POINT>;
//		break;
//	case WM_LBUTTONDOWN:
//		pt.x = LOWORD(lParam);
//		pt.y = HIWORD(lParam);
//		
//		(ptMap[hwnd])->push_back(pt);
//		InvalidateRect(hwnd,NULL,TRUE);
//
//		break;
//	case WM_RBUTTONDOWN:
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd,&ps);
//		for(unsigned i=0;i<(ptMap[hwnd])->size();i++)
//		{
//			//const POINT&pt = (*ptMap[hwnd])[i];
//			const POINT&pt = ptMap[hwnd]->at(i);
//			Ellipse(hdc,pt.x-20,pt.y-20,pt.x+20,pt.y+20);
//		}
//		EndPaint(hwnd,&ps);
//		break;
//	
//	case WM_DESTROY:
//		delete ptMap[hwnd];
//		break;
//	}
//	return DefWindowProc(hwnd,iMsg,wParam,lParam);
//}
////vector를 공유하기때문에 각각윈도우에서 독립적으로 저장이 불가능하다

//
//#include <windows.h>
//#include<vector>
//#include<map>
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//HINSTANCE g_hInst;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
//
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;   
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;		
//	WndClass.cbClsExtra	= 0;		//클래스의 extra -사용자정보를 담을수있는 메모리
//	WndClass.cbWndExtra	= 0;		//윈도우의 extra-사용자정보를 담을수있는 메모리
//	WndClass.hInstance = hInstance;		
//	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";
//	RegisterClass(&WndClass);
//
//	WndClass.hbrBackground = CreateSolidBrush(RGB(0xff,0,0)); //사용자가정함
//
//	WndClass.lpfnWndProc = TopProc;
//	WndClass.lpszClassName = "TopWindow";
//	RegisterClass(&WndClass);
//
//	WndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH); //시스템이 만들어놓은것
//	WndClass.lpfnWndProc = BottomProc;
//	WndClass.cbWndExtra	= sizeof(void*);		//윈도우의 extra-사용자정보를 담을수있는 메모리
//	//윈도우생성시 만들어지는 메모리
//	WndClass.lpszClassName = "BottomWindow";
//	RegisterClass(&WndClass);
//
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
//
//LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//	static HWND hButton, hEdit,hList;
//	static POINT pt={50,50};
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		hButton = CreateWindow("button","Push",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,pt.x,pt.y,120,25,hwnd,(HMENU)10,g_hInst,NULL);
//		//클래스이름,WS_VISIBLE와 WS_CHILD의 옵션이 있어야 한다.시작 위치와 10은 버튼의 ID
//		hEdit = CreateWindow("Edit","Hello!",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,pt.x,pt.y+50,120,25,hwnd,(HMENU)11,g_hInst,NULL);
//		hList = CreateWindow("listbox","",WS_VISIBLE|WS_CHILD|WS_BORDER|WS_VSCROLL,pt.x,pt.y+100,200,100,hwnd,(HMENU)12,g_hInst,NULL);
//		break;
//	case WM_LBUTTONDOWN:
//		pt.x = LOWORD(lParam);
//		pt.y = HIWORD(lParam);
//
//		//		MoveWindow(hButton,pt.x,pt.y,125,25,TRUE);
//		//		MoveWindow(hEdit,pt.x,pt.y+50,125,25,TRUE);
//		//		MoveWindow(hList,pt.x,pt.y+100,200,100,TRUE);
//		MoveWindow(GetDlgItem(hwnd,10),pt.x,pt.y,125,25,TRUE);
//		MoveWindow(GetDlgItem(hwnd,11),pt.x,pt.y+50,125,25,TRUE);
//		MoveWindow(GetDlgItem(hwnd,12),pt.x,pt.y+100,200,100,TRUE);//위의 코드와 동일하다.
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case 10:
//			{
//				TCHAR buf[200];
//				GetDlgItemText(hwnd,11,buf,200);
//				SendDlgItemMessage(hwnd,12,LB_ADDSTRING,0,(LPARAM)buf);
//			}
//			break;
//		}
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
////클래스와 윈도우를 모두 사용자가 정의한것
////프로시저를 정밀하게 처리하기 위해 사용한다.
////윈도우만 사용자가 정의하게되면 정밀한 처리가 불가능
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	static HWND hTop,hLeft,hRight;
//	switch(iMsg)
//	{
//	case WM_CREATE:
//		hTop = CreateWindow("TopWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)1,g_hInst,NULL);
//		hLeft = CreateWindow("BottomWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)2,g_hInst,NULL);
//		hRight = CreateWindow("BottomWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)3,g_hInst,NULL);
//		break;
//	case WM_SIZE:
//		{
//			int cx = LOWORD(lParam);
//			int cy = HIWORD(lParam);
//			MoveWindow(hTop,0,0,cx,cy/2,TRUE);
//			MoveWindow(hLeft,0,cy/2,cx/2,cy,TRUE);
//			MoveWindow(hRight,cx/2,cy/2,cx,cy,TRUE);
//		}
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	//static map<HWND,vector<POINT>*> ptMap;  //이렇게하면 벡터가 계속 복사되서 안된다
//	//map이 반환을 참조형식으로 한다.
//	HDC hdc;
//	POINT pt;
//	PAINTSTRUCT ps;
//	switch(iMsg)
//	{
//	case WM_CREATE:
//		//ptMap[hwnd] = new vector<POINT>;
//		//extra 메모리를 이용해서 각각의 윈도우 마다 메모리를 가지게함
//		//SetWindowLong(),GetWindowLong()
//		SetWindowLong(hwnd,/*실행할 작업기술*/0,(LONG)new vector<POINT>); //Proc를 두개로 만들어도되지만 비효율이다.
//		break;
//	case WM_LBUTTONDOWN:
//		{
//			pt.x = LOWORD(lParam);
//			pt.y = HIWORD(lParam);
//			vector<POINT>* pv = (vector<POINT>*)GetWindowLong(hwnd,0);
//			(pv)->push_back(pt);
//			InvalidateRect(hwnd,NULL,TRUE);
//		}
//		break;
//	case WM_RBUTTONDOWN:
//		break;
//	case WM_PAINT:
//		{
//			vector<POINT>* pv = (vector<POINT>*)GetWindowLong(hwnd,0);
//			hdc = BeginPaint(hwnd,&ps);
//			for(unsigned i=0;i<(pv)->size();i++)
//			{
//				//const POINT&pt = (*ptMap[hwnd])[i];
//				const POINT&pt = pv->at(i);
//				Ellipse(hdc,pt.x-20,pt.y-20,pt.x+20,pt.y+20);
//			}
//			EndPaint(hwnd,&ps);
//		}
//		break;
//
//	case WM_DESTROY:
//		delete (vector<POINT>*)GetWindowLong(hwnd,0); //LONG형식을 반환하므로 형변환이 필요하다.
//		break;
//	}
//	return DefWindowProc(hwnd,iMsg,wParam,lParam);
//}
////vector를 공유하기때문에 각각윈도우에서 독립적으로 저장이 불가능하다



#include <windows.h>
#include<vector>
#include<map>
using namespace std;
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE g_hInst;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpszCmdLine, int nCmdShow)
{
	g_hInst = hInstance;

	HWND 	 hwnd;
	MSG 	 msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;		
	WndClass.cbClsExtra	= 0;		//클래스의 extra -사용자정보를 담을수있는 메모리
	WndClass.cbWndExtra	= 0;		//윈도우의 extra-사용자정보를 담을수있는 메모리
	WndClass.hInstance = hInstance;		
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = "Window Class Name";
	RegisterClass(&WndClass);

	WndClass.hbrBackground = CreateSolidBrush(RGB(0xff,0,0)); //사용자가정함

	WndClass.lpfnWndProc = TopProc;
	WndClass.lpszClassName = "TopWindow";
	RegisterClass(&WndClass);

	WndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH); //시스템이 만들어놓은것
	WndClass.lpfnWndProc = BottomProc;
	WndClass.cbWndExtra	= sizeof(void*);		//윈도우의 extra-사용자정보를 담을수있는 메모리
	//윈도우생성시 만들어지는 메모리
	WndClass.lpszClassName = "BottomWindow";
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

LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam) 
{
	HDC         hdc;
	PAINTSTRUCT ps;
	static HWND hButton, hEdit,hList;
	static POINT pt={50,50};
	switch (iMsg)
	{
	case WM_CREATE:
		hButton = CreateWindow("button","Push",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,pt.x,pt.y,120,25,hwnd,(HMENU)10,g_hInst,NULL);
		//클래스이름,WS_VISIBLE와 WS_CHILD의 옵션이 있어야 한다.시작 위치와 10은 버튼의 ID
		hEdit = CreateWindow("Edit","Hello!",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,pt.x,pt.y+50,120,25,hwnd,(HMENU)11,g_hInst,NULL);
		hList = CreateWindow("listbox","",WS_VISIBLE|WS_CHILD|WS_BORDER|WS_VSCROLL,pt.x,pt.y+100,200,100,hwnd,(HMENU)12,g_hInst,NULL);
		break;
	case WM_LBUTTONDOWN:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);

		//		MoveWindow(hButton,pt.x,pt.y,125,25,TRUE);
		//		MoveWindow(hEdit,pt.x,pt.y+50,125,25,TRUE);
		//		MoveWindow(hList,pt.x,pt.y+100,200,100,TRUE);
		MoveWindow(GetDlgItem(hwnd,10),pt.x,pt.y,125,25,TRUE);
		MoveWindow(GetDlgItem(hwnd,11),pt.x,pt.y+50,125,25,TRUE);
		MoveWindow(GetDlgItem(hwnd,12),pt.x,pt.y+100,200,100,TRUE);//위의 코드와 동일하다.
		break;
	case WM_RBUTTONDOWN:
		PostMessage(GetDlgItem(GetParent(hwnd),2),WM_LBUTTONDOWN,wParam,lParam); //부모를찾아서 자식의 ID를 알면 전역이아니여도 가능하다
		PostMessage(GetDlgItem(GetParent(hwnd),3),WM_LBUTTONDOWN,wParam,lParam); //부모를찾아서 자식의 ID를 알면 전역이아니여도 가능하다
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		// 이곳에서 출력이 이루어짐
		EndPaint(hwnd, &ps);
		break; 
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case 10:
			{
				TCHAR buf[200];
				GetDlgItemText(hwnd,11,buf,200);
				SendDlgItemMessage(hwnd,12,LB_ADDSTRING,0,(LPARAM)buf);
			}
			break;
		}
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
//클래스와 윈도우를 모두 사용자가 정의한것
//프로시저를 정밀하게 처리하기 위해 사용한다.
//윈도우만 사용자가 정의하게되면 정밀한 처리가 불가능
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hTop,hLeft,hRight;
	switch(iMsg)
	{
	case WM_CREATE:
		hTop = CreateWindow("TopWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)1,g_hInst,NULL);
		hLeft = CreateWindow("BottomWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)2,g_hInst,NULL);
		hRight = CreateWindow("BottomWindow","",WS_VISIBLE|WS_CHILD|WS_BORDER,0,0,0,0,hwnd,(HMENU)3,g_hInst,NULL);
		break;
	case WM_SIZE:
		{
			int cx = LOWORD(lParam);
			int cy = HIWORD(lParam);
			MoveWindow(hTop,0,0,cx,cy/2,TRUE);
			MoveWindow(hLeft,0,cy/2,cx/2,cy,TRUE);
			MoveWindow(hRight,cx/2,cy/2,cx,cy,TRUE);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//static map<HWND,vector<POINT>*> ptMap;  //이렇게하면 벡터가 계속 복사되서 안된다
	//map이 반환을 참조형식으로 한다.
	HDC hdc;
	POINT pt;
	PAINTSTRUCT ps;
	switch(iMsg)
	{
	case WM_CREATE:
		//ptMap[hwnd] = new vector<POINT>;
		//extra 메모리를 이용해서 각각의 윈도우 마다 메모리를 가지게함
		//SetWindowLong(),GetWindowLong()
		SetWindowLong(hwnd,/*실행할 작업기술*/0,(LONG)new vector<POINT>); //Proc를 두개로 만들어도되지만 비효율이다.
		//윈도우에 할당된 LONG형식의 메모리공간을 사용할 수 있다.
		break;
	case WM_LBUTTONDOWN:
		{
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);
			vector<POINT>* pv = (vector<POINT>*)GetWindowLong(hwnd,0);
			(pv)->push_back(pt);
			InvalidateRect(hwnd,NULL,TRUE);
		}
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_PAINT:
		{
			vector<POINT>* pv = (vector<POINT>*)GetWindowLong(hwnd,0);
			hdc = BeginPaint(hwnd,&ps);
			for(unsigned i=0;i<(pv)->size();i++)
			{
				//const POINT&pt = (*ptMap[hwnd])[i];
				const POINT&pt = pv->at(i);
				Ellipse(hdc,pt.x-20,pt.y-20,pt.x+20,pt.y+20);
			}
			EndPaint(hwnd,&ps);
		}
		break;
	case WM_DESTROY:
		delete (vector<POINT>*)GetWindowLong(hwnd,0); //LONG형식을 반환하므로 형변환이 필요하다.
		break;
	}
	return DefWindowProc(hwnd,iMsg,wParam,lParam);
}
//vector를 공유하기때문에 각각윈도우에서 독립적으로 저장이 불가능하다