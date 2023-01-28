#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//for (int n = 1, nsqr = n * n; n < 10; n++, nsqr = n * n)
	//	printf("%d %d\n", n, nsqr);

	//Note that commas in printf() are not comma operators 
	//but separators

	//int i, j;
	//i = 1;
	//i++, j = i;// comma is a sequence point
	//printf("%d %d\n", i, j);

	//int x, y, z;
	//z = x = 1, y = 2;
	//printf("x=%d, y=%d, z=%d \n", x, y, z);
	//z = (x = 1), (y = 2);
	//printf("x=%d, y=%d, z=%d \n", x, y, z);
	//z = ((x = 1), (y = 2));
	//printf("x=%d, y=%d, z=%d \n", x, y, z);

	//int my_money = 123,456; // error
	int my_money = (123, 456);
	printf("%d\n", my_money);

	return 0;
}