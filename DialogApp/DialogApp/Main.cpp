#include <windows.h>
#include <vector>
#include "resource.h"
using namespace std;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
						 WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);

HINSTANCE g_hInst;
int dx=100 , dy=100;

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
void DrawRectList(HDC hdc, const vector<RECT>& rtList)
{
	for(unsigned i = 0 ; i < rtList.size(); ++i)
	{
		const RECT& rt = rtList[i];
		Rectangle(hdc, rt.left,rt.top,rt.right,rt.bottom);
	}
}
void MoveRectList(vector<RECT>& rtList, int dx, int dy)
{
	for(unsigned i = 0 ; i < rtList.size(); ++i)
	{
		RECT& rt = rtList[i];
		rt.left += dx;
		rt.right += dx;
		rt.top += dy;
		rt.bottom += dy;
	}
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
                         WPARAM wParam, LPARAM lParam) 
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	static RECT rt;
	static vector<RECT> rtList;
	
	switch (iMsg)
	{
    case WM_CREATE:
		break; 
	case WM_LBUTTONDOWN:
		rt.left = LOWORD(lParam);
		rt.top = HIWORD(lParam);
		break;
	case WM_LBUTTONUP:
		rt.right = LOWORD(lParam);
		rt.bottom = HIWORD(lParam);
		rtList.push_back(rt);
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case ID_RECTMOVE:
			if(IDOK==DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, DlgProc) )
			{
				MoveRectList(rtList, dx, dy);
				InvalidateRect(hwnd, NULL, TRUE);
			}
			break;

		}
		break;
    case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		DrawRectList(hdc, rtList);
		EndPaint(hwnd, &ps);
		break; 
    case WM_DESTROY:
		PostQuitMessage(0);
		break; 
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch(iMsg)
	{
	case WM_INITDIALOG:
		SetDlgItemInt(hDlg, IDC_EDITX, dx, TRUE);
		SetDlgItemInt(hDlg, IDC_EDITY, dy, TRUE);
		break;
	case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
			case IDOK:
				dx = GetDlgItemInt(hDlg, IDC_EDITX, NULL, TRUE);
				dy = GetDlgItemInt(hDlg, IDC_EDITY, NULL, TRUE);

				EndDialog(hDlg, IDOK);
				break;
			case IDCANCEL:
				EndDialog(hDlg, IDCANCEL);
				break;
			}
		}
		break;
	}
	return FALSE;
}

//#include <windows.h>
//#include <vector>
//#include "resource.h"
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
//
//HINSTANCE g_hInst;
//int dx , dy;
//
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
//void DrawRectList(HDC hdc, const vector<RECT>& rtList)
//{
//	for(unsigned i = 0 ; i < rtList.size(); ++i)
//	{
//		const RECT& rt = rtList[i];
//		Rectangle(hdc, rt.left,rt.top,rt.right,rt.bottom);
//	}
//}
//void MoveRectList(vector<RECT>& rtList, int dx, int dy)
//{
//	for(unsigned i = 0 ; i < rtList.size(); ++i)
//	{
//		RECT& rt = rtList[i];
//		rt.left += dx;
//		rt.right += dx;
//		rt.top += dy;
//		rt.bottom += dy;
//	}
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rt;
//	static vector<RECT> rtList;
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
//		rtList.push_back(rt);
//		InvalidateRect(hwnd, NULL, TRUE);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_RECTMOVE:
//			if(IDOK==DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, DlgProc) )
//			{
//				MoveRectList(rtList, dx, dy);
//				InvalidateRect(hwnd, NULL, TRUE);
//			}
//			break;
//
//		}
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRectList(hdc, rtList);
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_COMMAND:
//		{
//			switch(LOWORD(wParam))
//			{
//			case IDOK:
//				dx = GetDlgItemInt(hDlg, IDC_EDITX, NULL, TRUE);
//				dy = GetDlgItemInt(hDlg, IDC_EDITY, NULL, TRUE);
//
//				EndDialog(hDlg, IDOK);
//				break;
//			case IDCANCEL:
//				EndDialog(hDlg, IDCANCEL);
//				break;
//			}
//		}
//		break;
//	}
//	return FALSE;
//}

//#include <windows.h>
//#include <vector>
//#include "resource.h"
//using namespace std;
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//						 WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
//
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
//void DrawRectList(HDC hdc, const vector<RECT>& rtList)
//{
//	for(unsigned i = 0 ; i < rtList.size(); ++i)
//	{
//		const RECT& rt = rtList[i];
//		Rectangle(hdc, rt.left,rt.top,rt.right,rt.bottom);
//	}
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rt;
//	static vector<RECT> rtList;
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
//		rtList.push_back(rt);
//		InvalidateRect(hwnd, NULL, TRUE);
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_RECTMOVE:
//			if(IDOK==DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, DlgProc) )
//			{
//				SetWindowText(hwnd, "IDOK");
//			}
//			break;
//
//		}
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRectList(hdc, rtList);
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch(iMsg)
//	{
//	case WM_COMMAND:
//		{
//			switch(LOWORD(wParam))
//			{
//			case IDOK:
//				EndDialog(hDlg, IDOK);
//				break;
//			case IDCANCEL:
//				EndDialog(hDlg, IDCANCEL);
//				break;
//			}
//		}
//		break;
//	}
//	return FALSE;
//}
