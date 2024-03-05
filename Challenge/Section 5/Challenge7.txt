// Exercise:
// Write a function that receives an array. 
// The function should cound and print the Frequency of each of the Array's Elements

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

bool isPreviousElement(char* arr, char* ele, int pos)
{
    for(int i; i<pos; i++)
    {
        if (arr[i] == ele)
        {
            return true;
        }
    }
    printf("%c", ele);
    return false;
}

void elementFrequency(char* arr, int size)
{
    for(int i=0; i<size; i++)
    {
        int freq = 0;
        if( isPreviousElement(arr,arr[i],i) == false)
            {
                for(int j=i; j<size; j++)
                    if (arr[i] == arr[j])
                        freq++;
                
                printf(" frequency: %d\n", freq);
            }
    }
}

int main() {
    char arr[SIZE] = {'a','b','b','b','e'};
    
    elementFrequency(arr, SIZE);
}

/*********************************************************************************/
/****************************** RECURSIVE SOLUTION *******************************/
/*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

bool isPreviousElement(char* arr, char ele, int pos)
{
    if (pos < 1)
        return false;

    if (arr[pos - 1] == ele)
        return true;
    return isPreviousElement(arr, ele, pos - 1);
}

int checkFrequency(char* arr, char ele, int size)
{
    if (size < 0)
        return 0;

    if (arr[size] == ele)
        return checkFrequency(arr, ele, size- 1) + 1;
    
    return checkFrequency(arr, ele, size - 1);
}

void elementFrequency(char* arr, int size)
{
    if (size <= 0)
        return; // Terminate the recursion

    elementFrequency(arr, size - 1);
    
    if (!isPreviousElement(arr, arr[size], size))
    {
        printf("\n'%c' comes %d times", arr[size - 1], checkFrequency(arr, arr[size - 1], size));
    }
}

int main() {
    char arr[SIZE] = {'a', 'b', 'b', 'b', 'e'};

    elementFrequency(arr, SIZE);
}
