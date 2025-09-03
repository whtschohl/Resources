// "rename" function - practicle examples
// int rename(const char *oldFileName, const char *newFileName)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// int main()
// {
//     int result;
//     result = rename("myFile.txt", "yourNewFile.txt");
//     if(result == 0)
//         printf("File has been successfully renamed\n");
//     else
//         printf("Rename didn't work\n");
// }

//
// Move with Rename
//

int main()
{
    int result;
    result = rename("myFile.txt", "/DIR/myFile.txt"); // use with caution - may overrite existing file with the same name
    if(result == 0)
        printf("File has been successfully renamed\n");
    else
        printf("Rename didn't work\n");
}