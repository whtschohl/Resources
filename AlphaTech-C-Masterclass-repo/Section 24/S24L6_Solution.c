/***************************************************************************************************
 *  EXERCISE:   FindSpecificValueMaxSum - Question
 *
 *  TASK:       Develop a function that receives an array of integers and its size.
 *              The values in "sourceArr" are between "0" upt to "size".
 * 
 *              The function should return a specific value max sum.
 * 
 *              * The function should find and return a value, that if we sum all of its instances,
 *              then the reuslt will be the maximum.
 * 
 *  EXAMPLE:    1. {2,1,3,2,4,2,1}  size is 7 -> function returns "2". (sum of 2's ai Max = 6)
 *              2. {2,1,3,2,4,2,7}  size is 7 -> function returns "7". (sum of 7's ai Max = 7)
***************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 7

int findSpecificValueMaxSum(int *sourceArr, int size)
{
    int *countArr;
    int i, maxIndex = 0;

    countArr = (int*)calloc((size + 1), sizeof(int));
    assert(countArr);

    // Build the Counting Array
    for (i = 0; i < size; i++)
        countArr[sourceArr[i]]++;

    // "specific sum" = "index" * "number of appearances"
    for (i = 1; i <= size; i++)
        if(countArr[i] * i >= countArr[maxIndex] * maxIndex)
            maxIndex = i;
    
    free(countArr);
    return maxIndex;    
}

int main()
{
    int arr[SIZE] = {2,1,3,2,4,2,7};
    int result = findSpecificValueMaxSum(arr, SIZE);

    printf("\nMax Index: %d", result);

    return 0;
}
