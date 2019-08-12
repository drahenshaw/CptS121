#include "baseball.h"

int main(void)
{
	char response = '/0';
	double bonus = 0.0;


	printf("Welcome to the baseball bonus calculator!\n");
	printf("Please enter Y or N");
	printf("All-Star Game Appearance?\n");
	scanf("%c", &response);

	if (response == 'y' || response == 'Y')
	{
		bonus = bonus + 25000;
	}
	
	printf("Regular Season MVP?\n");
	scanf(" %c", &response);

	if (response == 'y' || response == 'Y')
	{
		bonus = bonus + 75000;
	}

	printf("World Series MVP?\n");
	scanf(" %c", &response);

	if (response == 'y' || response == 'Y')
	{
		bonus = bonus + 100000;
	}

	printf("Gold Glove Award?\n");
	scanf(" %c", &response);

	if (response == 'y' || response == 'Y')
	{
		bonus = bonus + 50000;
	}

	printf("Silver Slugger?\n");
	scanf(" %c", &response);

	if (response == 'y' || response == 'Y')
	{
		bonus = bonus + 35000;
	}

	printf("Home Run Champion?\n");
	scanf(" %c", &response);

	if (response == 'y' || response == 'Y')
	{
		bonus = bonus + 25000;
	}

	printf("Batting Average Champion?\n");
	scanf(" %c", &response);

	if (response == 'y' || response == 'Y')
	{
		bonus = bonus + 25000;
	}

	printf("Player's Total Year-End Bonus: $%.2lf\n", bonus);
	return 0;
}

