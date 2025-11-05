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

int areAllLettersIncluded(char* seq1, int size1, char* seq2, int size2)
{
    int i;
    int countArr[26] = { 0 };

    // Building a counting array for appearances of all caracters in seq2
    for(i = 0; i < size2; i++)
        countArr[seq2[i] - 'a']++;

    // // Option 1
    // // Removing all appearances of all characters in seq1
    // for(i = 0; i < size2; i++)
    //     countArr[seq2[i] - 'a']--;
    // // Looking if there's any negative number to indicate
    // // that not all characters of seq1 are included
    // for(i = 0; i < 26; i++)
    //     if(countArr[i] < 0)
    //         return 0;

    // Option 2
    // Removing all appearances of all characters in seq1
    // AND
    // Looking if there's any negative number to indicate
    // that not all characters of seq1 are included in seq2
    for (i = 0; i < size1; i++)
    {
        countArr[seq1[i]-'a']--;
        if(countArr[i] < 0)
            return 0;
    }

    return 1;
}

int main()
{
    char seq1[SIZE1] = {'l','o','l'};
    char seq2[SIZE2] = {'l','o','r','d'};

    int res = areAllLettersIncluded(seq1, SIZE1, seq2, SIZE2);
}
