/*
    How to Implament Bitwise Rotation?
    ---

    Task 1: Implement a Bitwise Right Rotation
    Task 2: Implement a Bitwise Left  Rotation
*/
#include <stdio.h>
#include <math.h>

void bitwise_right_rotation();
void bitwise_left_rotation();
void print_bin(int value);

void bitwise_left_rotation()
{
    /* Steps
        1. find the left most bit
        2. Shift value to the left
        3. (Assumption that machine fills values of 0s)
    */

    // Step 1:
    int value = 0b10011001; //shifted: 00110011
    int mask  = 0b10000000;
    int digit = value & mask;

    printf("\nvlaue : ");
    print_bin(value);

    // Step 2:
    value <<= 1;
    value &= 0xFF;

    // Step 3:
    if(mask == digit)
    {
        mask >>= 7;
        value |= mask;
    }

    printf("\nrotate: ");
    print_bin(value);
}

void bitwise_right_rotation()
{
    /* Steps
        1. find the right most bit
        2. Shift value to the right
        3. (Assumption that machine fills values of 0s)
    */

    // Step 1:
    int value = 0b10011001; //110011000
    int mask  = 0b00000001;
    int digit = value & mask;

    printf("\nvlaue : ");
    print_bin(value);

    // Step 2:
    value >>= 1;

    // Step 3:
    if(1 == digit)
    {
        mask <<= 7;
        value |= mask;
    }

    printf("\nrotate: ");
    print_bin(value);
}

void print_bin(int value)
{
    int i, result, mask;
    result = 0;
    int bits = 8;
    mask = pow(2, bits - 1);  // because we are printing from left to right

    for(i = 0; i < 8; i++)
    {
        result = mask & value;
        if(result == 0)
            printf("0");
        else
            printf("1");

        mask = mask >> 1;
    }
}

int main()
{
    printf("\nRight shift:\n");
    bitwise_right_rotation();
    printf("\n\nLeft shift:\n");
    bitwise_left_rotation();
    return 0;
}