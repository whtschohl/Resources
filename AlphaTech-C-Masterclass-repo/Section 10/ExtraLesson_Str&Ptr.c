// Header
// -------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions
// -------------------------------

// Code
// -------------------------------

int main()
{
    char charsArray[] = {'H', 'e', 'y', '\0'};          // Option 1
    char str[] = "Hey";                                 // Option 2
    char *str2 = "Hello";                               // Option 3

    /* Option 1*/

    char *tempPtr;
    tempPtr = charsArray;
    tempPtr[0] = 'G';
    
    printf("Printed from tempPtr: %s \n", tempPtr);
    printf("Printed from charsArray: %s \n", charsArray);
    

    /* Option 2 
    
    Option 2 is fully attached to the string - bound/static way. This str can be modified - not created in ROM
     
    */
    printf("Printed from str: %s \n", str);
    str = "Good-Bye";
    printf("Printed from str: %s \n", str);
    
    /* Option 3
    
    Option 3 uses up more mem. -> mem created for "Hello" & mem created for the pointer *str2, AND is not attatched to the string.
            This means that it can be easily changed like below. The Hello txt will be put into Read Only Memory in this case (Cant modify).
    
    */
    printf("Printed from *str2: %s \n", str2);
    str2 = "Good-Bye";
    printf("Printed from *str2: %s \n", str2);

    return 0;
}