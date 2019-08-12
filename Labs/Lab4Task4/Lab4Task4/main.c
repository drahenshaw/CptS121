#include "functions.h"

int main(void)
{
	FILE* infile = NULL;
	int choice = 0;
	double number1 = 0.0, number2 = 0.0, number3 = 0.0, number4 = 0.0, number5 = 0.0;
	double avg = 0.0, minimum = 0.0, maximum = 0.0;

	infile = fopen("five.txt", "r");

	number1 = read_double(infile);
	number2 = read_double(infile);
	number3 = read_double(infile);
	number4 = read_double(infile);
	number5 = read_double(infile);
	
	printf("1. Average\n2. Maximum\n3. Minimum\n");
	scanf("%d", &choice);

	if (choice == 1)
	{
		avg = calculate_avg(number1, number2, number3, number4, number5);
		printf("Average: %.2lf\n", avg);
	}
	else if (choice == 2)
	{
		maximum = find_max(number1, number2, number3, number4, number5);
		printf("Maximum: %.2lf\n", maximum);
	}
	else if (choice == 3)
	{
		minimum = find_min(number1, number2, number3, number4, number5);
		printf("Minimum: %.2lf\n", minimum);
	}
	else
	{
		printf("Error: Invalid choice\n");
		return -1;
	}
	return 0;
}	