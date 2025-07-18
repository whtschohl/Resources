/*
    Pointers to Functions

    Questions to be answered:
        What is the function?
        What does a pointer has to do with it?
        How can we use pointers to the functions in our Programming?

    ------------------------------------------------------------------

    A function is made up of micro functions. Higher level function is supported my lots of 
    lower level functions. 

    Memory of a higher lvl function:

    |--------------|
    |#Func 1st cmd | 4000
    |--------------|
    |#Func 2nd cmd | 40xx
    |--------------|
    |#Func 3rd cmd | 40xx
    |--------------|
    |     ...      | ...
    |--------------|
    |     ...      | ...
    |--------------|
    |#Last Func cmd|
    |--------------|

    This shows that every command in a function is stored in memory. Refresh Assembly 
    language knowledge to understand this better.

    function name = the initial address of the function code (similar to array's name
    is the initial address of the array)

    Call the function with "()", but if you just use the func name you will only get the 
    address of the function.

    printf("The address of 'func()' is: %p \n", func); // %p is used for pointers
*/