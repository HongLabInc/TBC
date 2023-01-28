#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Static variable with external linkage
	- File scope, external linkage, static storage duration
	- External storage class
	- External variables
*/

/* 
	Initializing External Variables
*/
int x = 5;					// ok, constant expression
int y = 1 + 2;				// ok, constant expression
size_t z = sizeof(int);		// ok, sizeof is a constant expression
//int x2 = 2 * x;			// not ok, x is a variable

int g_int = 0;
double g_arr[1000] = { 0.0, };

void fun()
{
	printf("g_int in fun() %d %p\n", g_int, &g_int);
	g_int += 10;
}

extern void fun_sec();

int main()
{
	/*
		defining declaration vs referencing declaration
	*/

	extern int g_int;			// Optional
	//extern int g_int = 1024;	// Error in block scope

	//int g_int = 123;			// hides global g_int

	extern double g_arr[];		// optional, size is not necessary

	printf("g_int in main() %d %p\n", g_int, &g_int);
	g_int += 1;

	fun();
	fun_sec();

	return 0;
}
