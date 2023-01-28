#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	unsigned int u_max = 0 - 1;

	// i to binary representation
	char buffer[33];
	_itoa(u_max, buffer, 2);

	// print decimal and binary
	printf("decimal: %u\n", u_max);
	printf("binary: %s\n", buffer);

	return 0;
}