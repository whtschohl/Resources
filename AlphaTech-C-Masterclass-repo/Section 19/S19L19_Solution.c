#define     _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Write a function that receives an input filename.
    The function should read and remove all space characters from the input file
    and create an output file (witht the same content without any spaces)
*/

void removeSpaceChar(char* inputFilename, char* outputFilename)
{
    char currentCharacter;
    FILE* inFile;
    FILE* outFile;
    inFile = fopen(inputFilename, "r");
    outFile = fopen(outputFilename, "w");
    if(inFile != NULL && outFile != NULL)
    {
        while (!feof(inFile))
        {
            currentCharacter = fgetc(inFile);
            if(currentCharacter != ' ')
                fputc(currentCharacter, outFile);
        }
    }
    // Closing just the files managed to open
    if (inFile != NULL)
        fclose(inFile);
    if (outFile != NULL)
        fclose(outFile);
}

int main()
{
    char inputFileName[20] = { 0 };
    char outputFileName[20] = { 0 };

    printf("Enter a file name for the input file: ");
    scanf("%s", inputFileName);
    
    printf("Enter a file name for the output file: ");
    scanf("%s", outputFileName);

    removeSpaceChar(inputFileName, outputFileName);
}