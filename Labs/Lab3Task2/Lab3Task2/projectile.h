#include <stdio.h>
#include <math.h>

#define G 32.17 //Gravitational constant

double get_theta();
double get_distance();
double get_velocity();
double calculate_time(double distance, double velocity, double theta);
double calculate_height(double velocity, double theta, double time);
double display_result(double time, double height);