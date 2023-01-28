#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	
	// n from file read, internet, user input, etc.

	char* arr = (char*)malloc(sizeof(char) * n);

	// ...

	free(arr);

	return 0;
}