/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 121, Fall 2017, Leb Section 03																										       *
*Programming Assignment: PA3																												           *
*Date: September 18, 2017																															   *
*Description: records.c source file contains the function descriptions for FILE input, output, and calculations							               *
Each function description begins with local variable declaration, the calculation for each equation, and then returns the value back to main.c	       *
********************************************************************************************************************************************************/

#include "records.h"


/*******************************************************************************
* Function: read_integer                                                       *
* Date Created: Sept 18, 2017												   *
* Date Last Modified: Sept 21, 2017                                            *
* Description: Reads an integer from an input file                             *
* Input parameters: FILE *infile                                               *
* Returns: integer (read-in)                                                   *
* Preconditions: The infile must already be open                               *
* Postconditions: Returns the integer from infile to main                      *
********************************************************************************/
int read_integer(FILE *infile) //read int from infile
{	
	int integer = 0;
	fscanf(infile, "%d", &integer); //look for integer and store in integer variable
	return integer;
}

/*******************************************************************************
* Function: read_double                                                        *
* Date Created: Sept 18, 2017												   *
* Date Last Modified: Sept 21, 2017                                            *
* Description: Reads a double from an input file                               *
* Input parameters: FILE *infile                                               *
* Returns: number (read-in)                                                    *
* Preconditions: The infile must already be open                               *
* Postconditions: Returns the double from infile to main                       *
********************************************************************************/
double read_double(FILE *infile) //read double from infile
{
	double number = 0.0;
	fscanf(infile, "%lf", &number); //look for long-float and store in number variable
	return number;
}

/*******************************************************************************
* Function: calculate_sum                                                      *
* Date Created: Sept 18, 2017												   *
* Date Last Modified: Sept 21, 2017                                            *
* Description: Sums 5 double values                                            *
* Input parameters: Five input real numbers                                    *
* Returns: Sum of the five numbers                                             *
* Preconditions: Valid inputs                                                  *
* Postconditions: Returns the sum                                              *
********************************************************************************/
double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
	double sum = 0;
	sum = number1 + number2 + number3 + number4 + number5; //summation of 5 double numbers
	return sum;
}

/*******************************************************************************
* Function: calculate_mean                                                     *
* Date Created: Sept 18, 2017												   *
* Date Last Modified: Sept 21, 2017                                            *
* Description: Calculates the average from any sum, protected from div by 0    *
* Input parameters: Sum and a number (count) to average by                     *
* Returns: mean (average)                                                      *
* Preconditions: The sum must already be calculated, count cannot be 0         *
* Postconditions: Returns the mean                                             *
********************************************************************************/
double calculate_mean(double sum, int number)
{
	double mean = 0.0;
	
	if (number == 0) //if divide by 0, return error -1 to avoid program crash
	{	
		return -1;
	}
	else
	{
		mean = sum / number; //otherswise, divide sum by the count to return a mean value
		return mean;
	}
	
}

/*******************************************************************************
* Function: calculate_deviation                                                *
* Date Created: Sept 18, 2017												   *
* Date Last Modified: Sept 21, 2017                                            *
* Description: Calculates the deviation between two numbers                    *
* Input parameters: Number and mean (another number)                           *
* Returns: deviation between the two numbers                                   *
* Preconditions: Valid entry of two real numbers                               *
* Postconditions: Returns the deviation                                        *
********************************************************************************/
double calculate_deviation(double number, double mean)
{
	double deviation = 0.0;
	deviation = number - mean; //find the difference between the actual value and the mean value
	return deviation;
}

/*******************************************************************************
* Function: calculate_variance                                                 *
* Date Created: Sept 18, 2017												   *
* Date Last Modified: Sept 21, 2017                                            *
* Description: Calculates variance of five deviations                          *
* Input parameters: 5 deviation inputs                                         *
* Returns: variance                                                            *
* Preconditions: Valid deviations already calculated, divisor must not be 0    *
* Postconditions: Returns the variance of five numbers                         *
* Future updates: Add in calculate_mean functionality                          *
********************************************************************************/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
	double variance = 0.0;
	variance = (pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) + pow(deviation5, 2)) / (number); //eqaution for variance of five deviation values
	return variance;
}

/*******************************************************************************
* Function: calculate_standard_deviation                                       *
* Date Created: Sept 18, 2017												   *
* Date Last Modified: Sept 21, 2017                                            *
* Description: Calculates standard deviation from a variance value             *
* Input parameters: variance                                                   *
* Returns: standard deviation                                                  *
* Preconditions: Math.h library must be included for sqrt, valid variance      *
* Postconditions: Returns standard deviation                                   *
********************************************************************************/
double calculate_standard_deviation(double variance)
{
	double stdev = 0.0;
	stdev = sqrt(variance); //math.h sqrt to find the standard deviation
	return stdev;
}

/*******************************************************************************
* Function: find_max                                                           *
* Date Created: Sept 18, 2017												   *
* Date Last Modified: Sept 21, 2017                                            *
* Description: Find the maximum value from 5 double numbers                    *
* Input parameters: 5 double numbers                                           *
* Returns: maximum value                                                       *
* Preconditions: valid entries, must have 5 inputs                             *
* Postconditions: Returns the maximum value                                    *
********************************************************************************/
double find_max(double number1, double number2, double number3, double number4, double number5)
{
	double max = number1; //initializes one of the values as the max
	
	if (number2 > max)	//checks each number to see if it is greater than the max
	{
		max = number2;	//if it is, that number is set to the new max
	}
	if (number3 > max)
	{
		max = number3;
	}
	if (number4 > max)
	{
		max = number4;
	}
	if (number5 > max)
	{
		max = number5;
	}
	return max;
}

/*******************************************************************************
* Function: find_min                                                           *
* Date Created: Sept 18, 2017												   *
* Date Last Modified: Sept 21, 2017                                            *
* Description: Find the minimum value from 5 double numbers                    *
* Input parameters: 5 double numbers                                           *
* Returns: manimum value                                                       *
* Preconditions: valid entries, must have 5 inputs                             *
* Postconditions: Returns the minimum value                                    *
********************************************************************************/
double find_min(double number1, double number2, double number3, double number4, double number5)
{
	double min = number1; //initializes one of the values as the min

	if (number2 < min) //checks each number to see if it is less than the min
	{
		min = number2; //if it is, that number is set to the new min
	}
	if (number3 < min)
	{
		min = number3;
	}
	if (number4 < min)
	{
		min = number4;
	}
	if (number5 < min)
	{
		min = number5;
	}
	return min;

}

/********************************************************************************
* Function: print_double                                                        *
* Date Created: Sept 18, 2017												    *
* Date Last Modified: Sept 21, 2017                                             *
* Description: Prints a double precision value to an outfile (hundreths place)  *
* Input parameters: Specified outfile and value to print                        *
* Returns: Nothing (void)                                                       *
* Preconditions: Outfile must already be open, writing privileges, valid double *
* Postconditions: Returns the maximum value                                     *
*********************************************************************************/
void print_double(FILE *outfile, double number) //prints a double number to the specified outfile
{
	fprintf(outfile, "%.2lf\n", number); //contains destination, formating, and the value desired to print
}