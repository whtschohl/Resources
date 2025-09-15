#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>

/*
    Make note when editing files. 
    Modifying can lead to weird changes like changing Germany to US can result in USermany. 
    
    Ideas on how to change it:
    - delete until ' '
    - delete and move remaining file bits by length of deleted bits
    - Cody remaining content to char after file pointer
    - Create a new file with data in the right locations
    
*/