/*
Creating and Returning a Dynamically Allocated Array from a Function
---------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Array of Integers
// We will return the address of the first element
int *createArray();

void printArray(int *arr, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int *arr;
    arr = createArray();
    printArray(arr, SIZE);
}

int *createArray()
{
    int i;
    //int myArr[SIZE];
    int *myArr;
    myArr = (int*)malloc(SIZE*sizeof(int));

    if(!myArr)
    {
        printf("ERROR");
        exit(1);
    }

    printf("Enter %d elements to your array.\n", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d", &myArr[i]);
    }
    return myArr;
}