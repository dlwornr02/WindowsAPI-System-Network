#include <windows.h>
#include<vector>
using namespace std;
struct TParam
{
	HWND hwnd;
	POINT pt;
	int count;
};
enum CDType
{
	LOGIN, LOGREP
};
struct copydata
{
	int t1,t2,t3,t4;
};
copydata cp={0};
int count=0;
void SendMessageCopyData(HWND hwnd, PCOPYDATASTRUCT pcds)
{
	HWND hWndA = FindWindow(NULL, TEXT("BB"));
	if( hWndA )
		SendMessage(hWndA, WM_COPYDATA, (WPARAM)hwnd, (LPARAM)pcds);
}
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
	WndClass.cbWndExtra	= sizeof(void*);		
	WndClass.hInstance = hInstance;		
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	
	WndClass.lpszMenuName = NULL;		
	WndClass.lpszClassName = TEXT("AA");	
	RegisterClass(&WndClass);	
	hwnd = CreateWindow("aa",
		TEXT("AA"),
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
COLORREF selectColor(int num)
{
	if(num==0)
		return RGB(255,0,0);
	else if(num==1)
		return RGB(0,255,0);
	else if(num==2)
		return RGB(0,0,255);

	return RGB(255,255,255);
}
DWORD _stdcall TFR(LPVOID pParam)
{
	TParam tp = *(TParam*)pParam;
	HDC hdc = GetDC(tp.hwnd);
	POINT pt = tp.pt;

	while(1)
	{
		for(int i = 0;i<3;i++)
		{
			i=cp.t1+1;
			HBRUSH newHbrush = CreateSolidBrush(selectColor(i));
			HBRUSH oldHbrush = (HBRUSH)SelectObject(hdc,newHbrush);
			Rectangle(hdc,0,0,pt.x/2,pt.y/2);
			Sleep(1000);
			SelectObject(hdc, oldHbrush);
			DeleteObject(newHbrush);
			cp.t1 = i;
		}
		cp.t1=-1;
	}
	ReleaseDC(tp.hwnd,hdc);
	return 0;
}
DWORD _stdcall TFcount(LPVOID pParam)
{
	TParam tp = *(TParam*)pParam;
	HDC hdc = GetDC(tp.hwnd);
	POINT pt = tp.pt;
	RECT rect = {pt.x/2,0,pt.x,pt.y/2};
	while(1)
	{
		for(int i = 0;i<=100;i++)
		{
			i=cp.t2+1;
			TCHAR buf[100];
			wsprintf(buf,"%d",i,100);
			DrawText(hdc,buf,lstrlen(buf),&rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			GdiFlush();
			Sleep(100);
			cp.t2=i;
		}
		Rectangle(hdc,pt.x/2,0,pt.x,pt.y/2);
		for(int i = 100;i>=0;i--)
		{
			i=cp.t2-1;
			TCHAR buf[100];
			wsprintf(buf,"%d",i,100);
			DrawText(hdc,buf,lstrlen(buf),&rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			GdiFlush();
			Sleep(100);
			cp.t2=i;
		}
		cp.t2=-1;
		Rectangle(hdc,pt.x/2,0,pt.x,pt.y/2);
		
	}
	ReleaseDC(tp.hwnd,hdc);
	return 0;
}
DWORD _stdcall TFLine(LPVOID pParam)
{
	TParam tp = *(TParam*)pParam;
	HDC hdc = GetDC(tp.hwnd);
	POINT pt = tp.pt;
	RECT rect = {pt.x/2,pt.y/2,pt.x,pt.y};
	TCHAR buf[100] = "hello!";
	while(1)
	{
		for(int i = 0;i<4;i++)
		{
			i=cp.t3+1;
			SetRect(&rect,pt.x/2,pt.y/10*(i+6),pt.x,pt.y/10*(i+6)+20);
			DrawText(hdc,buf,lstrlen(buf)+1,&rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			cp.t3=i;
			Sleep(1000);
			Rectangle(hdc,pt.x/2,pt.y/2,pt.x,pt.y);
			
		}
		cp.t3=-1;
	}
	ReleaseDC(tp.hwnd,hdc);
	return 0;
}
DWORD _stdcall TFText(LPVOID pParam)
{
	TParam tp = *(TParam*)pParam;
	delete (TParam*)pParam;
	HDC hdc = GetDC(tp.hwnd);
	POINT pt = tp.pt;


	while(1)
	{
		for(int i = 0;i<4;i++)
		{
			i=cp.t4+1;
			MoveToEx(hdc, 0,pt.y/10*(i+6) , NULL);
			LineTo(hdc, pt.x/2,pt.y/10*(i+6));
			cp.t4=i;
			Sleep(1000);
			Rectangle(hdc,0,pt.y/2,pt.x/2,pt.y);
		}
		cp.t4=-1;
	}
	ReleaseDC(tp.hwnd,hdc);
	return 0;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
                         WPARAM wParam, LPARAM lParam) 
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	DWORD id;
	TParam* ptp;  //스레드 사이에는 지역변수를 보내지않는다. main의 지역변수를 넘겨줄수 없다.
	RECT clientrt;
	static vector<HANDLE> hthread;
	switch (iMsg)	//static변수사용시 중첩현상발생 동적메모리로 한다.
	{
	case WM_CREATE:
		{
			cp.t1=0;
			cp.t2=0;
			cp.t3=0;
			cp.t4=0;
			COPYDATASTRUCT cds={0};
			cds.dwData = LOGIN;
			SendMessageCopyData(hwnd, &cds);
			GetClientRect(hwnd,&clientrt);
			ptp = new TParam;
			ptp->hwnd = hwnd;
			ptp->pt.x = clientrt.right;
			ptp->pt.y = clientrt.bottom;
			hthread.push_back(CreateThread(NULL,0,TFR,(LPVOID)ptp,0,&id));
			hthread.push_back(CreateThread(NULL,0,TFcount,(LPVOID)ptp,0,&id));
			hthread.push_back(CreateThread(NULL,0,TFLine,(LPVOID)ptp,0,&id));
			hthread.push_back(CreateThread(NULL,0,TFText,(LPVOID)ptp,0,&id));
		}
		break; 
	case WM_COPYDATA:
		{
			COPYDATASTRUCT* pcds = (COPYDATASTRUCT*)lParam;
			switch(pcds->dwData)
			{
			case LOGIN:
				{
					COPYDATASTRUCT cds = {0};
					cds.dwData = LOGREP;
					cds.lpData = &cp;
					cds.cbData = sizeof(cp);
					SendMessage((HWND)wParam, WM_COPYDATA,
						(WPARAM)hwnd, (LPARAM)&cds);
				}
				break;
			case LOGREP:
				{
					copydata* pcp;
					pcp = (copydata*)(pcds->lpData);
					(cp.t1) = (pcp->t1);
					(cp.t2) = (pcp->t2);
					(cp.t3) = (pcp->t3);
					(cp.t4) = (pcp->t4);
					
				}
				break;

			}			
		}
		break;
	case WM_SIZE:
		GetClientRect(hwnd,&clientrt);
		break;
    case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		// 이곳에서 출력이 이루어짐
		EndPaint(hwnd, &ps);
		break; 
    case WM_DESTROY:
		PostQuitMessage(0);
		break; 
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
