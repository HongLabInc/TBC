//#pragma once

#ifndef HEADER_B
#define HEADER_B

#include <stdio.h>
#include "Header_A.h"

static void test_function_B()
{
	test_function_A();
	printf("Hello, Header_B\n");
}

#endif
