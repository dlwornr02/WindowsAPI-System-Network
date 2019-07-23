extern "C" __declspec(dllexport)
void Swap(int* pa, int*pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}