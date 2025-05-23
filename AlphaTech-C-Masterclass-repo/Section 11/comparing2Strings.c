// Header

#include <stdio.h>
#include <stdlib.h>

// Function declarations

int iStrLen(char *c);

// Code

int main()
{
    char name[5] = "Tech";
    printf("name length: %d \n", iStrLen(name));
}

int iStrLen(char *c)
{   
    int iCount = 0;
    while (c[iCount] != '\0')
    {
        iCount++;
    }

    return iCount;
}
