
#include <windows.h> 
#include"resource.h"
#include<vector>
using namespace std;
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE g_hInst;
int dx = 100, dy = 100;
POINT startPoint;
POINT endPoint;
vector<RECT> rectList;
RECT rect;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	g_hInst = hInstance;
	HWND     hwnd;
	MSG     msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
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
BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		SetDlgItemInt(hDlg, IDC_EDITX, dx, TRUE);
		SetDlgItemInt(hDlg, IDC_EDITY, dx, TRUE);
		break;
	case WM_COMMAND:
		{
			switch (LOWORD(wParam))
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
BOOL CALLBACK DlgProc2(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_INITDIALOG:
		break;
	case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
			case IDOK:
				startPoint.x = GetDlgItemInt(hDlg, IDC_EDITL, NULL, TRUE);
				startPoint.y = GetDlgItemInt(hDlg, IDC_EDITT, NULL, TRUE);
				endPoint.x = GetDlgItemInt(hDlg, IDC_EDITR, NULL, TRUE);
				endPoint.y = GetDlgItemInt(hDlg, IDC_EDITB, NULL, TRUE);

				rect.left = startPoint.x;
				rect.top = startPoint.y;
				rect.right = endPoint.x;
				rect.bottom = endPoint.y;
				rectList.push_back(rect);
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
void DrawRectList(HDC hdc, const vector<RECT>& rtList)
{
	for (unsigned i = 0; i < rtList.size(); i++)
	{
		const RECT& rt = rtList[i];
		Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
	}
}
void MoveRectList(vector<RECT>& rtList, int dx, int dy)
{
	for (unsigned i = 0; i < rtList.size(); i++)
	{
		RECT& rt = rtList[i];
		rt.left += dx;
		rt.right += dx;
		rt.top += dy;
		rt.bottom += dy;
	}
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC         hdc;
	PAINTSTRUCT ps;

	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_LBUTTONDOWN:
		SetCapture(hwnd);
		rect.left = (short)LOWORD(lParam);
		rect.top = (short)HIWORD(lParam);
		break;
	case WM_LBUTTONUP:
		ReleaseCapture();
		rect.right = (short)LOWORD(lParam);
		rect.bottom = (short)HIWORD(lParam);
		rectList.push_back(rect);
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_RECTMOVE:
			if (IDOK == DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, DlgProc))
			{
				MoveRectList(rectList, dx, dy);
				InvalidateRect(hwnd, NULL, TRUE);
			}
			break;
		case ID_ADD:
			{
				if (IDOK == DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG2), hwnd, DlgProc2))
				{
					InvalidateRect(hwnd, NULL, TRUE);
				}
				else 
					break;
			}
		case ID_DELETE:
			{

			}
			break;
		}
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		DrawRectList(hdc, rectList);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}



