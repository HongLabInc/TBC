#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/* Pointer Compatibility */

	//int n = 5;
	//double x;
	//x = n;		// no error
	//int* p1 = &n;
	//double* pd = &x;
	////pd = p1;	// Warning

	//int* pt;
	//int(*pa)[2];
	//int ar1[2][3] = { 3, };
	//int ar2[3][2] = { 7, };
	//int** p2;		// a pointer to a pointer

	//pt = &ar1[0][0];	// pointer-to-int

	//pt = ar1[0];		// pointer-to-int;
	//
	////pt = ar1;			// Warning (Error)
	//
	////pa = ar1;			// pointer-to-int[3]
	//pa = ar2;			// Warning or error

	//p2 = &pt;			// pointer-to-int *
	//*p2 = ar2[0];		// pointer-to-int
	////p2 = ar2;			// Warning (Error)
	////Notes
	//// - p2: pointer to pointer to int
	//// - ar2: a pointer to array-of-2-ints

	/* Pointer and const */

	//int x = 20;
	//const int y = 23;
	//int* p1 = &x;
	//const int* p2 = &y;
	//const int** pp2 = &p1;
	////p1 = p2;		// Warning (Error)

	////*p2 = 123;	// Error
	//p2 = p1;

	//int x2 = 30;
	//int* p3 = &x2;
	//*pp2 = p3;
	//pp2 = &p1;

	//{
	//	const int** pp2;
	//	int* p1;
	//	const int n = 13;
	//	pp2 = &p1;		// const?
	//	*pp2 = &n;		// sets p1 to point at n
	//	*p1 = 10;		// change n
	//}

	/* C const and C++ const */
	{
		const int y;
		const int* p2 = &y;
		int* p1;
		p1 = p2;	// warning (error in cpp)
	}

	return 0;
}