#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define PSQR(x) printf("The square of " #x " is %d.\n", ((x)*(x)))

int main()
{
	int y = 5;
	PSQR(y);
	PSQR(2 + 4);

	return 0;
}