//#include <windows.h>
//#include<process.h>
//#include<vector>
//using namespace std;
//#define BUFSIZE 512
//HANDLE hMutex;
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
//	WPARAM wParam, LPARAM lParam);
//
//SOCKET listen_sock;
//HWND hMainWnd;
//vector<SOCKET> sockList;
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	// 윈속 초기화
//	WSADATA wsa;
//	if(WSAStartup(MAKEWORD(2,2), &wsa) != 0) 
//		return -1;
//
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
//	WndClass.lpszMenuName = NULL;		
//	WndClass.lpszClassName = "Window Class Name";	
//	RegisterClass(&WndClass);	
//	hwnd = CreateWindow("Window Class Name",
//		"GUI_TCP_Server",
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
//	return (int)msg.wParam;
//}
//void UpdateSocketList(const vector<SOCKET>&sockList)
//{
//	char buf[200];
//	wsprintf(buf,"client count : %d",sockList.size());
//	SetWindowText(hMainWnd,buf);
//}
//void DisplayListBox(HWND hwnd,const char*msg)
//{
//	SendDlgItemMessage(hwnd,1,LB_ADDSTRING,0,(LPARAM)msg);
//}
////void err_quit(HWND hParent,const char*msg)
////{
////	MessageBox(hParent,msg,"SOCKET Error",MB_OK);
////}
////void err_display(HWND hwnd,const char*msg)
////{
////	SetWindowText(hwnd,msg);
////}
//int FindSocket(const vector<SOCKET>&sockList,SOCKET client_sock)
//{
//	for(unsigned i = 0;i<sockList.size();i++)
//	{
//		if(sockList[i]==client_sock)
//			return i;
//	}
//	return -1;
//}
//void AddSocket(vector<SOCKET>&sockList,SOCKET client_sock)
//{
//	WaitForSingleObject(hMutex,INFINITE);
//
//	sockList.push_back(client_sock);
//	UpdateSocketList(sockList);
//
//	ReleaseMutex(hMutex);
//}
//void RemoveSocket(vector<SOCKET>&socket,SOCKET client_sock)
//{
//	WaitForSingleObject(hMutex,INFINITE);
//
//	int idx = FindSocket(sockList,client_sock);
//	if(idx!=-1)
//		sockList.erase(sockList.begin()+idx);
//	UpdateSocketList(sockList);
//
//	ReleaseMutex(hMutex);
//}
//BOOL InitSocket(HWND hwnd)
//{
//	listen_sock = socket(
//		AF_INET, //주소체계: 통신 영역 설정, 인터넷 영역을 사용하며 리모트 컴퓨터 사이의 통신을 사용, IPv4
//		SOCK_STREAM, //프로토콜유형: TCP/IP 기반 사용 SOCK_STREAM TCP는 이 방법 쓴다. SOCK_DGRAM은 UDP방식. 
//		0 //앞 두 인자로 프로토콜 결정이 명확하면 0사용, IPPROTO_TCP, IPPROTO_UDP
//		);
//	if(listen_sock == INVALID_SOCKET) 
//	{
//		DisplayListBox(hwnd,"socket()");   
//		return FALSE;
//	}
//
//	// bind()
//	SOCKADDR_IN serveraddr;   //구조체
//	ZeroMemory(&serveraddr, sizeof(serveraddr));
//	serveraddr.sin_family = AF_INET; //주소체계 //구조체 멤버
//	serveraddr.sin_port = htons(9000); //지역포트번호 //구조체 멤버 //대기소켓의 포트번호
//	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY/*0번지정 WHY? 이 서버가 어디서 실행하든 동작하겠다.*/); //지역IP 주소 //구조체 멤버
//	int retval = bind(listen_sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
//	if(retval == SOCKET_ERROR) 
//	{
//		DisplayListBox(hwnd,"bind()");
//		return FALSE;
//	}
//
//
//
//	// listen()
//	retval = listen(
//		listen_sock, 
//		SOMAXCONN //접속대기 큐의 크기
//		); // TCP 상태를 LISTENING 변경
//	if(retval == SOCKET_ERROR) 
//	{
//		DisplayListBox(hwnd,"listen()");
//		return FALSE;
//	}
//
//	return TRUE;
//}
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
//unsigned int _stdcall ClientThread(void* pParam)
//{
//	int retval;
//	char buf[BUFSIZE];
//	SOCKET client_sock = (SOCKET)pParam;
//	SOCKADDR_IN clientaddr;
//
//	// 클라이언트와 데이터 통신
//	while(1)
//	{
//		// 데이터 받기
//		retval = recvn( //retval 은 보내온 바이트만큼의 값을 가진다.   //os에서 받은 데이터의 내용물을 buf에 넣어주는 역활.
//			client_sock, //통신소켓핸들
//			buf, //받을 애플리케이션 버퍼
//			BUFSIZE, //수신 버퍼의 최대 크기
//			0 //대부분 0 or MSG_PEEK와 MSG_OOB를 사용 가능 //요즘은 무조건 0. 노 의문
//			);
//		if(retval == SOCKET_ERROR){
//			DisplayListBox(hMainWnd,"recv()");
//			break;
//		}
//		else if(retval == 0){ //retval이 0이면 정상적이 종료를 말한다.
//			break;
//		}
//		else{
//			// 받은 데이터 출력
//			//buf[retval] = '\0';   //받은 문자의 마지막을 null넣어서 출력.
//			char sbuf[500];
//			int len = sizeof(clientaddr);
//			getpeername(client_sock,(SOCKADDR*)&clientaddr,&len);
//			wsprintf(sbuf,"IP 주소=%s, 포트 번호=%d, [TCP 서버] 클라이언트 데이터 : %s",inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port) ,buf);
//			DisplayListBox(hMainWnd,sbuf);
//
//			//접속 종료와 관계가있으므로 동기화해준다.
//			WaitForSingleObject(hMutex,INFINITE);
//
//			for(unsigned i=0;i<sockList.size();i++)
//			{
//				retval = send(sockList[i], sbuf, BUFSIZE, 0);
//				if( retval == SOCKET_ERROR || retval == 0)
//					break;
//			}
//			ReleaseMutex(hMutex);
//		}
//	}
//	// closesocket()
//	
//	int len = sizeof(clientaddr);
//	getpeername(client_sock,(SOCKADDR*)&clientaddr,&len);
//
//	char sbuf[500];
//	wsprintf(sbuf,"-[TCP 서버] 클라이언트 종료: IP 주소=%s, 포트 번호=%d",
//		inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
//	DisplayListBox(hMainWnd,sbuf);
//
//
//	RemoveSocket(sockList,client_sock);
//
//	closesocket(client_sock);
//
//	return 0;
//}
//unsigned int _stdcall ListenThread(void* pParam)
//{
//	// 데이터 통신에 사용할 변수
//	HWND hwnd = (HWND)pParam;
//	SOCKET client_sock;
//	SOCKADDR_IN clientaddr;
//	int addrlen;
//	//char buf[BUFSIZE];
//
//	while(1)
//	{
//		// accept()
//		addrlen = sizeof(clientaddr);
//		client_sock = accept(
//			listen_sock, //대기 소켓
//			(SOCKADDR *)&clientaddr, //클라이언트의 정보 out param  //접속한 클라이언트의 정보를 가져올수 있다.
//			&addrlen //주소구조체형식의크기, in(크기지정), out(초기화한크기반환) param
//			); //통신소켓 생성: 원격 IP, 원격 포트 결정
//		if(client_sock == INVALID_SOCKET){
//			DisplayListBox(hwnd,"accept()");
//			continue;
//		}
//		char buf[500];
//		wsprintf(buf,"-[TCP 서버] 클라이언트 접속: IP 주소=%s, 포트 번호=%d",
//			inet_ntoa(clientaddr.sin_addr), //문자열로 IP주소 변환
//			ntohs(clientaddr.sin_port) // 포트번호 network to host
//			);
//		DisplayListBox(hwnd,buf);
//
//
//		AddSocket(sockList,client_sock);
//
//		unsigned int id;
//		_beginthreadex(NULL, 0, ClientThread, (void*)client_sock, 0, &id);
//	}
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
//	WPARAM wParam, LPARAM lParam)
//{
//	HDC         hdc;
//	PAINTSTRUCT ps;
//	unsigned int id;
//
//	switch (iMsg)
//	{
//	case WM_CREATE:
//		hMutex = CreateMutex(NULL,FALSE,NULL);
//		hMainWnd = hwnd;
//		CreateWindow("listbox",NULL,WS_VISIBLE | WS_BORDER | WS_CHILD,0,0,0,0,hwnd,(HMENU)1,((LPCREATESTRUCT)lParam)->hInstance,NULL);
//		if(!InitSocket(hwnd))
//			return -1;
//		CloseHandle((HANDLE)_beginthreadex(NULL,0,ListenThread,(void*)hwnd,0,&id));
//		break; 
//	case WM_SIZE:
//		MoveWindow(GetDlgItem(hwnd,1),0,0,LOWORD(lParam),HIWORD(lParam),TRUE);
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		// 이곳에서 출력이 이루어짐
//		EndPaint(hwnd, &ps);
//		break; 
//	case WM_DESTROY:
//		CloseHandle(hMutex);
//		PostQuitMessage(0);
//		break; 
//	}
//	return DefWindowProc(hwnd, iMsg, wParam, lParam);
//}

