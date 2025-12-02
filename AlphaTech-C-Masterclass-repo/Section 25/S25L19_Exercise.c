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
    int temp = 0;
    temp |= *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 5, b = 7;
    printf("before: \na=%d, b=%d", a, b);
    swap(&a, &b);
    printf("after: \na=%d, b=%d", a, b);

}