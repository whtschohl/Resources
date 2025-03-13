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

void allocate2DMatrixByRef(int ***mat, int rows, int columns);

// Code
// ------------------------------

int main()
{

}

void allocate2DMatrixByRef(int ***a, int rows, int columns)
{
    int** myMat;
    int i;
    myMat = (int**)calloc(rows, sizeof(int));
    if(!myMat) return Null;
    for (i = 0; i < rows; i++)
    {
        myMat[i] = (int*)calloc(columns, sizeof(int));
        if (!myMat)
        {
            // Free Matrix
            return NULL;
        }
    }
    *a = myMat;

    /*
        V2:

        int i;
        *a = (int**)calloc(rows, sizeof(int));
        if(!(*a)) return Null;
        for (i = 0; i < rows; i++)
        {
            (*a)[i] = (int*)calloc(columns, sizeof(int));
            if (!(*a))
            {
                // Free Matrix
                return NULL;
            }
        }

    */
}