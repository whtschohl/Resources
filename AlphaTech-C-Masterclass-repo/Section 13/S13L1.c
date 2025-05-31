#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct point
{
    int x;
    int y;
}Point;

int main()
{
    // Creating a "Static Array of Points"
    Point pointArray[5];
    int i;

    // Writing Input to the first point element in the arry
    printf("Enter a first point 'x' coordinate: ");
    scanf("%d", &pointArray[0].x);
    printf("Enter a first point 'y' coordinate: ");
    scanf("%d", &pointArray[0].y);

    // Iterating over all of the Point Array (and reading input into each of them)
    for(i = 0; i < 5; i++)
    {
        printf("Enter point #%d 'x' coordinate: ", i + 1);
        scanf("%d", &pointArray[i].x);
        printf("Enter point #%d 'y' coordinate: ", i + 1);
        scanf("%d", &pointArray[i].y);
    }

    // Accessing and printing all the values of each of the "Static Array of Points"
    for(i = 0; i < 5; i++)
    {
        printf("Point #%d = (%d, %d)\n", i + 1, pointArray[i].x, pointArray[i].y);
    }
}