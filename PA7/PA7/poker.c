/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 121, Fall 2017, Lab Section 03																										       *
*Programming Assignment: PA7 - Poker Five Card Draw																									   *
*Date: November 17, 2017																															   *
*Description: poker.c source file contains the function descriptions for text based battleship game										               *
********************************************************************************************************************************************************/

#include "poker.h"


/*******************************************************************************
* Function: shuffle		                                                       *
* Date Created: GIVEN - TEXTBOOK H&J										   *
* Date Last Modified: November 6, 2017                                         *
* Description: Shuffles a deck of 52 cards						               *
* Input parameters: 2D deck array for suit and face values                     *
* Returns: void									                               *
* Preconditions: running program											   *
* Postconditions: 2D array populated with card numbers randomly                *
********************************************************************************/
void shuffle(int wDeck[][13]) /* shuffle cards in deck */
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/*******************************************************************************
* Function: deal		                                                       *
* Date Created: GIVEN - TEXTBOOK H&J - Modified by D.Henshaw				   *
* Date Last Modified: November 17, 2017                                        *
* Description: Loops through deck of cards, finds card number and prints it    *
*			   with associated face and suit strings.						   *
* Input parameters: 2D deck array for suit and face values, Hand of cards      *
*					starting card, number of cards to deal next				   *
* Returns: integer to track card in the deck	                               *
* Preconditions: running program											   *
* Postconditions: 2D array populated with card numbers randomly                *
********************************************************************************/
int deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Hand *playerhand, int start_card, int cardstodeal)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* deal each of the 52 cards */
	for (card = start_card; card < start_card + cardstodeal; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row < SUITS; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column < FACES; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					//printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					playerhand->hand[card - start_card].suit = row;
					playerhand->hand[card - start_card].face = column + 1;	//Assign face and suit to the Hand struct
				}
			}
		}	
	}
	return start_card + cardstodeal; //Update the current card
}

