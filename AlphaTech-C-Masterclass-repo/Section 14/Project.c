/* Notes
--------------------------------------------------------------

The array of all students is kept in the school struct

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // needed for dynamic memory allocation
#include <stdbool.h>
#include <string.h>

// Structs

typedef struct student
{
    char name[10];
    int id;
    float grade;
}Student;

typedef struct course
{
    char name[15];
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
Course *getCourse(School *allSkools, int numberOfSchools);
School *getSchool(School *allSchools, int numberOfSchools);
void createSchool(School **arr, int *numberOfSchools);
void printStudentDetails(Student stud);
void printCourseDetails(Course course);
void printSchoolDetails(School skool);
bool isStudentInCourse(int id, char *course, char *schoolName, School *allSchools, int numberOfSchools);
bool isStudentInSchool(int id, char *schoolName, School **allSchools, int numberOfSchools);
void printStudentCourses(int id, School skool, School *allSkools, int numberOfSchools);
void printFailedStudents(Course course);
void printPassedStudents(Course course);
void printCourseAvgPass(School skool);
void printCourseAvgFail(School skool);
void printAvgScoreOfAllCourses(School skool);
void printCourseWithHighestAverage(School skool);
void freeAllSchools(School **ptr, int size);
void printMenu();

// Code

int main()
{
    static int numberOfSchools = 0;
    School *allSchools = (School*)malloc(sizeof(School) * numberOfSchools);
    int studentID, schoolIndex, option;
    char courseName[15], schoolName[15];
    Course *tempCourse;
    School *tempSchool;
    Student *tempStud;

    while(true)
    {
        
        // menu code
        /*
            create a menu to do what the functions want
            add in an option to close program
        */
        printMenu();
        if(scanf("%d", &option) != 1)
        {
            printf("\nInvalid input");
            while (getchar() != '\n'); 
        }

        switch (option)
        {
        case 1:
            if (allSchools == NULL)
            {
                createSchool(&allSchools, 0);
            } else
            {
                createSchool(&allSchools, &numberOfSchools);
            }
            break;
        
        case 2:
            if (NULL == allSchools)
            {
                printf("\nNo schools in database");
            }else {
                printf("\nEnter School Name: ");
                if(scanf("%s", schoolName) != 1)
                {
                    printf("\nInvalid input");
                    while (getchar() != '\n');  
                }
                 
                
                for (int i = 0; i < numberOfSchools; i++)
                    if (allSchools[i].name == schoolName)
                        schoolIndex = i;

                printSchoolDetails(allSchools[0]);
            }

            break;
        case 3:
            printf("\nEnter student id: ");
            if(scanf("%d", &studentID) != 1)
            {
                printf("\nInvalid input");
                while (getchar() != '\n');  
            }
            printf("\nEnter course name: ");
            if(scanf("%s", courseName) != 1)
            {
                printf("\nInvalid input");
                while (getchar() != '\n');  
            }
            printf("\nEnter school name: ");
            if(scanf("%s", schoolName) != 1)
            {
                printf("\nInvalid input");
                while (getchar() != '\n');  
            } 

            if(isStudentInCourse(studentID, courseName, schoolName, allSchools, numberOfSchools))
                printf("Student %d is enrolled in the %s course", studentID, courseName);
            
            break;
        
        case 4:
            printf("\nEnter student id: ");
            if(scanf("%d", &studentID) != 1)
            {
                printf("\nInvalid input");
                while (getchar() != '\n');  
            }
            printf("\nEnter school name: ");
            if(scanf("%s", schoolName) != 1)
            {
                printf("\nInvalid input");
                while (getchar() != '\n');  
            } 
            
            isStudentInSchool(studentID, schoolName, &allSchools, numberOfSchools);
            
            break;

        case 5:

            printf("\nEnter School name: ");
            if(scanf("%s", schoolName) != 1)
            {
                printf("\nInvalid input");
                while (getchar() != '\n');  
            }
            printf("\nEnter Course Name");
            if(scanf("%s", courseName) != 1)
            {
                printf("\nInvalid input");
                while (getchar() != '\n');  
            }

            tempSchool = allSchools;

            for (int i = 0; i < numberOfSchools; i++)
            {
                if(0 == strcmp(schoolName, tempSchool->name))
                {
                    tempCourse = tempSchool->coursesOffered;
                    for (int j = 0; j < tempSchool->numberOfCourses; j++)
                    {
                        if (0 == strcmp(tempCourse->name, courseName))
                        {
                            tempStud = tempCourse->studentsEnrolled;
                            for (int k = 0; k < tempCourse->numberOfStudents; k++)
                            {
                                printStudentDetails(*tempStud);
                            }
                            
                        }
                        
                    }
                    
                }
                tempSchool++;
            }
            
            break;

        case 6:

            tempCourse = getCourse(allSchools, numberOfSchools);
            printFailedStudents(*tempCourse);
            
            break;

        case 7:

            tempCourse = getCourse(allSchools, numberOfSchools);
            printPassedStudents(*tempCourse);
            
            break;

        case 8:

            tempSchool = getSchool(allSchools, numberOfSchools);
            printCourseAvgPass(*tempSchool);    

            break;

        case 9:

            tempSchool = getSchool(allSchools, numberOfSchools);
            printCourseAvgFail(*tempSchool);

            break;

        case 10:

            
            tempSchool = getSchool(allSchools, numberOfSchools);
            printAvgScoreOfAllCourses(*tempSchool);

            break;
            
        case 11:

            tempSchool = getSchool(allSchools, numberOfSchools);
            printCourseWithHighestAverage(*tempSchool);
            break;
            
        default:
            exit(EXIT_SUCCESS);
        }
    }
    freeAllSchools(&allSchools, numberOfSchools);
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
    if(scanf("%s", newStudent->name) != 1)
    {
        printf("\nInvalid input");
        while (getchar() != '\n');  
    }
    printf("\nStudent ID: ");
    if(scanf("%d", &newStudent->id) != 1)
    {
        printf("\nInvalid input");
        while (getchar() != '\n');  
    }
    printf("Student Grade: ");
    if(scanf("%f", &newStudent->grade) != 1)
    {
        printf("\nInvalid input");
        while (getchar() != '\n');  
    }

    return newStudent;
}

