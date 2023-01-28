#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h> // CHAR_BIT
#include <stdbool.h>
#include <string.h>

void char_to_binary(unsigned char uc)
{
	const int bits = CHAR_BIT * sizeof(unsigned char);
	for (int i = bits - 1; i >= 0; i--)
		printf("%d", (uc >> i) & 1);
}

void print_binary(char* data, int bytes)//Note: extended for any sizes
{
	for (int i = 0; i < bytes; ++i)
		char_to_binary(data[bytes - 1 - i]);
	printf("\n");
}

int main()
{
	struct {
		bool option1 : 1;
		unsigned long long	 : 0;
		bool option2 : 1;
		//unsigned long long option3 : 16;
	} bbf;

	//memset((char*)& bbf, 0x00, sizeof(bbf));
	//print_binary((char*)& bbf, sizeof(bbf));
	//bbf.option1 = 1;
	//bbf.option2 = 1;
	//bbf.option3 = 0xffff;
	//print_binary((char*)& bbf, sizeof(bbf));

	printf("%zu bytes\n", sizeof(bbf));

	struct {
		unsigned short option1 : 1;
		unsigned short option2 : 1;
		unsigned short : 0;
		unsigned short option3 : 1;
	} usbf;

	printf("%zu bytes\n", sizeof(usbf));

	struct {
		unsigned int option1 : 1;
		unsigned int : 0;
		unsigned int option2 : 1;
		//bool option3 : 1;
	} uibf;

	printf("%zu bytes\n", sizeof(uibf));

	//memset((char*)& uibf, 0x00, sizeof(uibf));
	//print_binary((char*)& uibf, sizeof(uibf));

	//uibf.option1 = 1;
	//uibf.option2 = 1;
	//print_binary((char*)& uibf, sizeof(uibf));

	return 0;
}
