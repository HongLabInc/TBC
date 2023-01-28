#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a = 7;

	int *ptr = &a;

	int** pptr = &ptr;

	**pptr = 9;//*(*pptr)

	printf("%d\n", a);

	return 0;
}