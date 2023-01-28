#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compute_pow(int base, int exp);

int main()
{
	// 3 4
	// 3*3*3*3 = 81
	int base, exp, result;

	while (scanf("%d %d", &base, &exp) == 2)
	{
		result = compute_pow(base, exp);

		printf("Result = %d\n", result);
	}

	return 0;
}

int compute_pow(int base, int exp)
{
	int i, result;

	result = 1;
	for (i = 0; i < exp; ++i)
		result *= base;

	return result;
}