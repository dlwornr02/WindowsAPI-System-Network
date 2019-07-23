//������ API ���� ������� �ҽ�
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

// ���ϵ��� ��û�� ó���Ѵ�.
DWORD WINAPI PipeThread(LPVOID temp)
{
	HANDLE hPipe=(HANDLE)temp;
	TCHAR szInput[255], szOutput[255];
	DWORD dwRead, dwWritten;
	BOOL bSuc;

	// ��û�� �ް� ������ �� �� ������ ������.
	for (;;) {
		bSuc=ReadFile(hPipe,szInput,255,&dwRead,NULL);
		if ((bSuc==FALSE) || (dwRead==0)) {
			break;
		}

		if (lstrcmp(szInput,"one")==0) lstrcpy(szOutput,"�ϳ�");
		if (lstrcmp(szInput,"two")==0) lstrcpy(szOutput,"��");
		if (lstrcmp(szInput,"three")==0) lstrcpy(szOutput,"��");
		if (lstrcmp(szInput,"four")==0) lstrcpy(szOutput,"��");
		if (lstrcmp(szInput,"five")==0) lstrcpy(szOutput,"�ټ�");

		bSuc=WriteFile(hPipe,szOutput,lstrlen(szOutput)+1,&dwWritten,NULL);
		if ((bSuc==FALSE) || (dwWritten==0)) {
			break;
		}
	}

	// ������ ������������������������������
	FlushFileBuffers(hPipe); // �������� ��� ���۰� �� ������ ���
	DisconnectNamedPipe(hPipe); // ������ ������ ����� Ŭ���̾�Ʈ�� ������ �ν��Ѵ�.
	CloseHandle(hPipe); // ������ �ν��Ͻ��� �ݴ´�.
	return 0;
}

// Ŭ���̾�Ʈ �ϳ��� �ϳ����� �����带 �����.����
DWORD WINAPI MainThread(LPVOID temp)
{
	HANDLE hPipe;
	DWORD ThreadID;
	BOOL bCon;

	for (;;) {
		// ������ ����
		hPipe=CreateNamedPipe(
            "\\\\.\\pipe\\MultiPipe", //������ �̸�
			//\\�� ������ϰ� ��ǻ�ͳ� ip�ּҸ� ����.
            PIPE_ACCESS_DUPLEX, // Read, Write ��δ� �Ǵ°ɷ� ���ڴ�.
			PIPE_TYPE_BYTE, //����Ʈ ���� ����� or PIPE_TYPE_MESSAGE(������ ���̳ʸ�, �ؽ�Ʈ ���� ����)
            3, // �ִ� �ν��Ͻ� 3��(�ִ� Ŭ���̾�Ʈ�� ����)Multipipe��� �̸����� ������ִ� Ŭ���̾�Ʈ�� 3���� ����
            4096, //��¹��� ũ��(�����һ� �ý����� ũ�� ����)
            4096, //�Է¹��� ũ��(0 ����Ʈ ũ��)
            10000, //WaitNamedPipe�Լ��� ���� �ð�(�и������� ����)�� �������� �����Ѵ�. Ŭ���̾�Ʈ�� NMPWAIT_USE_DEFAULT_WAIT�� Ÿ�Ӿƿ��� �����Ѵ�. 
            NULL //���ȼӼ�,��ӿ��θ� ����
            );

		// ���ϵ� ���. ���ӵǸ� ���ϵ� ��û ó�� ������ ����
		bCon=ConnectNamedPipe(hPipe,NULL);
		if ((bCon==FALSE) && (GetLastError() == ERROR_PIPE_CONNECTED)) //GetLastError()�� ����ó���� ��� �ý����Լ��� ȣ���ϸ� �����ڵ带 �߻���Ų��.
																	   //������ ���� �ڵ�� �����ϴ�. ���Ҹ���..?
			bCon=TRUE;
		if (bCon==TRUE)
		{
			CloseHandle(CreateThread(NULL,0,PipeThread,(LPVOID)hPipe,0,&ThreadID)); //������ �����带 �����Ų��.
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
	TCHAR *Mes="Ŭ���̾�Ʈ�κ����� ������ ������̸� ��û�� ó���մϴ�";
	
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
