#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//int seconds = 0, minutes = 0, hours = 0;

	//printf("Input seconds : ");
	//scanf("%d", &seconds);

	//while (seconds >= 0)
	//{
	//	minutes = seconds / 60;
	//	seconds %= 60;

	//	hours = minutes / 60;
	//	minutes %= 60;

	//	// print result
	//	printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

	//	printf("Input seconds : ");
	//	scanf("%d", &seconds);
	//}

	//printf("Good bye\n");

	int div, mod;
	
	div = 11 / 5;
	mod = 11 % 5;
	printf("div = %d, mod = %d\n", div, mod);

	div = 11 / -5;
	mod = 11 % -5;
	printf("div = %d, mod = %d\n", div, mod);

	div = -11 / -5;
	mod = -11 % -5;// first operand is negative
	printf("div = %d, mod = %d\n", div, mod);

	div = -11 / 5;
	mod = -11 % 5;// first operand is negative
	printf("div = %d, mod = %d\n", div, mod);

	return 0;
}