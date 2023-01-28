#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int g = 123;

void func()
{
	int i = 123;
	printf("Local variable     \t%lld\n", (long long)& i);
}

int main()
{
	const char* message = "Banana";

	void (*f_ptr)() = func; // address of a function

	printf("Local pointer    \t%lld\n", (long long)& message);
	printf("Function pointer \t%lld\n", (long long)& f_ptr);
	printf("String data      \t%lld\n", (long long)message);
	printf("Function address \t%lld\n", (long long)f_ptr);
	printf("Function address \t%lld\n", (long long)main);
	printf("Global variable  \t%lld\n", (long long)& g);

	func();

	int* ptr = (int*)malloc(100 * sizeof(int));
	if (!ptr) exit(EXIT_FAILURE);

	printf("Allocated memory \t%lld\n", (long long)ptr);

	free(ptr);

	return 0;
}
