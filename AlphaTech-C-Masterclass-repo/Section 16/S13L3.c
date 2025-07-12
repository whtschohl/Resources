#include <stdio.h>
#include <stdlib.h>

// This example emphasizes that a struct is going to be aligned to the largest Type Alignment Requirement
// ** And that's to make sure that this type fits exactly where it should! **//

typedef struct point
{
    char x;
    double y;
    int z;
}Point; 

/*  How this struct looks like in Memory:

    Struct has total of 13 bytes necessary, but uses 24 bytes because of the way that it is 
    initiated. 7 after the char, and 4 after the int. The system saves memory in groups of the
    largest type - in this case 8

    -----------------------------------------------------------------------------
    |        |        |        |        |        |        |        |        |
    |        |        |        |        |        |        |        |        |
    |        |        |        |        |        |        |        |        |
    | 2000   | 2001   | 2002   | 2003   | 2004   | 2005   | 2006   | 2007   | 2008
    |        |        |        |        |        |        |        |        |
    | char x | Free   | Free   | Free   | Free   | Free   | Free   | Free   | double y
    |        |        |        |        |        |        |        |        |
    -----------------------------------------------------------------------------

    -----------------------------------------------------------------------------
    |        |        |        |        |        |        |        |        |
    |        |        |        |        |        |        |        |        |
    |        |        |        |        |        |        |        |        |
    | 2008   | 2009   | 2010   | 2000   | 2012   | 2013   | 2014   | 2015   | 2016
    |        |        |        |        |        |        |        |        |
    |                                 double y                              | int z 
    |        |        |        |        |        |        |        |        |
    -----------------------------------------------------------------------------

    -----------------------------------------------------------------------------
    |        |        |        |        |        |        |        |        |
    |        |        |        |        |        |        |        |        |
    |        |        |        |        |        |        |        |        |
    | 2016   | 2017   | 2018   | 2019   | 2020   | 2021   | 2022   | 2023   | 2024
    |        |        |        |        |        |        |        |        |
    |                int z              | Free   | Free   | Free   | Free   | Free   
    |        |        |        |        |        |        |        |        |
    -----------------------------------------------------------------------------
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