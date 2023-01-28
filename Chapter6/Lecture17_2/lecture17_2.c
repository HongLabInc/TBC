#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int main()
{
	int numbers[SIZE];
	int sum = 0;
	int i;

	printf("Enter %d numbers : ", SIZE);

	for (i = 0; i < SIZE; ++i)
		scanf("%d", &numbers[i]);// &(numbers[i])

	for (i = 0; i < SIZE; ++i)
		sum += numbers[i];

	//TODO: average

	printf("Sum = %d\n", sum);

	return 0;
}