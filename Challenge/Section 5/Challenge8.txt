// Exercise:Write a function that receives
//          that receives an array. The function
//          should find and return the "second
//          smallest" in the array.
#include <stdio.h>

int secondSmallest(int *arr, int size)
{
    int small1 = arr[0], small2;
    for(int i = 1; i < size; i++)
    {   
        if (arr[i]<small1)
        {
            small2 = small1;
            small1 = arr[i];
        }
        else if (arr[i]<small2)
            small2 = arr[i];
    }
    
    return small2;
}

int main() 
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int small2 = secondSmallest(arr, size);
    printf("%d", small2);
}