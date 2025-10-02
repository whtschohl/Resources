#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>
#include    <stdlib.h>

typedef struct point {
    int x;
    int y;
}Point;

/*
    Exercise: Deleting a Point from the File
    ---
    Write a function that deletes a specific point from a file of points.
*/

void deletePoint(char* filename, int index)
{
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }
    FILE* tempFP = fopen("temp.bin", "wb");
    if(fp == NULL)
    {
        printf("Unable to open temporary file.\n");
        fclose(fp);
        return;
    }

    Point p;
    int currentIndex = 1;
    while(fread(&p, sizeof(Point), 1, fp))
    {
        if(currentIndex != index)
            fwrite(&p, sizeof(Point), 1, tempFP);
        currentIndex++;
    }

    fclose(fp);
    fclose(tempFP);
    if(remove(filename) == 0)
        if(rename("temp.bin", filename != 0))
            printf("Couldn't rename the temp file..");

}
