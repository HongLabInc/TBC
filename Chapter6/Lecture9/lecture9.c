#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
		for(initialize; test; update)
			statement
	*/

	for (int i = 10; i > 0; i--)
		printf("%d ", i);

	for (int i = 0; i < 100; i = i + 8)
		printf("%d ", i);

	for (char c = 'A'; c <= 'Z'; c++)
		printf("%c ", c);

	for (int i = 0; i * i < 10; i++)
		printf("%d ", i);

	for (int x = 1, y = 5; y <= 20; y = (++x * 3) + 10)
		printf("%d ", x);

	for (double d = 100.0; d < 300; d = d * 1.1)
		printf("%f\n", d);

	int i, n;
	n = 2;
	for (i = 2; n < 10; /* left blank */)
	{
		n = n * i;
		printf("%d\n", n);
	}

	for ( ; ; )
		printf("I love you! ");

	//int i = 0;
	//for(printf("Let's go!\n"); i != 7; scanf("%d", &i))
	//	;// null statement

	return 0;
}