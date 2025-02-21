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
void swapRows(void **a, int row1, int row2);
void swapCols(int **a, int col1, int col2);
// Code
// -------------------------------
int main()
{

}

void swapRows(void **a, int row1, int row2)
{
    void *temp;
    temp = a[row1];
    a[row1] = a[row2];
    a[row2] = temp;
}

void swapCols(int **a, int col1, int col2)
{
    int temp;

    for (int i = 0; i < count; i++)
    {
        temp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = temp;
    }   
}
