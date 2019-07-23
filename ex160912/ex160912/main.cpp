//
//#include <windows.h>
//#include "resource.h"
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hInst;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
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
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);		
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
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_MODAL:
//			{
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG),hwnd,DlgProc);
//			}
//			break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//
//
//#include <windows.h>
//#include "resource.h"
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hInst;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
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
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);		
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
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_MODAL:
//			{
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
//			}
//			break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_BUTTON1:
//			{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//			break;
//		case IDC_EDIT1:
//			switch(HIWORD(wParam))
//			{
//			case EN_CHANGE:
//				{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//				break;
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//
//#include <windows.h>
//#include "resource.h"
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hInst;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
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
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);		
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
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_MODAL:
//			{
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
//			}
//			break;
//		case ID_SHAPE:
//			DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG2),hwnd,DlgProc);
//			break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		CheckRadioButton(hDlg,IDC_RADIO1,IDC_RADIO3,IDC_RADIO3);
//		CheckRadioButton(hDlg,IDC_RADIO4,IDC_RADIO6,IDC_RADIO6);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_BUTTON1:
//			{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//			break;
//		case IDC_EDIT1:
//			switch(HIWORD(wParam))
//			{
//			case EN_CHANGE:
//				{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//				break;
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//
//#include <windows.h>
//#include "resource.h"
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hInst;
//int shapeType;
//int colorType;
//HWND hMainWnd;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
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
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hMainWnd = hwnd = CreateWindow("Window Class Name",
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
//COLORREF SelectColor(int colorType)
//{
//	switch(colorType)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//	case 1:
//		return RGB(0,0,0xff);
//	case 2:
//		return RGB(0,0xff,0);
//	default:
//		return RGB(0,0,0);
//	}
//}
//void DrawRowRect(HDC hdc,int shapeType)
//{
//	RECT rt;
//	GetClientRect(hMainWnd,&rt);
//
//	switch(shapeType)
//	{
//	case 0:
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 1:
//		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 2:
//		MoveToEx(hdc,rt.left,rt.top,NULL);
//		LineTo(hdc,rt.right,rt.bottom);
//		break;
//	}
//}
//void DrawRect(HDC hdc,int shapeType,int colorType)
//{
//	HPEN hNewPen = CreatePen(PS_SOLID,2,SelectColor(colorType));
//	HPEN hOldPen = (HPEN)SelectObject(hdc,hNewPen);
//	DrawRowRect(hdc,shapeType);
//	SelectObject(hdc,hOldPen);
//	DeleteObject(hNewPen);
//
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_MODAL:
//			{
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
//			}
//			break;
//		case ID_SHAPE:
//			
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG2),hwnd,ShapeDlgProc))
//				InvalidateRect(hwnd,NULL,TRUE);
//			break;
//		case ID_CHANGERECT:
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG3),hwnd,ChangeDlgProc);
//			break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRect(hdc,shapeType,colorType);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_BUTTON1:
//			{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//			break;
//		case IDC_EDIT1:
//			switch(HIWORD(wParam))
//			{
//			case EN_CHANGE:
//				{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//				break;
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		CheckRadioButton(hDlg,IDC_RADIO1,IDC_RADIO3,shapeType+IDC_RADIO1);
//		CheckRadioButton(hDlg,IDC_RADIO4,IDC_RADIO6,colorType+IDC_RADIO4);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_RADIO1: shapeType = 0;
//			break;
//		case IDC_RADIO2: shapeType = 1;
//			break;
//		case IDC_RADIO3: shapeType = 2;
//			break;
//		case IDC_RADIO4: colorType = 0;
//			break;
//		case IDC_RADIO5: colorType = 1;
//			break;
//		case IDC_RADIO6: colorType = 2;
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_BUTTON1:
//			{
//				RECT rt;
//				rt.left = GetDlgItemInt(hDlg,IDC_EDIT1,NULL,TRUE);
//				rt.top = GetDlgItemInt(hDlg,IDC_EDIT2,NULL,TRUE);
//				rt.right = GetDlgItemInt(hDlg,IDC_EDIT3,NULL,TRUE);
//				rt.bottom = GetDlgItemInt(hDlg,IDC_EDIT4,NULL,TRUE);
//
//				TCHAR buf[200];
//				wsprintf(buf,"(%d,%d - %d,%d)",rt.left,rt.top,rt.right,rt.bottom);
//				SendMessage(GetDlgItem(hDlg,IDC_LIST1),LB_ADDSTRING,0,(LPARAM)buf);//문자열의 시작주소를 올려준다.
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
////SendMessage(handle,message,wparam,lparam) 
////PostMessage(handle,message,wparam,lparam)
//
//
//#include <windows.h>
//#include "resource.h"
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hInst;
//int shapeType;
//int colorType;
//HWND hMainWnd;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
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
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hMainWnd = hwnd = CreateWindow("Window Class Name",
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
//COLORREF SelectColor(int colorType)
//{
//	switch(colorType)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//	case 1:
//		return RGB(0,0,0xff);
//	case 2:
//		return RGB(0,0xff,0);
//	default:
//		return RGB(0,0,0);
//	}
//}
//void DrawRowRect(HDC hdc,int shapeType)
//{
//	RECT rt;
//	GetClientRect(hMainWnd,&rt);
//
//	switch(shapeType)
//	{
//	case 0:
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 1:
//		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 2:
//		MoveToEx(hdc,rt.left,rt.top,NULL);
//		LineTo(hdc,rt.right,rt.bottom);
//		break;
//	}
//}
//void DrawRect(HDC hdc,int shapeType,int colorType)
//{
//	HPEN hNewPen = CreatePen(PS_SOLID,2,SelectColor(colorType));
//	HPEN hOldPen = (HPEN)SelectObject(hdc,hNewPen);
//	DrawRowRect(hdc,shapeType);
//	SelectObject(hdc,hOldPen);
//	DeleteObject(hNewPen);
//
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_MODAL:
//			{
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
//			}
//			break;
//		case ID_SHAPE:
//			
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG2),hwnd,ShapeDlgProc))
//				InvalidateRect(hwnd,NULL,TRUE);
//			break;
//		case ID_CHANGERECT:
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG3),hwnd,ChangeDlgProc);
//			break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRect(hdc,shapeType,colorType);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_BUTTON1:
//			{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//			break;
//		case IDC_EDIT1:
//			switch(HIWORD(wParam))
//			{
//			case EN_CHANGE:
//				{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//				break;
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		CheckRadioButton(hDlg,IDC_RADIO1,IDC_RADIO3,shapeType+IDC_RADIO1);
//		CheckRadioButton(hDlg,IDC_RADIO4,IDC_RADIO6,colorType+IDC_RADIO4);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_RADIO1: shapeType = 0;
//			break;
//		case IDC_RADIO2: shapeType = 1;
//			break;
//		case IDC_RADIO3: shapeType = 2;
//			break;
//		case IDC_RADIO4: colorType = 0;
//			break;
//		case IDC_RADIO5: colorType = 1;
//			break;
//		case IDC_RADIO6: colorType = 2;
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_BUTTON1:
//			{
//				RECT rt;
//				rt.left = GetDlgItemInt(hDlg,IDC_EDIT1,NULL,TRUE);
//				rt.top = GetDlgItemInt(hDlg,IDC_EDIT2,NULL,TRUE);
//				rt.right = GetDlgItemInt(hDlg,IDC_EDIT3,NULL,TRUE);
//				rt.bottom = GetDlgItemInt(hDlg,IDC_EDIT4,NULL,TRUE);
//
//				TCHAR buf[200];
//				wsprintf(buf,"(%d,%d - %d,%d)",rt.left,rt.top,rt.right,rt.bottom);
//				//SendMessage(GetDlgItem(hDlg,IDC_LIST1),LB_ADDSTRING,0,(LPARAM)buf);//문자열의 시작주소를 올려준다.
//				SendDlgItemMessage(hDlg,IDC_LIST1,LB_ADDSTRING,0,(LPARAM)buf);
//				int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCOUNT,0,0);
//				if(sel>0)
//				SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)(sel-1),0);
//				SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)-1,0);
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
////SendMessage(handle,message,wparam,lparam) 
////PostMessage(handle,message,wparam,lparam)
////ListBox의 sort속성을 true라고 하면 자동정렬되므로 기능에따라 false로 바꿔준다.

