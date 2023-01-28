#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int* temp;

int int_max(int i, int j)
{
	int m;
	m = i > j ? i : j;
	printf("address m = %p\n", &m);

	temp = &m;

	return m;
}

int main()
{
	int a;

	a = int_max(1, 2);

	printf("mtemp = %d\n", *temp);

	{
		int b;
		b = int_max(4, 5);

		printf("%p\n", &b);

		int* t1, * t2;
		{
			int b = 337;
			//printf("%p\n", &b);
			t1 = &b;
		}

		printf("t1 = %d\n", *t1);

		{
			int c;
			//printf("%p\n", &c);
			t2 = &c;
		}

		//printf("%p %p %d\n", t1, t2, (int)t1 - (int)t2);
	}

	return 0;
}

