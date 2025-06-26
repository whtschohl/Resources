#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Step 1: Defining the 'Student' Struct

typedef struct student {
    char name[20];
    unsigned int id;
    unsigned int grade;
}Student;

// Step 2: Defining the 'Course' Struct

typedef struct course {
    char name[20];
    double averageGrade;
    unsigned int totalStudents;
    Student *studentArray;
}Course;

// Step 3: Defining the 'School' Struct

typedef struct school{
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
    scanf("%u", &newStudent->id);
    printf("Enter student grade: ");
    scanf("%u", &newStudent->grade);
    return newStudent;
}

// Step 5: Creating a Course

Course *createCourse()
{
    Course* newCourse = (Course*)malloc(sizeof(Course));
    //assert
    printf("Enter course name: ");
    scanf("%s", newCourse->name);
    printf("Enter number of students: ");
    scanf("%u", &newCourse->totalStudents);
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
    scanf("%u", &newSchool->totalCourses);
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
    printf("Student grade: %u\n", student->grade);
}

// Step 8: Printing course details

void printCourseDetails(Course *course)
{
    printf("Course name: %s\n", course->name);
    printf("Course Average Grade: %f\n", course->averageGrade);
    printf("Course total student: %u\n", course->totalStudents);
    for (int i = 0; i < course->totalStudents; i++)
    {
        printf("Details for student #%d:\n", i + 1);
        printStudentDetails(&(course->studentArray[i]));
    }    
}

// Step 9: Printing All Student's Courses

void printStudentCourses(School *school, int studentID)
{
    printf("Courses for student with ID %d:\n", studentID);
    for (int i = 0; i < school->totalCourses; i++)
    {
        for (int j = 0; j < school->totalCourses; j++)
        {
            if (school->courseArray[i].studentArray[j].id == studentID)
            {
                printf(" - %s\n", school->courseArray[i].name);
                break; // student was found in this course, no need to keep tracking this course
            }
        }
    }
}

// Step 10: Printing Students Who Failed Course

void printStudentsWhoFailed(Course* course, double cutOffGrade)
{
    printf("Students who failed in %s:\n", course->name);
    for (int i = 0; i < course->totalStudents; i++)
    {
        if(course->studentArray[i].grade < cutOffGrade)
            printStudentDetails;
    }
}

// Step 11: Printing Students Who Passed Course

void printStudentsWhoPassed(Course* course, double cutOffGrade)
{
    printf("Students who passed in %s:\n", course->name);
    for (int i = 0; i < course->totalStudents; i++)
    {
        if(course->studentArray[i].grade >= cutOffGrade)
            printStudentDetails;
    }
}

// Step 12: Printing All Courses with Pass Average Grade

void printCourseWithPassAvgGrade(School* school, double cutOffGrade)
{
    printf("Courses with pass average grade:\n");
    for (int i = 0; i < school->totalCourses; i++)
    {
        if(school->courseArray[i].averageGrade >= cutOffGrade)
            printCourseDetails(&(school->courseArray[i]));
    }
}

// Step 13: Printing All Courses with Fail Average Grade

void printCourseWithFailAvgGrade(School* school, double cutOffGrade)
{
    printf("Courses with fail average grade:\n");
    for (int i = 0; i < school->totalCourses; i++)
    {
        if(school->courseArray[i].averageGrade < cutOffGrade)
            printCourseDetails(&(school->courseArray[i]));
    }
}

// Step 14: Printing the Average Grade Between All Courses 

void printAverageGradeAllCourses(School *school)
{
    double totalGrade = 0;
    for (int i = 0; i < school->totalCourses; i++)
        totalGrade += (school->courseArray[i].averageGrade);

    double average = totalGrade / school->totalCourses;
    printf("Average grade between all courses in school %s is %.2f\n", school->name, average);    
}

