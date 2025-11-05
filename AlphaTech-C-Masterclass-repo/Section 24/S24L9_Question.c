/***************************************************************************************************
 *  EXERCISE:   areAllLettersIncluded - Question
 *
 *  TASK:       Develop a function that receives 2 sequences of lowercase letters and their sizes.
 *              
 *              The functions should return 1 if all the letters of the first sequence appear in the
 *              second sequence. Otherwise, it should return 0.
 * 
 *              * Note: In this exercise, we're not talking about finding if there's a "sub-string"
 *              but rather, only if the letters appear (we do not caare about the order).
 * 
 *  EXAMPLE:    1. Seq1: {'d','o','g'}  Seq2: {'g','o','o','d'}     The function should return 1
 *              2. Seq1: {'d','o','g'}  Seq2: {'c','a','t'}         The function should return 0
 *              3. Seq1: {'l','o','l'}  Seq2: {'l','o','r','d'}     The function should return 0
***************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE1 3
#define SIZE2 4

int areAllLettersIncluded(char *seq1, int size1, char *seq2, int size2)
{
    int *count1, *count2;
    int i,j;

    count1 = (int*)calloc(size1, sizeof(int));
    count2 = (int*)calloc(size2, sizeof(int));

    for (i = 0; i <= size1; i++)
        for (j = 0; j < size2; j++)
            if (seq1[i] == seq2[j])
            {
                count1[i]++;
                count2[j]++;
            }
        
    for(i = 0; i < size1; i++)
        if (0 == count1[i])
        {
            free(count1);
            free(count2);
            return 0;
        }
    
    for(i = 0; i < size2; i++)
        if (0 == count2[i])
        {
            free(count1);
            free(count2);
            return 0;
        }
        
    free(count1);
    free(count2);
    return 1;
}

int main()
{
    char seq1[SIZE1] = {'l','o','l'};
    char seq2[SIZE2] = {'l','o','r','d'};

    int res = areAllLettersIncluded(seq1, SIZE1, seq2, SIZE2);
}