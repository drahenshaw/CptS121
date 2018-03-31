/**************************************************************************************************************
*Programmer: David Henshaw																					  *
*Class: CptS 121, Fall 2017, Lab Section 03																      *
*Programming Assignment: PA8 - Interview Questions															  *
*Date: November 29, 2017																					  *
*Description: Header file for PA8 including both standard libraries and custom function declarations          *
***************************************************************************************************************/

#ifndef INTERVIEW
#define INTERVIEW

#define MENU_MIN 1
#define MENU_MAX 8
#define STRING 1
#define BINARY 2
#define BUBBLE 3
#define PALINDROME 4
#define PRIMES 5
#define MAX__OCCUR 6
#define BONUS 7
#define MAX_STRING 50
#define MAX_LIST 100
#define ALPHABET 26

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

typedef struct occurrences
{
	int num_occurrences;
	double frequency;
} Occurrences;

//1. String N Copy
char * my_str_n_cat(char *destination, char *source); 

//2. Binary Search
int binary_search(int list[], int target_value, int size);
void populate_list(int list[], int size);
int set_list_size(void);
int get_target(void);

//3. Bubble Sort
void bubble_sort(char *string[], int num_strs);

//4. Palindrome
int is_palindrome(char *pStr, int length);
char *chomp_string(char *dest, char *source);

//5. Sum of Primes Recursively
int sum_primes(unsigned int n);
int is_prime(int n);

//6. Maximum Occurences
void maximum_occurences(char *s, Occurrences array[], int *n, char *c);

//7. Maximum Consecutive Integers
void max_consecutive_integers(int list[][5], int rows, int cols, int **start, int *sequence);

//Other functions
void welcome_screen(void);
void display_menu(void);
int menu_input(void);
int menu_selection(void);

#endif // !INTERVIEW