#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int ch;
	FILE* fr, * fw;

	const char* out_filename = "copy.txt";

	unsigned long count = 0;

	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fr = fopen(argv[1], "r")) == NULL)	// Open a text file for reading.
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((fw = fopen(out_filename, "w")) == NULL)	// Open a text file for writing.
	{
		printf("Can't open %s\n", out_filename);
		exit(EXIT_FAILURE);
	}


	while ((ch = fgetc(fr)) != EOF)
	{
		fputc(ch, stdout);	// same as putchar(ch);
		fputc(ch, fw);
		count++;
	}

	fclose(fr);
	fclose(fw);

	printf("FILE %s has %lu characters\n", argv[1], count);
	printf("Copied to %s", out_filename);

	return 0;
}

/* 

//File Reading example

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
int main()
{
	int c;
	FILE *file = NULL;
	char file_name[] = "my_file.txt";//TODO: use scanf(...)

	file = fopen(file_name, "r");// read or write
	if (file == NULL)
	{
		printf("Failed to open file.\n");
		exit(1);
	}

	while ((c = getc(file)) != EOF)
		putchar(c);
	fclose(file);

	return 0;
}
*/