//
//
//#include <windows.h>
//#include "resource.h"
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hInst;
//int shapeType;
//int colorType;
//RECT rtDraw = {100,100,200,200};
//HWND hMainWnd;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
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
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hMainWnd = hwnd = CreateWindow("Window Class Name",
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
//COLORREF SelectColor(int colorType)
//{
//	switch(colorType)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//	case 1:
//		return RGB(0,0,0xff);
//	case 2:
//		return RGB(0,0xff,0);
//	default:
//		return RGB(0,0,0);
//	}
//}
//void DrawRowRect(HDC hdc,int shapeType)
//{
//	RECT rt;
//	GetClientRect(hMainWnd,&rt);
//
//	switch(shapeType)
//	{
//	case 0:
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 1:
//		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 2:
//		MoveToEx(hdc,rt.left,rt.top,NULL);
//		LineTo(hdc,rt.right,rt.bottom);
//		break;
//	}
//}
//void DrawRect(HDC hdc,int shapeType,int colorType)
//{
//	HPEN hNewPen = CreatePen(PS_SOLID,2,SelectColor(colorType));
//	HPEN hOldPen = (HPEN)SelectObject(hdc,hNewPen);
//	DrawRowRect(hdc,shapeType);
//	SelectObject(hdc,hOldPen);
//	DeleteObject(hNewPen);
//
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_MODAL:
//			{
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
//			}
//			break;
//		case ID_SHAPE:
//
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG2),hwnd,ShapeDlgProc))
//				InvalidateRect(hwnd,NULL,TRUE);
//			break;
//		case ID_CHANGERECT:
//			DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG3),hwnd,ChangeDlgProc);
//			break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRect(hdc,shapeType,colorType);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_BUTTON1:
//			{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//			break;
//		case IDC_EDIT1:
//			switch(HIWORD(wParam))
//			{
//			case EN_CHANGE:
//				{
//					TCHAR buf[200];
//					GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//					SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//				}
//				break;
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		CheckRadioButton(hDlg,IDC_RADIO1,IDC_RADIO3,shapeType+IDC_RADIO1);
//		CheckRadioButton(hDlg,IDC_RADIO4,IDC_RADIO6,colorType+IDC_RADIO4);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_RADIO1: shapeType = 0;
//			break;
//		case IDC_RADIO2: shapeType = 1;
//			break;
//		case IDC_RADIO3: shapeType = 2;
//			break;
//		case IDC_RADIO4: colorType = 0;
//			break;
//		case IDC_RADIO5: colorType = 1;
//			break;
//		case IDC_RADIO6: colorType = 2;
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		SetDlgItemInt(hDlg,IDC_EDIT1,rtDraw.left,TRUE);
//		SetDlgItemInt(hDlg,IDC_EDIT2,rtDraw.top,TRUE);
//		SetDlgItemInt(hDlg,IDC_EDIT3,rtDraw.right,TRUE);
//		SetDlgItemInt(hDlg,IDC_EDIT4,rtDraw.bottom,TRUE);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_LIST1:
//			switch(HIWORD(wParam))
//			{
//			case LBN_SELCHANGE:
//				{
//					int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCURSEL,0,0); //LB_GETCURSEL ==> 현재 셀번호를 얻어와라
//					if(sel>=0) //개수가 아니므로 가능
//					{
//						TCHAR buf[200];
//						SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETTEXT,(WPARAM)sel,(LPARAM)buf);
//						SetWindowText(hDlg,buf);
//					}
//				}
//				break;
//			}
//			break;
//		case IDC_BUTTON1:
//			{
//				RECT rt;
//				rt.left = GetDlgItemInt(hDlg,IDC_EDIT1,NULL,TRUE);
//				rt.top = GetDlgItemInt(hDlg,IDC_EDIT2,NULL,TRUE);
//				rt.right = GetDlgItemInt(hDlg,IDC_EDIT3,NULL,TRUE);
//				rt.bottom = GetDlgItemInt(hDlg,IDC_EDIT4,NULL,TRUE);
//				rtDraw = rt;  //쓰던안쓰던 저장을 해놔야한다.
//
//				TCHAR buf[200];
//				wsprintf(buf,"(%d,%d - %d,%d)",rt.left,rt.top,rt.right,rt.bottom);
//				//SendMessage(GetDlgItem(hDlg,IDC_LIST1),LB_ADDSTRING,0,(LPARAM)buf);//문자열의 시작주소를 올려준다.
//				SendDlgItemMessage(hDlg,IDC_LIST1,LB_ADDSTRING,0,(LPARAM)buf);
//				int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCOUNT,0,0);
//				if(sel>0)
//					SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)(sel-1),0);
//				SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)-1,0);
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
////ListBox의 속성중 Notify를 true로 하지않으면 알림을 못함



