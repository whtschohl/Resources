/*
    How to use Bitfields
    ---

    example:

    struct
    {
        type[member_name]: width;
    };
*/

struct BitFieldExample
{
    unsigned int field1 : 1;    // can only store 1 bit  of info (0-1 in value)
    unsigned int field2 : 2;    // can only store 2 bits of info (0-3 in value)
    unsigned int field3 : 3;    // can only store 3 bits of info (0-7 in value)
};
