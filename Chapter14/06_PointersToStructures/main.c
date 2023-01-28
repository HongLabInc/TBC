#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 20

struct names {
	char given[LEN];
	char family[LEN];
};

struct friend {
	struct names full_name;
	char mobile[LEN];
};

int main(void)
{
	struct friend my_friends[2] = {
		{ {"Ariana", "Grande"}, "1234-1234"	},
		{ {"Taylor", "Swift"}, "6550-8888" }
	};
	
	struct friend* girl_friend;

	girl_friend = &my_friends[0];

	printf("%zd\n", sizeof(struct friend));
	printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);
	// -> : indirect member access operator

	girl_friend++;
	
	printf("%lld %s\n", (long long)girl_friend, (*girl_friend).full_name.given);
	// . has higher precedence than *

	return 0;
}