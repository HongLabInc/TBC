#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fit_str(char*, unsigned int);

int main()
{
	/*
		strlen() : returns length of the string
	*/

	////TODO: use debugger
	//char msg[] = "Just,"" do it!";
	//puts(msg);
	//printf("Length %d\n", strlen(msg));
	//fit_str(msg, 4);
	//puts(msg);
	//printf("Length %d\n", strlen(msg));
	////TODO: implement fit_str() function

	/*
		strcat() and strncat() : string concatenation
	*/

	//char str1[100] = "First string";
	//char str2[] = "Second string";

	///*strcat(str1, ", ");
	//strcat(str1, str2);*/
	//strncat(str1, str2, 2);	// Append 2 characters
	//puts(str1);

	//TODO: implement my_strcat() function!

	/*
		strcmp() and strncmp() : compare strings (not characters)
	*/

	//printf("%d\n", strcmp("A", "A"));
	//printf("%d\n", strcmp("A", "B"));
	//printf("%d\n", strcmp("B", "A"));
	//printf("%d\n", strcmp("Hello", "Hello"));
	//printf("%d\n", strcmp("Banana", "Bananas"));
	//printf("%d\n", strcmp("Bananas", "Banana"));
	//printf("%d\n", strncmp("Bananas", "Banana", 6));
	////TODO: implement strcmp!

	/*
		strcpy() and strncpy()
	*/

	//char dest[100] = "";	// make sure memory is enough
	//char source[] = "Start programming!";
	////dest = source;	// Error
	////dest = "Start something";// Error
	//strcpy(dest, source);
	//strncpy(dest, source, 5);	// '\0' is NOT added
	///*strcpy(dest, source + 6);
	//strcpy(dest, source);
	//strcpy(dest + 6, "coding!");*/
	//puts(dest);


	/*
		sprintf()
	*/

	//char str[100] = "";
	//int i = 123;
	//double d = 3.14;
	//sprintf(str, "%05d.png %f", i, d);
	//puts(str);
	//// capture00000.png, capture00001.png, ...

	/*
		There are more functions...		
	*/

	printf("%s\n", strchr("Hello, World", 'W'));

	printf("%s\n", strpbrk("Hello, World", "ABCDE"));
	printf("%s\n", strpbrk("Hello, World", "abcde"));

	printf("%s\n", strrchr("Hello, World, Hello, World", 'l'));// last occurrence

	printf("%s\n", strstr("Hello, World", "wor"));
	printf("%s\n", strstr("Hello, World", "Wor"));

	return 0;
}

void fit_str(char* str, unsigned int size)
{
	if (strlen(str) > size)
		str[size] = '\0';
}