//#include <windows.h> // 벡터한곳으로 몰아서 이제 위에 그려짐!
//#include"resource.h"
//#include<vector>
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
//HINSTANCE g_hInst;
//int dx = 100, dy = 100;
//POINT startPoint;
//POINT endPoint;
//vector<RECT> rectList;
//RECT rect;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
//	HWND     hwnd;
//	MSG     msg;
//	WNDCLASS WndClass;
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;
//	WndClass.cbClsExtra = 0;
//	WndClass.cbWndExtra = 0;
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
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (iMsg)
//	{
//	case WM_INITDIALOG:
//		SetDlgItemInt(hDlg, IDC_EDITX, dx, TRUE);
//		SetDlgItemInt(hDlg, IDC_EDITY, dx, TRUE);
//		break;
//	case WM_COMMAND:
//	{
//		switch (LOWORD(wParam))
//		{
//		case IDOK:
//			dx = GetDlgItemInt(hDlg, IDC_EDITX, NULL, TRUE);
//			dy = GetDlgItemInt(hDlg, IDC_EDITY, NULL, TRUE);
//
//			EndDialog(hDlg, IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg, IDCANCEL);
//			break;
//		}
//	}
//	break;
//	}
//	return FALSE;
//}
//BOOL CALLBACK DlgProc2(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//	{
//		switch (LOWORD(wParam))
//		{
//		case IDOK:
//			startPoint.x = GetDlgItemInt(hDlg, IDC_EDITL, NULL, TRUE);
//			startPoint.y = GetDlgItemInt(hDlg, IDC_EDITT, NULL, TRUE);
//			endPoint.x = GetDlgItemInt(hDlg, IDC_EDITR, NULL, TRUE);
//			endPoint.y = GetDlgItemInt(hDlg, IDC_EDITB, NULL, TRUE);
//			
//			rect.left = startPoint.x;
//			rect.top = startPoint.y;
//			rect.right = endPoint.x;
//			rect.bottom = endPoint.y;
//			rectList.push_back(rect);
//			EndDialog(hDlg, IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg, IDCANCEL);
//			break;
//		}
//	}
//	break;
//	}
//	return FALSE;
//}
//void DrawRectList(HDC hdc, const vector<RECT>& rtList)
//{
//	for (unsigned i = 0; i < rtList.size(); i++)
//	{
//		const RECT& rt = rtList[i];
//		Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//	}
//}
//void MoveRectList(vector<RECT>& rtList, int dx, int dy)
//{
//	for (unsigned i = 0; i < rtList.size(); i++)
//	{
//		RECT& rt = rtList[i];
//		rt.left += dx;
//		rt.right += dx;
//		rt.top += dy;
//		rt.bottom += dy;
//	}
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break;
//	case WM_LBUTTONDOWN:
//		SetCapture(hwnd);
//		rect.left = (short)LOWORD(lParam);
//		rect.top = (short)HIWORD(lParam);
//		break;
//	case WM_LBUTTONUP:
//		ReleaseCapture();
//		rect.right = (short)LOWORD(lParam);
//		rect.bottom = (short)HIWORD(lParam);
//		rectList.push_back(rect);
//		InvalidateRect(hwnd, NULL, TRUE);
//		break;
//	case WM_COMMAND:
//		switch (LOWORD(wParam))
//		{
//		case ID_RECTMOVE:
//			if (IDOK == DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, DlgProc))
//			{
//				MoveRectList(rectList, dx, dy);
//				InvalidateRect(hwnd, NULL, TRUE);
//			}
//			break;
//		case ID_ADD:
//		{
//			if (IDOK == DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG2), hwnd, DlgProc2))
//			{
//
//			}
//			InvalidateRect(hwnd, NULL, TRUE);
//		}
//		break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRectList(hdc, rectList);
//		EndPaint(hwnd, &ps);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}


