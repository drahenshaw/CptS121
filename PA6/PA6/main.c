/*************************************************************************************************************************
/*Programmer: David Henshaw																								 *
*Class: CptS 121, Fall 2017, Leb Section 03																			     *
*Programming Assignment: PA5 - Yahtzee																					 *
*Date: November 6, 2017																									 *
*Description:  This program plays Battleship in a text format. It includes several sub-menus.							 *
*																														 *
*			   Utilizes srand and rand function to randomly place ships, or allows user to place manually on a 2D board. *
*			   Once all 5 ships are placed, player battles the computer to sink the enemy fleet first.					 *
*			   First player to sink the enemy fleet wins.																 *
*              																											 *
*              Inputs: Menu Options, Keyboard input																		 *
*              Constants: See Header File																			     *
*              Computations: Adjustments to array indexing values to keep ships inbounds on game board array	         *
*              Outputs: Game board printouts, moves logged to battleship.log file with ending stats				    	 *
*																													     *
*              This program provides some error checking for input validation.										     *
*              This program contains a custom header and a second source file for custom function definitions.			 *
*																														 *
**************************************************************************************************************************/

#include "battleship.h"

int main(void)
{
	char player_one_board[NUM_ROWS][NUM_COLUMNS] = { {'~'} }; //Declares game board arrays
	char computer_board[NUM_ROWS][NUM_COLUMNS] = { {'-'} };

	FILE *outfile = NULL; 

	int placement = 0; //Variable for manual or random ship placement
	int current_player = 0; //Initialized current player to PLAYERONE
	Dir direct = VERTICAL; 
	Dir random = VERTICAL;
	int *x_begin = 0, *y_begin = 0; //Pointers to x,y start points for ship placement
	int *rx_begin = 0, *ry_begin = 0;
	int occupied = 0; //Flag for occupied cell in array
	int shot_x = 0, shot_y = 0; //Shot x and y coordinates
	int hitormiss = 0; //Hit or miss variable
	int *p1_h_tracker = 0; //Pointers to hit and miss trackers for player and cpu
	int *cp_h_tracker = 0;
	int *p1_m_tracker = 0;
	int *cp_m_tracker = 0;
	int *c_s = 0, *b_s = 0, *s_s = 0, *d_s = 0, *r_s = 0; //Pointers to sink trackers for player and cpu
	int *cp_s = 0, *bp_s = 0, *sp_s = 0, *dp_s = 0, *rp_s = 0;

	outfile = fopen("battleship.log", "w"); //Creates .log file for outputting moves at stats
	initialize_rand(); //Seeds rand
	welcome_screen(); //Prints rules of battleship
	press_enter(); //Clears screen after a key is pressed

	initialize_game_board(player_one_board, NUM_ROWS, NUM_COLUMNS); //Sets boards to default values
	initialize_comp_board(computer_board, NUM_ROWS, NUM_COLUMNS);
	printf("Your Waters:\n");										//Prints both boards
	print_game_board(player_one_board, NUM_ROWS, NUM_COLUMNS, PLAYERONE);
	printf("Enemy Waters:\n");
	print_game_board(computer_board, NUM_ROWS, NUM_COLUMNS, COMPUTER);
	
	placement = ship_placement_menu(); //Asks for manual or random ship placement

	if (placement == MANUAL)
	{
		direct = get_manual_direction(); //Get horizontal or vertical direction from the user	
		printf("Enter coordiantes for Carrier:\n");
		generate_start_manual(CARRIER, direct, &x_begin, &y_begin); //Obtains valid x,y for ship placement starting point
		printf("\nDeploying USS Semicolon - - - >\n\n");
		place_ship(player_one_board, CARRIER, direct, x_begin, y_begin, CAR); //Places the carrier
		print_game_board(player_one_board, NUM_ROWS, NUM_COLUMNS, PLAYERONE); //Prints the board
		press_enter(); //Clears screen
		system("cls");
		do
		{
			print_game_board(player_one_board, NUM_ROWS, NUM_COLUMNS, PLAYERONE); //Reprints board
			printf("Enter coordinates for Battleship:\n");
			direct = get_manual_direction(); //gets direction
			generate_start_manual(BATTLESHIP, direct, &x_begin, &y_begin); //new x and y
			occupied = prevent_overwrite(player_one_board, BATTLESHIP, direct, x_begin, y_begin); //checks to see if the x,y cell + ship length is occupied by another ship
			if (occupied == 0)
			{
				printf("\nDeploying HMS Infinite Loop - - - >\n\n"); //if not occupied, place the next ship
				place_ship(player_one_board, BATTLESHIP, direct, x_begin, y_begin, BAT);
				print_game_board(player_one_board, NUM_ROWS, NUM_COLUMNS, PLAYERONE);
				press_enter();
				system("cls");
			}
		} while (occupied != 0);
		do
		{
			print_game_board(player_one_board, NUM_ROWS, NUM_COLUMNS, PLAYERONE); //Repeat for Submarine
			printf("Enter coordinates for Submarine:\n");
			direct = get_manual_direction();
			
			generate_start_manual(SUBMARINE, direct, &x_begin, &y_begin);
			occupied = prevent_overwrite(player_one_board, SUBMARINE, direct, x_begin, y_begin);
			if (occupied == 0) 
			{
				printf("\nDeploying USNS Crash Code  - - - >\n\n");
				place_ship(player_one_board, SUBMARINE, direct, x_begin, y_begin, SUB); 
				print_game_board(player_one_board, NUM_ROWS, NUM_COLUMNS, PLAYERONE);
				press_enter();
				system("cls");
			}
		} while (occupied != 0);
		do
		{
			print_game_board(player_one_board, NUM_ROWS, NUM_COLUMNS, PLAYERONE); //Repeat for Destroyer
			printf("Enter coordinates for Destoyer:\n");
			direct = get_manual_direction();			
			generate_start_manual(DESTROYER, direct, &x_begin, &y_begin);
			occupied = prevent_overwrite(player_one_board, DESTROYER, direct, x_begin, y_begin);
			if (occupied == 0)
			{ 
				printf("\nDeploying HSwMS Undeclared - - - >\n\n");
				place_ship(player_one_board, DESTROYER, direct, x_begin, y_begin, DES);
				print_game_board(player_one_board, NUM_ROWS, NUM_COLUMNS, PLAYERONE);
				press_enter();
				system("cls");
			}
		} while (occupied != 0);
		do
		{
			print_game_board(player_one_board, NUM_ROWS, NUM_COLUMNS, PLAYERONE); //Repeat for Crusier
			printf("Enter coordinates for Crusier:\n");
			direct = get_manual_direction();			
			generate_start_manual(CRUSIER, direct, &x_begin, &y_begin);
			occupied = prevent_overwrite(player_one_board, CRUSIER, direct, x_begin, y_begin);
			if (occupied == 0)
			{ 
				printf("\nDeploying HSC Anvil - - - >\n\n");
				place_ship(player_one_board, CRUSIER, direct, x_begin, y_begin, CRU);
				print_game_board(player_one_board, NUM_ROWS, NUM_COLUMNS, PLAYERONE);
				press_enter();
				system("cls");
			}
		} while (occupied != 0);
	}
	else //placement == RANDOM
	{
		random = get_random_direction(); //Get random direction
		generate_start_random(CARRIER, random, NUM_ROWS, NUM_COLUMNS, &rx_begin, &ry_begin);
		place_ship(player_one_board, CARRIER, random, rx_begin, ry_begin, CAR);
		
		do
		{
			random = get_random_direction(); //Repeat for next ship
			generate_start_random(BATTLESHIP, random, NUM_ROWS, NUM_COLUMNS, &rx_begin, &ry_begin);
			occupied = prevent_overwrite(player_one_board, BATTLESHIP, random, rx_begin, ry_begin); //Checking for occupied cells
			if (occupied == 0)
			{
				place_ship(player_one_board, BATTLESHIP, random, rx_begin, ry_begin, BAT);				
			}
		} while (occupied != 0);

		do
		{
			random = get_random_direction();
			generate_start_random(SUBMARINE, random, NUM_ROWS, NUM_COLUMNS, &rx_begin, &ry_begin);
			occupied = prevent_overwrite(player_one_board, SUBMARINE, random, rx_begin, ry_begin);
			if (occupied == 0)
			{
				place_ship(player_one_board, SUBMARINE, random, rx_begin, ry_begin, SUB);				
			}
		} while (occupied != 0);

		do
		{
			random = get_random_direction();
			generate_start_random(DESTROYER, random, NUM_ROWS, NUM_COLUMNS, &rx_begin, &ry_begin);
			occupied = prevent_overwrite(player_one_board, DESTROYER, random, rx_begin, ry_begin);
			if (occupied == 0)
			{
				place_ship(player_one_board, DESTROYER, random, rx_begin, ry_begin, DES);				
			}
		} while (occupied != 0);

		do
		{
			random = get_random_direction();
			generate_start_random(CRUSIER, random, NUM_ROWS, NUM_COLUMNS, &rx_begin, &ry_begin);
			occupied = prevent_overwrite(player_one_board, CRUSIER, random, rx_begin, ry_begin);
			if (occupied == 0)
			{
				place_ship(player_one_board, CRUSIER, random, rx_begin, ry_begin, CRU);				
			}
		} while (occupied != 0);
	} //At this point, player one's ships are all placed either manually, or randomly

	
	//Computer placement - same as above for player - random.
	random = get_random_direction();
	generate_start_random(CARRIER, random, NUM_ROWS, NUM_COLUMNS, &rx_begin, &ry_begin);
	place_ship(computer_board, CARRIER, random, rx_begin, ry_begin, CAR);
	
	do
	{
		random = get_random_direction();
		generate_start_random(BATTLESHIP, random, NUM_ROWS, NUM_COLUMNS, &rx_begin, &ry_begin);
		occupied = prevent_overwrite(computer_board, BATTLESHIP, random, rx_begin, ry_begin);
		if (occupied == 0)
		{
			place_ship(computer_board, BATTLESHIP, random, rx_begin, ry_begin, BAT);			
		}
	} while (occupied != 0);

	do
	{
		random = get_random_direction();
		generate_start_random(SUBMARINE, random, NUM_ROWS, NUM_COLUMNS, &rx_begin, &ry_begin);
		occupied = prevent_overwrite(computer_board, SUBMARINE, random, rx_begin, ry_begin);
		if (occupied == 0)
		{
			place_ship(computer_board, SUBMARINE, random, rx_begin, ry_begin, SUB);			
		}
	} while (occupied != 0);

	do
	{
		random = get_random_direction();
		generate_start_random(DESTROYER, random, NUM_ROWS, NUM_COLUMNS, &rx_begin, &ry_begin);
		occupied = prevent_overwrite(computer_board, DESTROYER, random, rx_begin, ry_begin);
		if (occupied == 0)
		{
			place_ship(computer_board, DESTROYER, random, rx_begin, ry_begin, DES);			
		}
	} while (occupied != 0);

	do
	{
		random = get_random_direction();
		generate_start_random(CRUSIER, random, NUM_ROWS, NUM_COLUMNS, &rx_begin, &ry_begin);
		occupied = prevent_overwrite(computer_board, CRUSIER, random, rx_begin, ry_begin);
		if (occupied == 0)
		{
			place_ship(computer_board, CRUSIER, random, rx_begin, ry_begin, CRU);			
		}
	} while (occupied != 0);
	//Here, both the player and computer ships are placed. Clear the screen next and print the game screen for the user. 
	
	system("cls");
	printf("Your Waters:\n");
	print_game_board(player_one_board, NUM_ROWS, NUM_COLUMNS, PLAYERONE);
	printf("Enemy Waters:\n");
	print_game_board(computer_board, NUM_ROWS, NUM_COLUMNS, COMPUTER);
	printf("A random player will be selected to go first.\n");
	press_enter();

	
	current_player = select_who_starts(); //Randomly choose the first player

	while (p1_h_tracker < MAXHITS && cp_h_tracker < MAXHITS) //While both the hit trackers for the players is less than 17 (all ships sunk) repeat the loop
	{
		if (current_player == PLAYERONE)
		{
			printf("Player's turn: \n");
		}
		else //Computer
		{
			printf("Computer's turn: \n");
		}

		if (current_player == PLAYERONE) //While player one
		{
			do
			{
				fire_manual_shot(&shot_x, &shot_y); //Get shot coordinates manually
				hitormiss = check_shot(computer_board, shot_x, shot_y, &p1_h_tracker, &p1_m_tracker); //Check the shot for hit or miss or repeat if already fired in that location
			} while (hitormiss == -1);
			update_board(computer_board, shot_x, shot_y, hitormiss); //Change the symbol at the shot loction based on hit or miss		
			output_current_move(outfile, shot_x, shot_y, hitormiss, PLAYERONE); //Write move to the screen and the logfile
			check_sink(computer_board, outfile, &c_s, &b_s, &s_s, &d_s, &r_s); //Check for ship characters in the array, if none exist, a ship has sunk - looks at cpu board (enemy) here
			printf("Your Waters:\n");
			print_game_board(player_one_board, NUM_ROWS, NUM_COLUMNS, PLAYERONE); //Reprints the game screen
			printf("Enemy Waters:\n");
			print_game_board(computer_board, NUM_ROWS, NUM_COLUMNS, COMPUTER);

			
		}
		else //comptuer's turn
		{
			do
			{
				fire_random_shot(&shot_x, &shot_y); //gets a shot location randomly
				hitormiss = check_shot(player_one_board, shot_x, shot_y, &cp_h_tracker, &cp_m_tracker);	//checks the shot for hit, miss, or repeat			
			} while (hitormiss == -1);			
			update_board(player_one_board, shot_x, shot_y, hitormiss); //Updates the board - player ones this time (enemy)
			output_current_move(outfile, shot_x, shot_y, hitormiss, COMPUTER); //Write move to screen and logfile
			check_sink(player_one_board, outfile, &cp_s, &bp_s, &sp_s, &dp_s, &rp_s); //Checks for sinking of ships on the players board
		}
		current_player = !current_player; //Swaps players
		press_enter();	//Clears screen	
	}
	print_winner(p1_h_tracker, cp_h_tracker); //One the while loop breaks, compares which player had more hits, and prints the winnner
	output_stats(outfile, p1_h_tracker, p1_m_tracker, cp_h_tracker, cp_m_tracker); //Output end game stats of hits, misses, ratio & accuracy to the logfile.
	
}


