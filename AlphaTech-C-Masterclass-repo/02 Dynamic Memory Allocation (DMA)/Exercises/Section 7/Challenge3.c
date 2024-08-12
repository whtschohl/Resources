#include <stdio.h>
#include <stdlib.h>

/*
    Develop your own special "realloc" function.
    The function should have the following signature:
        void* myRealloc(void* srcblock, unsigned oldsize, unsigned newsize);

        - srcblock represent the address of the first byte in the memory

    The function should implement a GENERAL/UNIVERSAL reallocation functionality
    (without using the realloc function)
*/

void* myRealloc(void* srcblock, unsigned oldsize, unsigned newsize);

int main()
{
    int* numbers = (int*)malloc(3*sizeof(int));
    int* newNumbers = NULL;
    if (!numbers)   // numbers == NULL
        return 1;
    numbers[0] = 3;
    numbers[1] = 5;
    numbers[2] = 4;
    newNumbers = (int*)myRealloc(numbers, 3*sizeof(int), 4*sizeof(int));
}

void* myRealloc(void* srcblock, unsigned oldsize, unsigned newsize)
{
    int smallSize;
    if (oldsize < newsize)
        smallSize = oldsize;
    else
        smallSize = newsize;
    char* resultArr = (char*)malloc(newsize);
    if (!resultArr) return NULL;
    for (int i = 0; i < smallSize; i++)
        resultArr[i] = ((char*)srcblock)[i];
    free(srcblock);
    return resultArr;
}