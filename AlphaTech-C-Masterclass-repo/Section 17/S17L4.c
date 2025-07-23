/*
    Coding Example with Pointers Functions
*/

#include <stdio.h>
#include <stdlib.h>

void ageFunc(int age)
{
    printf("Your age is: %d\n", age);
}

int main()
{
    int age;
    void (*pf)(int); // We've created a "pointer to a function"
    printf("Enter your age: ");
    scanf("%d", &age);

    pf = &ageFunc;
    printf("The address of the function (&ageFunc) is: %p\n", pf);
    pf = ageFunc;
    printf("The address of the function (&ageFunc) is: %p\n", pf);

    ageFunc(age);
    return 0;
}