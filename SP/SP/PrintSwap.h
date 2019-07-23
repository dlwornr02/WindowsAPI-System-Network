#ifndef PRINT_SWAP_HHH
#define PRINT_SWAP_HHH

extern "C" __declspec(dllimport)
    void Print(int a, int b); //.c 파일은 extern "C" 필요 없음

extern "C" __declspec(dllimport)//dllimport 클라이언트에서 가져다쓰기때문에 사용
    void Swap(int* pa, int*pb);


#endif