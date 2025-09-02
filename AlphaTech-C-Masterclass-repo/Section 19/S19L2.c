#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main()
// {
//     // Open a file in write mode. If the file does not exist, it will be created.
//     FILE* file = fopen("log.txt", "w");
//     if (NULL == file)
//     {
//         printf("Failed to open file\n");
//         return 1;
//     }

//     // Write some data to the file
//     fprintf(file, "Processing user request ...\n");

//     // Close the file
//     fclose(file);

//     // Work...

//     // Delete the file
//     if (0 != remove("log.txt"))
//     {
//         printf("Failed to delete file\n");
//     }
//     else {
//         printf("File deleted successfully");
//     }
    
// }

int main()
{
    char filePath[30];
    printf("Enter the full path of the file you want to delete: ");
    fgets(filePath, sizeof(filePath), stdin);

    // Remove newline character if present
    int len = strlen(filePath);
    if(len > 0 && filePath[len - 1] == '\n'){
        filePath[--len] = '\0';
    }

    int result = remove(filePath);
    if(result != 0){
        printf("Removing the file has failed...\n");
    }
    else {
        printf("Hooray!");
    }
}