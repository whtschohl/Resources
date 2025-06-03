// Header

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // needed for dynamic memory allocation

// Exercise

/*
    Write 2 2 functions that allocaate dynamically an array of employees
    and reading inputs for each of the elements from the user;
        - The first function gets the size of the array, allocates memory, and 
          returns the array. 
        - The second function gets the size of the array, and allocates the 
          memory dynamically by updating it by "pointer" (finction of void type)
*/

// type definitions

typedef struct employee
{
    char name[10];
    float age;
    int id;
}Employee;

// Function Definitions
Employee *function1(int size);
void function2(Employee **arr, int size);
void populateEmployeeArray(Employee *arr, int size);

// Code

int main()
{
    int size;
    Employee *arr; 

    printf("\nEnter size of Array / Number of Employees: ");
    scanf("%d", &size);

    arr = function1(size);
    printf("func1 complete");

    // function2(&arr, size);

    printf("complete");

    return 0;
}

Employee *function1(int size)
{
    Employee *arr = (Employee*)malloc(sizeof(Employee) * size);
    populateEmployeeArray(arr, size);
    return arr;
}

void function2(Employee **arr, int size)
{
    *arr = (Employee*)malloc(sizeof(Employee) * size);
    populateEmployeeArray(*arr, size);
}

void populateEmployeeArray(Employee *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter emplyee #%d name: ", i +1);
        scanf("%s", arr->name);
        printf("\nEnter emplyee #%d age: ", i +1);
        scanf("%f", &arr->age);
        printf("\nEnter emplyee #%d id: ", i +1);
        scanf("%d", &arr->id);
        printf("--- Next Employee ---");
        arr++;
    }    
}