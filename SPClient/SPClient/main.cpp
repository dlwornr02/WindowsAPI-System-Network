/////����� DLL/////
#include<Windows.h>
#include<stdio.h>

void main()
{
	int a=10,b=20;
	printf("client\n");

	HMODULE hDll;
	hDll = LoadLibrary("SP.dll"); //�����Ϸ��� ����� �ε�

	if(hDll==NULL)
	{
		printf("SP.dll ���̺귯�� �ε� ����!\n");
	}

	void (*pswap)(int*,int*);

	pswap = (void(*)(int*,int*))GetProcAddress(hDll,"Swap"); //�Լ��� �ּҸ� ��ȯ
	if(pswap==NULL)
	{
		printf("pswap �Լ� ã�� ����!\n");
		return;
	}

	void(*print)(int,int);
	print = (void(*)(int,int))GetProcAddress(hDll,"Print");
	if(print == NULL)
	{
		printf("Print�Լ� ã�� ����!\n");
		return;
	}
	print(a,b);
	pswap(&a,&b);
	print(a,b);
	FreeLibrary(hDll); //

	getchar();
}