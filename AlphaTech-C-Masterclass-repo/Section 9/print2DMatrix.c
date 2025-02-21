// 2D Dynamically Allocated Arrays
// =================================
// Header
// ---------------------------------
#include <stdio.h>
// Functions
// ---------------------------------
void print2dDynamicMatrixx(int** a, int rows, int cols);
// Code
// ---------------------------------
int main()
{
    // create matrix
    // Assign Values
    // Print Matrix
}

void print2dDynamicMatrixx(int** a, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            // a[i][j]
            printf("%10d ", a[i][j]);
        }
        printf("/n");
               
}