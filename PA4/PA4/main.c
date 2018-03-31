/*************************************************************************************************************************
/*Programmer: David Henshaw																								 *
*Class: CptS 121, Fall 2017, Leb Section 03																			     *
*Programming Assignment: PA4 - Craps																					 *
*Date: October 6, 2017																									 *
*Description:  This program plays the casino game craps. It includes a menu and the abiltity to play repeatedly.		 *
*			   An inital bank balance is asked for and wagers will be added or subtracted from the bank based on		 *
*			   win or lose conditions. If the bank balance reaches $0.00 the game will end.								 *		
*																														 *
*			   Utilizes srand and rand function to roll two dice, sum the pair, and win or lose based on the sum.		 *
*			   Uses a switch statement to create the menu.																 *
*              																											 *
*              Inputs: Option       																					 *
*              Constants: None																						     *
*              Computations: Random # 1-6, Sum, Addition and Subtraction		          						         *
*              Outputs: print_game_rules, test_play(); to play the game, or exit					    				 *
*																													     *
*              This program provides some error checking for input validation										     *
*              This program contains a custom header and a second source file for custom function definitions.			 *
*																														 *
**************************************************************************************************************************/

#include "chance.h"

int main(void)
{
	int option = 0;
	
	initialize_rand(); //Initializes srand with seed Time = NULL

	do
	{
		option = menu_option(); //Function to display the menu and ask the user for input

		switch (option) //Switch statement based on the option given
		{
		case 1: print_game_rules(); //Prints game rules and the menu again
			break;
		case 2: test_play(); //Function that contains all other functions to drive the game as long as the user wants to play
			break;
		case 3: return 0; //Exits game
		}

	} while (option != 3); //Input validation - must be a valid integer 1 - 3 or the menu reprints
	
	return 0; //Program reaches end successfully
}
