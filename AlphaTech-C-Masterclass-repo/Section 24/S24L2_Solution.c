/***************************************************************************************************
    Exercise: Freq As Value 

    Develop a function that receives an array of integers, its size, and some value "k".
    The array consists of values between "0" and "k" (included).

    The function should check and return I, if the number of occurrences of any value in 
    the array equals to the value itself. Otherwise return 0.

    For example: there should be 0 occurrences of 0; 1 occurence of 1, 2 of 2, ... , 
    k occurrences of k.

    example: {1,2,2,4,3,3}, k = 4 - return 0
    example: {3,2,2,1,3,3}, k = 3 - return 1
***************************************************************************************************/

// Note: This solution is O(n+k) - linear complexity

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 6

int isFreqAsValue(int* srcArr, int size, int k)
{
    int* countArr;
    int i;

    countArr = (int*)calloc((k+1), sizeof(int));
    assert(countArr);

    //Building the Counting Array
    for (i = 0; i < size; i++)
        countArr[srcArr[i]]++;
    
    // Look for "index!=countArr[index]"
    for(i = 0; i <= k; i++)
        if (i != countArr[i])
        {
            free(countArr);
            return 0;
        }
    
    // All elements satisfy the "freqAsValue" cond.
    free(countArr);
    return 1;
}

int main()
{
    int arr[SIZE] = {3,2,2,1,3,3};
    int k = 3;
    int result = isFreqAsValue(arr, SIZE, k);

    // Display the results..
    // Make sure that it works :)

    return 0;
}
