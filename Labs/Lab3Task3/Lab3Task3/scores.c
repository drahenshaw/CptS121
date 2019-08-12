#include "scores.h"


double instructions() 
{
	printf("Please enter two exam scores, two lab scores, and two project scores:\n");
}

double get_score()
{
	double score = 0.0;
	printf("Please enter score: ");
	scanf("%lf", &score);
	return score;
}

double compute_average(double score1, double score2)
{
	double average = 0.0;
	average = (score1 + score2) / 2;
	return average;
}

double weighted_average(double exam_average, double lab_average, double project_average)
{
	double w_avg = 0.0;
	w_avg = (.60 * exam_average) + (.10 * lab_average) + (.30 * project_average);
	return w_avg;
}