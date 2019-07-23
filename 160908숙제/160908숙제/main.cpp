//
//#include <windows.h>
//#include <list>
//#include "resource.h"
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//   WPARAM wParam, LPARAM lParam);
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//   LPSTR lpszCmdLine, int nCmdShow)
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
//void MoveRectangle(list<RECT>& rtList, int dx, int dy)
//{
//   for(list<RECT>::iterator iter=rtList.begin(); iter!=rtList.end(); iter++)
//   {
//      iter->left += dx;
//      iter->right += dx;
//      iter->top += dy;
//      iter->bottom += dy;
//   }
//}
//void DrawRectList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
//{
//   HPEN newPen = CreatePen(PS_SOLID,1,penColor);
//   HPEN oldPen = (HPEN)SelectObject(hdc,newPen);
//   for(list<RECT>::const_iterator iter=rtList.begin(); iter!=rtList.end(); iter++)
//   {
//      const RECT& rt = *iter;
//      Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
//   }
//   SelectObject(hdc,oldPen);
//   DeleteObject(newPen);
//}
//void DrawElipseList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
//{
//   HPEN newPen = CreatePen(PS_SOLID,1,penColor);
//   HPEN oldPen = (HPEN)SelectObject(hdc,newPen);
//   for(list<RECT>::const_iterator iter=rtList.begin(); iter!=rtList.end(); iter++)
//   {
//      const RECT& rt = *iter;
//      Ellipse(hdc, rt.left, rt.top, rt.right, rt.bottom);
//   }
//   SelectObject(hdc,oldPen);
//   DeleteObject(newPen);
//}
//void DrawLineList(HDC hdc, const list<RECT>& rtList,COLORREF penColor)
//{
//   HPEN newPen = CreatePen(PS_SOLID,1,penColor);
//   HPEN oldPen = (HPEN)SelectObject(hdc,newPen);
//   for(list<RECT>::const_iterator iter=rtList.begin(); iter!=rtList.end(); iter++)
//   {
//      const RECT& rt = *iter;
//      MoveToEx(hdc, rt.left, rt.top, NULL);
//      LineTo(hdc, rt.right, rt.bottom);
//   }
//   SelectObject(hdc,oldPen);
//   DeleteObject(newPen);
//}
//void SetTextTitle(HWND hwnd, LPARAM lParam)
//{
//   TCHAR buf[100];
//   wsprintf(buf, "(%d,%d)", LOWORD(lParam), HIWORD(lParam));
//   SetWindowText(hwnd, buf);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//   WPARAM wParam, LPARAM lParam) 
//{
//   HDC         hdc;
//   PAINTSTRUCT ps; 
//   static RECT rt;
//   static list<RECT> rtList;
//   static bool bRClick;
//   static RECT rtDistance;
//   static POINT startPoint, endPoint;
//   static COLORREF color=RGB(0,0,0);
//   static int shapeType = 0;
//
//   switch (iMsg)
//   {
//   case WM_CREATE:
//      break; 
//   case WM_COMMAND:
//      switch(LOWORD(wParam)) //LOWORD==>ID , HIWORD는 0이다.
//      {
//      case ID_RECT:
//         shapeType = 0;
//         InvalidateRect(hwnd,NULL,TRUE);
//         break;
//      case ID_ELLIPSE:
//         shapeType = 1;
//         InvalidateRect(hwnd,NULL,TRUE);
//         break;
//      case ID_LINE:
//         shapeType = 2;
//         InvalidateRect(hwnd,NULL,TRUE);
//         break;
//      }
//      break;
//   case WM_RBUTTONDOWN:   
//      bRClick = true;
//      startPoint.x = (short)LOWORD(lParam);
//      startPoint.y = (short)HIWORD(lParam);
//      break;
//   case WM_MOUSEMOVE:
//      SetTextTitle(hwnd, lParam);
//      if(bRClick)
//      {
//         color = RGB(255,0,0);
//         endPoint.x = (short)LOWORD(lParam);
//         endPoint.y = (short)HIWORD(lParam);
//         MoveRectangle(rtList, endPoint.x-startPoint.x, endPoint.y-startPoint.y);
//         InvalidateRect(hwnd, NULL, TRUE);
//
//         startPoint = endPoint;
//      }
//      break;
//   case WM_RBUTTONUP:
//      bRClick = false;
//      color = RGB(0,0,0);
//      endPoint.x = (short)LOWORD(lParam);
//      endPoint.y = (short)HIWORD(lParam);
//      MoveRectangle(rtList, endPoint.x-startPoint.x, endPoint.y-startPoint.y);
//      InvalidateRect(hwnd, NULL, TRUE);
//      break;
//   case WM_LBUTTONDOWN:
//      SetCapture(hwnd);//윈도우밖으로 나가도 rect가 그려진다
//
//      rt.left = (short)LOWORD(lParam);//음수쪽으로 가면 이상하게 그려지는 이유
//      rt.top = (short)HIWORD(lParam);//음수일때 값이 lParam의 2byte를 초과한다. 2바이트로 고정시킨다.
//      break;
//   case WM_LBUTTONUP:
//      ReleaseCapture();//윈도우밖으로 나가도 rect가 그려진다 but 음수쪽으로 그리면 이상하게 그려진다.
//
//      rt.right = (short)LOWORD(lParam);
//      rt.bottom = (short)HIWORD(lParam);
//      rtList.push_back(rt);
//
//      InvalidateRect(hwnd, NULL, TRUE);
//      break;
//   case WM_PAINT:
//      hdc = BeginPaint(hwnd, &ps);
//      switch(shapeType)
//      {
//      case 0:
//         DrawRectList(hdc, rtList,color);
//         break;
//      case 1:
//         DrawElipseList(hdc, rtList,color);
//         break;
//      case 2:
//         DrawLineList(hdc, rtList,color);
//         break;
//      }
//      EndPaint(hwnd, &ps);
//      break; 
//   case WM_DESTROY:
//      PostQuitMessage(0);
//      break; 
//   }
//   return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//