//
//
/////////////////////////////리팩토링///////////////////////////////
//#include <windows.h>
//#include<vector>
//#include "resource.h"
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hInst;
//int shapeType;
//int colorType;
//RECT rtDraw = {100,100,200,200};
//HWND hMainWnd;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
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
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hMainWnd = hwnd = CreateWindow("Window Class Name",
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
//COLORREF SelectColor(int colorType)
//{
//	switch(colorType)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//	case 1:
//		return RGB(0,0,0xff);
//	case 2:
//		return RGB(0,0xff,0);
//	default:
//		return RGB(0,0,0);
//	}
//}
//void DrawRowRect(HDC hdc,int shapeType)
//{
//	RECT rt;
//	GetClientRect(hMainWnd,&rt);
//
//	switch(shapeType)
//	{
//	case 0:
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 1:
//		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 2:
//		MoveToEx(hdc,rt.left,rt.top,NULL);
//		LineTo(hdc,rt.right,rt.bottom);
//		break;
//	}
//}
//void DrawRect(HDC hdc,int shapeType,int colorType)
//{
//	HPEN hNewPen = CreatePen(PS_SOLID,2,SelectColor(colorType));
//	HPEN hOldPen = (HPEN)SelectObject(hdc,hNewPen);
//	DrawRowRect(hdc,shapeType);
//	SelectObject(hdc,hOldPen);
//	DeleteObject(hNewPen);
//
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_MODAL:
//			{
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
//			}
//			break;
//		case ID_SHAPE:
//
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG2),hwnd,ShapeDlgProc))
//				InvalidateRect(hwnd,NULL,TRUE);
//			break;
//		case ID_CHANGERECT:
//			DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG3),hwnd,ChangeDlgProc);
//			break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRect(hdc,shapeType,colorType);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_BUTTON1:
//			{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//			break;
//		case IDC_EDIT1:
//			switch(HIWORD(wParam))
//			{
//			case EN_CHANGE:
//				{
//					TCHAR buf[200];
//					GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//					SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//				}
//				break;
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		CheckRadioButton(hDlg,IDC_RADIO1,IDC_RADIO3,shapeType+IDC_RADIO1);
//		CheckRadioButton(hDlg,IDC_RADIO4,IDC_RADIO6,colorType+IDC_RADIO4);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_RADIO1: shapeType = 0;
//			break;
//		case IDC_RADIO2: shapeType = 1;
//			break;
//		case IDC_RADIO3: shapeType = 2;
//			break;
//		case IDC_RADIO4: colorType = 0;
//			break;
//		case IDC_RADIO5: colorType = 1;
//			break;
//		case IDC_RADIO6: colorType = 2;
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//void UpdateList(HWND hDlg,vector<RECT>&rtList)
//{
//	SendDlgItemMessage(hDlg,IDC_LIST1,LB_RESETCONTENT,0,0); //리스트를 비우는 역할
//	for(unsigned i=0;i<rtList.size();i++)
//	{
//		const RECT& rt = rtList[i];
//		TCHAR buf[200];
//		wsprintf(buf,"(%d,%d - %d,%d)",rt.left,rt.top,rt.right,rt.bottom);
//		//SendMessage(GetDlgItem(hDlg,IDC_LIST1),LB_ADDSTRING,0,(LPARAM)buf);//문자열의 시작주소를 올려준다.
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_ADDSTRING,0,(LPARAM)buf);
//	}
//	int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCOUNT,0,0);
//	if(sel>0)
//	{
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)(sel-1),0);
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)-1,0);
//	}
//}
//void UpdateEdit(HWND hDlg,const RECT & rt)
//{
//	SetDlgItemInt(hDlg,IDC_EDIT1,rt.left,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT2,rt.top,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT3,rt.right,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT4,rt.bottom,TRUE);
//}
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	static vector<RECT> rtList;
//
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		SetDlgItemInt(hDlg,IDC_EDIT1,rtDraw.left,TRUE);
//		SetDlgItemInt(hDlg,IDC_EDIT2,rtDraw.top,TRUE);
//		SetDlgItemInt(hDlg,IDC_EDIT3,rtDraw.right,TRUE);
//		SetDlgItemInt(hDlg,IDC_EDIT4,rtDraw.bottom,TRUE);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_LIST1:
//			switch(HIWORD(wParam))
//			{
//			case LBN_SELCHANGE:
//				{
//					int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCURSEL,0,0); //LB_GETCURSEL ==> 현재 셀번호를 얻어와라
//					if(sel >= 0) //개수가 아니므로 가능
//					{
//						rtDraw = rtList[sel];
//						UpdateEdit(hDlg,rtDraw);
//					}
//				}
//				break;
//			}
//			break;
//		case IDC_BUTTON1:
//			{
//				rtDraw.left = GetDlgItemInt(hDlg,IDC_EDIT1,NULL,TRUE);
//				rtDraw.top = GetDlgItemInt(hDlg,IDC_EDIT2,NULL,TRUE);
//				rtDraw.right = GetDlgItemInt(hDlg,IDC_EDIT3,NULL,TRUE);
//				rtDraw.bottom = GetDlgItemInt(hDlg,IDC_EDIT4,NULL,TRUE);
//
//				rtList.push_back(rtDraw);
//				UpdateList(hDlg,rtList);  //원래 이렇게 안한다.
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
////ListBox의 속성중 Notify를 true로 하지않으면 알림을 못함
//
//
/////////////////////////////리팩토링///////////////////////////////
//#include <windows.h>
//#include<vector>
//#include "resource.h"
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hInst;
//int shapeType;
//int colorType;
//RECT rtDraw = {100,100,200,200};
//HWND hMainWnd;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
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
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hMainWnd = hwnd = CreateWindow("Window Class Name",
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
//COLORREF SelectColor(int colorType)
//{
//	switch(colorType)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//	case 1:
//		return RGB(0,0,0xff);
//	case 2:
//		return RGB(0,0xff,0);
//	default:
//		return RGB(0,0,0);
//	}
//}
//void DrawRowRect(HDC hdc, const RECT&rt ,int shapeType)
//{
//	/*RECT rt;
//	GetClientRect(hMainWnd,&rt);*/
//
//	switch(shapeType)
//	{
//	case 0:
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 1:
//		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 2:
//		MoveToEx(hdc,rt.left,rt.top,NULL);
//		LineTo(hdc,rt.right,rt.bottom);
//		break;
//	}
//}
//void DrawRect(HDC hdc, const RECT&rt ,int shapeType,int colorType)
//{
//	HPEN hNewPen = CreatePen(PS_SOLID,2,SelectColor(colorType));
//	HPEN hOldPen = (HPEN)SelectObject(hdc,hNewPen);
//	DrawRowRect(hdc , rt , shapeType);
//	SelectObject(hdc,hOldPen);
//	DeleteObject(hNewPen);
//
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_MODAL:
//			{
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
//			}
//			break;
//		case ID_SHAPE:
//
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG2),hwnd,ShapeDlgProc))
//				InvalidateRect(hwnd,NULL,TRUE);
//			break;
//		case ID_CHANGERECT:
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG3),hwnd,ChangeDlgProc))
//				InvalidateRect(hwnd,NULL,TRUE);
//			break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRect(hdc , rtDraw , shapeType , colorType);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_BUTTON1:
//			{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//			break;
//		case IDC_EDIT1:
//			switch(HIWORD(wParam))
//			{
//			case EN_CHANGE:
//				{
//					TCHAR buf[200];
//					GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//					SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//				}
//				break;
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		CheckRadioButton(hDlg,IDC_RADIO1,IDC_RADIO3,shapeType+IDC_RADIO1);
//		CheckRadioButton(hDlg,IDC_RADIO4,IDC_RADIO6,colorType+IDC_RADIO4);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_RADIO1: shapeType = 0;
//			break;
//		case IDC_RADIO2: shapeType = 1;
//			break;
//		case IDC_RADIO3: shapeType = 2;
//			break;
//		case IDC_RADIO4: colorType = 0;
//			break;
//		case IDC_RADIO5: colorType = 1;
//			break;
//		case IDC_RADIO6: colorType = 2;
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//void UpdateList(HWND hDlg,vector<RECT>&rtList)
//{
//	SendDlgItemMessage(hDlg,IDC_LIST1,LB_RESETCONTENT,0,0); //리스트를 비우는 역할
//	for(unsigned i=0;i<rtList.size();i++)
//	{
//		const RECT& rt = rtList[i];
//		TCHAR buf[200];
//		wsprintf(buf,"(%d,%d - %d,%d)",rt.left,rt.top,rt.right,rt.bottom);
//		//SendMessage(GetDlgItem(hDlg,IDC_LIST1),LB_ADDSTRING,0,(LPARAM)buf);//문자열의 시작주소를 올려준다.
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_ADDSTRING,0,(LPARAM)buf);
//	}
//	int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCOUNT,0,0);
//	if(sel>0)
//	{
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)(sel-1),0);
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)-1,0);
//	}
//}
//void UpdateEdit(HWND hDlg,const RECT & rt)
//{
//	SetDlgItemInt(hDlg,IDC_EDIT1,rt.left,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT2,rt.top,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT3,rt.right,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT4,rt.bottom,TRUE);
//}
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	static vector<RECT> rtList;
//
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		SetDlgItemInt(hDlg,IDC_EDIT1,rtDraw.left,TRUE);
//		SetDlgItemInt(hDlg,IDC_EDIT2,rtDraw.top,TRUE);
//		SetDlgItemInt(hDlg,IDC_EDIT3,rtDraw.right,TRUE);
//		SetDlgItemInt(hDlg,IDC_EDIT4,rtDraw.bottom,TRUE);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_LIST1:
//			switch(HIWORD(wParam))
//			{
//			case LBN_SELCHANGE:
//				{
//					int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCURSEL,0,0); //LB_GETCURSEL ==> 현재 셀번호를 얻어와라
//					if(sel >= 0) //개수가 아니므로 가능
//					{
//						rtDraw = rtList[sel];
//						UpdateEdit(hDlg,rtDraw);
//					}
//				}
//				break;
//			}
//			break;
//		case IDC_BUTTON1:
//			{
//				rtDraw.left = GetDlgItemInt(hDlg,IDC_EDIT1,NULL,TRUE);
//				rtDraw.top = GetDlgItemInt(hDlg,IDC_EDIT2,NULL,TRUE);
//				rtDraw.right = GetDlgItemInt(hDlg,IDC_EDIT3,NULL,TRUE);
//				rtDraw.bottom = GetDlgItemInt(hDlg,IDC_EDIT4,NULL,TRUE);
//				rtList.push_back(rtDraw);
//				UpdateList(hDlg,rtList);  //원래 이렇게 안한다.
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
////ListBox의 속성중 Notify를 true로 하지않으면 알림을 못함
//
//
/////////////////////////////리팩토링///////////////////////////////
//#include <windows.h>
//#include<vector>
//#include "resource.h"
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hInst;
//int shapeType;
//int colorType;
//RECT rtDlg = {100,100,200,200};
//HWND hMainWnd;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
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
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hMainWnd = hwnd = CreateWindow("Window Class Name",
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
//COLORREF SelectColor(int colorType)
//{
//	switch(colorType)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//	case 1:
//		return RGB(0,0,0xff);
//	case 2:
//		return RGB(0,0xff,0);
//	default:
//		return RGB(0,0,0);
//	}
//}
//void DrawRowRect(HDC hdc, const RECT&rt ,int shapeType)
//{
//	/*RECT rt;
//	GetClientRect(hMainWnd,&rt);*/
//
//	switch(shapeType)
//	{
//	case 0:
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 1:
//		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 2:
//		MoveToEx(hdc,rt.left,rt.top,NULL);
//		LineTo(hdc,rt.right,rt.bottom);
//		break;
//	}
//}
//void DrawRect(HDC hdc, const RECT&rt ,int shapeType,int colorType)
//{
//	HPEN hNewPen = CreatePen(PS_SOLID,2,SelectColor(colorType));
//	HPEN hOldPen = (HPEN)SelectObject(hdc,hNewPen);
//	DrawRowRect(hdc , rt , shapeType);
//	SelectObject(hdc,hOldPen);
//	DeleteObject(hNewPen);
//
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rtDraw;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break; 
//	case WM_SIZE:
//		GetClientRect(hwnd,&rtDraw);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_MODAL:
//			{
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
//			}
//			break;
//		case ID_SHAPE:
//
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG2),hwnd,ShapeDlgProc))
//				InvalidateRect(hwnd,NULL,TRUE);
//			break;
//		case ID_CHANGERECT:
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG3),hwnd,ChangeDlgProc))
//			{
//				rtDraw = rtDlg;
//				InvalidateRect(hwnd,NULL,TRUE);
//			}
//			break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRect(hdc , rtDraw , shapeType , colorType);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_BUTTON1:
//			{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//			break;
//		case IDC_EDIT1:
//			switch(HIWORD(wParam))
//			{
//			case EN_CHANGE:
//				{
//					TCHAR buf[200];
//					GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//					SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//				}
//				break;
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		CheckRadioButton(hDlg,IDC_RADIO1,IDC_RADIO3,shapeType+IDC_RADIO1);
//		CheckRadioButton(hDlg,IDC_RADIO4,IDC_RADIO6,colorType+IDC_RADIO4);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_RADIO1: shapeType = 0;
//			break;
//		case IDC_RADIO2: shapeType = 1;
//			break;
//		case IDC_RADIO3: shapeType = 2;
//			break;
//		case IDC_RADIO4: colorType = 0;
//			break;
//		case IDC_RADIO5: colorType = 1;
//			break;
//		case IDC_RADIO6: colorType = 2;
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//void UpdateList(HWND hDlg,vector<RECT>&rtList)
//{
//	SendDlgItemMessage(hDlg,IDC_LIST1,LB_RESETCONTENT,0,0); //리스트를 비우는 역할
//	for(unsigned i=0;i<rtList.size();i++)
//	{
//		const RECT& rt = rtList[i];
//		TCHAR buf[200];
//		wsprintf(buf,"(%d,%d - %d,%d)",rt.left,rt.top,rt.right,rt.bottom);
//		//SendMessage(GetDlgItem(hDlg,IDC_LIST1),LB_ADDSTRING,0,(LPARAM)buf);//문자열의 시작주소를 올려준다.
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_ADDSTRING,0,(LPARAM)buf);
//	}
//	int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCOUNT,0,0);
//	if(sel>0)
//	{
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)(sel-1),0);
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)-1,0);
//	}
//}
//void UpdateEdit(HWND hDlg,const RECT & rt)
//{
//	SetDlgItemInt(hDlg,IDC_EDIT1,rt.left,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT2,rt.top,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT3,rt.right,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT4,rt.bottom,TRUE);
//}
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	static vector<RECT> rtList;
//
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		SetRect(&rtDlg,100,100,200,200);
//		UpdateEdit(hDlg,rtDlg);
//		rtList.clear();
//		UpdateList(hDlg,rtList);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_LIST1:
//			switch(HIWORD(wParam))
//			{
//			case LBN_SELCHANGE:
//				{
//					int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCURSEL,0,0); //LB_GETCURSEL ==> 현재 셀번호를 얻어와라
//					if(sel >= 0) //개수가 아니므로 가능
//					{
//						rtDlg = rtList[sel];
//						UpdateEdit(hDlg,rtDlg);
//					}
//				}
//				break;
//			}
//			break;
//		case IDC_BUTTON1:
//			{
//				rtDlg.left = GetDlgItemInt(hDlg,IDC_EDIT1,NULL,TRUE);
//				rtDlg.top = GetDlgItemInt(hDlg,IDC_EDIT2,NULL,TRUE);
//				rtDlg.right = GetDlgItemInt(hDlg,IDC_EDIT3,NULL,TRUE);
//				rtDlg.bottom = GetDlgItemInt(hDlg,IDC_EDIT4,NULL,TRUE);
//				rtList.push_back(rtDlg);
//				UpdateList(hDlg,rtList);  //원래 이렇게 안한다.
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
////ListBox의 속성중 Notify를 true로 하지않으면 알림을 못함
////내일은 스크롤 사용하여 색상변경하겠습니다.

