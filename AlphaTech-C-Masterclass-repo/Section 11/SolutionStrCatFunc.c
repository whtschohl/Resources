#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cstrcat(char *destStr, char *sourceStr)
{
    char *concatStr;
    
    int lengthDest, lengthSource;
    lengthDest = strlen(destStr);
    lengthSource = strlen(sourceStr);

    concatStr = (char*)malloc(lengthDest+lengthSource+1);

    for (int i = 0; i < lengthDest; i++)
        concatStr[i] = destStr[i];

    for (int i = 0; i < lengthSource; i++)
        concatStr[lengthDest+i] = sourceStr[i];
        
    concatStr[lengthDest+lengthSource] = '\0';
    
    return concatStr;
    
}

int main()
{
    char str1[] = "AlphaTech-";
    char str2[] = "BalphaTech";
    return 0;
}