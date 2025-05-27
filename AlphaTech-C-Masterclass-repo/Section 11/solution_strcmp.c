#include <stdio.h>
#include <stdlib.h>

//"1", "-1", "0"

int strcmp(char *str1, char *str2)
{
    int i = 0, flag = 0;
    while (flag == 0) // as long as we didnt find any different characters
    {
        /* code */
        if(str1[i] < str2[i])
            flag = -1;
        else if (str1[i] > str2[i])
            flag = 1;
        
        if(str1[i] == '\0') // ab abb
            break;

        i++;
    }

    return flag;
    
}

int main()
{
    char *str1 = "AlphaTech";
    char *str2 = "BalphaTech";



    return 0;
}