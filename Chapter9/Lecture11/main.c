#define _CRT_SECURE_NO_WARNINGS

#include "my_print_functions.h"
#include <stdio.h>

int main()
{
	print_hello();
	print_hi();
	print_hello();
	print_hi();
	print_str("No one lives forever.");
	print_str("Valar morghulis");

	printf("Hello!!");

	return 0;
}
