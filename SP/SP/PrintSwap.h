#ifndef PRINT_SWAP_HHH
#define PRINT_SWAP_HHH

extern "C" __declspec(dllimport)
    void Print(int a, int b); //.c ������ extern "C" �ʿ� ����

extern "C" __declspec(dllimport)//dllimport Ŭ���̾�Ʈ���� �����پ��⶧���� ���
    void Swap(int* pa, int*pb);


#endif