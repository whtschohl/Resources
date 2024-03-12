// Exercise - Recursion & Arrays
// Develop a recursive function that receives an array of integers and its size.
// The function should return:
//      - 1, if every two adjacent elements have the opposite sign.
//      - 0, otherwise (at least one pair of adjacent elements with the same sign)
//
// For example: 
//      arr = -1, 2, -4, size =3 --> 1
//      arr = 1, -2, 4, 5, -3, size = 5 --> 0
 
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// (checking from right to left)
int oppo(int *arr, int size)
{
    if (size == 1)
        return 1;
    if ((arr[size-1]*arr[size-2] < 0))
        return oppo(arr, size-1);
    else 
        return 0;
}

// Using Pointer Arithmatic
// (checking from left to right)
int oppo2(int *arr, int size)
{
    if (size == 1)
        return 1;
    if ((arr[0]*arr[1] < 0))
        return oppo2(arr+1, size-1);
    else 
        return 0;
}

int main()
{
    int arr[SIZE] = {-1, 2, -4, 5, -3};
    printf("\n\n%d\n\n", oppo2(arr, SIZE));
}