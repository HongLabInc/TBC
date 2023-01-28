#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Dummy Output\n");

	for(int k = 0; k < 1000000; ++k)
	{
		int n = 100000000;
		int* ptr = (int*)malloc(n * sizeof(int));

		if (!ptr)// if(ptr == NULL)
		{
			printf("Malloc() failed\n");
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < n; ++i)
			ptr[i] = i + 1;

		printf("%d %d\n", ptr[0], ptr[1]);

		//free(ptr);
		//ptr = NULL;
	}

	// what happens ?	
	//printf("%d %d\n", ptr_backup[0], ptr_backup[1]);
	printf("Dummy Output\n");

	return 0;
}