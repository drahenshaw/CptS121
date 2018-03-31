/*************************************************************************************************************************
/*Programmer: David Henshaw																								 *
*Class: CptS 121, Fall 2017, Lab Section 03																			     *
*Programming Assignment: PA8 - Interview Questions																		 *
*Date: November 29, 2017																								 *
*Description:  This program contains a series of six interview questions.												 *
*																														 *
*              																											 *
*              Inputs: Menu Options, Keyboard input																		 *
*              Constants: See Header File																			     *
*              Computations: Pointer arithmetic																		     *
*              Outputs: Printouts of each problem to the screen.												    	 *
*																													     *
*              This program provides some error checking for input validation.										     *
*              This program contains a custom header and a second source file for custom function definitions.			 *
*																														 *
**************************************************************************************************************************/

#include "Interview.h"

int main(void)
{
	int menu = 0;
	char src[MAX_STRING], dest[MAX_STRING];
	int list[MAX_LIST];
	int pos = 0;
	int tar = 0;
	int size = 0;

	char given_string[MAX_STRING] = { '\0' };
	char chomped_string[MAX_STRING] = { '\0' };
	int result = 0;

	char *strp[10] = { "dog", "cat", "apple", "banana", "elephant" };
	int test = 0;
	int prime = 0;	

	Occurrences array_occur[ALPHABET] = { {0, 0} };
	char string[100] = { "daviiidisaprogrammer" };
	int number = 0;
	char character = '\0';

	int _2D[4][5] = { { -5, 6, 0, 2, 2 },{ 2, 2, 2, 9, 3 },{ 3, 3, 2, 1, -8 },{ 7, -2, 0, 6, 4 } };
	int row = 4, col = 5;
	int **start_p = NULL; //pointer to an integer of starting address
	int *seq = NULL;
	
	do
	{
		welcome_screen();
		menu = menu_selection();

		switch (menu)
		{
		case STRING:
			getchar(); //Chomps new line off menu input
			printf("Enter destination string: "); //Asks for custom string
			gets(dest);
			printf("Enter source string: "); //Asks for custom source string
			gets(src);
			my_str_n_cat(dest, src); //String N Cat
			printf("%s\n", dest); //Prints appended string
			break;

		case BINARY:
			size = set_list_size(); //Get size of list
			populate_list(list, size); //Populate an ordered integer list
			tar = get_target(); //Ask user for target number
			pos = binary_search(list, tar, size); //Returns position of target if found, -1 if not
			if (pos == -1) printf("Target not found\n");
			break;

		case BUBBLE:

			bubble_sort(strp, 5); //Sorts a list pre declared out of order above
			for (int i = 0; i < 5; ++i)
			{
				printf("%s\n", strp[i]);
			}
			break;

		case PALINDROME:
			getchar();
			printf("Enter a string to determine if its a palindrome: ");
			gets(given_string);
			chomp_string(chomped_string, given_string); //removes punctuation and spacing
			printf("%s\n", chomped_string);
			result = is_palindrome(chomped_string, strlen(chomped_string)); //recursively calls here
			printf("%d\n", result);
			break;

		case PRIMES:
			printf("Enter number of terms: ");
			scanf("%d", &prime);
			result = sum_primes(prime); //recursively calls here
			printf("Sum of primes from 2 to %d = %d\n", prime, result);
			break;

		case MAX__OCCUR:
			maximum_occurences(string, array_occur, &number, &character); //string declared above
			for (int j = 0; j < 26; ++j)
			{
				printf(" %c: %d, freq: %lf\n", 'a' + j, array_occur[j].num_occurrences, array_occur[j].frequency);
			}
			printf("Letter %c occurs %d times.\n", character, number);
			break;

		case BONUS:
			max_consecutive_integers(_2D, row, col, &start_p, &seq); //Outside and inside pointers should match, array given by problem statment declared above
			printf("Scope: Main - Function Max Sequence: %d\n", seq);
			printf("Scope: Main -Start address: %d\n", start_p);
			break;

		default:;
		}
	} while (menu != MENU_MAX);
	
	return 0;
}


