#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 1, y = 2, z;

	x > y + 2;
	x > (y + 2);

	x = y > 2;
	x = (y > 2);

	z = x > y;
	z = (x > y);

	x != y == z;
	(x != y) == z;
	   
	return 0;
}