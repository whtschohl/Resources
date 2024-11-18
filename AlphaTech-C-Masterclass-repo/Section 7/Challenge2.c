/*
Print Dynamically Allocated Array
----------------------------------

note: grades array is not initialised
*/

#include <stdio.h>
#include <stdlib.h>

void printArray(int* ptr, int size)
{
    int i;
    printf("Printing grades:\n");
    for (i = 0; i < size; i++)
    {
        printf("grades[%d] = %d\n", i+1, ptr[i]);
    }
    printf("DONE.\n");
}

int main()
{
    int *grades;
    int arraySize;
    printf("Enter the number of grades that you have: ");
    scanf("%d", &arraySize);
    grades = (int*)malloc(sizeof(int)*arraySize);
    printArray(grades, arraySize);
    return 0;
}