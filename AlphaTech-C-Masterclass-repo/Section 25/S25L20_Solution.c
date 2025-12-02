/*
    Exercise:   Implement a swapping operation between two variables.
                Use only "bitwise operations"

    Example:
    before ==> a = 5 (0b00000101), b = 7 (0b00000111)
    after  ==> a = 7 (0b00000111), b = 5 (0b00000101)
*/
#include <stdio.h>

void swap(int* a, int* b)
{
    *a ^= *b;   // a = 0010
    *b ^= *a;   // b = 0101
    *a ^= *b;   // a = 0111
}

int main()
{
    int a = 5, b = 7;
    printf("before: \na=%d, b=%d", a, b);
    swap(&a, &b);
    printf("\nafter: \na=%d, b=%d", a, b);
}