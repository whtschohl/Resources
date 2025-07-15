#include <stdio.h>

// Tightly packed

typedef struct test{
    double average;     // 8 bytes
    char mark1;         // 1 byte
    char mark2;         // 1 byte
    short result;       // 2 bytes
    int value;          // 4 bytes
    double salary;      // 8 bytes
}Test;