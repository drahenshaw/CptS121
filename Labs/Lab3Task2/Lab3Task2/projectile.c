#include "projectile.h"

double get_theta()
{
	double theta = 0.0;
	printf("Please enter angle (radians) of elevation: ");
	scanf("%lf", &theta);
	return theta;
}

double get_distance()
{
	double distance = 0.0;
	printf("Please enter distance (feet) to target: ");
	scanf("%lf", &distance);
	return distance;
}

double get_velocity()
{
	double velocity = 0.0;
	printf("Please enter projectile velocity (ft/sec): ");
	scanf("%lf", &velocity);
	return velocity;
}

double calculate_time(double distance, double velocity, double theta)
{
	double time = 0.0;
	time = (distance) / (velocity * cos(theta));
	return time;
}

double calculate_height(double velocity, double theta, double time)
{
	double height = 0.0;
	height = velocity * sin(theta) * time - ((G * pow(time, 2) / 2));
	return height;
}

double display_result(double time, double height)
{
	printf("Time of Flight (sec): %lf\n", time);
	printf("Height of Impact (ft): %lf\n", height);
}





