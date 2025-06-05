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
    char name[10];
    int id;
}Student;

typedef struct course
{
    char name[10];
    float avgGrage;
    Student *studentsEnrolled;
}Course;

typedef struct school
{
    char name[10];
    Course *coursesOffered;
}School;

// Functions

Student *createStudent();
Course *createCourse(int numOfStudent);
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
    Student *allStudnets;

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

    printf("\n\nEnd of Program");
    return 0;
}

void printMenu()
{
    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<< MENU >>>>>>>>>>>>>>>>>>>>>>>>>>>");
    printf("\n============================================================");
    printf("\n 1 - Add School");
    printf("\n 2 - Print Student Details");
    printf("\n 3 - Print Course Details");
    printf("\n 4 - Print School Details");
    printf("\n 5 - Check if Student in course");
    printf("\n 6 - Check if Student in School");
    printf("\n 7 - Print all Students in Course");
    printf("\n 8 - Print all students who failed a Course");
    printf("\n 9 - Print all students who passed a Course");
    printf("\n10 - Print all the courses with a passed average grade");
    printf("\n11 - Print all the courses with a failed average grade");
    printf("\n12 - Print the average grade between all the courses");
    printf("\n13 - Print the course with the highest average grade");
    printf("\n============================================================");
}

Student *createStudent()
{
    Student *newStudent;
    newStudent = (Student*)malloc(sizeof(Student));

    printf("\nStudent Name: ");
    scanf("%s", newStudent->name);
    printf("\nStudent ID: ");
    scanf("%d", &newStudent->id);

    return newStudent;
}

Course *createCourse(int numOfStudent)
{
    Course *newCourse;
    newCourse = (Course*)malloc(sizeof(Course));
    Student **arrStudents;
    *arrStudents = (Student*)malloc(sizeof(Student) * numOfStudent);

    for (int i = 0; i < numOfStudent; i++)
        arrStudents[i] = createStudent();
    
    newCourse->studentsEnrolled = *arrStudents;

    return newCourse;
}