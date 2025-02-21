/*  Exercise:
    ==============================

    1. Implement 2 functions that receive a Dynamic 2D array (Pointer to Pointer ..)
                a.  First function should receive 2 rows.
                    The function should SWAP between the 2 rows in O(1). Make it Universal.
                b.  Second function should reveive 2 cloumns. 
                    The function should SWAP between the 2 columns in O(n) 
*/
// ==============================
// Headers
// ------------------------------
#include <stdio.h>
#include <stdlib.h>
// Functions
// ------------------------------
void vFreeMatrix(int ** a, int row);
int** iAllocatedMatrix(int iRows, int iCols);
void vPrint2dDynamicMatrix(int** a, int rows, int cols);
void vSwap2Rows(int **a, int row1, int row2);
void vSwap2Cols(int **a, int col1, int col2, int rows);
void vPopulateMatrix(int **a, int row, int col);
// Code
// -------------------------------
int main()
{
    int **m;
    int iRows, iCols ,iSwapRow1, iSwapRow2, iSwapCol1, iSwapCol2;

    printf("\nEnter number of rows: ");
    scanf("%d", &iRows);
    printf("\nEnter number of columns: ");
    scanf("%d", &iCols);

    m = iAllocatedMatrix(iRows, iCols);
    vPopulateMatrix(m, iRows, iCols);

    printf("\nEnter Row 1 to swap: ");
    scanf("%d", &iSwapRow1);
    printf("\nEnter Row 2 to swap: ");
    scanf("%d", &iSwapRow2);

    printf("\nEnter Column 1 to swap: ");
    scanf("%d", &iSwapCol1); 

    printf("\nEnter Column 2 to swap: ");
    scanf("%d", &iSwapCol2);

    //Quality Input check
   if ((!iSwapCol1) || (!iSwapCol2) || (!iSwapRow1) || (!iSwapRow2))
    {
        printf("No Number in Swap Var");
        return 0;
    }

    if ((iSwapCol1 > iCols) || (iSwapCol2 > iCols) || (iSwapRow1 > iRows) || (iSwapRow2 > iRows))
    {
        printf("Swap row/column doesnt exist");
        return 0;
    }


    // Printing

    printf("\n\nDynamic Matrix:\n");
    vPrint2dDynamicMatrix(m, iRows, iCols);

    vSwap2Rows(m,iSwapRow1,iSwapRow2);
    printf("\n\nSwapped Rows:\n");
    vPrint2dDynamicMatrix(m, iRows, iCols);

    vSwap2Cols(m, iSwapCol1, iSwapCol2, iRows);
    printf("\n\nSwapped Columns:\n");
    vPrint2dDynamicMatrix(m, iRows, iCols);
}

int** iAllocatedMatrix(int iRows, int iCols)
{
    int** a;

    a = (int**)calloc(iRows, sizeof(int*));
    if(!a) return NULL;
    for (int i = 0; i < iRows; i++)
    {
        a[i] = (int*)calloc(iCols, sizeof(int));
        if(!a[i]) 
        {   
            vFreeMatrix(a, i);
            return NULL;
        }
    }
    
    return a;
}

void vFreeMatrix(int ** a, int row)
{
    if(a == NULL) return;

    for (int i = 0; i < row; i++)
        free(a[i]);
    free(a);
    
    printf("Had to free memory\n");
}

void vPrint2dDynamicMatrix(int** a, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {   
        for (int j = 0; j < cols; j++)
            printf("%10d ", a[i][j]);
        printf("\n");
    }           
}

void vSwap2Cols(int **a, int col1, int col2, int rows)
{
    int temp;

    for (int i = 0; i < rows; i++)
    {
        temp = a[i][col1-1];
        a[i][col1-1] = a[i][col2-1];
        a[i][col2-1] = temp;    
    }
}

void vSwap2Rows(int **a, int row1, int row2)
{
    int *temp;

    temp = a[row1-1];
    a[row1-1] = a[row2-1];
    a[row2-1] = temp;
}

void vPopulateMatrix(int **a, int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            printf("Enter number: ");
            scanf("%d", &a[i][j]);
        }    
}