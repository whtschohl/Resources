/*
    Exercise: Comparing Two Textual Files

    The Task is to write a function that takes two filenames as arguments.
    This function will open and compare the content of these files.
    If the content of both files is identical, the function will return 1.
    If the files differ in any way, the function will return 0.
*/

// Preprocessor

#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>
#include    <stdbool.h>

// Functions

bool bIsSameFile(char* file1, char* file2);

// Code

int main()
{
    char file1[10] = { 0 };
    char file2[10] = { 0 };
    
    printf("\nEnter file 1 name: ");
    scanf("%s", file1);
    printf("\nEnter file 2 name: ");
    scanf("%s", file2);

    if(bIsSameFile(file1, file2))
        printf("\n--- Same File ---");
    else
        printf("\n--- Not the same ---");
}

bool bIsSameFile(char *file1, char *file2)
{
    FILE* fp1 = fopen(file1, "r");
    FILE* fp2 = fopen(file2, "r");
    char c1, c2;

    while (!feof(fp1) || !feof(fp2))
    {   
        c1 = fgetc(fp1);
        c2 = fgetc(fp2);
        if(c1 != c2)
            return false;
    }    

    fclose(fp1);
    fclose(fp2);

    return true;
}
