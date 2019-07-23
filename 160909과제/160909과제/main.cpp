
//
//
//#include <windows.h>
//#include<vector>
//#include"resource.h"
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//   WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hinst;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//   LPSTR lpszCmdLine, int nCmdShow)
//{
//   g_hinst = hInstance;
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
//void DrawRectList(HDC hdc,vector<RECT>& rtList)
//{
//   for(unsigned i=0;i<rtList.size();i++)
//   {
//      const RECT& rt = rtList[i];
//      Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//   }
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//   WPARAM wParam, LPARAM lParam) 
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
//      InvalidateRect(hwnd,NULL,TRUE);
//      break;
//   case WM_COMMAND:
//      switch(LOWORD(wParam))
//      {
//      case ID_RECTMOVE:
//         if(IDOK==DialogBox(g_hinst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc))
//         {
//            SetWindowText(hwnd,"ID_OK");
//         }
//      }
//      break;
//   case WM_PAINT:
//      hdc = BeginPaint(hwnd, &ps);
//      DrawRectList(hdc,rtList);
//      // 이곳에서 출력이 이루어짐
//      EndPaint(hwnd, &ps);
//      break; 
//   case WM_DESTROY:
//      PostQuitMessage(0);
//      break; 
//   }
//   return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//
//   switch(iMsg)
//   {
//   case WM_COMMAND: //메뉴를 선택할떄, 단축키를 누를때 , 자식컨트롤이 부모컨트롤에게 알림을 보낼때
//      {
//         switch(LOWORD(wParam))
//         {
//         case IDOK:
//            EndDialog(hDlg,IDOK); //두번째인수는 종료 코드 값이다. 일반적으로 종료값으로 버튼의 ID를 알려준다.
//            //return TRUE; 도 상관없음
//            break;
//         case IDCANCEL:
//            EndDialog(hDlg,IDCANCEL);
//            break;
//         }
//      }
//      break;
//   }
//   return FALSE; //false가 defWindowProc()의 역할을 한다.
//}
//
//
//#include <windows.h>
//#include<vector>
//#include"resource.h"
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//   WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hinst;
//int dx,dy;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//   LPSTR lpszCmdLine, int nCmdShow)
//{
//   g_hinst = hInstance;
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
//void DrawRectList(HDC hdc,vector<RECT>& rtList)
//{
//   for(unsigned i=0;i<rtList.size();i++)
//   {
//      const RECT& rt = rtList[i];
//      Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//   }
//}
//void MoveRectList(vector<RECT>&rtList,int dx,int dy)
//{
//   for(unsigned i=0;i<rtList.size();i++)
//   {
//      RECT& rt = rtList[i];
//      rt.left+=dx;
//      rt.right+=dx;
//      rt.bottom+=dy;
//      rt.top+=dy;
//   }
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//   WPARAM wParam, LPARAM lParam) 
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
//      InvalidateRect(hwnd,NULL,TRUE);
//      break;
//   case WM_COMMAND:
//      switch(LOWORD(wParam))
//      {
//      case ID_RECTMOVE:
//         if(IDOK==DialogBox(g_hinst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc))
//         {
//            MoveRectList(rtList,dx,dy);
//            InvalidateRect(hwnd,NULL,TRUE);
//         }
//      }
//      break;
//   case WM_PAINT:
//      hdc = BeginPaint(hwnd, &ps);
//      DrawRectList(hdc,rtList);
//      // 이곳에서 출력이 이루어짐
//      EndPaint(hwnd, &ps);
//      break; 
//   case WM_DESTROY:
//      PostQuitMessage(0);
//      break; 
//   }
//   return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//
//   switch(iMsg)
//   {
//   case WM_COMMAND: //메뉴를 선택할떄, 단축키를 누를때 , 자식컨트롤이 부모컨트롤에게 알림을 보낼때
//      {
//         switch(LOWORD(wParam))
//         {
//         case IDOK:
//            dx = GetDlgItemInt(hDlg,IDC_EDITX,NULL,TRUE);
//            dy = GetDlgItemInt(hDlg,IDC_EDITY,NULL,TRUE);
//            EndDialog(hDlg,IDOK); //두번째인수는 종료 코드 값이다. 일반적으로 종료값으로 버튼의 ID를 알려준다.
//            //return TRUE; 도 상관없음
//            break;
//         case IDCANCEL:
//            EndDialog(hDlg,IDCANCEL);
//            break;
//         }
//      }
//      break;
//   }
//   return FALSE; //false가 defWindowProc()의 역할을 한다.
//}
//
//
//#include <windows.h>
//#include<vector>
//#include"resource.h"
//using namespace std;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//   WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hinst;
//int dx=100,dy=100;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//   LPSTR lpszCmdLine, int nCmdShow)
//{
//   g_hinst = hInstance;
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
//
//void DrawRectList(HDC hdc,vector<RECT>& rtList,COLORREF penColor)
//{
//   HPEN newPen = CreatePen(PS_SOLID,1,penColor);
//   HPEN oldPen = (HPEN)SelectObject(hdc,newPen);
//   for(unsigned i=0;i<rtList.size();i++)
//   {
//      const RECT& rt = rtList[i];
//      Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//   }
//   SelectObject(hdc,oldPen);
//   DeleteObject(newPen);
//}
//void MoveRectList(vector<RECT>&rtList,int dx,int dy)
//{
//   for(unsigned i=0;i<rtList.size();i++)
//   {
//      RECT& rt = rtList[i];
//      rt.left+=dx;
//      rt.right+=dx;
//      rt.bottom+=dy;
//      rt.top+=dy;
//   }
//}
//class CmpRect
//{
//public:
//   bool operator()(RECT& a,RECT& b)
//   {
//      return (a.bottom==b.bottom && a.left==b.left && a.right==b.right && a.top==b.top);
//   }
//};
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//   WPARAM wParam, LPARAM lParam) 
//{
//   HDC         hdc;
//   PAINTSTRUCT ps; 
//   static RECT rt;
//   static vector<RECT> rtList;
//   static vector<RECT> selectRect;
//   static bool Click_Or_Drag=true;
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
//      InvalidateRect(hwnd,NULL,TRUE);
//      break;
//   case WM_COMMAND:
//      switch(LOWORD(wParam))
//      {
//      case ID_RECTMOVE:
//         if(IDOK==DialogBox(g_hinst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc))
//         {
//            MoveRectList(rtList,dx,dy);
//            InvalidateRect(hwnd,NULL,TRUE);
//         }
//         break;
//      case ID_CLICK:
//         Click_Or_Drag=true;
//         break;
//      case ID_DRAG:
//         Click_Or_Drag=false;
//         break;
//      }
//      break;
//   case WM_RBUTTONDOWN:
//      rt.left = LOWORD(lParam);
//      rt.top = HIWORD(lParam);
//      break;
//      /*case WM_MOUSEMOVE:
//      break;*/
//   case WM_RBUTTONUP:
//
//      if(Click_Or_Drag==true){
//         vector<RECT>::iterator siter = rtList.begin();
//         vector<RECT>::iterator riter = rtList.begin();
//         vector<RECT>::iterator eiter = rtList.end();
//         for(;riter!=eiter;)
//         {
//            if((*riter).left<=rt.left && rt.left<=(*riter).right && (*riter).top<=rt.top && rt.top<=(*riter).bottom)
//            {
//               selectRect.push_back(*riter);
//               riter = rtList.erase(riter);
//               if(riter!=siter)
//               {
//                  riter--;
//               }
//            }
//            else
//            {
//               riter++;
//            }
//         }
//
//         siter = selectRect.begin();
//         riter = selectRect.begin();
//         eiter = selectRect.end();
//
//         for(;riter!=eiter;)
//         {
//            if( ((*riter).left > rt.left || rt.left > (*riter).right) && ((*riter).top > rt.top || rt.top > (*riter).bottom) )
//            {
//               rtList.push_back(*riter);
//               riter = selectRect.erase(riter);
//            }
//         }
//         /*else if(Click_Or_Drag==false)
//         {
//         rt.right = LOWORD(lParam);
//         rt.bottom = HIWORD(lParam);
//
//         }*/
//      }
//      InvalidateRect(hwnd,NULL,TRUE);
//      break;
//
//   case WM_PAINT:
//      hdc = BeginPaint(hwnd, &ps);
//      DrawRectList(hdc,rtList,RGB(0,0,0));
//      DrawRectList(hdc,selectRect,RGB(255,0,0));
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
//BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//   switch(iMsg)
//   {
//   case WM_INITDIALOG:
//      SetDlgItemInt(hDlg,IDC_EDITX,dx,TRUE);
//      SetDlgItemInt(hDlg,IDC_EDITY,dy,TRUE);
//      break;
//   case WM_COMMAND: //메뉴를 선택할떄, 단축키를 누를때 , 자식컨트롤이 부모컨트롤에게 알림을 보낼때
//      {
//         switch(LOWORD(wParam))
//         {
//         case IDOK:
//            dx = GetDlgItemInt(hDlg,IDC_EDITX,NULL,TRUE);
//            dy = GetDlgItemInt(hDlg,IDC_EDITY,NULL,TRUE);
//            EndDialog(hDlg,IDOK); //두번째인수는 종료 코드 값이다. 일반적으로 종료값으로 버튼의 ID를 알려준다.
//            //return TRUE; 도 상관없음
//            break;
//         case IDCANCEL:
//            EndDialog(hDlg,IDCANCEL);
//            break;
//         }
//      }
//      break;
//   }
//   return FALSE; //false가 defWindowProc()의 역할을 한다.
//}


