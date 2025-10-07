/*
    Advanced Binary Student Record Handling - Files Project
    -------------------------------------------------------

    1. Define a structure (student):
        * name, total grades, dynamic array of grades
    
    2. Print student details.
    
    3. Student record creation function. (return student)

    4. Save student record to a file. (structures pointing to 
        pointers pointing to different arrays - not so easy)

    5. Read students records from file

    6. Enhanced functionality
        * updating grades
        * add new grades
        * average grades
    
    NOTE: 
    * make sure that you are properly formating the data
    * pay close attention to memory management
    * main focus: manipulating the bin file and managing the dynamic memory
*/

#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>
#include    <stdlib.h>

//
// Type def
//

typedef struct grades
{
    char*       m_sCourse;
    float       m_fGrade;
}stGrades;

typedef struct student {
    char*       m_pcName;
    int         m_iTotalGrades;
    stGrades*   m_pstGrades;
}stStudent;

//
// Functions
//

void vPrintStudDetails(stStudent *arr, int size);
void vAddStudent(stStudent *arr, int size);
void vCreateRecordFile(stStudent *arr, char *name, int size);
void vReadRecordFromFile(stStudent *arr, int size);
void vUpdateGrades(stStudent *arr, char *name, int size);
void vAddGrades(stStudent *arr, char *name, int size);
void vPrintAverageGrades(stStudent *arr, int size);

//
// Code
//

int main()
{
    // var
    stStudent *pstArr = { NULL };
    int iTotalSudents = 0;

    // create student
    vAddStudent(pstArr, iTotalSudents);

    // print student details
    vPrintStudDetails(pstArr, iTotalSudents);
}

void printStudDetails(stStudent *pstArr, int iSize)
{
    // var
    char *pcName = {NULL};

    // get info
    printf("\nEnter name of student: ");
    scanf("%s", pcName);

    // find student in arr
    for(int i = 0; i < iSize; i++)
        if(pstArr->m_pcName == pcName)
        {
            printf("\nStudent name: %s", pstArr->m_pcName);
            printf("\nStudent Total number of grades: %s", pstArr->m_pcName);
            printf("\nStudent grades: %s", pstArr->m_pcName);
        }

    return;
}
