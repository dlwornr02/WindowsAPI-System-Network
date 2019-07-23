#include <windows.h>
#include<vector>
#include"resource.h"
using namespace std;
vector<RECT> rtListUp;
vector<RECT> rtListDown;
int countUp=0,countDown=0;
int fullcountUp=0,fullcountDown=0;
HWND hModelessDlg;
HINSTANCE g_hInst;
HWND g_hwnd;
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
	WPARAM wParam, LPARAM lParam);
void CALLBACK TimerProc(HWND hwnd, UINT msg, UINT id, DWORD time);
void CALLBACK TimerProc2(HWND hwnd, UINT msg, UINT id, DWORD time);
BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg,WPARAM wParam,LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpszCmdLine, int nCmdShow)
{
	HWND     hwnd;
	MSG     msg;
	g_hInst = hInstance;
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
void UpdateRectList(vector<RECT>&rtList,int right,int bottom,int top,int slice)
{
	int x;
	x=right/slice;
	for(int i=0;i<slice;i++)
	{
		rtList[i].left=x*i;
		rtList[i].right=x*(i+1);
		rtList[i].top=top;
		rtList[i].bottom=bottom;
	}
}
void InitRectList(vector<RECT>&rtList,int right,int bottom,int top,int slice)
{
	RECT rt;
	int x;
	x=right/slice;
	for(int i=0;i<slice;i++)
	{
		rt.left=x*i;
		rt.right=x*(i+1);
		rt.top=top;
		rt.bottom=bottom;
		rtList.push_back(rt);
	}
}
void DrawRect(HDC hdc,RECT rt,COLORREF color)
{
	HBRUSH hNewBrush = CreateSolidBrush(color);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc,hNewBrush);

	Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);

	SelectObject(hdc,hOldBrush);
	DeleteObject(hNewBrush);
}
void DrawRectList(HDC hdc,vector<RECT> rtList,int num)
{
	COLORREF color=RGB(255,255,255);
	if(countUp==0){color=RGB(255,0,0);}
	else if(countUp==1){color=RGB(0,0,255);}
	else if(countUp==2){color=RGB(0,255,0);}
	for(unsigned i = 0; i<rtList.size();i++)
	{
		if(num!=i)
			DrawRect(hdc,rtList[i],RGB(255,255,255));
		else
			DrawRect(hdc,rtList[i],color);
	}
}
void DrawRectLine(HDC hdc,RECT rt)
{
	for(int i=0;i<3;i++)
	{
		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
		MoveToEx(hdc, rt.left, rt.bottom/6*(i+3), NULL);
		LineTo(hdc, rt.right,rt.bottom/6*(i+3));
		Sleep(200);
	}
}
void DrawRectList2(HDC hdc,vector<RECT> rtList)
{
	for(unsigned i = 0; i<rtList.size();i++)
	{
		if(countDown!=i)
			DrawRect(hdc,rtList[i],RGB(255,255,255));
		else
			DrawRectLine(hdc,rtList[i]);
	}
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam) 
{
	g_hwnd = hwnd;
	HDC         hdc;
	PAINTSTRUCT ps; 
	static RECT rt;
	static int cx,cy;
	RECT clientRt;
	switch (iMsg)
	{
	case WM_CREATE:
		GetClientRect(hwnd, &clientRt);
		cx = clientRt.right;
		cy = clientRt.bottom;
		InitRectList(rtListUp,cx,cy/2,0,3);
		InitRectList(rtListDown,cx,cy,cy/2,5);
		SetTimer(hwnd,1,500,TimerProc);
		SetTimer(hwnd,2,500,TimerProc2);
		break;
	case WM_SIZE:
		GetClientRect(hwnd, &clientRt);
		cx = clientRt.right;
		cy = clientRt.bottom;
		UpdateRectList(rtListUp,cx,cy/2,0,3);
		UpdateRectList(rtListDown,cx,cy,cy/2,5);
		InvalidateRect(hwnd,NULL,TRUE);
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case ID_INFO:
			if(!IsWindow(hModelessDlg))//hModelessDlg==NULL
			{
				hModelessDlg = CreateDialog(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
				ShowWindow(hModelessDlg,SW_SHOW);//SW_SHOW는 default로 뜨워준다.
			}
			else
			{
				SetFocus(hModelessDlg); //이미 윈도우가 띄워져있으면 윈도우에 포커스를 주게하는 메서드
			}
			break;
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		break; 
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
void CALLBACK TimerProc(HWND hwnd, UINT msg, UINT id, DWORD time)
{
	countUp%=3;
	HDC hdc = GetDC(hwnd);
	hdc = GetDC(hwnd);
	DrawRectList(hdc,rtListUp,countUp);
	ReleaseDC(hwnd, hdc);
	countUp++;
	if(countUp==2){
		fullcountUp++;
		TCHAR buf[100];
		wsprintf(buf,"%d-%d",fullcountUp,fullcountDown);
		SetWindowText(hwnd,buf);
		SetDlgItemInt(hModelessDlg, IDC_EDIT1,fullcountUp,TRUE);
		//SendDlgItemMessage(hModelessDlg, IDC_EDIT1, EN_CHANGE, (WPARAM)(fullcountUp), fullcountUp);
	}
}
void CALLBACK TimerProc2(HWND hwnd, UINT msg, UINT id, DWORD time)
{
	countDown%=5;
	HDC hdc = GetDC(hwnd);
	hdc = GetDC(hwnd);
	DrawRectList2(hdc,rtListDown);
	ReleaseDC(hwnd, hdc);
	countDown++;
	if(countDown==4){
		fullcountDown++;
		TCHAR buf[100];
		wsprintf(buf,"%d-%d",fullcountUp,fullcountDown);
		SetWindowText(hwnd,buf);
		SetDlgItemInt(hModelessDlg, IDC_EDIT2,fullcountDown,TRUE);
		//SendDlgItemMessage(hDlg,IDC_LIST1,LB_RESETCONTENT,0,0);
	}
}
BOOL CALLBACK DlgProc(HWND hDlg, UINT iMsg,WPARAM wParam,LPARAM lParam)
{
	static BOOL pause=true;
	switch(iMsg)
	{
	case WM_INITDIALOG:
		SetDlgItemInt(hDlg,IDC_EDIT1,fullcountUp,TRUE); //범위 설정
		SetDlgItemInt(hDlg,IDC_EDIT2,fullcountDown,TRUE);
		SetTimer(g_hwnd,1,500,TimerProc);
		SetTimer(g_hwnd,2,500,TimerProc2);
		break;
	case WM_CLOSE:
		DestroyWindow(hModelessDlg);
		hModelessDlg = NULL;
		break;
	case WM_COMMAND: 
		{
			switch (LOWORD(wParam))
			{
			case IDC_PAUSE:
				if(pause)
				{
					KillTimer(g_hwnd,1);
					KillTimer(g_hwnd,2);
					pause=false;
				}
				else
				{
					SetTimer(g_hwnd,1,500,TimerProc);
					SetTimer(g_hwnd,2,500,TimerProc2);
					pause=true;
				}
				//system("pause");
				break;
			}
			break;
		}
	}
	return FALSE; 
}