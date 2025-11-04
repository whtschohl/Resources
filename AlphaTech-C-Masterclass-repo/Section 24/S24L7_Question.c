/***************************************************************************************************
 *  EXERCISE:   FindLargestMissingValue - Question
 *
 *  TASK:       Develop a function that receives an array ("sourceArr") of integers and its size 
 *              ("n"). The values in "sourceArr" are not-negative and not greater thatn "n".
 * 
 *              The function should return the largest missing value in the array (<= n).
 * 
 *              *Note: The function should be efficient (without any nested loops).. You can use 
 *              an auxiliary memory to find the solution.
 * 
 *  EXAMPLE:    1. {2,1,3,2,4,2,7} n=7 -> Function Values {0-7}. The function should return "6"
 *              2. {2,1,2,4,5,6,7} n=7 -> Function Values {0-7}. The function should retunr "3"
***************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 7

int findLargestMissingValue(int *sourceArr, int size)
{
    int i;
    int *countArr = (int*)calloc(size+1, sizeof(int));
    assert(countArr);

    // build the countArr
    for (i = 0; i < size; i++)
        countArr[sourceArr[i]]++;

    for (i = size; i >= 0; i--)
        if (0 == countArr[i])
        {
            free(countArr);
            return i;
        }

    free(countArr);
    return -1;
}

int main()
{
    int arr[SIZE] = {2,1,2,4,5,6,7} ;
    int res = findLargestMissingValue(arr, SIZE);

    printf("result: %d\n", res);
    return 0;
}
