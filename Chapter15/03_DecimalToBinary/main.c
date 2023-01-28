#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>   // pow()
#include <string.h> // strlen()
#include <stdlib.h> // exit()
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main()
{
	unsigned char i = to_decimal("01000110");
	unsigned char mask = to_decimal("00000101");

	print_binary(i);
	print_binary(mask);
	print_binary(i & mask);

	/*
		Decimal to binary

			   Number     Mask         Mask
		2^7 : (01000110 & 10000000) != 10000000    print 0
		2^6 : (01000110 & 01000000) == 01000000    print 1
		2^5 : (01000110 & 00100000) != 00100000    print 0
		2^4 : (01000110 & 00010000) != 00010000    print 0
		2^3 : (01000110 & 00001000) != 00001000    print 0
		2^2 : (01000110 & 00000100) == 00000100    print 1
		2^1 : (01000110 & 00000010) == 00000010    print 1
		2^0 : (01000110 & 00000001) != 00000001    print 0
	*/

	return 0;
}

void print_binary(const unsigned char num)
{
	printf("Decimal %3d \t== Binary ", num);

	const size_t bits = sizeof(num) * 8;
	for (size_t i = 0; i < bits; ++i)
	{
		const unsigned char mask = 
			(unsigned char)pow((double)2, (double)(bits - 1 - i));
		// unsigned char mask = pow(2, (bits - 1 -i ));

		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}

	//for (size_t i = bits - 1; i >= 0; --i)// size_t ERROR
	//for (int i = bits - 1; i >= 0; --i)
	//{
	//	const unsigned char mask =
	//		(unsigned char)pow((double)2, (double)i);

	//	if ((num & mask) == mask)
	//		printf("%d", 1);
	//	else
	//		printf("%d", 0);
	//}

	printf("\n");
}

unsigned char to_decimal(const char bi[])
{
	const size_t bits = strlen(bi);
	unsigned char sum = 0;
	for (size_t i = 0; i < bits; ++i)
	{
		if (bi[i] == '1')
			sum += (unsigned char)pow((double)2, (double)(bits - 1 - i));
		else if (bi[i] != '0') {
			printf("Wrong character : %c", bi[i]);
			exit(1);
		}
	}

	return sum;
	//printf("Binary %s == Decimal %d\n", bi, sum);
}

