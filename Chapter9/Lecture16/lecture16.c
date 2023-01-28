#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a = 3, b = 5, c = 7, d = 9;
	int* a_ptr = &a, * b_ptr = &b, * c_ptr = &c, * d_ptr = &d;

	printf("%p %p %p %p", &a, &b, &c, &d);

	return 0;
}