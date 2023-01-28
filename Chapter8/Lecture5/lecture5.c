#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(char cr, int lines, int width);

int main()
{
	char c;
	int rows, cols;

	//while (1)
	//{
	//	scanf("%c %d %d", &c, &rows, &cols);
	//	while (getchar() != '\n') continue;
	//	display(c, rows, cols);
	//	if (c == '\n')
	//		break;		// doesn't work well
	//}

	printf("Input one character and two integers:\n");
	while ((c = getchar()) != '\n')
	{
		scanf("%d %d", &rows, &cols);
		while (getchar() != '\n') continue;

		display(c, rows, cols);
		printf("Input another character and two integers:\n");
		printf("Press Enter to quit.\n");
	}

	return 0;
}

void display(char cr, int lines, int width)
{
	int row, col;

	for (row = 1; row <= lines; row++)
	{
		for (col = 1; col <= width; col++)
			putchar(cr);
		putchar('\n');
	}
}