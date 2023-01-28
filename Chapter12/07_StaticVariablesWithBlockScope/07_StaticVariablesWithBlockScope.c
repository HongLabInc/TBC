#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count()
{
	int ct = 0;
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;

	//return &ct;
}

void static_count()
{
	static int ct = 0;	// initialized only once!
	printf("static count = %d %lld\n", ct, (long long)& ct);
	ct++;

	//return &ct;
}

//int func(static int i)	// Warning (Error in GCC)
//{
//}

void counter_caller()
{
	count();
}

void static_counter_caller()
{
	static_count();
}

int main()
{
	count();
	count();
	counter_caller();

	static_count();
	static_count();
	static_counter_caller();

	return 0;
}