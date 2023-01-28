#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TWO 2 /* you can use comments if you like */
#define OW "Consistency is the last refuge of the unimagina\
tive. - Oscar Wilde " /* a backslash continues a definition */
					  /* to the next line */

#define FOUR	TWO*TWO
#define PX		printf("X is %d. \n", x);
#define FMT		"X is %d.\n"

int main()
{
	int x = TWO;

	PX;
	x = FOUR;
	printf(FMT, x);
	printf("%s\n", OW);		// replaced
	printf("TWO: OW\n");	// Not replaced printf("%d: %s\n", TWO, OW);


	return 0;
}