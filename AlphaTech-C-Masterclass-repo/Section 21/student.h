#pragma once

typedef struct student {
    char name[30];
    int totalGrades;
    int* grades;
}Student;

void printStudent(Student s);
float findAverageGrade(Student s);
