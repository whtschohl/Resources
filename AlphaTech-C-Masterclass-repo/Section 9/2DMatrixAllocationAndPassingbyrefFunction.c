/*
    Exercies
    ==============================

    Write a function that allocates a 2D Dynamic Array and passes it by refrence.

*/

// Header
// ------------------------------

#include <stdio.h>
#include <stdlib.h>

// Functions
// ------------------------------

void vAllocate2DMatrixByRefrence(int ***mat, int n);
void vPrintMatrix(int **mat, int n);

// Code
// ------------------------------

int main()
{
    int **mat;
    int iSize = 3;
    
    vAllocate2DMatrixByRefrence(&mat, iSize);
    
    printf("\nMatrix: \n");
    vPrintMatrix(mat, iSize);

}

void vAllocate2DMatrixByRefrence(int ***mat, int n)
{
    *mat = (int**)malloc(n*sizeof(int*));
    
    // poputate matrix

    for (int i = 0; i < n; i++)
    {
        (*mat)[i] = (int*)malloc(n*sizeof(int));
        for (int j = 0; j < n; j++)
        {
            printf("\nEnter a number: ");
            scanf("%d", &(*mat)[i][j]);
        }
    }

    return;
}

void vPrintMatrix(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {   
        for (int j = 0; j < n; j++)
            printf("%10d ", mat[i][j]);
        printf("\n");
    }
}