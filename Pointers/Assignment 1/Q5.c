#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//swap ints func
void swapInts(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Swap ints Add/Sub
void swapIntsNoThird1(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

//Swap Ints Multiply / divide
void swapIntsNoThird2(int *a, int *b)
{
    *a = *a * *b; //35
    *b = *a / *b; //5
    *a = *a / *b;
}

//generic swap func
void genericSwap(void *a, void *b, int memSize)
{
    void* temp = malloc(memSize);
    
    memcpy(temp, a, memSize);
    memcpy(a, b, memSize);
    memcpy(b, temp, memSize);
}


int main() {
    int a = 5, b = 7;
    double c = 51.8, d = 89.7;
    
    //SwapInts Test
    printf("SwapInts\n=========\n");
    printf("a=%i, b=%i\n", a, b);
    swapInts(&a,&b);
    printf("a=%i, b=%i\n", a, b);

    //swap ints no third (add/sub) Test
    printf("SwapIntsNoThrid1\n=================\n");
    printf("a=%i, b=%i\n", a, b);
    swapIntsNoThird1(&a,&b);
    printf("a=%i, b=%i\n", a, b);

    //swap ints no third (multi/div) Test
    printf("SwapIntsNoThird2\n================\n");
    printf("a=%i, b=%i\n", a, b);
    swapIntsNoThird2(&a,&b);
    printf("a=%i, b=%i\n", a, b);

    ///genericSwap Test int and double
    printf("genericSwapInt\n===============\n");
    printf("a=%i, b=%i\n", a, b);
    genericSwap(&a,&b, sizeof(int));
    printf("a=%i, b=%i\n", a, b);
    printf("genericSwapDouble\n==================\n");
    printf("c=%0.1f, d=%0.1f\n", c, d);
    genericSwap(&c,&d, sizeof(double));
    printf("c=%0.1f, d=%0.1f\n", c, d);

    return 0;
}