#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MONTHS 12
#define YEARS 3

int main()
{
	double year2016[MONTHS] = { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 };
	double year2017[MONTHS] = { -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
	double year2018[MONTHS] = { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };

	/*
	1. Use 2D array
	2. Print data
	3. Calculate and print yearly average temperatures of 3 years
	4. Calculate and print monthly average temperatures for 3 years
	*/




	double temp_data[YEARS][MONTHS] = {
		{ -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 },
		{ -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 },
		{ -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 }
	};

	/* Step 2 */
	printf("[Temperature Data]\n");

	printf("Year index : ");
	for (int m = 0; m < MONTHS; ++m)
	{
		printf("\t%d ", m + 1);
	}
	printf("\n");

	for (int y = 0; y < YEARS; ++y) 
	{
		printf("Year %d     : ", y);
		for (int m = 0; m < MONTHS; ++m)
		{
			printf("\t%.1f ", temp_data[y][m]);
		}
		printf("\n");
	}
	printf("\n");

	/* Step 3 */
	printf("[Yearly average temperatures of 3 years]\n");
	for (int y = 0; y < YEARS; ++y) 
	{
		double avg_temp = 0.0;

		for (int m = 0; m < MONTHS; ++m)
			avg_temp += temp_data[y][m];

		avg_temp /= (double)MONTHS;

		printf("Year %d : average temperature = %.1f\n", y, avg_temp);
	}
	printf("\n");

	/* Step 4 */
	printf("[Monthly average temperatures for 3 years]\n");
	printf("Year index : ");
	for (int m = 0; m < MONTHS; ++m)
	{
		printf("\t%d ", m + 1);
	}
	printf("\n");
	
	printf("Avg temps  : ");
	for (int m = 0; m < MONTHS; ++m)
	{
		double avg_temp = 0;
		for (int y = 0; y < YEARS; ++y)
		{
			avg_temp += temp_data[y][m];
		}
		avg_temp /= (double)YEARS;
		printf("\t%.1f ", avg_temp);
	}
	printf("\n");

	return 0;
}