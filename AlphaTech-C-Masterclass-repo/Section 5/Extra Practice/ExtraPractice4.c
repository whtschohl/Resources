#include <stdio.h>
#include <stdlib.h>

/*  Exercise:

    Develop 2 recursive functions.
    Both should receive an array and its size.

    Func. A --> should print all array elements 
                from the leftmost value to the 
                rightmost value

    Func. B --> should print all arry elements 
                from the rightmost value to the 
                leftmost value.

    
    
    Example: 
    Array = [1,3,2,4]
    Func. A should print: 1324
    Func. B should print: 4231

*/

int LtoR(int *arr, int size)
{
    // end statement
    if (size < 1)
        return 0;

    // recursive Procedure
    printf("%d", arr[0]);
    LtoR(arr+1, size-1);
}

int RtoL(int *arr, int size)
{
    // end statement
    if (size < 1)
        return 0;

    // recursive Procedure
    printf("%d", arr[size-1]);
    LtoR(arr, size-1);
}

int main(void)
{
    int arr[4] = {1,3,2,4};
    LtoR(arr, 4);
    printf("\n");
    RtoL(arr, 4);
}