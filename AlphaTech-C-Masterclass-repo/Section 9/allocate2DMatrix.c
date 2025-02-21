// 2D Dynamically Allocated Arrays
// =================================
// Header
// ---------------------------------
#include <stdio.h>
// Private functions
// ---------------------------------
int** allocated2DMatrix();
int** allocated2DMatrixV2(int iRows, int iCol);
// Code
// ---------------------------------
int main()
{
    int** iMatrix;
    int iRows, iCols;

    printf("Enter number of rows for the 2D Matrix");
    scanf("%d", &iRows);

    printf("Enter number of columnss for the 2D Matrix");
    scanf("%d", &iCol);

    iMatrix = allocated2DMatrix();
}

int** allocated2DMatrix()
{
    int** a;
    int iRows, iCol;

    printf("Enter number of rows for the 2D Matrix");
    scanf("%d", &iRows);

    a = (int**)calloc(iRows, sizeof(int*));
    if(!a) return NULL;
    for (int i = 0; i < iRows; i++)
    {
        printf("Enter number of columnss for the 2D Matrix");
        scanf("%d", &iCol);
        a[i] = (int*)calloc(iCol, sizeof(int));
        if(!a[i])
        {
            // ... todo ... (free matrix. Or could cause memory leaks) 
        }
    }
    
    return a; //a has the address that will point to everything else in the matrix
}

int** allocated2DMatrixV2(int iRows, int iCols)
{
    int** a;

    a = (int**)calloc(iRows, sizeof(int*));
    if(!a) return NULL;
    for (int i = 0; i < iRows; i++)
    {
        
        a[i] = (int*)calloc(iCol, sizeof(int));
        if(!a[i])
        {
            // ... todo ... (free matrix. Or could cause memory leaks) 
        }
    }
    
    return a; //a has the address that will point to everything else in the matrix
}