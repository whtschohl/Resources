/*  Exercise:
    Write a recursive function that:
        - Receives an array of floating point numbers (>0) and its size.
        - Returns "1" if:
            - for any two adjacent elements in the array
              the "integer parts" are sorted in ascending order,
              AND the "fractional parts" are sorted in descending order.
        - Return "0", otherwise.



    For Example:

    Given the array: 1.4, 3.25, 4.5
    The function should return 0.

    Given the array: 1.4, 3.25, 4.2
    The array should return 1
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int checkAscendingIntegerDecendingFractions(double *arr, int size)
{   
    double f1, f2;
    // Exit condition
    
    if (size == 1)
        return 1;

    // process+

    if (checkAscendingIntegerDecendingFractions(arr+1, size - 1) == 0)
        return 0;
    else
    {
        f1 = arr[0] - (int)floor(arr[0]);
        f2 = arr[1] - (int)floor(arr[1]);

        if ( ( f1 > f2 ) && ( arr[0] < arr[1] ) )
            return 1;
        else 
            return 0;
        
    }
}

int main(void)
{
    double arr[] = {1.4, 3.25, 4.2};
    int size = 3;
    printf("%d", checkAscendingIntegerDecendingFractions(arr, size));
}