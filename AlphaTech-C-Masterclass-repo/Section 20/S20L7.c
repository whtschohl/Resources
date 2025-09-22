#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>

typedef struct point {
    int x;
    int y;
}Point;

/*
    Edit a specific point in the file
*/

int main()
{
    Point m_point;
    int choice;

    printf("What is the point you would like to edit? (1-5)\n");
    scanf("%d", &choice);

    // Opening an existing file for both "reading" and "writing".
    FILE* fp = fopen("myFile3.bin", "rb+");

    if(fp != NULL)
    {
        // Navigating to relevant address of the specific point in the file.
        fseek(fp, (choice - 1) * sizeof(Point), SEEK_SET);
        printf("The point was located in the file..\n");
        // Get new coordinates for the point.
        printf("Enter new x: ");
        scanf("%d", &m_point.x);
        printf("Enter new y: ");
        scanf("%d", &m_point.y);
        // Update the recordd.
        fwrite(&m_point, sizeof(Point), 1, fp);
        fclose(fp);
    }
    return 0;
}

