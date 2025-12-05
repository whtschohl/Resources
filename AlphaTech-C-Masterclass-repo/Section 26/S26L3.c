// Practical code Example in C (for bitfeilds)

#include <stdio.h>

struct BitFieldExample
{
    unsigned int field1 : 1;    // can only store 1 bit  of info (0-1 in value)
    unsigned int field2 : 2;    // can only store 2 bits of info (0-3 in value)
    unsigned int field3 : 3;    // can only store 3 bits of info (0-7 in value)
};

int main()
{
    struct BitFieldExample structExample;

    structExample.field1 = 1; 
    structExample.field2 = 3; 
    structExample.field3 = 5; 

    printf("\nfield1: %u, field2: %u, field3: %u\n",
        structExample.field1, structExample.field2, structExample.field3);

    return 0;
}