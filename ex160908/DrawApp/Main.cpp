#include <windows.h>
#include <list>
#include "resource.h"
using namespace std;

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
void MoveRectangle(list<RECT>& rtList, int dx, int dy)
{
	for(list<RECT>::iterator iter= rtList.begin(); iter != rtList.end();
		++iter)
	{
		iter->left += dx;
		iter->right += dx;
		iter->top += dy;
		iter->bottom += dy;
	}
}

void DrawRectList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
{
	HPEN newPen = CreatePen(PS_SOLID, 1, penColor);
	HPEN oldPen = (HPEN)SelectObject(hdc, newPen);
	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
	{
		const RECT& rt = *iter;
		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
	}
	SelectObject(hdc, oldPen);
	DeleteObject(newPen);
}
void DrawEllipseList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
{
	HPEN newPen = CreatePen(PS_SOLID, 1, penColor);
	HPEN oldPen = (HPEN)SelectObject(hdc, newPen);
	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
	{
		const RECT& rt = *iter;
		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
	}
	SelectObject(hdc, oldPen);
	DeleteObject(newPen);
}
void DrawLineList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
{
	HPEN newPen = CreatePen(PS_SOLID, 1, penColor);
	HPEN oldPen = (HPEN)SelectObject(hdc, newPen);
	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
	{
		const RECT& rt = *iter;
		MoveToEx(hdc, rt.left,rt.top, NULL);
		LineTo(hdc, rt.right,rt.bottom);
	}
	SelectObject(hdc, oldPen);
	DeleteObject(newPen);
}
void SetTextTitle(HWND hwnd, LPARAM lParam)
{
	TCHAR buf[100];
	wsprintf(buf,"(%d,%d)", LOWORD(lParam), HIWORD(lParam));
	SetWindowText(hwnd, buf);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
                         WPARAM wParam, LPARAM lParam) 
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	static RECT rt;
	static list<RECT> rtList;
	static bool bRClick;
	static POINT startPoint, endPoint;
	static COLORREF color=RGB(0,0,0);
	static int shapeType;
	
	switch (iMsg)
	{
    case WM_CREATE:
		break; 
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case ID_RECT:
			shapeType = 0;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case ID_ELLIPSE:
			shapeType = 1;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		case ID_LINE:
			shapeType = 2;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		break;
	case WM_RBUTTONDOWN:
		bRClick = true;		
		startPoint.x = (short)LOWORD(lParam);
		startPoint.y = (short)HIWORD(lParam);
		break;
	case WM_MOUSEMOVE:		
		SetTextTitle(hwnd, lParam);
		if(bRClick)
		{			
			color = RGB(120,120,120);

			endPoint.x = (short)LOWORD(lParam);
			endPoint.y = (short)HIWORD(lParam);

			MoveRectangle(rtList, endPoint.x-startPoint.x,
				endPoint.y-startPoint.y);
			InvalidateRect(hwnd, NULL, TRUE);

			startPoint = endPoint;
		}
		break;
	case WM_RBUTTONUP:
		bRClick = false;
		color = RGB(0,0,0);

		endPoint.x = (short)LOWORD(lParam);
		endPoint.y = (short)HIWORD(lParam);
		MoveRectangle(rtList, endPoint.x-startPoint.x,
				endPoint.y-startPoint.y);
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	case WM_LBUTTONDOWN:
		SetCapture(hwnd);

		rt.left = (short)LOWORD(lParam);
		rt.top = (short)HIWORD(lParam);				
		break;
	case WM_LBUTTONUP:
		ReleaseCapture();

		rt.right = (short)LOWORD(lParam);
		rt.bottom = (short)HIWORD(lParam);
		rtList.push_back( rt );

		InvalidateRect(hwnd, NULL, TRUE);
		break;
    case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		switch(shapeType)
		{
		case 0:
			DrawRectList(hdc, rtList, color );			
			break;
		case 1:
			DrawEllipseList(hdc, rtList, color);
			break;
		case 2:
			DrawLineList(hdc, rtList, color);
			break;
		}
		EndPaint(hwnd, &ps);
		break; 
    case WM_DESTROY:
		PostQuitMessage(0);
		break; 
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

//#include <windows.h>
//#include <list>
//#include "resource.h"
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
//void DrawRectList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
//{
//	HPEN newPen = CreatePen(PS_SOLID, 1, penColor);
//	HPEN oldPen = (HPEN)SelectObject(hdc, newPen);
//	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//	{
//		const RECT& rt = *iter;
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//	}
//	SelectObject(hdc, oldPen);
//	DeleteObject(newPen);
//}
//void DrawEllipseList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
//{
//	HPEN newPen = CreatePen(PS_SOLID, 1, penColor);
//	HPEN oldPen = (HPEN)SelectObject(hdc, newPen);
//	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//	{
//		const RECT& rt = *iter;
//		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
//	}
//	SelectObject(hdc, oldPen);
//	DeleteObject(newPen);
//}
//void DrawLineList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
//{
//	HPEN newPen = CreatePen(PS_SOLID, 1, penColor);
//	HPEN oldPen = (HPEN)SelectObject(hdc, newPen);
//	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//	{
//		const RECT& rt = *iter;
//		MoveToEx(hdc, rt.left,rt.top, NULL);
//		LineTo(hdc, rt.right,rt.bottom);
//	}
//	SelectObject(hdc, oldPen);
//	DeleteObject(newPen);
//}
//void SetTextTitle(HWND hwnd, LPARAM lParam)
//{
//	TCHAR buf[100];
//	wsprintf(buf,"(%d,%d)", LOWORD(lParam), HIWORD(lParam));
//	SetWindowText(hwnd, buf);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rt;
//	static list<RECT> rtList;
//	static bool bRClick;
//	static POINT startPoint, endPoint;
//	static COLORREF color=RGB(0,0,0);
//	static int shapeType;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_RECT:
//			shapeType = 0;
//			InvalidateRect(hwnd, NULL, TRUE);
//			break;
//		case ID_ELLIPSE:
//			shapeType = 1;
//			InvalidateRect(hwnd, NULL, TRUE);
//			break;
//		case ID_LINE:
//			shapeType = 2;
//			InvalidateRect(hwnd, NULL, TRUE);
//			break;
//		}
//		break;
//	case WM_RBUTTONDOWN:
//		bRClick = true;		
//		startPoint.x = (short)LOWORD(lParam);
//		startPoint.y = (short)HIWORD(lParam);
//		break;
//	case WM_MOUSEMOVE:		
//		SetTextTitle(hwnd, lParam);
//		if(bRClick)
//		{			
//			color = RGB(120,120,120);
//
//			endPoint.x = (short)LOWORD(lParam);
//			endPoint.y = (short)HIWORD(lParam);
//
//			MoveRectangle(rtList, endPoint.x-startPoint.x,
//				endPoint.y-startPoint.y);
//			InvalidateRect(hwnd, NULL, TRUE);
//
//			startPoint = endPoint;
//		}
//		break;
//	case WM_RBUTTONUP:
//		bRClick = false;
//		color = RGB(0,0,0);
//
//		endPoint.x = (short)LOWORD(lParam);
//		endPoint.y = (short)HIWORD(lParam);
//		MoveRectangle(rtList, endPoint.x-startPoint.x,
//				endPoint.y-startPoint.y);
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
//		InvalidateRect(hwnd, NULL, TRUE);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		switch(shapeType)
//		{
//		case 0:
//			DrawRectList(hdc, rtList, color );			
//			break;
//		case 1:
//			DrawEllipseList(hdc, rtList, color);
//			break;
//		case 2:
//			DrawLineList(hdc, rtList, color);
//			break;
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
//#include "resource.h"
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
//void DrawRectList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
//{
//	HPEN newPen = CreatePen(PS_SOLID, 1, penColor);
//	HPEN oldPen = (HPEN)SelectObject(hdc, newPen);
//	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//	{
//		const RECT& rt = *iter;
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//	}
//	SelectObject(hdc, oldPen);
//	DeleteObject(newPen);
//}
//void DrawEllipseList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
//{
//	HPEN newPen = CreatePen(PS_SOLID, 1, penColor);
//	HPEN oldPen = (HPEN)SelectObject(hdc, newPen);
//	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//	{
//		const RECT& rt = *iter;
//		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
//	}
//	SelectObject(hdc, oldPen);
//	DeleteObject(newPen);
//}
//void DrawLineList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
//{
//	HPEN newPen = CreatePen(PS_SOLID, 1, penColor);
//	HPEN oldPen = (HPEN)SelectObject(hdc, newPen);
//	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//	{
//		const RECT& rt = *iter;
//		MoveToEx(hdc, rt.left,rt.top, NULL);
//		LineTo(hdc, rt.right,rt.bottom);
//	}
//	SelectObject(hdc, oldPen);
//	DeleteObject(newPen);
//}
//void SetTextTitle(HWND hwnd, LPARAM lParam)
//{
//	TCHAR buf[100];
//	wsprintf(buf,"(%d,%d)", LOWORD(lParam), HIWORD(lParam));
//	SetWindowText(hwnd, buf);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rt;
//	static list<RECT> rtList;
//	static bool bRClick;
//	static POINT startPoint, endPoint;
//	static bool bRMove;
//	static int shapeType;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_RECT:
//			shapeType = 0;
//			InvalidateRect(hwnd, NULL, TRUE);
//			break;
//		case ID_ELLIPSE:
//			shapeType = 1;
//			InvalidateRect(hwnd, NULL, TRUE);
//			break;
//		case ID_LINE:
//			shapeType = 2;
//			InvalidateRect(hwnd, NULL, TRUE);
//			break;
//		}
//		break;
//	case WM_RBUTTONDOWN:
//		bRClick = true;		
//		startPoint.x = (short)LOWORD(lParam);
//		startPoint.y = (short)HIWORD(lParam);
//		break;
//	case WM_MOUSEMOVE:		
//		SetTextTitle(hwnd, lParam);
//		if(bRClick)
//		{			
//			bRMove = true;
//
//			endPoint.x = (short)LOWORD(lParam);
//			endPoint.y = (short)HIWORD(lParam);
//
//			MoveRectangle(rtList, endPoint.x-startPoint.x,
//				endPoint.y-startPoint.y);
//			InvalidateRect(hwnd, NULL, TRUE);
//
//			startPoint = endPoint;
//		}
//		break;
//	case WM_RBUTTONUP:
//		bRClick = false;
//		bRMove = false;
//		endPoint.x = (short)LOWORD(lParam);
//		endPoint.y = (short)HIWORD(lParam);
//		MoveRectangle(rtList, endPoint.x-startPoint.x,
//				endPoint.y-startPoint.y);
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
//		InvalidateRect(hwnd, NULL, TRUE);
//		break;
//    case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		switch(shapeType)
//		{
//		case 0:
//			if(bRMove)
//				DrawRectList(hdc, rtList, RGB(128,128,128) );
//			else
//				DrawRectList(hdc, rtList, RGB(0,0,0) );
//			break;
//		case 1:
//			if(bRMove)
//				DrawEllipseList(hdc, rtList, RGB(128,128,128) );
//			else
//				DrawEllipseList(hdc, rtList, RGB(0,0,0) );
//			break;
//		case 2:
//			if(bRMove)
//				DrawLineList(hdc, rtList, RGB(128,128,128) );
//			else
//				DrawLineList(hdc, rtList, RGB(0,0,0) );
//			break;
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
//#include "resource.h"
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
//void DrawRectList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
//{
//	HPEN newPen = CreatePen(PS_SOLID, 1, penColor);
//	HPEN oldPen = (HPEN)SelectObject(hdc, newPen);
//	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//	{
//		const RECT& rt = *iter;
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//	}
//	SelectObject(hdc, oldPen);
//	DeleteObject(newPen);
//}
//void DrawEllipseList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
//{
//	HPEN newPen = CreatePen(PS_SOLID, 1, penColor);
//	HPEN oldPen = (HPEN)SelectObject(hdc, newPen);
//	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//	{
//		const RECT& rt = *iter;
//		Ellipse(hdc,rt.left,rt.top,rt.right,rt.bottom);
//	}
//	SelectObject(hdc, oldPen);
//	DeleteObject(newPen);
//}
//void DrawLineList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
//{
//	HPEN newPen = CreatePen(PS_SOLID, 1, penColor);
//	HPEN oldPen = (HPEN)SelectObject(hdc, newPen);
//	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//	{
//		const RECT& rt = *iter;
//		MoveToEx(hdc, rt.left,rt.top, NULL);
//		LineTo(hdc, rt.right,rt.bottom);
//	}
//	SelectObject(hdc, oldPen);
//	DeleteObject(newPen);
//}
//void SetTextTitle(HWND hwnd, LPARAM lParam)
//{
//	TCHAR buf[100];
//	wsprintf(buf,"(%d,%d)", LOWORD(lParam), HIWORD(lParam));
//	SetWindowText(hwnd, buf);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rt;
//	static list<RECT> rtList;
//	static bool bRClick;
//	static POINT startPoint, endPoint;
//	static bool bRMove;
//	static int shapeType;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_COMMAND:
//		switch(LOWORD(lParam))
//		{
//		case ID_RECT:
//			shapeType = 0;
//			break;
//		case ID_ELLIPSE:
//			shapeType = 1;
//			break;
//		case ID_LINE:
//			shapeType = 2;
//			break;
//		}
//		break;
//	case WM_RBUTTONDOWN:
//		bRClick = true;		
//		startPoint.x = (short)LOWORD(lParam);
//		startPoint.y = (short)HIWORD(lParam);
//		break;
//	case WM_MOUSEMOVE:		
//		SetTextTitle(hwnd, lParam);
//		if(bRClick)
//		{			
//			bRMove = true;
//
//			endPoint.x = (short)LOWORD(lParam);
//			endPoint.y = (short)HIWORD(lParam);
//
//			MoveRectangle(rtList, endPoint.x-startPoint.x,
//				endPoint.y-startPoint.y);
//			InvalidateRect(hwnd, NULL, TRUE);
//
//			startPoint = endPoint;
//		}
//		break;
//	case WM_RBUTTONUP:
//		bRClick = false;
//		bRMove = false;
//		endPoint.x = (short)LOWORD(lParam);
//		endPoint.y = (short)HIWORD(lParam);
//		MoveRectangle(rtList, endPoint.x-startPoint.x,
//				endPoint.y-startPoint.y);
//		InvalidateRect(hwnd, NULL, TRUE);
//		break;
//	case WM_LBUTTONDOWN:
//		SetCapture(hwnd);
//
//		rt.left = (short)LOWORD(lParam);
//		rt.top = (short)HIWORD(lParam);		
//		InvalidateRect(hwnd, NULL, TRUE);
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
//		switch(shapeType)
//		{
//		case ID_RECT:
//			if(bRMove)
//				DrawRectList(hdc, rtList, RGB(128,128,128) );
//			else
//				DrawRectList(hdc, rtList, RGB(0,0,0) );
//			break;
//		case ID_ELLIPSE:
//			if(bRMove)
//				DrawEllipseList(hdc, rtList, RGB(128,128,128) );
//			else
//				DrawEllipseList(hdc, rtList, RGB(0,0,0) );
//			break;
//		case ID_LINE:
//			if(bRMove)
//				DrawLineList(hdc, rtList, RGB(128,128,128) );
//			else
//				DrawLineList(hdc, rtList, RGB(0,0,0) );
//			break;
//		}
//		EndPaint(hwnd, &ps);
//		break; 
//    case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

#include <windows.h>
#include <list>
#include "resource.h"
using namespace std;

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
void MoveRectangle(list<RECT>& rtList, int dx, int dy)
{
	for(list<RECT>::iterator iter= rtList.begin(); iter != rtList.end();
		++iter)
	{
		iter->left += dx;
		iter->right += dx;
		iter->top += dy;
		iter->bottom += dy;
	}
}

void DrawRectList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
{
	HPEN newPen = CreatePen(PS_SOLID, 1, penColor);
	HPEN oldPen = (HPEN)SelectObject(hdc, newPen);
	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
	{
		const RECT& rt = *iter;
		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
	}
	SelectObject(hdc, oldPen);
	DeleteObject(newPen);
}
void SetTextTitle(HWND hwnd, LPARAM lParam)
{
	TCHAR buf[100];
	wsprintf(buf,"(%d,%d)", LOWORD(lParam), HIWORD(lParam));
	SetWindowText(hwnd, buf);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
                         WPARAM wParam, LPARAM lParam) 
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	static RECT rt;
	static list<RECT> rtList;
	static bool bRClick;
	static POINT startPoint, endPoint;
	static bool bRMove;
	static int shapeType;
	
	switch (iMsg)
	{
    case WM_CREATE:
		break; 
	case WM_COMMAND:
		switch(LOWORD(lParam))
		{
		case ID_RECT:
			shapeType = 0;
			break;
		case ID_ELLIPSE:
			shapeType = 1;
			break;
		case ID_LINE:
			shapeType = 2;
			break;
		}
		break;
	case WM_RBUTTONDOWN:
		bRClick = true;		
		startPoint.x = (short)LOWORD(lParam);
		startPoint.y = (short)HIWORD(lParam);
		break;
	case WM_MOUSEMOVE:		
		SetTextTitle(hwnd, lParam);
		if(bRClick)
		{			
			bRMove = true;

			endPoint.x = (short)LOWORD(lParam);
			endPoint.y = (short)HIWORD(lParam);

			MoveRectangle(rtList, endPoint.x-startPoint.x,
				endPoint.y-startPoint.y);
			InvalidateRect(hwnd, NULL, TRUE);

			startPoint = endPoint;
		}
		break;
	case WM_RBUTTONUP:
		bRClick = false;
		bRMove = false;
		endPoint.x = (short)LOWORD(lParam);
		endPoint.y = (short)HIWORD(lParam);
		MoveRectangle(rtList, endPoint.x-startPoint.x,
				endPoint.y-startPoint.y);
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	case WM_LBUTTONDOWN:
		SetCapture(hwnd);

		rt.left = (short)LOWORD(lParam);
		rt.top = (short)HIWORD(lParam);		
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	case WM_LBUTTONUP:
		ReleaseCapture();

		rt.right = (short)LOWORD(lParam);
		rt.bottom = (short)HIWORD(lParam);
		rtList.push_back( rt );

		hdc = GetDC(hwnd);
		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
		ReleaseDC(hwnd, hdc);
		break;
    case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		if(bRMove)
			DrawRectList(hdc, rtList, RGB(128,128,128) );
		else
			DrawRectList(hdc, rtList, RGB(0,0,0) );
		EndPaint(hwnd, &ps);
		break; 
    case WM_DESTROY:
		PostQuitMessage(0);
		break; 
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
