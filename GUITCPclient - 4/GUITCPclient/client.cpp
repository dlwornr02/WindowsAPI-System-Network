//#include <windows.h>
//#include<process.h>
//#include"resource.h"
//#define BUFSIZE 512
//HWND hModelessDlg;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
//HINSTANCE g_hInst;
//SOCKET sock;
//HWND hMainWnd;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	// 윈속 초기화
//	WSADATA wsa;
//	if(WSAStartup(MAKEWORD(2,2), &wsa) != 0) 
//		return -1;
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
//
//	WndClass.lpfnWndProc = TopProc;
//	WndClass.lpszClassName = "TopWindow";
//	RegisterClass(&WndClass);
//
//	WndClass.lpfnWndProc = BottomProc;
//	WndClass.lpszClassName = "BottomWindow";
//	RegisterClass(&WndClass);
//	hwnd = CreateWindow("Window Class Name",
//		"GUI_TCP_Client",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		CW_USEDEFAULT,	
//		NULL,	
//		NULL,	
//		hInstance,	
//		NULL	 
//		);
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		TranslateMessage(&msg);	
//		DispatchMessage(&msg);	
//	}   
//	// 윈속 종료
//	WSACleanup();
//
//	return (int)msg.wParam;
//}
//void DisplayListBox(HWND hwnd,const char*msg)
//{
//	SendDlgItemMessage(GetDlgItem(hwnd,1),1,LB_ADDSTRING,0,(LPARAM)msg);
//}
//BOOL Connect(HWND hwnd)
//{
//	// socket()
//	sock = socket(AF_INET, SOCK_STREAM, 0);
//	if(sock == INVALID_SOCKET) 
//	{
//		DisplayListBox(hMainWnd,"socket()");
//		return FALSE;
//	}
//
//	// connect()
//	SOCKADDR_IN serveraddr;
//	ZeroMemory(&serveraddr, sizeof(serveraddr));//모든메모리의 16바이트를 0으로 초기화
//	//setmemory와 비슷
//	//서버의 정보
//	serveraddr.sin_family = AF_INET;
//	serveraddr.sin_port = htons(9000);
//	serveraddr.sin_addr.s_addr = inet_addr("220.68.231.160");
//
//	int retval = connect( //소켓생성후 server의 정보를 입력하고 바로 connect해준다.
//		sock, //소켓핸들
//		(SOCKADDR *)&serveraddr, //접속 서버 주소값
//		sizeof(serveraddr) //주소값 크기
//		); // 서버에 접속 요청(성공하면 자동으로 지역포트, 지역주소를 할당)
//	if(retval == SOCKET_ERROR)
//	{
//		DisplayListBox(hMainWnd,"connect()");
//		return FALSE;
//	}
//	return TRUE;
//}
//
//int recvn(SOCKET s, char *buf, int len, int flags)
//{
//	int received;
//	char *ptr = buf;
//	int left = len;
//
//	while(left > 0){
//		received = recv(s, ptr, left, flags);
//		if(received == SOCKET_ERROR) 
//			return SOCKET_ERROR;
//		else if(received == 0) 
//			break;
//		left -= received;
//		ptr += received;
//	}
//
//	return (len - left);
//}
//unsigned int _stdcall RecvThread(void* pParam)
//{
//	char buf[BUFSIZE];
//	int len;
//
//	// 서버와 데이터 통신
//	while(1)
//	{
//
//		// '\n' 문자 제거
//		len = strlen(buf);
//		if(buf[len-1] == '\n')
//			buf[len-1] = '\0';
//		if(strlen(buf) == 0)
//			break;
//		//receive는 독립적인 스레드로 이뤄져야한다.
//		//언제 데이터가 들어올지 모르기때문에 & 몇바이트를 보낼지 모르기 때문에
//		//다른 클라이언트에서도 보낼수있기 때문에 데이터포맷이 필요하다.
//		//고정길이 송수신포맷을 이용한다.
//		//ex)보낼때도 100바이트,불러올때도 100바이트
//		//recv에 BUFSIZE를 보내면 최대길이기때문에 안된다.
//
//		//
//		int retval = recvn(sock,buf,BUFSIZE,0);//recvn()을 쓰는이유 길이만큼 정확히 받으려고 고정길이사용
//		if(retval==SOCKET_ERROR || retval == 0)
//			break;
//		char sbuf[1024];
//		wsprintf(sbuf,"[TCP 클라이언트]: %s",buf);
//		DisplayListBox(hMainWnd,sbuf);
//	}
//
//	// closesocket()
//	closesocket(sock);
//
//	return 0;
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam) 
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	unsigned int id;
//	static HWND hTop,hBottom;
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		hMainWnd=hwnd;
//
//		hTop = CreateWindow("TopWindow",NULL,WS_VISIBLE | WS_CHILD,0,0,0,0,hwnd,(HMENU)1,((CREATESTRUCT*)lParam)->hInstance,NULL);
//		hBottom = CreateWindow("BottomWindow",NULL,WS_VISIBLE | WS_CHILD,0,0,0,0,hwnd,(HMENU)2,((CREATESTRUCT*)lParam)->hInstance,NULL);
//
//		if(!Connect(hwnd))
//			return -1;
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,RecvThread,NULL,0,&id));
//		break; 
//	case WM_SIZE:
//		{
//			int cx = LOWORD(lParam);
//			int cy = HIWORD(lParam);
//			MoveWindow(hTop,0,0,cx,cy/2,TRUE);
//			MoveWindow(hBottom,0,cy/2,cx,cy,TRUE);
//		}
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case ID_CONNECTION:
//			{
//				if(!IsWindow(hModelessDlg))//hModelessDlg==NULL
//				{
//					hModelessDlg = CreateDialog(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
//					ShowWindow(hModelessDlg,SW_SHOW);//SW_SHOW는 default로 뜨워준다.
//				}
//				else
//				{
//					SetFocus(hModelessDlg); //이미 윈도우가 띄워져있으면 윈도우에 포커스를 주게하는 메서드
//				}
//			}
//			break;
//		}
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}
//
//LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam)
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//	RECT rt;
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		CreateWindow("listbox",NULL,WS_VISIBLE | WS_CHILD | WS_BORDER,0,0,0,0,hwnd,(HMENU)1,g_hInst,NULL);
//		CreateWindow("edit",NULL,WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,0,0,0,0,hwnd,(HMENU)2,g_hInst,NULL);
//		CreateWindow("button","전송",WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON,0,0,0,0,hwnd,(HMENU)3,g_hInst,NULL);
//		break;
//		//////////////////////////////////////////////////////////////////////////////////////////////
//		//////////////////////////////////////////////////////////////////////////////////////////////
//		//////////////////////////////////////////////////////////////////////////////////////////////
//	case WM_COMMAND:
//		{
//			switch(LOWORD(wParam))
//			{
//		//////////////////////////////////////////////////////////////////////////////////////////////
//		//////////////////////////////////////////////////////////////////////////////////////////////
//		//////////////////////////////////////////////////////////////////////////////////////////////
//			case 3:
//				{
//					TCHAR buf[300];
//					GetWindowText(GetDlgItem(hwnd,2),buf,500);
//					SetWindowText(GetDlgItem(hwnd,2),"");
//
//
//					// 데이터 보내기
//					int retval = send( //blocking함수
//						sock, //통신소켓핸들
//						buf, // 보낼 애플리케이션 버퍼
//						BUFSIZE, //보낼 데이터 크기
//						0 //대부분 0 or MSG_DONTROUTE나 MSG_OOB를 사용 가능
//						);
//					if(retval == SOCKET_ERROR){
//						DisplayListBox(hMainWnd,"send()");
//						break;
//					}
//				}
//				break;
//			}
//		}
//		break;
//	case WM_SIZE:
//		{
//			int cx = LOWORD(lParam);
//			int cy = HIWORD(lParam);
//			MoveWindow(GetDlgItem(hwnd,1),0,0,cx,cy-50,TRUE);
//			MoveWindow(GetDlgItem(hwnd,2),0,cy-40,cx-100,30,TRUE);
//			MoveWindow(GetDlgItem(hwnd,3),cx-90,cy-40,75,30,TRUE);
//			MoveWindow(GetDlgItem(hwnd,4),cx-90,cy-160,75,100,TRUE);
//
//		}
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd,&ps);
//		GetClientRect(hwnd,&rt);
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		EndPaint(hwnd,&ps);
//		break;
//	}
//
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//
//}
//
//LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam)
//{
//	HDC         hdc;
//	PAINTSTRUCT ps; 
//	RECT rt;
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		break; 
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd,&ps);
//		GetClientRect(hwnd,&rt);
//		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
//		EndPaint(hwnd,&ps);
//		break;
//	}
//
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//
//}
//void UpdateList(HWND hDlg)
//{
//	SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_RESETCONTENT,0,0); //리스트박스내의 텍스트를 지워준다.
//
//	int sel = SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_GETCOUNT,0,0);
//	if(sel>0) //리스트 박스를 벗어낫을때 스크롤바가 아래로 진행하게 하는 코드
//	{
//		SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_SETCURSEL,(WPARAM)(sel-1),0);
//		SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_SETCURSEL,(WPARAM)-1,0);
//	}
//}
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	UINT nPos;
//	switch(iMsg)//modeless다이얼로그라서 COMMAND가 필요 없다.
//	{
//	case WM_INITDIALOG:
//		UpdateList(hDlg);
//		break;
//	case WM_CLOSE:
//		DestroyWindow(hModelessDlg);
//		hModelessDlg = NULL;
//		break;
//	case WM_COMMAND:
//		switch(LOWORD(wParam))
//		{
//		case IDC_CONNECTIONLIST:
//			break;
//		}
//		break;
//	case IDC_BUTTON1:
//		{
//			UpdateList(hDlg);
//		}
//		break;
//	}
//	return FALSE;
//}
#include <windows.h>
#include<process.h>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
#include"resource.h"
#define BUFSIZE 512
using namespace std;
map<int,long> clientList;
vector<int> portList;
HWND hModelessDlg;
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
	WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg, 
	WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg, 
	WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam);
