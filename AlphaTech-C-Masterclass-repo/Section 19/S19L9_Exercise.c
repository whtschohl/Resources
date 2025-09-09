/*
    Write a function that receives an input filename.
    The function should read and remove all space characters from the input file
    and create an output file (witht the same content without any spaces)
*/

#define     _CRT_SECURE_NO_WARNINGS

// Headers

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Functions

void removeSpaceInFile(char* file);

int main()
{
    char file[100] = "";
    printf("Enter file name: ");
    scanf("%s", file);
    removeSpaceInFile(file);
    return 0;
}

void removeSpaceInFile(char *file)
{
    char c;
    FILE* pf = fopen(file, "r");
    FILE* pf2 = fopen("output.txt", "w");

    // Remove spaces
    while ((c = fgetc(pf)) != EOF)
    {
        if(!(' ' == c))
            fprintf(pf2, "%c", c);
    }

    fclose(pf);   
    fclose(pf2);  
}
