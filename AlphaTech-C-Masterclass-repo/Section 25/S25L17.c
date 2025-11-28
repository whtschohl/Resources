/*
    How to implament Bitwise Rotation?
    ---

    Task 1: Implament a Bitwise Right Rotation
        - Bitwise Shift right

        value:   10011001
        shifted: x1001100 -> x is 1 or 0 depending on the computer. Will assume 0 for this lesson
        .: res:  01001100

        Rotaion places the "lost" bit back at the front.
        so: value rotated right is 11001100
*/
#include <stdio.h>
#include <math.h>

void bitwise_right_rotation();
void print_bin(int value);

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
    bitwise_right_rotation();
    return 0;
}