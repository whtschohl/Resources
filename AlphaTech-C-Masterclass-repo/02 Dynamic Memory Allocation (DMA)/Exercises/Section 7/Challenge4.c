#include <stdio.h>
#include <stdlib.h>

/*
    TASK: Write a function that creates and populates a dynamic array.
        The size of the array is UNKNOWN in advance
        What's known is that once we read a value of "-1", the function
        should stop reading inputs from the user, and it should return the 
        array, and pass its size.
*/

int *createDA(int size);
void printArr(int *arr, int size);

int main()
{
    int *size;
    int *arr = createDA(*size);

    printf("\nSize: %d", *size);
    printArr(arr, *size);
}

int *createDA(int size)
{
    int i = 0;
    int *arr = (int *) malloc(sizeof(int));

    while(arr[i] != -1)
    {
        size = sizeof(arr)/sizeof(int);
        arr = (int*) realloc(arr, size+1);
        printf("\nPlease enter an integer value: ");
        scanf("%i", &arr[i]);
    }

    size = sizeof(arr)/sizeof(int);
    return arr;
}

void printArr(int *arr, int size)
{
    for(int i = 0; i< size ;i++)
    {
        printf(" %d,", arr[i]);
    }
}

/*

Solution
=====================================================
*/

int* adjustableReallocation(int *arrSize)
{
    int num, lastIndex = 0, size = 2;
    int* arr = NULL;
    int* temp = NULL;

    printf("Enter Num: ");
    scanf("%d", &num);

    if(num == -1)
    {
        *arrSize = 0;
        return NULL;
    }
    else    
    {
        temp = (int*)malloc(size*sizeof(int));
        if (!temp) 
            return NULL;
        
        arr = temp;
    }

    while (num != -1)
    {
        if(lastIndex == size)
        {
            size = size + 1;
            temp = (int*)realloc(arr, size*sizeof(int));
            if (!temp) 
                return NULL;
        
            arr = temp;
        }

        arr[lastIndex] = num;
        lastIndex++;
        printf("Enter Num: ");
        scanf("%d", &num);
    }
    *arrSize = lastIndex;
    return arr;
}