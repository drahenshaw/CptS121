#include "Lab12.h"


int sum_digits(int n)
{
	static int sum = 0;

	if (n == 0)
	{
		return sum;
	}
	else
	{
		sum = n % 10 + sum_digits(n / 10);
	}
	return sum;
}