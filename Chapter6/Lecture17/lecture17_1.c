#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int main()
{
	/* Motivation */
	//int i1 = 0;
	//int i2 = 1;
	//int i3 = 2;
	//// ...

	//printf("%d\n", i1);
	//printf("%d\n", i2);
	//printf("%d\n", i3);
	//// ... 

	int my_arr[SIZE];

	// prepare for array data
	for (int i = 0; i < SIZE; ++i)
		my_arr[i] = i * i;
	
	// print array data
	for (int i = 0; i < SIZE; ++i)
		printf("%d ", my_arr[i]);

	//TODO: try debugger

	return 0;
}