#include <windows.h>
#include<vector>
#include"resource.h"
using namespace std;
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
	WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg,WPARAM wParam,LPARAM lParam);
BOOL CALLBACK DlgProc2(HWND hDlg, UINT iMsg,WPARAM wParam,LPARAM lParam);
HINSTANCE g_hinst;
int dx=100,dy=100;
int left=50,right=200,top=50,bottom=200;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpszCmdLine, int nCmdShow)
{
	g_hinst = hInstance;
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

void DrawRectList(HDC hdc,vector<RECT>& rtList,COLORREF penColor)
{
	HPEN newPen = CreatePen(PS_SOLID,1,penColor);
	HPEN oldPen = (HPEN)SelectObject(hdc,newPen);
	for(unsigned i=0;i<rtList.size();i++)
	{
		const RECT& rt = rtList[i];
		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
	}
	SelectObject(hdc,oldPen);
	DeleteObject(newPen);
}
void MoveRectList(vector<RECT>&rtList,int dx,int dy)
{
	for(unsigned i=0;i<rtList.size();i++)
	{
		RECT& rt = rtList[i];
		rt.left+=dx;
		rt.right+=dx;
		rt.bottom+=dy;
		rt.top+=dy;
	}
}
class CmpRect
{
public:
	bool operator()(RECT& a,RECT& b)
	{
		return (a.bottom==b.bottom && a.left==b.left && a.right==b.right && a.top==b.top);
	}
};
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam) 
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	static RECT rt;
	static vector<RECT> rtList;
	static vector<RECT> selectRect;
	static bool Click_Or_Drag=true;

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
		InvalidateRect(hwnd,NULL,TRUE);
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case ID_RECTMOVE:
			if(IDOK==DialogBox(g_hinst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc))
			{
				MoveRectList(rtList,dx,dy);
				InvalidateRect(hwnd,NULL,TRUE);
			}
			break;
		case ID_CLICK:
			Click_Or_Drag=true;
			break;
		case ID_DRAG:
			Click_Or_Drag=false;
			break;
		case ID_ADD:
			if(IDOK==DialogBox(g_hinst,MAKEINTRESOURCE(IDD_DIALOG2),hwnd,DlgProc2))
			{
				rt.left = left;
				rt.top   =top;
				rt.right =right;
				rt.bottom=bottom;
				rtList.push_back(rt);
				InvalidateRect(hwnd,NULL,TRUE);
			}
			break;
		case ID_DELETE:
			selectRect.clear();
			InvalidateRect(hwnd,NULL,TRUE);
			break;
		}
		break;
	case WM_RBUTTONDOWN:
		rt.left = LOWORD(lParam);
		rt.top = HIWORD(lParam);
		break;
		/*case WM_MOUSEMOVE:
		break;*/
	case WM_RBUTTONUP:

		if(Click_Or_Drag==true){
			vector<RECT>::iterator siter = rtList.begin();
			vector<RECT>::iterator riter = rtList.begin();
			vector<RECT>::iterator eiter = rtList.end();
			for(;riter!=eiter;)
			{
				if((*riter).left<=rt.left && rt.left<=(*riter).right && (*riter).top<=rt.top && rt.top<=(*riter).bottom)
				{
					selectRect.push_back(*riter);
					riter=rtList.erase(riter);
					eiter = rtList.end();
				}
				else
				{
					riter++;
				}
			}

			siter = selectRect.begin();
			riter = selectRect.begin();
			eiter = selectRect.end();

			for(vector<RECT>::iterator riter=selectRect.begin();riter!=selectRect.end();)
			{
				if( (*riter).left > rt.left || rt.left > (*riter).right || (*riter).top > rt.top || rt.top > (*riter).bottom )
				{
					rtList.push_back(*riter);
					riter = selectRect.erase(riter);
					eiter = rtList.end();
				}
				else
				{
					riter++;
				}
			}
		}
		else if(Click_Or_Drag==false)
		{
			rt.right = LOWORD(lParam);
			rt.bottom = HIWORD(lParam);

			vector<RECT>::iterator siter = rtList.begin();
			vector<RECT>::iterator riter = rtList.begin();
			vector<RECT>::iterator eiter = rtList.end();
			for(;riter!=eiter;)
			{
				if((*riter).left>=rt.left && rt.right>=(*riter).right && (*riter).top>=rt.top && rt.bottom>=(*riter).bottom)
				{
					selectRect.push_back(*riter);
					riter=rtList.erase(riter);
					eiter = rtList.end();
				}
				else
				{
					riter++;
				}
			}

			siter = selectRect.begin();
			riter = selectRect.begin();
			eiter = selectRect.end();

			for(vector<RECT>::iterator riter=selectRect.begin();riter!=selectRect.end();)
			{
				if( ((*riter).left < rt.left || rt.right < (*riter).right) || ((*riter).top < rt.top || rt.bottom < (*riter).bottom) )
				{
					rtList.push_back(*riter);
					riter = selectRect.erase(riter);
				}
				else
				{
					riter++;
				}
				eiter = rtList.end();
			}
		}

		InvalidateRect(hwnd,NULL,TRUE);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		DrawRectList(hdc,rtList,RGB(0,0,0));
		DrawRectList(hdc,selectRect,RGB(255,0,0));
		EndPaint(hwnd, &ps);
		break; 
	case WM_DESTROY:
		PostQuitMessage(0);
		break; 
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg,WPARAM wParam,LPARAM lParam)
{
	switch(iMsg)
	{
	case WM_INITDIALOG:
		SetDlgItemInt(hDlg,IDC_EDITX,dx,TRUE);
		SetDlgItemInt(hDlg,IDC_EDITY,dy,TRUE);
		break;
	case WM_COMMAND: //메뉴를 선택할떄, 단축키를 누를때 , 자식컨트롤이 부모컨트롤에게 알림을 보낼때
		{
			switch(LOWORD(wParam))
			{
			case IDOK:
				dx = GetDlgItemInt(hDlg,IDC_EDITX,NULL,TRUE);
				dy = GetDlgItemInt(hDlg,IDC_EDITY,NULL,TRUE);
				EndDialog(hDlg,IDOK); //두번째인수는 종료 코드 값이다. 일반적으로 종료값으로 버튼의 ID를 알려준다.
				//return TRUE; 도 상관없음
				break;
			case IDCANCEL:
				EndDialog(hDlg,IDCANCEL);
				break;
			}
		}
		break;
	}
	return FALSE; //false가 defWindowProc()의 역할을 한다.
}

