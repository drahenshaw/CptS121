#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

typedef struct cell //Sample struct definition with multiple data types
{
	int x;
	int y;
	char color;
	int occupied;
}Cell;

void initialize_struct(Cell array[][10], int rows, int cols);
void print_struct_array(Cell array[][10], int rows, int cols);

int my_strlen(const char*s);
int my_strlen_array(char str[]);

char *my_strcpy(char *destination, const char *source);
char *my_strcpy_array(char destination[], const char source[]);
char *my_str_n_cpy(char *destination, char *source, int n);

char *my_strcat(char *destination, char *source);

int my_strcmp(const char *s1, const char *s2);

void divide(int num, int divisor, int *result, int *remainder);
void get_date(int *month, int *day, int * year);

int sequential_search(int value[], int target, int size);

void selection_sort2(int *pList, int size);


int main(void)
{	//CHAPTER 10 - STRUCTS
	Cell board[10][10] = { {0} }; //Struct Array declaration
	Cell sample, choice, final; //Struct Cell type variables

	initialize_struct(board, 10, 10);
	board[2][3].color = 'g';
	print_struct_array(board, 10, 10);

	sample.color = board[2][3].color; //Using the dot operator, can change the colors of the Cell variables
	choice.color = sample.color;
	final = choice; //Can set structs == to each other

	printf("Color swap: %c\n", final.color);
	/********************************************************************************************************************/

	//CHAPTER 8 - STRINGS
	char str[100] = { 'c', 'a', 't', '\0' };
	char pointer[25] = { 'b', 'o', 'b' };
	char strng[] = "Bills";
	char *strn = "Literal";
	char *ptr;
	//char test = "Problem"; incorrect declaration, must either be a pointer, or an array of characters

	printf("%s\n", &str[1]);
	int length = 0;
	length = my_strlen(str);
	printf("%d\n", length);
	length = my_strlen_array(strng);
	printf("%d\n", length);

	my_strcpy(str, strng);
	puts(str);

	my_strcpy_array(pointer, strn);
	puts(pointer);

	ptr = my_strcpy_array(pointer, strn);
	puts(ptr);

	ptr = my_str_n_cpy(pointer, strn, 4);
	puts(ptr);
	puts(pointer);

	char destiny[50] = "Destiny is so ";
	char sour[] = "Ceorge";
	char *newptr;
	int result = 0;

	newptr = my_strcat(destiny, sour);
	puts(destiny);
	puts(newptr);

	result = my_strcmp(destiny, sour);
	puts(destiny);
	puts(sour);
	printf("%d\n", result);

	int n = 0, count = 0;
	for (scanf("%d", &n); n > 0; --n)
	{
		if (!(n % 11))
		{
			++count;
		}
	}

	printf("%d\n", count);


	char string[80] = "This - is - Sparta!";
	const char k[2] = { '-' };
	char *token;

	token = strtok(string, k);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, k);
	}

	int horray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
	length = sequential_search(horray, 4, 10);
	printf("Target found at index[%d]\n", length);




	/*int *month, *day, *year;
	get_date(&month, &day, &year);
	printf("Date: %d / %d / %d\n", month, day, year);*/

	int arrayyy[10] = { 2,4,3,1,7,8,11,9,6,5 };
	selection_sort2(arrayyy, 10);

	int index1 = 0, index2 = 0;
	
	for (index2 = 0; index2 < 10; ++index2)
	{
		printf("%d\t", arrayyy[index2]);
	}
	

}

//This function is an example of how to initialize values in a struct.
void initialize_struct(Cell array[][10], int rows, int cols)
{
	int i = 0, j = 0; //Nested loop indices

	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < cols; ++j)
		{
			array[i][j].x = i; //Initializes the different struct information
			array[i][j].y = j;
			array[i][j].color = 'r';
			array[i][j].occupied = 0;
		}
	}
}
//Example to print out the initialized information from the struct array
void print_struct_array(Cell array[][10], int rows, int cols)
{
	int i = 0, j = 0; //Nested loop indices

	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < cols; ++j)
		{
			printf("X: %d\n", array[i][j].x);
			printf("Y: %d\n", array[i][j].y);
			printf("Color: %c \n", array[i][j].color);
			printf("Occupied: %d\n", array[i][j].occupied);
			putchar('\n');
}}}

