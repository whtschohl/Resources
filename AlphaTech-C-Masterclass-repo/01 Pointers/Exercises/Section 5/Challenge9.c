/* Exercise:    Write a function that receives a Sorted (smallest->largest) Array of elements 
                The function also receives a "value". The function should find if there is a sum of 
                2 elements in the array that is equal to the received "value". If there are such 2 
                elements, then return 1 and pass them by refrence. Else, return 0, and pass for both of 
                them the value 0.
*/
#include <stdio.h>

/******************************************************************************/
// First thoughts -> basic logical solution
/******************************************************************************/

/*int isSum(int *arr, int value, int size, int* index)
{
    for(int i=0; i<size; i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if (arr[i]+arr[j] == value)
            {
                index[0] = i;
                index[1] = j;
                return 1;
            }
        }
    }
    index[0] = 0;
    index[1] = 0;
    return 0;
}

int main() 
{
    int arr[] = {1,3,4,7,9,10,12};
    int index[2] = {0,0};
    int value = 13, size = sizeof(arr) / sizeof(arr[0]);
    
    isSum(arr, value, size, index);
    printf("%d + %d = %d", arr[index[0]], arr[index[1]], value);
}*/

/******************************************************************************/
// nicer solution (only works for sorted arrays) -> logic upgrade
/******************************************************************************/


int isSum(int *arr, int value, int size, int* index)
{
    int i=0, j = size-1, sum;
    while(i<j)
    {
        sum = arr[i]+arr[j];
        if (sum == value)
        {
            index[0] = i;
            index[1] = j;
            return 1;
        }
        if (sum < value)
            i++;    // if i increases, so does the sum
        if (sum > value)
            j--;    // if j decreases, so does the sum 
        
    }
    index[0] = 0;
    index[1] = 0;
    return 0;
}

int main() 
{
    int arr[] = {1,3,4,7,9,10,12};
    int index[2] = {0,0};
    int value =4, size = sizeof(arr) / sizeof(arr[0]);
    
    isSum(arr, value, size, index);
    printf("%d + %d = %d", arr[index[0]], arr[index[1]], value);
}