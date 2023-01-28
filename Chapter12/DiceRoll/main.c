#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// srand()
#include <time.h>	// time()
#include "diceroll.h"

/*
	rand() 0 to RAND_MAX defined in stdlib.h. (typically INT_MAX)
*/

int main()
{
	int dice, roll;	// Dice is the plural form of die
	int sides;

	srand((unsigned int)time(0));	// random seed
	printf("# of sides per die, 0 to stop.\n");

	while (scanf("%d", &sides) == 1 && sides > 0)
	{
		printf("How many dice?\n");

		int status;	// ?
		if ((status = scanf("%d", &dice)) != 1)
		{
			if (status == EOF)
				break;
			else
			{
				printf("You should have entered an integer.");
				printf("Let's begin again.\n");

				while (getchar() != '\n')
					continue;

				printf("How many sides? Enter 0 to stop.\n");
				continue;
			}
		}

		roll = roll_n_dice(dice, sides);

		printf("You have rolled a %d using %d %d-sided dice.\n", roll, dice, sides);
		printf("How many sides? Enter 0 to stop.\n");
	}

	printf("The rollem() function was called %d times.\n", roll_count);	// use extern variable

	printf("GOOD FORTUNE TO YOU!\n");

	return 0;
}