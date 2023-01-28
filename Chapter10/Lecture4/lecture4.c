#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[10];

	int num = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < num; ++i)
		arr[i] = (i + 1) * 100;

	int* ptr = arr;

	printf("%p %p %p\n", ptr, arr, &arr[0]);

	ptr += 2;
	
	printf("%p %p %p\n", ptr, arr + 2, &arr[2]);

	//Note: arr += 2; // invalid

	printf("%d %d %d\n", *(ptr + 1), *(arr + 3), arr[3]);//Note: *(ptr+1) == ptr[1]

	//// Warning
	printf("%d %d %d\n", *ptr + 1, *arr + 3, arr[3]);

	for (int i = 0, *ptr = arr; i < num; ++i)
	{
		printf("%d %d\n", *ptr++, arr[i]);
		//printf("%d %d\n", *(ptr + i), arr[i]);
		//printf("%d %d\n", *ptr + i, arr[i]);
	}

	return 0;
}