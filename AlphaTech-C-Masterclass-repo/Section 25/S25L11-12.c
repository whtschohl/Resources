/*
    Set specific bits in the value
    (using bitwise OR operator)

    value: (5)  0b00000101   turn the first bit to a 1 but keep the other values as is
    Mask:       0b10000000
    value | mask
    ---
    result:     0b10000101

    Exercise: with a value of 0b10110101, create a mask to ensure that bit 0,3 and 6 are set to 1.
                Result should be 0b11111101.

    value: (5)  0b10110101
    mask:       0b01001001
    value | mask
    ---
    result:     0b11111101
*/