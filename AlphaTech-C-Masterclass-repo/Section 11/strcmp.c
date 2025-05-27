/*
    Exercise: compare string lexicographical 
    Basically, which one comes first alphabetically

    str1 > str2 -> 1
    str2 < str2 -> -1
    str1 = str2 -> 0
*/

#include <stdio.h>
#include <stdlib.h>

int iStrCmp(char *str1, char *str2);

int main()
{
    char *name1 = "Apple";
    char *name2 = "Banana";

    printf("result: %d\n", iStrCmp(name1, name2));
}

int iStrCmp(char *str1, char *str2)
{
    if (*str1 == *str2)
    {
        str1++;
        str2++;
    } else
    {        
        if (str1 > str2)
            return 1;
        else if (str1 < str2)
            return -1;
        else
            return 0;   
    }
        
}
