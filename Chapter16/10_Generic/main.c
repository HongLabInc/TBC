#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Generic selection expression
	- generic programming : code is not specific to a particular type

	_Generic : C11 keyword
*/

#define MYTYPE(X) _Generic((X), \
	int: "int", \
	float : "float", \
	double : "double", \
	default: "other"\
)

int main()
{
	int d = 5;
	
	//printf("%s\n", MYTYPE(d));
	//printf("%s\n", MYTYPE(2.0*d));
	//printf("%s\n", MYTYPE(3L));
	//printf("%s\n", MYTYPE(&d));

	return 0;
}