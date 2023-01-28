#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int* ptr = 0;// try double*, long long*, char*, void*

	//printf("%d", *ptr);//Error in this lecture

	printf("%p %lld\n", ptr, (long long)ptr);

	ptr -= 2;	// try -=, ++, --, -, +

	printf("%p %lld\n", ptr, (long long)ptr);

	//ptr = -ptr;	// Not working
	//ptr = +ptr;	// Not working

	/* Subtraction */
	double arr[10];
	double* ptr1 = &arr[1], * ptr2 = &arr[3];

	//int * ptr3 = ptr1 + ptr2;	// Not working
	int i = ptr2 - ptr1;	// meaning?

	printf("%lld %lld %d\n", (long long)ptr1, (long long)ptr2, i);

	return 0;
}