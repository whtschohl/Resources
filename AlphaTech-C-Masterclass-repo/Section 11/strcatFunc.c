/*
    Creating my own strcat function
    Function that receives 2 strings
    Concatenates (combines) them in 1 longer string
*/

// Header

#include <stdio.h>
#include <stdlib.h>

// Function declarations

void vStrCat(char *strD, char *strS);

// Code

int main()
{
    char strDestination[20] = "Hello ";
    char strSource[] = "World!";
    vStrCat(strDestination, strSource);
    printf("string after concatenation: %s \n", strDestination);
}

void vStrCat(char *strD, char *strS)
{   
    // using pointer arithmatic

    while (*strD != '\0')
        *strD++;

    while (*strS != '\0')
    {
        *strD = *strS;
        *strS++;
        *strD++;
    }
}