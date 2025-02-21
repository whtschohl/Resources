// Write a function that receives an array of integers.
// This function should be a "void" type.
// Create and copy all the elements from the received array to a new one.
// The new array (copied) should be passed by refrence to the caller function:

// Header
//-------------------
#include <stdio.h>
#include <stdlib.h>

// Private defines
//-------------------
#define SIZE 3

void vCopy(int *original, int size, int** target);
void vPrintArray(int *arr, int size);

int main()
{
    int arrOriginal[SIZE] = {1, 2, 5};
    int *arrCopy;

    vCopy(arrOriginal, SIZE, &arrCopy);

    printf("\nOriginal Array: ");
    vPrintArray(arrOriginal, SIZE);
    printf("\nCopy Array: ");
    vPrintArray(arrCopy, SIZE);
}

void vCopy(int *original, int size, int** target)
{
    *target = (int*)malloc(size * sizeof(int));
    if (target != NULL)
        for (int i = 0; i < size; i++)
            (*target)[i] = original[i];     
    
}

void vPrintArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d, ", arr[i]);
}