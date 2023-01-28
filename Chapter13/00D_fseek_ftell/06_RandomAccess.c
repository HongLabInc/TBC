#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
	ABCDEF ...
	Current position 0 and read -> A
	Current position 1 and read -> B
	...
*/

int main()
{
	int ch;
	long cur;

	FILE* fp = fopen("test.txt", "r");

	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	fseek(fp, 2L, SEEK_SET);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	fseek(fp, -2L, SEEK_CUR);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	/* SEEK_END */

	fseek(fp, 0L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	fseek(fp, -1L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	fseek(fp, -2L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	/* fsetpos(), fgetpos() */

	fpos_t pt;
	pt = 10;
	fsetpos(fp, &pt);			//returns 0 ok
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);
	fgetpos(fp, &pt);			//returns 0 ok
	printf("%lld\n", pt);		//NOTE: not meant to be read directly

	return 0;
}