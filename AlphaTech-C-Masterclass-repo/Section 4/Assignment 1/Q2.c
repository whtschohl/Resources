#include <stdio.h>

void swapIntsNoThird1(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


int main() {
    int a = 5, b = 7;
    printf("a=%i, b=%i\n", a, b);
    swapIntsNoThird1(&a,&b);
    printf("a=%i, b=%i\n", a, b);

    return 0;
}