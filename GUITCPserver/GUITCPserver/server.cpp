#include <windows.h>
#include<process.h>
#define BUFSIZE 512
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
	WPARAM wParam, LPARAM lParam);

SOCKET listen_sock;
HWND hMainWnd;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpszCmdLine, int nCmdShow)
{
	// ���� �ʱ�ȭ
	WSADATA wsa;
	if(WSAStartup(MAKEWORD(2,2), &wsa) != 0) 
		return -1;


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
	hwnd = CreateWindow("Window Class Name",
		"GUI_TCP_Server",
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
	SendDlgItemMessage(hwnd,1,LB_ADDSTRING,0,(LPARAM)msg);
}
//void err_quit(HWND hParent,const char*msg)
//{
//	MessageBox(hParent,msg,"SOCKET Error",MB_OK);
//}
//void err_display(HWND hwnd,const char*msg)
//{
//	SetWindowText(hwnd,msg);
//}
BOOL InitSocket(HWND hwnd)
{
	listen_sock = socket(
		AF_INET, //�ּ�ü��: ��� ���� ����, ���ͳ� ������ ����ϸ� ����Ʈ ��ǻ�� ������ ����� ���, IPv4
		SOCK_STREAM, //������������: TCP/IP ��� ���      SOCK_STREAM TCP�� �� ��� ����. SOCK_DGRAM�� UDP���. 
		0 //�� �� ���ڷ� �������� ������ ��Ȯ�ϸ� 0���, IPPROTO_TCP, IPPROTO_UDP
		);
	if(listen_sock == INVALID_SOCKET) 
	{
		DisplayListBox(hwnd,"socket()");   
		return FALSE;
	}

	// bind()
	SOCKADDR_IN serveraddr;   //����ü
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET; //�ּ�ü�� //����ü ���
	serveraddr.sin_port = htons(9000); //������Ʈ��ȣ //����ü ��� //�������� ��Ʈ��ȣ
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY/*0������ WHY? �� ������ ��� �����ϵ� �����ϰڴ�.*/); //����IP �ּ� //����ü ���
	int retval = bind(listen_sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if(retval == SOCKET_ERROR) 
	{
		DisplayListBox(hwnd,"bind()");
		return FALSE;
	}



	// listen()
	retval = listen(
		listen_sock, 
		SOMAXCONN //���Ӵ�� ť�� ũ��
		); // TCP ���¸� LISTENING ����
	if(retval == SOCKET_ERROR) 
	{
		DisplayListBox(hwnd,"listen()");
		return FALSE;
	}

	return TRUE;
}
unsigned int _stdcall ClientThread(void* pParam)
{
   int retval;
   char buf[BUFSIZE];
   SOCKET client_sock = (SOCKET)pParam;

   // Ŭ���̾�Ʈ�� ������ ���
   while(1)
   {
      // ������ �ޱ�
      retval = recv( //retval �� ������ ����Ʈ��ŭ�� ���� ������.   //os���� ���� �������� ���빰�� buf�� �־��ִ� ��Ȱ.
         client_sock, //��ż����ڵ�
         buf, //���� ���ø����̼� ����
         BUFSIZE, //���� ������ �ִ� ũ��
         0 //��κ� 0 or MSG_PEEK�� MSG_OOB�� ��� ���� //������ ������ 0. �� �ǹ�
         );
      if(retval == SOCKET_ERROR){
         DisplayListBox(hMainWnd,"recv()");
         break;
      }
      else if(retval == 0){ //retval�� 0�̸� �������� ���Ḧ ���Ѵ�.
         break;
      }
      else{
         // ���� ������ ���
         buf[retval] = '\0';   //���� ������ �������� null�־ ���.
		 char sbuf[500];
         wsprintf(sbuf,"[TCP ����] Ŭ���̾�Ʈ ������ : %s\n", buf);
		 DisplayListBox(hMainWnd,sbuf);


         retval = send(client_sock, buf, retval, 0);
         if( retval == SOCKET_ERROR || retval == 0)
            break;
      }
   }
   // closesocket()
   SOCKADDR_IN clientaddr;
   int len = sizeof(clientaddr);
   getpeername(client_sock,(SOCKADDR*)&clientaddr,&len);

   char sbuf[500];
   wsprintf(sbuf,"[TCP ����] Ŭ���̾�Ʈ ����: IP �ּ�=%s, ��Ʈ ��ȣ=%d",
      inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
   DisplayListBox(hMainWnd,sbuf);

   closesocket(client_sock);

   return 0;
}
unsigned int _stdcall ListenThread(void* pParam)
{
	// ������ ��ſ� ����� ����
	HWND hwnd = (HWND)pParam;
	SOCKET client_sock;
	SOCKADDR_IN clientaddr;
	int addrlen;
	//char buf[BUFSIZE];

	while(1)
	{
		// accept()
		addrlen = sizeof(clientaddr);
		client_sock = accept(
			listen_sock, //��� ����
			(SOCKADDR *)&clientaddr, //Ŭ���̾�Ʈ�� ���� out param  //������ Ŭ���̾�Ʈ�� ������ �����ü� �ִ�.
			&addrlen //�ּұ���ü������ũ��, in(ũ������), out(�ʱ�ȭ��ũ���ȯ) param
			); //��ż��� ����: ���� IP, ���� ��Ʈ ����
		if(client_sock == INVALID_SOCKET){
			DisplayListBox(hwnd,"accept()");
			continue;
		}
		char buf[500];
		wsprintf(buf,"[TCP ����] Ŭ���̾�Ʈ ����: IP �ּ�=%s, ��Ʈ ��ȣ=%d",
			inet_ntoa(clientaddr.sin_addr), //���ڿ��� IP�ּ� ��ȯ
			ntohs(clientaddr.sin_port) // ��Ʈ��ȣ network to host
			);
		DisplayListBox(hwnd,buf);
		unsigned int id;
		_beginthreadex(NULL, 0, ClientThread, (void*)client_sock, 0, &id);
	}
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{
	HDC         hdc;
	PAINTSTRUCT ps;
	unsigned int id;

	switch (iMsg)
	{
	case WM_CREATE:
		hMainWnd = hwnd;
		CreateWindow("listbox",NULL,WS_VISIBLE | WS_BORDER | WS_CHILD,0,0,0,0,hwnd,(HMENU)1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
		if(!InitSocket(hwnd))
			return -1;
		CloseHandle((HANDLE)_beginthreadex(NULL,0,ListenThread,(void*)hwnd,0,&id));
		break; 
	case WM_SIZE:
		MoveWindow(GetDlgItem(hwnd,1),0,0,LOWORD(lParam),HIWORD(lParam),TRUE);
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