#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int grades[] = {50, 60, 70, 85, 100};
    int* ptr = grades;

    for (int i = 0; i < 5; i++)
    {
        /* code */
        ptr++;
    }
    
    
    // *ptr --> 50
    //ptr++;
    // *ptr --> 60
}