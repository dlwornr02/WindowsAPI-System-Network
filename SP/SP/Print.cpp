#include <stdio.h>
extern "C" __declspec(dllexport) //__declspec(dllexport)��ũ�� ��� ,extern "C"�� cpp�� �ƴ� c�� ������ �����ڴٴ� ��
void Print(int a, int b)
{
    printf("%d, %d\n", a, b);
}