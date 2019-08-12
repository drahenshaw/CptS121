#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100
#define MAX_COMBO 5

typedef enum
{
	false, true
}bool;

bool palindrome(const char *stringstart, const char *stringend);

int main(void)
{
	//Task 1: Recursive Palindrome Function
	char string1[MAX_STRING_LENGTH];
	char string2[MAX_STRING_LENGTH] = { '\0' };
	int index_1 = 0, index_2 = 0;

	printf("Please enter a string to determine if it's a palindrome.\n");
	fgets(string1, MAX_STRING_LENGTH, stdin);

	*(strchr(string1, '\n')) = '\0';

	for (index_1; index_1 < strlen(string1); ++index_1)
	{
		string1[index_1] = tolower((int)string1[index_1]);

		if (!(isspace((int)string1[index_1]) || ispunct((int)string1[index_1])))
		{
			string2[index_2] = string1[index_1];
			index_2++;
		}
	}	
	printf("%s is", string2);
	if (palindrome(string2, string2 + strlen(string2) - 1) == false)
	{
		printf(" not");
	}
	printf(" a palindrome.\n\n");

	//Task 3
	char input[MAX_COMBO];
	printf("Enter a string of up to five x's, 0's and 1's (i.e. x0x1): ");
	fgets(input, MAX_COMBO, stdin);
	return 0;
}

bool palindrome(const char *stringstart, const char *stringend)
{
	//Recursive Implementation		
	if (stringstart > stringend) //base case
	{
		return true;
	}
	if (*stringstart != *stringend) //if values are not equal, return false
	{
		return false;
	}
	return palindrome(stringstart + 1, stringend - 1); //recursive step
}

