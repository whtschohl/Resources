#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

// Step 4: Creating a Student

Student *createStudent()
{
    Student* newStudent = (Student*)malloc(sizeof(Student));
    //assert
    printf("Enter student name: ");
    scanf("%s", newStudent->name);
    printf("Enter student ID: ");
    scanf("%d", newStudent->id);
    return newStudent;
}

// Step 5: Creating a Course

Course *createCourse()
{
    Course* newCourse = (Student*)malloc(sizeof(Student));
    //assert
    printf("Enter course name: ");
    scanf("%s", newCourse->name);
    printf("Enter number of students: ");
    scanf("%d", newCourse->totalStudents);
    newCourse->studentArray = (Student*)malloc(sizeof(Student) * newCourse->totalStudents);
    //assert
    for (int i = 0; i < newCourse->totalStudents; i++)
    {
        printf("Enter details for student #%d\n", i + 1);
        Student* newStudent = createStudent();
        //assert
        newCourse->studentArray[i] = *newStudent; // copying field-by-field
        free(newStudent); // free the temperary student memory allocated by "createStudent" function
    }
    return newCourse;   
}

// Step 6: Creating a School

School* createSchool()
{
    School *newSchool = (School*)malloc(sizeof(School));
    //assert
    printf("Enter school name: ");
    scanf("%s", newSchool->name);
    printf("Enter number of courses: ");
    scanf("%d", newSchool->totalCourses);
    newSchool->courseArray = (Course*)malloc(sizeof(Course) * newSchool->totalCourses);
    //assert
    for (int i = 0; i < newSchool->totalCourses; i++)
    {
        printf("Enter details for course #%d\n", i + 1);
        Course* newCourse = createCourse();
        //assert
        newSchool->courseArray[i] = *newCourse; // copying field-by-field
        free(newCourse); 
    }
    return newSchool;   
}

// Step 7: Printing student details

void printStudentDetails(Student *student)
{
    printf("Student name: %s\n", student->name);
    printf("Student ID: %u\n", student->id);
}

// Step 8: Printing course details

void printStudentDetails(Course *course)
{
    printf("Student name: %s\n", course->name);
    printf("Student ID: %u\n", course->);
}

