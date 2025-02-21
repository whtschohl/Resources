// Free a Dynamic Maxix
// =============================
// Headers
#include <stdio.h>
// Functions
// -----------------------------
void freeMatrix(int** a, int row);
// Code
// -----------------------------
int main()
{

}

void freeMatrix(int ** a, int row)
{
    /*  Note: 

        "free(a)" will only free the memory for the 
        first array that contains the other arrays.

        IT WILL NOT FREE THE ARRAYS WITHIN THE ARRAY 
        THAT HAS BEEN FREED
    */

    for (int i = 0; i < row; i++)
        free(a[i]);
    free(a);   
}