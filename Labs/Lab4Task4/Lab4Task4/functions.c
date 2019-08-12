#include "functions.h"

double calculate_avg(double num1, double num2, double num3, double num4, double num5)
{
	double average = 0.0;
	average = (num1 + num2 + num3 + num4 + num5) / 5;
	return average;
}

double find_min(double num1, double num2, double num3, double num4, double num5)
{
	double min = num1;
	
	if (num2 < min)
	{
		min = num2;
	}
	if (num3 < min)
	{
		min = num3;
	}
	if (num4 < min)
	{
		min = num4;
	}
	if (num5 < min)
	{
		min = num5;
	}
	return min;
}



double find_max(double num1, double num2, double num3, double num4, double num5)
{
	double max = num1;

	if (num2 > max)
	{
		max = num2;
	}
	if (num3 > max)
	{
		max = num3;
	}
	if (num4 > max)
	{
		max = num4;
	}
	if (num5 > max)
	{
		max = num5;
	}
	return max;
}

double read_double(FILE* infile)
{
	double number = 0.0;
	fscanf(infile, "%lf", &number);
	return number;
}

