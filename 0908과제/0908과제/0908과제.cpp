#include<windows.h>
#include<vector>
#include"resource.h"
using namespace std;
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
class Shape{
	POINT startPt;
	POINT endPt;
public:
	Shape(long x1, long y1, long x2, long y2)
	{
		startPt.x = x1;
		startPt.y = y1;
		endPt.x = x2;
		endPt.y = y2;
	}
	virtual void Draw(HDC hdc) = 0;
};
class Rect : public Shape{
	POINT startPt;
	POINT endPt;
public:
	Rect(long x1, long y1, long x2, long y2) :Shape(x1, y1, x2, y2)
	{
		startPt.x = x1;
		startPt.y = y1;
		endPt.x = x2;
		endPt.y = y2;
	}
	virtual void Draw(HDC hdc)
	{
		Rectangle(hdc, startPt.x, startPt.y, endPt.x, endPt.y);
	}
};
class Ell : public Shape{
	POINT startPt;
	POINT endPt;
public:
	Ell(long x1, long y1, long x2, long y2) :Shape(x1, y1, x2, y2)
	{
		startPt.x = x1;
		startPt.y = y1;
		endPt.x = x2;
		endPt.y = y2;
	};
	virtual void Draw(HDC hdc)
	{
		Ellipse(hdc, startPt.x, startPt.y, endPt.x, endPt.y);
	};
};
class Line : public Shape{
	POINT startPt;
	POINT endPt;
public:
	Line(int x1, int y1, int x2, int y2) :Shape(x1, y1, x2, y2)
	{
		startPt.x = x1;
		startPt.y = y1;
		endPt.x = x2;
		endPt.y = y2;
	}
	virtual void Draw(HDC hdc)
	{
		MoveToEx(hdc, startPt.x, startPt.y, NULL);
		LineTo(hdc, endPt.x, endPt.y);
	}
};
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
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
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC         hdc;
	PAINTSTRUCT ps;
	static vector<Shape*> rtList;
	static POINT startPoint, endPoint;
	static int shapeType = 0;
	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
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
	case WM_LBUTTONDOWN:
		SetCapture(hwnd);
		startPoint.x = (short)LOWORD(lParam);
		startPoint.y = (short)HIWORD(lParam);
		break;
	case WM_LBUTTONUP:
		ReleaseCapture();
		endPoint.x = (short)LOWORD(lParam);
		endPoint.y = (short)HIWORD(lParam);

		hdc = GetDC(hwnd);
		switch (shapeType)
		{
		case 0:
		{
			Rect r(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
			rtList.push_back(&r);
		}
		break;
		case 1:
		{
			Ell e(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
			rtList.push_back(&e);
		}
		break;
		case 2:
		{
			Line l(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
			rtList.push_back(&l);
		}
		break;
		}
		InvalidateRect(hwnd, NULL, TRUE);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		for (int i = 0; i<rtList.size(); i++)
		{
			rtList[i]->Draw(hdc);
		}
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}