BOOL CALLBACK DlgProc2(HWND hDlg, UINT iMsg,WPARAM wParam,LPARAM lParam)
{
	switch(iMsg)
	{
	case WM_INITDIALOG:
		SetDlgItemInt(hDlg,IDC_EDITLEFT,left,TRUE);
		SetDlgItemInt(hDlg,IDC_EDITTOP,top,TRUE);
		SetDlgItemInt(hDlg,IDC_EDITRIGHT,right,TRUE);
		SetDlgItemInt(hDlg,IDC_EDITBOTTOM,bottom,TRUE);
		break;
	case WM_COMMAND: //메뉴를 선택할떄, 단축키를 누를때 , 자식컨트롤이 부모컨트롤에게 알림을 보낼때
		{
			switch(LOWORD(wParam))
			{
			case IDOK:
				left = GetDlgItemInt(hDlg,IDC_EDITLEFT,NULL,TRUE);
				top = GetDlgItemInt(hDlg,IDC_EDITTOP,NULL,TRUE);
				right = GetDlgItemInt(hDlg,IDC_EDITRIGHT,NULL,TRUE);
				bottom = GetDlgItemInt(hDlg,IDC_EDITBOTTOM,NULL,TRUE);
				EndDialog(hDlg,IDOK); //두번째인수는 종료 코드 값이다. 일반적으로 종료값으로 버튼의 ID를 알려준다.
				//return TRUE; 도 상관없음
				break;
			case IDCANCEL:
				EndDialog(hDlg,IDCANCEL);
				break;
			}
		}
		break;
	}
	return FALSE; //false가 defWindowProc()의 역할을 한다.
}
