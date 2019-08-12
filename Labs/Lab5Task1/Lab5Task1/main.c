#include "salary.h"


int main(void)
{
	FILE *infile = NULL, *outfile = NULL;	
	double sum = 0.0, num = 0.0;

	infile = fopen("salary.txt", "r");
	outfile = fopen("output.txt", "w");

		while (!feof(infile))
	{
		num = read_double(infile);
		sum += num;
	}
		if (sum < 15000)
		{
			printf("Income: l\n");
		}
		else if (sum >= 15000 && sum <= 200000)
		{
			printf("Income: m\n");			
		}
		else
		{
			printf("Income: h\n");				
		}

	print_double(outfile, sum);
	fcloseall;
}
