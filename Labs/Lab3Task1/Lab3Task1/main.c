/*Progammer: David Henshaw
 *Class: CptS 121, Fall 2017, Lab Section 3
 *PA: Lab 3 Task 1
 *Date: 9/11/2017
 *Description: BMI calculator using functions - shows example of custom functions in single final format. 
 */

#include <stdio.h>
#include <math.h>

double bmi_calculator = 0.0;

double get_weight(void); // prompts the user for weight in pounds, and returns the weight
double get_height(void); // prompts the user for height in feet, and returns the height
double convert_feet_to_inches(double height_in_feet); // converts the height of the user from feet to inches, and returns the height in inches
double calculate_bmi(double weight_in_pounds, double height_in_feet); // evaluates the BMI based on weight in pounds and height in inches, and returns the BMI – call convert_feet_to_inches ()
void display_bmi(double bmi); // display the resultant BMI value to the tenths place

int main(void)										//Main Function Drives the program
{
	double weight = 0.0, height = 0.0, bmi = 0.0;	//Local variable declarations
	weight = get_weight();							//Calls get_weight -stores user weight
	height = get_height();							//Calls get_height
	bmi = calculate_bmi(weight, height);			//Calls calculate_bmi and passes it the inputs weight and height from the user
	display_bmi(bmi);								//Displays BMI
}

double get_weight(void)
{
	double weight = 0.0;
	printf("Please enter weight in lbs: ");
	scanf("%lf", &weight);
	return weight;
}

double get_height(void)
{
	double height = 0.0;
	printf("Please enter height in ft: ");
	scanf("%lf", &height);
	return height;
}

double convert_feet_to_inches(double height_in_feet)			
{
	double height_inches = 0.0;
	height_inches = 12 * height_in_feet;
	return height_inches;
}

double calculate_bmi(double weight_in_pounds, double height_in_feet)	//Main calls this function and passes it weight/height from the user. Height goes to convert_to_inches function, gets coverted, and returns to height_in. Then final BMI is calculated.
{
	double bmi = 0.0, height_in = 0.0;
	height_in = convert_feet_to_inches(height_in_feet);
	bmi = (weight_in_pounds) / (pow(height_in, 2)) * 703;
	return bmi;		
}

void display_bmi(double bmi)
{
	printf("BMI: %.2lf\n", bmi);
	
}