#pragma once

#include <stdio.h>

static void different_func_in_different_file()
{
	printf("__FILE__ : %s\n", __FILE__);
	printf("__func__ %s\n", __func__);
}