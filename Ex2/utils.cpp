void Swap(int& a, int& b) {
    int* pa = &a, * pb = &b;
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}
