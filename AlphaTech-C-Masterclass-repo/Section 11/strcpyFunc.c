// Exercies: create a function that copies a string into another variable

// Header
// ----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// function definitions
// ----------------------------------------------------------------------

void vStrCpy(char *dest, char *src);

// Code
// ----------------------------------------------------------------------

int main()
{
    char str1[5] = "Tech";
    char str2[10];

    vStrCpy(str2, str1);

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}

void vStrCpy(char *dest, char *src)
{
    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
