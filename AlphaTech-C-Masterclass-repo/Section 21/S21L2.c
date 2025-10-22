/***************************************************************************************************
    Macros
    ---

    What is a Macro?
    - a macro is a name given to a certain block of statements as a preprocessing directive


***************************************************************************************************/

#include <stdio.h>

// Example 1
// #define VALUE 5
//
// int main()
// {
//     int num = VALUE;
//     int average = (5+10+VALUE) / 3;
// }

// Example 2
// #define PI 3.14159
// #define SQUARE(X) ((X) * (X))
//
// int main()
// {
//     double radius = 5.0;
//     double area = PI * SQUARE(radius);
//
//     printf("The area of the circle is %.2f\n", area);
//
//     return 0;
// }

// Example 3
// #define MAX(a, b) ((a) > (b) ? (a) : (b))
//
// int main()
// {
//     int num1 = 10, num2 = 20;
//     printf("The maximum between %d and %d is %d.\n", num1, num2, MAX(num1, num2));
//     return 0;
// }

// Example 4
// Hash operator 
// - preprosessor operator and converts parameter to string
// #define TO_STRING(x) #x
// //
// int main()
// {
//     printf("%s\n", TO_STRING(Hello World));
//     return 0;
// }

// Example 5
//
// #define DISPLAY_INTEGER(x)                  printf(#x " = %d..!\n", x)
// #define DISPLAY_FLOAT(x)                    printf(#x " = %f..!\n", x)
// #define DISPLAY_ANY_VALUE(x, placeholder)   printf(#x " = %" #placeholder "..!\n", x)
// //
// int main()
// {
//     int num = 10;
//     float num2 = 15.3;
// //
//     DISPLAY_INTEGER(num);
//     DISPLAY_FLOAT(num2);
//     DISPLAY_ANY_VALUE(num, d);
// }

// Example 6
// Predefined Macros
    // __DATE__: the current date as a character literal in "MM DD YYYY" format
    // __TIME__: the current time as a character literal in "HH:MM:SS" format
    // __FILE__: the current filename as a character literal
    // __LINE__: the current line number as a character literal
// int main()
// {
//     printf("This program was compiled on %s at %s.\n", __DATE__, __TIME__);
//     return 0;
// }

//Example 7
// #define PRINT_LOCATION printf("At %s, line %d.\n", __FILE__, __LINE__)
// int main()
// {
//     PRINT_LOCATION;
//     return 0;
// }
