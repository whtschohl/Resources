/*
    Exercise
    ==============================

    Write a function that receives a string - "Alpha"
    Return a concatenated string - "AlphaAlpha"
    str need a "\0" at the end of the array

*/

// Header
// -------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions
// -------------------------------

char *strConCat(char *originalStr);

// Code
// -------------------------------

int main()
{
    return 0;
}

char *strConCat(char *originalStr)
{
    char *newStr;
    int lengthOriginal = strlen(originalStr);
    newStr = (char*)malloc(2*lengthOriginal*sizeof(char) + 1); // the +1 is for the \0 at the end of the arr
    for (int i = 0; i < lengthOriginal; i++)
    {
        newStr[i] = originalStr[i];
        newStr[i+lengthOriginal] = originalStr[i];
    }
    newStr[strlen(newStr)] = '\0';
    return newStr;
}
