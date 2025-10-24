#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS 

enum workingDays
{
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY
};

int main()
{   
    // inconvenient
    // int firstDay = 0;
    // int secondDay = 1;
    // ..
    // int userDay;

    // Better:
    enum workingDays userDay; // Creating a "day" variable

    printf("Please enter the day you worked: ");
    scanf("%d", &userDay);
    
    // Inconvenient code:
    // if (userDay == 0) // Monday
    //     // Some operations related to working with Monday ..
    //     printf("Monday... Do this and Do that...\n");

    // Convenient and readable code:
    if(userDay == MONDAY) // Monday
        // Some operations related to working with Monday ..
        printf("Monday... Do this and Do that...\n");
    else if (userDay == TUESDAY)
        // Do something
        printf("...");
}       

/*
    Naming convention: Use FULL CAPITAL LETTERS for enum identifiers. 
    This makes them stnad out and not to get confused with regular variables.
*/
