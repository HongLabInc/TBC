#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// make a test binary file
	{
		FILE* fp = fopen("binary", "wb");
		for (int i = 0; i < 100; ++i)
		{
			double d = i * 1.11;
			fwrite(&d, sizeof(double), 1, fp);
		}
		fclose(fp);
	}

	// read

	FILE* fp = fopen("binary", "rb");
	long cur;
	double d;
	
	cur = ftell(fp);
	printf("Before reading %ld\n", cur);

	fread(&d, sizeof(double), 1, fp);

	cur = ftell(fp);
	printf("After reading %ld\n", cur);
	
	printf("%f\n", d);

	fread(&d, sizeof(double), 1, fp);
	printf("%f\n", d);

	cur = ftell(fp);
	printf("After reading %ld\n", cur);

	fseek(fp, 32L, SEEK_SET);	// 32 = 4 * 8
	fread(&d, sizeof(double), 1, fp);
	printf("%f\n", d);

	fclose(fp);

	return 0;
}