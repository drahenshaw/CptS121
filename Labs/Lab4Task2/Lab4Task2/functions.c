#include "BMR.h"

double read_double(FILE* infile)
{
	double dbl = 0.0;
	fscanf(infile, "%lf", &dbl);
	return dbl;
}

int read_int(FILE* infile)
{
	int integer = 0.0;
	fscanf(infile, "%d", &integer);
	return integer;
}
double convert_height(double height)
{
	double height_in = 0.0;
	height_in = 12 * height;
	return height_in;
}

double w_bmr(double weight, double height, double age)
{
	double wbmr = 0.0;
	wbmr = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
	return wbmr;
}

double m_bmr(double weight, double height, double age)
{
	double mbmr = 0.0;
	mbmr = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);
	return mbmr;
}

double determine_gender_bmi(int gender, double weight, double height, double age)
{
	double bmr = 0.0;

	if (gender == 1)
	{
		bmr = m_bmr(weight, height, age);
		return bmr;
	}
	else if (gender == 0)
	{
		bmr = w_bmr(weight, height, age);
		return bmr;
	}
	else
	{
		printf("Invalid entry\n");
		return -1;
	}
}

double activity_factor(int activity, double bmr)
{
	double cal = bmr;

	if (activity == 1)
	{
		cal = bmr * 1.2;
		return cal;
	}
	else if (activity == 2)
	{
		cal = bmr * 1.375;
		return cal;
	}
	else if (activity == 3)
	{
		cal = bmr * 1.55;
		return cal;
	}
	else if (activity == 4)
	{
		cal = bmr * 1.725;
		return cal;
	}
	else if (activity == 5)
	{
		cal = bmr * 1.9;
		return cal;
	}
	else
	{
		printf("Unknown activity level\n");
		return -1;
	}
}
