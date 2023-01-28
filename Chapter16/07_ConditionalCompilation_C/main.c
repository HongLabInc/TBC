#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TYPE 3

#if TYPE == 1
#include "my_function_1.h"
#elif TYPE == 2
#include "my_function_2.h"
#else
static void my_function()
{
	printf("Wrong compile option!");
}
#endif

int main()
{
	my_function();

	return 0;
}
