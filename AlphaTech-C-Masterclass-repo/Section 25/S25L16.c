/*
    Displaying in binary
*/
#include <stdio.h>

void printBin(int value)
{
    int i, result, mask;
    result = 0;
    mask = 0b10000000;  // because we are printing from left to right

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

void main()
{
    int value = 0b01101001;
    printBin(value);
}