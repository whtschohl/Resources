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
    vDeletePoint("myFile3.bin", 3);
}

void vDeletePoint(char *sFilename, int idx)
{
    // var
    FILE *fp = fopen(sFilename, "rb");
    FILE *fpTemp = fopen("temp.bin", "wb");
    int iTotalPoints, j = 0;

    // algo - not writing
    // if (NULL != fp) // assert
    // {
    //     fseek(fp, 0, SEEK_END);
    //     iTotalPoints = (ftell(fp) / sizeof(Point));  
    //     Point *aPtAfterDelete = malloc((iTotalPoints - idx - 1) * sizeof(Point));
    //     if (NULL == aPtAfterDelete) // assert
    //     {
    //         fclose(fp);
    //         printf("Memory allocation failed\n");
    //         return;
    //     }
    //     fseek(fp, idx * sizeof(Point), SEEK_SET);
    //
    //     // Read all points after deleted point
    //     fread(aPtAfterDelete, sizeof(Point), (iTotalPoints - idx -1), fp);
    //     fseek(fp, idx * sizeof(Point), SEEK_SET);
    //
    //     fwrite(aPtAfterDelete, sizeof(Point), (iTotalPoints - idx -1), fp);
    //     fclose(fp);
    //     free(aPtAfterDelete);
    // }
    
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
        fseek(fp, 0, SEEK_SET);

        // Read all points after deleted point
        for (int i = 0; i < iTotalPoints; i++)
        {
            if(i == idx-1)
            {
                i++;
                fseek(fp, sizeof(Point), SEEK_CUR);
            }
            fread(&aPtAfterDelete[j], sizeof(Point), 1, fp);
            j++;
        }
        fseek(fp, idx * sizeof(Point), SEEK_SET);
        fclose(fp);

        fwrite(aPtAfterDelete, sizeof(Point), 4, fpTemp);
        if(0 != remove(sFilename))
        {
            printf("Error: Could not delete file!");
        }
        else
        {
            fclose(fpTemp);
            if(!rename("temp.bin", sFilename))
                printf("Successfully renamed file");
            else    
                printf("Could not rename file");            
        }
        free(aPtAfterDelete);
    }
    else    
        printf("Could not open file");
}
