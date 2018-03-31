/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 121, Fall 2017, Lab Section 03																										       *
*Programming Assignment: PA5 - Yahtzee																												   *
*Date: October 20, 2017																																   *
*Description: Yahtzee.c source file contains the function descriptions for dice game Yahtzee											               *
********************************************************************************************************************************************************/

#include "Yahtzee.h"

/*******************************************************************************
* Function: Yahtzee_rules                                                      *
* Date Created: October 6, 2017												   *
* Date Last Modified: October 6, 2017                                          *
* Description: Prints the rules of Yahtzee						               *
* Input parameters: void					                                   *
* Returns: void									                               *
* Preconditions: running program											   *
* Postconditions: void									                       *
********************************************************************************/
void Yahtzee_rules(void)
{
	printf("* * * * * * * * * * * * THE RULES OF YAHTZEE * * * * * * * * * * * *\n");
	printf("The Yahtzee scorecard is composed of two sections: an upper section and a lower section.\n");
	printf("A total of 13 scoring combinations are available.\n");
	printf("The upper section cosists of boxes scored by summing the value of dice matching the faces of the box.\n");
	printf("If the player rolls four 3's, then the socre placed in the 3's box is the sum of the dice: 12.\n");
	printf("Once a score combination box has been chosen, it may not be changed and is no longer available for future rounds.\n");
	printf("If the scores from the upper section total 63+, then 35 bonus points are awarded to the player's total score.\n");
	printf("The lower section contains a number of poker like combinations.\n");
	printf("\nThe following are the combinations:\n");
	printf("1.  Sum of 1's\t 7. Three-of-a-kind\n");
	printf("2.  Sum of 1's\t 8. Four-of-a-kind\n");
	printf("3.  Sum of 1's\t 9. Full House: 25 points\n");
	printf("4.  Sum of 1's\t 10. Small Straight: 30 points\n");
	printf("5.  Sum of 1's\t 11. Large Straight: 40 points\n");
	printf("6.  Sum of 1's\t 12. Yahtzee: 50 points\n");
	printf("13. Chance: Sum of all face values\n\n");
}

/*******************************************************************************
* Function: display_menu                                                       *
* Date Created: October 2, 2017												   *
* Date Last Modified: October 6, 2017                                          *
* Description: Displays a three option menu to the user			               *
* Input parameters: void					                                   *
* Returns: void									                               *
* Preconditions: running program											   *
* Postconditions: void									                       *
********************************************************************************/
void display_menu(void)
{
	printf("1. Display Yahtzee Rules\n");
	printf("2. Play Yahtzee\n");
	printf("3. Exit\n");
}

/*******************************************************************************
* Function: menu_input                                                         *
* Date Created: October 2, 2017												   *
* Date Last Modified: October 6, 2017                                          *
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
* Function: Yahtzee_menu                                                       *
* Date Created: October 5, 2017												   *
* Date Last Modified: October 11, 2017                                         *
* Description: Combines display_menu and menu_input to prompt and validate	   *
*				user input to pick which menu option to run, 1 - 3             *
* Input parameters: void					                                   *
* Returns: Menu option chosen					                               *
* Preconditions: running program, subfunctions compiled						   *
* Postconditions: void									                       *
********************************************************************************/
int Yahtzee_menu(void)
{
	int option = 0;
	do //Repeats when input is not in the integer range of 1 - 3
	{
		display_menu();
		option = menu_input();
		system("cls");
	} while (option < 1 || option > 3);
	return option;
}

/*******************************************************************************
* Function: initialize_rand                                                    *
* Date Created: October 2, 2017												   *
* Date Last Modified: October 6, 2017                                          *
* Description: Seeds srand with time NULL							           *
* Input parameters: void					                                   *
* Returns: void									                               *
* Preconditions: program started											   *
* Postconditions: void									                       *
********************************************************************************/
void initialize_rand(void)
{
	srand(time(NULL));
}

/*******************************************************************************
* Function: press_enter	                                                       *
* Date Created: October 9, 2017												   *
* Date Last Modified: October 9, 2017                                          *
* Description: Press any key to continue fuunction using getch		           *
* Input parameters: void					                                   *
* Returns: void									                               *
* Preconditions: program started											   *
* Postconditions: void, screen cleared					                       *
********************************************************************************/
void press_enter(void)
{
	printf("Press any key to Continue\n");
	getch();
	system("cls");
}

/*******************************************************************************
* Function: Yahtzee_dice_roll                                                  *
* Date Created: October 9, 2017												   *
* Date Last Modified: October 9, 2017                                          *
* Description: The inital roll of five dice, printing the results	           *
* Input parameters: dice array, size of the dice array                         *
* Returns: void									                               *
* Preconditions: array created of size[i] created							   *
* Postconditions: dice array populated with random values 1-6, printed         *
********************************************************************************/
void Yahtzee_dice_roll(int dice[], int size)
{
	int index = 0;

	for (index = 0; index < size; ++index)
	{
		dice[index] = rand() % 6 + 1;
		printf("%d\t", dice[index]);
	}
	putchar('\n');
	putchar('\n');
}

