#include <stdio.h>
#include <stdlib.h>

int *createArray(int size)
{
    int *arr;
    arr = (int*)malloc(size*sizeof(int));
    if(!arr)
        return NULL;

    return arr;
}

void initArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter Element: ");
        scanf("%d", &arr[i]);
    }
}

void displayArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\n%d", arr[i]);
    }
}

int doubleArraySize(int **arr, int size)
{
    size = size * 2;
    int *newArr = (int*)realloc(*arr, size*sizeof(int));
    if(!newArr)
        return -1;
    
    for (int i = 0; i < (size*2); i++)
        newArr[i] = 0;

    *arr = newArr;

    return 0;
    
}

void freeMemory(int *ptr)
{
    free(ptr);
}

int main()
{
    int *arr;
    int size = 4;

    arr = createArray(size);
    if (!arr)
        return -1;

    initArray(arr, size);
    displayArray(arr, size);
    
    doubleArraySize(&arr, size);
    if(!arr)
        return -1;

    displayArray(arr, 2*size);
    freeMemory(arr);
}