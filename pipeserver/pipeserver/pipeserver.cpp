//윈도우 API 정복 김상형저 소스
#include <windows.h>
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass=TEXT("MultiPipe1");

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst=hInstance;

	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance=hInstance;
	WndClass.lpfnWndProc=WndProc;
	WndClass.lpszClassName=lpszClass;
	WndClass.lpszMenuName=NULL;
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd=CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW,
		100,100,500,500,
		NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow);

	while (GetMessage(&Message,NULL,0,0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

// 차일드의 요청을 처리한다.
DWORD WINAPI PipeThread(LPVOID temp)
{
	HANDLE hPipe=(HANDLE)temp;
	TCHAR szInput[255], szOutput[255];
	DWORD dwRead, dwWritten;
	BOOL bSuc;

	// 요청을 받고 연산을 한 후 응답을 보낸다.
	for (;;) {
		bSuc=ReadFile(hPipe,szInput,255,&dwRead,NULL);
		if ((bSuc==FALSE) || (dwRead==0)) {
			break;
		}

		if (lstrcmp(szInput,"one")==0) lstrcpy(szOutput,"하나");
		if (lstrcmp(szInput,"two")==0) lstrcpy(szOutput,"둘");
		if (lstrcmp(szInput,"three")==0) lstrcpy(szOutput,"셋");
		if (lstrcmp(szInput,"four")==0) lstrcpy(szOutput,"넷");
		if (lstrcmp(szInput,"five")==0) lstrcpy(szOutput,"다섯");

		bSuc=WriteFile(hPipe,szOutput,lstrlen(szOutput)+1,&dwWritten,NULL);
		if ((bSuc==FALSE) || (dwWritten==0)) {
			break;
		}
	}

	// 파이프 해제ㅇㅇㅇㅇㅇㅇㅇㅇㅇㅇㅇㅇㅇ
	FlushFileBuffers(hPipe); // 파이프의 출력 버퍼가 빌 때까지 대기
	DisconnectNamedPipe(hPipe); // 파이프 연결이 끊기고 클라이언트가 에러를 인식한다.
	CloseHandle(hPipe); // 파이프 인스턴스를 닫는다.
	return 0;
}

// 클라이언트 하나당 하나씩의 스레드를 만든다.ㅇㅇ
DWORD WINAPI MainThread(LPVOID temp)
{
	HANDLE hPipe;
	DWORD ThreadID;
	BOOL bCon;

	for (;;) {
		// 파이프 생성
		hPipe=CreateNamedPipe(
            "\\\\.\\pipe\\MultiPipe", //파이프 이름
			//\\는 꼭써야하고 컴퓨터나 ip주소를 쓴다.
            PIPE_ACCESS_DUPLEX, // Read, Write 모두다 되는걸로 열겠다.
			PIPE_TYPE_BYTE, //바이트 단위 입출력 or PIPE_TYPE_MESSAGE(파일의 바이너리, 텍스트 모드와 같다)
            3, // 최대 인스턴스 3개(최대 클라이언트의 개수)Multipipe라는 이름으로 만들수있는 클라이언트를 3개로 정의
            4096, //출력버퍼 크기(지정할뿐 시스템이 크기 설정)
            4096, //입력버퍼 크기(0 디폴트 크기)
            10000, //WaitNamedPipe함수의 만료 시간(밀리세컨드 단위)을 서버에서 시장한다. 클라이언트는 NMPWAIT_USE_DEFAULT_WAIT로 타임아웃을 지정한다. 
            NULL //보안속성,상속여부를 결정
            );

		// 차일드 대기. 접속되면 차일드 요청 처리 스레드 생성
		bCon=ConnectNamedPipe(hPipe,NULL);
		if ((bCon==FALSE) && (GetLastError() == ERROR_PIPE_CONNECTED)) //GetLastError()는 예외처리가 없어서 시스템함수를 호출하면 오류코드를 발생시킨다.
																	   //옛날에 쓰던 코드라서 복잡하다. 뭔소리지..?
			bCon=TRUE;
		if (bCon==TRUE)
		{
			CloseHandle(CreateThread(NULL,0,PipeThread,(LPVOID)hPipe,0,&ThreadID)); //파이프 스레드를 실행시킨다.
		}
		else
		{
			CloseHandle(hPipe);
		}
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	DWORD ThreadID;
	TCHAR *Mes="클라이언트로부터의 접속을 대기중이며 요청을 처리합니다";
	
	switch (iMessage) {
	case WM_CREATE:
		CloseHandle(CreateThread(NULL,0,MainThread,NULL,0,&ThreadID));
		return 0;
	case WM_PAINT:
		hdc=BeginPaint(hWnd, &ps);
		TextOut(hdc,50,50,Mes,lstrlen(Mes));
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}
