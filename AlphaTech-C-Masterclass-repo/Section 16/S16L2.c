#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    char x;
    short y;
    int z;
}Point; 

void main()
{
    unsigned int totalStructBytes = sizeof(Point); 
    Point p1;

    p1.x = 0xFF;        // 1 byte  of memory
    p1.y = 0x1234;      // 2 bytes of memory
    p1.z = 0x6789ABCD;  // 4 bytes of memory

    printf("end of program.");
}

/*
    In memory, the bytes are changed up a bit. Instead of xx xx FF 12 34 67 89 AB CD xx xx
    We get: xx xx FF 34 12 CD AB 89 67 xx xx 
    This is because when we write it in the program, 0x1234, it starts with the 
    least significant bit (LSB), 0x12; 
    In memory, the LSB comes after the most significant bit (MSB), 0x34; 
*/