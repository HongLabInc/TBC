#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double average(double *, int n);

int main()
{
	double arr1[5] = { 10, 13, 12, 7, 8 };
	//double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
	double arr2[3] = { 1.8, -0.2, 6.3 };	// size is different

	printf("Address = %p\n", arr1);
	printf("Size = %zd\n", sizeof(arr1));
	printf("Address = %p\n", arr2);
	printf("Size = %zd\n", sizeof(arr2));

	printf("Avg = %f\n", average(arr1, 5));
	printf("Avg = %f\n", average(arr2, 3));

	return 0;
}

double average(double *data_array, int n)
{
	printf("Size = %zd in function average\n", sizeof(data_array));

	double avg = 0.0;
	for (int i = 0; i < n; ++i)
	{
		avg += data_array[i];
	}
	avg /= (double)n;

	return avg;
}

/*
double average(double *arr, int n);
double average(double *, int n);
double average(double arr[], int n);
double average(double [], int n);
*/