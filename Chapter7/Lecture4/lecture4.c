#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// assessment standard tax base
#define BASE1  12000000.0
#define BASE2  46000000.0
#define BASE3  88000000.0
#define BASE4 150000000.0
#define BASE5 300000000.0
#define BASE6 500000000.0

#define RATE1 (6.0 / 100.0)		// percent to rate
#define RATE2 (15.0 / 100.0)
#define RATE3 (24.0 / 100.0)
#define RATE4 (35.0 / 100.0)
#define RATE5 (38.0 / 100.0)
#define RATE6 (40.0 / 100.0)
#define RATE7 (42.0 / 100.0)

#define BASIC_DEDUCTION 1500000.0

int main()
{
	double income = 0.0;	  // annual income
	double tax = 0.0;

	scanf("%lf", &income);
	
	income -= BASIC_DEDUCTION;

	if (income <= BASE1)
	{
		tax = income * RATE1;
	}
	else if (income <= BASE2)
	{
		tax = BASE1 * RATE1 + (income - BASE1) * RATE2;
	}

	printf("Tax is = %f\n", tax);
	printf("Your income after tax deduction = %f", income - tax);

	return 0;
	


	
	//else if (income <= BASE3)
	//{
	//	tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (income - BASE2) * RATE3;
	//}
	//else if (income <= BASE4)
	//{
	//	tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3 + (income - BASE3) * RATE4;
	//}
	//else if (income <= BASE5)
	//{
	//	tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3 + (BASE4 - BASE3) * RATE4
	//		+ (income - BASE4) * RATE5;
	//}
	//else if (income <= BASE6)
	//{
	//	tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3 + (BASE4 - BASE3) * RATE4
	//		+ (BASE5 - BASE4) * RATE5 + (income - BASE5) * RATE6;
	//}
	//else //if(income > BASE6)
	//{
	//	tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3 + (BASE4 - BASE3) * RATE4
	//		+ (BASE5 - BASE4) * RATE5 + (BASE6 - BASE5) * RATE6 + (income - BASE6) * RATE7;
	//}

	// https://www.nts.go.kr/support/support_01.asp?cinfo_key=MINF5520100726112800
	// http://incomtax.fpvhxm.com/jincomtax.html
}