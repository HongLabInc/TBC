#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 31

int main(void)
{
	FILE* fp;
	char words[MAX] = { '\0', };
	
	const char* filename = "record.txt";

	/*
	fopen() mode strings for text files
	- r: reading
	- w: creating-and-writing or over-writing
	- a: appending or creating-and-writing
	- r+: both reading and writing
	- w+: reading and writing, over-writing or creating
	- a+: reading and writing, appending or creating
	*/

	if ((fp = fopen(filename, "a+")) == NULL)// Try r+, w+, a+
	{
		fprintf(stderr, "Can't open \"%s\" file.\n", filename);
		exit(EXIT_FAILURE);
	}

	//while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.'))
	//	fprintf(fp, "%s\n", words);

	while ((fgets(words, MAX, stdin) != NULL) && (words[0] != '.'))
		fputs(words, fp);

	rewind(fp);  /* go back to beginning of file */

	//while (fscanf(fp, "%s", words) != EOF)
	//	fprintf(stdout, "%s\n", words);

	while (fgets(words, MAX, fp) != NULL)// EOF check
		fputs(words, stdout);

	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");

	return 0;
}