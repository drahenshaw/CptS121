#include "scores.h"

int main(void)
{
	double score1 = 0, score2 = 0, score3 = 0, score4 = 0, score5 = 0, score6 = 0;
	double exam_average = 0.0, lab_average = 0.0, project_average = 0.0, w_avg = 0.0;

	instructions();
	score1 = get_score();
	score2 = get_score();
	score3 = get_score();
	score4 = get_score();
	score5 = get_score();
	score6 = get_score();
	exam_average = compute_average(score1, score2);
	lab_average = compute_average(score3, score4);
	project_average = compute_average(score5, score6);

	printf("Exam: %.2lf  Lab: %.2lf  Project: %.2lf\n", exam_average, lab_average, project_average);
	//w_avg = weighted_average(exam_average, lab_average, project_average);
	//printf("%lf", w_avg);

}