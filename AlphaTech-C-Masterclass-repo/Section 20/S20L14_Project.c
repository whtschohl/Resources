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

void vPrintStudDetails(stStudent *arr);
void vAddStudent(stStudent *arr);
void vCreateRecordFile(stStudent *arr, char *name);
void vReadRecordFromFile(stStudent *arr);
void vUpdateGrades(stStudent *arr, char *name);
void vAddGrades(stStudent *arr, char *name);
void vPrintAverageGrades(stStudent *arr);

//
// Code
//

int main()
{
    // var
    stStudent stArr;

    // create student
    vAddStudent(&stArr);

    // print student details
    vPrintStudDetails(&stArr);
}

void vPrintStudDetails(stStudent *arr)
{
    // var
    char *pcName = {NULL};

    // get info
    printf("\nEnter name of student: ");
    scanf("%s", pcName);

    // find student in arr
    for(int i = 0; i < arr->m_iTotalGrades; i++)
        if(arr->m_pcName == pcName)
        {
            printf("\nStudent name: %s", arr->m_pcName);
            printf("\nStudent Total number of grades: %s", arr->m_pcName);
            printf("\nStudent grades: %s", arr->m_pcName);
        }

    return;
}

void vAddStudent(stStudent *arr)
{
    stStudent *pstNewStudent;
    pstNewStudent = (stStudent*)malloc(sizeof(stStudent));

    arr = (stStudent*)malloc(sizeof(stStudent) * arr->m_iTotalGrades);
    arr[arr->m_iTotalGrades] = *pstNewStudent;
}

void vCreateRecordFile(stStudent *arr, char *name)
{
    // write arr to file in bin
    FILE* fp = fopen("recordFile.bin", "wb");
    if (NULL == fp)
    {
        int iWritten = fwrite(arr, sizeof(stStudent), arr->m_iTotalGrades, fp);
        printf("Successfully Written Elements: %d\n", iWritten);
        fclose(fp);
    }
    return;    
}

void vReadRecordFromFile(stStudent *arr)
{
    FILE* fp = fopen("recordFile.bin", "rb");
    if (NULL == fp)
    {
        fseek(fp, 0, SEEK_END);
        arr->m_iTotalGrades = (ftell(fp) / sizeof(stStudent));
        fseek(fp, 0, SEEK_SET);
        arr = (stStudent*)realloc(arr, arr->m_iTotalGrades * sizeof(stStudent)); // reassign new size of memory, specific to file
        fread(arr, sizeof(stStudent), arr->m_iTotalGrades, fp);
        fclose(fp);
    }
    return;
}

void vUpdateGrades(stStudent *arr, char *name)
{
    for (int i = 0; i < arr->m_iTotalGrades; i++)
    {
        printf("\nEnter new Course: ");
        scanf("%s", arr->m_pstGrades[i].m_sCourse);
        printf("\nEnter new Grade: ");
        scanf("%f", &arr->m_pstGrades[i].m_fGrade);
    }
}

void vAddGrades(stStudent *arr, char *name)
{
    stGrades *grades = (stGrades*)malloc(sizeof((sizeof(stGrades) * arr->m_iTotalGrades) + sizeof(stGrades)));
    
    printf("Enter new Course name to be added: ");
    scanf("%s", grades[arr->m_iTotalGrades].m_sCourse);
    printf("Enter new Grade to be added: ");
    scanf("%f", &grades[arr->m_iTotalGrades].m_fGrade);

    arr->m_pstGrades = grades;
}

void vPrintAverageGrades(stStudent *arr)
{
    float fSum = 0;

    for (int i = 0; i < arr->m_iTotalGrades; i++)
    {
        fSum += arr->m_pstGrades[i].m_fGrade;
    }

    printf("\n Average Grade: %.2f", fSum/arr->m_iTotalGrades);
    
}
