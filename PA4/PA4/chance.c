/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 121, Fall 2017, Lab Section 03																										       *
*Programming Assignment: PA4 - Craps																												   *
*Date: October 6, 2017																																   *
*Description: chance.c source file contains the function descriptions for casino game craps												               *
********************************************************************************************************************************************************/

#include "chance.h"

/*******************************************************************************
* Function: print_game_rules                                                   *
* Date Created: September 30, 2017											   *
* Date Last Modified: October 6, 2017                                          *
* Description: Prints out the game rules for craps                             *
* Input parameters: void			                                           *
* Returns: void				                                                   *
* Preconditions: program started with menu displayed, player chooses to print  *
*				 the game rules												   *
* Postconditions: prints game rules						                       *
********************************************************************************/
void print_game_rules(void) 
{
	printf("Welcome to Craps!\n\n");
	printf("The rules are as follows:\n");
	printf("Player rolls two standard dice. The sum of the upward faces is calculated.\n\nIf the sum is 7 or 11 on the first throw the player wins!\n");
	printf("If the sum is 2, 3, or 12 on the first throw it is called \"craps\" and the player loses.\n");
	printf("If the sum is 4, 5, 6, 8, 9, or 10 on the first throw that sum becomes the player's \"point.\"\n\n");
	printf("To win, the player must continue rolling the dice until the \"point\" is reached.\nIf the player rolls a sum of 7 before making the \"point\" they lose!\n\n");
}

/*******************************************************************************
* Function: chatter_messages                                                   *
* Date Created: October 5, 2017											       *
* Date Last Modified: October 6, 2017                                          *
* Description: Displays flavor messages based on win/loss, #rolls, and balance *
* Input parameters: number of dice rolls, bank balance, win/loss conditon      *
* Returns: printf statement (void)                                             *
* Preconditions: game must have played at least once, valid balance and roll # *
* Postconditions: prints chatter text   				                       *
********************************************************************************/
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
	int rolls = number_rolls;
	int win = win_loss_neither;
	
	if (initial_bank_balance < current_bank_balance)
	{
		printf("\nOn your way to becoming a high roller!\n");
	}
	
	if (current_bank_balance == (2 * initial_bank_balance))
	{
		printf("\nYou doubled your money!\nBetter cash out because I think security is onto you...\n");
	}

	if (current_bank_balance <= 0)
	{
		printf("\nYou really went broke? The ATMs are located in the lobby.\n");
	}
		

	if (number_rolls > 5 && win == 1)
	{
		printf("\nWow, the stakes have never been higher!\n");
	}
	else if	(number_rolls > 3 && win == 1)
	{
		printf("\nRisky business...\n");
	}
	
	if (number_rolls > 5 && win == 0)
	{
		printf("\nShoot for the stars and crash to the Earth!\n");
	}
	else if (number_rolls > 3 && win == 0)
	{
		printf("\nCrash and burn!\n");
	}

}

/*******************************************************************************
* Function: check_wager_amount                                                 *
* Date Created: October 5, 2017												   *
* Date Last Modified: October 6, 2017                                          *
* Description: checks that user wager !> current balance                       *
* Input parameters: user's wager and balance                                   *
* Returns: int 0 if wager is invalid, 1 if valid                               *
* Preconditions: program started valid inputs								   *
* Postconditions: returns integer value	(true / false) for valid wager         *
********************************************************************************/
int check_wager_amount(double wager, double balance)
{
	double check_wager = 0;

	if (wager > balance)
	{
		printf("Wager exceeds bank balance. Please re-stake.\n");		
		return 0;		
	}
	else return 1;
}	

/*******************************************************************************
* Function: validate_wager                                                     *
* Date Created: October 5, 2017												   *
* Date Last Modified: October 6, 2017                                          *
* Description: Combines get_wager_amount() and check_wager_amount to make sure *
*				user's wager !> balace. If it is, get a new wager              *
* Input parameters: user's balance			                                   *
* Returns: a valid double: wager amount			                               *
* Preconditions: a valid balance											   *
* Postconditions: returns valid wager					                       *
********************************************************************************/
double validate_wager(double balance)
{
	double final_wager = 0.0;
	int check = -1;

	do
	{
		final_wager = get_wager_amount();
		check = check_wager_amount(final_wager, balance);
	} while (check == 0);

	return final_wager;
}

/*******************************************************************************
* Function: roll_die		                                                   *
* Date Created: September 30, 2017											   *
* Date Last Modified: October 6, 2017                                          *
* Description: Rolls dice for a random int value 1 - 6						   *
* Input parameters: void					                                   *
* Returns: Dice value 1 - 6						                               *
* Preconditions: srand must be initialized									   *
* Postconditions: returns dice value					                       *
********************************************************************************/
int roll_die(void)
{
	int die_value = 0;
	die_value = rand() % 6 + 1;
	return die_value;
}

