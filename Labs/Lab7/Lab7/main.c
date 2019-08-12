#include "Seven.h"


int main(void)
{
	double total = 0, average = 0, time_c = 0, test = 0;
	double *ptr = &average;
	printf("Enter time connected: ");
	scanf("%lf", &time_c);
	charges(&total, ptr, time_c);
	printf("Payment due: %lf\tAverage Cost/Hr: %lf\n", total, average);
	round_money(total);
}