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

// Functions
void ascending(int *arr);
void descending(int *arr);
void swap(int *num1, int *num2);

int main()
{
    int arr[] = {1, 7, 3, 2, 9, 4, 8, 6, 5};
    void *ptrFunc = NULL;
}

// Use Bubble Sort Algo
// Bubble sort compares 2 adjacent elements -> 1 vs 7; then 7 vs 3; etc...

void ascending(int *arr)
{
    int size = round(sizeof(arr) / sizeof(int));
    for (int i = 0; i < size; i++)
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);     
}

void descending(int *arr)
{
    int size = round(sizeof(arr) / sizeof(int));
    for (int i = 0; i > size; i++)
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);  
}

void swap(int *num1, int *num2)
{
    int temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}