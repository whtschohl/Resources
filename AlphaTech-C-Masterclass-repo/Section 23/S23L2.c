/*
    ---
    Why do you need to use constants?
    ---

    1. Performance. 
        - Parallelism friendly
        - Lower CPU usage than var
    
    2. Defense
        - Cant accidently change the values

    3. Code Readability

    ---    
    When do you need to use constants?
    ---

    1. use it whenever it's possible
    2. if you are sure variables won't need to change in the future

    ---
    Why to use constants, not literal Numbers
    ---

    Task:       calculate the exact amount of taxes a given company should pay. tax = 20%.
    Solution:   Use "const int tax = 20;" to make sure code more readable

*/

/**************************************************************************************************/

// Example
// Task: find and print the avg grade of a given array

#include <stdio.h>

// void findAverage(int *gradesArray, int size) // original
void findAverage(int *gradesArray, const int size) // improved
{
    int totalSum = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        totalSum += gradesArray[i];
        // size = size -1; // Some mistake you've made
    }
    printf("Average Grade = %lf\n", totalSum/size);
}

int main()
{
    int grades[3] = {80,90,85};
}