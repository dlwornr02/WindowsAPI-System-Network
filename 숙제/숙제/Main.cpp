
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



//#include <windows.h> // �����Ѱ����� ���Ƽ� ���� ���� �׷���!
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
//#include <windows.h> // ���� �߰������� ������ �� ������ ������ ��!
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
//#include <windows.h>//�Ф�
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
//			if (IDOK == DialogBox(g_hInst, MAKEINTRESOURCE(IDO_DIALOG1), hwnd, DlgProc)) // �̹��忡�� ���������� ���̾�αװ� ������� ���ϵ�
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
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam) //���ó�� ���ִ°��̴�.
//{
//	/////////////����
//	switch (iMsg)
//	{
//	case WM_INITDIALOG:
//		SetDlgItemInt(hDlg, IDC_EDITX, dx, TRUE);
//		SetDlgItemInt(hDlg, IDC_EDITY, dy, TRUE);
//
//	case WM_COMMAND:   //���̾�α� ������ ���� ��ư�� ���Ѵ�.
//	{
//		switch (LOWORD(wParam))
//		{
//		case IDOK:
//			dx = GetDlgItemInt(hDlg, IDC_EDITX, NULL, TRUE);
//			dy = GetDlgItemInt(hDlg, IDC_EDITY, NULL, TRUE);
//			EndDialog(hDlg, IDOK); //���� ��ư�� ���̵� �༭ ������ ���̴�.
//			break;
//		case IDCANCEL:
//			EndDialog(hDlg, IDCANCEL);
//			break;
//		}
//
//	}
//
//	break;         //WINAPI = Control ����ܼ��� ����� �������̽� ������
//
//	}
//	//����ȭ�鿡 ���������� ��� ������ ����� �������̽��� �����̶��Ѵ�.
//	////////////////
//	return FALSE; //������ �߿��� ��Ȱ�� �Ѵ�. 
//}