int my_strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}

int my_strlen_array(char str[])
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

char *my_strcpy(char *destination, const char *source)
{
	while (*source)
	{
		*destination = *source;
		source++;
		destination++;
	}
	*destination = '\0';
}

char *my_strcpy_array(char destination[], const char source[])
{
	int i = 0;
	static char string[100];
	while (source[i] != '\0')
	{
		string[i] = source[i];
		i++;
	}
	return string;
}

char *my_str_n_cpy(char *destination, char *source, int n)
{
	int i = 0;
	
	for (i = 0; i < n && source[i] != '\0'; ++i)
	{
		destination[i] = source[i];
	}

	return destination;
}

char *my_strcat(char *destination, char *source)
{
	int i = 0, j = 0;

	while (destination[i] != '\0') i++;
	while (source[j] != '\0')
	{
		destination[i] = source[j];
		i++;
		j++;
	}	
	destination[i] = '\0';
	return destination;
}

int my_strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s2[i] == s1[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			break;
		}
		i++;
	}
	
	if (s1[i] < s2[i])
	{
		return -1;
	}
	else if (s1[i] > s2[i])
	{
		return 1;
	}
	else if (s1[i] == '\0' && s2[i] == '\0')
	{
		return 0;
	}
	
}

void divide(int num, int divisor, int *result, int *remainder)
{
	int r = 0;
	int rem = 0;

	r = num / divisor;
	rem = num % divisor;

	*result = r;
	*remainder = rem;
}

void get_date(int *month, int *day, int * year)
{
	int valid, status;
	char sep1, sep2;

	do
	{
		valid = 1;
		printf("Please enter a date (mm/dd/yyyy): ");
		status = scanf("%d %c%d %c%d", month, &sep1, day, &sep2, year);

		if (status != 5 || sep1 != '/' || sep2 != '/'|| *month < 1 || *month > 12 || *day < 1 || *day > 31)
		{
			valid = 0;
			printf("Date is invalid\n");
		}
	} while (!valid);
}

int sequential_search(int value[], int target, int size)
{
	int index = 0, found = 0;

	while (index < size && !found)
	{
		if (value[index] == target)
		{
			printf("Target aquired\n");
			found = 1;
		}
		else index++;
	}

	if (found) return index; 
	else return -1;
}

int binary_search(int values[], int target, int size)
{
	int found = 0;
	int left = 0;
	int right = size;
	int mid;

	while (!found && left <= right)
	{
		mid = (left + right) / 2;
		if (target == values[mid])
		{
			found = 1;
		}
		else if (target < values[mid])
		{
			right = mid - 1;
		}
		else left = mid + 1;
	}

	if (found)return mid;
	else return -1;
}

void selection_sort(int values[], int num_values)
{
	int i, index_of_smallest, temp;
	for (i = 0; i < num_values - 1; ++i)
	{
		/* Find the index of the smallest element in unsorted list... */
		index_of_smallest = find_smallest(values, i, num_values - 1);
		/* Swap the smallest value in the subarray i+1 .. num_values - 1
		with the value i, thereby putting into place the ith element. */
		temp = values[i];
		values[i] = values[index_of_smallest];
		values[index_of_smallest] = temp;
	}
}
int find_smallest(int values[], int low, int high)
{
	int smallest_index, i;
	smallest_index = low;
	for (i = low + 1; i <= high; i++)
		if (values[i] < values[smallest_index])
			smallest_index = i;
	return smallest_index;
}

void selection_sort2(int *pList, int size) //ascending order, * is the sane as [] in this case, pointer to first item address in contiguous memory.
{
	int index = 0, passes = 1, max = 0, pos = 0, temp = 0;

	for (passes = 1; passes < size; ++passes) //determine how many passes
	{
		max = pList[0]; //initial max and pos always start at zero before iteration through the lsit
		pos = 0;
		for (index = 0; index < size - passes + 1; ++index) //where sorting and swaps happen
		{
			if (max < pList[index])
			{
				max = pList[index];
				pos = index;
			}
		}
		temp = max; //swap - requires 3rd variable to temp store the value
		pList[pos] = pList[size - passes];
		pList[size - passes] = temp;
	}
}