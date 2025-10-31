/***************************************************************************************************
 *  EXERCISE:   FindDominantValue - Question
 *
 *  TASK:       Develop a function that receives a sequence of natural numbers("sourceArr") and
 *              its size ("size"). The values in "sourceArr" are between "0" up to "size".
 * 
 *              The function should return a *"dominant" value (if it exists). Otherwise, return -1
 * 
 *              * A "dominant" value is a value whose number of appearences in the array is greater
 *              than half of the array (greater than half the size of the array)
 * 
 *  EXAMPLE:    1. {3,5,4,3,3} -> return  3
 *              2. {3,5,4,2,3} -> return -1
***************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 5

int findDominantValue(int *sourceArr, int size)
{
    int *countArr;
    int i;

    countArr = (int*)calloc((size + 1), sizeof(int));
    assert(countArr);

    // Build the Countign Array
    for (i = 0; i < size; i++)
        countArr[sourceArr[i]]++;
    
    // Search for a "dominant" value
    for (i = 0; i <= size; i++)
        if (countArr[i] > size/2)
        {
            free(countArr);
            return i;
        }
    // No dominant element was fount
    free(countArr);
    return -1;    
}

int main()
{
    int arr[SIZE] = {3,5,4,2,3};
    int res = findDominantValue(arr, SIZE);
}