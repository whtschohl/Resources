/* 
Exercise
=====================================================

Given an array of intergers [12,5,7,8,3,10,4,9]
Create 2 dynamically allocated arrays
First array will consist only of "Even Values" [12,8,10,4]
Second array will consist only of "Odd Values" [5,7,3,9]
The function should simply print the values of both of the arrays
Step 2 - Return & Pass by Ref

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void splitArray(int *arr, int size, int **evenArr, int **oddArr, int *oddSize, int *evenSize)
{ 
    for (int i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0) //Even
        {
            (*evenSize)++;
            *evenArr = (int*)realloc(*evenArr, *evenSize*sizeof(int));
            (*evenArr)[*evenSize-1] = arr[i];
            if(!evenArr)
                return;
        }        
        else
        {
            (*oddSize)++;
            *oddArr = (int*)realloc(*oddArr, *oddSize*sizeof(int));
            (*oddArr)[*oddSize-1] = arr[i];
            if(!oddArr)
                return;
        }
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n-----\n");
    
}

int main()
{
    int *evenArr = NULL;
    int *oddArr = NULL;
    int arr[SIZE] = {12,5,7,8,3,10,4,9};
    int oddSize = 0, evenSize = 0;
    
    splitArray(arr, SIZE, &evenArr, &oddArr, &oddSize, &evenSize);
    
    printf("\nSource Array: ");
    printArray(arr, SIZE);
    
    printf("\nEven Array: ");
    printArray(evenArr, evenSize);

    printf("\nOdd Array: ");
    printArray(oddArr, oddSize);

    free(evenArr);
    free(oddArr);
}