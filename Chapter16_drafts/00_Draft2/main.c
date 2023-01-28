#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SQUARE(X)	X*X
#define PR(X)		printf("The result is %d.\n", X)

int main()
{
	int x = 5;
	int z;

	printf("x = %d\n", x);
	z = SQUARE(x);

	PR(z);

	z = SQUARE(2);

	printf("Evaluating SQUARE(2): ");
	PR(z);
	PR(SQUARE(x + 2));
	PR(100 / SQUARE(2));
	PR(SQUARE(++x));

	return 0;
}