#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.141592f
#define AI_NAME "Friday"

int main()
{
	float radius, area, circum;

	printf("I'm %s.\n", AI_NAME);
	printf("Please, input radius\n");

	scanf("%f", &radius);

	area = PI * radius * radius; // area = pi*r*r
	circum = 2.0f * PI * radius; // circum = 2.0 * pi * r

	printf("Area is %f\n", area);
	printf("Circumference is %f\n", circum);

	//TODO: wrong usage, strings, const

	return 0;
}