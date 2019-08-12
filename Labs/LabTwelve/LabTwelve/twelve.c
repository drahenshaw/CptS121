#include "Lab12.h"


int sum_digits(int n)
{
	static int sum = 0;

	if (n == 0)
	{
		return sum;
	}
	else
	{
		sum = n % 10 + sum_digits(n / 10);
	}
	return sum;
}

void towers_of_Hanoi(int n_discs, int source_rod, int target_rod, int aux_rod)
{
	if (n_discs == 1)
	{
		printf("Move disc 1 from rod %d to rod %d\n", source_rod, target_rod);
		return;
	}
	towers_of_Hanoi(n_discs - 1, source_rod, aux_rod, target_rod);
	printf("Move disc %d from rod %d to rod %d\n", n_discs, source_rod, target_rod);
	towers_of_Hanoi(n_discs - 1, aux_rod, target_rod, source_rod);
}