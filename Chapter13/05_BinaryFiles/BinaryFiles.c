#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*
	fopen() mode string for binary IO
	- "rb", "wb", "ab"
	- "ab+", "a+b"
	- "wb+", "w+b"
	- "ab+", "a+b"

	C11 'x' mode fails if the file exists, instead of overwriting it.
	- "wx", "wbx", "w+x", "wb+x", "w+bx"
	*/

	// Writing example
	{
		FILE* fp = fopen("binary_file", "wb");

		double d = 1.0 / 3.0;
		int n = 123;
		int* parr = (int*)malloc(sizeof(int) * n);
		if (!parr) exit(1);
		for (int n = 0; n < 123; ++n)
			* (parr + n) = n * 2;

		fwrite(&d, sizeof(d), 1, fp);
		fwrite(&n, sizeof(n), 1, fp);
		fwrite(parr, sizeof(int), n, fp);

		fclose(fp);
		free(parr);

		// Total size is 8 * 1 + 4 * 1 + 123 * 4 = 504 bytes
	}

	// Reading example, feof(), ferror()
	{
		FILE* fp = fopen("binary_file", "rb");
		double d;
		int n = 0;
		fread(&d, sizeof(d), 1, fp);
		fread(&n, sizeof(n), 1, fp);

		int* parr = (int*)malloc(sizeof(int) * n);
		if (!parr) exit(1);

		fread(parr, sizeof(int), n, fp);

		printf("feof = %d\n", feof(fp));

		printf("%f\n", d);
		printf("%d\n", n);
		for (int i = 0; i < n; ++i)
			printf("%d ", *(parr + i));
		printf("\n");

		printf("feof = %d\n", feof(fp));

		fread(&n, sizeof(n), 1, fp);		 // read one more toward EOF

		printf("feof = %d\n", feof(fp));     // returns non-zero at EOF
		printf("ferror = %d\n", ferror(fp)); // returns 0 : ok

		fwrite(&n, sizeof(n), 1, fp);		 // try writing to make an error

		printf("ferror = %d\n", ferror(fp)); // 0 is ok, non-zero otherwise.

		fclose(fp);
		free(parr);
	}

	return 0;
}