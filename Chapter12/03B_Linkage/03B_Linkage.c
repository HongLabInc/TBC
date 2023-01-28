#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Linkage

	Variables with block scope, function scope, or function prototype scope
	- No linkage

	File scope variables
	- External or internal linkage
*/

// translation unit

int el;			// file scope with external linkage (global variable)
static int il;	// file scope with internal linkage

void testLinkage();

int main()
{
	el = 1024;

	testLinkage();

	printf("%d\n", el);

	return 0;
}