// Basic concept of recursive programming - factorial
/*

Steps to creating recursive functions
--------------------------------------------------------------------------------------

1) Initialise the Alogorithm with a seed value
2) check to see if the current value matches the base case (return base value if yes)
3) Redefine the answer in smaller/simpler terms
4) Run the answer on the sub-problem
5) Combine the results in the formulation of the answer
6) Return results.

*/

#include <stdio.h>

int factorial(int n) // 1
{
    if (n == 1) // 2
        return 1; // 2.1

    return n * factorial(n-1);// 3,4,5,6
}

int main()
{
    printf("%d", factorial(4));
}