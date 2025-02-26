/*  Develop a recursive function that receives an integer value "n".
    The function should print the value of "n" in Binary-Representation (base 2).
    For Example:
        n = 4 --> 100
        n = 6 --> 110
        n = 12 --> 1100
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printDecimalToBinary(int n)
{
    // end condition

    if (n<=1)
        printf("%d", n);
    
    // process
    else
    {
        printDecimalToBinary(n/2);
        printf("%i", n % 2);
    }
}

int main()
{
    printDecimalToBinary(12);
    printf("\n");
}