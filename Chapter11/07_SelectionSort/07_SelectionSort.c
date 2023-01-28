#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Selection Sort Algorithm
	https://www.geeksforgeeks.org/selection-sort/

	Youtube search "Selection Sort", "CS50"

	64 25 12 22 11	(min_idx = 0)
	   64			(min_idx = 0)
	   25			(min_idx = 1)
		  25        (min_idx = 1)
		  12        (min_idx = 2)
			 12     (min_idx = 2)
				12  (min_idx = 2)
				11  (min_idx = 4)
	11 25 12 22 64  (swap arr[0] and arr[4])

	11 25 12 22 64	(min_idx = 1)
		  25		(min_idx = 1)
		  12		(min_idx = 2)
			 12		(min_idx = 2)
				12	(min_idx = 2)
	11 12 25 22 64  (swap arr[1] and arr[2])

	11 12 25 22 64	(min_idx = 2)
	...

	11 12 22 25 64	(min_idx = 3)
	...
*/

void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);

int main()
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	selectionSort(arr, n);	// ascending order

	printArray(arr, n);

	return 0;
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < n - 1; i++)	//Note n - 1
	{
		// Find the minimum element in unsorted array 
		//TODO: fill the blank(s)
		for (j = i + 1; j < n; j++)	//Note i + 1
		{
			//TODO: fill the blank(s)
		}

		// Swap the found minimum element with the first element
		//TODO: fill the blank(s)
	}
}





/*
		min_idx = i;

		if (arr[j] < arr[min_idx])
			min_idx = j;

		swap(&arr[min_idx], &arr[i]);
*/
