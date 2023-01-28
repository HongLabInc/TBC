#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "names_st.h"
#include "names_st.h"	// accidental second inclusion

int main()
{
	names candidate;

	get_names(&candidate);
	printf("Let's welcome ");
	show_names(&candidate);
	printf(" to this program!\n");

	return 0;
}