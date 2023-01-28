#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	// printf() in second.c

extern int g_int;// referencing declaration

void fun_second(void)
{
	g_int += 1;
	printf("g_int in fun_second() %d %p\n", g_int, &g_int);
}