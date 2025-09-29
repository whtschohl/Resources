#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>
#include    <stdlib.h>

typedef struct point {
    int x;
    int y;
}Point;

// Adding a Point to an Existing File

// A function that take a Point as arguments,
// and adds the Point to the end of the file.

void addPoint(char* filename, Point newPoint)
{
    FILE* fp = fopen(filename, "ab");
    if(fp != NULL)
    {
        fwrite(&newPoint, sizeof(Point), 1, fp);
        fclose(fp);
    }
    else    
        printf("File was not opened..\n");
}