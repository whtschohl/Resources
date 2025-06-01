#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // needed for dynamic memory allocation

typedef struct point
{
    int x;
    int y;
}Point;

int main()
{
    // Creating a "Static Array of Points"
    Point* pointsArr;
    int totalPoints;
    int i;

    // Writing Input to the first point element in the arry
    printf("Enter the total number of points: ");
    scanf("%d", &totalPoints);

    // Making the Dynamic Memory Allocation (at run time ..)
    pointsArr = (Point*)malloc(sizeof(Point) * totalPoints);

    // Iterating over all of the Point Array (and reading input into each of them)
    for(i = 0; i < totalPoints; i++)
    {
        printf("Enter point #%d 'x' coordinate: ", i + 1);
        scanf("%d", &pointsArr[i].x);
        printf("Enter point #%d 'y' coordinate: ", i + 1);
        scanf("%d", &pointsArr[i].y);
    }

    // Accessing and printing all the values of each of the "Static Array of Points"
    for(i = 0; i < totalPoints; i++)
    {
        printf("Point #%d = (%d, %d)\n", i + 1, pointsArr[i].x, pointsArr[i].y);
    }
}