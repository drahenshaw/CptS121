#include "data.h"

int main(void)
{
	FILE *infile = NULL, *outfile = NULL;
	double sum = 0.0, num = 0.0, average = 0.0;
	int count = 0;

	infile = fopen("data.txt", "r");
	outfile = fopen("output.txt", "w");
	
	if (infile != NULL)
	{
		while (!feof(infile))
		{
			num = read_double(infile);
			sum += num;
			count++;
		}
	}

	average = sum / count;
	fprintf(outfile,"%.2lf\n", average);
	fcloseall;

	return 0;
}
