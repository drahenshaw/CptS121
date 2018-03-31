/**************************************************************************************************************
*Programmer: David Henshaw																					  *
*Class: CptS 121, Fall 2017, Lab Section 03																      *
*Programming Assignment: PA6 - Battleship																	  *
*Date: November 6, 2017																						  *
*Description: Header file for PA6 including both standard libraries and custom function declarations          *
***************************************************************************************************************/

//Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//#Define Constants
#define NUM_ROWS 10
#define NUM_COLUMNS 10
#define MANUAL 1
#define RANDOM 2
#define CARRIER 5
#define BATTLESHIP 4
#define SUBMARINE 3
#define DESTROYER 3
#define CRUSIER 2
#define PLAYERONE 0
#define COMPUTER 1
#define MAXHITS 17

typedef enum Dir //Dir for Vertical or Horizontal selection
{
	VERTICAL, HORIZONTAL
}Dir;

typedef enum Ship //Ship to enumerate the different ship types
{
	CAR, BAT, SUB, DES, CRU
}Ship;

//Dir Return
Dir get_random_direction(void);
Dir get_manual_direction(void);

//Void Return
void welcome_screen(void);
void press_enter(void);
void initialize_rand(void);
void initialize_game_board(char board[][NUM_COLUMNS], int rows, int cols);
void initialize_comp_board(char board[][NUM_COLUMNS], int rows, int cols);
void print_game_board(char board[][NUM_COLUMNS], int rows, int cols, int player);
void display_menu(void);
void fire_manual_shot(int *x, int *y);
void update_board(char board[][NUM_COLUMNS], int  x, int y, int hitmiss);
void check_sink(char board[][NUM_COLUMNS], FILE *outfile, int *cs, int *bs, int *ss, int *ds, int *rs);
void fire_random_shot(int *x, int *y);
void generate_start_manual(int ship_length, Dir direction, int *x_start, int *y_start);
void generate_start_random(int ship_length, Dir direction, int rows, int cols, int *x_start, int *y_start);
void place_ship(char board[][NUM_COLUMNS], int ship_length, Dir direction, int x_start, int y_start, Ship ship);
void output_current_move(FILE *outfile, int x, int y, int hitmiss, int player);
void output_stats(FILE *outfile, int hit, int miss, int chit, int cmiss);
void print_winner(int p1hits, int cpuhits);

//Integer Return
int prevent_overwrite(char board[][NUM_COLUMNS], int ship_length, Dir direction, int x_start, int y_start);
int check_shot(char board[][NUM_COLUMNS], int x, int y, int *htracker, int * mtracker);
int menu_input(void);
int ship_placement_menu(void);
int select_who_starts(void);