//
//#include <windows.h> // 도형 추가되지만 도형이 맨 앞으로 나오게 됨!
//#include"resource.h"
//#include<vector>
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
//HINSTANCE g_hInst;
//int dx = 100, dy = 100;
//POINT startPoint;
//POINT endPoint;
//vector<RECT> rectList;
//RECT rect;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
//	HWND     hwnd;
//	MSG     msg;
//	WNDCLASS WndClass;
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;
//	WndClass.cbClsExtra = 0;
//	WndClass.cbWndExtra = 0;
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
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (iMsg)
//	{
//	case WM_INITDIALOG:
//		SetDlgItemInt(hDlg, IDC_EDITX, dx, TRUE);
//		SetDlgItemInt(hDlg, IDC_EDITY, dx, TRUE);
//		break;
//	case WM_COMMAND:
//	{
//		switch (LOWORD(wParam))
//		{
//		case IDOK:
//			dx = GetDlgItemInt(hDlg, IDC_EDITX, NULL, TRUE);
//			dy = GetDlgItemInt(hDlg, IDC_EDITY, NULL, TRUE);
//
//			EndDialog(hDlg, IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg, IDCANCEL);
//			break;
//		}
//	}
//	break;
//	}
//	return FALSE;
//}
//BOOL CALLBACK DlgProc2(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (iMsg)
//	{
//	case WM_INITDIALOG:
//		break;
//	case WM_COMMAND:
//	{
//		switch (LOWORD(wParam))
//		{
//		case IDOK:
//			startPoint.x = GetDlgItemInt(hDlg, IDC_EDITL, NULL, TRUE);
//			startPoint.y = GetDlgItemInt(hDlg, IDC_EDITT, NULL, TRUE);
//			endPoint.x = GetDlgItemInt(hDlg, IDC_EDITR, NULL, TRUE);
//			endPoint.y = GetDlgItemInt(hDlg, IDC_EDITB, NULL, TRUE);
//			
//			rect.left = startPoint.x;
//			rect.top = startPoint.y;
//			rect.right = endPoint.x;
//			rect.bottom = endPoint.y;
//			rectList.push_back(rect);
//			EndDialog(hDlg, IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg, IDCANCEL);
//			break;
//		}
//	}
//	break;
//	}
//	return FALSE;
//}
//void DrawRectList(HDC hdc, const vector<RECT>& rtList)
//{
//	for (unsigned i = 0; i < rtList.size(); i++)
//	{
//		const RECT& rt = rtList[i];
//		Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//	}
//}
//void MoveRectList(vector<RECT>& rtList, int dx, int dy)
//{
//	for (unsigned i = 0; i < rtList.size(); i++)
//	{
//		RECT& rt = rtList[i];
//		rt.left += dx;
//		rt.right += dx;
//		rt.top += dy;
//		rt.bottom += dy;
//	}
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//	static RECT rt;
//	static vector<RECT> rtList;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
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
//		switch (LOWORD(wParam))
//		{
//		case ID_RECTMOVE:
//			if (IDOK == DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, DlgProc))
//			{
//				MoveRectList(rtList, dx, dy);
//				InvalidateRect(hwnd, NULL, TRUE);
//			}
//			break;
//		case ID_ADD:
//		{
//			if (IDOK == DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG2), hwnd, DlgProc2))
//			{
//
//			}
//			InvalidateRect(hwnd, NULL, TRUE);
//		}
//		break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRectList(hdc, rtList);
//		DrawRectList(hdc, rectList);
//		EndPaint(hwnd, &ps);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//
//#include <windows.h>
//#include"resource.h"
//#include<vector>
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
//HINSTANCE g_hInst;
//int dx = 100, dy = 100;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
//	HWND     hwnd;
//	MSG     msg;
//	WNDCLASS WndClass;
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;
//	WndClass.cbClsExtra = 0;
//	WndClass.cbWndExtra = 0;
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
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (iMsg)
//	{
//	case WM_INITDIALOG:
//		SetDlgItemInt(hDlg, IDC_EDITX, dx, TRUE);
//		SetDlgItemInt(hDlg, IDC_EDITY, dx, TRUE);
//		break;
//	case WM_COMMAND:
//	{
//		switch (LOWORD(wParam))
//		{
//		case IDOK:
//			dx = GetDlgItemInt(hDlg, IDC_EDITX, NULL, TRUE);
//			dy = GetDlgItemInt(hDlg, IDC_EDITY, NULL, TRUE);
//
//			EndDialog(hDlg, IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg, IDCANCEL);
//			break;
//		}
//	}
//	break;
//	}
//	return FALSE;
//}
//void DrawRectList(HDC hdc, const vector<RECT>& rtList)
//{
//	for (unsigned i = 0; i < rtList.size(); i++)
//	{
//		const RECT& rt = rtList[i];
//		Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//	}
//}
//void MoveRectList(vector<RECT>& rtList, int dx, int dy)
//{
//	for (unsigned i = 0; i < rtList.size(); i++)
//	{
//		RECT& rt = rtList[i];
//		rt.left += dx;
//		rt.right += dx;
//		rt.top += dy;
//		rt.bottom += dy;
//	}
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//	static RECT rt;
//	static vector<RECT> rtList;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
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
//		switch (LOWORD(wParam))
//		{
//		case ID_RECTMOVE:
//			if (IDOK == DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, DlgProc))
//			{
//				MoveRectList(rtList, dx, dy);
//				InvalidateRect(hwnd, NULL, TRUE);
//			}
//			break;
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRectList(hdc, rtList);
//		EndPaint(hwnd, &ps);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//#include"resource.h"
//#include<vector>
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
//HINSTANCE g_hInst;
//int dx, dy;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//   LPSTR lpszCmdLine, int nCmdShow)
//{
//   g_hInst = hInstance;
//   HWND     hwnd;
//   MSG     msg;
//   WNDCLASS WndClass;
//   WndClass.style = CS_HREDRAW | CS_VREDRAW;
//   WndClass.lpfnWndProc = WndProc;
//   WndClass.cbClsExtra = 0;
//   WndClass.cbWndExtra = 0;
//   WndClass.hInstance = hInstance;
//   WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//   WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//   WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//   WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
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
//      );
//   ShowWindow(hwnd, nCmdShow);
//   UpdateWindow(hwnd);
//   while (GetMessage(&msg, NULL, 0, 0))
//   {
//      TranslateMessage(&msg);
//      DispatchMessage(&msg);
//   }
//   return (int)msg.wParam;
//}
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//   switch (iMsg)
//   {
//   case WM_COMMAND:
//   {
//      switch (LOWORD(wParam))
//      {
//      case IDOK:
//         dx = GetDlgItemInt(hDlg, IDC_EDITX, NULL, TRUE);
//         dy = GetDlgItemInt(hDlg, IDC_EDITY, NULL, TRUE);
//
//         EndDialog(hDlg, IDOK);
//         break;
//      case IDCANCEL:
//         EndDialog(hDlg, IDCANCEL);
//         break;
//      }
//   }
//   break;
//   }
//   return FALSE;
//}
//void DrawRectList(HDC hdc, const vector<RECT>& rtList)
//{
//   for (unsigned i = 0; i < rtList.size(); i++)
//   {
//      const RECT& rt = rtList[i];
//      Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//   }
//}
//void MoveRectList(vector<RECT>& rtList, int dx, int dy)
//{
//   for (unsigned i = 0; i < rtList.size(); i++)
//   {
//      RECT& rt = rtList[i];
//      rt.left += dx;
//      rt.right += dx;
//      rt.top += dy;
//      rt.bottom += dy;
//   }
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//   HDC         hdc;
//   PAINTSTRUCT ps;
//   static RECT rt;
//   static vector<RECT> rtList;
//
//   switch (iMsg)
//   {
//   case WM_CREATE:
//      break;
//   case WM_LBUTTONDOWN:
//      rt.left = LOWORD(lParam);
//      rt.top = HIWORD(lParam);
//      break;
//   case WM_LBUTTONUP:
//      rt.right = LOWORD(lParam);
//      rt.bottom = HIWORD(lParam);
//      rtList.push_back(rt);
//      InvalidateRect(hwnd, NULL, TRUE);
//      break;
//   case WM_COMMAND:
//      switch (LOWORD(wParam))
//      {
//      case ID_RECTMOVE:
//         if (IDOK == DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, DlgProc))
//         {
//            MoveRectList(rtList, dx, dy);
//            InvalidateRect(hwnd, NULL, TRUE);
//         }
//         break;
//      }
//   case WM_PAINT:
//      hdc = BeginPaint(hwnd, &ps);
//      DrawRectList(hdc, rtList);
//      EndPaint(hwnd, &ps);
//      break;
//   case WM_DESTROY:
//      PostQuitMessage(0);
//      break;
//   }
//   return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

