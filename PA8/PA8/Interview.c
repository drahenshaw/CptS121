/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 121, Fall 2017, Lab Section 03																										       *
*Programming Assignment: PA8 - Interview Questions																									   *
*Date: November 29, 2017																															   *
*Description: interview.c source file contains the function descriptions for 6 interview problems										               *
********************************************************************************************************************************************************/

#include "Interview.h"

//1. String N Cat
/*******************************************************************************
* Function: string_n_cat                                                       *
* Date Created: December 3 , 2017											   *
* Date Last Modified: December 6, 2017                                         *
* Description: Appends a string to n characters					               *
* Input parameters: destination and source strings                             *
* Returns: pointer to destination string		                               *
* Preconditions: valid strings with ample size, mutable						   *
* Postconditions: string is appended					                       *
********************************************************************************/
char * my_str_n_cat(char *destination, char *source)
{
	int i = 0, j = 0, n = 0;

	printf("How many characters do you want to append?: ");
	scanf("%d", &n);

	while (destination[i] != '\0') i++; //find null character
	for (j = 0; j < n && source[j] != '\0'; ++j, ++i)
	{
		destination[i] = source[j]; //start appending through given number of characters
	}
	destination[i] = '\0';
	return destination;
}

//2. Binary Search
/*******************************************************************************
* Function: binary_search                                                      *
* Date Created: October 18, 2017											   *
* Date Last Modified: December 6, 2017                                         *
* Description: Searchs through a list dividing in half each time               *
* Input parameters: list, a target value, size of list                         *
* Returns: index value of target if found, -1 if not                           *
* Preconditions: list and target value										   *
* Postconditions: target index returned					                       *
********************************************************************************/
int binary_search(int list[], int target_value, int size)
{
	int found = 0, left = 1, right = size, mid = 0;
	int target_index = 0;	

	while (!found && left <= right) //still searching or indices cross
	{
		mid = (left + right) / 2;
		if (target_value == list[mid])
		{
			found = 1;
			target_index = mid;
		}
		else if (target_value < list[mid])
		{
			right = mid - 1;
		}
		else left = mid + 1;
	}
	if (found)
	{
		printf("Target %d found at index %d\n", target_value, target_index);
		return target_index;
	}
	else return -1;
}

/*******************************************************************************
* Function: set_list_size                                                      *
* Date Created: December 3 , 2017											   *
* Date Last Modified: December 6, 2017                                         *
* Description: Gets an integer value from user					               *
* Input parameters: void						                               *
* Returns: int chosen							                               *
* Preconditions: running program											   *
* Postconditions: int returned							                       *
********************************************************************************/
int set_list_size(void)
{
	int size = 0;
	printf("Generate a list of integers from 0 to: ");
	scanf("%d", &size);
	return size;
}

/*******************************************************************************
* Function: populate_list                                                      *
* Date Created: December 3 , 2017											   *
* Date Last Modified: December 6, 2017                                         *
* Description: Populates a list with indices 1 through size		               *
* Input parameters: list, size						                           *
* Returns: void									                               *
* Preconditions: valid list and size parameters        						   *
* Postconditions: void									                       *
********************************************************************************/
void populate_list(int list[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		list[i] = i + 1;
	}
}

/*******************************************************************************
* Function: get_target                                                         *
* Date Created: December 3 , 2017											   *
* Date Last Modified: December 6, 2017                                         *
* Description: Gets an integer value from user					               *
* Input parameters: void						                               *
* Returns: int chosen							                               *
* Preconditions: running program											   *
* Postconditions: int returned							                       *
********************************************************************************/
int get_target(void)
{
	int target = 0;
	printf("Target integer: ");
	scanf("%d", &target);
	return target;
}

//3. Bubble Sort
/*******************************************************************************
* Function: bubble_sort	                                                       *
* Date Created: October 18, 2017											   *
* Date Last Modified: December 6, 2017                                         *
* Description: Sorts an array of pointers to string for alphabetical ordering  *
* Input parameters: array of pointers to strings, number of strings            *
* Returns: void									                               *
* Preconditions: valid pointers, number of strings							   *
* Postconditions: pointers reordered to alphabetical based on strings          *
********************************************************************************/
void bubble_sort(char *string[], int num_strs)
{
	int i = 0;
	int passes = 1;
	char *temp = NULL;
	
	for (; passes < num_strs; ++passes)
	{
		for (i = 0; i < num_strs - passes; ++i)
		{

			if ((strcmp(string[i], string[i + 1]) > 0)) //if the first string is larger than the second, make a swap
			{
				temp = string[i];
				string[i] = string[i + 1];
				string[i + 1] = temp;
			}
		}
	}
}