#include <windows.h>
#include <list>
#include<typeinfo.h>
#include<fstream>
#include <conio.h>
#include <iostream>
#include "resource.h"
using namespace std;
class Shape
{
protected:
	int left,right,top,bottom;
	HDC hdc;
public:
	Shape(int left,int top,int right,int bottom):left(left),right(right),top(top),bottom(bottom){}
	virtual~Shape(){}
	virtual void Draw(HDC hdc)=0;
	void movePosition(int dx,int dy)
	{
		left+=dx;
		right+=dx;
		top+=dy;
		bottom+=dy;
	}
	int GetLeft(){return left;}
	int GetRight(){return right;}
	int GetTop(){return top;}
	int GetBottom(){return bottom;}
};
class Rect : public Shape
{
public:
	Rect(int left,int top,int right,int bottom):Shape(left,top,right,bottom){}
	void Draw(HDC hdc)
	{
		Rectangle(hdc, left, top, right, bottom);
	}
};
class _Ellipse : public Shape
{
public:
	_Ellipse(int left,int top,int right,int bottom):Shape(left,top,right,bottom){}
	void Draw(HDC hdc)
	{
		Ellipse(hdc, left, top, right, bottom);
	}
};
class Line : public Shape
{

public:
	Line(int left,int top,int right,int bottom):Shape(left,top,right,bottom){}
	void Draw(HDC hdc)
	{

		MoveToEx(hdc, left, top, NULL);
		LineTo(hdc, right, bottom);
	}
};
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
	WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpszCmdLine, int nCmdShow)
{
	HWND     hwnd;
	MSG     msg;
	WNDCLASS WndClass;   
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;      
	WndClass.cbClsExtra   = 0;      
	WndClass.cbWndExtra   = 0;      
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
void MoveShape(list<Shape*>&shapelist,int dx,int dy,int shapetype)
{
	list<Shape*>::iterator siter = shapelist.begin();
	list<Shape*>::iterator eiter = shapelist.end();
	if(shapetype==0)
	{
		for(;siter!=eiter;siter++)
		{
			if(typeid(**siter)==typeid(Rect))
			{
				(*siter)->movePosition(dx,dy);
			}
		}
	}
	else if(shapetype==1)
	{
		for(;siter!=eiter;siter++)
		{
			if(typeid(**siter)==typeid(_Ellipse))
			{
				(*siter)->movePosition(dx,dy);
			}
		}
	}
	else if(shapetype==2)
	{
		for(;siter!=eiter;siter++)
		{
			if(typeid(**siter)==typeid(Line))
			{
				(*siter)->movePosition(dx,dy);
			}
		}
	}
}
void Save(list<Shape*>&shapelist)
{
	ofstream fout("shape.txt");
	fout<<shapelist.size()<<" ";
	list<Shape*>::iterator iter = shapelist.begin();
	for(;iter!=shapelist.end();iter++)
	{
		if(typeid(**iter)==typeid(Rect))
		{
			fout<<0<<" ";
		}
		else if(typeid(**iter)==typeid(_Ellipse))
		{
			fout<<1<<" ";
		}
		else if(typeid(**iter)==typeid(Line))
		{
			fout<<2<<" ";
		}
		fout<<(*iter)->GetLeft()<<" ";
		fout<<(*iter)->GetTop()<<" ";
		fout<<(*iter)->GetRight()<<" ";
		fout<<(*iter)->GetBottom()<<" ";
	}
	fout.close();
}
void Load(list<Shape*>&shapelist)
{
	ifstream fin;
	int size;
	int left;
	int top;
	int right;
	int bottom;
	int shapetype;
	fin.open("shape.txt");
	fin>>size;
	shapelist.clear();
	for(int i=0; i<size; i++)
	{
		fin>>shapetype;
		fin>>left;
		fin>>top;
		fin>>right;
		fin>>bottom;
		if(shapetype==0)
		{
			shapelist.push_back(new Rect(left,top,right,bottom));
		}
		else if(shapetype==1)
		{
			shapelist.push_back(new _Ellipse(left,top,right,bottom));
		}
		else if(shapetype==2)
		{
			shapelist.push_back(new Line(left,top,right,bottom));
		}
	}

	fin.close();
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam) 
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	static list<Shape*> shapelist;
	static int shapeType=0;
	static int left,right,top,bottom;
	static bool bRClick=false;
	static POINT startPoint, endPoint;
	static COLORREF color=RGB(0,0,0);
	list<Shape*>::iterator iter = shapelist.begin();
	switch (iMsg)
	{
	case WM_CREATE:
		break; 
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		
		for(;iter!=shapelist.end();iter++)
		{
			(*iter)->Draw(hdc);
		}
		EndPaint(hwnd, &ps);
		break;
	case WM_LBUTTONDOWN:
		SetCapture(hwnd);//윈도우밖으로 나가도 rect가 그려진다
		left = (short)LOWORD(lParam);//음수쪽으로 가면 이상하게 그려지는 이유
		top = (short)HIWORD(lParam);//음수일때 값이 lParam의 2byte를 초과한다. 2바이트로 고정시킨다.
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam)) //LOWORD==>ID , HIWORD는 0이다.
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
		case ID_SAVE:
			Save(shapelist);
			break;
		case ID_CALL:
			Load(shapelist);
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		break;
	case WM_LBUTTONUP:
		ReleaseCapture();//윈도우밖으로 나가도 rect가 그려진다 but 음수쪽으로 그리면 이상하게 그려진다.
		right = (short)LOWORD(lParam);
		bottom = (short)HIWORD(lParam);

		if(shapeType==0)
		{
			shapelist.push_back(new Rect(left, top, right, bottom));
		}
		else if(shapeType==1)
		{
			shapelist.push_back(new _Ellipse(left, top, right, bottom));
		}
		else if(shapeType==2)
		{
			shapelist.push_back(new Line(left, top, right, bottom));
		}
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	case WM_RBUTTONDOWN:   
		bRClick = true;
		startPoint.x = (short)LOWORD(lParam);
		startPoint.y = (short)HIWORD(lParam);
		break;
	case WM_MOUSEMOVE:
		if(bRClick)
		{
			color = RGB(255,0,0);
			endPoint.x = (short)LOWORD(lParam);
			endPoint.y = (short)HIWORD(lParam);
			MoveShape(shapelist, endPoint.x-startPoint.x, endPoint.y-startPoint.y,shapeType);
			InvalidateRect(hwnd, NULL, TRUE);

			startPoint = endPoint;
		}
		break;
	case WM_RBUTTONUP:
		bRClick = false;
		color = RGB(0,0,0);
		endPoint.x = (short)LOWORD(lParam);
		endPoint.y = (short)HIWORD(lParam);
		MoveShape(shapelist, endPoint.x-startPoint.x, endPoint.y-startPoint.y,shapeType);
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		for(;iter!=shapelist.end();iter++)
		{
			delete *iter;
		}
		break; 
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}