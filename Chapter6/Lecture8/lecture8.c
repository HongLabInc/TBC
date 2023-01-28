#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// Indefinite loop vs. Counting loop
	//while(1)
	//{
	//	// do something
	//}

	/*
		Counting Loop
		1. Counter initialization
		2. Counter check
		3. Counter change
	*/

	//int i;

	//i = 1;

	//while (i <= 10)			//Note: <=
	//{
	//	printf("%d ", i);
	//	i++;
	//}

	int i;

	for (i = 1; i <= 10; i++)
	{
		printf("dummy ");
		printf("%d ", i);
	}

	return 0;
}