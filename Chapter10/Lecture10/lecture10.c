#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// type qualifiers: const, volatile, ... 

	const double PI = 3.14159;
	//PI = 2.14159;

	const int arr[5] = { 1, 2, 3, 4, 5};
	//arr[1] = 123;

	const double arr2[4] = { 1.0, 2.0, 3.0, 4.0};
	//arr2[0] = 100.0;

	const double* const pd = arr2;
	//*pd = 3.0;		// pd[0] = 3.0; arr2[0] = 3.0;
	//pd[2] = 1024.0;	// arr2[2] = 1024.0;
	
	printf("%f %f", pd[2], arr2[2]);

	//pd++;// allowed

	printf("%f %f", pd[2], arr2[2]);

	return 0;
}