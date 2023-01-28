#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

//_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");

int main()
{
	int n = 10;

	float vla[n];
	for (int i = 0; i < n; ++i)
		vla[i] = (float)i;
	
	for (int i = 0; i < n; ++i)
		printf("%f\n", vla[i]);

	puts("char is 16 bits.");

	return 0;
}