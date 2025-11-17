/*
    Extract / Understand specific bits in the value
    (using bitwise AND operator)
*/

// Example: extract right most bit

#include <stdio.h>

int main()
{
    int x, mask, result;
    x = 0b10110100;
    mask = 0b00000001;
    result = x & mask;

    printf("%d", result);
}