/*******************************************************************************
* Function: calculate_sum_dice                                                 *
* Date Created: September 30, 2017											   *
* Date Last Modified: October 6, 2017                                          *
* Description: Simply adds the two dice values together for the sum            *
* Input parameters: two dice values			                                   *
* Returns: dice sum								                               *
* Preconditions: dice must be rolled										   *
* Postconditions: returns sum							                       *
********************************************************************************/
int calculate_sum_dice(int die1_value, int die2_value)
{
	int sum = 0.0;
	sum = die1_value + die2_value;
	return sum; 
}

/*******************************************************************************
* Function: is_win_loss_or_point                                               *
* Date Created: September 30, 2017											   *
* Date Last Modified: October 6, 2017                                          *
* Description: Determines if the initial dice rolls wins or loses	           *
* Input parameters: valid dice sum (initial rolls)                             *
* Returns: int 1 if win, 0 if loss, -1 if point (neither)                      *
* Preconditions: a valid dice sum											   *
* Postconditions: returns int value indicating win/loss condition              *
********************************************************************************/
int is_win_loss_or_point(int sum_dice)
{
	if (sum_dice == 7 || sum_dice == 11)
	{
		return 1;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) 
	{
		return 0;
	}
	else return -1;
}

/*******************************************************************************
* Function: is_point_loss_or_neither                                           *
* Date Created: September 30, 2017											   *
* Date Last Modified: October 6, 2017                                          *
* Description: Similar to is_win_loss_or_point but used for subsequent rolls   *
* Input parameters: dice sum and point value                                   *
* Returns: int 1 for win, 0 for loss, -1 for neither                           *
* Preconditions: a valid sum, and the point value must be set after			   *
*				 initial roll takes place									   *
* Postconditions: returns int value indicating win/loss condition              *
********************************************************************************/
int is_point_loss_or_neither(int sum_dice, int point_value)
{
	if (sum_dice == point_value)
	{
		return 1;
	}
	else if (sum_dice == 7)
	{
		return 0;
	}
	else return -1;
}

/*******************************************************************************
* Function: get_bank_balance                                                   *
* Date Created: September 30, 2017											   *
* Date Last Modified: October 6, 2017                                          *
* Description: Gets bank balance from the user						           *
* Input parameters: void					                                   *
* Returns: double bank balance					                               *
* Preconditions: game must be playing										   *
* Postconditions: returns valid balance					                       *
********************************************************************************/
double get_bank_balance(void)
{
	double balance = 0.0;

	printf("Please enter initial bank balance: $ ");
	scanf(" %lf", &balance);
	return balance;
}

/*******************************************************************************
* Function: get_wager_amount                                                   *
* Date Created: September 30, 2017											   *
* Date Last Modified: October 6, 2017                                          *
* Description: Get wager from the user with a simple scanf		               *
* Input parameters: void					                                   *
* Returns: double wager							                               *
* Preconditions: craps must be playing										   *
* Postconditions: returns valid wager					                       *
********************************************************************************/
double get_wager_amount(void)
{
	double wager = 0.0;

	printf("Name your stake: $ ");
	scanf(" %lf", &wager);
	return wager;
}

/*******************************************************************************
* Function: adjust_bank_balance                                                *
* Date Created: October 5, 2017												   *
* Date Last Modified: October 6, 2017                                          *
* Description: Adjusts bank balance by the waged amount prior to the roll	   *
*			   If win, adds wager. If loss, subtracts wager					   *
* Input parameters: user's balance, wager, and add_or_subtract (win/loss)      *
* Returns: new bank balance						                               *
* Preconditions: a valid balance, wager, and game has played at least once     *
* Postconditions: returns updated bank balance			                       *
********************************************************************************/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
	double adjust = 0.0;
	
	if (add_or_subtract == 1)
	{
		adjust = bank_balance + wager_amount;
	}
	else
	{
		adjust = bank_balance - wager_amount;
	}
	return adjust; 
}

