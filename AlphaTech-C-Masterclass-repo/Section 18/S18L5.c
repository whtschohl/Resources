/*
    Tutorial: Using Function Pointers and Void Pointers in C

    Main Goal: create a function that any operation on all 
        elements of an array of any data type
*/

// 
// Headers
// 
#include <stdio.h>
#include <stdlib.h>

// Function to print an interger
void printInt(void* a ){
    printf("%d ", *(int*)a);
}

// Function to print a float
void printFloat(void* a ){
    printf("%.2f ", *(float*)a);
}

// Function to print a double
void printDouble(void* a ){
    printf("%.2lf ", *(double*)a);
}

// Function to print a char
void printChar(void* a ){
    printf("%c ", *(char*)a);
}

// Function to perform an operation on all elemetns of an array
void performOperation(void* arr, int arrLength, int elemSize, void (*operation)(void*))
{
    for(int i = 0; i < arrLength; i++)
    {
        operation((char*)arr+i*elemSize);
    }    
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Integer array
    int arrInt[] = {1,2,3};
    performOperation(arrInt, 3, sizeof(int), printInt);
    // Float array
    float arrFloat[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    performOperation(arrFloat, 5, sizeof(float), printFloat);
    // Double array
    double arrDouble[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    performOperation(arrDouble, 5, sizeof(double), printDouble);
    // Char array
    char arrChar[] = {'H', 'e', 'l', 'l', 'o'};
    performOperation(arrChar, 5, sizeof(char), printChar);

    return 0;
}
