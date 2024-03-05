// Exercise: Print Dynamically Allocated Array
#include <stdio.h>
#include <stdlib.h>

int printArray(int *ptr, int size)
{
    printf("Printing the Grades: \n");
    for (int i=0; i<size; i++)
    {
        printf("grades[%d] = %d\n", i, ptr[i]);
    }
    printf("Done.\n");
}

int inputArray(int *arr, int size)
{
    printf("Enter your grades: \n");
    for(int i=0; i<size; i++)
        scanf("%d", &arr[i]);
}

int main() 
{
    int *grades;
    int arraySize;
    printf("Enter the number of grades that you have: ");
    scanf("%d", &arraySize);
    grades = (int*)malloc(sizeof(int)*arraySize);
    inputArray(grades, arraySize);
    printArray(grades, arraySize);
    return 0;
}