Course *createCourse()
{
    Course *newCourse;
    Student *temp;
    int Sum = 0;
    newCourse = (Course*)malloc(sizeof(Course));
    
    printf("\nCourse Name? ");
    if(scanf("%s", newCourse->name) != 1)
    {
        printf("\nInvalid input");
        while (getchar() != '\n');  
    }
    printf("\nHow many students are in this Course? ");
    if(scanf("%d", &newCourse->numberOfStudents) != 1)
    {
        printf("\nInvalid input");
        while (getchar() != '\n');  
    }

    Student *arrStudents = (Student*)malloc(sizeof(Student) * newCourse->numberOfStudents);
    newCourse->studentsEnrolled = arrStudents; 

    for (int i = 0; i < newCourse->numberOfStudents; i++)
    {   arrStudents[i] = *createStudent();}
    
    // Calculate average grade in course
    temp = newCourse->studentsEnrolled;
    for (int i = 0; i < newCourse->numberOfStudents; i++)
    {   Sum += temp->grade;
        temp++;
    }

    if(0 == newCourse->numberOfStudents)
        printf("\nNo students");
    else
        newCourse->avgGrage = Sum / newCourse->numberOfStudents;
    
    
    newCourse->studentsEnrolled = arrStudents;

    return newCourse;
}

Course *getCourse(School *allSkools, int numberOfSchools)
{
    char courseName[15];
    Course *tempCourse;

    printf("\nCourse Name? ");
    if(scanf("%s", courseName) != 1)
    {
        printf("\nInvalid input");
        while (getchar() != '\n');  
    }   
    
    for (int i = 0; i < tempCourse->numberOfStudents; i++)
    {
        if (0 == strcmp(courseName, tempCourse->name))
            return tempCourse;
        else
            printf("Course is not offered at the given school - check spelling");
    }

    return NULL;
}

School *getSchool(School *allSchools, int numberOfSchools)
{
    School *tempSchool;
    char schoolName[15];

    printf("\nEnter School name: ");
            if(scanf("%s", schoolName) != 1)
            {
                printf("\nInvalid input");
                while (getchar() != '\n');  
            }

    for (int i = 0; i < allSchools->numberOfCourses; i++)
        if(0 == strcmp(tempSchool->name, schoolName))
            return tempSchool;
        else 
            printf("\nSchool is not in the system - check spelling");
    
    return NULL;
}

