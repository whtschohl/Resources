/*  
    Exercise: Sorting an Array using Function Poiters   
                            / \
                           /   \ 
                         |_     _|
                         
                    Ascending   Descending


    Your Tasks:
    ------------

    1. Define two comparison functions: asc, desc
    2. Sort(int *arr; int n; ______)
    3. "main"
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defines

#define SIZE 9 

// Functions
void ascending(int *arr, int size);
void descending(int *arr, int size);
void swap(int *num1, int *num2);
void printArr(int *arr, int size);

int main()
{   
    int choice;
    int arr[] = {1, 7, 3, 2, 9, 4, 8, 6, 5};
    void (*pfaSortType[])(int *arr, int size) = {ascending, descending};
    void *ptrFunc = NULL;

    printf("Choose: \n0 - Ascending order \n1 - Descending order\n");
    scanf("%d", &choice);

    printf("Before:\n");
    printArr(arr, SIZE);
    (*pfaSortType[choice])(arr, SIZE);
    printf("After:\n");
    printArr(arr, SIZE);
    
    return 0;
}

// Use Bubble Sort Algo
// Bubble sort compares 2 adjacent elements -> 1 vs 7; then 7 vs 3; etc...

void ascending(int *arr, int size)
{
    for (int j = 0; j < size - 1; j++)
        for (int i = 0; i < size - j - 1; i++)
            if (arr[i] > arr[i+1])
                swap(&arr[i], &arr[i+1]);     
}

void descending(int *arr, int size)
{
    for (int j = 0; j < size - 1; j++)
        for (int i = 0; i < size - j - 1; i++)
            if (arr[i] < arr[i+1])
                swap(&arr[i], &arr[i+1]);  
}

void swap(int *num1, int *num2)
{
    int temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void printArr(int *arr, int size)
{
    printf("Arr:");
    for (int i = 0; i < size; i++)
        printf(" %d", arr[i]);     
    printf("\n");
}