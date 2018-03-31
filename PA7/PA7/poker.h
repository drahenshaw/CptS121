/**************************************************************************************************************
*Programmer: David Henshaw																					  *
*Class: CptS 121, Fall 2017, Lab Section 03																      *
*Programming Assignment: PA7 - Poker Five Card Draw															  *
*Date: November 17, 2017																					  *
*Description: Header file for PA7 including both standard libraries and custom function declarations          *
***************************************************************************************************************/

#ifndef POKER
#define POKER

//Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//#define Consants
#define MAXREDRAW 3
#define HAND 5
#define SUITS 4
#define FACES 13
#define FINALROUND 11

//Custom Structs
typedef struct card 
{
	int suit;
	int face;
}Card;
typedef struct hand
{
	Card hand[HAND];
}Hand;

//Custom enumerated types
typedef enum bool
{
	false, true,
}Bool;

//Void Returns
void welcome_screen(void);
void print_legend(int round);
void press_enter(void);
void shuffle(int wDeck[][13]);
void reset_deck(int wDeck[][FACES]);
void reset_maintain(int maintainence[]);
void print_hand(Hand playerhand, char *player);
void bubble_sort(Hand *hand, int n);
void print_winner(int result, int *pwins, int *dwins);
void final_winner(int pwins, int dwins);

//Interger Returns
int deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Hand *playerhand, int start_card, int cardstodeal);
int redraw_cards(int maintain[], int redraw, const int wDeck[][13], const char *wFace[], const char *wSuit[], Hand *playerhand, int start_card, int cardstodeal);
int dealer_ai(Hand dealr, int dealr_rt, int playr_rt, const int wDeck[][13], const char *wFace[], const char *wSuit[], Hand *playerhand, int start_card);
int hand_analysis(Hand final_hand, char *player);
int pair_tie(Hand playerhand, Hand dealerhand, int * ptr);
int tiebreaker(int p1, int dealer, Hand player, Hand dealr);
int number_to_redraw(void);

//Bool Returns
Bool contains_pair(Hand hand, int n);
Bool contains_two_pair(Hand hand, int n);
Bool contains_threeKind(Hand hand, int n);
Bool contains_Straight(Hand hand, int n);
Bool contains_Flush(Hand hand, int n);
#endif 
