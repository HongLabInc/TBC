#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void why_me();

int main()
{
	printf("The file is %s.\n", __FILE__);
	printf("The date is %s.\n", __TIME__);
	//printf("The version is %ld.\n", __STDC_VERSION__);	// VS not defined
	printf("This is line %d.\n", __LINE__);
	printf("This function is %s\n", __func__);
	why_me();

	return 0;
}

void why_me()
{
	printf("This function is %s\n", __func__);
	printf("This is line %d.\n", __LINE__);
}