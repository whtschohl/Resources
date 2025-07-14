#include <stdio.h>

typedef struct point1
{
    char x;
    char z;
    double y;
}Point1;

typedef struct point
{
    char t;
    short x;
    char z;
    double y;
}Point;

void main()
{
    Point p1;
    unsigned int totalBytes = sizeof(Point);
    p1.t = 0x11;
    p1.x = 0xAABBCCDD;
    p1.z = 0xEE;
    p1.y = 0x123456789ABCDEF; 
}