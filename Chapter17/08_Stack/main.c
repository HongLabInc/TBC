#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack.h"

print_stack(const Stack * stack)
{
	printf("Stack : ");
	if (IsEmpty(stack) == true)
		printf("Empty");
	else
		for (int i = 0; i <= stack->top; ++i)
		printf("%d ", stack->items[i].key);
	printf("\n");
}

element get_element(const int key)
{
	element new_element;
	new_element.key = key;
	return new_element;
}

int main()
{
	Stack my_stack;
	
	Initialize(&my_stack);
	print_stack(&my_stack);

	Push(&my_stack, get_element(1));
	print_stack(&my_stack);

	Push(&my_stack, get_element(3));
	print_stack(&my_stack);

	Push(&my_stack, get_element(4));
	print_stack(&my_stack);

	Push(&my_stack, get_element(5));
	print_stack(&my_stack);

	Push(&my_stack, get_element(6));
	print_stack(&my_stack);

	Push(&my_stack, get_element(7));
	print_stack(&my_stack);

	for (int i = 0; i < MAX_STACK_SIZE + 1; ++i)
	{
		printf("Pop : %d\n", Pop(&my_stack).key);
		print_stack(&my_stack);
	}

	return 0;
}