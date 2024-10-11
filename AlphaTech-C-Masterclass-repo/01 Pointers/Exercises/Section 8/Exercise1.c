/* 
Exercise
=====================================================

Given a sorted array of integers [1,3,3,5,6,7,7,7,8,12,12]
Create a new, dynamically allocated array, with no duplicates

*/

#include <stdio.h>
#include <stdlib.h>

/*  My Solution */

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}

void createNoDoublesArray(int *arr, int size)
{
    int noDoulesSize = 0;
    int *noDoublesArr = NULL;

    noDoublesArr = (int*)malloc(sizeof(int));
    noDoublesArr[0] = arr[0];
    noDoulesSize++;

    if (!noDoublesArr)
    {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 1; i < size; i++)
    {
        if(arr[i] != arr[i-1]) 
        {
            noDoulesSize++;
            noDoublesArr = (int*)realloc(noDoublesArr, noDoulesSize*sizeof(int));
            noDoublesArr[noDoulesSize-1] = arr[i];

            if(!noDoublesArr)
            {
                printf("noDoublesArr is NULL");
                free(noDoublesArr);
            }
        }
    }
    
    printf("\nSource Array: ");
    printArray(arr, size);

    printf("\nNo Doubles Array: ");
    printArray(noDoublesArr, noDoulesSize);

    printf("\n---------------------\n");
    free(noDoublesArr);
}

int main()
{
    int arr[] = {1,3,3,5,6,7,7,7,8,12,12};
    int size = sizeof(arr) / sizeof(arr[0]);

    createNoDoublesArray(arr, size);
}


/*  Given Solution  */

/*

int *createNoDuplexArray(int* sourceArray, int size)
{
    int i, j=0;
    int count = 1;
    int *noDuplexArray;
    for (i = 0; i < size-1; i++)
        if (sourceArray[i] != sourceArray[i+1])
            count++;

    noDuplexArray = (int*)malloc(count*sizeof(int));
    // [_,_,_,_,_,_]
    for (i = 0; i < size-1; i++) // "i" - represents the index of the source array
        if(sourceArray[i] != sourceArray[i+1])
        {
            noDuplexArray[j] = sourceArray[i];
            j++;
        }
    noDuplexArray[j] = sourceArray[i];
    //[1,3,5,6,7,8,12]
    return noDuplexArray;
}

void printArray(int *arr, int size)
{
    int i;
    printf("\nArray Values: \n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int originalArray[] = {1,3,3,5,6,7,7,7,8,12,12};
    int *newArray;
    printArray(originalArray, 11);
    newArray = createNoDuplexArray(originalArray, 11);
    printArray(newArray, 7);
    return 0;
}

*/