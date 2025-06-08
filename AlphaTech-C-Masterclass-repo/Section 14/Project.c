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
    int numberOfStudents;
}Course;

typedef struct school
{
    char name[10];
    Course *coursesOffered;
    int numberOfCourses;
}School;

// Functions

Student *createStudent();
Course *createCourse();
void createSchool(School **arr, int numberOfSchools);
void printStudentDetails(Student stud);
void printCourseDetails(Course course);
void printSchoolDetails(School skool);
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
    static int numberOfSchools = 0;
    School *allSchools = (School*)malloc(sizeof(School) * numberOfSchools);

    while(true)
    {
        int option;
        // menu code
        /*
            create a menu to do what the functions want
            add in an option to close program
        */
        printMenu();
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            if (allSchools == NULL)
            {
                createSchool(&allSchools, 0);
            } else
            {
                createSchool(&allSchools, numberOfSchools);
            }
            break;
        
        case 2:
            if (NULL == allSchools)
            {
                printf("\nNo schools in database");
            }else {            
            printSchoolDetails(allSchools[0]);
            }

            break;
        
        default:
            break;
        }
    }

    printf("\n\nEnd of Program");
    return 0;
}

void printMenu()
{
    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<< MENU >>>>>>>>>>>>>>>>>>>>>>>>>>>");
    printf("\n============================================================");
    printf("\n 1 - Add School");
    printf("\n 2 - Print School Details");
    printf("\n 3 - Check if Student in course");
    printf("\n 4 - Check if Student in School");
    printf("\n 5 - Print all Students in Course");
    printf("\n 6 - Print all students who failed a Course");
    printf("\n 7 - Print all students who passed a Course");
    printf("\n 8 - Print all the courses with a passed average grade");
    printf("\n 9 - Print all the courses with a failed average grade");
    printf("\n10 - Print the average grade between all the courses");
    printf("\n11 - Print the course with the highest average grade");
    printf("\n 0 - Exit Program");
    printf("\n============================================================");
    printf("\nYour option: ");
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

Course *createCourse()
{
    Course *newCourse;
    newCourse = (Course*)malloc(sizeof(Course));
    

    printf("\nHow many students are in this Course? ");
    scanf("%d", &newCourse->numberOfStudents);

    Student *arrStudents = (Student*)malloc(sizeof(Student) * newCourse->numberOfStudents);

    for (int i = 0; i < newCourse->numberOfStudents; i++)
        arrStudents[i] = *createStudent();
    
    newCourse->studentsEnrolled = arrStudents;

    return newCourse;
}

void createSchool(School **arr, int numberOfSchools)
{
    School *newArr = (School*)malloc(sizeof(School) * numberOfSchools);
    School *newSchool = NULL;

    // the array of schools increases by 1 to add the new school
    numberOfSchools++;
    newArr = (School*)realloc(*arr, sizeof(School) * numberOfSchools); 
    if(newArr == NULL)
    {
        printf("newArr is still NULL");
        exit(EXIT_FAILURE);
    }
    
    newSchool = newArr + (numberOfSchools-1); //get to the right element in the array

    printf("\nEnter new school name: ");
    scanf("%s", newSchool->name);

    // Insert courses
    printf("\nHow many courses are offered: ");
    scanf("%d", &newSchool->numberOfCourses);
    newSchool->coursesOffered = (Course*)malloc(sizeof(Course) * newSchool->numberOfCourses);

    for (int i = 0; i < newSchool->numberOfCourses; i++)
        newSchool->coursesOffered[i] = *createCourse();

    // return new array of schools
    *arr = newArr;    
}

void printStudentDetails(Student stud)
{
    printf("\n----------------------------");
    printf("\nStudent name: %s", stud.name);
    printf("\nStudent id: %d", stud.id);
    printf("\n----------------------------");
}

void printCourseDetails(Course course)
{
    Student *temp = course.studentsEnrolled;
    printf("\n------------------------------------------------------------");
    printf("\nCourse: %s", course.name);
    printf("\nCourse Average Grade: %.2f", course.avgGrage);
    printf("\nStudents in Course: \n");
    for (int i = 0; i < course.numberOfStudents; i++)
    {
        printStudentDetails(*temp);
        temp++;
    }    
    printf("\n------------------------------------------------------------");
}

void printSchoolDetails(School skool)
{
    Course *temp = skool.coursesOffered;
    printf("\n============================================================");
    printf("\nSchool Name: %s", skool.name);
    printf("\nSchool Courses Details: ");
    for (int i = 0; i < skool.numberOfCourses; i++)
    {
        printCourseDetails(*temp);
        temp++;
    }    
    printf("\n============================================================");
}
