#include <stdio.h>
#include <stdlib.h>

/*
    Exercise:
    Write a recursive function that:
        - receives an array and its size
        - returns the average value of the array

    Example:
        Given array: 1,4,3 - size=3
        The function should return 2.666... (8/3)
*/

float getAvg(int *arr, int size)
{   
    double avg;
    // Exit condition
    if (size == 1)
        return arr[0];
        
    // process+
    avg = getAvg(arr+1, size-1);
    return (avg * (size-1) + arr[0])/size; 
}

int main(void)
{
    int size = 3;
    int arr[3] = {1,4,3};

    printf("%.3f", getAvg(arr, size));

}