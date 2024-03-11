// Excersise: Find Max number in array
#include <stdio.h>
#include <stdlib.h>

// definitions
#define SIZE 4

int maxNum(int* arr)
{
    int max = 0;
    for(int i = 0; i<SIZE; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main() {
    int arr[SIZE] = {80,85,72,90};
    int max = maxNum(arr);
    
    printf("Max number in array: %d", max);

    return 0;
}