#include <windows.h>
#include<process.h>
#include<vector>
using namespace std;
#define BUFSIZE 512
HANDLE hMutex;
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
	WPARAM wParam, LPARAM lParam);

SOCKET listen_sock;
HWND hMainWnd;
vector<SOCKET> sockList;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	// 윈속 초기화
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
	// 윈속 종료
	WSACleanup();
	return (int)msg.wParam;
}
void UpdateSocketList(const vector<SOCKET>&sockList)
{
	char buf[200];
	wsprintf(buf,"client count : %d",sockList.size());
	SetWindowText(hMainWnd,buf);
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
int FindSocket(const vector<SOCKET>&sockList,SOCKET client_sock)
{
	for(unsigned i = 0;i<sockList.size();i++)
	{
		if(sockList[i]==client_sock)
			return i;
	}
	return -1;
}
void AddSocket(vector<SOCKET>&sockList,SOCKET client_sock)
{
	WaitForSingleObject(hMutex,INFINITE);

	sockList.push_back(client_sock);
	UpdateSocketList(sockList);

	ReleaseMutex(hMutex);
}
void RemoveSocket(vector<SOCKET>&socket,SOCKET client_sock)
{
	WaitForSingleObject(hMutex,INFINITE);

	int idx = FindSocket(sockList,client_sock);
	if(idx!=-1)
		sockList.erase(sockList.begin()+idx);
	UpdateSocketList(sockList);

	ReleaseMutex(hMutex);
}
BOOL InitSocket(HWND hwnd)
{
	listen_sock = socket(
		AF_INET, //주소체계: 통신 영역 설정, 인터넷 영역을 사용하며 리모트 컴퓨터 사이의 통신을 사용, IPv4
		SOCK_STREAM, //프로토콜유형: TCP/IP 기반 사용 SOCK_STREAM TCP는 이 방법 쓴다. SOCK_DGRAM은 UDP방식. 
		0 //앞 두 인자로 프로토콜 결정이 명확하면 0사용, IPPROTO_TCP, IPPROTO_UDP
		);
	if(listen_sock == INVALID_SOCKET) 
	{
		DisplayListBox(hwnd,"socket()");   
		return FALSE;
	}

	// bind()
	SOCKADDR_IN serveraddr;   //구조체
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET; //주소체계 //구조체 멤버
	serveraddr.sin_port = htons(9000); //지역포트번호 //구조체 멤버 //대기소켓의 포트번호
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY/*0번지정 WHY? 이 서버가 어디서 실행하든 동작하겠다.*/); //지역IP 주소 //구조체 멤버
	int retval = bind(listen_sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if(retval == SOCKET_ERROR) 
	{
		DisplayListBox(hwnd,"bind()");
		return FALSE;
	}



	// listen()
	retval = listen(
		listen_sock, 
		SOMAXCONN //접속대기 큐의 크기
		); // TCP 상태를 LISTENING 변경
	if(retval == SOCKET_ERROR) 
	{
		DisplayListBox(hwnd,"listen()");
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
unsigned int _stdcall ClientThread(void* pParam)
{
	int retval;
	char buf[BUFSIZE];
	SOCKET client_sock = (SOCKET)pParam;
	SOCKADDR_IN clientaddr;

	// 클라이언트와 데이터 통신
	while(1)
	{
		// 데이터 받기
		retval = recvn( //retval 은 보내온 바이트만큼의 값을 가진다.   //os에서 받은 데이터의 내용물을 buf에 넣어주는 역활.
			client_sock, //통신소켓핸들
			buf, //받을 애플리케이션 버퍼
			BUFSIZE, //수신 버퍼의 최대 크기
			0 //대부분 0 or MSG_PEEK와 MSG_OOB를 사용 가능 //요즘은 무조건 0. 노 의문
			);
		//recvn()함수는 사용자 정의함수로 고정길이로 데이터를 주고받을때 사용한다.

		if(retval == SOCKET_ERROR){
			DisplayListBox(hMainWnd,"recv()");
			break;
		}
		else if(retval == 0){ //retval이 0이면 정상적이 종료를 말한다.
			break;
		}
		else{
			// 받은 데이터 출력
			//buf[retval] = '\0';   //받은 문자의 마지막을 null넣어서 출력.
			char sbuf[500];
			int len = sizeof(clientaddr);
			getpeername(client_sock,(SOCKADDR*)&clientaddr,&len);
			wsprintf(sbuf,"m-IP 주소=%s, 포트 번호=%d, [TCP 서버] 클라이언트 데이터 : %s",inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port) ,buf);
			DisplayListBox(hMainWnd,sbuf);

			//접속 종료와 관계가있으므로 동기화해준다.
			WaitForSingleObject(hMutex,INFINITE);

			for(unsigned i=0;i<sockList.size();i++)
			{
				retval = send(sockList[i], sbuf, BUFSIZE, 0);
				if( retval == SOCKET_ERROR || retval == 0)
					break;
			}
			ReleaseMutex(hMutex);
		}
	}
	// closesocket()
	
	int len = sizeof(clientaddr);
	getpeername(client_sock,(SOCKADDR*)&clientaddr,&len);

	char sbuf[500];
	wsprintf(sbuf,"[TCP 서버] 클라이언트 종료: IP 주소=%s, 포트 번호=%d",
		inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
	DisplayListBox(hMainWnd,sbuf);

	WaitForSingleObject(hMutex,INFINITE);

	for(unsigned i=0;i<sockList.size();i++)
	{
		char lbuf[BUFSIZE];
		lbuf[0]='o';

		int port=ntohs(clientaddr.sin_port);
		*((int*)lbuf+1)=port;

		long addr = inet_addr(inet_ntoa(clientaddr.sin_addr));
		*((long*)lbuf+1)=addr;

		int retval = send(sockList[i], lbuf, BUFSIZE, 0);

		/*if( retval == SOCKET_ERROR || retval == 0)
			break;*/
	}
	ReleaseMutex(hMutex);


	RemoveSocket(sockList,client_sock);

	closesocket(client_sock);

	return 0;
}
unsigned int _stdcall ListenThread(void* pParam)
{
	// 데이터 통신에 사용할 변수
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
			listen_sock, //대기 소켓
			(SOCKADDR *)&clientaddr, //클라이언트의 정보 out param  //접속한 클라이언트의 정보를 가져올수 있다.
			&addrlen //주소구조체형식의크기, in(크기지정), out(초기화한크기반환) param
			); //통신소켓 생성: 원격 IP, 원격 포트 결정
		if(client_sock == INVALID_SOCKET){
			DisplayListBox(hwnd,"accept()");
			continue;
		}
		char buf[500];
		wsprintf(buf,"[TCP 서버] 클라이언트 접속: IP 주소=%s, 포트 번호=%d",
			inet_ntoa(clientaddr.sin_addr), //문자열로 IP주소 변환
			ntohs(clientaddr.sin_port) // 포트번호 network to host
			);
		DisplayListBox(hwnd,buf);

		WaitForSingleObject(hMutex,INFINITE);

		for(unsigned i=0;i<sockList.size();i++)
		{
			char lbuf[BUFSIZE];
			lbuf[0]='l';
			
			int port=ntohs(clientaddr.sin_port);
			*((int*)lbuf+1)=port;
			
			long addr = inet_addr(inet_ntoa(clientaddr.sin_addr));
			*((long*)lbuf+1)=addr;


			int retval = send(sockList[i], lbuf, BUFSIZE, 0);

			if( retval == SOCKET_ERROR || retval == 0)
				break;
		}
		ReleaseMutex(hMutex);

		AddSocket(sockList,client_sock);

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
		hMutex = CreateMutex(NULL,FALSE,NULL);
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