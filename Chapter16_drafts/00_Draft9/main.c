#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MYTYPE(X) _Generic((X), \
	int: "int", \
	float : "float", \
	double : "double", \
	default: "other"\
)

int main()
{
	int d = 5;

	/*
	printf("%s\n", MYTYPE(d));		// d is type int
	printf("%s\n", MYTYPE(2.0*d));
	printf("%s\n", MYTYPE(3L));
	printf("%s\n", MYTYPE(&d));
	*/

	return 0;
}