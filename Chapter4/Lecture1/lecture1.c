#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char fruit_name[40]; // stores only one character.

	printf("What is your farovate fruit?\n");

	scanf("%s", fruit_name); // be careful with &

	printf("You like %s!\n", fruit_name);

	return 0;
}