void createSchool(School **arr, int *numberOfSchools)
{
    School *newArr = (School*)malloc(sizeof(School) * *numberOfSchools);
    School *newSchool = NULL;

    // the array of schools increases by 1 to add the new school
    *numberOfSchools += 1;
    newArr = (School*)realloc(*arr, sizeof(School) * *numberOfSchools); 
    if(newArr == NULL)
    {
        printf("newArr is still NULL");
        exit(EXIT_FAILURE);
    }
    
    newSchool = newArr + (*numberOfSchools-1); //get to the right element in the array

    printf("\nEnter new school name: ");
    if(scanf("%s", newSchool->name) != 1)
    {
        printf("\nInvalid input");
        while (getchar() != '\n');  
    }

    // Insert courses
    printf("\nHow many courses are offered: ");
    if(scanf("%d", &newSchool->numberOfCourses) != 1)
    {
        printf("\nInvalid input");
        while (getchar() != '\n');  
    }
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
    printf("\nStudent Grade: %.2f", stud.grade);
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

bool isStudentInCourse(int id, char *course, char *schoolName, School *allSchools, int numberOfSchools)
{
    School *tempSchool = allSchools;
    Course *tempCourse;
    Student *tempStud;

    for (int i = 0; i < allSchools->numberOfCourses; i++)
        if(0 == strcmp(tempSchool->name, schoolName))
            tempCourse = tempSchool->coursesOffered;
        else 
            printf("\nSchool is not in the system - check spelling");
    
    for (int i = 0; i < tempCourse->numberOfStudents; i++)
    {
        if (0 == strcmp(course, tempCourse->name))
            tempStud = tempCourse->studentsEnrolled;
        else
            printf("Course is not offered at the given school - check spelling");
    }

    for (int i = 0; i < tempCourse->numberOfStudents; i++)
    {
        if(tempStud->id == id)
        {
            return true;
        }
        tempStud++;
    }
    
    return false;
}

bool isStudentInSchool(int id, char *schoolName, School **allSchools, int numberOfSchools)
{   
    
    Course *tempCourse;
    School *tempSkool = *allSchools;    

    for (int i = 0; i < numberOfSchools; i++)
        if(0 == strcmp(tempSkool->name, schoolName))
            tempCourse = tempSkool->coursesOffered;
        else 
            printf("\nSchool is not in the system - check spelling");
    

    for (int i = 0; i < tempSkool->numberOfCourses; i++)
    {
        if(true == isStudentInCourse(id, tempCourse->name, tempSkool->name, *allSchools, numberOfSchools))
        {
            return true;
        }
        tempCourse++;
    }
    
    return false;
}

void printStudentCourses(int id, School skool, School *allSkools, int numberOfSchools)
{
    Course *temp;
    temp = skool.coursesOffered;

    if (isStudentInSchool(id, skool.name, &allSkools, numberOfSchools))
    {
        printf("\nStudent Courses: ");
        if (isStudentInCourse(id, temp->name, skool.name, &skool, numberOfSchools))
            printf("\n%s", temp->name);
        
    }
    else 
        printf("\nStudent is not in the given school");
}

void printFailedStudents(Course course)
{
    Student *temp = course.studentsEnrolled;

    printf("\nThe following students have failed: ");

    for (int i = 0; i < course.numberOfStudents; i++)
    {
        if (temp->grade < 50)
            printf("\n%d: %s", temp->id, temp->name);
        temp++;
    }    
}

void printPassedStudents(Course course)
{
        Student *temp = course.studentsEnrolled;

    printf("\nThe following students have Passed: ");

    for (int i = 0; i < course.numberOfStudents; i++)
    {
        if (temp->grade > 50)
            printf("\n%d: %s", temp->id, temp->name);
        temp++;
    } 
}

void printCourseAvgPass(School skool)
{
    Course *temp = skool.coursesOffered;

    printf("All Courses with a passing average:");

    for (int i = 0; i < skool.numberOfCourses; i++)
    {
        if (temp->avgGrage > 50)
            printf("\n%s", temp->name);
        temp++;        
    }   
}

void printCourseAvgFail(School skool)
{
        Course *temp = skool.coursesOffered;

    printf("All Courses with a failing average:");

    for (int i = 0; i < skool.numberOfCourses; i++)
    {
        if (temp->avgGrage < 50)
            printf("\n%s", temp->name);
        temp++;        
    } 
}

void printAvgScoreOfAllCourses(School skool)
{
    Course *temp = skool.coursesOffered;
    float avg = 0;

    for (int i = 0; i < skool.numberOfCourses; i++)
    {
        avg += temp->avgGrage;
        temp++;
    }
    avg = avg / skool.numberOfCourses;

    printf("\nAverage grade of all courses: %.2f", avg);    
}

void printCourseWithHighestAverage(School skool)
{
    Course *temp = skool.coursesOffered;
    Course *best = NULL;

    if (temp->avgGrage > best->avgGrage)
    {
        best = temp;
        temp++;
    }
    
    printf("\nCourse with the highest score (%f): %s", best->avgGrage, best->name);
}

void freeAllSchools(School **ptr, int size)
{
    Course *tempCourse = (*ptr)->coursesOffered;
    Student *tempStudent = tempCourse->studentsEnrolled;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < (*ptr)->numberOfCourses; j++)
        {
            for (int k = 0; k < tempCourse->numberOfStudents; k++)
            {
                free(tempStudent);
                tempStudent++;
            }
            free(tempCourse);
            tempCourse++;   
        }
        free(*ptr);
    }
    printf("\nMemory has been given a sock.");
}