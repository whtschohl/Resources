/*
    Introduction to Bitwise Operations

    Opereation  | Graphic               | Description               | Example
    ------------|-----------------------|---------------------------|-----------------------------------|
    Not: "~"    | 0/1 -> 1/0            | inverts the bit           | x = 5 (0b0101); y = ~x (0b1010);  |
                |          ___          |                           |                                   |
    AND: "&"    | bit1 -> |AND| -> bit  | if both bits are 1, then  | x = 5 (0b0101); y =  7 (0b0111);  |
                | bit2 -> |___|         | output is 1, else 0       | x & y = 5 (0b0101);               |
                |          ___          |                           |                                   |
    OR:  "|"    | bit1 -> |OR | -> bit  | if any bit is 0 then      | x = 5 (0b0101); y =  7 (0b0111);  |
                | bit2 -> |___|         | output is 1, else 0       | x | y = 7 (0b0111);               |
                |          ___          |                           |                                   |
    XOR: "^"    | bit1 -> |XOR| -> bit  | if the 2 bits differ then | x = 5 (0b0101); y =  7 (0b0111);  |
                | bit2 -> |___|         | output is 1, else 0       | x ^ y = 2 (0b0010);               |
    ------------|-----------------------|---------------------------|-----------------------------------|
*/