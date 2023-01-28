#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_functions.h"
#include "my_structures.h"
//#include "my_macros.h"	// path
#include "my_headers\my_macros.h"
//#include "D:\git-repo\TBC\Chapter16\06_Include\my_headers\my_macros.h"

extern int status;

int main()
{

#include "hello_world.h"

	printf("PI = %f\n", PI);

	printf("%p %d\n", &status, status);

	print_status();

	printf("%d\n", multiply(51, 2));

	printf("main()\n");
	printf("Static function address %p\n", multiply);
	printf("Static variable address %p\n", &si);

	print_address();

	patient_info james = { "James Bone", 45 }, michael = { "Michael Jobs", 50 };

	return 0;
}