//4. Palindrome
/*******************************************************************************
* Function: is_palidrome                                                       *
* Date Created: December 3 , 2017											   *
* Date Last Modified: December 6, 2017                                         *
* Description: Recursively computes whether a string is a palindrome or not    *
* Input parameters: pointer to the string and length                           *
* Returns: int 1 if palindrome, 0 if not		                               *
* Preconditions: valid pointer and length, room on call stack				   *
* Postconditions: int returned							                       *
********************************************************************************/
int is_palindrome(char *pStr, int length)
{
	if (length <= 0) //base case
	{
		return 1;
	}
	if (pStr[0] != pStr[length - 1])
	{
		return 0;
	}
	return is_palindrome(pStr + 1, length - 2);
}

/*******************************************************************************
* Function: chomp_string                                                       *
* Date Created: December 3 , 2017											   *
* Date Last Modified: December 6, 2017                                         *
* Description: Takes a string, chomps out punctuation and spacing, lowercase   *
* Input parameters: source and destination strings                             *
* Returns: pointer to the destination string	                               *
* Preconditions: valid strings   											   *
* Postconditions: string chomped and in all lowercase	                       *
********************************************************************************/
char *chomp_string(char *dest, char *source)
{
	int i = 0, j = 0;

	for (i = 0; i < strlen(source); ++i) //iterate through the string 
	{
		source[i] = tolower((int)source[i]); //change each letter to lowercase

		if (!(isspace((int)source[i]) || ispunct((int)source[i]))) //if its NOT a space or punct symbol, copy to destination string
		{
			dest[j] = source[i];
			++j;
		}
	}
	return dest;
}

//5. Sum of Primes Recursively
/*******************************************************************************
* Function: sum_primes                                                         *
* Date Created: December 3 , 2017											   *
* Date Last Modified: December 6, 2017                                         *
* Description: Calculates the sum of n prime numbers			               *
* Input parameters: unsigned int n				                               *
* Returns: int sum of n primes					                               *
* Preconditions: is_prime function 											   *
* Postconditions: sum returned							                       *
********************************************************************************/
int sum_primes(unsigned int n)
{
	if (n > 1)
	{
		return n = is_prime(n) + sum_primes(n - 1);	//recursive call n - 1, only adds to sum if number is prime
	}	
	else return 0; //base case hit when n = 1
}

/*******************************************************************************
* Function: is_prime	                                                       *
* Date Created: December 3 , 2017											   *
* Date Last Modified: December 6, 2017                                         *
* Description: Gets an integer value from user					               *
* Input parameters: void						                               *
* Returns: int chosen							                               *
* Preconditions: running program											   *
* Postconditions: int returned							                       *
********************************************************************************/
int is_prime(int n)
{
	int i = 2; //start at 2
	int rem = n % 2; //find remainder

	for (; n != i && rem != 0; ++i) //if n is not equal to i and remainder is not equal to 0
	{
		rem = n % i; //update remainder and i
	}
	if (n != i) //if n == i, number is not prime
	{
		return 0;
	}
	else
	{
		return n; //return the number to add if prime
	}
}

//6. Maximum Occurances
/*******************************************************************************
* Function: maximum_occurences                                                 *
* Date Created: December 5 , 2017											   *
* Date Last Modified: December 6, 2017                                         *
* Description: Find the max occurences of a letter in a string	               *
* Input parameters: pointer to a string, int, and char, occurences data        *
* Returns: void									                               *
* Preconditions: valid inputs and typedef									   *
* Postconditions: occurences array updated with max occurences and frequency   *
********************************************************************************/
void maximum_occurences(char *s, Occurrences array[], int *n, char *c)
{
	int temp = 0;
	int len = strlen(s);
	int max = 0;
	int pos = 0;

	for (int i = 0; i < len; ++i) //iterate through the string
	{
		temp = s[i] - 'a'; //subtract 'a' to get the correct index
		array[temp].num_occurrences += 1; //tally the letter at the correct index
	}

	for (int i = 0; i < len; ++i) //iterate through string
	{
		temp = s[i] - 'a';
		array[temp].frequency = (double)array[temp].num_occurrences / len; //divide num of occurences by total length of letters to get frequency
	}

	for (int j = 0; j < 26; ++j) //iterate through whole array of occurences (for each letter)
	{
		if (max < array[j].num_occurrences) //search for the max
		{
			max = array[j].num_occurrences; //if new max found, update position
			pos = j;
		}
	}	
	*c = pos + 'a'; //add a to adjust for position and pass back as output parameter (to get letter instead of index)
	*n = max; //output parameter of max number of occurences

}