void UpdateList(HWND hDlg);

HANDLE hMutex;
HINSTANCE g_hInst;
SOCKET sock;
HWND hMainWnd;

int shapeType=0;
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
class PolyLine : public Shape
{
	vector<POINT> lineList;
public:
	PolyLine():Shape(0,0,0,0){}
	void AddLine(const POINT pt)
	{
		lineList.push_back(pt);
	}
	void Draw(HDC hdc)
	{
		if(1<lineList.size())
		{
			for(unsigned i=0;i<lineList.size()-1;i++)
			{
				MoveToEx(hdc, lineList[i].x, lineList[i].y, NULL);
				LineTo(hdc, lineList[i+1].x, lineList[i+1].y);
			}
			MoveToEx(hdc, lineList[0].x , lineList[0].y, NULL);
			LineTo(hdc, lineList[lineList.size()-1].x , lineList[lineList.size()-1].y);
		}
	}
	void Clear()
	{
		lineList.clear();
	}
};
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpszCmdLine, int nCmdShow)
{
	// 윈속 초기화
	WSADATA wsa;
	if(WSAStartup(MAKEWORD(2,2), &wsa) != 0) 
		return -1;
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

	WndClass.lpfnWndProc = TopProc;
	WndClass.lpszClassName = "TopWindow";
	RegisterClass(&WndClass);

	WndClass.lpfnWndProc = BottomProc;
	WndClass.lpszClassName = "BottomWindow";
	RegisterClass(&WndClass);
	hwnd = CreateWindow("Window Class Name",
		"GUI_TCP_Client",
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
	// 윈속 종료
	WSACleanup();

	return (int)msg.wParam;
}
void DisplayListBox(HWND hwnd,const char*msg)
{
	SendDlgItemMessage(GetDlgItem(hwnd,1),1,LB_ADDSTRING,0,(LPARAM)msg);
}
BOOL Connect(HWND hwnd)
{
	// socket()
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == INVALID_SOCKET) 
	{
		DisplayListBox(hMainWnd,"socket()");
		return FALSE;
	}
	// connect()
	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));//모든메모리의 16바이트를 0으로 초기화
	//setmemory와 비슷
	//서버의 정보
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(9000);
	serveraddr.sin_addr.s_addr = inet_addr("220.68.231.160");

	int retval = connect( //소켓생성후 server의 정보를 입력하고 바로 connect해준다.
		sock, //소켓핸들
		(SOCKADDR *)&serveraddr, //접속 서버 주소값
		sizeof(serveraddr) //주소값 크기
		); // 서버에 접속 요청(성공하면 자동으로 지역포트, 지역주소를 할당)
	if(retval == SOCKET_ERROR)
	{
		DisplayListBox(hMainWnd,"connect()");
		return FALSE;
	}
	return TRUE;
}

