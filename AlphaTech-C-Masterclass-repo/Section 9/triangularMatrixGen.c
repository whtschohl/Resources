/* 

    	Exercise
   ==============================

    Write 2 functions that should: 
        1. Create a "Lower Triangular Matrix" and return it. 
        2. Create an "Upper Triangular Matrix" and return it. 

*/

// Header
// ------------------------------

#include <stdio.h>
#include <stdlib.h>

// Functions
// ------------------------------

int** lowerTriMat(int **a, int iSize);
int** upperTriMat(int **a, int iSize);
void vPrintLower(int** a, int iSize);
void vPrintUpper(int **a, int iSize);
void vfreeMatrix(int** a, int row);

// Code
// ------------------------------

int main()
{
    int **ppiLower, **ppiUpper;
    int iSize = 3;

    ppiLower = lowerTriMat(ppiLower, iSize);
    printf("\nLower Matrix: \n");
    vPrintLower(ppiLower, iSize);

    ppiUpper = upperTriMat(ppiUpper, iSize);
    printf("\nUpper Matrix: \n");
    vPrintUpper(ppiUpper, iSize);
}

int** lowerTriMat(int **a, int iSize)
{   
    a = (int**)calloc(iSize, sizeof(int*));
    for (int i = 0; i < iSize; i++)
    {
        a[i] = (int*)calloc(i, sizeof(int));
        if (!a[i]) 
        {   
            vfreeMatrix(a, i);
            return NULL;
        }

        for (int j = 0; j <= i; j++)
            a[i][j] = 1;
    }
    return a;
}

int** upperTriMat(int **a, int iSize)
{   
    a = (int**)calloc(iSize, sizeof(int*));
    if (a==NULL)           
    {   
        printf("FAILURE!");
        return NULL;
    }
    for (int i = 0; i < iSize; i++)
    {   
        if ((iSize - i) > 0)
        {   
            a[i] = (int*)calloc((iSize-i)-1, sizeof(int));
            if (a[i]==NULL)           
            {   
                printf("FAILURE!");
                vfreeMatrix(a, i);
                return NULL;
            }
            for (int j = 0; j < iSize; j++)
                a[i][j] = 1;            
        } else
            a[i] = NULL;
    }
    
    return a;
}

void vPrintLower(int **a, int iSize)
{
    for (int i = 0; i < iSize; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%10d ", a[i][j]);
        }
        printf("\n");
    }
}

void vPrintUpper(int **a, int iSize)
{
    
    
    for (int i = 0; i < iSize; i++)
    {
        for (int j = 0; j < (iSize-i); j++)
        {
            printf("%10d ", a[i][j]);
        }
        printf("\n");
    }
}

void vfreeMatrix(int **a, int row)
{
    for (int i = 0; i < row; i++)
        free(a[i]);
    free(a);  
}
