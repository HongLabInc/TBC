#include <stdio.h>

int main()
{
	const int TWO = 2;

	int a;
	int b;
	int c;
	
	a = 42;
	b = a;
	c = TWO * (a + b);

	return 0;
}