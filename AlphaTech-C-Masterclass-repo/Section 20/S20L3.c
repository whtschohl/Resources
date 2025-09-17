#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>

/*
    Writing a Structure Record to a File
    (gotta open .bin in hex editor ext)
*/

typedef struct point {
    int x;
    int y;
}Point;

int main()
{
    Point p = {3,5};
    FILE* fp = fopen("myFile.bin", "wb");
    if(fp !=NULL)
    {
        printf("File was successfully opened for binary writing.. \n");
        fwrite(&p, sizeof(Point), 1, fp);
        fclose(fp);
    }
    return 0;
}