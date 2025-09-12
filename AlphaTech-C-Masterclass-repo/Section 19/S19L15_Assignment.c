/*
    Assignment
    -------------------------------------------------------
*/

// Defines

#define     _CRT_SECURE_NO_WARNINGS

// Headers

#include <stdio.h>

// Functions

void createAndWriteFile(char* filename, char* string);
void readFile(char* filename);
void appendToFile(char* filename, char* string);
void modifyLineInFile(char* filename, int lnNum, char* string);

// Code

int main()
{
    char file[20] = "asstxt.txt\0";

    printf("\nCreated file text: \n");
    createAndWriteFile(file, "Text for the Assignment");
    readFile(file);

    printf("\nAdded file text: \n");
    appendToFile(file, "\nThis has been added");
    readFile(file);

    printf("\nModified file text: \n");
    modifyLineInFile(file, 2, "This has been modified");
    readFile(file);
}

void createAndWriteFile(char *filename, char *string)
{
    FILE* fp = fopen(filename, "w");

    // assert
    if(NULL == fp)
    {
        printf("Could not open file %s", filename);
        return;
    }

    // Write file
    for (int i = 0; '\0' != string[i]; i++)
    {
        fputc(string[i], fp);
    }

    fclose(fp);
}

void readFile(char *filename)
{
    FILE* fp        = fopen(filename, "r");
    char str[100]   = { 0 };

    // assert
    if(NULL == fp)
    {
        printf("Could not open file %s", filename);
        return;
    }

    // Read file
    while (fgets(str, sizeof(str), fp))
    {
        printf("%s", str);
    }

    fclose(fp);    
}

void appendToFile(char *filename, char *string)
{
    FILE* fp        = fopen(filename, "a"); // "a" open file at last position

    // assert
    if(NULL == fp)
    {
        printf("Could not open file %s", filename);
        return;
    }

    // Append to file
    fprintf(fp, "%s\n", string);

    fclose(fp);
}

void modifyLineInFile(char *filename, int lnNum, char *string) 
{
    FILE *fp = fopen(filename, "r");
    FILE *tmp = fopen("temp.txt", "w");
    char buffer[1024];
    int curLn = 1;
    
    // assert
    if (!fp) {
        printf("Could not open file %s", filename);
        return;
    }   
    if (!tmp) {
        perror("open temp");
        fclose(fp);
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp)) 
    {
        if (curLn == lnNum) 
        {
            fprintf(tmp, "%s", string); 
        } 
        else 
        {
            fputs(buffer, tmp);             
        }
        curLn++;
    }

    fclose(fp);
    fclose(tmp);

    remove(filename);
    rename("temp.txt", filename);
}
