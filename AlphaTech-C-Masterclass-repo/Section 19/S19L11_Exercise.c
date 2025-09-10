#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>


// Exercise: Sorting Numbers from a File into Odd and Even Files

// The task is to write a function that accepts a filename as an argument.
// This file contailns integer numbers seperated by space characters.
// Based on the integers in this source file, the function should generate 2 new files:
// "odd.txt" & "even.txt"
// These files should hold the odd and even values from the source file, respectively.

// Functions

void separateNum(char *file);

// Code

int main()
{
    char file[10] = { 0 };
    printf("\nEnter file name: ");
    scanf("%s", file);

    separateNum(file);
    return 0;
}

void separateNum(char *file)
{
    FILE* fp        = fopen(file, "r");
    FILE* fpOdd     = fopen("odd.txt", "w");
    FILE* fpEven    = fopen("even.txt", "w");
    int num;

    // assert
    if((!fp) | (!fpOdd) | (!fpEven))
    {   
        printf("Error in opening file");
        return;
    }
    
    while(!feof(fp))
    {
        fscanf(fp, "%d", &num);
        printf("%d", num);
        if(num % 2)
        {
            fprintf( fpOdd, "%d", num);
            fputc(' ', fpOdd);
        }
        else    
        {
            fprintf( fpEven, "%d", num);
            fputc(' ', fpEven);
        }     
    }

    fclose(fp);
    fclose(fpEven);
    fclose(fpOdd);
}
