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
//	// ���� �ʱ�ȭ
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
//	// ���� ����
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
//	ZeroMemory(&serveraddr, sizeof(serveraddr));//���޸��� 16����Ʈ�� 0���� �ʱ�ȭ
//	//setmemory�� ���
//	//������ ����
//	serveraddr.sin_family = AF_INET;
//	serveraddr.sin_port = htons(9000);
//	serveraddr.sin_addr.s_addr = inet_addr("220.68.231.160");
//
//	int retval = connect( //���ϻ����� server�� ������ �Է��ϰ� �ٷ� connect���ش�.
//		sock, //�����ڵ�
//		(SOCKADDR *)&serveraddr, //���� ���� �ּҰ�
//		sizeof(serveraddr) //�ּҰ� ũ��
//		); // ������ ���� ��û(�����ϸ� �ڵ����� ������Ʈ, �����ּҸ� �Ҵ�)
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
//	// ������ ������ ���
//	while(1)
//	{
//
//		// '\n' ���� ����
//		len = strlen(buf);
//		if(buf[len-1] == '\n')
//			buf[len-1] = '\0';
//		if(strlen(buf) == 0)
//			break;
//		//receive�� �������� ������� �̷������Ѵ�.
//		//���� �����Ͱ� ������ �𸣱⶧���� & �����Ʈ�� ������ �𸣱� ������
//		//�ٸ� Ŭ���̾�Ʈ������ �������ֱ� ������ ������������ �ʿ��ϴ�.
//		//�������� �ۼ��������� �̿��Ѵ�.
//		//ex)�������� 100����Ʈ,�ҷ��ö��� 100����Ʈ
//		//recv�� BUFSIZE�� ������ �ִ���̱⶧���� �ȵȴ�.
//
//		//
//		int retval = recvn(sock,buf,BUFSIZE,0);//recvn()�� �������� ���̸�ŭ ��Ȯ�� �������� �������̻��
//		if(retval==SOCKET_ERROR || retval == 0)
//			break;
//		char sbuf[1024];
//		wsprintf(sbuf,"[TCP Ŭ���̾�Ʈ]: %s",buf);
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
//					ShowWindow(hModelessDlg,SW_SHOW);//SW_SHOW�� default�� �߿��ش�.
//				}
//				else
//				{
//					SetFocus(hModelessDlg); //�̹� �����찡 ����������� �����쿡 ��Ŀ���� �ְ��ϴ� �޼���
//				}
//			}
//			break;
//		}
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// �̰����� ����� �̷����
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
//		CreateWindow("button","����",WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON,0,0,0,0,hwnd,(HMENU)3,g_hInst,NULL);
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
//					// ������ ������
//					int retval = send( //blocking�Լ�
//						sock, //��ż����ڵ�
//						buf, // ���� ���ø����̼� ����
//						BUFSIZE, //���� ������ ũ��
//						0 //��κ� 0 or MSG_DONTROUTE�� MSG_OOB�� ��� ����
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
//	SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_RESETCONTENT,0,0); //����Ʈ�ڽ����� �ؽ�Ʈ�� �����ش�.
//
//	int sel = SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_GETCOUNT,0,0);
//	if(sel>0) //����Ʈ �ڽ��� ������� ��ũ�ѹٰ� �Ʒ��� �����ϰ� �ϴ� �ڵ�
//	{
//		SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_SETCURSEL,(WPARAM)(sel-1),0);
//		SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_SETCURSEL,(WPARAM)-1,0);
//	}
//}
//BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
//{
//	UINT nPos;
//	switch(iMsg)//modeless���̾�α׶� COMMAND�� �ʿ� ����.
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
	// ���� �ʱ�ȭ
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
	// ���� ����
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
	ZeroMemory(&serveraddr, sizeof(serveraddr));//���޸��� 16����Ʈ�� 0���� �ʱ�ȭ
	//setmemory�� ���
	//������ ����
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(9000);
	serveraddr.sin_addr.s_addr = inet_addr("220.68.231.160");

	int retval = connect( //���ϻ����� server�� ������ �Է��ϰ� �ٷ� connect���ش�.
		sock, //�����ڵ�
		(SOCKADDR *)&serveraddr, //���� ���� �ּҰ�
		sizeof(serveraddr) //�ּҰ� ũ��
		); // ������ ���� ��û(�����ϸ� �ڵ����� ������Ʈ, �����ּҸ� �Ҵ�)
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

	// ������ ������ ���
	while(1)
	{

		// '\n' ���� ����
		len = strlen(buf);
		if(buf[len-1] == '\n')
			buf[len-1] = '\0';
		if(strlen(buf) == 0)
			break;
		//receive�� �������� ������� �̷������Ѵ�.
		//���� �����Ͱ� ������ �𸣱⶧���� & �����Ʈ�� ������ �𸣱� ������
		//�ٸ� Ŭ���̾�Ʈ������ �������ֱ� ������ ������������ �ʿ��ϴ�.
		//�������� �ۼ��������� �̿��Ѵ�.
		//ex)�������� 100����Ʈ,�ҷ��ö��� 100����Ʈ
		//recv�� BUFSIZE�� ������ �ִ���̱⶧���� �ȵȴ�.

		//
		int retval = recvn(sock,buf,BUFSIZE,0);//recvn()�� �������� ���̸�ŭ ��Ȯ�� �������� �������̻��
		if(retval==SOCKET_ERROR || retval == 0)
			break;
		char sbuf[1024];
		string s=buf;
		switch(s[0])
		{
		case 'm':
			{
				wsprintf(sbuf,"[TCP Ŭ���̾�Ʈ]: %s",buf);
				DisplayListBox(hMainWnd,sbuf);
			}
			break;
		case 'l':
			{
				DisplayListBox(hMainWnd,"����!");
				int port=*((int*)buf+1);
				long addr = *((long*)buf+1);
				clientList[port]=addr;
				portList.push_back(port);
				UpdateList(hModelessDlg);
			}
			break;
		case 'o':
			{
				DisplayListBox(hMainWnd,"����!");
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
					ShowWindow(hModelessDlg,SW_SHOW);//SW_SHOW�� default�� �߿��ش�.
				}
				else
				{
					SetFocus(hModelessDlg); //�̹� �����찡 ����������� �����쿡 ��Ŀ���� �ְ��ϴ� �޼���
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
		// �̰����� ����� �̷����
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
		CreateWindow("button","����",WS_VISIBLE | WS_CHILD | WS_BORDER | BS_PUSHBUTTON,0,0,0,0,hwnd,(HMENU)3,g_hInst,NULL);
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


					// ������ ������
					int retval = send( //blocking�Լ�
						sock, //��ż����ڵ�
						buf, // ���� ���ø����̼� ����
						BUFSIZE, //���� ������ ũ��
						0 //��κ� 0 or MSG_DONTROUTE�� MSG_OOB�� ��� ����
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
			SetCapture(hwnd);//����������� ������ rect�� �׷�����
			left = (short)LOWORD(lParam);//���������� ���� �̻��ϰ� �׷����� ����
			top = (short)HIWORD(lParam);//�����϶� ���� lParam�� 2byte�� �ʰ��Ѵ�. 2����Ʈ�� ������Ų��.
			if(shapeType==3)
			{
				POINT pt={left,top};
				pl.AddLine(pt);
			}
			break;
		//case WM_COMMAND:
		//	switch(LOWORD(wParam)) //LOWORD==>ID , HIWORD�� 0�̴�.
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
			ReleaseCapture();//����������� ������ rect�� �׷����� but ���������� �׸��� �̻��ϰ� �׷�����.
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
	SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_RESETCONTENT,0,0); //����Ʈ�ڽ����� �ؽ�Ʈ�� �����ش�.

	//SOCKADDR_IN clientaddr;
	//int sel;

	//int len = sizeof(clientaddr);
	//for(unsigned i=0;i<clientList.size();i++)
	//{
	//	char sbuf[500];
	//	wsprintf(sbuf,"IP �ּ�=%s, ��Ʈ ��ȣ=%d",clientList[portList[i]]/*inet_ntoa(clientaddr.sin_addr)*/, portList[i]);
	//	SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_ADDSTRING,0,(LPARAM)sbuf);
	//	sel = SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_GETCOUNT,0,0);
	//	if(sel>0) //����Ʈ �ڽ��� ������� ��ũ�ѹٰ� �Ʒ��� �����ϰ� �ϴ� �ڵ�
	//	{
	//		SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_SETCURSEL,(WPARAM)(sel-1),0);
	//		SendDlgItemMessage(hDlg,IDC_CONNECTIONLIST,LB_SETCURSEL,(WPARAM)-1,0);
	//	}
	//}
}
BOOL CALLBACK DlgProc(HWND hDlg,UINT iMsg,WPARAM wParam,LPARAM lParam)
{
	switch(iMsg)//modeless���̾�α׶� COMMAND�� �ʿ� ����.
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