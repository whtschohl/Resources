#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// Project: Pizza Making - A Delicious Use of Function Pointers //
// Step 1: Define Functions for Each Pizza Element
// Dough making functions

void thinCrust() {
    printf("making thin crust\n");
}

void thickCrust() {
    printf("making thick crust\n");
}

// Sauce making functions

void tomatoSauce() {
    printf("making tomato sauce\n");
}

void pestoSauce() {
    printf("making pesto sauce\n");
}

void newSauce() {
    printf("adding new sauce\n");
}

// Cheese making functions

void mozarellaCheese() {
    printf("making mozarella cheese\n");
}

void cheddarCheese() {
    printf("making cheddar cheese\n");
}

// Step 2: Create the Pizza Funtion

// Pizza creation process

void createPizza(void (*makeDough)(), void (*makeSauce)(), void (*makeCheese)())
{
    makeDough();
    makeSauce();
    makeCheese();
}

// Step 3: Main Function

int main()
{
    printf("Pizza 1:\n");
    createPizza(thinCrust, tomatoSauce, mozarellaCheese);
    printf("\n=================\n");

    printf("Pizza 2:\n");
    createPizza(thinCrust, pestoSauce, newSauce);
    printf("\n=================\n");

    return 0;
}