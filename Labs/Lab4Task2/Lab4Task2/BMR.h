#include <stdio.h>
#include <math.h>

double read_double(FILE* infile);
int read_int(FILE* infile);

double determine_gender_bmi(int gender, double weight, double height, double age);
double convert_height(double height);
double w_bmr(double weight, double height, double age);
double m_bmr(double weight, double height, double age);
double activity_factor(int activity, double bmr);