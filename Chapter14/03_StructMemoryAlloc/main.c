#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* 
		Well aligned structure
	*/

	struct Aligned
	{
		int a;
		float b;	
		double c;
	};

	/*
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|
	|int a  |float b|double c             |
	4 + 4 + 8 = 16
	*/

	struct Aligned a1, a2;

	printf("struct Aligned a1\n");
	printf("Sizeof %zd\n", sizeof(struct Aligned));
	printf("%lld\n", (long long)& a1);
	printf("%lld\n", (long long)& a1.a);
	printf("%lld\n", (long long)& a1.b);
	printf("%lld\n", (long long)& a1.c);

	printf("\nstruct Aligned a2\n");
	printf("Sizeof %zd\n", sizeof(a2));
	printf("%lld\n", (long long)& a2);
	printf("%lld\n", (long long)& a2.a);
	printf("%lld\n", (long long)& a2.b);
	printf("%lld\n", (long long)& a2.c);

	/*
		padding (struct member alignment)
		- 1 word: 4 bytes in x86, 8 bytes in x64
	*/

	struct Padded1
	{
		char a;
		float b;
		double c;
	};

	/* Without padding
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
	|a|float b|double c          | ?  ?  ?
	1 + 4 + 8 = 13
	*/

	/* With padding
	 0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
	|char a |float b|double c             |
	4(char?) + 4 + 8 = 16
	*/

	struct Padded1 p1;

	printf("\nstruct Padded1 p1\n");
	printf("Sizeof %zd\n", sizeof(p1));// 4 + 4 + 8
	printf("%lld\n", (long long)& p1);
	printf("%lld\n", (long long)& p1.a);
	printf("%lld\n", (long long)& p1.b);
	printf("%lld\n", (long long)& p1.c);

	struct Padded2
	{
		float a;
		double b;
		char c;
	};

	/*
	|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
	|float a        | double b            | char c                |
	8(float?) + 8 + 8(char?) = 24
	*/

	struct Padded2 p2;

	printf("\nstruct Padded p2\n");
	printf("Sizeof %zd\n", sizeof(p2));
	printf("%lld\n", (long long)& p2);
	printf("%lld\n", (long long)& p2.a);
	printf("%lld\n", (long long)& p2.b);
	printf("%lld\n", (long long)& p2.c);

	struct Padded3
	{
		char a;
		double b;
		double c;
	};

	/*
	|0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16 17 18 19 20 21 22 23|24
	| char a        | double b            | double c              |
	8(char?) + 8 + 8 = 24
	*/

	struct Padded3 p3;

	printf("\nstruct Padded2 p3\n");
	printf("Sizeof %zd\n", sizeof(p3));
	printf("%lld\n", (long long)& p3);
	printf("%lld\n", (long long)& p3.a);
	printf("%lld\n", (long long)& p3.b);
	printf("%lld\n", (long long)& p3.c);

	struct Person
	{
		char name[41];	// member
		int age;		// member
		float height;	// member
	};

	struct Person mommy;

	printf("\nstruct Person\n");
	printf("%lld\n", (long long)& mommy.name[0]);
	printf("%lld\n", (long long)& mommy.age);
	printf("%lld\n", (long long)& mommy.height);
	printf("Sizeof %zd\n", sizeof(mommy));// 41 + 4 + 4 = 49 ?

	struct Person f[4];

	printf("Sizeof a structure array %zd\n", sizeof(f));
/*
|f[0].name        | f[0].age | f[0].height | ... ... |f[3].name        | f[3].age | f[3].height |
*/

	return 0;
}