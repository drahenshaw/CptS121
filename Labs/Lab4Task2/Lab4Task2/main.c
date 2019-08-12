#include "BMR.h"


int main(void)
{
	FILE* infile = NULL;
	int gender = 0, activity = 0;
	double weight = 0.0, height = 0.0, age = 0.0, bmr = 0.0;

	infile = fopen("bmr.txt", "r"); //Open file for reading
	
	age = read_double(infile);	//Reading of file for age, gender, weight, height, and activity levels
	gender = read_int(infile);
	weight = read_double(infile);
	height = read_double(infile);
	activity = read_int(infile);

	height = convert_height(height);	//Converts height in feet to height in inches

	bmr = determine_gender_bmi(gender, weight, height, age); //Function to determine which BMI equation to use: male or female
	bmr = activity_factor(activity, bmr);	//Scales the BMR by the correct activity factor
	printf("Calories: %.2lf\n", bmr);	//Prints result - the daily calories needed based on the data
}