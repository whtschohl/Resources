#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS 

enum workingDays
{
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY
};

enum months
{
    JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

// have a reason behind why you are assigning a specific value to the enum identifier
// Note: this would overwrite the value of "JAN" and make the for loop start at 10 and not at 1. 
//          Keep the identifiers unique
// enum monthsBonus
// {
//     JAN=10, FEB=20, MAR=30
// };

// int main()
// {
//     enum months month;
//     char *monthNames[] = {"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

//     int salaries[12] = { 10, 20, 30, 25, 10, 20, 30, 25, 10, 20, 30, 25 };
//     for(month = JAN; month <= DEC; month++)
//     {
//         printf("%s%10d\n", monthNames[month], salaries[month-1]);
//     }

//     return 0;
// }

enum workingDays2
{
    MONDAY=10, TUESDAY=10, WEDNESDAY=10, THURSDAY, FRIDAY
};

int main()
{
    enum workingDays2 day;
    for (day = MONDAY; day < FRIDAY; day++)
    {
        printf("%d ", day); // 10 
    }
    
}