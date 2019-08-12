#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct coordinate
{
	int row;
	int col;
}Coordinate;

typedef struct cell
{
	int occupied;
	char symbol;
	Coordinate location;
}Cell;

typedef struct game_info
{
	int wins;
	int loss;
	int games;
}Game_info;

void init_board(Cell board[][10], int num_rows, int num_cols);

int main(void)
{
	srand(time(NULL));
	char *article[] = { "the", "a", "one", "some", "any" }; //Because this is char * the data cannot be changed
	char *noun[] = { "boy", "girl", "dog", "town", "car" };
	char *verb[] = { "drove","jumped", "ran", "walked", "skipped" };
	char *preposition[] = { "to", "from", "over", "under", "on" };

	char sentance[100] = { '\0' };
	char *space = { ' ' };
	char *exclaim = { '!' };
	char temp = '\0';

	int index = 0;

	for (index = 0; index < 19; ++index)
	{


		sentance[0] = article[(rand() % 5)];
		strcat(sentance, &space);
		strcpy(sentance, article[rand() % 5]);
		strcat(sentance, &space);
		strcat(sentance, noun[rand() % 5]);
		strcat(sentance, &space);
		strcat(sentance, verb[rand() % 5]);
		strcat(sentance, &space);
		strcat(sentance, preposition[rand() % 5]);
		strcat(sentance, &space);
		strcat(sentance, article[rand() % 5]);
		strcat(sentance, &space);
		strcat(sentance, noun[rand() % 5]);
		puts(sentance);
		//putchar('\n');
	}
			
	sentance[0] = article[(rand() % 5)];
	strcat(sentance, &space);
	strcpy(sentance, article[rand() % 5]);
	strcat(sentance, &space);
	strcat(sentance, noun[rand() % 5]);
	strcat(sentance, &space);
	strcat(sentance, verb[rand() % 5]);
	strcat(sentance, &space);
	strcat(sentance, preposition[rand() % 5]);
	strcat(sentance, &space);
	strcat(sentance, article[rand() % 5]);
	strcat(sentance, &space);
	strcat(sentance, noun[rand() % 5]);
	temp = sentance[0];
	sentance[0] = (toupper(temp));
	strcat(sentance, &exclaim);
	puts(sentance);
	/********************************/	
	/************Task 2**************/

	int player = 0; 
	int size = 0;
	int first_player = rand() % 2;

	printf("Enter size of game board: ");
	scanf("%d", &size);


	Cell game_board[][100] = { 0 };

	init_board(game_board, size, size);

	
	
}

void init_board(Cell board[][10], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			board[row_index][col_index].location.row = row_index;
			board[row_index][col_index].location.col = col_index;
			board[row_index][col_index].symbol = '\0';
			board[row_index][col_index].occupied = 0;
		}
	}
}