/*************************************************************************************************************************
/*Programmer: David Henshaw																								 *
*Class: CptS 121, Fall 2017, Leb Section 03																			     *
*Programming Assignment: PA5 - Yahtzee																					 *
*Date: October 20, 2017																									 *
*Description:  This program plays the dice game Yahtzee. It includes a menu and the abiltity to play repeatedly.		 *		   
*																														 *
*			   Utilizes srand and rand function to roll five dice, check the values for 13 combinations, and assign		 *
*			   points based on the combination. These can only be used once per player.									 *
*			   Dice can be selected and rerolled. Uses switch statements to create multiple menus. Firse use of arrays.	 *
*              																											 *
*              Inputs: Menu Options, Keyboard input																		 *
*              Constants: See Header File																			     *
*              Computations: 13 Scoring Combinations such as Full House and Large Straight, Random # 1-6 		         *
*              Outputs: Yahtzee_rules, Play_Yahtzee(); to view rules, play the game, or exit					    	 *
*																													     *
*              This program provides some error checking for input validation										     *
*              This program contains a custom header and a second source file for custom function definitions.			 *
*																														 *
**************************************************************************************************************************/

#include "Yahtzee.h"

int main(void)
{
	int Yahtzee_menu_selection = 0;

	initialize_rand(); //Initializes random number generator seed
		
	do
	{
		Yahtzee_menu_selection = Yahtzee_menu(); //Prints menu and obtains selection

		switch (Yahtzee_menu_selection)
		{
		case 1: Yahtzee_rules(); //Prints the rules
			break;
		case 2: Play_Yahtzee(); //Plays Yahtzee
			break;
		case 3: printf("Thank you for playing Yahtzee!\n\n"); //Exits game
			break;
		}
	} while (Yahtzee_menu_selection != 3); //Exits game
	
	return 0;
}