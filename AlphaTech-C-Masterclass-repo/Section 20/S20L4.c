#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>

typedef struct point {
    int x;
    int y;
}Point;

int main()
{
    Point p1, p2;
    FILE* fp = NULL;

    printf("Enter x1 :");
    scanf("%d", &p1.x);
    printf("Enter y1 :");
    scanf("%d", &p1.y);
    printf("Enter x2 :");
    scanf("%d", &p2.x);
    printf("Enter y2 :");
    scanf("%d", &p2.y);

    fp = fopen("myFile2.bin", "wb");
    if(fp != NULL)
    {
        printf("File was successfully opened for binary writing.. \n");
        fwrite(&p1, sizeof(Point), 1, fp);      // fwrite -> specify address of start copy, specify size of record, # of records, location where to store 
        fwrite(&p1, sizeof(Point), 1, fp);
        fclose(fp);
    }
    return 0;
}