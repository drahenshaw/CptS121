/**************************************************************************************************************
*Programmer: David Henshaw																					  *
*Class: CptS 121, Fall 2017, Lab Section 03																      *
*Programming Assignment: PA4 - Craps																		  *
*Date: October 6, 2017																						  *
*Description: Header file for PA4 including both standard libraries and custom function declarations          *
***************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Void type functions:
void print_game_rules(void);
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);
void initialize_rand(void); //Seeds srand
void display_menu(void);
void test_play(void); //Function that plays through craps and can repeat

int menu_input(void);
int menu_option(void);
int play_craps(void); //Asks the user to play again
int check_balance(double bank_balance);


int check_wager_amount(double wager, double balance);
int roll_die(void); //Rolls dice rand 1 - 6
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice); //Calculates win or loss on first roll
int is_point_loss_or_neither(int sum_dice, int point_value); //Calculates win or loss on subseqent rolls

double get_bank_balance(void); //Initialized bank balace
double get_wager_amount(void); //Gets wager from user before each round
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract); //Adds or subtracts current wager based on win or loss
double validate_wager(double balance); //Combines get_wager_amount and check_wager_amount to make sure wager !> balance and re-asks if it is. 


