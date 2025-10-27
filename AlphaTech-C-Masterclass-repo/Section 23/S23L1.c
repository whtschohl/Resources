/*
    What is a constant?
    ---

    Allows us to create initiated variables that cannot be changed.
    
    How to create a constant?
    ---

    with the keyword "const"
    example: 
        const int year = 2025;
        const float pi = 3.14159265;

    Notes:
    ---

    - default type of const is int
        const age = 35; == const int age = 35;

    - pointer to a const | const int *ptr;
        a pointer to a constant! "int" constant that we're pointing to cannot be changed. 
        The address held by the pointer can be changed.

    - int *cont ptr;
        constant pointer to int "int" variable. 
        You can change the value of the pointed variable.

    - const int *const ptr;
        A constant pointer pointing to a constant integer.
        Nothing can be changed.
*/