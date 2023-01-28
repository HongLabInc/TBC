#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//#undef _WIN64

void say_hello()
{
//#ifdef _WIN64		// #if defined (_WIN64)
#if defined (_WIN64)
	printf("Hello, WIN64");
#elif _WIN32
	printf("Hello, WIN32");
#elif __linux__
	printf("Hello, linux");
#endif
}

int main()
{
	say_hello();

	return 0;
}

