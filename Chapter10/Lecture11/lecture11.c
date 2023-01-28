#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_array(const int arr[], const int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

void add_value(int arr[], const int n, const int val)
{
	int i;
	for (i = 0; i < n; i++)
		arr[i] += val;
}

int sum(const int ar[], const int n)
{
	int i;
	int total = 0;

	for (i = 0; i < n; i++)
		total += ar[i];	// wrong implementation

	return total;
}

int main()
{
	const int arr[] = { 1, 2, 3, 4, 5 };
	const int n = sizeof(arr) / sizeof(arr[0]);

	print_array(arr, 5);
	add_value(arr, 5, 100);
	print_array(arr, 5);

	int s = sum(arr, n);

	printf("sum is %d\n", s);
	print_array(arr, 5);

	return 0;
}