#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//NOTE: ungetc doesn't work on Windows.
void printBuffer();

int main()
{
	/* while(... getchar()...) */
// 	char c;
// 	while ((c = getchar()) != '\n')
// 	{
// 	    printf("%c\n", c);
// 		printBuffer();
// 	}

	/* scanf() example
	Test cases:
	A 1 2
	A1 2
	AB 1
	...
	*/
	//     char c;
	// 	int rows, cols;
	// 	int flag;
	// 	while (1)
	// 	{
	// 		flag = scanf("%c %d %d", &c, &rows, &cols);
	// 		printf("%c %d %d\n", c, rows, cols);
	// 		printBuffer();
	// 		//while ((c = getchar()) != '\n');
	// 	}

	/* 8.5 Question
	"#_3_2_" and "%_1_2" // _ means blank
	*/
	//char c;
	//int rows, cols;
	//int flag;
	//while ((c = getchar()) != '\n')
	//{
	//	flag = scanf("%d %d", &rows, &cols);
	//	printf("%c %d %d\n", c, rows, cols);
	//	printBuffer();
	//}

	printf("END\n");
	return 0;
}

void printBuffer()
{
	char buffer[BUFSIZ] = { -1, }; // Copy of input buffer

	fgets(buffer, BUFSIZ, stdin);

	printf("\nBuffer dump start:\n");
	for (int i = 0; i < BUFSIZ; i++)
	{
		if (buffer[i] == 0)
			break;
		printf("%i(%c) ", (int)buffer[i], buffer[i]);
	}
	printf("\nBuffer dump end.\n");

	/* ungetc() example */
//  ungetc('\n', stdin);
// 	ungetc('o', stdin);
// 	ungetc('l', stdin);
// 	ungetc('l', stdin);
// 	ungetc('e', stdin);
// 	ungetc('h', stdin);

// 	while (putchar(getchar()) != '\n')
// 		;

	//Note: ungetc() in inversed order of the string
	for (int i = BUFSIZ - 1; i >= 0; i--)
	{
		if (buffer[i] == 0)
			continue;
		ungetc(buffer[i], stdin);//NOTE: Doesn't work on Windows
	}
}


