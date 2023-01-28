#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i = 0;
	while (i < 10)
	// an example of compound statements (block)
	{
		i++;
		printf("%d\n", i);
	}

	return 0;
}