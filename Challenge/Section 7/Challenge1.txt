// Exercise: Create and Return a Dynamically allocated Array from a function
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int *createArray()
{
    int *myArr;
    myArr = (int*)malloc(SIZE*sizeof(int)); //malloc is of type void*. Because we are using type int*, we need to cast to type -> (int*)malloc...
    // make sure works properly
    if(!myArr)
    {
        printf("You\'ve got an error... check momory");
        exit(1);
    }
    
    printf("\n Enter %d elements to your array. \n", SIZE);
    for(int i = 0; i<SIZE; i++)
    {
        printf("\nEnter number %d: ", i+1);
        scanf("%d", &myArr[i]);
    }
    
    return myArr;
}

int printArray(int* arr)
{
    for(int i=0; i<SIZE; i++)
    {
        printf("%d,", arr[i]);
    }
}

int main() {
   int* arr;
   arr = createArray();
   printArray(arr);
}