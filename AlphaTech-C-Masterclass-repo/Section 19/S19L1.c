#include <stdio.h>
#include <stdlib.h>

int main()
{
    int result;
    result = remove("myFile.txt");
    if(0 != result)
        printf("Error occurred while trying to remove the file\n");
    else  // result = 0
        printf("File has been successfully removed");
    }