//7. Maximum Consecutive Integers
/*******************************************************************************
* Function: max_consecutive_integers                                           *
* Date Created: December 3 , 2017											   *
* Date Last Modified: December 6, 2017                                         *
* Description: Finds longest consecutive list of same number in 2D array       *
* Input parameters: 2D array, row & cols, start address pointer and max value  *
* Returns: void									                               *
* Preconditions: running program with valid pointers						   *
* Postconditions: Max sequence found (indirect), starting address output       *
********************************************************************************/
void max_consecutive_integers(int list[][5], int rows, int cols, int **start, int *sequence)
{
	int i = 0, j = 0;
	int max = 0;
	int count = 0;
	int *temp = NULL;
	
	for (i = 0; i < rows; ++i) //nested loop to iterate through 2D array
	{
		for (j = 0; j < cols; ++j)
		{
			if (list[i][j] != list[i][j + 1]) //if the next number is the not the same
			{
				count = 0; //reset count
			}
			else //next number is the same
			{
				count++; //add 1 to count
				if (count == 1) //if count is now 1, store the starting address
				{
					temp = &list[i][j];
				}
			}
			if (count > max) //if count is new max, update start address and max sequence values
			{
				max = count;
				*start = temp;
			}
		}
	}
	*sequence = max + 1;
	printf("Scope: Inside Function - Start Address: %d\n", *start);
	printf("Scope: Inside Function - Max Sequence: %d\n", *sequence);
}

//Other Functions

/*******************************************************************************
* Function: welcome_screen                                                     *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Prints a simple title screen						               *
* Input parameters: void					                                   *
* Returns: void									                               *
* Preconditions: running program											   *
* Postconditions: void									                       *
********************************************************************************/
void welcome_screen(void)
{
	printf("Welcome to the Interview Questions Application!\n");
	printf("Please select the problem to run.\n\n");
}

/*******************************************************************************
* Function: display_menu                                                       *
* Date Created: October 2, 2017												   *
* Date Last Modified: October 31, 2017                                         *
* Description: Displays a multi-option menu to the user			               *
* Input parameters: void					                                   *
* Returns: void									                               *
* Preconditions: running program											   *
* Postconditions: void									                       *
********************************************************************************/
void display_menu(void)
{
	printf("1. String N Copy\n");
	printf("2. Binary Search\n");
	printf("3. Bubble Sort\n");
	printf("4. Palindrome\n");
	printf("5. Sum of Primes\n");
	printf("6. Maximum Occurances\n");
	printf("7. Maximum Consecutive Integers (Bonus)\n");
	printf("8. Exit\n");
}

/*******************************************************************************
* Function: menu_input                                                         *
* Date Created: October 2, 2017												   *
* Date Last Modified: October 31, 2017                                         *
* Description: Promps user for a menu option with scanf			               *
* Input parameters: void					                                   *
* Returns: int # of option						                               *
* Preconditions: running program											   *
* Postconditions: int # of option						                       *
********************************************************************************/
int menu_input(void)
{
	int option = 0;
	scanf("%d", &option);
	return option;
}

/*******************************************************************************
* Function: menu_selection (modified Yahtzee menu)	                           *
* Date Created: October 5, 2017												   *
* Date Last Modified: October 31, 2017                                         *
* Description: Combines display_menu and menu_input to prompt and validate	   *
*				user input to pick which menu option to run, 1 - 6             *
* Input parameters: void					                                   *
* Returns: Menu option chosen					                               *
* Preconditions: running program, subfunctions compiled						   *
* Postconditions: returns option, #define constants		                       *
********************************************************************************/
int menu_selection(void)
{
	int option = 0;
	do //Repeats when input is not in the integer range of 1 - 2
	{
		display_menu();
		option = menu_input();
		system("cls");
		if (option < MENU_MIN || option > MENU_MAX)
		{
			printf("Invalid option. Please try again.\n\n");
		}
	} while (option < MENU_MIN || option > MENU_MAX);

	return option;
}