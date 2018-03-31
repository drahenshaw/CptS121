/**************************************************************************************************************
*Programmer: David Henshaw																					  *
*Class: CptS 121, Fall 2017, Lab Section 03																      *
*Programming Assignment: PA5 - Yahtzee																		  *
*Date: October 20, 2017																						  *
*Description: Header file for PA5 including both standard libraries and custom function declarations          *
***************************************************************************************************************/

#ifndef YAHTZEE_HEADER
#define YAHTZEE_HEADER

//Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//General Constants
#define PLAYER_ONE 0
#define PLAYER_TWO 1
#define FIVEDICE 5
#define COUNTER 7
#define COMBOS 13
#define TOTAL_ROUNDS 27

//Upper Bonus
#define UPPER 6
#define UPPERLIMIT 63
#define UPPERBONUS 35

//Combinations
#define SUMOFONES 1
#define SUMOFTWOS 2
#define SUMOFTHREES 3
#define SUMOFFOURS 4
#define SUMOFFIVES 5
#define SUMOFSIXES 6
#define THREEOFAKIND 7
#define FOUROFAKIND 8
#define FULLHOUSE 9
#define SMALLSTRAIGHT 10
#define LARGESTRAIGHT 11
#define YAHTZEE 12
#define CHANCE 13

//Functions

//Void Return
void Play_Yahtzee(void);
void Yahtzee_rules(void);
void display_menu(void);
void initialize_rand(void);
void press_enter(void);
void Yahtzee_dice_roll(int dice[], int size);
void initialize_scorecombos(int array[], int size);
void print_combinations(void);
void check_combination(int array[], int *selection);
void reinitialize_dice_counter(int array[], int size);
void score_category(int dice_array[], int count_array[], int choice, int score_array[], int combo_array[]);
void print_winner(int p1_score, int p2_score);
void upper_section(int score_array[], int *score);

//Integer Return
int choose_combination(void);
int get_combination(void);
int reroll_dice(int array[], int size); //Not Used
int check_for_reroll(void);
int execute_reroll(int reroll, int array[], int size, int *count); //Not Used
int sumofones(int array[], int counter[]);
int sumoftwos(int array[], int counter[]);
int sumofthrees(int array[], int counter[]);
int sumoffours(int array[], int counter[]);
int sumoffives(int array[], int counter[]);
int sumofsixes(int array[], int counter[]);
int threeofakind(int array[], int counter[]);
int fourofakind(int array[], int counter[]);
int yahtzee(int array[], int counter[]);
int fullhouse(int array[], int counter[]);
int smallstraight(int array[], int counter[]);
int largestraight(int array[], int counter[]);
int chance(int array[], int counter[]);
int menu_input(void);
int sum_points(int score_array[]);
int dice_reroll(int reroll, int dice[], int size, int *count);

#endif