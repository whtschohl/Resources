// Function to delete an element from an array

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    
}

void *remove(void *arr, unsigned size, unsigned idx, unsigned sourceSize)
{
    void *newArr = malloc(size - sourceSize);
    if(!newArr)return NULL;
    memcpy(newArr, arr, idx);
    memcpy((char*)newArr+idx, (char*)arr+idx+sourceSize, size - idx - sourceSize);
    return newArr;
}