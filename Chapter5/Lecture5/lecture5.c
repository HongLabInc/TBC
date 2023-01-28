#include <stdio.h>

int main()
{
	printf("Integer divisions\n");
	printf("%d\n", 14 / 7);
	printf("%d\n", 7 / 2);// 3.5 in floating division
	printf("%d\n", 7 / 3);// 2.333 in floating division
	printf("%d\n", 7 / 4);// 1.75 in floating division
	printf("%d\n", 8 / 4);// 2

	printf("Truncating toward zero (C99)\n");
	printf("%d\n", -7 / 2);// -3.5 in floating division
	printf("%d\n", -7 / 3);// -2.333 in floating division
	printf("%d\n", -7 / 4);// -1.75 in floating division
	printf("%d\n", -8 / 4);// -2

	printf("\nFloating divisions\n");
	printf("%f\n", 9.0 / 4.0);
	printf("%f\n", 9.0 / 4);// Note: 4 is integer

	return 0;
}