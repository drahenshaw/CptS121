#include "Seven.h"

void charges(double *total, double *average, double hours)
{
	if (hours > 10)
	{
		*total = 7.99 + 1.99 * ceil(hours - 10);
		*average = *total / hours;
	}
	else
	{
		*total = 7.99;
		*average = *total / hours;
	}
}

double round_money(double cost)
{
	double rounded = 0.0, second = 0.0;
	//rounded = cost - (int)cost % 100; subtracts cost with decimal from int cost to get just the decimal leftover;
	//printf("%lf\n", rounded);
	second = floor(cost * 100) / 100;
	printf("$%.2lf\n", second);
}