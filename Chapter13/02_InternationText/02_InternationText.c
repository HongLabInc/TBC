#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>	// SetConsoleOutputCP()

int main()
{
	const UINT default_cp = GetConsoleOutputCP();
	printf("%u\n", default_cp);

	int ch;
	FILE* fr, * fw;

	const char* in_filename = "원본.txt";
	const char* out_filename = "사본.txt";

	unsigned long count = 0;

	if ((fr = fopen(in_filename, "r")) == NULL)	// Open a text file for reading.
	{
		printf("Can't open %s\n", in_filename);
		exit(EXIT_FAILURE);
	}

	if ((fw = fopen(out_filename, "w")) == NULL)	// Open a text file for writing.
	{
		printf("Can't open %s\n", out_filename);
		exit(EXIT_FAILURE);
	}

	SetConsoleOutputCP(CP_UTF8);// UTF-8 mode

	while ((ch = fgetc(fr)) != EOF)
	{
		fputc(ch, stdout);	// same as putchar(ch);
		fputc(ch, fw);
		count++;
	}

	fclose(fr);
	fclose(fw);

	SetConsoleOutputCP(default_cp);// ISO 2022 Korean

	printf("FILE %s has %lu characters\n", in_filename, count);
	printf("Copied to %s\n", out_filename);

	printf("한글 출력 확인");

	return 0;
}
