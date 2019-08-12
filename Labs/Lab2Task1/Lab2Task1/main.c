/*Programmer: David Henshaw
 *Class: CptS 121, Fall 2017, Lab Section 3
 *Programming Assignment: Lab2Task1
 *Date: September 6th, 2017
 *Description: Perpendicular Bisector - finds equation of the line that bisects a line given by two user-defined coordinate points. 
 */
#include <stdio.h>
#include <math.h>


int main(void)
{
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	double slope = 0, slope_b = 0, mid_x = 0, mid_y = 0, y_int = 0, y = 0;
	double height = 0, weight = 0, height_in = 0, bmi = 0;
	int harris = 0, coaches = 0;
	double harris_poll = 0, coaches_poll = 0, computer_ranking = 0, BCS_score = 0;

	// Task 1 ) Perpendicular Bisector
	printf("Please enter two (x,y) coordinates: ");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	slope = (y2 - y1) / (x2 - x1);
	mid_x = x1 + x2 / (2);
	mid_y = y1 + y2 / (2);
	printf("Coordinates: (%d , %d) (%d , %d)\n", x1, y1, x2, y2);
	printf("Midpoint coordinates: (%lf , %lf)\n", mid_x, mid_y);
	slope_b = -1 / slope;
	y_int = mid_y - slope_b * mid_x;
	y = slope_b * mid_x + y_int;
	printf("Perpendicular Bisector: y = mx + b = %lf * %lf + %lf = %lf\n", slope_b, mid_x, y_int, y);
	printf("\n");

	// Task 2 ) BMI
	printf("Enter height (ft) and weight (lbs): ");
	scanf("%lf %lf", &height, &weight);
	height_in = height * 12;
	bmi = weight / (pow(height_in, 2)) * 703;
	printf("BMI: %lf\n", bmi);
	printf("\n");

	// Task 3 ) Bowl Championship Series Scores
	printf("Please enter Harris poll (1 - 2850), Coaches' poll (1 - 1475), and Computer Ranking (0 - 1) Scores: ");
	scanf("%d%d%lf", &harris, &coaches, &computer_ranking);
	harris_poll = (double)harris / 2850;
	coaches_poll = (double)coaches / 1475;
	BCS_score = (harris_poll + coaches_poll + computer_ranking) / 3;
	printf("Harris Poll: %lf \nCoaches' Poll: %lf\n", harris_poll, coaches_poll);
	printf("BCS Score: %lf\n", BCS_score);
	
	return 0;
	
}