#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>

typedef struct point {
    int x;
    int y;
}Point;

void mulPointBy3(char* filename, unsigned int choice)
{
    FILE* fp = fopen(filename, "rb+");
    Point p;
    if(fp != NULL)
    {
        fseek(fp, (choice-1)*sizeof(Point), SEEK_SET);
        fread(&p, sizeof(Point), 1, fp);
        p.x *= 3;
        p.y *= 3;
        fseek(fp, (-1) * (int)sizeof(Point), SEEK_CUR);
        fwrite(&p, sizeof(Point), 1, fp);
        fclose(fp)
    }
}

/* 
    Note: 

    The following code will write over the next point. fp increases with the fread() function.
    So we will need to move 1 point back. Use fseek() before writing

    if(fp != NULL)
    {
        fseek(fp, (choice-1)*sizeof(Point), SEEK_SET);
        fread(&p, sizeof(Point), 1, fp);
        p.x *= 3;
        p.y *= 3;
        fwrite(&p, sizeof(Point), 1, fp);
        fclose(fp)
    }
*/