/*******************************************************************************
* Function: initialize_scorecombos                                             *
* Date Created: October 9, 2017												   *
* Date Last Modified: October 9, 2017                                          *
* Description: Initialized scoreboard to all values of -1			           *
* Input parameters: scoreboard array, size                                     *
* Returns: void									                               *
* Preconditions: input array initialized									   *
* Postconditions: scoreboard array now holds values of -1                      *
********************************************************************************/
void initialize_scorecombos(int array[], int size)
{
	int index = 0;

	for (index = 0; index < size; ++index)
	{
		array[index] = -1;
	}
}

/*******************************************************************************
* Function: print_combinations	                                               *
* Date Created: October 9, 2017												   *
* Date Last Modified: October 9, 2017                                          *
* Description: Prints the availalbe Yahtzee score combinations		           *
* Input parameters: void					                                   *
* Returns: void									                               *
* Preconditions: program started											   *
* Postconditions: menu printed to screen				                       *
********************************************************************************/
void print_combinations(void)
{
	printf("\nChoose a following combination:\n");
	printf("1.  Sum of 1's\t 7. Three-of-a-kind\n");
	printf("2.  Sum of 2's\t 8. Four-of-a-kind\n");
	printf("3.  Sum of 3's\t 9. Full House: 25 points\n");
	printf("4.  Sum of 4's\t 10. Small Straight: 30 points\n");
	printf("5.  Sum of 5's\t 11. Large Straight: 40 points\n");
	printf("6.  Sum of 6's\t 12. Yahtzee: 50 points\n");
	printf("13. Chance: Sum of all face values\n\n");
}

