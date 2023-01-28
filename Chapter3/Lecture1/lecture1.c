#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	float a = 1.234f;
	double pi = 3.141592;

	float won = 0.0f;
	float dollar = 0.0f;

	printf("Input Won\n");
	scanf("%f", &won);

	dollar = won * 0.00089f;

	printf("Dollar = %f\n", dollar);

	return 0;
}