/*******************************************************************************
* Function: welcome_screen                                                     *
* Date Created: November 1, 2017											   *
* Date Last Modified: November 6, 2017                                         *
* Description: Prints the rules of Poker						               *
* Input parameters: void					                                   *
* Returns: void									                               *
* Preconditions: running program											   *
* Postconditions: void									                       *
********************************************************************************/
void welcome_screen(void)
{
	printf("* * * * * * * * * * WELCOME TO 5 CARD DRAW POKER * * * * * * * * * *\n\n");
	printf("The player is dealt five cards, face down, followed by the dealer.\n");
	printf("Players may discard up to three cards from their initial hand, to be replaced by cards from the remaining deck.\n");
	printf("Once each player has 5 cards again, the winner is the player with the best hand. Ties go to the house.\n");
	printf("The game of poker will finish after ten rounds.\n\n");
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
* Function: number_to_redraw                                                   *
* Date Created: November 6, 2017											   *
* Date Last Modified: November 9, 2017                                         *
* Description: Asks user for an option within 0 - 3							   *
* Input parameters: void					                                   *
* Returns: option chosen						                               *
* Preconditions: program started											   *
* Postconditions: option obtained with input validation	                       *
********************************************************************************/
int number_to_redraw(void)
{
	int num = 0;
	do
	{
		printf("\nHow many cards do you want to discard (0 - 3)?: ");
		scanf("%d", &num);
	} while (num < 0 || num > 3);
	putchar('\n');
	return num;
}

/*******************************************************************************
* Function: redraw_cards                                                       *
* Date Created: November 11, 2017											   *
* Date Last Modified: November 17, 2017                                        *
* Description: Asks which cards to discard from hand w/ input validation.	   *
*			   Redraws specified number of cards after discard.				   *
* Input parameters: 2D deck array for suit and face values, Hand of cards      *
*					starting card, number of cards to deal next, discard array *
* Returns: integer to track card in the deck	                               *
* Preconditions: running program, all arrays initialized, need # of cards      *
* Postconditions: card counter updated, Hand updated with fresh cards          *
********************************************************************************/
int redraw_cards(int maintain[], int redraw, const int wDeck[][13], const char *wFace[], const char *wSuit[], Hand *playerhand, int start_card, int cardstodeal)
{
	int i = 0;
	int temp = 0;
	int card = start_card;
	int row = 0;
	int column = 0;
	
	printf("Which cards (1 - 5) do you want to discard?: ");
	for (i = 0; i < redraw; ++i) //Do as many redraws as necessary
	{
		do
		{
			scanf("%d", &temp); //If i want to discard card 1, index[0]...card 5, index[4]..etc.
			if (temp < 1 || temp > 5)
			{
				printf("Selection must be with hand. Try again.\n");
			}

		} while (temp < 1 || temp > 5);
		maintain[temp - 1] = temp; //Discard array[5] sets a positive value.
	}	
	//redraw from deck - pass return from deal to redraw to main. 	
	for (i = 0; i < HAND; ++i) //Counter: maintain[i] has a non-zero value, user wants to discard. redraw card from deck. 
		{
			if (maintain[i] != 0) //if the discard array has a +value, user wants to discard that card.
			{				
				/* loop through rows of wDeck */
				for (row = 0; row < SUITS; row++)
				{
					/* loop through columns of wDeck for current row */
					for (column = 0; column < FACES; column++)
					{
						/* if slot contains current card, display card */
						if (wDeck[row][column] == card)
						{
							//printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
							playerhand->hand[i].suit = row;
							playerhand->hand[i].face = column + 1; //modified deal function but with discard array												
						}
					}
				}
				card++;
			}
		}
	return card;
}

/*******************************************************************************
* Function: print_legend                                                       *
* Date Created: November 17, 2017											   *
* Date Last Modified: November 17, 2017                                        *
* Description: Prints the legend of Poker cards: Strings -> integers           *
* Input parameters: current round			                                   *
* Returns: void									                               *
* Preconditions: running program with round number							   *
* Postconditions: void									                       *
********************************************************************************/
void print_legend(int round)
{
	printf("Legend:\n");
	printf("Suit: Hearts = 0, Diamonds = 1, Clubs = 3, Spades = 4\n");
	printf("Face: Ace = 1, Jack = 11, Queen = 12, King = 13\n");
	printf("Round: %d\n\n", round);
}

/*******************************************************************************
* Function: print_hand		                                                   *
* Date Created: November 11, 2017											   *
* Date Last Modified: November 11, 2017                                        *
* Description: Prints the current player's hand in integer format              *
* Input parameters: Hand of cards, player string literal                       *
* Returns: void									                               *
* Preconditions: Hand of cards and player names								   *
* Postconditions: void									                       *
********************************************************************************/
void print_hand(Hand playerhand, char *player)
{
	int i = 0;

	printf("%s's Hand (Face Suit)\n", player);
	for (i = 0; i < HAND; ++i)
	{
		printf("\t Card[%d]: %d %d\n", i + 1, playerhand.hand[i].face, playerhand.hand[i].suit);
	}
	
}

/*******************************************************************************
* Function: bubble_sort		                                                   *
* Date Created: October 18, 2017											   *
* Date Last Modified: November 11, 2017                                        *
* Description: Bubble sorts the face values, moves suits along with            *
* Input parameters: Pointer to Hand of cards, size of hand	                   *
* Returns: void									                               *
* Preconditions: Hand of cards												   *
* Postconditions: Hand now sorted by face value in ascending order             *
********************************************************************************/
void bubble_sort(Hand *hand, int n)
{
	int i = 0, j = 0;
	Card temp;
	for (i = 0; i < (n - 1); ++i) //(n-1) prevents going off the end of array[size n]
	{
		for (j = 0; j < (n - i - 1); ++j) //adjust by number of previous passes (i)
		{
			if (hand->hand[j].face > hand->hand[j + 1].face) //search for new max
			{
				temp.face = hand->hand[j].face; //swap using pointer to Hand
				hand->hand[j].face = hand->hand[j + 1].face;
				hand->hand[j + 1].face = temp.face;
				temp.suit = hand->hand[j].suit; //move suit along with to avoid mixing cards
				hand->hand[j].suit = hand->hand[j + 1].suit;
				hand->hand[j + 1].suit = temp.suit;
			}
		}
	}
}

/*******************************************************************************
* Function: contains_pair	                                                   *
* Date Created: November 6, 2017											   *
* Date Last Modified: November 11, 2017                                        *
* Description: Searches for two equal face values in a hand of cards.          *
* Input parameters: Hand of cards, size of hand				                   *
* Returns: Boolean true or false				                               *
* Preconditions: Hand of cards with size									   *
* Postconditions: Boolean returned									           *
********************************************************************************/
Bool contains_pair(Hand hand, int n)
{
	int i = 0;
	Bool result = false;
	int position = -1;

	for (i = 0; i < n - 1; ++i) //avoid out of bounds
	{
		if (hand.hand[i].face == hand.hand[i + 1].face)
		{
			result = true; //if any two card face values are the same, result = true
		}	
	}	
	return result;
}

/*******************************************************************************
* Function: contains_two_pair                                                  *
* Date Created: November 6, 2017											   *
* Date Last Modified: November 11, 2017                                        *
* Description: Searches for two distinct, equal face values in a hand of cards.*
* Input parameters: Hand of cards, size of hand				                   *
* Returns: Boolean true or false				                               *
* Preconditions: Hand of cards with size									   *
* Postconditions: Boolean returned									           *
********************************************************************************/
Bool contains_two_pair(Hand hand, int n)
{
	int i = 0;
	int pair_count = 0;
	Bool result = false;

	for (i = 0; i < n - 1; i++) //avoid out of bounds
	{
		if (hand.hand[i].face == hand.hand[i + 1].face)
		{
			pair_count++; //if two faces are equal, update pair tracker
			i++;
		}
	}
	if (pair_count == 2) //if tracker = 2, we have two unique pairs
	{
		result = true;
	}
	return result;
}

/*******************************************************************************
* Function: contains_threeKind                                                 *
* Date Created: November 6, 2017											   *
* Date Last Modified: November 11, 2017                                        *
* Description: Searches for three equal face values in a hand of cards.		   *
* Input parameters: Hand of cards, size of hand				                   *
* Returns: Boolean true or false				                               *
* Preconditions: Hand of cards with size									   *
* Postconditions: Boolean returned									           *
********************************************************************************/
Bool contains_threeKind(Hand hand, int n)
{
	int i = 0;
	Bool result = false;

	for (i = 0; i < (n - 3); ++i) // n - 3 to avoid bound
	{
		if ((hand.hand[i].face == hand.hand[i + 1].face) && (hand.hand[i].face == hand.hand[i + 2].face))
		{
			result = true; //if card at [i] = to the next two cards, true
		}
	}
	return result; 
}

/*******************************************************************************
* Function: contains_fourKind                                                  *
* Date Created: November 6, 2017											   *
* Date Last Modified: November 11, 2017                                        *
* Description: Searches for four equal face values in a hand of cards.		   *
* Input parameters: Hand of cards, size of hand				                   *
* Returns: Boolean true or false				                               *
* Preconditions: Hand of cards with size									   *
* Postconditions: Boolean returned									           *
********************************************************************************/
Bool contains_fourKind(Hand hand, int n)
{
	int i = 0;
	Bool result = false;	
	int count = 0;

	for (i = 0; i < n - 1; ++i) //iterate through hand, checking face values. 
	{
		if (hand.hand[i].face == hand.hand[i + 1].face)
		{
			count++;
		}
	}
	if (count == 3) //If card = next card 3 times, 4 of a kind is true
	{
		result = true;
	}
	return result;
}

/*******************************************************************************
* Function: contains_Straight                                                  *
* Date Created: November 6, 2017											   *
* Date Last Modified: November 11, 2017                                        *
* Description: Searches for five consequtive face values in a hand of cards.   *
* Input parameters: Hand of cards, size of hand				                   *
* Returns: Boolean true or false				                               *
* Preconditions: Hand of cards with size									   *
* Postconditions: Boolean returned									           *
********************************************************************************/
Bool contains_Straight(Hand hand, int n)
{
	Bool result = false;

	if ((hand.hand[4].face == hand.hand[0].face + 4) && //card 4 has to be card 1 + 4 etc...
		(hand.hand[3].face == hand.hand[0].face + 3) &&
		(hand.hand[2].face == hand.hand[0].face + 2) &&
		(hand.hand[1].face == hand.hand[0].face + 1))
	{
		result = true;
	}
	return result;	
}

/*******************************************************************************
* Function: contains_Flush	                                                   *
* Date Created: November 6, 2017											   *
* Date Last Modified: November 11, 2017                                        *
* Description: Searches for five equal suit values in a hand of cards.		   *
* Input parameters: Hand of cards, size of hand				                   *
* Returns: Boolean true or false				                               *
* Preconditions: Hand of cards with size									   *
* Postconditions: Boolean returned									           *
********************************************************************************/
Bool contains_Flush(Hand hand, int n)
{
	int i = 0;
	Bool result = false;
	int initial_suit = hand.hand[0].suit; //sets suit to 1st card's suit
	int flag = 0;

	for (i = 1; i < n; ++i) //checks cards 2-5 for same suit
	{
		if (hand.hand[i].suit != initial_suit) //if suit is the same, result is true
		{
			flag = 1;
		}		
	}
	if (flag == 0)
	{
		result = true;
	}
	return result;	
}

/*******************************************************************************
* Function: reset_deck		                                                   *
* Date Created: November 6, 2017											   *
* Date Last Modified: November 11, 2017                                        *
* Description: Resets deck of cards 2D array suit and face to 0				   *
* Input parameters: Deck array								                   *
* Returns: void									                               *
* Preconditions: Deck declared												   *
* Postconditions: Deck reset to 0									           *
********************************************************************************/
void reset_deck(int wDeck[][FACES])
{
	int row = 0;
	int col = 0;
	
	for(row = 0; row < SUITS; ++row)
	{
		for (col = 0; col < FACES; ++col)
		{
			wDeck[row][col] = 0;
		}
	}
}

/*******************************************************************************
* Function: hand_analysis	                                                   *
* Date Created: November 11, 2017											   *
* Date Last Modified: November 17, 2017                                        *
* Description: Calls each contain function to check and assigns points		   *
* Input parameters: Finalized hand of cards, player name string                *
* Returns: Hand rating (points)					                               *
* Preconditions: Valid inputs												   *
* Postconditions: Rating returned									           *
********************************************************************************/
int hand_analysis(Hand final_hand, char *player)
{
	int rating = 0;

	printf("Analyzing %s hand: \n", player);

	if (contains_pair(final_hand, HAND)) //Checks for each type of hand combination
	{
		rating += 1;	//point system just scales by 1 each time. i.e. three of a kind gives 1 point for pair and 2 points for 3 of a kind.
		printf("Pair found\t");
	}
	if (contains_two_pair(final_hand, HAND))
	{
		rating += 2;
		printf("Two Pair found\t");
	}
	if (contains_threeKind(final_hand, HAND))
	{
		rating += 3;
		printf("Three of a kind found\t");
	}
	if (contains_Straight(final_hand, HAND))
	{
		rating += 4;
		printf("Straight found\t");
	}
	if (contains_Flush(final_hand, HAND))
	{
		rating += 5;
		printf("Flush found\t");
	}
	if (contains_threeKind(final_hand, HAND) && contains_two_pair(final_hand, HAND)) //checks threeKind and two_unique pairs for a full house (3-2)
	{
		rating += 6;
		printf("Full House found\t");
	}
	if (contains_fourKind(final_hand, HAND))
	{
		rating += 7;
		printf("Four of a kind found\t");
	}
	if (contains_Straight(final_hand, HAND) && contains_Flush(final_hand, HAND)) //checks straight and flush for straightflush
	{
		rating += 8;
		printf("Straight Flush found\t");
	}
	if (rating == 0)
	{
		printf("No matches found.\n"); //if no combo is found (true) then print no matches found
	}
	putchar('\n');
	putchar('\n');
	return rating;
}

/*******************************************************************************
* Function: tiebreaker		                                                   *
* Date Created: November 11, 2017											   *
* Date Last Modified: November 17, 2017                                        *
* Description: Checks for tie in hand rating and choses high card for winner.  *
*				Ace is considered low card in this implementation.			   *
* Input parameters: Both player ratings and hands			                   *
* Returns: Integer 1 for player win, 0 for dealer	                           *
* Preconditions: Hand analysis completed									   *
* Postconditions: Rating returned									           *
********************************************************************************/
int tiebreaker(int p1, int dealer, Hand player, Hand dealr)
{
	int player_high = 0, deal_high = 0;
	int i = 0;
	int temp = 0;
	int max = player.hand[0].face;
	int dmax = dealr.hand[0].face;

	if (p1 == dealer) //If equal ratings, find max value (face)
	{
		printf("Hands are equivalent. To break the tie, the high card is played.\n");
		for (i = 0; i < HAND; ++i)
		{
			if (max < player.hand[i].face)
			{
				max = player.hand[i].face;
			}
		}
		for (i = 0; i < HAND; ++i)
		{
			if (dmax < dealr.hand[i].face)
			{
				dmax = dealr.hand[i].face;
			}
		}
		if (max > dmax) //check max value from each hand and print appropriate winner with values.
		{
			printf("Player's high card of %d is greater than dealer's card %d.\n", max, dmax);
			return 1;
		}
		else
		{
			printf("Dealer's high card of %d is greater than player's card %d.\n", dmax, max);
			return 0;
		}
	}
	if (p1 > dealer) //if players rating is better, just return 1 for player win
	{
		return 1;
	}
	if (dealer > p1) return 0; //if dealer rating is better, return 0 for player loss
}

/*******************************************************************************
* Function: print_winner                                                       *
* Date Created: October 16, 2017											   *
* Date Last Modified: November 11, 2017                                        *
* Description: Prints who wins the round, and updates win trackers		       *
* Input parameters: result (1 or 0) pointers to win trackers                   *
* Returns: void									                               *
* Preconditions: tiebreaker has returned a winner							   *
* Postconditions: print winner output to screen				                   *
********************************************************************************/
void print_winner(int result, int *pwins, int *dwins)
{
	if (result == 1)
	{
		printf("Player wins the round.\n");
		*pwins += 1;
	}
	else
	{
		printf("Delear wins the round.\n");
		*dwins += 1;
	}
}

/*******************************************************************************
* Function: final_winner                                                       *
* Date Created: November 16, 2017											   *
* Date Last Modified: November 17, 2017                                        *
* Description: Prints who wins the game									       *
* Input parameters: Win trackers from dealer and player		                   *
* Returns: void									                               *
* Preconditions: 10 rounds have been finished, with updated win trackers	   *
* Postconditions: print winner output to screen				                   *
********************************************************************************/
void final_winner(int pwins, int dwins)
{
	printf("Player has won %d rounds.\n", pwins);
	printf("Dealer has won %d rounds.\n", dwins);
	if (pwins > dwins)
	{
		printf("Dealer folds! Player wins!\n");
	}
	else
	{
		printf("You went all in and leave the table empty!\n");
	}
	printf("\nThank you for playing Five Card Draw Poker!\n");
}

/*******************************************************************************
* Function: pair_tie		                                                   *
* Date Created: November 11, 2017											   *
* Date Last Modified: November 17, 2017                                        *
* Description: Checks for tie when both players have a pair and finds higher   *
*				value out of the two pairs									   *
* Input parameters: Both player hands and pointer to the higher card found     *
* Returns: The better pair's face value				                           *
* Preconditions: Hand analysis completed									   *
* Postconditions: Rating returned									           *
********************************************************************************/
int pair_tie(Hand playerhand, Hand dealerhand, int *ptr)
{
	int i = 0, j = 0;
	int position = -1;
	int pvalue = 0;
	int dvalue = 0;

	for (i = 0; i < HAND - 1; ++i)
	{
		if (playerhand.hand[i].face == playerhand.hand[i + 1].face) //if pair found
		{
			pvalue = playerhand.hand[i].face; //face value at that pair. Since cards are sorted first, the last pair will also be the highest value
		}
	}
	for (j = 0; j < HAND - 1; ++j)
	{
		if (dealerhand.hand[j].face == dealerhand.hand[j + 1].face)
		{
			dvalue = dealerhand.hand[j].face;
		}
	}

	if (pvalue > dvalue) //compairs pairs for higher value, and returns the higher card via a pointer
	{
		*ptr = pvalue;
		return 1;
	}
	else
	{
		*ptr = dvalue;
		return 0;
	}
}

/*******************************************************************************
* Function: reset_maintainence                                                 *
* Date Created: November 17, 2017											   *
* Date Last Modified: November 17, 2017                                        *
* Description: Resets discard array to 0									   *
* Input parameters: Discard array							                   *
* Returns: void									                               *
* Preconditions: Array declared												   *
* Postconditions: Array reset to 0									           *
********************************************************************************/
void reset_maintain(int maintainence[])
{
	int i = 0;

	for (i = 0; i < HAND; ++i)
	{
		maintainence[i] = 0; //sets to 0 to avoid discarding too many cards after round 1
	}
}

/*******************************************************************************
* Function: dealer_ai		                                                   *
* Date Created: November 17, 2017											   *
* Date Last Modified: November 17, 2017                                        *
* Description: Provides some artificial intelligence to the dealer based on    *
*				hand ratings compared to the player's hand.	If leading, does   *
*				not redraw. If behind zero rating, draws 3 cards because no	   *
*				combos were found. If behind but greater than zero, checks for *
*				at least a pair, and draws any additional cards after that.	   *
* Input parameters: Hand, ratings, deck, suit, face, pointer to deal hand to   *
*					redraw cards and update. Start_card to upkeep tracker.	   *
* Returns: int of current card					                               *
* Preconditions: Preliminary hand analysis on dealer's hand					   *
* Postconditions: Hand updated with card tracker					           *
********************************************************************************/
int dealer_ai(Hand dealr, int dealr_rt, int playr_rt, const int wDeck[][13], const char *wFace[], const char *wSuit[], Hand *playerhand, int start_card)
{
	int j = 0;
	int temp = 0;
	int *ptr = 0;
	int card = 0;

	if (dealr_rt == 0) //draw 3 new cards because we didn't score any points
	{
		temp = deal(wDeck, wFace, wSuit, &dealr, start_card, MAXREDRAW);
		return temp; //update card tracker
	}
	else if (dealr_rt < playr_rt) //if behind, check for a pair at least, and then draw any cards after the found pair
	{
		if (contains_pair(dealr, HAND))
		{
			for (j = 0; j < HAND - 1; ++j)
			{
				if (dealr.hand[j].face == dealr.hand[j + 1].face)
				{
					temp = dealr.hand[j].face;
				}
			}
		}
		temp = deal(wDeck, wFace, wSuit, &dealr, start_card, (HAND - j)); //make sure to stay inside hand array
		card = temp;
		return card; //update card tracker
	}
	else //dealer > player ranking
	{
		return start_card; //did not draw any cards
	}
}//Could continue to make AI more involved based on other conditions/hand combinations as to which cards, if any to redraw.