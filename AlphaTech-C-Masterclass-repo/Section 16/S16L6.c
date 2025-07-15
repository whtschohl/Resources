#include <stdio.h>

typedef struct a {
    char val3;
    short val1;
    int val2;    
}A;

typedef struct b
{
    char val1;
    int val2;
    A val3;
}B;

int main()
{
    unsigned int totalBytesA = sizeof(A);
    unsigned int totalBytesB = sizeof(B);
    B b1;
    b1.val1 = 0xFF;
    b1.val2 = 0x12341234;
    b1.val3.val1 = 0xBBDD;
    b1.val3.val2 = 0xAACCEEFF;
    b1.val3.val3 = 0x99;
    return 0;    
}