#include <stdio.h>
#include <windows.h>

struct TParam
{
	HWND hwnd;
	RECT rt;
};

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, 
                   WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
               LPSTR lpszCmdLine, int nCmdShow)
{
   HWND     hwnd;
   MSG     msg;
   WNDCLASS WndClass;   
   WndClass.style = CS_HREDRAW | CS_VREDRAW;
   WndClass.lpfnWndProc = WndProc;      
   WndClass.cbClsExtra   = 0;      
   WndClass.cbWndExtra   = 0;      
   WndClass.hInstance = hInstance;      
   WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
   WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);   
   WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   
   WndClass.lpszMenuName = NULL;      
   WndClass.lpszClassName = "Window Class Name";   
   RegisterClass(&WndClass);   
   hwnd = CreateWindow("Window Class Name",
      "Window Title Name",
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

DWORD _stdcall TR(LPVOID pParam)
{
	TParam tp=*(TParam*)pParam;
	delete (TParam*)pParam;
	HDC hdc=GetDC(tp.hwnd);

	for(int i=0 ; i< 100 ; i+=5)
	{

		while(1)
		{
			HBRUSH newBrush = CreateSolidBrush(RGB(255, 0, 0));
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
			Rectangle(hdc,tp.rt.left,tp.rt.top,tp.rt.right,tp.rt.bottom);
			SelectObject(hdc, oldBrush);
		    DeleteObject(newBrush);
			//Sleep(500);
		}
		//ReleaseDC(tp.hwnd,hdc);
		return 0;
	}
}

DWORD _stdcall TG(LPVOID pParam)
{
	TParam tp=*(TParam*)pParam;
	delete (TParam*)pParam;
	HDC hdc=GetDC(tp.hwnd);

	for(int i=0 ; i< 100 ; i+=5)
	{

		while(1)
		{
			HBRUSH newBrush = CreateSolidBrush(RGB(0, 255, 0));
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
			Rectangle(hdc,tp.rt.right,tp.rt.top,tp.rt.right,tp.rt.bottom);
			SelectObject(hdc, oldBrush);
		    DeleteObject(newBrush);
			//Sleep(500);
		}
		ReleaseDC(tp.hwnd,hdc);
		return 0;
	}
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
                         WPARAM wParam, LPARAM lParam) 
{
   HDC         hdc;
   PAINTSTRUCT ps; 
   static RECT rt;
   DWORD id;
   TParam* ptp;
   
   switch (iMsg)
   {
    case WM_CREATE:
		ptp = new TParam;
		GetClientRect(hwnd,&rt);
		ptp->rt.left = rt.left;
		ptp->rt.top = rt.top;
		ptp->rt.right = rt.right/2;
		ptp->rt.bottom = rt.bottom/2;
		ptp->hwnd = hwnd;

		CreateThread(NULL,0,TR,(LPVOID)ptp,0,&id);
		CreateThread(NULL,0,TG,(LPVOID)ptp,0,&id);
		//CreateThread(NULL,0,TW,(LPVOID)hwnd,0,&id);
		//CreateThread(NULL,0,TB,(LPVOID)hwnd,0,&id);

      break; 
    case WM_PAINT:
      hdc = BeginPaint(hwnd, &ps);
      EndPaint(hwnd, &ps);
      break; 
    case WM_DESTROY:
      PostQuitMessage(0);
      break;   
   }
   return DefWindowProc(hwnd, iMsg, wParam, lParam);
}