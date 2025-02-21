// 2D Dynamically Allocated Arrays
// =================================
// Header
// ---------------------------------
#include <stdio.h>

// Code
// ---------------------------------
int main()
{
    int** a; // Pointer to int - 1D array; Pointer to Pointer to int - 2D array
    int rows, cols;
    printf("Please enter number of rows: ");
    scanf("%d", &rows);

    a = (int**)calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; i++)
    {
        printf("Please enter number of rows: ");
        scanf("%d", &rows);
        a[i] = (int*)calloc(cols, sizeof(int));        
    }
    
}