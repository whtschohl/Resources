#include <stdio.h>

void swapIntsNoThird2(int *a, int *b)
{
    *a = *a * *b; //35
    *b = *a / *b; //5
    *a = *a / *b;
}


int main() {
    int a = 5, b = 7;
    printf("a=%i, b=%i\n", a, b);
    swapIntsNoThird2(&a,&b);
    printf("a=%i, b=%i\n", a, b);

    return 0;
}