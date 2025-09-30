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

// Functions
void vDeletePoint(char* sFilename, int idx);

// Code
int main()
{
    vDeletePoint("myFile3.bin", 2);
}

void vDeletePoint(char *sFilename, int idx)
{
    // var
    FILE *fp = fopen(sFilename, "rb+");
    int iTotalPoints;

    // algo
    if (NULL != fp) // assert
    {
        fseek(fp, 0, SEEK_END);
        iTotalPoints = (ftell(fp) / sizeof(Point));  
        Point *aPtAfterDelete = malloc((iTotalPoints - idx - 1) * sizeof(Point));
        if (NULL == aPtAfterDelete) // assert
        {
            fclose(fp);
            printf("Memory allocation failed\n");
            return;
        }
        fseek(fp, idx * sizeof(Point), SEEK_SET);

        // Read all points after deleted point
        fread(aPtAfterDelete, sizeof(Point), (iTotalPoints - idx -1), fp);
        fseek(fp, idx * sizeof(Point), SEEK_SET);

        fwrite(aPtAfterDelete, sizeof(Point), (iTotalPoints - idx -1), fp);
        fclose(fp);
        free(aPtAfterDelete);
    }
    
}
