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

#include <stdio.h>

#define SIZE 6

int freq_as_value(int *arr, const int size, const int k);

int main()
{
    int arr[SIZE] = {3,2,2,1,3,3};
    int k = 3;
    int res = freq_as_value(arr, SIZE, k);
}

int freq_as_value(int *arr, const int size, const int k)
{
    int iCount;
    for (int i = 0; i < k; i++)
    {
        iCount = 0;
        for (int j = 0; j < size; j++)
        {
            if(i == arr[j])
                iCount++;
        }
        
        if(i != iCount)
            return 0;
        
    }
    return 1;
}