/*******************************************************************************
* Function: play_craps	                                                       *
* Date Created: October 5, 2017												   *
* Date Last Modified: October 6, 2017                                          *
* Description: This function asks if the user would like to play again after   *
*				each round. Uses a do-while loop statement to validate input   *
* Input parameters:	void					                                   *
* Returns: int 1 to play again, 0 to quit, -1 for invalid entry                *
* Preconditions: none														   *
* Postconditions: int to play quit or repeat entry		                       *
********************************************************************************/
int play_craps(void)
{
	char type = '\0';
	int play = '\0';

	do //Repeats when input is not yes or no
	{
		printf("Would you like to play again? "); 
		scanf(" %c", &type);
		system("cls");

		switch (type)
		{
		case 'y':
		case 'Y': play = 1;
			break;
		case 'n':
		case 'N': play = 0;
			break;
		default: printf("Please Enter Y or N:\n"); play = -1;
		}

	} while (play == -1);
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
	printf("1. Display Craps Rules\n");
	printf("2. Play Craps\n");
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
* Function: menu_option                                                        *
* Date Created: October 5, 2017												   *
* Date Last Modified: October 6, 2017                                          *
* Description: Combines display_menu and menu_input to prompt and validate	   *	
*				user input to pick which menu option to run, 1 - 3             *
* Input parameters: void					                                   *
* Returns: Menu option chosen					                               *
* Preconditions: running program, subfunctions compiled						   *
* Postconditions: void									                       *
********************************************************************************/
int menu_option(void)
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
* Function: check_balance                                                      *
* Date Created: October 5, 2017												   *
* Date Last Modified: October 6, 2017                                          *
* Description: Checks bank balance for $0.00					               *
* Input parameters: bank balance			                                   *
* Returns: int 0 if bank balance is 0, 1 otherwise                             *
* Preconditions: valid balance input										   *
* Postconditions: int 0 if balance is 0, 1 otherwise returned                  *
********************************************************************************/
int check_balance(double bank_balance)
{
	double balance = bank_balance;

	if (balance <= 0)
	{
		return 0;
	}
	else return 1;
}

/*******************************************************************************
* Function: test_play                                                          *
* Date Created: October 5, 2017												   *
* Date Last Modified: October 6, 2017                                          *
* Description: This function acts similar to a main function in that it		   *
*				contains nested loops to repeat the game of craps. It starts   *
*				with initalizing most variables and repeats dice rolls, wager  * 
*				prompts and game prompts.									   *
* Input parameters: void					                                   *
* Returns: void									                               *
* Preconditions: running program, menu option chosen to play game			   *
* Postconditions: game returns to menu or plays again	                       *
********************************************************************************/
void test_play(void)
{
	double wager = 0.0, initialbalance = 0.0, balance = 0.0; //Initialzation of variables
	int roll = 0, roll_two = 0, sum = 0, addsub = 0;
	int result = '\0', point = 0, resume = '\0'; //Want result and resume to be null rather than 0
	int option = 0;
	int count = 0; //Counter for looping dice rolls
	int game_over = '\0'; 

	initialbalance = get_bank_balance(); //Gets initial bank balance from user
	balance = initialbalance; //Stores in a new variable balance (two are separate for chatter messages)
	result = -1; //Result of first loop to prevent loop error
	do
	{
		result = -1; //Re-initialize to prevent error
		wager = validate_wager(balance); //Get a valid wager that does not exceed current bank balance
		roll = roll_die();
		roll_two = roll_die();
		printf("Roll 1: %d\n", roll);
		printf("Roll 2: %d\n\n", roll_two);
		sum = calculate_sum_dice(roll, roll_two); //Sum two dice
		result = is_win_loss_or_point(sum); //Determine win loss or neither on first roll

		if (result == 1)	//If result is W
		{
			printf("You WIN!\n");
			addsub = 1; //Win loss variable
			balance = adjust_bank_balance(balance, wager, addsub); //Adjusts balance + or - based on W/L
			printf("\nBalance: $%.2lf\n", balance);
		}
		else if (result == 0) //If result is L
		{
			printf("You LOSE! CRAPS!\n");
			addsub = 0;
			balance = adjust_bank_balance(balance, wager, addsub);
			printf("\nBalance: $%.2lf\n", balance);
		}
		else point = sum;	//Result is now set to point if neither W or L
		printf("Target Point: %d\n\n", point);

		if (point == sum) //If point is == sum continue program to subsequent point rolls
		{
			count = 0; //Re-initialize the counting variable
			do
			{
				roll = roll_die();	//Keeps rolling until point is made or loss. Should this be changed to singular rolls/sums?
				roll_two = roll_die();
				printf("Roll 3: %d\n", roll);
				printf("Roll 4: %d\n\n", roll_two);
				sum = calculate_sum_dice(roll, roll_two); //Sum two dice
				result = is_point_loss_or_neither(sum, point); //Determine point loss or neither
				count++; //Add one to count (used in chatter)

			} while (result == -1); //Repeats until win or loss

			printf("Rolls to make point: %d\n", count); //Tracks how many subsequent rolls it took to win or lose

			if (result == 1) //If Win
			{
				printf("You WIN!\n");
				addsub = 1; //W
				balance = adjust_bank_balance(balance, wager, addsub); //Updates balance
				chatter_messages(count, result, initialbalance, balance); //Chatters based on number of rolls and the balance
				printf("\nBalance: $%.2lf\n", balance);
			}
			else
			{
				printf("You LOSE! CRAPS!\n"); //Loss
				addsub = 0; //L
				balance = adjust_bank_balance(balance, wager, addsub); //Updates balance
				chatter_messages(count, result, initialbalance, balance); //Chatter based on loss
				printf("\nBalance: $%.2lf\n", balance);
			}

		}
		game_over = check_balance(balance); //Variable game over uses check_balance to see if the balance hit 0

		if (game_over == 0) //If the player goes bankrupt the game exits
		{
			printf("* * * * *GAME OVER* * * * *\n\n");
			return 0;
		}

		resume = play_craps(); //Asks if player wannts to play again
		printf("Previous Balance: $%.2lf\n", balance); //Prints previous balance on screen after system (cls) to help player keep track of their balance while wagering


	} while (resume != 0); //Program repeats until user says they no longer wish to play another round


	return 0;
}
