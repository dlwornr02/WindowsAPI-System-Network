//制亀酔 API 舛差 沿雌莫煽 社什
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

// 託析球税 推短聖 坦軒廃陥.
DWORD WINAPI PipeThread(LPVOID temp)
{
	HANDLE hPipe=(HANDLE)temp;
	TCHAR szInput[255], szOutput[255];
	DWORD dwRead, dwWritten;
	BOOL bSuc;

	// 推短聖 閤壱 尻至聖 廃 板 誓岩聖 左浬陥.
	for (;;) {
		bSuc=ReadFile(hPipe,szInput,255,&dwRead,NULL);
		if ((bSuc==FALSE) || (dwRead==0)) {
			break;
		}

		if (lstrcmp(szInput,"one")==0) lstrcpy(szOutput,"馬蟹");
		if (lstrcmp(szInput,"two")==0) lstrcpy(szOutput,"却");
		if (lstrcmp(szInput,"three")==0) lstrcpy(szOutput,"実");
		if (lstrcmp(szInput,"four")==0) lstrcpy(szOutput,"掛");
		if (lstrcmp(szInput,"five")==0) lstrcpy(szOutput,"陥叱");

		bSuc=WriteFile(hPipe,szOutput,lstrlen(szOutput)+1,&dwWritten,NULL);
		if ((bSuc==FALSE) || (dwWritten==0)) {
			break;
		}
	}

	// 督戚覗 背薦ししししししししししししし
	FlushFileBuffers(hPipe); // 督戚覗税 窒径 獄遁亜 柵 凶猿走 企奄
	DisconnectNamedPipe(hPipe); // 督戚覗 尻衣戚 快奄壱 適虞戚情闘亜 拭君研 昔縦廃陥.
	CloseHandle(hPipe); // 督戚覗 昔什渡什研 丸澗陥.
	return 0;
}

// 適虞戚情闘 馬蟹雁 馬蟹梢税 什傾球研 幻窮陥.しし
DWORD WINAPI MainThread(LPVOID temp)
{
	HANDLE hPipe;
	DWORD ThreadID;
	BOOL bCon;

	for (;;) {
		// 督戚覗 持失
		hPipe=CreateNamedPipe(
            "\\\\.\\pipe\\MultiPipe", //督戚覗 戚硯
			//\\澗 伽潤醤馬壱 陳濃斗蟹 ip爽社研 彰陥.
            PIPE_ACCESS_DUPLEX, // Read, Write 乞砧陥 鞠澗杏稽 伸畏陥.
			PIPE_TYPE_BYTE, //郊戚闘 舘是 脊窒径 or PIPE_TYPE_MESSAGE(督析税 郊戚格軒, 努什闘 乞球人 旭陥)
            3, // 置企 昔什渡什 3鯵(置企 適虞戚情闘税 鯵呪)Multipipe虞澗 戚硯生稽 幻級呪赤澗 適虞戚情闘研 3鯵稽 舛税
            4096, //窒径獄遁 滴奄(走舛拝屍 獣什奴戚 滴奄 竺舛)
            4096, //脊径獄遁 滴奄(0 巨虹闘 滴奄)
            10000, //WaitNamedPipe敗呪税 幻戟 獣娃(腔軒室珍球 舘是)聖 辞獄拭辞 獣舌廃陥. 適虞戚情闘澗 NMPWAIT_USE_DEFAULT_WAIT稽 展績焼数聖 走舛廃陥. 
            NULL //左照紗失,雌紗食採研 衣舛
            );

		// 託析球 企奄. 羨紗鞠檎 託析球 推短 坦軒 什傾球 持失
		bCon=ConnectNamedPipe(hPipe,NULL);
		if ((bCon==FALSE) && (GetLastError() == ERROR_PIPE_CONNECTED)) //GetLastError()澗 森須坦軒亜 蒸嬢辞 獣什奴敗呪研 硲窒馬檎 神嫌坪球研 降持獣轍陥.
																	   //疹劾拭 床揮 坪球虞辞 差説馬陥. 杭社軒走..?
			bCon=TRUE;
		if (bCon==TRUE)
		{
			CloseHandle(CreateThread(NULL,0,PipeThread,(LPVOID)hPipe,0,&ThreadID)); //督戚覗 什傾球研 叔楳獣轍陥.
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
	TCHAR *Mes="適虞戚情闘稽採斗税 羨紗聖 企奄掻戚悟 推短聖 坦軒杯艦陥";
	
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
