#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
	rand(), srand(), malloc(), free(), ...
*/

void goodbye(void)
{
	printf("Goodbye\n");
}

void thankyou(void)
{
	printf("Thankyou\n");
}

int main()
{
	printf("Purchased?\n");
	if (getchar() == 'y')
		atexit(thankyou);
	
	while (getchar() != '\n') {};

	printf("Goodbye message ?\n");
	if (getchar() == 'y')
		atexit(goodbye);		

	/*
		exit(0);
	*/

	/*
		qsort();
	*/

	return 0;
}