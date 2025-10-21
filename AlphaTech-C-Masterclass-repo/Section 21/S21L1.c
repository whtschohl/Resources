/*
    Header files
    ---
    
    - suffix ".h"
    - used to help encapsulation

        what is a headerfile?
        - contains
            1. function declarations
            2. macro definitions
            3. data types
        - headerfiles is the "what", c files are the "how"
        
*/

#include <stdio.h>
#include "math_utils.h"
#include "student.h"

int main()
{
    int num1 = 5, num2 = 7;
    int max = findMax(num1, num2);
    float average = findAverage(num1, num2);
    Student student1;
}
