#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Function-like macros

	#define		ADD(X,Y)	((X)+(Y))

	X and Y : macro arguments
*/

#define	ADD1(X,Y)		X+Y
#define	ADD2(X,Y)		((X)+(Y))
#define SQUARE(X)		X*X			// ((X)*(X))

int main()
{
	int sqr = SQUARE(3);

	int a = 1;

	printf("%d\n", 2 * ADD1(1, 3)); //2 * X + Y = 2 * 1 + 3 = 5 // WRONG!!!
	printf("%d\n", 2 * ADD2(1, 3)); //2 * (1 + 3) = 8

	printf("%d\n", SQUARE(1 + 2)); // 1+2*1+2 = 1 + 2 + 2 = 5 // WRONG!!!!
	printf("%d\n", 100 / SQUARE(3 + 1)); //100 / 3 + 1 * 3 + 1 = 33 + 3 + 1 = 37 // WRONG!!!
	printf("%d\n", SQUARE(++a)); // ++a * ++a = 3 * 3 = 9 // DANGEROUS!

	return 0;
}