#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/** Motivation
int c = 0; // red:0, orange:1, yellow:2, green:3, ...
if (c == 0)
	printf("red");
else if(c == 1)
	printf("orange");
else if (c == 2)
	printf("yellow");	
... ...
*/

/**
#define RED		1
#define ORANGE	2
#define YELLOW  3

int c = YELLOW;
if (c == YELLOW)
	printf("yellow");
*/

int main()
{
	/*
		Enumerated type
		- Symbolic names to represent integer constants
		- Improve readability and make it easy to maintain
		- enum-specifier (struct-specifier, union-specifier)

		Enumerators
		- The symbolic constants
	*/

	enum spectrum { red, orange, yellow, green, blue, violet };
	//				0    1       2       3      4     5
	
	enum spectrum color;
	color = blue;
	if (color == yellow)
		printf("yellow");	//Note: enumerators are not strings
	
	for (color = red; color <= violet; color++)//Note: ++ operator doesn't allowed in C++, use type int.
		printf("%d\n", color);

	printf("red = %d, orange = %d\n", red, orange);
	
	enum kids { jackjack, dash, snoopy, nano, pitz };
	// nina has a value of 3
	enum kids my_kid = nano;
	printf("nano %d %d\n", my_kid, nano);

	enum levels { low = 300, medium = 500, high = 2000 };

	int score = 800;//TODO: user input
	if (score > high)
		printf("High score!\n");
	else if (score > medium)
		printf("Good job\n");
	else if (score > low)
		printf("Not bad\n");
	else
		printf("Do your best\n");

	enum pet { cat, dog = 10, lion, tiger };
	// puma has a value of 11
	printf("cat %d\n", cat);
	printf("lion %d\n", lion);

	return 0;
}