//
//
/////////////////////////////리팩토링///////////////////////////////
//#include <windows.h>
//#include<vector>
//#include "resource.h"
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hInst;
//int shapeType;
//int colorType;
//int bkcolorType;
//RECT rtDlg = {100,100,200,200};
//HWND hMainWnd;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
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
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hMainWnd = hwnd = CreateWindow("Window Class Name",
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
//COLORREF SelectColor(int colorType)
//{
//	switch(colorType)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//	case 1:
//		return RGB(0,0,0xff);
//	case 2:
//		return RGB(0,0xff,0);
//	default:
//		return RGB(0,0,0);
//	}
//}
//void DrawRowRect(HDC hdc, const RECT&rt ,int shapeType)
//{
//	/*RECT rt;
//	GetClientRect(hMainWnd,&rt);*/
//
//	switch(shapeType)
//	{
//	case 0:
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 1:
//		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 2:
//		MoveToEx(hdc,rt.left,rt.top,NULL);
//		LineTo(hdc,rt.right,rt.bottom);
//		break;
//	}
//}
//void DrawRect(HDC hdc, const RECT&rt ,int shapeType,int colorType,int bkcolorType)
//{
//	HPEN hNewPen = CreatePen(PS_SOLID,2,SelectColor(colorType));
//	HPEN hOldPen = (HPEN)SelectObject(hdc,hNewPen);
//	HBRUSH hNewBrush = CreateSolidBrush(SelectColor(bkcolorType));
//	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);
//
//	DrawRowRect(hdc , rt , shapeType);
//
//	SelectObject(hdc,hOldBrush);
//	SelectObject(hdc,hOldPen);
//	DeleteObject(hNewBrush);
//	DeleteObject(hNewPen);
//
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rtDraw;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break; 
//	case WM_SIZE:
//		GetClientRect(hwnd,&rtDraw);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_MODAL:
//			{
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
//			}
//			break;
//		case ID_SHAPE:
//
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG2),hwnd,ShapeDlgProc))
//				InvalidateRect(hwnd,NULL,TRUE);
//			break;
//		case ID_CHANGERECT:
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG3),hwnd,ChangeDlgProc))
//			{
//				rtDraw = rtDlg;
//				InvalidateRect(hwnd,NULL,TRUE);
//			}
//			break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRect(hdc , rtDraw , shapeType , colorType , bkcolorType);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_BUTTON1:
//			{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//			break;
//		case IDC_EDIT1:
//			switch(HIWORD(wParam))
//			{
//			case EN_CHANGE:
//				{
//					TCHAR buf[200];
//					GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//					SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//				}
//				break;
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		CheckRadioButton(hDlg,IDC_RADIO1,IDC_RADIO3,shapeType+IDC_RADIO1);
//		CheckRadioButton(hDlg,IDC_RADIO4,IDC_RADIO6,colorType+IDC_RADIO4);
//		CheckRadioButton(hDlg,IDC_RADIO7,IDC_RADIO9,bkcolorType+IDC_RADIO7);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_RADIO1: shapeType = 0;
//			break;
//		case IDC_RADIO2: shapeType = 1;
//			break;
//		case IDC_RADIO3: shapeType = 2;
//			break;
//		case IDC_RADIO4: colorType = 0;
//			break;
//		case IDC_RADIO5: colorType = 1;
//			break;
//		case IDC_RADIO6: colorType = 2;
//			break;
//		case IDC_RADIO7: bkcolorType = 0;
//			break;
//		case IDC_RADIO8: bkcolorType = 1;
//			break;
//		case IDC_RADIO9: bkcolorType = 2;
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//void UpdateList(HWND hDlg,vector<RECT>&rtList)
//{
//	SendDlgItemMessage(hDlg,IDC_LIST1,LB_RESETCONTENT,0,0); //리스트를 비우는 역할
//	for(unsigned i=0;i<rtList.size();i++)
//	{
//		const RECT& rt = rtList[i];
//		TCHAR buf[200];
//		wsprintf(buf,"(%d,%d - %d,%d)",rt.left,rt.top,rt.right,rt.bottom);
//		//SendMessage(GetDlgItem(hDlg,IDC_LIST1),LB_ADDSTRING,0,(LPARAM)buf);//문자열의 시작주소를 올려준다.
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_ADDSTRING,0,(LPARAM)buf);
//	}
//	int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCOUNT,0,0);
//	if(sel>0)
//	{
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)(sel-1),0);
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)-1,0);
//	}
//}
//void UpdateEdit(HWND hDlg,const RECT & rt)
//{
//	SetDlgItemInt(hDlg,IDC_EDIT1,rt.left,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT2,rt.top,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT3,rt.right,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT4,rt.bottom,TRUE);
//}
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	static vector<RECT> rtList;
//
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		SetRect(&rtDlg,100,100,200,200);
//		UpdateEdit(hDlg,rtDlg);
//		rtList.clear();
//		UpdateList(hDlg,rtList);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_LIST1:
//			switch(HIWORD(wParam))
//			{
//			case LBN_SELCHANGE:
//				{
//					int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCURSEL,0,0); //LB_GETCURSEL ==> 현재 셀번호를 얻어와라
//					if(sel >= 0) //개수가 아니므로 가능
//					{
//						rtDlg = rtList[sel];
//						UpdateEdit(hDlg,rtDlg);
//					}
//				}
//				break;
//			}
//			break;
//		case IDC_BUTTON1:
//			{
//				rtDlg.left = GetDlgItemInt(hDlg,IDC_EDIT1,NULL,TRUE);
//				rtDlg.top = GetDlgItemInt(hDlg,IDC_EDIT2,NULL,TRUE);
//				rtDlg.right = GetDlgItemInt(hDlg,IDC_EDIT3,NULL,TRUE);
//				rtDlg.bottom = GetDlgItemInt(hDlg,IDC_EDIT4,NULL,TRUE);
//				rtList.push_back(rtDlg);
//				UpdateList(hDlg,rtList);  //원래 이렇게 안한다.
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
////ListBox의 속성중 Notify를 true로 하지않으면 알림을 못함
////내일은 스크롤 사용하여 색상변경하겠습니다.
//
//
////modal,modaless 다이얼로그 - 바로 적용되게 하려면 modaless로 띄우는게 맞다.
//#include <windows.h>
//#include<vector>
//#include "resource.h"
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK BrushDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hInst;
//HWND hModelessDlg;
//int shapeType;
//int colorType;
//int bkcolorType;
//RECT rtDlg = {100,100,200,200};
//HWND hMainWnd;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
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
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hMainWnd = hwnd = CreateWindow("Window Class Name",
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
//COLORREF SelectColor(int colorType)
//{
//	switch(colorType)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//	case 1:
//		return RGB(0,0,0xff);
//	case 2:
//		return RGB(0,0xff,0);
//	default:
//		return RGB(0,0,0);
//	}
//}
//void DrawRowRect(HDC hdc, const RECT&rt ,int shapeType)
//{
//	/*RECT rt;
//	GetClientRect(hMainWnd,&rt);*/
//
//	switch(shapeType)
//	{
//	case 0:
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 1:
//		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 2:
//		MoveToEx(hdc,rt.left,rt.top,NULL);
//		LineTo(hdc,rt.right,rt.bottom);
//		break;
//	}
//}
//void DrawRect(HDC hdc, const RECT&rt ,int shapeType,int colorType,int bkcolorType)
//{
//	HPEN hNewPen = CreatePen(PS_SOLID,2,SelectColor(colorType));
//	HPEN hOldPen = (HPEN)SelectObject(hdc,hNewPen);
//	HBRUSH hNewBrush = CreateSolidBrush(SelectColor(bkcolorType));
//	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);
//
//	DrawRowRect(hdc , rt , shapeType);
//
//	SelectObject(hdc,hOldBrush);
//	SelectObject(hdc,hOldPen);
//	DeleteObject(hNewBrush);
//	DeleteObject(hNewPen);
//
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rtDraw;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break; 
//	case WM_SIZE:
//		GetClientRect(hwnd,&rtDraw);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_MODAL:
//			{
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
//			}
//			break;
//		case ID_SHAPE:
//
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG2),hwnd,ShapeDlgProc))
//				InvalidateRect(hwnd,NULL,TRUE);
//			break;
//		case ID_CHANGERECT:
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG3),hwnd,ChangeDlgProc))
//			{
//				rtDraw = rtDlg;
//				InvalidateRect(hwnd,NULL,TRUE);
//			}
//			break;
//		case ID_BRUSHCHANGE:
//			//CreateWindow()와 같음
//			if(!IsWindow(hModelessDlg))//hModelessDlg==NULL
//			{
//				hModelessDlg = CreateDialog(g_hInst,MAKEINTRESOURCE(IDD_DIALOG4),hwnd,BrushDlgProc);
//				ShowWindow(hModelessDlg,SW_SHOW);//SW_SHOW는 default로 뜨워준다.
//			}
//			else
//			{
//				SetFocus(hModelessDlg); //이미 윈도우가 띄워져있으면 윈도우에 포커스를 주게하는 메서드
//			}
//			break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRect(hdc , rtDraw , shapeType , colorType , bkcolorType);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_BUTTON1:
//			{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//			break;
//		case IDC_EDIT1:
//			switch(HIWORD(wParam))
//			{
//			case EN_CHANGE:
//				{
//					TCHAR buf[200];
//					GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//					SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//				}
//				break;
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		CheckRadioButton(hDlg,IDC_RADIO1,IDC_RADIO3,shapeType+IDC_RADIO1);
//		CheckRadioButton(hDlg,IDC_RADIO4,IDC_RADIO6,colorType+IDC_RADIO4);
//		CheckRadioButton(hDlg,IDC_RADIO7,IDC_RADIO9,bkcolorType+IDC_RADIO7);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_RADIO1: shapeType = 0;
//			break;
//		case IDC_RADIO2: shapeType = 1;
//			break;
//		case IDC_RADIO3: shapeType = 2;
//			break;
//		case IDC_RADIO4: colorType = 0;
//			break;
//		case IDC_RADIO5: colorType = 1;
//			break;
//		case IDC_RADIO6: colorType = 2;
//			break;
//		case IDC_RADIO7: bkcolorType = 0;
//			break;
//		case IDC_RADIO8: bkcolorType = 1;
//			break;
//		case IDC_RADIO9: bkcolorType = 2;
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//void UpdateList(HWND hDlg,vector<RECT>&rtList)
//{
//	SendDlgItemMessage(hDlg,IDC_LIST1,LB_RESETCONTENT,0,0); //리스트를 비우는 역할
//	for(unsigned i=0;i<rtList.size();i++)
//	{
//		const RECT& rt = rtList[i];
//		TCHAR buf[200];
//		wsprintf(buf,"(%d,%d - %d,%d)",rt.left,rt.top,rt.right,rt.bottom);
//		//SendMessage(GetDlgItem(hDlg,IDC_LIST1),LB_ADDSTRING,0,(LPARAM)buf);//문자열의 시작주소를 올려준다.
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_ADDSTRING,0,(LPARAM)buf);
//	}
//	int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCOUNT,0,0);
//	if(sel>0)
//	{
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)(sel-1),0);
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)-1,0);
//	}
//}
//void UpdateEdit(HWND hDlg,const RECT & rt)
//{
//	SetDlgItemInt(hDlg,IDC_EDIT1,rt.left,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT2,rt.top,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT3,rt.right,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT4,rt.bottom,TRUE);
//}
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	static vector<RECT> rtList;
//
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		SetRect(&rtDlg,100,100,200,200);
//		UpdateEdit(hDlg,rtDlg);
//		rtList.clear();
//		UpdateList(hDlg,rtList);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_LIST1:
//			switch(HIWORD(wParam))
//			{
//			case LBN_SELCHANGE:
//				{
//					int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCURSEL,0,0); //LB_GETCURSEL ==> 현재 셀번호를 얻어와라
//					if(sel >= 0) //개수가 아니므로 가능
//					{
//						rtDlg = rtList[sel];
//						UpdateEdit(hDlg,rtDlg);
//					}
//				}
//				break;
//			}
//			break;
//		case IDC_BUTTON1:
//			{
//				rtDlg.left = GetDlgItemInt(hDlg,IDC_EDIT1,NULL,TRUE);
//				rtDlg.top = GetDlgItemInt(hDlg,IDC_EDIT2,NULL,TRUE);
//				rtDlg.right = GetDlgItemInt(hDlg,IDC_EDIT3,NULL,TRUE);
//				rtDlg.bottom = GetDlgItemInt(hDlg,IDC_EDIT4,NULL,TRUE);
//				rtList.push_back(rtDlg);
//				UpdateList(hDlg,rtList);  //원래 이렇게 안한다.
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//BOOL CALLBACK BrushDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)//modeless다이얼로그라서 COMMAND가 필요 없다.
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_CLOSE:
//		DestroyWindow(hModelessDlg);
//		hModelessDlg = NULL;
//		break;
//	}
//	return FALSE;
//}
//
//
////modal,modaless 다이얼로그 - 바로 적용되게 하려면 modaless로 띄우는게 맞다.
//#include <windows.h>
//#include<vector>
//#include "resource.h"
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK BrushDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hInst;
//HWND hModelessDlg;
//int shapeType;
//int colorType;
//int bkcolorType;
//UINT nR,nG,nB;
//
//RECT rtDlg = {100,100,200,200};
//HWND hMainWnd;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
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
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hMainWnd = hwnd = CreateWindow("Window Class Name",
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
//COLORREF SelectColor(int colorType)
//{
//	switch(colorType)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//	case 1:
//		return RGB(0,0,0xff);
//	case 2:
//		return RGB(0,0xff,0);
//	default:
//		return RGB(0,0,0);
//	}
//}
//void DrawRowRect(HDC hdc, const RECT&rt ,int shapeType)
//{
//	/*RECT rt;
//	GetClientRect(hMainWnd,&rt);*/
//
//	switch(shapeType)
//	{
//	case 0:
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 1:
//		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 2:
//		MoveToEx(hdc,rt.left,rt.top,NULL);
//		LineTo(hdc,rt.right,rt.bottom);
//		break;
//	}
//}
//void DrawRect(HDC hdc, const RECT&rt ,int shapeType,int colorType,int bkcolorType)
//{
//	HPEN hNewPen = CreatePen(PS_SOLID,2,SelectColor(colorType));
//	HPEN hOldPen = (HPEN)SelectObject(hdc,hNewPen);
//	HBRUSH hNewBrush = CreateSolidBrush(SelectColor(bkcolorType));
//	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);
//
//	DrawRowRect(hdc , rt , shapeType);
//
//	SelectObject(hdc,hOldBrush);
//	SelectObject(hdc,hOldPen);
//	DeleteObject(hNewBrush);
//	DeleteObject(hNewPen);
//
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rtDraw;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break; 
//	case WM_SIZE:
//		GetClientRect(hwnd,&rtDraw);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_MODAL:
//			{
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
//			}
//			break;
//		case ID_SHAPE:
//
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG2),hwnd,ShapeDlgProc))
//				InvalidateRect(hwnd,NULL,TRUE);
//			break;
//		case ID_CHANGERECT:
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG3),hwnd,ChangeDlgProc))
//			{
//				rtDraw = rtDlg;
//				InvalidateRect(hwnd,NULL,TRUE);
//			}
//			break;
//		case ID_BRUSHCHANGE:
//			//CreateWindow()와 같음
//			if(!IsWindow(hModelessDlg))//hModelessDlg==NULL
//			{
//				hModelessDlg = CreateDialog(g_hInst,MAKEINTRESOURCE(IDD_DIALOG4),hwnd,BrushDlgProc);
//				ShowWindow(hModelessDlg,SW_SHOW);//SW_SHOW는 default로 뜨워준다.
//			}
//			else
//			{
//				SetFocus(hModelessDlg); //이미 윈도우가 띄워져있으면 윈도우에 포커스를 주게하는 메서드
//			}
//			break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRect(hdc , rtDraw , shapeType , colorType , bkcolorType);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_BUTTON1:
//			{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//			break;
//		case IDC_EDIT1:
//			switch(HIWORD(wParam))
//			{
//			case EN_CHANGE:
//				{
//					TCHAR buf[200];
//					GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//					SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//				}
//				break;
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		CheckRadioButton(hDlg,IDC_RADIO1,IDC_RADIO3,shapeType+IDC_RADIO1);
//		CheckRadioButton(hDlg,IDC_RADIO4,IDC_RADIO6,colorType+IDC_RADIO4);
//		CheckRadioButton(hDlg,IDC_RADIO7,IDC_RADIO9,bkcolorType+IDC_RADIO7);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_RADIO1: shapeType = 0;
//			break;
//		case IDC_RADIO2: shapeType = 1;
//			break;
//		case IDC_RADIO3: shapeType = 2;
//			break;
//		case IDC_RADIO4: colorType = 0;
//			break;
//		case IDC_RADIO5: colorType = 1;
//			break;
//		case IDC_RADIO6: colorType = 2;
//			break;
//		case IDC_RADIO7: bkcolorType = 0;
//			break;
//		case IDC_RADIO8: bkcolorType = 1;
//			break;
//		case IDC_RADIO9: bkcolorType = 2;
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//void UpdateList(HWND hDlg,vector<RECT>&rtList)
//{
//	SendDlgItemMessage(hDlg,IDC_LIST1,LB_RESETCONTENT,0,0); //리스트를 비우는 역할
//	for(unsigned i=0;i<rtList.size();i++)
//	{
//		const RECT& rt = rtList[i];
//		TCHAR buf[200];
//		wsprintf(buf,"(%d,%d - %d,%d)",rt.left,rt.top,rt.right,rt.bottom);
//		//SendMessage(GetDlgItem(hDlg,IDC_LIST1),LB_ADDSTRING,0,(LPARAM)buf);//문자열의 시작주소를 올려준다.
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_ADDSTRING,0,(LPARAM)buf);
//	}
//	int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCOUNT,0,0);
//	if(sel>0)
//	{
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)(sel-1),0);
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)-1,0);
//	}
//}
//void UpdateEdit(HWND hDlg,const RECT & rt)
//{
//	SetDlgItemInt(hDlg,IDC_EDIT1,rt.left,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT2,rt.top,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT3,rt.right,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT4,rt.bottom,TRUE);
//}
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	static vector<RECT> rtList;
//
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		SetRect(&rtDlg,100,100,200,200);
//		UpdateEdit(hDlg,rtDlg);
//		rtList.clear();
//		UpdateList(hDlg,rtList);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_LIST1:
//			switch(HIWORD(wParam))
//			{
//			case LBN_SELCHANGE:
//				{
//					int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCURSEL,0,0); //LB_GETCURSEL ==> 현재 셀번호를 얻어와라
//					if(sel >= 0) //개수가 아니므로 가능
//					{
//						rtDlg = rtList[sel];
//						UpdateEdit(hDlg,rtDlg);
//					}
//				}
//				break;
//			}
//			break;
//		case IDC_BUTTON1:
//			{
//				rtDlg.left = GetDlgItemInt(hDlg,IDC_EDIT1,NULL,TRUE);
//				rtDlg.top = GetDlgItemInt(hDlg,IDC_EDIT2,NULL,TRUE);
//				rtDlg.right = GetDlgItemInt(hDlg,IDC_EDIT3,NULL,TRUE);
//				rtDlg.bottom = GetDlgItemInt(hDlg,IDC_EDIT4,NULL,TRUE);
//				rtList.push_back(rtDlg);
//				UpdateList(hDlg,rtList);  //원래 이렇게 안한다.
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//void UpdateEdit(HWND hDlg,int nR,int nG, int nB)
//{
//	SetDlgItemInt(hDlg,IDC_EDIT1,nR,TRUE); //범위 설정
//	SetDlgItemInt(hDlg,IDC_EDIT2,nG,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT3,nB,TRUE);
//}
//void UpdateScroll(HWND hDlg,int nR,int nG,int nB) //scroll bar와 같이 범위를 가지는 컨트롤들은 범위를 설정해줘야 한다.
//{
//	SetScrollPos(GetDlgItem(hDlg,IDC_SCROLLBAR1),SB_CTL,nR,TRUE);
//	SetScrollPos(GetDlgItem(hDlg,IDC_SCROLLBAR2),SB_CTL,nG,TRUE);
//	SetScrollPos(GetDlgItem(hDlg,IDC_SCROLLBAR3),SB_CTL,nB,TRUE);
//}
//BOOL CALLBACK BrushDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)//modeless다이얼로그라서 COMMAND가 필요 없다.
//	{
//	case WM_INITDIALOG:
//		SetScrollRange(GetDlgItem(hDlg,IDC_SCROLLBAR1),SB_CTL,0,255, TRUE); //스크롤바에는 두가지 종류가있다. 메인윈도위와 컨트롤에 달린 스크롤바
//		SetScrollRange(GetDlgItem(hDlg,IDC_SCROLLBAR2),SB_CTL,0,255, TRUE); //스크롤바에는 두가지 종류가있다. 메인윈도위와 컨트롤에 달린 스크롤바
//		SetScrollRange(GetDlgItem(hDlg,IDC_SCROLLBAR3),SB_CTL,0,255, TRUE); //스크롤바에는 두가지 종류가있다. 메인윈도위와 컨트롤에 달린 스크롤바
//
//		UpdateEdit(hDlg,nR,nG,nB);
//		UpdateScroll(hDlg,nR,nG,nB);
//		break;
//	case WM_HSCROLL:
//		switch(wParam)
//		{
//			//일반적으로 5가지의 메세지를 처리하게된다.
//		case SB_LINELEFT:
//			nR =max(0,nR-1);
//			break;
//		case SB_LINERIGHT:
//			nR =min(255,nR+1);
//			break;
//		case SB_PAGELEFT:
//			nR = max(0,nR-10);
//			break;
//		case SB_PAGERIGHT:
//			nR = min(255,nR+10);
//			break;
//		case SB_THUMBTRACK:
//			nR = HIWORD(wParam);
//			break;
//		}
//		UpdateEdit(hDlg,nR,nG,nB);
//		UpdateScroll(hDlg,nR,nG,nB);
//		break;
//	case WM_CLOSE:
//		DestroyWindow(hModelessDlg);
//		hModelessDlg = NULL;
//		break;
//	}
//	return FALSE;
//}
//
//
////modal,modaless 다이얼로그 - 바로 적용되게 하려면 modaless로 띄우는게 맞다.
//#include <windows.h>
//#include<vector>
//#include "resource.h"
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//BOOL CALLBACK BrushDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hInst;
//HWND hModelessDlg;
//int shapeType;
//int colorType;
//int bkcolorType;
//UINT nR,nG,nB;
//
//RECT rtDlg = {100,100,200,200};
//HWND hMainWnd;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
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
//	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hMainWnd = hwnd = CreateWindow("Window Class Name",
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
//COLORREF SelectColor(int colorType)
//{
//	switch(colorType)
//	{
//	case 0:
//		return RGB(0xff,0,0);
//	case 1:
//		return RGB(0,0,0xff);
//	case 2:
//		return RGB(0,0xff,0);
//	default:
//		return RGB(0,0,0);
//	}
//}
//void DrawRowRect(HDC hdc, const RECT&rt ,int shapeType)
//{
//	/*RECT rt;
//	GetClientRect(hMainWnd,&rt);*/
//
//	switch(shapeType)
//	{
//	case 0:
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 1:
//		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		break;
//	case 2:
//		MoveToEx(hdc,rt.left,rt.top,NULL);
//		LineTo(hdc,rt.right,rt.bottom);
//		break;
//	}
//}
//void DrawRect(HDC hdc, const RECT&rt ,int shapeType,int colorType,int bkcolorType)
//{
//	HPEN hNewPen = CreatePen(PS_SOLID,2,SelectColor(colorType));
//	HPEN hOldPen = (HPEN)SelectObject(hdc,hNewPen);
//	HBRUSH hNewBrush = CreateSolidBrush(SelectColor(bkcolorType));
//	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);
//
//	DrawRowRect(hdc , rt , shapeType);
//
//	SelectObject(hdc,hOldBrush);
//	SelectObject(hdc,hOldPen);
//	DeleteObject(hNewBrush);
//	DeleteObject(hNewPen);
//
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rtDraw;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break; 
//	case WM_SIZE:
//		GetClientRect(hwnd,&rtDraw);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_MODAL:
//			{
//				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
//			}
//			break;
//		case ID_SHAPE:
//
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG2),hwnd,ShapeDlgProc))
//				InvalidateRect(hwnd,NULL,TRUE);
//			break;
//		case ID_CHANGERECT:
//			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG3),hwnd,ChangeDlgProc))
//			{
//				rtDraw = rtDlg;
//				InvalidateRect(hwnd,NULL,TRUE);
//			}
//			break;
//		case ID_BRUSHCHANGE:
//			//CreateWindow()와 같음
//			if(!IsWindow(hModelessDlg))//hModelessDlg==NULL
//			{
//				hModelessDlg = CreateDialog(g_hInst,MAKEINTRESOURCE(IDD_DIALOG4),hwnd,BrushDlgProc);
//				ShowWindow(hModelessDlg,SW_SHOW);//SW_SHOW는 default로 뜨워준다.
//			}
//			else
//			{
//				SetFocus(hModelessDlg); //이미 윈도우가 띄워져있으면 윈도우에 포커스를 주게하는 메서드
//			}
//			break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRect(hdc , rtDraw , shapeType , colorType , bkcolorType);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_BUTTON1:
//			{
//				TCHAR buf[200];
//				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//			}
//			break;
//		case IDC_EDIT1:
//			switch(HIWORD(wParam))
//			{
//			case EN_CHANGE:
//				{
//					TCHAR buf[200];
//					GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
//					SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
//				}
//				break;
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//
//
//BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		CheckRadioButton(hDlg,IDC_RADIO1,IDC_RADIO3,shapeType+IDC_RADIO1);
//		CheckRadioButton(hDlg,IDC_RADIO4,IDC_RADIO6,colorType+IDC_RADIO4);
//		CheckRadioButton(hDlg,IDC_RADIO7,IDC_RADIO9,bkcolorType+IDC_RADIO7);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_RADIO1: shapeType = 0;
//			break;
//		case IDC_RADIO2: shapeType = 1;
//			break;
//		case IDC_RADIO3: shapeType = 2;
//			break;
//		case IDC_RADIO4: colorType = 0;
//			break;
//		case IDC_RADIO5: colorType = 1;
//			break;
//		case IDC_RADIO6: colorType = 2;
//			break;
//		case IDC_RADIO7: bkcolorType = 0;
//			break;
//		case IDC_RADIO8: bkcolorType = 1;
//			break;
//		case IDC_RADIO9: bkcolorType = 2;
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//void UpdateList(HWND hDlg,vector<RECT>&rtList)
//{
//	SendDlgItemMessage(hDlg,IDC_LIST1,LB_RESETCONTENT,0,0); //리스트를 비우는 역할
//	for(unsigned i=0;i<rtList.size();i++)
//	{
//		const RECT& rt = rtList[i];
//		TCHAR buf[200];
//		wsprintf(buf,"(%d,%d - %d,%d)",rt.left,rt.top,rt.right,rt.bottom);
//		//SendMessage(GetDlgItem(hDlg,IDC_LIST1),LB_ADDSTRING,0,(LPARAM)buf);//문자열의 시작주소를 올려준다.
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_ADDSTRING,0,(LPARAM)buf);
//	}
//	int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCOUNT,0,0);
//	if(sel>0)
//	{
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)(sel-1),0);
//		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)-1,0);
//	}
//}
//void UpdateEdit(HWND hDlg,const RECT & rt)
//{
//	SetDlgItemInt(hDlg,IDC_EDIT1,rt.left,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT2,rt.top,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT3,rt.right,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT4,rt.bottom,TRUE);
//}
//BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	static vector<RECT> rtList;
//
//	switch(iMsg)
//	{
//	case WM_INITDIALOG:
//		SetRect(&rtDlg,100,100,200,200);
//		UpdateEdit(hDlg,rtDlg);
//		rtList.clear();
//		UpdateList(hDlg,rtList);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_LIST1:
//			switch(HIWORD(wParam))
//			{
//			case LBN_SELCHANGE:
//				{
//					int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCURSEL,0,0); //LB_GETCURSEL ==> 현재 셀번호를 얻어와라
//					if(sel >= 0) //개수가 아니므로 가능
//					{
//						rtDlg = rtList[sel];
//						UpdateEdit(hDlg,rtDlg);
//					}
//				}
//				break;
//			}
//			break;
//		case IDC_BUTTON1:
//			{
//				rtDlg.left = GetDlgItemInt(hDlg,IDC_EDIT1,NULL,TRUE);
//				rtDlg.top = GetDlgItemInt(hDlg,IDC_EDIT2,NULL,TRUE);
//				rtDlg.right = GetDlgItemInt(hDlg,IDC_EDIT3,NULL,TRUE);
//				rtDlg.bottom = GetDlgItemInt(hDlg,IDC_EDIT4,NULL,TRUE);
//				rtList.push_back(rtDlg);
//				UpdateList(hDlg,rtList);  //원래 이렇게 안한다.
//			}
//			break;
//		case IDOK:
//			EndDialog(hDlg,IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg,IDCANCEL);
//			break;
//		}
//		break;
//	}
//	return FALSE;
//}
//void UpdateEdit(HWND hDlg,int nR,int nG, int nB)
//{
//	SetDlgItemInt(hDlg,IDC_EDIT1,nR,TRUE); //범위 설정
//	SetDlgItemInt(hDlg,IDC_EDIT2,nG,TRUE);
//	SetDlgItemInt(hDlg,IDC_EDIT5,nB,TRUE);
//}
//void UpdateScroll(HWND hDlg,int nR,int nG,int nB) //scroll bar와 같이 범위를 가지는 컨트롤들은 범위를 설정해줘야 한다.
//{
//	SetScrollPos(GetDlgItem(hDlg,IDC_SCROLLBAR1),SB_CTL,nR,TRUE);
//	SetScrollPos(GetDlgItem(hDlg,IDC_SCROLLBAR2),SB_CTL,nG,TRUE);
//	SetScrollPos(GetDlgItem(hDlg,IDC_SCROLLBAR3),SB_CTL,nB,TRUE);
//}
//BOOL CALLBACK BrushDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	UINT nPos;
//	switch(iMsg)//modeless다이얼로그라서 COMMAND가 필요 없다.
//	{
//	case WM_INITDIALOG:
//		SetScrollRange(GetDlgItem(hDlg,IDC_SCROLLBAR1),SB_CTL,0,255, TRUE); //스크롤바에는 두가지 종류가있다. 메인윈도위와 컨트롤에 달린 스크롤바
//		SetScrollRange(GetDlgItem(hDlg,IDC_SCROLLBAR2),SB_CTL,0,255, TRUE); //스크롤바에는 두가지 종류가있다. 메인윈도위와 컨트롤에 달린 스크롤바
//		SetScrollRange(GetDlgItem(hDlg,IDC_SCROLLBAR3),SB_CTL,0,255, TRUE); //스크롤바에는 두가지 종류가있다. 메인윈도위와 컨트롤에 달린 스크롤바
//
//		UpdateEdit(hDlg,nR,nG,nB);
//		UpdateScroll(hDlg,nR,nG,nB);
//		break;
//	case WM_HSCROLL:
//		if((HWND)lParam == GetDlgItem(hDlg,IDC_SCROLLBAR1))
//			nPos = nR;
//		else if((HWND)lParam == GetDlgItem(hDlg,IDC_SCROLLBAR2))
//			nPos = nG;
//		else if((HWND)lParam == GetDlgItem(hDlg,IDC_SCROLLBAR3))
//			nPos = nB;
//		switch(wParam)
//		{
//			//일반적으로 5가지의 메세지를 처리하게된다.
//		case SB_LINELEFT:
//			nPos =max(0,nPos-1);
//			break;
//		case SB_LINERIGHT:
//			nPos =min(255,nPos+1);
//			break;
//		case SB_PAGELEFT:
//			nPos = max(0,nPos-10);
//			break;
//		case SB_PAGERIGHT:
//			nPos = min(255,nPos+10);
//			break;
//		case SB_THUMBTRACK:
//			nPos = HIWORD(wParam);
//			break;
//		}
//		if((HWND)lParam == GetDlgItem(hDlg,IDC_SCROLLBAR1))
//			nR = nPos;
//		else if((HWND)lParam == GetDlgItem(hDlg,IDC_SCROLLBAR2))
//			nG = nPos;
//		else if((HWND)lParam == GetDlgItem(hDlg,IDC_SCROLLBAR3))
//			nB = nPos;
//
//
//		UpdateEdit(hDlg,nR,nG,nB);
//		UpdateScroll(hDlg,nR,nG,nB);
//		break;
//	case WM_CLOSE:
//		DestroyWindow(hModelessDlg);
//		hModelessDlg = NULL;
//		break;
//	}
//	return FALSE;
//}



