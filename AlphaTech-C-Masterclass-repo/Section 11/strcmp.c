/*
    Exercise: compare string

    str1 > str2 -> 1
    str2 < str2 -> -1
    str1 = str2 -> 0
*/

#include <stdio.h>
#include <stdlib.h>

int iStrCmp(char *str1, char *str2);
int iGetStrLen(char *str);

int main()
{
    char *name1 = "Mike";
    char *name2 = "Maye";

    printf("result: %d\n", iStrCmp(name1, name2));
}

int iStrCmp(char *str1, char *str2)
{
    int iStr1Len = iGetStrLen(str1);
    int iStr2Len = iGetStrLen(str2);
    
    if (iStr1Len > iStr2Len)
        return 1;
    else if (iStr1Len < iStr2Len)
        return -1;
    else
        return 0;   
    
}

int iGetStrLen(char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    
    return len;
}
