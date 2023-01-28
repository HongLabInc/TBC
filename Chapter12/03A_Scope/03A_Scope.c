#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Variable scopes (visibility)
	- block, function, function prototype, file.
*/

void f1(int hello, double world);	// to the end of the prototype declaration
//void vla_param(int n, int m, double ar[n][m]); // gcc only

double func_block(double d)
{
	double p = 0.0;

	int i;
	for (i = 0; i < 10; i++)
	//for (int i = 0; i < 10; i++) // C99
	{
		double q = d * i;
		p *= q;

		if (i == 5)
			goto hello;
	}

hello:
	printf("Hello, World");

	return p;
}

int main()
{
	func_block(1.0);
}

void f1(int hello, double world)
{
}

//void vla_param(int n, int m, double ar[n][m])
//{
//
//}