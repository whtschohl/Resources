/*
    Reverse the Order of Points in a File - Question
    Given a binary file of Points, 
    Write a function that reverses the order of Point in the File.

    My idea:
    - Read points and save them into an array
    - change the order of the points in the array using a swap function
    - rewrite the points into the file in their new location

    Process from Vlad:
    1. Get total number of points -> move pointer to the end. Divide reulst from pointer by the size of a Point.
    2. Read points and save them into an array.
    3. Change the order of the points in the array using a swap function.
    4. Rewrite the points into the file in their new location
*/

#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>
#include    <stdlib.h>

typedef struct point {
    int x;
    int y;
}Point;

void reversePointsInFile(char* filename);
void swapPoints(Point* p1, Point* p2);

int main()
{
    char* filename = "myFile3.bin";

    reversePointsInFile(filename);
}

void reversePointsInFile(char *filename)
{
    FILE *fp = fopen(filename, "rb+");
    
    int iPoints, i, iFilesize;

    // assert
    if (fp != NULL)
    {   
        // Find Total number of points
        fseek(fp, 0, SEEK_END);
        iFilesize = ftell(fp);
        iPoints = (int)(iFilesize / sizeof(Point));
        // Allocate memory
        Point *arrPoints = malloc(iPoints * sizeof(Point));
        if (!arrPoints) 
        {
            fclose(fp);
            printf("Memory allocation failed\n");
            return;
        }

        // Save points in arrPoints
        fseek(fp, 0, SEEK_SET);
        for (i = 0; i < iPoints; i++)
        {
            fread(&arrPoints[i], sizeof(Point), 1, fp);
        }
        
        // Swap Points in array
        for (i = 0; i < (iPoints/2); i++)
        {
            swapPoints(&arrPoints[i], &arrPoints[iPoints - i - 1]);
        }
        

        // Print Points in File
        fseek(fp, 0, SEEK_SET);
        for (i = 0; i < iPoints; i++)
        {
            fwrite(&arrPoints[i], sizeof(Point), 1, fp);
        }

        // Close file
        fclose(fp);
    } else
        printf("Could not open File");
    
    return;
    
}

void swapPoints(Point *p1, Point *p2)
{
    Point temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
