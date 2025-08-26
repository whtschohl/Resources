/*
    Project: Pizza Making 
    =============================================
    - A delicious use of function pointers
    ---------------------------------------------
    
    Pizza is made up of dough, sauce, and cheese.
                          |      |           |   
                          v      v           v
                          3      4           5
    ----> 3 * 4 * 5 = 60 different pizzas

    Tasks
    ---------------------------------------------
        [] Write 2 dough functions 
        [] Write 2 sauce functions
        [] Write 2 cheese functions
        [] Define a function create_pizza that takes three function pointers as parameters: 1 for dough, sauce, cheese.
        [] Inside create_pizza, call the functions in this order:
            Dough function
            Sauce function
            Cheese function
        [] In main(), call create_pizza at least twice with different combinations of dough, sauce, and cheese.
*/

// Headers

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// Functions
void createPizza(void (*makeDough)(), void (*makeSauce)(), void (*makeCheese)());
void thinCrust();
void thickCrust();
void redSauce();
void whiteSauce();
void mozzarella();
void cheddar();

// Code

int main()
{
    createPizza(thinCrust, redSauce, mozzarella);
    createPizza(thickCrust, whiteSauce, cheddar);
}

void createPizza(void (*makeDough)(), void (*makeSauce)(), void (*makeCheese)())
{
    printf("Making Pizza..\n");
    makeDough();
    makeSauce();
    makeCheese();
}

        // Crust
void thinCrust() { printf("Preparing thin crust..\n");}
void thickCrust() { printf("Preparing thick crust..\n");}
        // Sauce
void redSauce() { printf("Preparing red sauce..\n");}
void whiteSauce() { printf("Preparing white sauce..\n");}
        // Cheese
void mozzarella() { printf("Preparing mozzarella..\n");}
void cheddar() { printf("Preparing thick cheddar..\n");}
