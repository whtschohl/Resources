// Exercise:
// Write a function that receives an array and its size
// return 1 if the array has a some element which value equals to the sum of both of its neighbors (right and left)
// else reutrn 0
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// definitions
#define SIZE 5

// functions
bool goodNeighbor(int* arr)
{
    for(int i = 1; i<(SIZE-1); i++)
    {
        if (arr[i] == (arr[i-1]+arr[i+1]))
            return true;
    }
    return false;
}
// main
int main()
{
    int arr[SIZE] = {1,4,1,4,2};
    bool bGN = goodNeighbor(arr);
    printf("Good neighbors: %s", bGN?"true":"false");
    
    return 0;
}