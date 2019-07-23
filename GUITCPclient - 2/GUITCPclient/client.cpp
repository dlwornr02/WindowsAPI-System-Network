#include <windows.h>
#include<process.h>

#define BUFSIZE 512

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
						 WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK TopProc(HWND hwnd, UINT iMsg, 
						 WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK BottomProc(HWND hwnd, UINT iMsg, 
						 WPARAM wParam, LPARAM lParam);
HINSTANCE g_hInst;
SOCKET sock;
HWND hMainWnd;
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
	WndClass.lpszMenuName = NULL;		
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
		wsprintf(sbuf,"[TCP Ŭ���̾�Ʈ] ���������� : %s",buf);
		DisplayListBox(hMainWnd,sbuf);
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
    case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		// �̰����� ����� �̷����
		EndPaint(hwnd, &ps);
		break; 
    case WM_DESTROY:
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
	case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{

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
	switch (iMsg)
	{
    case WM_CREATE:
		break; 
	case WM_PAINT:
		hdc = BeginPaint(hwnd,&ps);
		GetClientRect(hwnd,&rt);
		Rectangle(hdc,rt.left,rt.top,rt.right,rt.bottom);
		EndPaint(hwnd,&ps);
		break;
	}

	return DefWindowProc(hwnd, iMsg, wParam, lParam);

}