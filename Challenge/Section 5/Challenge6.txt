// Exercise: 
// Write a function that checks if teh array is "really sorted", "sorted", or "not sorted".
// The function should return 1 and pass 1 by refrence if the array is really sorted
// The function should return 1 and pass 0 by refrence if the array is really sorted
// The function should return 0 and pass 0 by refrence if the array is really sorted
// Tests: [1,2,5,7,10] RS; [1,2,2,5,10] S; [1,2,7,3,10] NS; 
#include <stdio.h>
#include <stdlib.h>

//definitions
#define SIZE 5

void printArr(int* arr)
{
    for(int i = 0; i<SIZE; i++ )
    {
        printf("%d", arr[i]);
    }
}

void reverse(int* arr)
{
    int temp[SIZE] = {};
    
    for(int i=0; i<SIZE; i++)
    {
        temp[(SIZE-(i+1))] = arr[i];
    }
    for(int i=0; i<SIZE; i++)
    {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[SIZE] = {1,2,3,4,5};
    
    printf("Array: ");
    printArr(arr);
    reverse(arr);
    printf("\nReverse: ");
    printArr(arr);
}

/*********************************************************************************/
/****************************** RECURSIVE SOLUTION *******************************/
/*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//definitions
#define SIZE 5

void printArr(int* arr)
{
    for(int i = 0; i<SIZE; i++ )
    {
        printf("%d", arr[i]);
    }
}

void reverse(int* arr, int* rev, int size)
{
    printf("\n%d", size);
    if (size == 1)
    {
        rev[SIZE-size] = arr[size-1];
        return 0;
    }
    rev[SIZE-size] = arr[size-1];
    reverse(arr, rev, size-1);   
}

int main() {
    int arr[SIZE] = {1,2,3,4,5};
    int rev[SIZE] ={0,0,0,0,0};
    
    printf("Array: ");
    printArr(arr);
    reverse(arr, rev, SIZE);
    printf("\nReverse: ");
    printArr(rev);
}

/*********************************************************************************/
/********************************* COURSE SOLUTION *******************************/
/*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//definitions
#define SIZE 5

// Function to Swap two variables
void swap(char* ptr1, char* ptr2)
{
    char temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

// Function to print arrays
void printArr(char* arr)
{
    for(int i = 0; i<SIZE; i++ )
        printf("%c", arr[i]);
    printf("\n");
}

//Iterative approach to the reverse function
void reverseIter(char* arr, int size)
{
    for(int i = 0; i<size/2; i++)
        swap(&arr[i], &arr[SIZE-(1+i)]);
}

//Recursive approach to the reverse function
void reverseRec(char* arr, int size)
{
    if (size > 1)
    {
        swap(&arr[0], &arr[size-1]);
        reverseRec(arr+1, size-2); //size -2 because you move 2 spaces - from the left and from the right
    }  
}

//Recursive approach to the reverse function with more pointer-arithmetic
void reverseRec2(char* arr, int size)
{
    if (size > 1)
    {
        swap(arr, arr+(size-1));
        reverseRec(arr+1, size-2);
    }  
}

int main() {
    char arr[SIZE] = {'1','2','3','4','5'};
    
    printf("Array: ");
    printArr(arr);
    reverseRec(arr, SIZE);
    printf("Reverse: ");
    printArr(arr);
}