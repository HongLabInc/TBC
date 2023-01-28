#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//int arr[4] = { 2, 5, 11, 18 };
	double arr[2] = { 1.1, 2.2 };
	for (int i = 0; i < 2; ++i)
		arr[i] = (i + 1.0) * 1.1;

	for (int i = 0; i < 2; ++i)
		printf("%f\n", arr[i]);

	/* Monthly temperatures */
	int high[12] = {2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4};
	int low[12] = {-7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5};

	for (int i = 0; i < 12; ++i)
		printf("%d ", high[i]);

	int* ptr;
	ptr = (int[2]) { 10, 20 };

	printf("%d\n", ptr[0]);

	//int a;

	////printf("%d\n", a);

	//int arr[10];

	//for (int i = 0; i < 10; ++i)
	//	printf("%d", arr[i]);
	//printf("\n");

	//static int a_static;

	//printf("%d\n", a_static);

	//static int arr_static[10];

	//for (int i = 0; i < 10; ++i)
	//	printf("%d", arr_static[i]);
	//printf("\n");

	return 0;
}