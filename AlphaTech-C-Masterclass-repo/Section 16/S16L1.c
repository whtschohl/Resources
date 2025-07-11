#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    char x;
    short y;
    int z;
}Point; // char = 1 byte; short = 2 bytes; int = 4 bytes

void main()
{
    unsigned int totalStructBytes = sizeof(Point); // Total = 8 bytes. Why?
    printf("%d", totalStructBytes);
}

/* 
    Law of Data alignment - 32 bit system = 4 byte words. 
    Total size of data types can only be multiples of the word.
    If all data types in the struct are one after the other in memory, the CPU
    will need 2 operations to get the int - bad preformance. So the CPU saves it 
    implicitly in a new word. This improves preformance.

    Datatypes are placed in addresses in natural addresses - addresses that aare multiples
    of its natural size. So char starts at any address. shors starts at 2002, and int starts
    at 2004

            Word 1                              Word 2
    -----------------------------------------------------------------------------
    |        |        |        |       ||        |        |        |        |
    |        |        |        |       ||        |        |        |        |
    |        |        |        |       ||        |        |        |        |
    | 2000   | 2001   | 2002   | 2003  || 2004   | 2005   | 2006   | 2007   | 2008
    |        |        |        |       ||        |        |        |        |
    |  char  |        |     short      ||                int                |
    |        |        |        |       ||        |        |        |        |
    -----------------------------------------------------------------------------


*/
