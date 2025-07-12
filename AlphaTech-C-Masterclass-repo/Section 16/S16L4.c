#include <stdio.h>
#include <stdlib.h>

// This example emphasizes that a struct is going to be aligned to the largest Type Alignment Requirement
// ** And that's to make sure that this type fits exactly where it should! **//

typedef struct point
{
    char x;
    int z;
    double y;    
}Point; 

/*  
    Note: saveing space by putting the data type int after char in the struct. changing it from
    24 to 16. 
    
    Optimising the memory in structs saves memory, and reduces execution time. Reduces execution 
    time because it reduces the amount of operation needed to access the memory. 
    (double check me on this)
*/

void main()
{
    unsigned int totalStructBytes = sizeof(Point); 
    Point p1;

    p1.x = 0xFF;
    // Note: the information in "y" is not going to be that readable since it's stored in a "double" type
    p1.y = 0x1234;      // 8 bytes = 16 hexadecimal characters
    p1.z = 0x6789ABCD;  // 4 bytes = 8  hexadecimal characters

    printf("Size: %d", totalStructBytes);
}