#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*
		One variable
	*/

	//int* ptr = NULL;

	//ptr = (int*)malloc(sizeof(int) * 1);
	//if (!ptr) exit(1);

	//*ptr = 1024 * 3;
	//printf("%d\n", *ptr);

	//free(ptr);
	//ptr = NULL;

	/*
		1D array
	*/

	//int n = 3;
	//int * ptr = (int*)malloc(sizeof(int) * n);
	//if (!ptr) exit(1);

	//ptr[0] = 123;
	//*(ptr + 1) = 456;
	//*(ptr + 2) = 789;

	//free(ptr);
	//ptr = NULL;

	/*
		2D array
	*/

	//int row = 3, col = 2;
	//int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);
	////int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col);// VLA
	//if (!ptr2d) exit(1);

	//for (int r = 0; r < row; r++)
	//	for (int c = 0; c < col; c++)
	//		ptr2d[r][c] = c + col * r;

	//for (int r = 0; r < row; r++)
	//{
	//	for (int c = 0; c < col; c++)
	//		printf("%d ", ptr2d[r][c]);
	//	printf("\n");
	//}

	/*
		Using 1D arrays as 2D arrays

		row = 3, col = 2

		(r, c)

		2D
		(0, 0) (0, 1)
		(1, 0) (1, 1)
		(2, 0) (2, 1)

		1D
		(0, 0) (0, 1) (1, 0) (1, 1) (2, 0) (2, 1)
		0      1      2      3      4      5      = c + col * r
		
	*/

	//int row = 3, col = 2;
	//int* ptr = (int*)malloc(row * col * sizeof(int));
	//if (!ptr) exit(1);

	//for (int r = 0; r < row; r++)
	//	for (int c = 0; c < col; c++)
	//		ptr[c + col * r] = c + col * r;

	//for (int r = 0; r < row; r++)
	//{
	//	for (int c = 0; c < col; c++)
	//		printf("%d ", *(ptr + c + col * r));
	//	printf("\n");
	//}
	
	/*
		Using 1D arrays as 3D arrays

		row = 3, col = 2, depth = 2

		(r, c, d)

		3D 
		-------------------
		(0, 0, 0) (0, 1, 0)
		(1, 0, 0) (1, 1, 0)
		(2, 0, 0) (2, 1, 0)
		-------------------
		(0, 0, 1) (0, 1, 1)
		(1, 0, 1) (1, 1, 1)
		(2, 0, 1) (2, 1, 1)
		-------------------

		1D
		(0, 0, 0) (0, 1, 0) (1, 0, 0) (1, 1, 0) (2, 0, 0) (2, 1, 0) (0, 0, 1) (0, 1, 1)	(1, 0, 1) (1, 1, 1) (2, 0, 1) (2, 1, 1)
		0         1         2         3         4         5         6         7         8         9         10        11
		= c + col * r + (col*row) * d
		= 1 + 2 * 1 + (3*2) * 1 = 1 + 2 + 6 = 9

		3D
		row, col, depth, height
		(r, c, d, h)
		index = c + col * r + (col*row) * d + (row * col * depth) * h
	*/

	int row = 3, col = 2, depth = 2;
	int* ptr = (int*)malloc(row * col * depth * sizeof(int));
	if (!ptr) exit(1);

	for (int d = 0; d < depth; d++)
		for (int r = 0; r < row; r++)
			for (int c = 0; c < col; c++)
				ptr[c + col * r + (col * row) * d] = c + col * r + (col * row) * d;

	/*
		int idx2(int c, int r)
		{
			return c + col * r;
		}

		int idx3(int c, int r, int d)
		{
			static const int cr = col * row;
			return c + col * r + cr * d;
		}
	*/

	for (int d = 0; d < depth; d++)
	{
		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
				printf("%d ", *(ptr + c + col * r + (col * row) * d));
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}