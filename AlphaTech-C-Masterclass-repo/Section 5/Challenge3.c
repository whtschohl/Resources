// Exercise:    Write a function called "updateeAvg" that takes 2 values and update
//              the average number by-refrence
#include <stdio.h>
#include <stdlib.h>

// definitions
#define SIZE 4

double updateAvg(int* arr, double* avg)
{
    if (avg == NULL)
        avg = 0;
    
    int sum = 0;
    
    // Populate array
    for (int i=0; i<SIZE; i++)
    {
        printf("Enter Value\n");
        scanf("%d", &arr[i]);
    }
    
    // Get sum
    for(int i = 0; i<SIZE; i++)
    {
        sum += arr[i];
    }
    
    // Calculate AVG
    *avg = (double)sum/SIZE;
}

int main() {
    double avg;
    int arr[SIZE] = {};
    
    updateAvg(arr, &avg);
    
    printf("Average Value in array: %0.2f", avg);
    
    return 0;
}