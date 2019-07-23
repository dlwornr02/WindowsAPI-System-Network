/////명시적 DLL/////
#include<Windows.h>
#include<stdio.h>

void main()
{
	int a=10,b=20;
	printf("client\n");

	HMODULE hDll;
	hDll = LoadLibrary("SP.dll"); //참조하려고 명시적 로드

	if(hDll==NULL)
	{
		printf("SP.dll 라이브러리 로드 실패!\n");
	}

	void (*pswap)(int*,int*);

	pswap = (void(*)(int*,int*))GetProcAddress(hDll,"Swap"); //함수의 주소를 반환
	if(pswap==NULL)
	{
		printf("pswap 함수 찾기 실패!\n");
		return;
	}

	void(*print)(int,int);
	print = (void(*)(int,int))GetProcAddress(hDll,"Print");
	if(print == NULL)
	{
		printf("Print함수 찾기 실패!\n");
		return;
	}
	print(a,b);
	pswap(&a,&b);
	print(a,b);
	FreeLibrary(hDll); //

	getchar();
}