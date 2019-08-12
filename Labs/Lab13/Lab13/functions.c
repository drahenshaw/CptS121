#include "thirteen.h"

void itob(int n, char * p)
{
	char * ptr = p;

	if (p == NULL) return;

	do
	{
		if (n % 2 == 0)
		{
			*p = '0';
		}
		else
		{
			*p = '1';
		}

		p++;

		n =  n / 2;

	} while (n > 0);
	*p = '\0';
	strrev(ptr);
}

unsigned int power2(int number, int power)
{
	int result = 0;
	result = number << power;
	return result;
}

unsigned int packCharacters(int packer, char character)
{
	unsigned int result = 0;
	char p[100];
	char c = '\0';

	if (packer == 0)
	{
		packer = character;
	}
	result = power2(packer, 8);
	//itob(result, p);
	//printf("Packed: %d = %s\n", result, p); //Print number and binary representation	
	//printf("Enter a character: "); //Enter second letter to OR with
	//scanf(" %c", &c);
	//result = packer | c; //Bitwise OR
	//result = power2(packer, 8); //Shift by 8
	//itob(result, p);
	//printf("Packed: %d = %s\n", result, p); //Print & repeat
	
	return result;
}