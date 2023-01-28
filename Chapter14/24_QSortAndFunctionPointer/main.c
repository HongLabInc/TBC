#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//TODO: try increasing/decreasing order
int compare(const void* first, const void* second)
{
	if (*(float*)first > * (float*)second)
		return 1;
	else if (*(float*)first < *(float*)second)
		return -1;
	else
		return 0;
}

int main()
{
	float arr[] = { 8.1f, 2.4f, 5.6f, 3.2f, 6.1f, 11.0f };
	int n = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, n, sizeof(float), compare);

	for (int i = 0; i < n; i++)
		printf("%f ", arr[i]);

	return 0;
}