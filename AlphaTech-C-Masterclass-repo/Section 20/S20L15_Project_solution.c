#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>
#include    <stdlib.h>

typedef struct student {
    char name[30];
    int total_grades;
    int* grades;
} Student;

void printStudentData(Student s) {
    printf("Name: %s\n", s.name);
    printf("Total grades %d\n", s.total_grades);
    for (int i = 0; i < s.total_grades; i++) {
        printf("Grade %d: %d\n", i+1, s.grades[i]);
    }
}

Student createStudentRecord() {
    Student s;
    printf("Enter student's name: ");
    scanf("%s", s.name);
    printf("Enter total number of grades: ");
    scanf("%d", &s.total_grades);
    s.grades = (int*)malloc(s.total_grades * sizeof(int));
    for (int i = 0; i < s.total_grades; i++)
    {
        printf("Enter grade %d: ", i + 1);
        scanf("%d", &s.grades[i]);
    }
    return s;
}

// Note: saving the structure "Student" into a file will save an address in place of grades.
void saveStudentToFile(Student s, char* filename)
{
    FILE* fp = fopen(filename, "ab");
    if(fp != NULL)
    {
        fwrite(s.name, sizeof(char), 30, fp);
        fwrite(&s.total_grades, sizeof(int), 1, fp);
        fwrite(s.grades, sizeof(int), s.total_grades, fp);
        fclose(fp);
    }
}

void saveStudentsArrayToFile(Student* studentsArray, unsigned int totalStudent, char* filename)
{
    for (unsigned int i = 0; i < totalStudent; i++)
    {
        saveStudentToFile(studentsArray[i], filename);
    }
}

    // Not working ...
// void saveStudentsArrayToFile(Student* studentsArray, unsigned int totalStudent, char* filename)
// {
//     FILE* fp = fopen(filename, "wb");
//     if (fp != NULL)
//     {
//         fwrite(studetnsArray, sizeof(Student), totalStudent, fp);
//         fclose(fp);
//     }
// }

Student readStudentRecord(char* filename)
{
    Student s;
    FILE* fp = fopen(filename, "rb");
    if(fp != NULL)
    {
        fread(s.name, sizeof(char), 30, fp);
        fread(&s.total_grades, sizeof(int), 1, fp);
        s.grades = (int*)malloc(sizeof(int) * s.total_grades);
        // assert ..
        fread(&s.grades, sizeof(int), s.total_grades, fp);
        fclose(fp);
    }
}

int main()
{

}
