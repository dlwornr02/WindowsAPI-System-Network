#include <windows.h>
#include <list>
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
	
	switch (iMsg)
	{
    case WM_CREATE:
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

//#include <windows.h>
//#include <list>
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
//void DrawRectList(HDC hdc, const list<RECT>& rtList)
//{
//	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//	{
//		const RECT& rt = *iter;
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//	}
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
//	static RECT rtDistance;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_RBUTTONDOWN:
//		bRClick = true;		
//		rtDistance.left = (short)LOWORD(lParam);
//		rtDistance.top = (short)HIWORD(lParam);
//		break;
//	case WM_MOUSEMOVE:
//		SetTextTitle(hwnd, lParam);
//		if(bRClick)
//		{			
//			rtDistance.right = (short)LOWORD(lParam);
//			rtDistance.bottom = (short)HIWORD(lParam);
//
//			MoveRectangle(rtList, rtDistance.right-rtDistance.left,
//				rtDistance.bottom-rtDistance.top);
//			InvalidateRect(hwnd, NULL, TRUE);
//
//			rtDistance.left = rtDistance.right;
//			rtDistance.top = rtDistance.bottom;
//		}
//		break;
//	case WM_RBUTTONUP:
//		bRClick = false;
//		rtDistance.right = (short)LOWORD(lParam);
//		rtDistance.bottom = (short)HIWORD(lParam);
//		MoveRectangle(rtList, rtDistance.right-rtDistance.left,
//			rtDistance.bottom-rtDistance.top);
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
//		hdc = GetDC(hwnd);
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		ReleaseDC(hwnd, hdc);
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

//#include <windows.h>
//#include <list>
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
//void DrawRectList(HDC hdc, const list<RECT>& rtList)
//{
//	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//	{
//		const RECT& rt = *iter;
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//	}
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
//	static RECT rtDistance;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
//		break; 
//	case WM_RBUTTONDOWN:
//		bRClick = true;		
//		rtDistance.left = (short)LOWORD(lParam);
//		rtDistance.top = (short)HIWORD(lParam);
//		break;
//	case WM_MOUSEMOVE:
//		SetTextTitle(hwnd, lParam);
//		if(bRClick)
//		{
//			rtDistance.right = (short)LOWORD(lParam);
//			rtDistance.bottom = (short)HIWORD(lParam);
//			MoveRectangle(rtList, rtDistance.right-rtDistance.left,
//				rtDistance.bottom-rtDistance.top);
//			InvalidateRect(hwnd, NULL, TRUE);
//		}
//		break;
//	case WM_RBUTTONUP:
//		bRClick = false;
//		/*rtDistance.right = (short)LOWORD(lParam);
//		rtDistance.bottom = (short)HIWORD(lParam);
//		MoveRectangle(rtList, rtDistance.right-rtDistance.left,
//			rtDistance.bottom-rtDistance.top);
//		InvalidateRect(hwnd, NULL, TRUE);*/
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
//		hdc = GetDC(hwnd);
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		ReleaseDC(hwnd, hdc);
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

//#include <windows.h>
//#include <list>
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
//void DrawRectList(HDC hdc, const list<RECT>& rtList)
//{
//	for(list<RECT>::const_iterator iter=rtList.begin(); iter!= rtList.end(); ++iter)
//	{
//		const RECT& rt = *iter;
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//	}
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//                         WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	static RECT rt;
//	static list<RECT> rtList;
//	
//	switch (iMsg)
//	{
//    case WM_CREATE:
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
//		hdc = GetDC(hwnd);
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		ReleaseDC(hwnd, hdc);
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

