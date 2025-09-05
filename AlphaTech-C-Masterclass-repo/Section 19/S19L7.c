/*
    Practical Example - demonstrating the usage of ftell(), fseek(), and rewind() functions
    -----------------------------------------------------------------------------------------

*/

#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>

int main()
{
    int pos;
    FILE* fp = fopen("myFile.txt", "r");
    // assert ...

    // ftell()

    // pos = ftell(fp);
    // printf("Position in File = %d\n", pos);
    // fgetc(fp);
    // pos = ftell(fp);
    // printf("Position in File = %d\n", pos);
    // fgetc(fp);
    // pos = ftell(fp);
    // printf("Position in File = %d\n", pos);
    // fgetc(fp);

    // fseek()

    // fseek(fp, 5, SEEK_END);

    // rewind()

    rewind(fp);
    
    // close file

    fclose(fp);
}