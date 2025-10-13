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

void vPrintStudDetails(stStudent *arr, int *iSize);
void vAddStudent(stStudent *arr, int *iSize);
void vCreateRecordFile(stStudent *arr, char *name, int *iSize);
void vReadRecordFromFile(stStudent *arr, int *iSize);
void vUpdateGrades(stStudent *arr, char *name);
void vAddGrades(stStudent *arr, char *name, int *iSize);
void vPrintAverageGrades(stStudent *arr, int *iSize);

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

void vPrintStudDetails(stStudent *pstArr, int *iSize)
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

void vAddStudent(stStudent *arr, int *iSize)
{
    stStudent *pstNewStudent;
    pstNewStudent = (stStudent*)malloc(sizeof(stStudent));

    arr = (stStudent*)malloc(sizeof(stStudent) * *iSize);
    arr[*iSize] = *pstNewStudent;
}

void vCreateRecordFile(stStudent *arr, char *name, int *iSize)
{
    // write arr to file in bin
    FILE* fp = fopen("recordFile.bin", "wb");
    if (NULL == fp)
    {
        int iWritten = fwrite(arr, sizeof(stStudent), iSize, fp);
        printf("Successfully Written Elements: %d\n", iWritten);
        fclose(fp);
    }
    return;    
}

void vReadRecordFromFile(stStudent *arr, int *iSize)
{
    FILE* fp = fopen("recordFile.bin", "rb");
    if (NULL == fp)
    {
        fseek(fp, 0, SEEK_END);
        *iSize = (ftell(fp) / sizeof(stStudent));
        fseek(fp, 0, SEEK_SET);
        arr = (stStudent*)realloc(arr, *iSize * sizeof(stStudent)); // reassign new size of memory, specific to file
        fread(arr, sizeof(stStudent), iSize, fp);
        fclose(fp);
    }
    return;
}

void vUpdateGrades(stStudent *arr, char *name)
{
    for (int i = 0; i < arr->m_iTotalGrades; i++)
    {
        printf("\nEnter new Grade: ");
        scanf("%d", &arr->m_pstGrades[i]);
    }
}
