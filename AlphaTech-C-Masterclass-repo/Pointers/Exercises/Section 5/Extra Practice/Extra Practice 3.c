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

int maxAdj(int *arr, int size, int temp)
{
    if (size == 1)
        return 1;

    if (arr[0]+arr[1]>temp)
        temp = arr[0]+arr[1];

    return maxAdj(arr+1, size-1, temp);
}

int main()
{
    int arr[SIZE] = {1,2,4,3,1};
    printf("\n\n%d\n\n", maxAdj(arr, SIZE, 0));
}