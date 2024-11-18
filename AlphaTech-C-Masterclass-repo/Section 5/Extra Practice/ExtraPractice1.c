// write a recursive function to check if an array is a palindrome (reads the same from right to left and left to right)
// the function should return a 1 if it is a palindrome, and a 0 if it isn't a palindrome.
// For example:
//              121     --> 1
//              12342   --> 0
//              987789  --> 1

#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

int isPalindrome(int* arr, int size)
{
    if (size <= 1)
        return 1;

    if (arr[0] != arr[size-1])
        return 0;
    else
        return isPalindrome(arr + 1, size - 2);
}

int main() {
    
    int arr[3] = {1, 2, 1};
    printf("%d", isPalindrome(arr, 3));

    return 0;
}