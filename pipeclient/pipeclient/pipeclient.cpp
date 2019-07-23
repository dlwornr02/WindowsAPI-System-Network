#include <windows.h>
//�����̾�Ʈ�� �ϳ��� �����带 ���´�.
//��û���ϰ� ������ �޴� �������� �۾��� �����ؾ� �ϹǷ�, ����ڰ� �ϴ��۾����� ������ �۾�
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass=TEXT("MultiPipe2");

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
		CW_USEDEFAULT,CW_USEDEFAULT,500,500,
		NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow);

	while (GetMessage(&Message,NULL,0,0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}


TCHAR Mes[255]="������ ������ ������� �ֽʽÿ�";
#define random(i) (rand() % i)

// ������ ��û�� ���� ����� �޾ƿ´�.
DWORD WINAPI MainThread(LPVOID temp) //���α׷��� �����Ҷ����� ����ִ�.
{
	HANDLE hPipe;
	TCHAR szInput[255], szOutput[255];
	DWORD dwRead, dwWritten;
	TCHAR arInput[5][10]={"one","two","three","four","five"};
	BOOL bSuc;

	// ������ �������� ������ ������ ���� ����Ѵ�.
	for (;;) {  //���ѷ����� �����ִ�.
		if (WaitNamedPipe("\\\\.\\pipe\\MultiPipe",NMPWAIT_USE_DEFAULT_WAIT)==TRUE) { //��Ƽ�������� �����ϰڴٴ� ��,
			hPipe=CreateFile("\\\\.\\pipe\\MultiPipe",GENERIC_READ | GENERIC_WRITE,
				0,NULL,OPEN_EXISTING,0,NULL); //������ ������ ����
			if (hPipe!=INVALID_HANDLE_VALUE) //��ȿ�� �ڵ鰪�� �ƴϸ�
				break;
		}
	}
	for (;;) { //�����͸� �ְ�޴� ���� �Ѵ�.
		// one~five�� �ϳ��� ������ �����Ѵ�.
		lstrcpy(szInput,arInput[random(5)]); 

		// ��û�� ���� �� ������ �޴´�.
		bSuc=WriteFile(hPipe,szInput,lstrlen(szInput)+1,&dwWritten,NULL);
		if ((bSuc==FALSE) || (dwWritten==0))
			break;
		ReadFile(hPipe,szOutput,255,&dwRead,NULL);

		// ������ ȭ������ ����Ѵ�.
		wsprintf(Mes,"%s=%s",szInput,szOutput);
		InvalidateRect(hWndMain,NULL,TRUE);
		UpdateWindow(hWndMain);

		Sleep(500);
	}

	// ������ ���� ����� ���
	lstrcpy(Mes,"������ ����Ǿ����ϴ�.");
	InvalidateRect(hWndMain,NULL,TRUE);

	// �������� �����ϰ� ����� ���� �����쿡 ����Ѵ�.
	CloseHandle(hPipe);
	
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	DWORD ThreadID;

	switch (iMessage) {
	case WM_CREATE:
		hWndMain=hWnd;
		srand(GetTickCount());
		CloseHandle(CreateThread(NULL,0,MainThread,NULL,0,&ThreadID)); //���ν������ ���ѹ� ȣ��
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
//�����ΰ� �ϳ��̹Ƿ� ���������� Ŭ���̾�Ʈ��� ��ȭ�� �� �ִ� �����峪 �ٸ������ �̿��Ѵ�.