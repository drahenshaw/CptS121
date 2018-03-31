/*************************************************************************************************************************
/*Programmer: David Henshaw																								 *
*Class: CptS 121, Fall 2017, Leb Section 03																			     *
*Programming Assignment: PA7 - Poker 5 Hand Draw																		 *
*Date: November 17, 2017																								 *
*Description:  This program plays a game of five card draw poker in text format.										 *
*																														 *
*			   Utilizes srand and rand function to shuffle a deck of cards. Cards have a suit and face value, and		 *
*				are placed in a struct. A hand struct is used to store an array of five cards.							 *
*			   Players can discard up to three cards per turn to maximize their winning potential.						 *
*			   The program uses some basic artificial inteligence to compare the dealer's hand to the players.			 *
*				If the dealer's hand ranks higher, it plays conservatively. If behind, it's more willing to gamble.		 * 
*              																											 *
*              Inputs: Menu Options, Keyboard input																		 *
*              Constants: See Header File																			     *
*              Computations: Shuffling of cards requires several nested loops and modifications to prevent off by 1.     *
*              Outputs: Game printouts of current hands and analysis to the screen.								    	 *
*																													     *
*              This program provides some error checking for input validation.										     *
*              This program contains a custom header and a second source file for custom function definitions.			 *
*																														 *
**************************************************************************************************************************/

#include "poker.h"

int main(void)
{
	//Players
	char *player = "Player";
	char *dealr = "Dealer";
	Hand player_one = { {0} };
	Hand dealer = { {0} };
	//Scoring
	int player_one_rt = 0, dealer_rt = 0, tie = 0;
	int player_one_maintain[5] = { 0 }; //Cards kept array
	//Counters
	int card_count = 1, redraw = 0, round = 1;
	int pwins = 0, dwins = 0;
	int compare = 0;	
	/* initialize suit array */
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	/* initialize face array */
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };
	/* initalize deck array */
	int deck[4][13] = { 0 };
	srand((unsigned)time(NULL)); /* seed random-number generator */
	welcome_screen();
	do
	{
		card_count = 1; //reset card tracker
		redraw = 0; //reset number of cards to redraw
		press_enter(); //clear sceen
		reset_deck(deck); //set deck to 0's
		shuffle(deck); //shuffle the cards
		card_count = deal(deck, face, suit, &player_one, card_count, HAND); //deal 5 cards to player, update card counter
		card_count = deal(deck, face, suit, &dealer, card_count, HAND); //deal 5 cards to dealer
		bubble_sort(&player_one, HAND); //sort cards using bubble sort on face values
		bubble_sort(&dealer, HAND);
		print_legend(round); //print the string to integer legend
		print_hand(player_one, player); //print first player hand		
		redraw = number_to_redraw(); //ask user for number of cards to redraw
		if (redraw != 0)
		{
			redraw = redraw_cards(player_one_maintain, redraw, deck, face, suit, &player_one, card_count, redraw); //redraw specified number of cards
		}
		bubble_sort(&player_one, HAND);	//sort after redraw		
		print_hand(player_one, player);
		printf("\nFinal Hand. Press Enter to analyze hand.\n"); //press a key to move to analysis
		press_enter();
		print_legend(round);
		print_hand(player_one, player);
		player_one_rt = hand_analysis(player_one, player); //rank the hand (pairs..etc.)
		printf("Press Enter to challenge dealer.\n\n");		
		press_enter();
		dealer_rt = hand_analysis(dealer, dealr); //preliminary dealer scan
		system("cls");
		card_count = dealer_ai(dealer, dealer_rt, player_one_rt, deck, face, suit, &dealer, card_count); //use dealer ai to redraw cards, based on prelim analysis
		print_legend(round);
		print_hand(dealer, dealr);	//print final dealer hand	
		dealer_rt = hand_analysis(dealer, dealr); //rescan final hand
		printf("\nPlayer Hand Ranking: %d\tDealer Hand Ranking: %d\n\n", player_one_rt, dealer_rt); //Show the scores
		if ((dealer_rt == player_one_rt) && (contains_pair(player_one, HAND) && (contains_pair(dealer, HAND)))) //if both have a pair (most common tie)
		{
			 tie = pair_tie(player_one, dealer, &compare); //compare highest value at pair location
			 if (tie == 1)
			 {
				 printf("Player's high pair of %d is greater than dealer's pair.\n\n", compare);
				 print_hand(player_one, player);
			 }
			 else //tie == 0
			 {
				 printf("Dealer's high pair of %d is greater than player's pair.\n\n", compare);
				 print_hand(player_one, player);
			 }
		}
		else //if no pair is present, use the tiebreaker function to just search for the high card. 
		{
			tie = tiebreaker(player_one_rt, dealer_rt, player_one, dealer);
			print_hand(player_one, player);
		}
		print_winner(tie, &pwins, &dwins); //print the winner of the round, and update # of wins for each player	
		round++; //up the round
		reset_maintain(player_one_maintain); //reset the cards to keep array
		
	} while (round < FINALROUND); //loop until round 10 is over
	system("cls"); 
	final_winner(pwins, dwins); //print who won the most rounds
	return 0;
}