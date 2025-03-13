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

int** createLowerTriangular(int n);
int** createUpperTriangular(int n);
void printLowerTriangular(int** a, int n);
void printUpperTriangular(int **a, int n);

// Code
// ------------------------------

int main()
{
    // code
}

int** createLowerTriangular(int n)
{
    int** a;
    a = (int**)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int*)malloc((i + 1) * sizeof(int));
    }
    return;
}

int** createUpperTriangular(int n)
{
    int** a;
    a = (int**)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int*)malloc((n-i) * sizeof(int));
    }
    return;
}

void printLowerTriangular(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (i<j)
                printf("0");
            else
                printf ("%d", a[i][j]);
        }
        printf("\n");
    }
}

void printUpperTriangular(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (i>j)
                printf("0");
            else
                printf ("%d", a[i][j]);
        }
        printf("\n");
    }
}
