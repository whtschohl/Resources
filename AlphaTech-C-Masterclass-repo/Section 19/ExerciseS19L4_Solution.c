#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char filename[100], extension[10], newFilename[110];
    int i, j;
    int result;

    printf("Enter the current filename with extention: ");
    scanf("%s", filename);
    printf("Enter the new extention for the file: ");
    scanf("%s", extension);

    // Find position of the last '.'
    int dotPosition = -1;
    for (i = 0; '\0' != filename[i]; i++)
    {
        if ('.' == filename[i])
            dotPosition = i;        
    }

    // if '.' was not found in filename, return error
    if(-1 == dotPosition)
    {
        printf("Error: filename does not have an extension.\n")
    }
    
    // Construct new filename up to the last '.'
    for (j = 0; j < dotPosition; j++)
    {
        newFilename[j] = filename[j];
    }

    // Add the new extension
    newFilename[j++] = '.';
    for (i = 0; '\0' != extension[i]; i++, j++)
    {
        newFilename[j] = extension[i];
    }
    
    // Null-terminate the new filename
    newFilename[j] = '\0';

    // Rename the file
    result = rename(filename, newFilename);
    if(0 == result)
        printf("File has been successfully renamed to %s\n", newFilename);
    else    
        printf("File has been not been renamed\n");
}