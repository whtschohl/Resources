#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>
#include    <stdlib.h>

typedef struct point {
    int x;
    int y;
}Point;

/*
    Reverse the Order of Points in a File - Question
    Given a binary file of Points, 
    Write a function that reverses the order of Point in the File.
*/

void reverseFileOfPoints(char* filename)
{
    FILE *fp = fopen(filename, "rb+");
    Point temp;
    if(fp == NULL)
    {
        printf("Failed to open ");
        return;
    }

    // Determine the number of points in the file.
    fseek(fp, 0, SEEK_END);
    int totalPoints = ftell(fp) / sizeof(Point);
    fseek(fp, 0, SEEK_SET);

    // Read Point to Memory.
    Point* pointArray = (Point*)malloc(totalPoints * sizeof(Point));
    fread(pointArray, sizeof(Point), totalPoints, fp);

    // Reverse the array of points ...
    for(int i = 0; i < totalPoints / 2; i++)
    {
        temp = pointArray[i];
        pointArray[i] = pointArray[totalPoints -1 -i];
        pointArray[totalPoints -1 -i] = temp;
    }

    // Write updated array of points to the file.
    fseek(fp, 0, SEEK_SET);
    fwrite(pointArray, sizeof(Point), totalPoints, fp);

    // Cleaning up
    fclose(fp);
    free(pointArray);
}
