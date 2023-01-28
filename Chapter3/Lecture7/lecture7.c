#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	char c = 65;
	short s = 200;
	unsigned int ui = 3000000000U;//3'000'000'000U
	long l = 65537L;
	long long ll = 12345678908642LL; // 12'345'678'908'642ll

	printf("char = %hhd, %d, %c\n", c, c, c);
	printf("short = %hhd, %hd, %d\n", s, s, s);
	printf("unsigned int = %u, %d \n", ui, ui);
	printf("long = %ld, %hd\n", l, l);
	printf("long long = %lld, %ld\n", ll, ll);

	return 0;
}