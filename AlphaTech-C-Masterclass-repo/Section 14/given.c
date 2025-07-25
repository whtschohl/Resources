#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void updateAverageGrade(Course* course)
{
    double totalGrades = 0;
    for (int i = 0; i < course->totalStudents; i++)
        totalGrades += (course->studentArray[i].grade);
    course->averageGrade = totalGrades / course->averageGrade;
    
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
    updateAverageGrade(newCourse);
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

// Step 15: Printing the Course with the Highest Average Grade

void printCourseWithHighestAverage(School *school)
{
    double highestAvg = 0;
    Course *highestAvgCourse = NULL;

    for (int i = 0; i < school->totalCourses; i++)
        if (school->courseArray[i].averageGrade > highestAvg)
        {
            highestAvg = school->courseArray[i].averageGrade;
            highestAvgCourse = &(school->courseArray[i]);
        }
        
    printf("Course with the highest average grade:\n"); 
    printCourseDetails(highestAvgCourse);   
}

// Step 16: Printing School details

printSchoolDetails(School* school)
{
    for (int i = 0; i < school->totalCourses; i++)
    {
        printCourseDetails(&(school->courseArray[i]));
    }
}

// Step 17: Updating Student Grade

void updateStudentGrade(Course* course, unsigned int studentID, unsigned int newGrade)
{
    // Iterate over the students in the course
    for (unsigned int i = 0; i < course->totalStudents; i++)
    {
        // Checkis if the student ID matches the provided studentID
        if (course->studentArray[i].id == studentID)
        {
            // Update student grade
            course->studentArray[i].grade = newGrade;

            // Automatically update the course average
            updateAverageGrade(course);
            return;
        }
    }
    printf("Student was not found!\n");
}

// Step 18: Updateing Student Name

void updateStudentName(Course* course, unsigned int studentID, char* newName)
{
    // Iterate over the students in the course
    for (unsigned int i = 0; i < course->totalStudents; i++)
    {
        // Checkis if the student ID matches the provided studentID
        if (course->studentArray[i].id == studentID)
        {
            // Update student name
            strcpy(course->studentArray[i].name, newName);
            
            return;
        }
    }
    printf("Student was not found!\n");
}

// Step 19: Is Course In School?

bool isCourseInSchool(School* school, char* courseName)
{
    Course* courseArray = school->courseArray;
    unsigned int numCourses = school->totalCourses;

    // Iterate over all the courses in the array
    for (unsigned int i = 0; i < numCourses; i++)
    {
        if (strcmp(courseArray->name, courseName) == 0)
            return true;
    }
    return false;    
}

// Step 20: Updating Course name

void updateCourseName(Course* course, char* newName)
{
    strcpy(course->name, newName);
}

// Step 21: Printing Common Courses Between Schools'

void printCommonCoursesBetweenSchool(School* school1, School* school2)
{
    printf("Common courses between %s and %s:\n", school1->name, school2->name);

    // Iterate over all courses in the first school
    for (unsigned int i = 0; i < school1->totalCourses; i++)
    {
        // Check if the course is also in the second school
        if (isCourseInSchool(school2, school1->courseArray[i].name))
            printf("%s", school1->courseArray[i].name);        
    }    
}

// Step 22: Printing Courses In One School WHile Not In The Other

void printUniqueCoursesBetweenSchool(School* school1, School* school2)
{
    printf("Common in %s but not in %s:\n", school1->name, school2->name);

    // Iterate over all courses in the first school
    for (unsigned int i = 0; i < school1->totalCourses; i++)
    {
        // Check if the course is also in the second school
        if (!isCourseInSchool(school2, school1->courseArray[i].name))
            printf("%s", school1->courseArray[i].name);        
    }    
}

void freeStudents(Student* student)
{
    free(student);
}

void freeCourses(Course* course, unsigned int totalCourses)
{
    for (unsigned int i = 0; i < totalCourses; i++)
    {
        freeStudents(course[i].studentArray);
        course[i].studentArray = NULL;
    }    
}

void freeSchool(School* school)
{
    freeCourses(school->courseArray, school->totalCourses);
    free(school->courseArray);
    school->courseArray = NULL;
    free(school);
}

int main()
{
    // Create School

    School* mySchool = createSchool();

    // Print details about the school
    printSchoolDetails(mySchool);

    printStudentCourses(mySchool, 123);

    printStudentsWhoFailed(&(mySchool->courseArray[0]), 60.0);
    printStudentsWhoPassed(&(mySchool->courseArray[0]), 60.0);
    
    freeSchool(mySchool);
}   