int recvn(SOCKET s, char *buf, int len, int flags)
{
	int received;
	char *ptr = buf;
	int left = len;

	while(left > 0){
		received = recv(s, ptr, left, flags);
		if(received == SOCKET_ERROR) 
			return SOCKET_ERROR;
		else if(received == 0) 
			break;
		left -= received;
		ptr += received;
	}

	return (len - left);
}
unsigned int _stdcall RecvThread(void* pParam)
{
	char buf[BUFSIZE];
	int len;

	// 서버와 데이터 통신
	while(1)
	{

		// '\n' 문자 제거
		len = strlen(buf);
		if(buf[len-1] == '\n')
			buf[len-1] = '\0';
		if(strlen(buf) == 0)
			break;
		//receive는 독립적인 스레드로 이뤄져야한다.
		//언제 데이터가 들어올지 모르기때문에 & 몇바이트를 보낼지 모르기 때문에
		//다른 클라이언트에서도 보낼수있기 때문에 데이터포맷이 필요하다.
		//고정길이 송수신포맷을 이용한다.
		//ex)보낼때도 100바이트,불러올때도 100바이트
		//recv에 BUFSIZE를 보내면 최대길이기때문에 안된다.

		//
		int retval = recvn(sock,buf,BUFSIZE,0);//recvn()을 쓰는이유 길이만큼 정확히 받으려고 고정길이사용
		if(retval==SOCKET_ERROR || retval == 0)
			break;
		char sbuf[1024];
		string s=buf;
		switch(s[0])
		{
		case 'm':
			{
				wsprintf(sbuf,"[TCP 클라이언트]: %s",buf);
				DisplayListBox(hMainWnd,sbuf);
			}
			break;
		case 'l':
			{
				DisplayListBox(hMainWnd,"접속!");
				int port=*((int*)buf+1);
				long addr = *((long*)buf+1);
				clientList[port]=addr;
				portList.push_back(port);
				UpdateList(hModelessDlg);
			}
			break;
		case 'o':
			{
				DisplayListBox(hMainWnd,"퇴장!");
				int port=*((int*)buf+1);
				long addr = *((long*)buf+1);
				clientList.erase(port);
				vector<int>::iterator iter = find(portList.begin(),portList.end(),port);
				portList.erase(iter);
				UpdateList(hModelessDlg);
			}
			break;
		case 's':
			{
			}
			break;
		}
	}

	// closesocket()
	closesocket(sock);

	return 0;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam) 
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	unsigned int id;
	static HWND hTop,hBottom;
	switch (iMsg)
	{
	case WM_CREATE:
		hMutex=CreateMutex(NULL,FALSE,"vecMutex");
		hMainWnd=hwnd;

		hTop = CreateWindow("TopWindow",NULL,WS_VISIBLE | WS_CHILD,0,0,0,0,hwnd,(HMENU)1,((CREATESTRUCT*)lParam)->hInstance,NULL);
		hBottom = CreateWindow("BottomWindow",NULL,WS_VISIBLE | WS_CHILD,0,0,0,0,hwnd,(HMENU)2,((CREATESTRUCT*)lParam)->hInstance,NULL);

		if(!Connect(hwnd))
			return -1;
		CloseHandle((HANDLE)_beginthreadex(NULL,0,RecvThread,NULL,0,&id));
		break; 
	case WM_SIZE:
		{
			int cx = LOWORD(lParam);
			int cy = HIWORD(lParam);
			MoveWindow(hTop,0,0,cx,cy/2,TRUE);
			MoveWindow(hBottom,0,cy/2,cx,cy,TRUE);
		}
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case ID_CONNECTION:
			{
				if(!IsWindow(hModelessDlg))//hModelessDlg==NULL
				{
					hModelessDlg = CreateDialog(g_hInst,MAKEINTRESOURCE(IDD_DIALOG1),hwnd,DlgProc);
					ShowWindow(hModelessDlg,SW_SHOW);//SW_SHOW는 default로 뜨워준다.
				}
				else
				{
					SetFocus(hModelessDlg); //이미 윈도우가 띄워져있으면 윈도우에 포커스를 주게하는 메서드
				}
			}
			break;
		case ID_RECT:
			shapeType = 0;
			break;
		case ID_ELLIPSE:
			shapeType = 1;
			break;
		case ID_LINE:
			shapeType = 2;
			break;
		case ID_POLYLINE:
			shapeType = 3;
			break;
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		// 이곳에서 출력이 이루어짐
		EndPaint(hwnd, &ps);
		break; 
	case WM_DESTROY:
		CloseHandle(hMutex);
		PostQuitMessage(0);
		break; 
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{
	HDC         hdc;
	PAINTSTRUCT ps;
	RECT rt;
	switch (iMsg)
	{
	case WM_CREATE:
		CreateWindow("listbox",NULL,WS_VISIBLE | WS_CHILD | WS_BORDER,0,0,0,0,hwnd,(HMENU)1,g_hInst,NULL);
		CreateWindow("edit",NULL,WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,0,0,0,0,hwnd,(HMENU)2,g_hInst,NULL);
		CreateWindow("button","전송",WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON,0,0,0,0,hwnd,(HMENU)3,g_hInst,NULL);
		break;
		//////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////
	case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
		//////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////
			case 3:
				{
					TCHAR buf[300];
					GetWindowText(GetDlgItem(hwnd,2),buf,500);
					SetWindowText(GetDlgItem(hwnd,2),"");


					// 데이터 보내기
					int retval = send( //blocking함수
						sock, //통신소켓핸들
						buf, // 보낼 애플리케이션 버퍼
						BUFSIZE, //보낼 데이터 크기
						0 //대부분 0 or MSG_DONTROUTE나 MSG_OOB를 사용 가능
						);
					if(retval == SOCKET_ERROR){
						DisplayListBox(hMainWnd,"send()");
						break;
					}
				}
				break;
			}
		}
		break;
	case WM_SIZE:
		{
			int cx = LOWORD(lParam);
			int cy = HIWORD(lParam);
			MoveWindow(GetDlgItem(hwnd,1),0,0,cx,cy-50,TRUE);
			MoveWindow(GetDlgItem(hwnd,2),0,cy-40,cx-100,30,TRUE);
			MoveWindow(GetDlgItem(hwnd,3),cx-90,cy-40,75,30,TRUE);
			MoveWindow(GetDlgItem(hwnd,4),cx-90,cy-160,75,100,TRUE);

		}
	case WM_PAINT:
		hdc = BeginPaint(hwnd,&ps);
		GetClientRect(hwnd,&rt);
		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
		EndPaint(hwnd,&ps);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);

}

LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{
	HDC         hdc;
	PAINTSTRUCT ps; 
	RECT rt;
	static list<Shape*> shapelist;
	static int left,top,right,bottom;
	static PolyLine pl;
	list<Shape*>::iterator iter = shapelist.begin();
		switch (iMsg)
	{
		case WM_CREATE:
			break; 
		case WM_PAINT:
			hdc = BeginPaint(hwnd,&ps);
			GetClientRect(hwnd,&rt);
			Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
			for(;iter!=shapelist.end();iter++)
			{
				(*iter)->Draw(hdc);
			}
			EndPaint(hwnd,&ps);
			break;
		case WM_LBUTTONDOWN:
			SetCapture(hwnd);//윈도우밖으로 나가도 rect가 그려진다
			left = (short)LOWORD(lParam);//음수쪽으로 가면 이상하게 그려지는 이유
			top = (short)HIWORD(lParam);//음수일때 값이 lParam의 2byte를 초과한다. 2바이트로 고정시킨다.
			if(shapeType==3)
			{
				POINT pt={left,top};
				pl.AddLine(pt);
			}
			break;
		//case WM_COMMAND:
		//	switch(LOWORD(wParam)) //LOWORD==>ID , HIWORD는 0이다.
		//	{
		//	case ID_RECT:
		//		shapeType = 0;
		//		break;
		//	case ID_ELLIPSE:
		//		shapeType = 1;
		//		break;
		//	case ID_LINE:
		//		shapeType = 2;
		//		break;
		//	}
		//	break;
		case WM_LBUTTONUP:
			ReleaseCapture();//윈도우밖으로 나가도 rect가 그려진다 but 음수쪽으로 그리면 이상하게 그려진다.
			right = (short)LOWORD(lParam);
			bottom = (short)HIWORD(lParam);

			if(shapeType==0)
			{
				pl.Clear();
				shapelist.push_back(new Rect(left, top, right, bottom));
			}
			else if(shapeType==1)
			{
				pl.Clear();
				shapelist.push_back(new _Ellipse(left, top, right, bottom));
			}
			else if(shapeType==2)
			{
				pl.Clear();
				shapelist.push_back(new Line(left, top, right, bottom));
			}
			if(shapeType!=3)
			{
				InvalidateRect(hwnd, NULL, TRUE);
			}
			break;
		case WM_RBUTTONDOWN:
			{
				if(shapeType==3)
				{
					PolyLine* pl2=new PolyLine();
					(*pl2)=pl;
					shapelist.push_back(pl2);
					pl.Clear();
				}
				InvalidateRect(hwnd, NULL, TRUE);
			}
			break;
		case WM_SIZE:
			{

			}
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
void UpdateList(HWND hDlg)
{
	SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_RESETCONTENT,0,0); //리스트박스내의 텍스트를 지워준다.

	//SOCKADDR_IN clientaddr;
	//int sel;

	//int len = sizeof(clientaddr);
	//for(unsigned i=0;i<clientList.size();i++)
	//{
	//	char sbuf[500];
	//	wsprintf(sbuf,"IP 주소=%s, 포트 번호=%d",clientList[portList[i]]/*inet_ntoa(clientaddr.sin_addr)*/, portList[i]);
	//	SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_ADDSTRING,0,(LPARAM)sbuf);
	//	sel = SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_GETCOUNT,0,0);
	//	if(sel>0) //리스트 박스를 벗어낫을때 스크롤바가 아래로 진행하게 하는 코드
	//	{
	//		SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_SETCURSEL,(WPARAM)(sel-1),0);
	//		SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_SETCURSEL,(WPARAM)-1,0);
	//	}
	//}
}
BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
{
	switch(iMsg)//modeless다이얼로그라서 COMMAND가 필요 없다.
	{
	case WM_INITDIALOG:
		hModelessDlg=hDlg;
		UpdateList(hDlg);
		break;
	case WM_CLOSE:
		DestroyWindow(hModelessDlg);
		hModelessDlg = NULL;
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDC_CONNECTIONLIST:
			break;
		}
		break;
	case IDC_BUTTON1:
		{
			UpdateList(hDlg);
		}
		break;
	}
	return FALSE;
}