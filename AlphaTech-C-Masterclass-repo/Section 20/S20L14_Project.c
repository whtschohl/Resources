/*
    Advanced Binary Student Record Handling - Files Project
    -------------------------------------------------------

    1. Define a structure (student):
        * name, total grades, dynamic array of grades
    
    2. Print student details.
    
    3. Student record creation function. (return student)

    4. Save student record to a file. (structures pointing to 
        pointers pointing to different arrays - not so easy)

    5. Read students records from file

    6. Enhanced functionality
        * updating grades
        * add new grades
        * average grades
    
    NOTE: 
    * make sure that you are properly formating the data
    * pay close attention to memory management
    * main focus: manipulating the bin file and managing the dynamic memory
*/

#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>
#include    <stdlib.h>

//
// Type def
//

typedef struct student {
    char *name;
    int totalGrades;
    int *grades;
}Student;

//
// Functions
//

void printStudDetails(Student arr, char *name);
void addStudent(Student arr);
void createRecordFile(Student arr, char *name);
void readRecordFromFile(Student arr);
void updateGrades(Student arr, char *name);
void addGrades(Student arr, char *name);
void printAverageGrades(Student arr);

//
// Code
//
