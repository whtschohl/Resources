#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implementing Remove Operation //

// void

void* insert(void* arr, unsigned size, unsigned idx, void* source, unsigned sourceSize);
void printArr(int* arr, int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}

int main()
{
	int* grades = (int*)malloc(3 * sizeof(int));
	int grade;
	int* updatedArr = NULL;
	if (!grades) return NULL;
	grades[0] = 90;
	grades[1] = 80;
	grades[2] = 100;
	printArr(grades, 3);
	printf("Enter additional grade to add to arr: ");
	scanf("%d", &grade);
	updatedArr = (int*)remove(grades, 3 * sizeof(int), 2*sizeof(int), sizeof(grade));
	printArr(updatedArr, 4);
	return 0;
}

void* remove(void* arr, unsigned size, unsigned idx, unsigned sourceSize)
{
	void* newArr = malloc(size - sourceSize);
	if (!newArr) return NULL;
	memcpy(newArr, arr, idx); // copy everything up until element that needs to be removed
	// note: pointer arithmetic is not allowed by standard...
	//memcpy(newArr + idx, source, sourceSize); 
	//memcpy((char*)newArr + idx, source, sourceSize); // used in insert function
	memcpy((char*)arr + idx, (char*)newArr + idx + sourceSize, size-idx-sourceSize);
	return newArr;
}

