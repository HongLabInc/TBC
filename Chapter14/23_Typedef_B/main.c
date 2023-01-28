#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	"One good way to synthesize declarations is 
	in small steps with typedef, ..."
	- K&R book Chapter 5.12
*/

/* Complicated Function Declarations */

char char3[3] = { 'A', 'B', 'C' };

char(*complicated_function1())[3] // Function Returns Pointer To Char[3]
{
	return &char3;// Returns a pointer to char[3]
}

typedef char(*FRPTC3())[3];	// Funciton Returns Pointer To Char[3]
typedef char(*(*PTFRPTC3)())[3];

char(*(*fptr1)())[3] = complicated_function1;

FRPTC3 *fptr2 = complicated_function1;
PTFRPTC3 fptr3 = complicated_function1;

/* Use typedef to make declarations simpler */

typedef char c3[3];

c3* complicated_function2()
{
	return &char3;// Returns a pointer to char[3]
}

int main()
{
	char(*ret_val)[3] = fptr1();

	printf("%c %c %c\n", (*ret_val)[0], (*ret_val)[1], (*ret_val)[2]);

	c3 *my_c3 = fptr2();

	printf("%c %c %c\n", (*my_c3)[0], (*my_c3)[1], (*my_c3)[2]);

	return 0;
}