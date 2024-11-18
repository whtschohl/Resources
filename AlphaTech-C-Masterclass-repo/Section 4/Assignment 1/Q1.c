// Online C compiler to run C program online
#include <stdio.h>

void swapInts(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main() {
    int a = 5, b = 7;
    printf("a=%i, b=%i\n", a, b);
    swapInts(&a,&b);
    printf("a=%i, b=%i\n", a, b);

    return 0;
}