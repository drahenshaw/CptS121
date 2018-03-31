/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 121, Fall 2017, Lab Section 03																										       *
*Programming Assignment: PA6 - Battleship																											   *
*Date: November 6, 2017																																   *
*Description: battleship.c source file contains the function descriptions for text based battleship game								               *
********************************************************************************************************************************************************/

#include "battleship.h"

/*******************************************************************************
* Function: welcome_screen                                                     *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Prints the rules of Battleship					               *
* Input parameters: void					                                   *
* Returns: void									                               *
* Preconditions: running program											   *
* Postconditions: void									                       *
********************************************************************************/
void welcome_screen(void)
{
	printf("* * * * * * * * * * * * * * * * * * * *WELCOME TO BATTLESHIP* * * * * * * * * * * * * * * * * * * *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("* * * * * * * * * * * ** * * * *  * * * RULES OF BATTLESHIP * * * * * * * * * * * * * * * * * * * *\n");
	putchar('\n');
	printf("Battleship is a player vs player Naval warship game where the objective is to sink the enemy fleet.\n");
	printf("Each fleet consists of five ships, Carrier, Battleship, Submarine, Destroyer, and Crusier.\n");
	printf("Each ship occupies the following number of cells on a 10 x 10 game board:\n");
	printf(" 1. Carrier - 5\n 2. Battleship - 4\n 3. Submarine - 3\n 4. Destroyer - 3\n 5. Crusier - 2\n\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\nThe player fires shot at a (x,y) location to try and hit the enemy ships.\n");
	printf("Hits and misses are marked on the game board.\n");
	printf("When all cells of a ship are hit, the ship sinks. The player to sink all five ships first wins!\n\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\nThe player whose turn is first is selected at random. Ships may be placed randomly or manually.\n");
	printf("Ships may only be placed vertically or horizontally, not diagonally.\n\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
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
* Function: initialize_game_board                                              *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Initializes 2D player gameboard array with water symbols        *
* Input parameters: 2D array, number of rows and columns                       *
* Returns: void									                               *
* Preconditions: running program, created 2D array, #rows, #cols to match 	   *
* Postconditions: 2D array initialized with default values                     *
********************************************************************************/
void initialize_game_board(char board[][NUM_COLUMNS], int rows, int cols)
{
	int i = 0, j = 0;

	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < cols; ++j)
		{
			board[i][j] = '~';
		}
	}
}

/*******************************************************************************
* Function: initialize_comp_board                                              *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Initializes 2D computer gameboard array with dash symbols       *
* Input parameters: 2D array, number of rows and columns                       *
* Returns: void									                               *
* Preconditions: running program, created 2D array, #rows, #cols to match 	   *
* Postconditions: 2D array initialized with default values                     *
********************************************************************************/
void initialize_comp_board(char board[][NUM_COLUMNS], int rows, int cols)
{
	int i = 0, j = 0;

	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < cols; ++j)
		{
			board[i][j] = '-';
		}
	}
}

