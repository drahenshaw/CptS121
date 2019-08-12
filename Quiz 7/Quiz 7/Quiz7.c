#include <stdio.h>


void matrix(int matrix[][10], int rows, int cols);

int main()
{
	char my_str[] = { "Life is good!\n" };
	int count = 0, counter = 0;
	int test_matrix[5][10] = { 0 };
	matrix(test_matrix, 5, 10);
	
	int row, columns;

	for (int row = 0; row<5; row++)
	{
		for (int columns = 0; columns<10; columns++)
		{
			printf("%d     ", test_matrix[row][columns]);
		}
		printf("\n");
	}
	printf("%s", my_str);
}


void matrix(int matrix[][10], int rows, int cols)
{
	int i = 0, j = 0;

	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < cols; ++j)
		{
			matrix[i][j] = i + j;
		}
	}
}