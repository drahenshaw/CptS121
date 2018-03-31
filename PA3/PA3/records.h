/**************************************************************************************************************
*Programmer: David Henshaw																					  *
*Class: CptS 121, Fall 2017, Leb Section 03																      *
*Programming Assignment: PA3																				  *
*Date: September 18, 2017																					  *
*Description: Header file for PA3 including both standard libraries and custom function declarations          *
***************************************************************************************************************/

#include <stdio.h>
#include <math.h>

//Custom function declarations

//Reading values
int read_integer(FILE *infile);
double read_double(FILE *infile);

//Calculations
double calculate_sum(double number1, double number2, double number3, double number4, double number5);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculate_standard_deviation(double variance);

//Finding Max/Min Values
double find_max(double number1, double number2, double number3, double number4, double number5);
double find_min(double number1, double number2, double number3, double number4, double number5);

//Printing Results
void print_double(FILE *outfile, double number);
