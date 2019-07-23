#include <stdio.h>
extern "C" __declspec(dllexport) //__declspec(dllexport)메크로 사용 ,extern "C"는 cpp가 아닌 c의 명명법을 따르겠다는 뜻
void Print(int a, int b)
{
    printf("%d, %d\n", a, b);
}