//modal,modaless 다이얼로그 - 바로 적용되게 하려면 modaless로 띄우는게 맞다.
#include <windows.h>
#include<vector>
#include "resource.h"
using namespace std;
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
BOOL CALLBACK BrushDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
HINSTANCE g_hInst;
HWND hModelessDlg;
int shapeType;
int colorType;
UINT nR,nG,nB;

RECT rtDlg = {100,100,200,200};
HWND hMainWnd;
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
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);		
	WndClass.lpszClassName = "Window Class Name";	
	RegisterClass(&WndClass);	
	hMainWnd = hwnd = CreateWindow("Window Class Name",
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
COLORREF SelectColor(int colorType)
{
	switch(colorType)
	{
	case 0:
		return RGB(0xff,0,0);
	case 1:
		return RGB(0,0,0xff);
	case 2:
		return RGB(0,0xff,0);
	default:
		return RGB(0,0,0);
	}
}
void DrawRowRect(HDC hdc, const RECT&rt ,int shapeType)
{
	/*RECT rt;
	GetClientRect(hMainWnd,&rt);*/

	switch(shapeType)
	{
	case 0:
		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
		break;
	case 1:
		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
		break;
	case 2:
		MoveToEx(hdc,rt.left,rt.top,NULL);
		LineTo(hdc,rt.right,rt.bottom);
		break;
	}
}
void DrawRect(HDC hdc, const RECT&rt ,int shapeType,int colorType, COLORREF colorBK)
{
	HPEN hNewPen = CreatePen(PS_SOLID,2,SelectColor(colorType));
	HPEN hOldPen = (HPEN)SelectObject(hdc,hNewPen);
	HBRUSH hNewBrush = CreateSolidBrush(colorBK);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);

	DrawRowRect(hdc , rt , shapeType);

	SelectObject(hdc,hOldBrush);
	SelectObject(hdc,hOldPen);
	DeleteObject(hNewBrush);
	DeleteObject(hNewPen);

}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam) 
{

	HDC         hdc;
	PAINTSTRUCT ps; 
	static RECT rtDraw;

	switch (iMsg)
	{
	case WM_CREATE:
		break; 
	case WM_SIZE:
		GetClientRect(hwnd,&rtDraw);
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case ID_MODAL:
			{
				DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
			}
			break;
		case ID_SHAPE:

			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG2),hwnd,ShapeDlgProc))
				InvalidateRect(hwnd,NULL,TRUE);
			break;
		case ID_CHANGERECT:
			if(IDOK==DialogBox(g_hInst,MAKEINTRESOURCE(IDD_DIALOG3),hwnd,ChangeDlgProc))
			{
				rtDraw = rtDlg;
				InvalidateRect(hwnd,NULL,TRUE);
			}
			break;
		case ID_BRUSHCHANGE:
			//CreateWindow()와 같음
			if(!IsWindow(hModelessDlg))//hModelessDlg==NULL
			{
				hModelessDlg = CreateDialog(g_hInst,MAKEINTRESOURCE(IDD_DIALOG4),hwnd,BrushDlgProc);
				ShowWindow(hModelessDlg,SW_SHOW);//SW_SHOW는 default로 뜨워준다.
			}
			else
			{
				SetFocus(hModelessDlg); //이미 윈도우가 띄워져있으면 윈도우에 포커스를 주게하는 메서드
			}
			break;
		}
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		DrawRect(hdc , rtDraw , shapeType , colorType , RGB(nR,nG,nB));
		// 이곳에서 출력이 이루어짐
		EndPaint(hwnd, &ps);
		break; 
	case WM_DESTROY:
		PostQuitMessage(0);
		break; 
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}


BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
{
	switch(iMsg)
	{
	case WM_INITDIALOG:
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDC_BUTTON1:
			{
				TCHAR buf[200];
				GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
				SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
			}
			break;
		case IDC_EDIT1:
			switch(HIWORD(wParam))
			{
			case EN_CHANGE:
				{
					TCHAR buf[200];
					GetWindowText(GetDlgItem(hDlg,IDC_EDIT1),buf,200);
					SetWindowText(GetDlgItem(hDlg,IDC_EDIT2),buf);
				}
				break;
			}
			break;
		case IDOK:
			EndDialog(hDlg,IDOK);
			break;
		case IDCANCEL:
			EndDialog(hDlg,IDCANCEL);
			break;
		}
		break;
	}
	return FALSE;
}


BOOL CALLBACK ShapeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
{
	switch(iMsg)
	{
	case WM_INITDIALOG:
		CheckRadioButton(hDlg,IDC_RADIO1,IDC_RADIO3,shapeType+IDC_RADIO1);
		CheckRadioButton(hDlg,IDC_RADIO4,IDC_RADIO6,colorType+IDC_RADIO4);
		CheckRadioButton(hDlg,IDC_RADIO7,IDC_RADIO9,IDC_RADIO7);
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDC_RADIO1: shapeType = 0;
			break;
		case IDC_RADIO2: shapeType = 1;
			break;
		case IDC_RADIO3: shapeType = 2;
			break;
		case IDC_RADIO4: colorType = 0;
			break;
		case IDC_RADIO5: colorType = 1;
			break;
		case IDC_RADIO6: colorType = 2;
			break;
		case IDC_RADIO7: nR = 0xff;nG=0;nB=0;
			break;
		case IDC_RADIO8: nR = 0;nG=0;nB=0xff;
			break;
		case IDC_RADIO9: nR = 0;nG=0xff;nB=0;
			break;
		case IDOK:
			EndDialog(hDlg,IDOK);
			break;
		case IDCANCEL:
			EndDialog(hDlg,IDCANCEL);
			break;
		}
		break;
	}
	return FALSE;
}
void UpdateList(HWND hDlg,vector<RECT>&rtList)
{
	SendDlgItemMessage(hDlg,IDC_LIST1,LB_RESETCONTENT,0,0); //리스트를 비우는 역할
	for(unsigned i=0;i<rtList.size();i++)
	{
		const RECT& rt = rtList[i];
		TCHAR buf[200];
		wsprintf(buf,"(%d,%d - %d,%d)",rt.left,rt.top,rt.right,rt.bottom);
		//SendMessage(GetDlgItem(hDlg,IDC_LIST1),LB_ADDSTRING,0,(LPARAM)buf);//문자열의 시작주소를 올려준다.
		SendDlgItemMessage(hDlg,IDC_LIST1,LB_ADDSTRING,0,(LPARAM)buf);
	}
	int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCOUNT,0,0);
	if(sel>0)
	{
		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)(sel-1),0);
		SendDlgItemMessage(hDlg,IDC_LIST1,LB_SETCURSEL,(WPARAM)-1,0);
	}
}
void UpdateEdit(HWND hDlg,const RECT & rt)
{
	SetDlgItemInt(hDlg,IDC_EDIT1,rt.left,TRUE);
	SetDlgItemInt(hDlg,IDC_EDIT2,rt.top,TRUE);
	SetDlgItemInt(hDlg,IDC_EDIT3,rt.right,TRUE);
	SetDlgItemInt(hDlg,IDC_EDIT4,rt.bottom,TRUE);
}
BOOL CALLBACK ChangeDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
{
	static vector<RECT> rtList;

	switch(iMsg)
	{
	case WM_INITDIALOG:
		SetRect(&rtDlg,100,100,200,200);
		UpdateEdit(hDlg,rtDlg);
		rtList.clear();
		UpdateList(hDlg,rtList);
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDC_LIST1:
			switch(HIWORD(wParam))
			{
			case LBN_SELCHANGE:
				{
					int sel = SendDlgItemMessage(hDlg,IDC_LIST1,LB_GETCURSEL,0,0); //LB_GETCURSEL ==> 현재 셀번호를 얻어와라
					if(sel >= 0) //개수가 아니므로 가능
					{
						rtDlg = rtList[sel];
						UpdateEdit(hDlg,rtDlg);
					}
				}
				break;
			}
			break;
		case IDC_BUTTON1:
			{
				rtDlg.left = GetDlgItemInt(hDlg,IDC_EDIT1,NULL,TRUE);
				rtDlg.top = GetDlgItemInt(hDlg,IDC_EDIT2,NULL,TRUE);
				rtDlg.right = GetDlgItemInt(hDlg,IDC_EDIT3,NULL,TRUE);
				rtDlg.bottom = GetDlgItemInt(hDlg,IDC_EDIT4,NULL,TRUE);
				rtList.push_back(rtDlg);
				UpdateList(hDlg,rtList);  //원래 이렇게 안한다.
			}
			break;
		case IDOK:
			EndDialog(hDlg,IDOK);
			break;
		case IDCANCEL:
			EndDialog(hDlg,IDCANCEL);
			break;
		}
		break;
	}
	return FALSE;
}
void UpdateEdit(HWND hDlg,int nR,int nG, int nB)
{
	SetDlgItemInt(hDlg,IDC_EDIT1,nR,TRUE); //범위 설정
	SetDlgItemInt(hDlg,IDC_EDIT2,nG,TRUE);
	SetDlgItemInt(hDlg,IDC_EDIT5,nB,TRUE);
}
void UpdateScroll(HWND hDlg,int nR,int nG,int nB) //scroll bar와 같이 범위를 가지는 컨트롤들은 범위를 설정해줘야 한다.
{
	SetScrollPos(GetDlgItem(hDlg,IDC_SCROLLBAR1),SB_CTL,nR,TRUE);
	SetScrollPos(GetDlgItem(hDlg,IDC_SCROLLBAR2),SB_CTL,nG,TRUE);
	SetScrollPos(GetDlgItem(hDlg,IDC_SCROLLBAR3),SB_CTL,nB,TRUE);
}
BOOL CALLBACK BrushDlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
{
	UINT nPos;
	switch(iMsg)//modeless다이얼로그라서 COMMAND가 필요 없다.
	{
	case WM_INITDIALOG:
		SetScrollRange(GetDlgItem(hDlg,IDC_SCROLLBAR1),SB_CTL,0,255, TRUE); //스크롤바에는 두가지 종류가있다. 메인윈도위와 컨트롤에 달린 스크롤바
		SetScrollRange(GetDlgItem(hDlg,IDC_SCROLLBAR2),SB_CTL,0,255, TRUE); //스크롤바에는 두가지 종류가있다. 메인윈도위와 컨트롤에 달린 스크롤바
		SetScrollRange(GetDlgItem(hDlg,IDC_SCROLLBAR3),SB_CTL,0,255, TRUE); //스크롤바에는 두가지 종류가있다. 메인윈도위와 컨트롤에 달린 스크롤바

		UpdateEdit(hDlg,nR,nG,nB);
		UpdateScroll(hDlg,nR,nG,nB);
		InvalidateRect(hMainWnd,NULL,TRUE);
		break;
	case WM_HSCROLL:
		if((HWND)lParam == GetDlgItem(hDlg,IDC_SCROLLBAR1))
			nPos = nR;
		else if((HWND)lParam == GetDlgItem(hDlg,IDC_SCROLLBAR2))
			nPos = nG;
		else if((HWND)lParam == GetDlgItem(hDlg,IDC_SCROLLBAR3))
			nPos = nB;
		switch(wParam)
		{
			//일반적으로 5가지의 메세지를 처리하게된다.
		case SB_LINELEFT:
			nPos =max(0,nPos-1);
			break;
		case SB_LINERIGHT:
			nPos =min(255,nPos+1);
			break;
		case SB_PAGELEFT:
			nPos = max(0,nPos-10);
			break;
		case SB_PAGERIGHT:
			nPos = min(255,nPos+10);
			break;
		case SB_THUMBTRACK:
			nPos = HIWORD(wParam);
			break;
		}
		if((HWND)lParam == GetDlgItem(hDlg,IDC_SCROLLBAR1))
			nR = nPos;
		else if((HWND)lParam == GetDlgItem(hDlg,IDC_SCROLLBAR2))
			nG = nPos;
		else if((HWND)lParam == GetDlgItem(hDlg,IDC_SCROLLBAR3))
			nB = nPos;


		UpdateEdit(hDlg,nR,nG,nB);
		UpdateScroll(hDlg,nR,nG,nB);
		InvalidateRect(hMainWnd,NULL,TRUE);
		break;
	case WM_CLOSE:
		DestroyWindow(hModelessDlg);
		hModelessDlg = NULL;
		break;
	}
	return FALSE;
}
//월욜부터는 시스템ㅍ프로그래밍ㄱㄱ