//#include <windows.h>
//#include"resource.h"
//#include<vector>
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
//HINSTANCE g_hInst;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//   LPSTR lpszCmdLine, int nCmdShow)
//{
//   g_hInst = hInstance;
//   HWND     hwnd;
//   MSG     msg;
//   WNDCLASS WndClass;
//   WndClass.style = CS_HREDRAW | CS_VREDRAW;
//   WndClass.lpfnWndProc = WndProc;
//   WndClass.cbClsExtra = 0;
//   WndClass.cbWndExtra = 0;
//   WndClass.hInstance = hInstance;
//   WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//   WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
//   WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//   WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
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
//      );
//   ShowWindow(hwnd, nCmdShow);
//   UpdateWindow(hwnd);
//   while (GetMessage(&msg, NULL, 0, 0))
//   {
//      TranslateMessage(&msg);
//      DispatchMessage(&msg);
//   }
//   return (int)msg.wParam;
//}
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//   switch (iMsg)
//   {
//   case WM_COMMAND:
//   {
//      switch (LOWORD(wParam))
//      {
//      case IDOK:
//         EndDialog(hDlg, IDOK);
//         break;
//      case IDCANCEL:
//         EndDialog(hDlg, IDCANCEL);
//         break;
//      }
//   }
//   break;
//   }
//   return FALSE;
//}
//void DrawRectList(HDC hdc, const vector<RECT>& rtList)
//{
//   for (unsigned int i = 0; i < rtList.size(); i++)
//   {
//      const RECT& rt = rtList[i];
//      Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//   }
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
//{
//   HDC         hdc;
//   PAINTSTRUCT ps;
//   static RECT rt;
//   static vector<RECT> rtList;
//
//   switch (iMsg)
//   {
//   case WM_CREATE:
//      break;
//   case WM_LBUTTONDOWN:
//      rt.left = LOWORD(lParam);
//      rt.top = HIWORD(lParam);
//      break;
//   case WM_LBUTTONUP:
//      rt.right = LOWORD(lParam);
//      rt.bottom = HIWORD(lParam);
//      rtList.push_back(rt);
//	  InvalidateRect(hwnd, NULL, TRUE);
//      break;
//   case WM_COMMAND:
//      switch (LOWORD(wParam))
//      {
//      case ID_RECTMOVE:
//         if (IDOK == DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1),hwnd, DlgProc))
//         {
//            SetWindowText(hwnd, "IDOK");
//         }
//         break;
//      }
//   case WM_PAINT:
//      hdc = BeginPaint(hwnd, &ps);
//      DrawRectList(hdc,rtList);
//      EndPaint(hwnd, &ps);
//      break;
//   case WM_DESTROY:
//      PostQuitMessage(0);
//      break;
//   }
//   return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}


