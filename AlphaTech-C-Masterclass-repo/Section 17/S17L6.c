/*    An array of Pointers to function    */

#include <stdio.h>
#include <stdlib.h>

// Functions

void addition(int a, int b)
{
    printf("%d + %d = %d\n", a, b, a+b);
}

void subtraction(int a, int b)
{
    printf("%d - %d = %d\n", a, b, a-b);
}

void multiplication(int a, int b)
{
    printf("%d x %d = %d\n", a, b, a*b);
}

void division(int a, int b)
{
    if (b != 0)
        printf("%d : %d = %d\n", a, b, a/b);
    else
        printf("Cannot divide by 0!\n")    ;
}

void remainder(int a, int b)
{
    if (b != 0)
        printf("%d %% %d = %d\n", a, b, a%b);
    else
        printf("Cannot divide by 0!\n")    ;
}

int main()
{
    void (*funPtrArray[])(int,int) = {addition, subtraction, multiplication, division, remainder};
    int num1, num2, choice;
    //char op;

    printf("Choose: \n0 - addition \n1 - subtraction \n2 - multiplication \n3 - division \n4 - remainder \n");
    //printf("Enter the operation that you want to perform (+,-,*,/): ");
    scanf("%d",&choice);
    printf("Enter num 1: ");
    scanf("%d",&num1);
    printf("Enter num 1: ");
    scanf("%d",&num2);

    (*funPtrArray[choice])(num1, num2);
    
    /*
    switch (op)
    {
        case '+':
            addition(num1, num2);
            break;
        
        case '-':
            subtraction(num1, num2);
            break;

        case '*':
            multiplication(num1, num2);
            break;

        case '/':
            division(num1, num2);
            break;

        default:
            printf("No relevant operation... try again..");
            break;
    } */

}