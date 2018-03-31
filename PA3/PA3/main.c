/*************************************************************************************************************************
/*Programmer: David Henshaw																								 *
*Class: CptS 121, Fall 2017, Leb Section 03																			     *
*Programming Assignment: PA3																							 *
*Date: September 21, 2017																								 *
*Description:  This program reads in values about students from an infile.									             *
*              Reads in ID numbers, GPA, Class Standing, and Age from five students 									 *
*			   Uses custom functions to solve for the mean of GPA and class standing									 *
*               standard deviation of GPA, and the minimum and maximum GPA 												 *
*              The results are printed to an output.dat file.											                 *
*																											             *
*              Inputs: infile, outfile (to open)         																 *
*                      id_1, id_2, id_3, id_4, id_5, gp1, gp2, gp3, gp4, gp5										     *
*                      class1, class2, class3, class4, class5, age1, age2, age3, age4, age5              			     *
*                      																					                 *
*              Constants: None																						     *
*              Computations: Sum, mean, variance, deviation, standard deviation          						         *
*              Outputs: GPA mean, class standing mean, age mean, GPA standard deviation, GPA min/max     				 *
*																													     *
*              This program provides some error checking in calculate_mean											     *
*              This program contains a custom header and a second source file for custom function definitions.			 *
*																														 *
* Relevant Formulas: 																									 *
*          (1)Mean = sum / number																					     *
*          (2)Deviation = number - mean                                              							         *
*          (3)Variance = ((deviation1)^2 + (deviation2)^2 + (deviation3)^2 + (deviation4)^2 + (deviation5)^2) / number	 *
*          (4)Stand Deviation = sqrt (variance)              															 *
**************************************************************************************************************************/

#include "records.h"

int main(void)
{
	FILE *infile = NULL, *outfile = NULL;	//FILE* type declarations for reading file and writing file
	int id_1 = 0, id_2 = 0, id_3 = 0, id_4 = 0, id_5 = 0; //id variables, only one is needed and can be overwritten but i left them separate for now
	double gp1 = 0.0, gp2 = 0.0, gp3 = 0.0, gp4 = 0.0, gp5 = 0.0;
	int class1 = 0, class2 = 0, class3 = 0, class4 = 0, class5 = 0; //class standing is represented by integers 1-4 (fr - sr)
	double age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0;

	double sum_gpa = 0.0, sum_class = 0.0, sum_age = 0.0, mean = 0.0, mean_gpa = 0.0, dev = 0.0;
	double deviation1 = 0.0, deviation2 = 0.0, deviation3 = 0.0, deviation4 = 0.0, deviation5 = 0.0;
	double variance = 0.0, stdev = 0.0, min = 0.0, max = 0.0;


	infile = fopen("input.dat", "r"); //Open file for reading
	outfile = fopen("output.dat", "w"); //Open file for writing

	id_1 = read_integer(infile); //First student data
	gp1 = read_double(infile);
	class1 = read_integer(infile);
	age1 = read_double(infile);
	
	id_2 = read_integer(infile); //Second student data
	gp2 = read_double(infile);
	class2 = read_integer(infile);
	age2 = read_double(infile);

	id_3 = read_integer(infile); //Third student data
	gp3 = read_double(infile);
	class3 = read_integer(infile);
	age3 = read_double(infile);

	id_4 = read_integer(infile); //Fourth student data
	gp4 = read_double(infile);
	class4 = read_integer(infile);
	age4 = read_double(infile);

	id_5 = read_integer(infile); //Fifth student data
	gp5 = read_double(infile);
	class5 = read_integer(infile);
	age5 = read_double(infile);

	sum_gpa = calculate_sum(gp1, gp2, gp3, gp4, gp5); //Sum of the GPA's
	sum_class = calculate_sum(class1, class2, class3, class4, class5); //Sum of the class standing values
	sum_age = calculate_sum(age1, age2, age3, age4, age5); //Sum of the student's ages

	mean_gpa = calculate_mean(sum_gpa, 5); //GPA MEAN
	print_double(outfile, mean_gpa); //Print to outfile

	mean = calculate_mean(sum_class, 5); //CLASS MEAN
	print_double(outfile, mean); //Print to outfile

	mean = calculate_mean(sum_age, 5); //AGE MEAN
	print_double(outfile, mean); //Print to outfile
	fprintf(outfile, "\n"); //Print newline escape sequence to the outfile

	deviation1 = calculate_deviation(gp1, mean_gpa); //Finds the deviation from the mean of the GPA values
	deviation2 = calculate_deviation(gp2, mean_gpa);
	deviation3 = calculate_deviation(gp3, mean_gpa);
	deviation4 = calculate_deviation(gp4, mean_gpa);
	deviation5 = calculate_deviation(gp5, mean_gpa);

	variance = calculate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, 5); //Finds the variance of the five numbers
	stdev = calculate_standard_deviation(variance); //Uses sqrt to find the standard deviation
	print_double(outfile, stdev); //Print to outfile

	min = find_min(gp1, gp2, gp3, gp4, gp5); //Finds minimum GPA
	max = find_max(gp1, gp2, gp3, gp4, gp5); //Finds maximum GPA
	print_double(outfile, min); //Prints final two results to the outfile
	print_double(outfile, max);
	
	fclose(infile); //Closes input.dat
	fclose(outfile); //Closes output.dat
	return 0;
}