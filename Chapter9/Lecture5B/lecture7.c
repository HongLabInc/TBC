#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int temp(int i, int j)
{
	int m;

	printf("temp()  \t %lld %lld %lld\n", (long long)& i, (long long)& j, (long long)& m);

	m = i > j ? i : j;
	return m;
}

int int_max(int i, int j)
{
	int m;

	printf("int_max() \t %lld %lld %lld\n", (long long)& i, (long long)& j, (long long)& m);

	m = i > j ? i : j;

	temp(1, 2);

	return m;
}

int main()
{
	int a;

	a = int_max(1, 2);

	printf("main() a\t %lld\n", (long long)& a);

	{
		int b;
		b = int_max(4, 5);

		printf("main() b\t %lld\n", (long long)& b);
		{
			int b = 123;
			printf("main() b\t %lld\n", (long long)& b);
		}

		{
			int c = 456;
			printf("main() c\t %lld\n", (long long)& c);
		}
	}

	return 0;
}