/*******************************************************************************
* Function: print_game_board	                                               *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Prints the game screen with indexing						       *
* Input parameters: 2D array, number of rows and columns, player               *
* Returns: void									                               *
* Preconditions: created 2D array, #rows, #cols to match, player or cpu		   *
* Postconditions: 2D array initialized with default values                     *
********************************************************************************/
void print_game_board(char board[][NUM_COLUMNS], int rows, int cols, int player)
{
	int i = 0, j = 0;
	printf("Row:\n");
	for (i = 0; i < rows; ++i)
	{	
		printf("%d.\t", i); //Row indexing
		for (j = 0; j < cols; ++j)
		{
			if (player == COMPUTER) //If player is the computer, letters should not be shown.
			{
				if (board[i][j] == 'c' || board[i][j] == 'b' || board[i][j] == 's' || board[i][j] == 'd' || board[i][j] == 'r')
				{
					printf("%c ", '-'); //Draws a dash instead to hide the ships from the player
				}
				else
				{
					printf("%c ", board[i][j]);
				}
			}
			else
			{
				printf("%c ", board[i][j]); //If player one, then just print the characters normally
			}
		}
		putchar('\n');
	}
	putchar('\n');
	printf("Col:    0.1.2.3.4.5.6.7.8.9.\n\n"); //Column indexing 
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
	printf("1. Place Fleet Manually?\n");
	printf("2. Place Ships Randomly?\n");	
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
* Function: ship_placement_menu (modified Yahtzee menu)                        *
* Date Created: October 5, 2017												   *
* Date Last Modified: October 31, 2017                                         *
* Description: Combines display_menu and menu_input to prompt and validate	   *
*				user input to pick which menu option to run, 1 - 2             *
* Input parameters: void					                                   *
* Returns: Menu option chosen					                               *
* Preconditions: running program, subfunctions compiled						   *
* Postconditions: returns option, MANUAL or RANDOM		                       *
********************************************************************************/
int ship_placement_menu(void)
{
	int option = 0;
	do //Repeats when input is not in the integer range of 1 - 2
	{
		display_menu();
		option = menu_input();
		system("cls");
	} while (option < MANUAL || option > RANDOM);
	return option;
}

/*******************************************************************************
* Function: get_random_direction                                               *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Gets a random direction, horizontal or vertical			       *
* Input parameters: void										               *
* Returns: Dir direction						                               *
* Preconditions: typecast of enumerated type Dir							   *
* Postconditions: VERTICAL or HORIZONTAL randomly		                       *
********************************************************************************/
Dir get_random_direction(void)
{
	Dir direction = VERTICAL; //enumerated type Dir

	direction = rand() % 2;
	return direction;
}

/*******************************************************************************
* Function: get_manual_direction                                               *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Gets a manual direction, horizontal or vertical			       *
* Input parameters: void, user input							               *
* Returns: Dir direction						                               *
* Preconditions: typecast of enumerated type Dir							   *
* Postconditions: VERTICAL or HORIZONTAL randomly		                       *
********************************************************************************/
Dir get_manual_direction(void)
{
	Dir direction = VERTICAL;
	
	do
	{
		printf("Choose a direction:\n0.Vertical\t1.Horizontal\n");
		scanf("%d", &direction);
	} while (direction < VERTICAL || direction > HORIZONTAL);
	return direction;
}

/*******************************************************************************
* Function: generate_start_random                                              *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Generates the starting point for ship placement, within bounds  *
* Input parameters: ship length, direction, rows/cols, pointer to x,y start    *
* Returns: Output parameters to x,y location within game board                 *
* Preconditions: typecast of enumerated type Dir, pointer declaration, inputs  *
* Postconditions: Valid x and y location generated randomly                    *
********************************************************************************/
void generate_start_random(int ship_length, Dir direction, int rows, int cols, int *x_start, int *y_start)
{
	if (direction == HORIZONTAL) 
	{
		*x_start = rand() % rows; // 0 - 9
		*y_start = rand() % (cols - ship_length + 1); //Number of cols - length of the ship + 1 to keep inside the array when placing horizontally
	}
	else // VERTICAL
	{
		*x_start = rand() % (rows - ship_length + 1); //Number of rows - length of the ship +1 to keep inside the array when placing vertically
		*y_start = rand() % cols; // 0 - 9
	}
}

/*******************************************************************************
* Function: generate_start_manual                                              *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Generates the starting point for ship placement, within bounds  *
* Input parameters: ship length, direction, pointer to x,y start			   *
* Returns: Output parameters to x,y location within game board                 *
* Preconditions: typecast of enumerated type Dir, pointer declaration, inputs  *
* Postconditions: Valid x and y location generated manually                    *
********************************************************************************/
void generate_start_manual(int ship_length, Dir direction, int *x_start, int *y_start)
{
	int x = 0, y = 0, flag = 0;

	if (direction == VERTICAL)
	{
		do
		{
			flag = 0;
			printf("Choose starting row to place ship: "); //Get row
			scanf("%d", &x);
			printf("Choose starting column to place ship: "); //Get col
			scanf("%d", &y);

			if ((x + ship_length - 1) > NUM_ROWS || y > 9 || x < 0 || y < 0) //If ship length + row is out of bounds....
			{
				printf("Invalid ship placement: ship must be inbounds.\n"); //invalid placement, asks again
				printf("Please try again!\n");
				flag = 1;
			}
		} while (flag == 1); //Until flag remains 0 (valid placement) repeat the loop
	}

	if (direction == HORIZONTAL)
	{
		do
		{
			flag = 0;
			printf("Choose starting row to place ship: ");
			scanf("%d", &x);
			printf("Choose starting column to place ship: ");
			scanf("%d", &y);

			if ((y + ship_length - 1) > NUM_COLUMNS || x > 9 || x < 0 || y < 0) //IF ship length + col is out of bounds
			{
				printf("Invalid ship placement: ship must be inbounds.\n"); //Invalid placement
				printf("Please try again!\n");
				flag = 1;
			}
		} while (flag == 1); //Until flag remains 0, repeat
	}

	*x_start = x; //Output parameters to valid x and y starting point
	*y_start = y;
}

/*******************************************************************************
* Function: place_ship			                                               *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Places the ship on the game board							   *
* Input parameters: ship length, direction, x,y start, type of ship placed     *
* Returns: void												                   *
* Preconditions: typecast of enumerated type Dir, x, y, Ship type declared	   *
* Postconditions: Game board array modified with ship location                 *
********************************************************************************/
void place_ship(char board[][NUM_COLUMNS], int ship_length, Dir direction, int x_start, int y_start, Ship ship)
{
	int i = x_start, j = y_start; //Start index at the starting location of the ship

	if (direction == VERTICAL) //Check for direction
	{
		for (i = x_start; i < (ship_length + x_start); ++i) //Start at x starting location, iterate the rest of the ship length
		{
			switch (ship) //Decide which ship is being placed
			{
			case CAR: board[i][j] = 'c'; //Carrier
				break;
			case BAT: board[i][j] = 'b'; //Battleship
				break;
			case SUB: board[i][j] = 's'; //Submarine
				break;
			case DES: board[i][j] = 'd'; //Destroyer
				break;
			case CRU: board[i][j] = 'r'; //Crusier
				break;
			}
		}
	}
	else //horizontal
	{
		for (j = y_start; j < (ship_length + y_start); ++j) //Start at y location, iterate through the rest of ship length
		{
			switch (ship) //Which ship is being placed
			{
			case CAR: board[i][j] = 'c'; //Place appropriate characters
				break;
			case BAT: board[i][j] = 'b';
				break;
			case SUB: board[i][j] = 's';
				break;
			case DES: board[i][j] = 'd';
				break;
			case CRU: board[i][j] = 'r';
				break;
			}
		}
	}
	
}

/*******************************************************************************
* Function: prevent_overwrite	                                               *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Makes sure ship placement does not overlap					   *
* Input parameters: ship length, direction, rows/cols, x,y start		       *
* Returns: integer 1 for invalid placement, 0 for valid placement              *
* Preconditions: typecast of enumerated type Dir, pointer declaration, inputs  *
* Postconditions: Integer for in/valid placement of the ship                   *
********************************************************************************/
int prevent_overwrite(char board[][NUM_COLUMNS], int ship_length, Dir direction, int x_start, int y_start)
{
	int i = x_start, j = y_start;	
	
	if (direction == VERTICAL)
		{
			for (i = x_start; i < (x_start + ship_length); i += 1) //Start at x, iterate through the rest of the ship length
			{
				if (board[i][y_start] != '~' && board[i][y_start] == '-') //If the board is not water for player one, or dash for computer...
				{
					printf("Space already occupied, please try again\n"); //...try again, return 1
					return 1;
				}
			}
		}
	else //HORIZONTAL
		{
			for (j = y_start; j < (y_start + ship_length); ++j) //Start at y, iterate through length
			{
				if (board[x_start][j] != '~' && board[x_start][j] != '-')
				{
					printf("Space already occupied, please try again\n");
					return 1;
				}
			}
		}
	return 0;
}

/*******************************************************************************
* Function: select_who_starts	                                               *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Randomly choose if player one or cpu fires shots first		   *
* Input parameters: void												       *
* Returns: int of player chosen, 0 or 1						                   *
* Preconditions: #define constant, random generation						   *
* Postconditions: returns starting player, 0 if player, 1 if cpu               *
********************************************************************************/
int select_who_starts(void)
{
	int player = PLAYERONE;
	player = rand() % 2;
	return player;
}

/*******************************************************************************
* Function: fire_manual_shot	                                               *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Fires a shot at x,y coordinate, makes sure its inbounds		   *
* Input parameters: void													   *
* Returns: Output parameters to x,y location within game board                 *
* Preconditions: pointer declaration										   *
* Postconditions: Valid x,y shot coordinates selected manually                 *
********************************************************************************/
void fire_manual_shot(int *x, int *y)
{
	int tx = 0, ty = 0;
	char comma = ',';
	do
	{
		printf("Enter target coordinates (x,y): "); //Asks for (x,y) formatted input, including the comma
		scanf("%d%c%d", &tx, &comma, &ty);
	} while (tx < 0 || tx > 9 || ty < 0 || ty > 9 || comma != ','); //If x or y are negative or >9, repeat, or if symbol is not a comma separating the values
	*x = tx; //Output parameters to x and y location to shoot
	*y = ty;
}

/*******************************************************************************
* Function: fire_random_shot	                                               *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Fires a shot at x,y coordinate, makes sure its inbounds, random *
* Input parameters: ship length, direction, rows/cols, pointer to x,y start    *
* Returns: Output parameters to x,y location within game board                 *
* Preconditions: pointer declaration										   *
* Postconditions: Valid x,y shot coordinates selected randomly                 *
********************************************************************************/
void fire_random_shot(int *x, int *y)
{
	*x = rand() % 10; //0 - 9 Output parameters
	*y = rand() % 10; //0 - 9
}

/*******************************************************************************
* Function: check_shot			                                               *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Checks shot for hit/miss or repeated shot					   *
* Input parameters: 2D game board, (x,y) shot location						   *
* Returns: Output parameters to hit/miss trackers, return int for shot type    *
* Preconditions: Game board placed with ships								   *
* Postconditions: Valid x,y shot coordinates selected manually                 *
********************************************************************************/
int check_shot(char board[][NUM_COLUMNS], int x, int y, int *htracker, int *mtracker)
{
	if (board[x][y] == '~' || board[x][y] == '-') //Checks board for defaul characters
	{
		printf("Miss: (%d, %d)\n", x, y);
		*mtracker += 1; //Update miss tracker
		return 0; //Returns 0 if shot is a miss
	}
	else if (board[x][y] == 'c' || board[x][y] == 'b' || board[x][y] == 's' || board[x][y] == 'd' || board[x][y] == 'r') //Checks board for ship characters
	{
		printf("Hit!: (%d, %d)\n", x, y); 
		*htracker += 1; //Update hit tracker
		return 1; //Returns 1 if hit
	}
	else if (board[x][y] == '*' || board[x][y] == 'm') //Checks for shot token, returns -1 if location already used
	{
		printf("Shot already fired at this location\n");
		return -1;
	}
}

/*******************************************************************************
* Function: update_board		                                               *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Updates board with shot characters * for hit, m for miss		   *
* Input parameters: 2D game board, (x,y) shot location, hitormiss indicator	   *
* Returns: void																   *
* Preconditions: Game board placed with ships, fire location selected		   *
* Postconditions: Updated game board with shot character	                   *
********************************************************************************/
void update_board(char board[][NUM_COLUMNS], int  x, int y, int hitmiss)
{
	if (hitmiss == 0)
	{
		board[x][y] = 'm';
	}
	else if (hitmiss == 1)
	{
		board[x][y] = '*';
	}
}

/*******************************************************************************
* Function: check_sink			                                               *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Checks for if a ship sinks									   *
* Input parameters: Outfile for writing, pointers to ship trackers, game board *
* Returns: Output parameters to ship trackers								   *
* Preconditions: Game board placed with ships, shot chosen and fired		   *
* Postconditions: Updates ship trackers, prints to outfile if ship sinks       *
********************************************************************************/
void check_sink(char board[][NUM_COLUMNS], FILE *outfile, int *cs, int *bs, int *ss, int *ds, int *rs)
{
	int i = 0, j = 0; //Index variables
	int c = 0, b = 0, s = 0, d = 0, r = 0;	//Ship flags
	
	
	for (i = 0; i < NUM_ROWS; ++i)
	{
		for (j = 0; j < NUM_COLUMNS; ++j) //Iterated through the 2D array
		{
			if (board[i][j] == 'c') //If the associated ship character is anywhere on the array, the flag is set to 1
			{
				c = 1;
			}
			else if (board[i][j] == 'b')
			{
				b = 1;
			}
			else if (board[i][j] == 's')
			{
				s = 1;
			}
			else if (board[i][j] == 'd')
			{
				d = 1;
			}
			else if (board[i][j] == 'r')
			{
				r = 1;
			}
		}
	}
	if (c == 0 && *cs == 0) //After checking the array, if the ship flag and the sunk_trackers are both 0...
	{
		printf("Carrier Sunk\n");
		fprintf(outfile, "Carrier Sunk!\n"); //Print to screen and file that the ship has sunk
		*cs = 1;							 //Set the tracker to 1 to prevent repeating the print statement every turn after the ship has sunk
	}
	if (b == 0 && *bs == 0)
	{
		printf("Battleship Sunk\n");
		fprintf(outfile, "Battleship Sunk!\n");
		*bs = 1;
	}
	if (s == 0 && *ss == 0)
	{
		printf("Submarine Sunk\n");
		fprintf(outfile, "Submarine Sunk!\n");
		*ss = 1;
	}
	if (d == 0 && *ds == 0)
	{
		printf("Destroyer Sunk\n");
		fprintf(outfile, "Destroyer Sunk!\n");
		*ds = 1;
	}
	if (r == 0 && *rs == 0)
	{
		printf("Crusier Sunk\n");
		fprintf(outfile, "Crusier Sunk!\n");
		*rs = 1;
	}
	
}

/*******************************************************************************
* Function: output_current_move	                                               *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Prints shot location, player, and hit or miss to logfile		   *
* Input parameters: outfile, (x,y) shot location, player					   *
* Returns: void																   *
* Preconditions: Shot fired and checked, outfile open						   *
* Postconditions: Current move written to outfile(.log)		                   *
********************************************************************************/
void output_current_move(FILE *outfile, int x, int y, int hitmiss, int player)
{
	if (hitmiss == 1)
	{
		fprintf(outfile, "Player %d: (%d, %d) ""Hit""\n", player, x, y);
	}
	else fprintf(outfile, "Player %d: (%d, %d) ""Miss""\n", player, x, y);
}

/*******************************************************************************
* Function: output_stats		                                               *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Prints hits, misses, shots, accuracy, hit/miss ration to outfile*
* Input parameters: outfile, hits, misses, cpu hits/misses					   *
* Returns: Output parameters to hit/miss trackers, return int for shot type    *
* Preconditions: Game board placed with ships								   *
* Postconditions: Valid x,y shot coordinates selected manually                 *
********************************************************************************/
void output_stats(FILE *outfile, int hit, int miss, int chit, int cmiss)
{
	int n_hits = hit; //Set local variables to input parameters for player
	int n_miss = miss;
	int c_hits = chit; //Computer
	int c_miss = cmiss;

	int total = 0;
	

	double ratio = 0;
	double accuracy = 0;

	//Player One
	total = n_hits + n_miss;
	if (n_miss != 0 && total != 0) //Protect from diving by 0
	{
		ratio = (n_hits / n_miss) * 100;
		accuracy = (n_hits / total) * 100;
	}

	fprintf(outfile, "\n*** Player 0 Stats ***\n"); //Output stats
	fprintf(outfile, "Number Hits: %d\n", n_hits);
	fprintf(outfile, "Number Misses: %d\n", n_miss);
	fprintf(outfile, "Hit/Miss Ratio: %lf\n", ratio);
	fprintf(outfile, "Accuracy: %lf\n", accuracy);

	//Computer
	total = c_hits + c_miss;
	if (c_miss != 0 && total != 0) //Protect from div by 0
	{
		ratio = (c_hits / c_miss) * 100;
		accuracy = (c_hits / total) * 100;
	}

	fprintf(outfile, "\n*** Computer Stats ***\n"); //Output stats
	fprintf(outfile, "Number Hits: %d\n", c_hits);
	fprintf(outfile, "Number Misses: %d\n", c_miss);
	fprintf(outfile, "Hit/Miss Ratio: %lf\n", ratio);
	fprintf(outfile, "Accuracy: %lf\n", accuracy);

}

/*******************************************************************************
* Function: print_winner                                                       *
* Date Created: October 16, 2017											   *
* Date Last Modified: November 1, 2017                                         *
* Description: Compares hits for player 1 and computer and prints winner       *
* Input parameters: player hits, cpu hits		                               *
* Returns: void									                               *
* Preconditions: One player should reach 17 hits							   *
* Postconditions: print winner output to screen				                   *
********************************************************************************/
void print_winner(int p1hits, int cpuhits)
{
	if (p1hits > cpuhits)
	{
		printf("\nPlayer WINS!\n");
		printf("Enemy Fleet Has Been Sunk!\n");
		printf("See battleship.log for detailed statistics.\n");
	}
	else
	{
		printf("Computer WINS!\n");
		printf("Your Fleet Has Been Sunk!");
	}
}
/**********************************************************************************************************************************************************************************************************************/
/**********************************************************************************************************************************************************************************************************************/
