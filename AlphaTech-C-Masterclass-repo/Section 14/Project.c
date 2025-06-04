/* Notes
--------------------------------------------------------------

The array of all students is kept in the school struct



*/

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
    Student *studentsEnrolled;
}Course;

typedef struct school
{
    char *name;
    Course *coursesOffered;
    Student *studentsEnrolled;
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
void printMenu();

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
        printMenu();


        // test
        break;
    }

    printf("\n\nout of loop");
    return 0;
}

void printMenu()
{
    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<< MENU >>>>>>>>>>>>>>>>>>>>>>>>>>>");
    printf("\n============================================================");
    printf("\n 1 - Add Student");
    printf("\n 2 - Add Course");
    printf("\n 3 - Add School");
    printf("\n 4 - Print Student Details");
    printf("\n 5 - Print Course Details");
    printf("\n 6 - Print School Details");
    printf("\n 7 - Check if Student in course");
    printf("\n 8 - Check if Student in School");
    printf("\n 9 - Print all Students in Course");
    printf("\n10 - Print all students who failed a Course");
    printf("\n11 - Print all students who passed a Course");
    printf("\n12 - Print all the courses with a passed average grade");
    printf("\n13 - Print all the courses with a failed average grade");
    printf("\n14 - Print the average grade between all the courses");
    printf("\n15 - Print the course with the highest average grade");
    printf("\n============================================================");
}
