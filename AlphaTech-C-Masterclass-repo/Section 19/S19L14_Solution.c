#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>

/*
    Exercise: Comparing Two Textual Files

    The Task is to write a function that takes two filenames as arguments.
    This function will open and compare the content of these files.
    If the content of both files is identical, the function will return 1.
    If the files differ in any way, the function will return 0.
*/

int compareTwoFiles(char* filename1, char* filename2)
{
    FILE* fp1 = NULL;
    FILE* fp2 = NULL;

    char ch1, ch2;

    fp1 = fopen(filename1, "r");
    fp2 = fopen(filename2, "r");

    // assert.. 

    if(fp1 == NULL)
    {
        printf("File1 couldn't be opened\n");
        return -1;
    }
    if(fp2 == NULL)
    {
        printf("File2 couldn't be opened\n");
        fclose(fp1);
        return -1;
    }

    ch1 = fgetc(fp1);
    ch2 = fgetc(fp2);
    
    while((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2))
    {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);
    }

    fclose(fp1);
    fclose(fp2);

    if(ch1 == ch2)
        return 1;
    else 
        return 0;
}

int main()
{
    printf("%d", compareTwoFiles("f1.txt", "f3.txt"));
}