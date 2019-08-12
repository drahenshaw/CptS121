#include "salary.h"


double read_double(FILE* infile)
{
	double number = 0.0;
	fscanf(infile, "%lf", &number);
	return number;
}

void print_double(FILE *outfile, double number)
{
	fprintf(outfile, "%.2lf", number);
}