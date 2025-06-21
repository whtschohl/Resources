#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// Step 1: Defining the 'Student' Struct

typedef struct student {
    char name[20];
    unsigned int id;
}Student;

// Step 2: Defining the 'Course' Struct

typedef struct course {
    char name[20];
    double averageGrade;
    unsigned int totalStudents;
    Student *studentArray;
}Course;

// Step 3: Defining the 'School' Struct

typedef struct school
{
    char name[20];
    unsigned int totalCourses;
    Course *courseArray;
}School;

