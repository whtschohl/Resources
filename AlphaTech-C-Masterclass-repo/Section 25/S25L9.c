/*
    Extract / Understand specific bits in the value
    (using bitwise AND operator)
*/

#include <stdio.h>

// Example: get left most bit

enum {
    LEFT_MOST_BIT   = 0b10000000,
    RIGHT_MOST_BIT  = 0b00000001
}Bit;

void printBinary(int value)
{
    for (int i = 7; i >= 0; i--) // total of 8 itterations
        putchar((value & (1U << i)) ? '1' : '0');
}

int main()
{
    int x, mask, result;
    x = 0b10110100;
    mask = 0b10000000;
    result = x & mask;
    
    if(LEFT_MOST_BIT == result)
        printBinary(result);
    else   
        printf("0");
}