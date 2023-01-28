#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	return 0;
}

////#define _CRT_SECURE_NO_WARNINGS   //Not necessary
//#include <stdio.h>
//
//#define ROWS 3
//#define COLS 4
//
//int sum2d_2(int ar[][COLS], int row)
//{
//	int r, c, tot = 0;
//	for (r = 0; r < row; r++)
//		for (c = 0; c < COLS; c++)
//			tot += ar[r][c];
//	return tot;
//}
//
//int sum2d_3(int* ar, int row, int col)
//{
//	int r, c, tot = 0;
//	for (r = 0; r < row; r++)
//		for (c = 0; c < col; c++)
//			tot += *(ar + c + col * r);	//ar[c + col * r]
//	return tot;
//}
//
//int sum2d_4(int row, int col, int ar[row][col])
//{
//	//printf("%zd\n", sizeof(ar));
//	//printf("%zd\n", sizeof(ar[0]));
//	int r, c, tot = 0;
//	for (r = 0; r < row; r++)
//		for (c = 0; c < col; c++)
//			tot += ar[r][c];
//	return tot;
//}

//int main()
//{
//	int n;
//
//	printf("Input array length : ");
//	scanf("%d", &n);
//
//	float my_arr[n];//Note: cannot change length after declaration
//
//	for (int i = 0; i < n; ++i)
//		my_arr[i] = (float)i;
//
//	for (int i = 0; i < n; ++i)
//		printf("%f\n", my_arr[i]);
//
//
//	int data[ROWS][COLS] = {
//								{1, 2, 3, 4},
//								{5, 6, 7, 8},
//								{9, 0, 1, 2}
//	};
//
//	printf("%d\n", sum2d_4(ROWS, COLS, data));
//
//	return 0;
//}
