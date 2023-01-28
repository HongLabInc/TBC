#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num, sum = 0;

	printf("Enter an integer (q to quit) : ");

	while (scanf("%d", &num) == 1) { 			// equality operator
	
		// do something
		sum = sum + num;

		printf("Enter next integer (q to quit) : ");
	}

	printf("Sum = %d\n", sum);

	//TODO: C-style shortcut

	return 0;
}