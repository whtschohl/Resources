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

// Functions
// Solution Function 1
Employee *createEmployeesArray(int totalElements)
{
    Employee *employeesArr;
    employeesArr = (Employee*)malloc(sizeof(Employee) * totalElements);
    for (int i = 0; i < totalElements; i++)
    {
        printf("\nEnter emplyee #%d name: ", i + 1);
        scanf("%s", &employeesArr[i].name); //&(employeeArr+i)->name
        printf("\nEnter emplyee #%d age: ", i + 1);
        scanf("%f", &employeesArr[i].age);
        printf("\nEnter emplyee #%d id: ", i + 1);
        scanf("%d", &employeesArr[i].id);
        printf("--- Next Employee ---");
    }
    return employeesArr;
}

// Solution Function 2
void createEmployeesArray2(Employee **empPtr, int totalElements)
{
    Employee *employeesArr;
    employeesArr = (Employee*)malloc(sizeof(Employee) * totalElements);
    for (int i = 0; i < totalElements; i++)
    {
        printf("\nEnter emplyee #%d name: ", i + 1);
        scanf("%s", &employeesArr[i].name); //&(employeeArr+i)->name
        printf("\nEnter emplyee #%d age: ", i + 1);
        scanf("%f", &employeesArr[i].age);
        printf("\nEnter emplyee #%d id: ", i + 1);
        scanf("%d", &employeesArr[i].id);
        printf("--- Next Employee ---");
    }
    *empPtr = employeesArr;
}

int main()
{
    Employee* ptrArr;
    createEmployeesArray2(&ptrArr, 5);
}