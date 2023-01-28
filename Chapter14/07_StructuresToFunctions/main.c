#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define FUNDLEN 50

struct fortune {
	char	bank_name[FUNDLEN];
	double	bank_saving;
	char	fund_name[FUNDLEN];
	double	fund_invest;

	float* arr;
};

double sum(struct fortune *my_fortune);

int main()
{
	struct fortune my_fortune = {
		"Wells-Fargo",
		123.45,
		"JPMorgan Chase",
		6789.7
	};

	printf("Total : $%.2f.\n",
		//sum(&my_fortune.bank_saving, &my_fortune.fund_invest)
		sum(&my_fortune)
	);

	//struct fortune my_fortune2;
	//my_fortune2 = my_fortune;

	return 0;
}

double sum(const struct fortune *mf)	//TOOD: try pointers
{
	return mf->bank_saving + mf->fund_invest;
}