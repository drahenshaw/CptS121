#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char string_reverse(char array[], int size);
char pointer_reverse(char *pString);
int string_length(char *pString);

char *my_strcpy(char destination[], const char source[]);
char *my_strcat(char destination[], const char source[]);


int main(void)
{
	int test_length = 0;
	char my_str[] = "Life is good!";
	char pointer[20] = "CptS 121 is cool!";
	char copy[20] = { '\0' };

	char append[40] = { "Cats" };
	char testsourceappend[40] = "Elephant";
	
	test_length = string_length(pointer);
	//test_length = string_length(rts_ym);
	printf("%d\n", test_length);

	string_reverse(my_str, 13);
	printf("%s", my_str);
	putchar('\n');
	
	pointer_reverse(pointer);
	puts(pointer);

	test_length = strlen(pointer);
	printf("%d\n", test_length);

	my_strcpy(copy, pointer);
	puts(copy);
	puts("end");

	my_strcat(append, testsourceappend);
	puts(append);

}

char string_reverse(char array[], int size)
{
	int start = 0; //Indexing variables
	int finish = size - 1;
	int temp = 0;

	while (start < finish)
	{
		temp = array[start];
		array[start] = array[finish];
		array[finish] = temp;
		start++;
		finish--;
	}
}

char pointer_reverse(char *pString)
{
	int start = 0; //Indexing variables
	int finish = string_length(pString);
	int temp = 0;
	finish--;
	while (start < finish)
	{
		temp = *(pString + start);
		*(pString + start) = *(pString + finish);
		*(pString + finish) = temp;
		start++;
		finish--;
	}
}

int string_length(char *pString)
{
	int c = 0;

	for (c = 0; *(pString + c) != '\0';)
	{
		c++;
	}
	return c;
}

char *my_strcpy(char destination[], const char source[])
{
	int i = 0; 

	for (; i < strlen(source) + 1; ++i)
	{
		destination[i] = source[i];
	}
	return destination;
}

char *my_strcat(char destination[], const char source[])
{
	int i = 0, j = 0;

	for (i = 0; i < strlen(source) + 1; ++i)
	{
		if (destination[i] == '\0')
		{
			for (j = 0; j < strlen(source) + 1; ++j)
			{
				destination[i + j] = source[j];
			}
		}
	}
}