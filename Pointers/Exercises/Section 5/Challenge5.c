// Exercise: 
// Write a function that checks if teh array is "really sorted", "sorted", or "not sorted".
// The function should return 1 and pass 1 by refrence if the array is really sorted
// The function should return 1 and pass 0 by refrence if the array is really sorted
// The function should return 0 and pass 0 by refrence if the array is really sorted
// Tests: [1,2,5,7,10] RS; [1,2,2,5,10] S; [1,2,7,3,10] NS; 
#include <stdio.h>
#include <stdlib.h>

//definitions
#define SIZE 5

int isSorted(int* arr, int* P)
{
    // case of not sorted
    for(int i = 0; i < SIZE-1; i++)
    {
        if (arr[i] > arr[i+1])
            return 0;
        if (arr[i] == arr[i+1])
            *P = 0;
    }
    return 1;
}

int main() {
    
    int arr[SIZE] = {1,2,5,7,10};
    int P = 1, R;
    R = isSorted(arr, &P);
    printf("P:%d\nR:%d\n", P, R);
    
    if ((P == 1) && (R == 1))
        printf("Really Sorted");
    else
        if ((P == 0) && (R == 1))
            printf("Sorted");
        else printf("Not Sorted");
    
}

/*********************************************************************************/
/****************************** RECURSIVE SOLUTION *******************************/
/*********************************************************************************/

// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// definitions
#define SIZE 5

int isSortedRecursive(int* arr, int size, int* isReallySorted)
{
    int result;
    if (size == 1)
    {
        *isReallySorted = 1;
        return 1;
    }
    
    result = isSortedRecursive(arr, size-1, isReallySorted);
    
    if (result != 0 && arr[size-1] == arr[size-2])
        *isReallySorted = 0;
    if (result != 0 && arr[size-1] < arr[size-2])
    {
        *isReallySorted = 0;
        return 0;
    }
    return result;
}

int main() {
    
    int arr[SIZE] = {1,2,5,7,10};
    int P = 1, R;
    R = isSortedRecursive(arr, SIZE, &P);
    printf("P:%d\nR:%d\n", P, R);
    
    if ((P == 1) && (R == 1))
        printf("Really Sorted");
    else
        if ((P == 0) && (R == 1))
            printf("Sorted");
        else printf("Not Sorted");
    
}