/*

Exrtcise - Recursions & Arrays!
Develop a recursive function that receives an array of integers and its size
The function should calculate and return the Maximum Sum of two adjacent elements

Example:
    arr = 1,2,4,3,1, size = 5 --> 7
    arr = 9,2,4,5,3, size = 5 --> 11

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int maxAdj(int *arr, int size)
{
    int Max, Sum;

    if (size == 2)
        return arr[0]+arr[1];

    Sum = arr[0] + arr[1];
    Max = maxAdj(arr+1,size-1);

    if (Max > Sum)
        return Max;
    else 
        return Sum;    
}

int main()
{
    int arr[SIZE] = {1,2,4,3,1};
    printf("\n\n%d\n\n", maxAdj(arr, SIZE));
}