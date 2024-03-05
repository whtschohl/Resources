// Exercise: return average value of array
#include <stdio.h>
#include <stdlib.h>

// definitions
#define SIZE 4

int Avg(int* arr)
{
    int sum = 0;
    for(int i = 0; i<SIZE; i++)
    {
        sum += arr[i];
    }
    return (double)sum/SIZE;
}

int main() {

    int arr[SIZE] = {80,85,72,90};
    double max = Avg(arr);
    
    printf("Average Value in array: %0.2f", max);

    return 0;
}