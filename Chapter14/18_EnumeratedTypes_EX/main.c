#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp (HINT!)
#include <stdbool.h>// C99

enum spectrum {red, orange, yellow, green, blue};
const char* colors[] = { "red", "orange", "yellow", "green", "blue"};

#define LEN 30

int main()
{
	char choice[LEN] = { 0, };
	enum spectrum color;
	bool color_is_found = false;
	
	while (1)
	{
		puts("Input a color name (empty line to quit):");

		if (scanf("%[^\n]%*c", choice) != 1)
			break;

		for (color = red; color <= blue; color++)
		{
			if (strcmp(choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}

		if (color_is_found)
			switch (color)
			{
			case red:
				puts("Red roses");
				break;
			case orange:
				puts("Oranges are delicious");
				break;
			case yellow:
				puts("Yellow sunflowers");
				break;
			case green:
				puts("Green apples");
				break;
			case blue:
				puts("Blue ocean");
				break;
			}
		else
			printf("Please try different color %s.\n", choice);

		color_is_found = false;		
	}
	puts("Goodbye!");

	return 0;
}
