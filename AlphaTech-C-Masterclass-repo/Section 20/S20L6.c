#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>

/*
    Search for a specific point in a file. Reading
*/
typedef struct point {
    int x;
    int y;
}Point;

int main()
{
    Point targetPoint;  // This point we're looking for.
    Point pointInFile;  // Will be used to read a point from the file.
    FILE* fp = fopen("myFile3.bin", "rb");
    
    printf("What is the point you're looking for?\n");
    printf("Enter x: ");
    scanf("%d", &targetPoint.x);
    printf("Enter y: ");
    scanf("%d", &targetPoint.y);

    if (fp != NULL)
    {
        while (!feof(fp))
        {
            fread(&pointInFile, sizeof(Point), 1, fp);
            if((pointInFile.x == targetPoint.x) && (pointInFile.y == targetPoint.y))
                printf("Your point was found in the file!!\n");
        }
        fclose(fp);
    }
    return 0;
    

}
