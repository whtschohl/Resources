#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void genericSwap(void *a, void *b, int memSize)
{
    void* temp = malloc(memSize);
    
    memcpy(temp, a, memSize);
    memcpy(a, b, memSize);
    memcpy(b, temp, memSize);
}


int main() {
    int a = 5, b = 7;
    
    
    printf("genericSwapInt\n===============\n");
    printf("a=%i, b=%i\n", a, b);
    genericSwap(&a,&b, sizeof(int));
    printf("a=%i, b=%i\n", a, b);
    
    printf("genericSwapDouble\n==================\n");
    printf("c=%0.1f, d=%0.1f\n", c, d);
    genericSwap(&c,&d, sizeof(double));
    printf("c=%0.1f, d=%0.1f\n", c, d);
}