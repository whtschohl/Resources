#include <stdio.h>
#include <stdlib.h>

//strcpy(char *strDestination, char *strSrc)

char *strcpy(char *destindation, char *source)
{
    char *tempPtr;
    int i = 0;
    tempPtr = destindation;

    while (source[i] != '\0')   // Till we got to the end of the source string
    {
        destindation[i] = source[i];
        i++;
    }
    destindation[i] = '\0';

    return tempPtr;

}

int main()
{
    char myNickName[] = "AlphaTech";
    char copyOfNickName[30];
    char *tempResult;

    tempResult = strcpy(copyOfNickName, myNickName);

    printf("The new copied t string is: %s \n", tempResult);
    printf("The new copied t string is: %s \n", copyOfNickName);

    return 0;
}