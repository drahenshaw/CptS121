#include "data.h"

double read_double(FILE *infile) //read double from infile
{
	double number = 0.0;
	fscanf(infile, "%lf", &number); //look for long-float and store in number variable
	return number;
}