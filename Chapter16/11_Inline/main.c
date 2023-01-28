#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "MyHeader.h"

int main()
{
	int i = hello();

	printf("%d\n", i);

	printf("%p\n", hello);

	return 0;
}
