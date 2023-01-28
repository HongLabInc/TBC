#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>//Windows, _getch(), _getche()

int main()
{
	char c;

	while ((c = _getch()) != '.')//echo
		putchar(c);

	return 0;
}