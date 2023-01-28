#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>	// isalpha() and more

/*
	Reference link
	https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
*/

int main()
{
	char ch;

	while ((ch = getchar()) != '\n')
	{
		if (islower(ch))// 'A' = 65, 'a' = 97
			ch = toupper(ch);
		else if (isupper(ch))
			ch = tolower(ch);

		//for (int i = '0'; i <= '9'; ++i)
		if (isdigit(ch) != 0)
			ch = '*';

		putchar(ch);
	}

	putchar(ch);// last '\n'

	return 0;
}