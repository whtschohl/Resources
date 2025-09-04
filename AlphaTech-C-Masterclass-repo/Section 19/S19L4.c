/*
    "rename" function - practical exercise

    Task
    -----------------------------------------
    - Write down a program that will take a 
        file name (including the file extention)
        and a new file extention and change the
        name of the file to have the new file 
        extention

        eg myFile.txt -> myFile.csv

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int result;
    char file[] = "myFile.txt";
    char extention[] = ".csv";
    char fileName[100];
    int ext;

    ext = strchr(file, '.') - file;
    
    strncpy(fileName, file, ext);
    fileName[ext] = '\0';   // null terminate

    result = rename(file, strcat(fileName, extention)); // use with caution - may overrite existing file with the same name
    if(result == 0)
        printf("File has been successfully renamed\n");
    else
        printf("Rename didn't work\n");
}