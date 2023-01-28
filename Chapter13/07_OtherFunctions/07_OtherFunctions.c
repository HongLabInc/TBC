#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp;
	int ch;

	/* ungetc() */
	//fp = fopen("input.txt", "r");

	//ch = fgetc(fp);
	//fputc(ch, stdout);

	//ungetc((int)'A', fp);		// try another characters

	//ch = fgetc(fp);
	//fputc(ch, stdout);

	//ch = fgetc(fp);
	//fputc(ch, stdout);

	//fclose(fp);

	/* setvbuf() */

	//fp = fopen("input.txt", "r");

	//char buffer[32] = {'\0',};

	//setvbuf(fp, buffer, _IOFBF, sizeof(buffer));	// _IOLBF, _IOFBF, _IONBF
	//
	//// dump buffer
	//for (int i = 0; i < sizeof(buffer); ++i)
	//	printf("%hhd", buffer[i]);
	//printf("\n");

	//ch = fgetc(fp);	// Read just only a single character!

	//// dump buffer
	//for (int i = 0; i < sizeof(buffer); ++i)
	//		printf("%c", buffer[i]);
	//	printf("\n");

	//fclose(fp);

	/* fflush() */

	// Writing a large amount of data
	// fflush(fp);

	return 0;
}