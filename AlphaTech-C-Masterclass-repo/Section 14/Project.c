#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // needed for dynamic memory allocation
#include <stdbool.h>

// Structs

typedef struct student
{
    char *name;
    int id;
}Student;

typedef struct course
{
    char *name;
    float avgGrage;
    Student *studnetsEnrolled;
}Course;

typedef struct school
{
    char *name;
    Course *coursesOffered;

}School;

// Functions

void createStudent();
void createCourse();
void createSchool();
void printStudentDetails();
void printCourseDetails();
void printSchoolDetails();
bool isStudentInCourse(int id, Course course);
bool isStudentInSchool(int id, School school);
void printStudenCourses(int id, Course course);
void printFailedStudents();
void printPassedStudents();
void printCourseAvgPass();
void printCourseAvgFail();
void printAvgScoreOfAllCourses();
void printCourseWithHighestAverage();
void freeMemory();

// Code

int main()
{
    while(true)
    {
        // menu code
        /*
            create a menu to do what the functions want
            add in an option to close program
        */
        printf("in the loop \n");
        break;
    }

    printf("out of loop");
    return 0;
}