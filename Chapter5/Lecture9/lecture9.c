#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <math.h>	// sqrt

int main()
{
	/* Statements */
	int x, y, apples;	// declaration statement
	apples = 3;			// assignment statement
	;					//null statement
	7;
	1 + 2;
	x = 4;
	++x;
	//y = sqrt(x);
	x = 1 + (y = 5);	// y = 5 is subexpression

	while (x++ < 10)	// while statement (structured statements)
		y = x + y;

	printf("%d\n", y);	// function statement

	return 0;// return statement

	/* Side Effects and Sequence Points */

	x = 4;			    // main intent is evaluating expressions
	y = 1 + x++;

	printf("%d\n", y);  // printing is a side effect ?
	
	/* full expression */

	while (x++ < 10)	// (x++ < 10) is a full expression.
		printf("%d\n", x);

	y = (4 + x++) + (6 + x++); // None of (4 + x++) or (6 + x++) is a full expression.
	
}