#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
	int temp;
	temp = 1 ? 1024 : 7;
	printf("%d\n", temp);

	temp = 0 ? 1024 : 7;
	printf("%d\n", temp);

	/*int a = 1, b = 2;
	int max = (a > b) ? a : b;*/

	/*int number;
	scanf("%d", &number);*/

	//bool is_even = (number % 2 == 0) ? true : false;

	//if (number % 2 == 0)
	//	is_even = true;
	//else
	//	is_even = false;

	//(number % 2 == 0) ? printf("Even") : printf("Odd");

	/*if (is_even)
		printf("Even");
	else
		printf("Odd");*/

	return 0;
}