// Create your own realloc function
#include <stdio.h>
#include <stdlib.h>

void* myRealloc(void* oldArr, unsigned oldSize, unsigned newSize);

int main() {
    int size = 3;
    int* numbers = (int*)malloc(size * sizeof(int));
    if(!numbers) // number == NULL
        return 1;
    for(int i=0;i<size;i++)
        numbers[i] = i+1;
}

void* myRealloc(void* oldArr, unsigned oldSize, unsigned newSize)
{
    char* newArr = (char*)malloc(newSize * sizeof(char));
    for(int i = 0; i<oldSize; i++)
        newArr[i] = ((char*)oldArr)[i];
    free(oldArr);
    return newArr;
}