/*
    Extract / Understand specific bits in the vaule
    (using bitwise AND operator)

    Example 1:
        value:      11100010
        We want this bit  ^
        mask:       00000010
        ---
        if result == 00000000 then that bit was 0
        else if result == 00000010 then bit was 1

    Example 2:
        value:  11100010
        bits:    ^    ^
        mask:   01000010
        ---
        if result !=0, means that one or both bits are true.
        if we want both, then result == 0b01000010
        or if result == mask. 
*/