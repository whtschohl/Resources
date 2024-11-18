/* 
Exercise
=====================================================

Given an array of intergers {'A','r','e','Y','o','U','T','h'};
Create 2 dynamically allocated arrays
First array will consist only of "Upper Values" [A,Y,U,T]
Second array will consist only of "Lower Values" [r,e,o,h]
The function should simply print the values of both of the arrays
Step 2 - Return & Pass by Ref

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*   My Try   */

// Defines
#define SIZE 8

// Private Function
bool bIsUpper(char c);
void vSplitArr(int size, char **upper, char **lower, char *arr, int *upperSize, int *lowerSize);
void printArray(char *arr, int size);

// Main
int main()
{
    char cArrBig[SIZE] = {'A','r','e','Y','o','U','T','h'};
    char *cArrUpper = NULL;
    char *cArrLower = NULL;
    int iUpperSize = 0, iLowerSize = 0;

    vSplitArr(SIZE, &cArrUpper, &cArrLower, cArrBig, &iUpperSize, &iLowerSize);
    
    printf("Given Array: ");
    printArray(cArrBig, SIZE);
    printf("Array Upper: ");
    printArray(cArrUpper, iUpperSize);
    printf("Array Lower: ");
    printArray(cArrLower, iLowerSize);
    printf("\n");

    return 0;
}

bool bIsUpper(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return 1;  // True: The character is uppercase
    } else {
        return 0;  // False: The character is not uppercase
    }
}

void vSplitArr(int size, char **upper, char **lower, char *arr, int *upperSize, int *lowerSize)
{
    for (int i = 0; i < size; i++)
    {
        if(bIsUpper(arr[i])) // Case of Upper
        {
            (*upperSize)++;
            *upper = (char*)realloc(*upper, *upperSize*sizeof(int));
            (*upper)[*upperSize-1] = arr[i];
        }
        else // Case of Lower
        {
            (*lowerSize)++;
            *lower = (char*)realloc(*lower, *lowerSize*sizeof(int));
            (*lower)[*lowerSize-1] = arr[i];
        }
    }
    
}

void printArray(char *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c, ", arr[i]);
    }
    printf("\n-----\n");
    
}