/*******************************************************************************
* Function: choose_combination                                                 *
* Date Created: October 9, 2017												   *
* Date Last Modified: October 9, 2017                                          *
* Description: Press any key to continue fuunction using getch		           *
* Input parameters: void					                                   *
* Returns: choice, the option chosen by the user                               *
* Preconditions: program started											   *
* Postconditions: returns user choice integer			                       *
********************************************************************************/
int choose_combination(void)
{
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

/*******************************************************************************
* Function: get_combination                                                    *
* Date Created: October 9, 2017												   *
* Date Last Modified: October 9, 2017                                          *
* Description: Prints combination menu and obtains user's selection            *
* Input parameters: void					                                   *
* Returns: user's choice, input validated to be within range 1-13              *
* Preconditions: program started											   *
* Postconditions: returns user choice					                       *
********************************************************************************/
int get_combination(void)
{
	int combination = 0;
	do
	{
		print_combinations();
		combination = choose_combination();
	} while (combination > 13 || combination < 1); //Input validation for 1-13 only
	return combination;
}

/*******************************************************************************
* Function: reroll_dice	- NOT USED, NEW VERSION DICE_REROLL                    *
* Date Created: October 10, 2017											   *
* Date Last Modified: October 10, 2017                                         *
* Description: used to reroll all 5 dice							           *
* Input parameters: dice array, size		                                   *
* Returns: setup to potentially return count, output passed through array      *
* Preconditions: arrays initalized											   *
* Postconditions: array repopulated with new dice values	                   *
********************************************************************************/
int reroll_dice(int array[], int size)
{
	int count = 1;
	Yahtzee_dice_roll(array, size);
	count++;
}

/*******************************************************************************
* Function: check_for_reroll                                                   *
* Date Created: October 10, 2017											   *
* Date Last Modified: October 10, 2017                                         *
* Description: Asks user Y/N ro reroll dice, input validation added	           *
* Input parameters: void					                                   *
* Returns: int 1 for yes, 0 for no, -1 for invalid input                       *
* Preconditions: program started											   *
* Postconditions: returns validated answer to rerolling the dice               *
********************************************************************************/
int check_for_reroll(void)
{
	char yesorno = '/0';
	int reroll = -1;
	do
	{
		printf("Do you want to reroll the dice?\n");
		scanf(" %c", &yesorno);
		putchar('\n');
		switch (yesorno)
		{
		case 'y':
		case 'Y': reroll = 1; //Sets reroll to 1 if yes
			break;
		case 'n':
		case 'N': reroll = 0; //Sets reroll to 0 if no
			break;
		default: printf("Invalid entry. Please enter Y or N\n"); reroll = -1;
		}
	} while (reroll == -1);
	return reroll;
}

/*******************************************************************************
* Function: execute_reroll	- NOT USED, NEW VERSION DICE_REROLL                *
* Date Created: October 11, 2017											   *
* Date Last Modified: October 11, 2017                                         *
* Description: Executes the actual rerolling of the 5 dice			           *
* Input parameters: reroll, dice array, size, and pointer to count # rerolls   *
* Returns: int 1 for reroll, 0 for no reroll, used to prevent > 3 rerolls      *
* Preconditions: valid inputs, including a return from reroll variable		   *
* Postconditions: repopulated dice array, increments count by 1, returns 1/0   *
********************************************************************************/
int execute_reroll(int reroll, int array[], int size, int *count)
{
	if (reroll == 1)
	{
		reroll_dice(array, size); //Rerolls all 5 dice
		*count = *count + 1; //Increments count
		return 1;
	}
	else
		return 0;
}

/*******************************************************************************
* Function: dice_reroll	                                                       *
* Date Created: October 19, 2017											   *
* Date Last Modified: October 19, 2017                                         *
* Description: Iterates execute reroll to allow for individual dice rerolls    *
* Input parameters: reroll, dice array, size, pointer to count # rerolls       *
* Returns: int 1 for success, 0 if user denies reroll                          *
* Preconditions: valid inputs												   *
* Postconditions: individually updated dice array, increments count            *
********************************************************************************/
int dice_reroll(int reroll, int dice[], int size, int *count)
{
	int i = 0, keep = 0, temp = 0;
	int dice_keep[5] = { 0 };

	if (reroll == 1)
	{
		do
		{
			printf("How many dice do you want to keep?: ");
			scanf("%d", &keep);
		} while (keep < 0 || keep > 5); //Input validation that negatives of >5 values of dice are entered, which would break the dice array

		printf("Which dice do you want to keep (#1 - 5)?: "); //Enter the number of the dice you want to keep
		for (i = 0; i < keep; ++i) //Loops for the number user wants to keep, and scans for which slot you want to keep
		{
			scanf("%d", &temp);
			dice_keep[temp - 1] = temp; //Populates dice_keep array with a number != 0
		}
		for (i = 0; i < FIVEDICE; ++i) //Runs through dice_keep array and if the number is 0, user did not want to keep it
		{
			if (dice_keep[i] == 0)
			{
				dice[i] = rand() % 6 + 1; //Assigns new value to the dice that were rejected
					
			}
		}
		putchar('\n');
		for (i = 0; i < FIVEDICE; ++i) //Reprints the dice array
		{
			printf("%d\t", dice[i]);
		}
		putchar('\n');
		*count = *count + 1; //Increments count
		return 1;		//Returns 1 for validation loop
	}
	else return 0;
}

/*******************************************************************************
* Function: sumofones	                                                       *
* Date Created: October 14, 2017											   *
* Date Last Modified: October 14, 2017                                         *
* Description: Sums of the number of ones and returns the points	           *
* Input parameters: dice array, dice counter array                             *
* Returns: number of points awarded				                               *
* Preconditions: valid inputs												   *
* Postconditions: points returned						                       *
********************************************************************************/
int sumofones(int array[], int counter[])
{
	int i = 0, points = 0;
	
	for (i = 0; i < FIVEDICE; ++i) //Loops through dice
	{
		if (array[i] == 1)
		{
			counter[SUMOFONES]++;	//If dice = 1, add a tally to the counter	
		}		
	}
	points = counter[SUMOFONES]; //Points = 1 * tally
	return points;
}

/*******************************************************************************
* Function: sumoftwos	                                                       *
* Date Created: October 14, 2017											   *
* Date Last Modified: October 14, 2017                                         *
* Description: Sums of the number of twos and returns the points	           *
* Input parameters: dice array, dice counter array                             *
* Returns: number of points awarded				                               *
* Preconditions: valid inputs												   *
* Postconditions: points returned						                       *
********************************************************************************/
int sumoftwos(int array[], int counter[])
{
	int i = 0, points = 0;
	
	for (i = 0; i < FIVEDICE; ++i)
	{
		if (array[i] == SUMOFTWOS)
		{
			counter[SUMOFTWOS]++; //Counts 2's
		}
	}
	points = 2 * counter[SUMOFTWOS]; //Points = 2 * tally
	return points;
}

/*******************************************************************************
* Function: sumofthrees	                                                       *
* Date Created: October 14, 2017											   *
* Date Last Modified: October 14, 2017                                         *
* Description: Sums of the number of threes and returns the points	           *
* Input parameters: dice array, dice counter array                             *
* Returns: number of points awarded				                               *
* Preconditions: valid inputs												   *
* Postconditions: points returned						                       *
********************************************************************************/
int sumofthrees(int array[], int counter[])
{
	int i = 0, points = 0;
	
	for (i = 0; i < FIVEDICE; ++i)
	{
		if (array[i] == SUMOFTHREES)
		{
			counter[SUMOFTHREES]++; //Counts threes
		}
	}
	points = 3 * counter[SUMOFTHREES]; //Points = 3 * tally
	return points;
}

/*******************************************************************************
* Function: sumoffours	                                                       *
* Date Created: October 14, 2017											   *
* Date Last Modified: October 14, 2017                                         *
* Description: Sums of the number of fours and returns the points	           *
* Input parameters: dice array, dice counter array                             *
* Returns: number of points awarded				                               *
* Preconditions: valid inputs												   *
* Postconditions: points returned						                       *
********************************************************************************/
int sumoffours(int array[], int counter[])
{
	int i = 0, points = 0;
	
	for (i = 0; i < FIVEDICE; ++i)
	{
		if (array[i] == SUMOFFOURS)
		{
			counter[SUMOFFOURS]++; //Counts fours
		}
	}
	points = 4 * counter[SUMOFFOURS]; //Points = 4 * tally
	return points;
}

/*******************************************************************************
* Function: sumoffives	                                                       *
* Date Created: October 14, 2017											   *
* Date Last Modified: October 14, 2017                                         *
* Description: Sums of the number of fives and returns the points	           *
* Input parameters: dice array, dice counter array                             *
* Returns: number of points awarded				                               *
* Preconditions: valid inputs												   *
* Postconditions: points returned						                       *
********************************************************************************/
int sumoffives(int array[], int counter[])
{
	int i = 0, points = 0;
	
	for (i = 0; i < FIVEDICE; ++i)
	{
		if (array[i] == SUMOFFIVES)
		{
			counter[SUMOFFIVES]++; //Counts fives
		}
	}
	points = 5 * counter[SUMOFFIVES]; //Points = 5 * tally
	return points;
}

/*******************************************************************************
* Function: sumofsixes	                                                       *
* Date Created: October 14, 2017											   *
* Date Last Modified: October 14, 2017                                         *
* Description: Sums of the number of sixes and returns the points	           *
* Input parameters: dice array, dice counter array                             *
* Returns: number of points awarded				                               *
* Preconditions: valid inputs												   *
* Postconditions: points returned						                       *
********************************************************************************/
int sumofsixes(int array[], int counter[])
{
	int i = 0, points = 0;
	
	for (i = 0; i < FIVEDICE; ++i)
	{
		if (array[i] == SUMOFSIXES)
		{
			counter[SUMOFSIXES]++; //Counts sixes
		}
	}
	points = 6 * counter[SUMOFSIXES]; //Points = 6 * tally
	return points;
}

/*******************************************************************************
* Function: threeofakind                                                       *
* Date Created: October 14, 2017											   *
* Date Last Modified: October 14, 2017                                         *
* Description: Looks for 3 or more identical dice, if true sums the numbers    *
* Input parameters: dice array, dice counter array                             *
* Returns: number of points awarded				                               *
* Preconditions: valid inputs												   *
* Postconditions: points returned						                       *
********************************************************************************/
int threeofakind(int array[], int counter[])
{
	int i = 0, points = 0, index = 0;
	int flag = 0;
	
	for (i = 0; i < FIVEDICE; ++i) //Loops through the dice, tallying each one in the dice counter array
	{
		if (array[i] == SUMOFONES)
		{
			counter[SUMOFONES]++;
		}
		else if (array[i] == SUMOFTWOS)
		{
			counter[SUMOFTWOS]++;
		}
		else if (array[i] == SUMOFTHREES)
		{
			counter[SUMOFTHREES]++;
		}
		else if (array[i] == SUMOFFOURS)
		{
			counter[SUMOFFOURS]++;
		}
		else if (array[i] == SUMOFFIVES)
		{
			counter[SUMOFFIVES]++;
		}
		else
		{
			counter[SUMOFSIXES]++;
		}
	}	
	for (i = 0; i < COUNTER; ++i) //Checks the counter array for a value of three or greater
	{
		if (counter[i] >= 3)
		{
			flag = 1; //Sets flag indicator to sum the faces of the dice
		}
	}
		
	if (flag == 1) //If three of a kind is true
	{
		while (index < FIVEDICE) //loop through the array and add up the face of each die, returning as points 
		{
			points += array[index];
			index++;
		}
	}	
	return points; //If flag is still 0, it will return 0 points
}

/*******************************************************************************
* Function: fourofakind                                                        *
* Date Created: October 14, 2017											   *
* Date Last Modified: October 14, 2017                                         *
* Description: Looks for 4 or more identical dice, if true sums the numbers    *
* Input parameters: dice array, dice counter array                             *
* Returns: number of points awarded				                               *
* Preconditions: valid inputs												   *
* Postconditions: points returned						                       *
********************************************************************************/
int fourofakind(int array[], int counter[])
{
	int i = 0, points = 0, index = 0;
	int flag = 0;
	
	for (i = 0; i < FIVEDICE; ++i) //Loops through the dice, counting each type
	{
		if (array[i] == SUMOFONES)
		{
			counter[SUMOFONES]++;
		}
		else if (array[i] == SUMOFTWOS)
		{
			counter[SUMOFTWOS]++;
		}
		else if (array[i] == SUMOFTHREES)
		{
			counter[SUMOFTHREES]++;
		}
		else if (array[i] == SUMOFFOURS)
		{
			counter[SUMOFFOURS]++;
		}
		else if (array[i] == SUMOFFIVES)
		{
			counter[SUMOFFIVES]++;
		}
		else
		{
			counter[SUMOFSIXES]++;
		}
	}
	for (i = 0; i < COUNTER; ++i) //Loops through the counter searching for a 4 or greater
	{
		if (counter[i] >= 4)
		{
			flag = 1; //Flag indicator set to one
		}
	}

	if (flag == 1) //If 4 dice of a kind exist
	{
		while (index < FIVEDICE)
		{
			points += array[index]; //Loop though dice array and sum the faces of the dice
			index++;
		}
	}
	return points; //If flag is still 0, return 0 points
}

/*******************************************************************************
* Function: fullhouse	                                                       *
* Date Created: October 15, 2017											   *
* Date Last Modified: October 15, 2017                                         *
* Description: Looks for 3 of one identical dice and a pair of identical dice  *
* Input parameters: dice array, dice counter array                             *
* Returns: number of points awarded				                               *
* Preconditions: valid inputs												   *
* Postconditions: points returned						                       *
********************************************************************************/
int fullhouse(int array[], int counter[])
{
	int i = 0, j = 0, points = 0, index = 0;
	int flag_two = 0, flag_three = 0;
	
	for (i = 0; i < FIVEDICE; ++i) //Loops through dice array counting each type
	{
		if (array[i] == SUMOFONES)
		{
			counter[SUMOFONES]++;
		}
		else if (array[i] == SUMOFTWOS)
		{
			counter[SUMOFTWOS]++;
		}
		else if (array[i] == SUMOFTHREES)
		{
			counter[SUMOFTHREES]++;
		}
		else if (array[i] == SUMOFFOURS)
		{
			counter[SUMOFFOURS]++;
		}
		else if (array[i] == SUMOFFIVES)
		{
			counter[SUMOFFIVES]++;
		}
		else
		{
			counter[SUMOFSIXES]++;
		}
	}
	for (i = 0; i < COUNTER; ++i) //Looks in counter array for a value of three
	{
		if (counter[i] == 3)
		{
			flag_three = 1; //Sets flag indicator to 1, meaning 3 of a kind is found
			counter[i] = -1; //Sets this index to -1, to prevent it being counted again for the pair needed for a full house			
		}		
	}

	if (flag_three == 1) //If 3 of a kind is found
	{
		for (j = 0; j < COUNTER; ++j) //Re check for a pair of dice
		{
			if (counter[j] == 2) //If the counter is 2
			{
				flag_two = 1; //Set flag indicator for a pair to 1
			}
		}
	}

	if (flag_three == 1 && flag_two == 1) //If both a 3 of a kind and a pair are true, 25 points awarded
	{
		points = 25;		
	}	
	return points; //If either flag is not 1, returns 0 points
}

/*******************************************************************************
* Function: yahtzee		                                                       *
* Date Created: October 15, 2017											   *
* Date Last Modified: October 15, 2017                                         *
* Description: Looks for 5 identical dice, if true sums the numbers			   *
* Input parameters: dice array, dice counter array                             *
* Returns: number of points awarded				                               *
* Preconditions: valid inputs												   *
* Postconditions: points returned						                       *
********************************************************************************/
int yahtzee(int array[], int counter[])
{
	int i = 0, points = 0, index = 0;
	int flag = 0;
	
	for (i = 0; i < FIVEDICE; ++i) //Loops through dice, counting each type
	{
		if (array[i] == SUMOFONES)
		{
			counter[SUMOFONES]++;
		}
		else if (array[i] == SUMOFTWOS)
		{
			counter[SUMOFTWOS]++;
		}
		else if (array[i] == SUMOFTHREES)
		{
			counter[SUMOFTHREES]++;
		}
		else if (array[i] == SUMOFFOURS)
		{
			counter[SUMOFFOURS]++;
		}
		else if (array[i] == SUMOFFIVES)
		{
			counter[SUMOFFIVES]++;
		}
		else
		{
			counter[SUMOFSIXES]++;
		}
	}
	for (i = 0; i < COUNTER; ++i) //Loops through counter to find five of a kind
	{
		if (counter[i] == 5)
		{
			flag = 1; //If true, set flag indicator to 1
		}
	}

	if (flag == 1)
	{		
		points = 50; //Award 50 points if flag = 1	
	}
	return points; //Otherwise return 0 points
}

/*******************************************************************************
* Function: chance		                                                       *
* Date Created: October 15, 2017											   *
* Date Last Modified: October 15, 2017                                         *
* Description: Catch all combination, sums faces of all dice			       *
* Input parameters: dice array, dice counter array                             *
* Returns: number of points awarded				                               *
* Preconditions: valid inputs												   *
* Postconditions: points returned						                       *
********************************************************************************/
int chance(int array[], int counter[])
{
	int i = 0, points = 0, index = 0;
	int flag = 0;
	
	for (i = 0; i < FIVEDICE; ++i) //Loops through dice and adds up the sum of all faces
	{
		points += array[i];
	}
	return points; //Returns the sum as the number of points
}

/*******************************************************************************
* Function: largestraight                                                      *
* Date Created: October 16, 2017											   *
* Date Last Modified: October 16, 2017                                         *
* Description: Checks two possible combinations for large straight			   *
* Input parameters: dice array, dice counter array                             *
* Returns: number of points awarded				                               *
* Preconditions: valid inputs												   *
* Postconditions: points returned						                       *
********************************************************************************/
int largestraight(int array[], int counter[])
{
	int i = 0, points = 0, index = 0;
	int flag = 0;
	
	for (i = 0; i < FIVEDICE; ++i) //Loops through dice, counting each type
	{
		if (array[i] == SUMOFONES)
		{
			counter[SUMOFONES]++;
		}
		else if (array[i] == SUMOFTWOS)
		{
			counter[SUMOFTWOS]++;
		}
		else if (array[i] == SUMOFTHREES)
		{
			counter[SUMOFTHREES]++;
		}
		else if (array[i] == SUMOFFOURS)
		{
			counter[SUMOFFOURS]++;
		}
		else if (array[i] == SUMOFFIVES)
		{
			counter[SUMOFFIVES]++;
		}
		else
		{
			counter[SUMOFSIXES]++;
		}
	}
	if (counter[1] == 0) //Checks counter array for a 0 in index 1
	{
		for (i = 2; i < COUNTER; ++i) //Loops through index 2 - 6
		{
			if (counter[i] != 1) //Checks all index for 1
			{
				flag = -1; //If any value is not a single dice, trips the flag indicator to -1
			}
		}
	}
	else if (counter[1] == 1) //Checks counter array for 1 in index 1
	{
		for (i = 2; i < 6; ++i) //Checks index 2 - 5 
		{
			if (counter[i] != 1) //If any value is not a single dice, trip flag
			{
				flag = -1;
			}
		}
	}

	if (flag != -1) //if no flag has been tripped, largestraight is true and 40 points awarded
	{
		points = 40;
	}
	return points;
}

/*******************************************************************************
* Function: smallstraight                                                      *
* Date Created: October 16, 2017											   *
* Date Last Modified: October 16, 2017                                         *
* Description: Checks three combinations for smallstraight					   *
* Input parameters: dice array, dice counter array                             *
* Returns: number of points awarded				                               *
* Preconditions: valid inputs												   *
* Postconditions: points returned						                       *
********************************************************************************/
int smallstraight(int array[], int counter[])
{
	int i = 0, points = 0, index = 0;
	int flag = 0;
	
	for (i = 0; i < FIVEDICE; ++i) //Loops through the dice, counting each type
	{
		if (array[i] == SUMOFONES)
		{
			counter[SUMOFONES]++;
		}
		else if (array[i] == SUMOFTWOS)
		{
			counter[SUMOFTWOS]++;
		}
		else if (array[i] == SUMOFTHREES)
		{
			counter[SUMOFTHREES]++;
		}
		else if (array[i] == SUMOFFOURS)
		{
			counter[SUMOFFOURS]++;
		}
		else if (array[i] == SUMOFFIVES)
		{
			counter[SUMOFFIVES]++;
		}
		else
		{
			counter[SUMOFSIXES]++;
		}
	}
	if (counter[1] == 0) //Checks index 1 for 0
	{
		for (i = 2; i < 6; ++i) //Checks index 2 - 5 for smallstraight
		{
			if (counter[i] != 1) //If not a single die, trip flag
			{
				flag = -1;
			}
		}
	}
	else if (counter[1] == 1) //Checks index 1 for 1
	{
		for (i = 2; i < 5; ++i) //Checks index 2 - 4 for smallstraight
		{
			if (counter[i] != 1)
			{
				flag = -1;
			}
		}
	}
	else if (counter[1] == 0 && counter[2] == 0) //If both index 1 and 2 are 0, 3 - 6 must be single dice or no small straight exists
	{
		for (i = 3; i < COUNTER; ++i)
		{
			if (counter[i] != 1)
			{
				flag = -1;
			}
		}
	}

	if (flag != -1) //If one of the three combinations exists, awards 30 points
	{
		points = 30;
	}
	return points;
}

/*******************************************************************************
* Function: checkcombination                                                   *
* Date Created: October 12, 2017											   *
* Date Last Modified: October 12, 2017                                         *
* Description: Checks to make sure score combination hasn't been used		   *
* Input parameters: dice array, pointer to combination selected by user        *
* Returns: void									                               *
* Preconditions: valid inputs												   *
* Postconditions: valid score selection chosen that hasn't already been used   *
********************************************************************************/
void check_combination(int array[], int *selection)
{
	int valid_choice = -1;
	while (array[*selection - 1] == 1)
	{
		system("cls");
		printf("That combination has already been used.\n");
		*selection = get_combination();
	}
}

/*******************************************************************************
* Function: reinitialize_dice_counter                                          *
* Date Created: October 12, 2017											   *
* Date Last Modified: October 12, 2017                                         *
* Description: Resets dice counter for use after each turn					   *
* Input parameters: dice array, size			                               *
* Returns: void									                               *
* Preconditions: valid inputs												   *
* Postconditions: dice counter array reset to 0s		                       *
********************************************************************************/
void reinitialize_dice_counter(int array[], int size)
{
	int index = 0;

	for (index = 0; index < size; ++index)
	{
		array[index] = 0;
	}
}

/*******************************************************************************
* Function: score_category                                                     *
* Date Created: October 16, 2017											   *
* Date Last Modified: October 16, 2017                                         *
* Description: Assigns points to scoreboard, marks selection as used		   *
* Input parameters: dice array, dice counter array, combo choice               *
* Returns: void									                               *
* Preconditions: valid arrays, needs choice from user						   *
* Postconditions: Modifies scoreboard with points and marks combo as used      *
********************************************************************************/
void score_category(int dice_array[], int count_array[], int choice, int score_array[], int combo_array[])
{
	switch (choice) //Based on choice passed in from the 13 score combinations. 
	{
	case SUMOFONES: score_array[0] = sumofones(dice_array, count_array); //Assigns scoreboard index with appropriate points
					combo_array[0]= 1;									 //Marks combo as used ( = 1 || Choice - 1)		
		break;
	case SUMOFTWOS: score_array[1] = sumoftwos(dice_array, count_array);
					combo_array[1] = 1;
		break;
	case SUMOFTHREES: score_array[2] = sumofthrees(dice_array, count_array);
					  combo_array[2] = 1;
		break;
	case SUMOFFOURS: score_array[3] = sumoffours(dice_array, count_array);
					 combo_array[3] = 1;
		break;
	case SUMOFFIVES: score_array[4] = sumoffives(dice_array, count_array);
					 combo_array[4] = 1;
		break;
	case SUMOFSIXES: score_array[5] = sumofsixes(dice_array, count_array);
					 combo_array[5] = 1;
		break;
	case THREEOFAKIND: score_array[6] = threeofakind(dice_array, count_array);
					   combo_array[6] = 1;
		break;
	case FOUROFAKIND: score_array[7] = fourofakind(dice_array, count_array);
					  combo_array[7] = 1;
		break;
	case FULLHOUSE: score_array[8] = fullhouse(dice_array, count_array);
					combo_array[8] = 1;
		break;
	case SMALLSTRAIGHT: score_array[9] = smallstraight(dice_array, count_array);
						combo_array[9] = 1;
		break;
	case LARGESTRAIGHT: score_array[10] = largestraight(dice_array, count_array);
						combo_array[10] = 1;
		break;
	case YAHTZEE: score_array[11] = yahtzee(dice_array, count_array);
				  combo_array[11] = 1;
		break;
	case CHANCE: score_array[12] = chance(dice_array, count_array);
				 combo_array[12] = 1;
		break;
	}
	printf("Points this turn: %d\n\n", score_array[choice - 1]); //Prints the points awarded during the current turn
}

/*******************************************************************************
* Function: sum_points	                                                       *
* Date Created: October 16, 2017											   *
* Date Last Modified: October 16, 2017                                         *
* Description: Loops through scoreboard to sum the total points			       *
* Input parameters: scoreboard array			                               *
* Returns: total of points awarded				                               *
* Preconditions: valid inputs, should be fully completed scoreboard  		   *
* Postconditions: total points returned					                       *
********************************************************************************/
int sum_points(int score_array[]) 
{
	int i = 0, sum = 0; 

	for (i = 0; i < COMBOS; ++i) //Loops through scoreboard array to sum all the points
	{
		sum += score_array[i];
	}
	return sum;
}

/*******************************************************************************
* Function: print_winner                                                       *
* Date Created: October 16, 2017											   *
* Date Last Modified: October 16, 2017                                         *
* Description: Compares points for player 1 and player 2 and prints winner     *
* Input parameters: player 1 score, player 2 score                             *
* Returns: void									                               *
* Preconditions: total points summed										   *
* Postconditions: print output to screen				                       *
********************************************************************************/
void print_winner(int p1_score, int p2_score)
{
	printf("Player One's Total Points: %d\n", p1_score);
	printf("Player Two's Total Points: %d\n", p2_score);

	if (p1_score > p2_score) //P1 WIN
	{
		printf("\nPLAYER ONE WINS with a score of %d\n\n", p1_score);
	}
	else if (p2_score > p1_score) //P2 WIN
	{
		printf("\nPLAYER TWO WINS with a score of %d\n\n", p2_score);
	}
	else //DRAW
		printf("If you ain't first you're...last??\nDRAW of score %d\n\n", p1_score);
}

/*******************************************************************************
* Function: uppersection                                                       *
* Date Created: October 16, 2017											   *
* Date Last Modified: October 16, 2017                                         *
* Description: Adds bonus score for upper section if point threshold met	   *
* Input parameters: scoreboard array				                           *
* Returns: void									                               *
* Preconditions: valid inputs												   *
* Postconditions: points returned through pointer to score                     *
********************************************************************************/
void upper_section(int score_array[], int *score)
{
	int i = 0, sum = 0;

	for (i = 0; i < UPPER; ++i) //Loops through the Upper section of the scoreboard (SUMS)
	{
		sum += score_array[i]; //Adds points awarded
	}

	if (sum >= UPPERLIMIT) //If 63 + points
	{
		*score += UPPERBONUS; //Add 35 points to the total score
	}
}

/*******************************************************************************
* Function: Play_Yahtzee                                                       *
* Date Created: October 14, 2017											   *
* Date Last Modified: October 19, 2017                                         *
* Description: Drives the looping gameplay for Yahtzee						   *
* Input parameters: void							                           *
* Returns: void									                               *
* Preconditions: Play game selected in menu									   *
* Postconditions: Game completes with winner displayed, menu displayed         *
********************************************************************************/
void Play_Yahtzee(void)
{	//Menu selection and array initialization variables
	int Yahtzee_menu_selection = 0;
	int dice[FIVEDICE] = { 0 }, dice_counter[COUNTER] = { 0 }; //Dice Arrays
	int p1_scorecard[COMBOS] = { 0 }, p1_combos_used[COMBOS] = { 0 }; //Scoring Arrays
	int p2_scorecard[COMBOS] = { 0 }, p2_combos_used[COMBOS] = { 0 };
	int current_player = PLAYER_ONE; //Initial Player
	//Counters
	int choice = 0, reroll = 0, reroll2 = 0, count = 1, round = 1;
	int p1_total_points = 0, p2_total_points = 0;	
	//Test arrays - AUSTIN -- Feel free to plug these into my score_category function in place of dice for faster testing :) <****************<*********<******LOOK*****<****HERE******<*******LOOK******<*******HERE******<***********************<
	int test_fullhouse[5] = { 3, 3, 3, 2, 2 }, test_largestraight[5] = { 1, 2, 3, 4, 5 }, test_smallstraight[5] = { 1, 2, 3, 4 };
	int test_yahtzee[5] = { 5, 5, 5, 5, 5 };
	//Sets score combinations to -1 to indicate they have not been used yet	
	initialize_scorecombos(p1_combos_used, COMBOS);
	initialize_scorecombos(p2_combos_used, COMBOS);

	//Game Starts
	printf("YAHTZEE - A true test of champions. May your wit be unwaivering!\n");
	printf("\n& if you hit that 5 of a kind, don't forget to scream!\t YAHTZEEEEEEEE!\n");
	printf("\nPlayer One, BEGIN!\n\n");
		
	do
	{
		press_enter(); //Press any key to continue
		Yahtzee_dice_roll(dice, FIVEDICE); //Rolls all 5 dice
		count = 1; //Reinitialize count to 1 for looped gameplay

		do
		{
			reroll = check_for_reroll(); //Asks user if they want to reroll the dice, returns 1 if yes
			reroll2 = dice_reroll(reroll, dice, FIVEDICE, &count); //If Yes, rerolls the dice, increases count by 1.					
		} while (count < 3 && reroll2 != 0); //Stops rolling the dice if user says no or rolls reaches 3
		printf("Dice rolls used: %d\n", count);
		choice = get_combination(); //Gets scoring combination desired from the user

		if (current_player == PLAYER_ONE)
		{
			check_combination(p1_combos_used, &choice); //Checks to make sure the combination hasn't already been used
			score_category(dice, dice_counter, choice, p1_scorecard, p1_combos_used); //Scores the valid combination and adjusts scoring & combos used arrays
		}
		else if (current_player == PLAYER_TWO)
		{
			check_combination(p2_combos_used, &choice); //Checks to make sure the combination hasn't already been used
			score_category(dice, dice_counter, choice, p2_scorecard, p2_combos_used); //Scores the valid combination and adjusts scoring & combos used arrays
		}

		reinitialize_dice_counter(dice_counter, COUNTER); //Resets the counter to 0
		current_player = !current_player; //Swaps players
		++round;
	} while (round < TOTAL_ROUNDS);


	printf("Remember all the loot & glory goes to the VICTOR!\n\n");
	press_enter();
	p1_total_points = sum_points(p1_scorecard); //Sums up Player One's points
	p2_total_points = sum_points(p2_scorecard); //Sums up Player Two's points
	upper_section(p1_scorecard, &p1_total_points); //Decides whether to add 63 bonus points for the upper section
	upper_section(p2_scorecard, &p2_total_points);
	print_winner(p1_total_points, p2_total_points); //Prints the winner
}
	