#include "Eight.h"

int main(void)
{
	char word[6] = { 'l', 'a', 'p', 't', 'o', 'p' }; //Hangman word to guess
	char guesses[26] = { '/0' }; //Keeps track of guesses so far
	char print[6] = { ' ', ' ', ' ', ' ', ' ',' ' }; //Print the word with guesses
	int lives = 6;
	char guess = '/0';
	int i = 0, j = 0;
	int match = 0;
	int win = 1;
	int counter[6] = { 0 };
	int points = 0;
	int invalid = 0;
	
	
	do
	{
		match = 0;
		do {
			printf("Please enter a letter: ");
			scanf(" %c", &guess);
			guesses[j] = guess;
			
			for (i = 0; i < 26; ++i)
			{
				if (guess == guesses[i])
				{
					printf("You already guessed that letter!\n");
					invalid = 1;
				}
			}
		} while (invalid = 1 && j > 0);

		
		//breaking comment



		for (i = 0; i < 6; ++i)
		{
			if (guess == word[i])
			{
				printf("%c is a match!\n", guess);
				print[i] = guess;				
				match = 1;
				points += 1;
			}
		}
		if (match != 1)
		{
			printf("Incorrect guess\n");
			--lives;
		}		
		for (i = 0; i < 6; ++i) printf("%c", print[i]);
		putchar('\n');
	
		for (i = 0; i < 6; ++i)
		{
			if (word[i] == print[i])
			{
				counter[i] = 1;
			}			
		}



		if (points == 6)
		{
			printf("You WIN!\n");
			break;
		}
		

		j++;
	} while (lives > 0);
	
	if (lives == 0)
	{
		printf("You LOSE!\n");
	}

	return 0;
}