#include "Lab12.h"


int main(void)
{
	//Task 2 - Summing the digits in an integer
	int test = 61492;
	int sum = 0;

	sum = sum_digits(test);
	printf("%d\n", sum);

	//Task 4 - Towers of Hanoi
	int disc_1_diamter = 1, disc_2_diamter = 2,	disc_3_diamter = 3;
	int disc_1_tower = 1, disc_2_tower = 1, disc_3_tower = 1;

	towers_of_Hanoi(3, disc_1_tower, 2, 3);

}