//
//#include <windows.h>//ㅠㅠ
//#include "resource.h"
//#include <vector>
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam);
//
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
//HINSTANCE g_hInst;
//int dx=100, dy=100;
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	g_hInst = hInstance;
//	HWND 	 hwnd;
//	MSG 	 msg;
//	WNDCLASS WndClass;
//	WndClass.style = CS_HREDRAW | CS_VREDRAW;
//	WndClass.lpfnWndProc = WndProc;
//	WndClass.cbClsExtra = 0;
//	WndClass.cbWndExtra = 0;
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
//
//void DrawRecList(HDC hdc, const vector<RECT>& rtList)
//{
//	for (unsigned i = 0; i < rtList.size(); ++i)
//	{
//		const RECT rt = rtList[i];
//		Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//	}
//}
//void MoveRectList(vector<RECT>& rtList, int dx, int dy)
//{
//	for (unsigned i = 0; i < rtList.size(); ++i)
//	{
//		RECT& rt = rtList[i];
//		rt.left += dx;
//		rt.right += dx;
//		rt.top += dy;
//		rt.bottom += dy;
//	}
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam)
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//	static RECT rt;
//	static vector<RECT> rtList;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break;
//	case WM_LBUTTONDOWN:
//		rt.left = LOWORD(lParam);
//		rt.top = HIWORD(lParam);
//		break;
//	case WM_LBUTTONUP:
//		rt.right = LOWORD(lParam);
//		rt.bottom = HIWORD(lParam);
//		rtList.push_back(rt);
//		break;
//	case WM_COMMAND:
//		switch (LOWORD(wParam))
//		{
//		case ID_RECTMOVE:
//			if (IDOK == DialogBox(g_hInst, MAKEINTRESOURCE(IDO_DIALOG1), hwnd, DlgProc)) // 이문장에서 멈추져있음 다이얼로그가 사라져야 리턴됨
//			{
//				MoveRectList(rtList, dx, dy);
//				InvalidateRect(hwnd, NULL, TRUE);
//			}
//			break;
//
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		DrawRecList(hdc, rtList);
//		EndPaint(hwnd, &ps);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam) //대신처리 해주는것이다.
//{
//	/////////////정석
//	switch (iMsg)
//	{
//	case WM_INITDIALOG:
//		SetDlgItemInt(hDlg, IDC_EDITX, dx, TRUE);
//		SetDlgItemInt(hDlg, IDC_EDITY, dy, TRUE);
//
//	case WM_COMMAND:   //다이얼로그 윈도의 안의 버튼을 뜻한다.
//	{
//		switch (LOWORD(wParam))
//		{
//		case IDOK:
//			dx = GetDlgItemInt(hDlg, IDC_EDITX, NULL, TRUE);
//			dy = GetDlgItemInt(hDlg, IDC_EDITY, NULL, TRUE);
//			EndDialog(hDlg, IDOK); //누른 버튼의 아이디를 줘서 끝내는 것이다.
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg, IDCANCEL);
//			break;
//		}
//
//	}
//
//	break;         //WINAPI = Control 가장단순한 사용자 인터페이스 윈도우
//
//	}
//	//바탕화면에 독립적으로 띄워 간단한 사용자 인터페이스를 위젯이라한다.
//	////////////////
//	return FALSE; //굉장히 중요한 역활을 한다. 
//}
